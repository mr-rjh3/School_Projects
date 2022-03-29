package nguy7710_a01;
import java.io.*;
import java.net.*;
import java.lang.String;


public class ClientSide {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String hostName = "localhost";
		int portNumber = 7;
		
		try {
			Socket clientSocket = new Socket (hostName, portNumber);
			
			PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);
			BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
			BufferedReader stdIn = new BufferedReader(new InputStreamReader(System.in));
			
			String userInput;
			while((userInput = stdIn.readLine()) != null) {
				out.println(userInput);
				System.out.println("echo: " + in.readLine());
			}

			stdIn.close();
			in.close();
			out.close();
			clientSocket.close();
			
		}catch(UnknownHostException e) {
			System.err.println("brhhruh wrong host stoopid");
			System.exit(1);
		}catch(IOException e) {
			System.err.println("bro I/O shizz going on what?");
		}
		
	}

}
