
import java.io.IOException;
import java.net.DatagramSocket;
import java.net.SocketException;
import java.util.Random;

/**
 * Implements a reliable socket UDP datagram implementation. All of the
 * necessary implementation details are hidden within the socket class.
 * 
 * The only major details here are loss simulation.
 * 
 * @author Vaughan Hilts
 *
 */
public class ReliableSenderSocket extends DatagramSocket {

	private Random m_random = new Random();
	private int m_reliabilityNumber = 0;

	public ReliableSenderSocket(int port, int reliabilityNumber)
			throws SocketException {
		super(port);
		this.m_reliabilityNumber = reliabilityNumber;
	}

	/**
	 * A custom implementation of send which has the possibility of sometimes
	 * "losing" a packet rather than actually sending it.
	 */
	@Override
	public void send(java.net.DatagramPacket packet) throws IOException {
		int die = getRandomInt(1, this.m_reliabilityNumber);

		// Pseudo-lossy
		if (die == 1)
			return;

		super.send(packet);
	}

	/**
	 * A simple helper method to generate random integers between [min, max]
	 * inclusive.
	 */
	private int getRandomInt(int min, int max) {
		return this.m_random.nextInt(max - min + 1) + min;
	}

}
