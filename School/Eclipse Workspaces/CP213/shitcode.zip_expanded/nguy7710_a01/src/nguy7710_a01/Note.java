package nguy7710_a01;

public class Note {

	String data;			// String
	String colour;			// Colour
	int x;					// X coordinate
	int y;					// Y coordinate
	boolean pinned = false; // State of being pinned
	Note next = null;
	
	public Note(String d, String c, int coordx, int coordy) {
		data = d;			
		colour = c;			
		x = coordx;					
		y = coordy;					
	}
	
	public void pin(int x, int y) {
		
		//
	}
	
	public boolean getPin() {
		return this.pinned;
	}
	
	public void togglePin() {
		this.pinned = !this.pinned;
		
	}
	
	public void shake() {
		
	}

} // End of Class
