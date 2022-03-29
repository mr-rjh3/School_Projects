import java.io.FileNotFoundException;
import java.io.IOException;
import java.net.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.Semaphore;
import java.io.ByteArrayOutputStream;
import java.io.FileInputStream;

/**
	 * Client side implementation.
	 * 
	 * A sample file transfer client that will load bytes from from files
	 *  and send them to a server.
	 * 
	 * The Client is relatively simple. It uses UDP to continually send packets
	 * It resends packets until it receives an ack for each unique segment of data
	 * that has been sent.
	 * 
	 * @author Vaughan Hilts & Brandon Smith
	 *
*/
public class Client {

	// We need a way of storing packets that are yet to recieve acknowledge;
	// we'll do so here
	private static Map<Byte, ReliablePacket> unackedPackets = new ConcurrentHashMap<Byte, ReliablePacket>();

	private static final Semaphore lock = new Semaphore(1);

	// A 2s timeout is plenty
	// TODO: Make this variable depending on network conditions

	public static long oldestPacketTime = 0;

	public static void main(String[] args) throws InterruptedException,
			IOException {

		System.out.println("Client started with parameters: ");
		for (String arg : args) {
			System.out.println(arg);
		}
		// initilize the values
		String hostAddress = "";
		int portClient, portHost;
		String fileName = "";
		int reliabilityNumber = 0;
		int windowSize = 0;
		int timeout = 200;
		// Blank line
		System.out.println("");

		try {
			// Put the parameters in the correct locations
			hostAddress = args[0];
			portClient = Integer.parseInt(args[1]);
			portHost = Integer.parseInt(args[2]);
			fileName = args[3];
			reliabilityNumber = Integer.parseInt(args[4]);
		} catch (Exception e) {
			System.out
					.println("The given command line arguments were not valid. "
							+ "Check your parameters and then try again.");
			return;
		}

		windowSize = 1;

		// Make sure reliability number is non-negative
		if (reliabilityNumber < 0) {
			System.out
					.println("The reliability number must be 0 or greater and a valid integer.");
			return;
		}

		long startTime = System.currentTimeMillis();

		// set up a chunked file see chunked file class.
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
			// is this the socket were working from?
			socket = new ReliableSenderSocket(portClient, reliabilityNumber);
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

		Boolean transmitComplete = false;

		// initilize values for future calculations
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
								IPAddress, portHost));
						chunksSent++;
					} catch (IOException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}

				} else {

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
							IPAddress, portHost));
				}

				// Reset timer
				System.out.println(System.currentTimeMillis());
				oldestPacketTime = System.currentTimeMillis();
			}

			lock.release();

		}

		// print when we start shutting down
		System.out
				.println("All "
						+ chunksSent
						+ " file chunks acknowledged. Awaiting shutdown confirmation...");
		// need one more byte
		byte[] temp = new byte[1];
		// Byte will contain a sequence number of -1
		ReliablePacket packet = new ReliablePacket((byte) -1, temp,
				System.currentTimeMillis());

		unackedPackets.put((byte) -1, packet);
		// Build our terminate packet

		DatagramPacket terminate = new DatagramPacket(
				packet.getPacketPayload(), packet.getPacketPayload().length,
				IPAddress, portHost);

		long previous = System.currentTimeMillis();
		socket.send(terminate);
		// wait until we receive our final acknowledgement pulsing the terminate
		// packet as we go
		while (unackedPackets.isEmpty() == false) {
			if (System.currentTimeMillis() - previous > timeout) {
				socket.send(terminate);
				previous = System.currentTimeMillis();
			}
		}

		System.out.println("Shutdown acknowledged. Terminating client...");
		// log the time
		float totalTime = (System.currentTimeMillis() - startTime)
				/ (float) 1000;
		System.out.println("Total Transmission Time: " + totalTime + "s");

		// Goodbye
		socket.close();

	}

	// This is the Ack listener
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
					System.out.println("Acquiring issues...");
					e.printStackTrace();
				}

				// Remove the element from the hash table; sequence number
				// expected; however, that's not all.
				// Since this is a cumulative ack, we should remove everything
				// else that is below, as well

				// Get our sequence number
				byte seqNum = ackPacket.getData()[0];

				ReliablePacket destructorPacket = this.packetMap.get(seqNum);

				if (destructorPacket != null) {

					this.packetMap.remove(ackPacket.getData()[0]);

					Iterator<Map.Entry<Byte, ReliablePacket>> iter = this.packetMap
							.entrySet().iterator();
					while (iter.hasNext()) {
						Map.Entry<Byte, ReliablePacket> entry = iter.next();
						// Remove if the packet should be wiped out from a
						// cumlative ack
						if (entry.getValue().getUniqueId() < destructorPacket
								.getUniqueId()) {
							// Watch your step now! Are you serious?
							// Don't do this inside a for loop; safe iteration
							// remove
							System.out.println("Removing excessive ack");
							iter.remove();
						}
					}

				}

				// update the oldest packet
				long newOldest = Long.MAX_VALUE;
				// gets teh oldest packets time
				for (ReliablePacket packet : packetMap.values()) {
					if (packet.getTimestamp() < newOldest) {
						newOldest = packet.getTimestamp();
					}
				}
				// sets our time to the new oldest time.
				Client.oldestPacketTime = newOldest;
				if (ackPacket.getData()[0] == -1) {
					return;
				}

				lock.release();
				System.out.println("Ack recieved: " + ackPacket.getData()[0]);

			}

		}

	}

	/**
	 * A chunked file returns a portion at a time when requested. The chunked
	 * file itself for simplicity will read all the required data up front. This
	 * approach is slightly naive as it will allocate a massive buffer up front
	 * for the files but will reduce the I/O overhead as this simulation is
	 * about networking.
	 * 
	 * @author Vaughan Hilts & Brandon Smith
	 *
	 */
	public static class ChunkedFile {

		// Make constants
		private final int CHUNK_SIZE = 124;
		private final static int BUFFER_LEN = 4096;

		// Initialize values used in chunked file
		private int m_offset = 0;
		private byte[] m_data;
		private FileInputStream m_internalStream;

		public ChunkedFile(String fileName) throws FileNotFoundException {
			// Get out stream ready for the incoming file provided to us
			m_internalStream = new FileInputStream(fileName);
			this.m_data = getBytesFromInputStream(this.m_internalStream);
		}

		/**
		 * Checks to see if the chunked file has been read entirley by
		 * "getByteChunk" already.
		 * 
		 * @return Returns true if the entire file has been read, false
		 *         otherwise.
		 */
		public boolean isDataLeft() {
			return this.m_offset != this.m_data.length;
		}

		/**
		 * Returns the next few bytes in chunked increments available from the
		 * filesystem to the caller.
		 * 
		 * @return The chunked bytes
		 * @throws IOException
		 *             Throws if an I/O error occurs for some reason
		 */
		public byte[] getByteChunk() throws IOException {
			byte[] b = new byte[CHUNK_SIZE];
			int length = b.length;

			if (this.m_offset == this.m_data.length) {
				// close down the link
				System.out.println("It's over");
			}

			if (this.m_offset + b.length > this.m_data.length) {
				// TODO: Poor man's implementation, throttle hard!
				length = 1;
				b = new byte[length];
			}

			// Copy our data into where need it to be
			System.arraycopy(this.m_data, this.m_offset, b, 0, length);

			this.m_offset += length;

			return b;
		}

		/**
		 * Given a file input streams, reads all the data and returns it as a
		 * buffer.
		 * 
		 * @param is
		 *            The input file stream to use and read all the data out of.
		 * @return An array of byte data contained in the file
		 */
		private static byte[] getBytesFromInputStream(FileInputStream is) {
			try (ByteArrayOutputStream os = new ByteArrayOutputStream();) {
				// make a new byte list of length buffer
				byte[] buffer = new byte[BUFFER_LEN];

				for (int len; (len = is.read(buffer)) != -1;)
					os.write(buffer, 0, len);
				// Force anything buffered to to written immediately
				os.flush();

				return os.toByteArray();
			} catch (IOException e) {
				// something went wrong return null
				return null;
			}
		}

	}

	/**
	 * A reliable packet implementation that encapsulates data for reliable file
	 * transfer over UDP. The sequence number, payload, and timestamp are
	 * recorded. Generally, a reliable packet is immutable with the exception of
	 * the timestamp.
	 * 
	 * Upon retransmission, the timestamp should be updated so the timer can
	 * ticked down.
	 * 
	 * @author Vaughan Hilts & Brandon Smith
	 *
	 */
	public static class ReliablePacket {

		// constants we may want to change later
		private static final int HEADER_SIZE = 3;
		private static final int BYTES = 255;
		// Initialize the variables for the class
		private byte m_sequenceNumber = 0;
		private byte[] m_payload;
		private long m_timestamp;

		private long m_id = 0;
		// a variable shared between the packets to easily differentiate between
		// packets
		private static long uId = 0;

		public ReliablePacket(byte sequenceNumber, byte[] payload,
				long timestamp) {
			// builds the packet based on the given info
			this.m_payload = payload;
			this.m_sequenceNumber = sequenceNumber;
			this.m_timestamp = timestamp;
			this.m_id = uId++;
		}

		public byte getSequenceNumber() {
			// gets the sequence number for a packet
			return this.m_sequenceNumber;
		}

		public long getTimestamp() {
			// Retrieves the time stamp on a packet
			return this.m_timestamp;
		}

		public void setTimestamp(long time) {
			// sets the time stamp on a packet
			this.m_timestamp = time;
		}

		public long getUniqueId() {
			// gets the id of a packet
			return this.m_id;
		}

		public byte[] getPacketPayload() {
			byte[] packetData = new byte[this.m_payload.length + HEADER_SIZE];
			byte[] payload = this.m_payload;

			// Copy the payload out
			System.arraycopy(payload, 0, packetData, HEADER_SIZE,
					payload.length);

			// Shove in the sequence number
			packetData[0] = this.m_sequenceNumber;

			// TODO: Do something with this big of flag data; can use to signify
			// ACK, TEARDOWN etc
			// Of course, set it to something other than 255 as well
			packetData[1] = (byte) BYTES;

			packetData[2] = (byte) payload.length;

			return packetData;
		}

	}

	/**
	 * Implements a reliable socket UDP datagram implementation. All of the
	 * necessary implementation details are hidden within the socket class.
	 * 
	 * The only major details here are loss simulation.
	 * 
	 * @author Vaughan Hilts & Brandon Smith
	 *
	 */
	public static class ReliableSenderSocket extends DatagramSocket {

		private Random m_random = new Random();
		private int m_reliabilityNumber = 0;

		// Constructor for our socket
		public ReliableSenderSocket(int port, int reliabilityNumber)
				throws SocketException {
			super(port);
			// Pseudo reliability number set to this socket
			this.m_reliabilityNumber = reliabilityNumber;
		}

		/**
		 * A custom implementation of send which has the possibility of
		 * sometimes "losing" a packet rather than actually sending it.
		 */
		@Override
		public void send(java.net.DatagramPacket packet) throws IOException {

			// If the number is zero we dont simulate loss
			if (this.m_reliabilityNumber != 0) {
				// this generates a random integer between 1 and a value given
				// at start up
				int die = getRandomInt(1, this.m_reliabilityNumber);

				// if the given value is a 1 then the packet is not actually
				// sent
				if (die == 1)
					return;

			}

			super.send(packet);
		}

		/**
		 * A simple helper method to generate random integers between [min, max]
		 * inclusive.
		 */
		private int getRandomInt(int min, int max) {
			// this generates our random number
			return this.m_random.nextInt(max - min + 1) + min;
		}

	}

}
