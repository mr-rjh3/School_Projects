package cp213;

import java.awt.Dimension;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.WindowConstants;
//new
import javax.swing.ImageIcon;
import javax.swing.SwingConstants;
import java.awt.TextField;
import javax.swing.JButton;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JTextArea;


//import javax.swing.border.EmptyBorder;

/**
 * Handles the GUI portion of the vending machine. May use other GUI classes for
 * individual elements of the vending machine. Should use the VendModel for all
 * control logic.
 *
 * @author your name here
 * @version 2021-03-19
 */
@SuppressWarnings("serial")
public class VendView extends JPanel {

    private VendModel model = null;
    protected JTextArea textInput = new JTextArea();
    protected String item = "";
    
    public VendView(VendModel model) {
    	this.model = model;
    	
    	
    	
		// your code here
    	try {
    		
	    	this.setPreferredSize(new Dimension(650,300));
	    
	    	// Chocolate
    		
    		JPanel ChocolatePanel = new JPanel();
    		ChocolatePanel.setPreferredSize(new Dimension(500, 700));
			
	    	GridBagConstraints gbc_Chocolate = new GridBagConstraints();
			this.setLayout(new GridBagLayout());
			gbc_Chocolate.fill = GridBagConstraints.BOTH;
			gbc_Chocolate.weightx = 1;
			gbc_Chocolate.weighty = 1;
			
			for (int i = 0; i < 30; i++) {
				JLabel chocolate = new JLabel(new ImageIcon("chocolate-bar-small.png"));
				if(i < 5)
					chocolate.setText("A" + String.valueOf(i));
				else if(i >= 5 && i < 10)
					chocolate.setText("B" + String.valueOf(i - 5));
				else if(i >= 10 && i < 15)
					chocolate.setText("C" + String.valueOf(i - 10));
				else if(i >= 15 && i < 20)
					chocolate.setText("D" + String.valueOf(i - 15));
				else if(i >= 20 && i < 25)
					chocolate.setText("E" + String.valueOf(i - 20));
				else if(i >= 25 && i < 30)
					chocolate.setText("F" + String.valueOf(i - 25));
				chocolate.setHorizontalTextPosition(JLabel.CENTER);
				chocolate.setVerticalTextPosition(JLabel.BOTTOM);
				ChocolatePanel.add(chocolate, gbc_Chocolate);

				}
			this.add(ChocolatePanel);
			
    		// Buttons
	    	JPanel NumButtons = new JPanel();
	    	NumButtons.setPreferredSize(new Dimension(150, 400));
	    	int index = 0;
	    	char letter = 'A';
	    	GridBagConstraints gbc = new GridBagConstraints();
	    	ActionHandler Pressed = new ActionHandler();
			//this.setLayout(new GridBagLayout());
    		gbc.fill = GridBagConstraints.BOTH;
			for(int col = 0; col < 3; col++) {
				gbc.gridy = col;
				for (int row = 0; row < 6; row++) {
					JButton b;
					if(index < 6)
						b = new JButton(String.valueOf(letter++));
					else if(index >= 6 && index < 15)
						b = new JButton(String.valueOf(index - 5));
					else if(index == 15)
						b = new JButton("*");
					else if(index == 16)
						b = new JButton("0");
					else
						b = new JButton("#");
					b.addActionListener(Pressed);
					gbc.gridx = row;
					NumButtons.add(b , gbc);
					index++;
					}
			}

			// Message Box
			textInput.setPreferredSize(new Dimension(150, 20)); // change size of text field
			textInput.setAlignmentX(JTextArea.RIGHT_ALIGNMENT);
			NumButtons.add(textInput); // add text field to window
			
			
			
			JButton Cash = new JButton("Cash");
			gbc.gridx = 0;
			gbc.gridy = 0;
			NumButtons.add(Cash , gbc);
			JButton Credit = new JButton("Credit");
			gbc.gridx = 1;
			NumButtons.add(Credit , gbc);
			
			
			JButton FiveC = new JButton("5¢");
			gbc.gridx = 1;
			gbc.gridy = 1;
			FiveC.addActionListener(Pressed);
			NumButtons.add(FiveC , gbc);
			
			JButton TenC = new JButton("10¢");
			gbc.gridx = 1;
			gbc.gridy = 1;
			TenC.addActionListener(Pressed);
			NumButtons.add(TenC , gbc);
			
			JButton TwentyFiveC = new JButton("25¢");
			gbc.gridx = 2;
			gbc.gridy = 1;
			TwentyFiveC.addActionListener(Pressed);
			NumButtons.add(TwentyFiveC , gbc);
			
			JButton OneD = new JButton("$1");
			gbc.gridx = 0;
			gbc.gridy = 2;
			OneD.addActionListener(Pressed);
			NumButtons.add(OneD , gbc);
			
			JButton FiveD = new JButton("$5");
			gbc.gridx = 1;
			gbc.gridy = 2;
			FiveD.addActionListener(Pressed);
			NumButtons.add(FiveD , gbc);
			
			JButton TenD = new JButton("$10");
			gbc.gridx = 2;
			gbc.gridy = 2;
			TenD.addActionListener(Pressed);
			NumButtons.add(TenD , gbc);
			
			JButton Clear = new JButton("Clear");
			gbc.gridx = 2;
			Clear.addActionListener(Pressed);
			NumButtons.add(Clear , gbc);
			
			add(NumButtons);
    	}
    	catch(Exception e) {
    		System.out.println("ERROR!!");
    	}
		
    }
 // Class to deal with when a button is pressed
    public class ActionHandler implements ActionListener {
	    @Override
	       public void actionPerformed(ActionEvent e) {
	    	   Object source = e.getSource();
	    	   JButton b = (JButton) source;
	    	   String str = "";
	    	   
	    	   if(b.getText() == "Clear")
	    		   textInput.setText("");
	    	   else if(b.getText() == "#") {
	    		   // Item Selected
	    		   item = textInput.getText();
	    		   textInput.setText("");
	    	   }
	    	   else if(b.getText().contains("¢")) {
	    		   str = b.getText().replace("¢", "");
	    	   }
	    	   else if(b.getText().contains("$")) {
	    		   str = b.getText().replace("$", "");
	    	   }
	    	   else
	    		   str = b.getText();
	    	   textInput.append(str);
	    		   
	    	                    
	       }
    }
    


}