

import java.io.FileNotFoundException;
import java.io.IOException;
import java.net.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.Semaphore;

public class Client {

	// We need a way of storing packets that are yet to recieve acknowledge;
	// we'll do so here
	private static Map<Byte, ReliablePacket> unackedPackets = new ConcurrentHashMap<Byte, ReliablePacket>();

	private static final Semaphore lock = new Semaphore(1);

	
	// A 2s timeout is plenty
	// TODO: Make this variable depending on network conditions
	private int timeout = 300;

	public static long oldestPacketTime = 0;

	public static void main(String[] args) throws InterruptedException,
			IOException {

		System.out.println("Client started with parameters: ");
		for (String arg : args) {
			System.out.println(arg);
		}

		String hostAddress = "";
		int portHost, portClient;
		String fileName = "";
		int reliabilityNumber = 0;
		int windowSize = 0;
		int timeout = 0;
		// Blank line
		System.out.println("");

		try {

			hostAddress = args[0];
			portHost = Integer.parseInt(args[1]);
			portClient = Integer.parseInt(args[2]);
			fileName = args[3];
			reliabilityNumber = Integer.parseInt(args[4]);
			windowSize = Integer.parseInt(args[5]);
			timeout=Integer.parseInt(args[6]);
		} catch (Exception e) {
			System.out
					.println("The given command line arguments were not valid. "
							+ "Check your parameters and then try again.");
			return;
		}

		// Verify window size
		if (windowSize < 1 || windowSize > 128) {
			System.out
					.println("The window size must be 1-128 and a valid integer.");
			return;
		}

		if (reliabilityNumber < 0) {
			System.out
					.println("The reliability number must be 0 or greater and a valid integer.");
			return;
		}

		portClient = 7000;

		// TODO: Remove this... for now we set this to 1 for 'stop and wait'
		//windowSize = 40;

		long startTime = System.currentTimeMillis();

		ChunkedFile chunkedFile;
		try {
			chunkedFile = new ChunkedFile(fileName);
		} catch (FileNotFoundException exception) {
			System.out
					.println("The specified file provied could not be found or loaded. Exiting.");
			return;
		}

		// OK, now we setup our socket and prepare to do some actual work
		ReliableSenderSocket socket;

		try {
			socket = new ReliableSenderSocket(3333, reliabilityNumber);
		} catch (SocketException exception) {
			System.out.println("The host could not be contacted. Aborting.");
			return;
		}

		// Get an IP address
		InetAddress IPAddress;
		try {
			IPAddress = InetAddress.getByName(hostAddress);
		} catch (UnknownHostException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
			socket.close();
			return;
		}

		System.out.println("Sending to port " + portClient + " on port "
				+ portHost);

		Boolean transmitComplete = false;

		int chunksSent = 0;

		byte seqNumber = 0;

		Thread ack_listener = new Thread(
				new AckListener(unackedPackets, socket));
		ack_listener.start();

		while (transmitComplete == false) {

		   lock.acquire();

		
			// If there's data left, we can try and send it
			if (chunkedFile.isDataLeft()) {

				
				// Only send if we can afford to
				if (unackedPackets.values().size() < windowSize) {

					byte[] payload;

					try {
						payload = chunkedFile.getByteChunk();
					} catch (IOException exception) {
						System.out.println("Oops... ran out of file!");
						break;
					}

					// Create our packet with the timestamp of the current time
					ReliablePacket packet = new ReliablePacket(seqNumber,
							payload, System.currentTimeMillis());

					// If this is the only packet in queue, it must be the
					// oldest
					if (unackedPackets.size() == 0)
						oldestPacketTime = packet.getTimestamp();

					unackedPackets.put(seqNumber, packet);

					// Increment our sequence counter
					seqNumber = (byte) ((seqNumber + 1) % 128);

					payload = packet.getPacketPayload();

					// Send our data
					try {
						socket.send(new DatagramPacket(payload, payload.length,
								IPAddress, portClient));
						chunksSent++;
					} catch (IOException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}

				}
				else{
				
				}

			} else {

				// No need to send any more files; when the ack table is empty
				// then we can feel free to finally leave

				if (unackedPackets.size() == 0) {
					transmitComplete = true;
				}

			}

			// Check to see if we need to retransmit anything
			long delta = System.currentTimeMillis() - oldestPacketTime;

			if (delta > timeout) {

				// Sort by the unique creation ID so we guarentee the oldest
				// packet will be sent
				// first without fail
				List<ReliablePacket> packets = new ArrayList<ReliablePacket>(
						unackedPackets.values());

				Collections.sort(packets, new Comparator<ReliablePacket>() {
					public int compare(ReliablePacket s1, ReliablePacket s2) {
						return Long.compare(s1.getUniqueId(), s2.getUniqueId());
					}
				});

				// Resend our payload
				for (ReliablePacket packet : packets) {
					packet.setTimestamp(System.currentTimeMillis());
					System.out.println(System.currentTimeMillis() / 10000
							+ "|| Retransmit: " + packet.getSequenceNumber());
					byte[] payload = packet.getPacketPayload();
					socket.send(new DatagramPacket(payload, payload.length,
							IPAddress, portClient));
				}

				// Reset timer
				System.out.println(System.currentTimeMillis());
				oldestPacketTime = System.currentTimeMillis();
			}
			
		    lock.release();


		}

		System.out
				.println("All "
						+ chunksSent
						+ " file chunks acknowledged. Awaiting shutdown confirmation...");

		byte[] temp = new byte[1];

		ReliablePacket packet = new ReliablePacket((byte) -1, temp,
				System.currentTimeMillis());

		unackedPackets.put((byte) -1, packet);
		DatagramPacket terminate = new DatagramPacket(
				packet.getPacketPayload(), packet.getPacketPayload().length,
				IPAddress, portClient);

		long previous = System.currentTimeMillis();
		socket.send(terminate);
		while (unackedPackets.isEmpty() == false) {
			if (System.currentTimeMillis() - previous > timeout) {
				socket.send(terminate);
				previous = System.currentTimeMillis();
			}
		}

		System.out.println("Shutdown acknowledged. Terminating client...");

		float totalTime = (System.currentTimeMillis() - startTime) / (float) 1000;
		System.out.println("Total Transmission Time: " + totalTime + "s");

		// Goodbye
		socket.close();

	}

	public static class AckListener implements Runnable {

		private Map<Byte, ReliablePacket> packetMap;
		private DatagramSocket socket;

		public AckListener(Map<Byte, ReliablePacket> packetMap,
				DatagramSocket socket) {
			this.packetMap = packetMap;
			this.socket = socket;
		}

		@Override
		public void run() {

			for (;;) {

				DatagramPacket ackPacket = new DatagramPacket(new byte[1], 1);

				// Recieve the ack packet
				try {
					this.socket.receive(ackPacket);
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}

				try {
					lock.acquire();
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}

				// Remove the element from the hash table; sequence number
				// expected; however, that's not all.
				// Since this is a cumulative ack, we should remove everything
				// else that is below, as well
				this.packetMap.remove(ackPacket.getData()[0]);

				// Get our sequence number
				byte seqNum = ackPacket.getData()[0];
				
				ReliablePacket destructorPacket = this.packetMap.get(seqNum);
				
				Iterator<Map.Entry<Byte,ReliablePacket>> iter = this.packetMap.entrySet().iterator();
				while (iter.hasNext()) {
				    Map.Entry<Byte,ReliablePacket> entry = iter.next();
				    // Remove if the packet should be wiped out from a cumlative ack
				    if(entry.getValue().getUniqueId() < destructorPacket.getUniqueId()){
				        // Watch your step now! Are you serious?
				    	// Don't do this inside a for loop; safe iteration remove
				    	iter.remove();
				    }
				}
				
				// C'mon; two step OK
				
				
				
				// We need to update the oldest packet

				long newOldest = Long.MAX_VALUE;

				for (ReliablePacket packet : packetMap.values()) {
					if (packet.getTimestamp() < newOldest) {
						newOldest = packet.getTimestamp();
					}
				}

				Client.oldestPacketTime = newOldest;
				if (ackPacket.getData()[0] == -1) {
					return;
				}

				lock.release();
				System.out.println("Ack recieved: " + ackPacket.getData()[0]);
				
				
				
			}

		}

	}

}
