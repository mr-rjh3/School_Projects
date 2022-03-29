package nguy7710_a01;

public class BBoard {
	
	Note front = null;
	Note rear = null;
	
	
	public String get(String data, String colour, int x, int y, Boolean pinned) {
		// 
		String content = "";
		
		Note current = this.front;
		
		
		return content;
	}
	
	public void post(String data, String colour, int x, int y) {
		Note NewNote = new Note(data, colour, x, y);
		// Is the board empty
		if(this.front == null) 
			// then it is the only note on the board
			this.front = this.rear = NewNote;
		
		else {
			// Otherwise insert into the rear
			this.rear.next = NewNote;
			this.rear = NewNote;
			// Was there only one note on the board
			if(this.rear == this.front)
				// If so then set front.next to the next note
				this.front.next = this.rear;
				
		}
		
	}
	
	public void pin(int x, int y) {
		
	}
	
	public void unpin(int x, int y) {
		
	}
	
	public void shake() {
		
	}
	
	public void clear() {
		// Empty the entire board
		this.front = null;
		this.rear = null;
		
	}

	
}
