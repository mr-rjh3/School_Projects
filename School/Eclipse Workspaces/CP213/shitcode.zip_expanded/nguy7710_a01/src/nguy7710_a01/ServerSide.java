package nguy7710_a01;
import java.net.*;
import java.io.*;

public class ServerSide {

	public static void main(String[] args) throws IOException{
		// Initalize the port number
		int portNumber = 7;
		try {
			// Create server socket
			ServerSocket serverSocket = new ServerSocket(portNumber);  // given port number
			// Wait for connection to a client
			Socket clientSocket = serverSocket.accept();
			
			
			PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);
			BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
			
			String inputLine;
			while((inputLine = in.readLine()) != null){
				out.println(inputLine);
			}
			
			in.close();
			out.close();
			clientSocket.close();
			serverSocket.close();
			
		// If invalid port / error on when listening, then catches the generated error and exits
		} catch (IOException e) {
			System.out.print("Exception caught when trying to listen on port " + portNumber + " or listening for connection");
			System.out.println(e.getMessage());
			System.exit(1);
		}
		
	} // END OF MAIN
	
	
	public void disconnect(ServerSocket server, Socket client) throws IOException{
		server.close();
		client.close();
		
	}

}
