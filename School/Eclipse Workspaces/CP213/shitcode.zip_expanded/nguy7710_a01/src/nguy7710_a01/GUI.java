package nguy7710_a01;


import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;
import java.awt.Dimension;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import javax.swing.BorderFactory;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class GUI extends JPanel {
	JTextField address = new JTextField("");
	JTextField port = new JTextField("");
	public GUI() {
		try {
			JFrame connectionWindow = new JFrame();			// Create Window
			JPanel connectionPanel = new JPanel();			// Create Frame
			
			JTextField get_address = new JTextField("IP of Server:");
			get_address.setEditable(false);
			
			JTextField get_port = new JTextField("Connect at Port:");
			get_port.setEditable(false);
			
			JButton bConnect = new JButton("Connect");
			ActionHandler Pressed = new ActionHandler();
			
			bConnect.addActionListener(Pressed);
			connectionPanel.setLayout(new GridBagLayout());
			connectionPanel.setBorder(BorderFactory.createEmptyBorder(30, 30, 30, 30));
			GridBagConstraints gbc = new GridBagConstraints();
			gbc.fill = GridBagConstraints.BOTH;
			gbc.weightx = 1;
			
			connectionWindow.setSize(400, 300);
			connectionWindow.add(connectionPanel);
			
			connectionPanel.add(get_address, gbc);
			connectionPanel.add(address, gbc);
			gbc.gridy = 1;
			connectionPanel.add(get_port, gbc);
			connectionPanel.add(port, gbc);
			gbc.gridy = 2;
			connectionPanel.add(bConnect, gbc);
			
			connectionWindow.setTitle("Connect to Server..");
			connectionWindow.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			connectionWindow.setVisible(true);
		}
		catch(Exception e) {
			System.out.println("ERROR!!");
		}
	}
	
	public class ActionHandler implements ActionListener {
	    @Override
	       public void actionPerformed(ActionEvent evt){   	
	    		try {
	    			String hostName = address.getText();
		    		int portNumber = Integer.parseInt(port.getText());
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
	    		}catch(IOException e) {
	    			System.err.println("bro I/O shizz going on what?");
	    		}catch(Exception e) {
	    			System.err.println("bro wtf u even doing man");
	    		}
	    		
	    	}
	    	                    
	       }
    }