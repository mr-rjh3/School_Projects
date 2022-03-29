

import java.io.ByteArrayOutputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

/**
 * A chunked file returns a portion at a time when requested. The chunked file
 * itself for simplicity will read all the required data up front. This approach
 * is slightly naive as it will allocate a massive buffer up front for the files
 * but will reduce the I/O overhead as this simulation is about networking.
 * 
 * @author Vaughan Hilts
 *
 */
public class ChunkedFile {

	private FileInputStream m_internalStream;
	private final int CHUNK_SIZE = 124;

	private int m_offset = 0;
	private byte[] m_data;

	public ChunkedFile(String fileName) throws FileNotFoundException {
		// Get out stream ready for the incoming file provided to us
		m_internalStream = new FileInputStream(fileName);
		this.m_data = getBytesFromInputStream(this.m_internalStream);
	}

	/**
	 * Checks to see if the chunked file has been read entirley by
	 * "getByteChunk" already.
	 * 
	 * @return Returns true if the entire file has been read, false otherwise.
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
			byte[] buffer = new byte[4096];

			for (int len; (len = is.read(buffer)) != -1;)
				os.write(buffer, 0, len);

			os.flush();

			return os.toByteArray();
		} catch (IOException e) {
			return null;
		}
	}

}
