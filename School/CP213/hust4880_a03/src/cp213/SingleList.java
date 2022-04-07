package cp213;

/**
 * A simple linked list structure of <code>Node T</code> objects. Only the
 * <code>T</code> data contained in the stack is visible through the standard
 * list methods. Extends the <code>SingleLink</code> class, which already
 * defines the head node, length, iterator, and toArray.
 *
 * @author your name here
 * @version 2021-02-05
 * @param <T> this SingleList data type.
 */
public class SingleList<T extends Comparable<T>> extends SingleLink<T> {

    /**
     * Searches for the first occurrence of key in this SingleList. Private helper
     * methods - used only by other ADT methods.
     *
     * @param key The value to look for.
     * @return A pointer to the node previous to the node containing key.
     */
    private SingleNode<T> linearSearch(final T key) {
    	// set current to front of list
    	SingleNode<T> curr = this.front;	
    	// If list is not empty, has more than one value, or the front is not the key value
    	if(!this.isEmpty() && this.length > 1 && curr.getData() != key) {	
    		// If the next node has the key value or the node after that is null end loop
	    	while(curr.getNext().getNext() != null && curr.getNext().getData().compareTo(key) != 0) 
	    		// Advances current node
	    		curr = curr.getNext();	
	    	if(curr.getNext().getData().compareTo(key) != 0) 
	    		// after while loop if value after current is not the key value it is not in the list
	    		curr = null;
    	}
    	// Special case: if key value is the first value of the list
    	// If list only has one value and it is not the key value current = null
    	else if(curr != null && curr.getData() != key) {	
    		curr = null;	
    	}		
    	// If the first value is the key value then return the node it is in because there is no previous node			
    		
    	return curr;
    }

    /**
     * Appends data to the end of this SingleList.
     *
     * @param data The data to append.
     */
    public void append(final T data) {

    	SingleNode<T> node = new SingleNode<T>(data, null);
    	if(this.isEmpty()) {
    		this.front = node;
    	}
    	else {
    		this.rear.setNext(node);
    	}
    	this.rear = node;
    	
    	this.length++;
    }

    /**
     * Removes duplicates from this SingleList. The list contains one and only one
     * of each value formerly present in this SingleList. The first occurrence of
     * each value is preserved.
     */
    public void clean() {
    	if(!this.isEmpty()) {
	    	SingleNode<T> curr = this.front;
	    	SingleNode<T> compare = curr;
	    	while(curr.getNext() != null) {
	    		while(compare.getNext() != null) {
	    			if(compare.getNext().getData().compareTo(curr.getData()) == 0) {
	    				compare.setNext(compare.getNext().getNext());
	    				this.length--;
	    			}
	    			else {
	    				compare = compare.getNext();
	    			}
	    		}
	    		if(curr.getNext() != null) {
	    			curr = curr.getNext();
	    			compare = curr;
	    		}
	    	}
	    	this.rear = curr;
    	}
    }

    /**
     * Combines contents of two lists into a third. Values are alternated from the
     * origin lists into this SingleList. The origin lists are empty when finished.
     * NOTE: data must not be moved, only nodes.
     *
     * @param left  The first list to combine with this SingleList.
     * @param right The second list to combine with this SingleList.
     */
    public void combine(final SingleList<T> left, final SingleList<T> right) {

    	SingleNode<T> node_left = left.front;
    	SingleNode<T> node_right = right.front;
    	boolean alternate = true;
    	while(node_left != null && node_right != null) {
    		if(!this.isEmpty()) {
    			
				if(alternate) {
					this.rear.setNext(node_left);
					this.rear = node_left;
					left.front = left.front.getNext();
					node_left = left.front;
					left.length--;
					
					if(node_left == null)
						left.rear = null;
				}
				else {
					this.rear.setNext(node_right);
					this.rear = node_right;
					right.front = right.front.getNext();
					node_right = right.front;
					right.length--;
					
					if(node_right == null)
						right.rear = null;
				}
				
    		}
    		else {
    			this.front = this.rear = node_left;
    			left.front = left.front.getNext();
				node_left = left.front;	
				left.length--;
    		}
    		this.length++;
    		alternate = !alternate;
    	}
    	
    	if(node_left != null) {
    		this.rear.setNext(node_left);
    		this.rear = left.rear;
    		this.length += left.length;
    		
    		left.rear = null;
    		left.front = null;
    		left.length = 0;
    	}
    	if(node_right != null) {
    		this.rear.setNext(node_right);
    		this.rear = right.rear;
    		this.length += right.length;
    		
    		right.rear = null;
    		right.front = null;
    		right.length = 0;
    	}
    }

    /**
     * Determines if this SingleList contains key.
     *
     * @param key The key value to look for.
     * @return true if key is in this SingleList, false otherwise.
     */
    public boolean contains(final T key) {
    	return this.linearSearch(key) != null;
    }

    /**
     * Finds the number of times key appears in list.
     *
     * @param key The value to look for.
     * @return The number of times key appears in this SingleList.
     */
    public int count(final T key) {
    	int num = 0;
    	if(!this.isEmpty()) {
	    	SingleNode<T> curr = this.front;
	    	while (curr.getNext() != null) {
	    		if(curr.getData().compareTo(key) == 0)
	    			num++;
	    		curr = curr.getNext();
	    	}
    	}
    	return num;
    }

    /**
     * Finds and returns the value in list that matches key.
     *
     * @param key The value to search for.
     * @return The value that matches key, null otherwise.
     */
    public T find(final T key) {
    	T data;
    	SingleNode<T> curr = this.linearSearch(key);
    	if(curr != null) {
	    	if(curr.getData().compareTo(key) == 0) 
	    		data = curr.getData();
	    	else
	    		data = curr.getNext().getData();
    	}
    	else 
    		data = null;
    	
	return data;
    }

    /**
     * Get the nth item in this SingleList.
     *
     * @param n The index of the item to return.
     * @return The nth item in this SingleList.
     * @throws ArrayIndexOutOfBoundsException if n is not a valid index.
     */
    public T get(final int n) throws ArrayIndexOutOfBoundsException {
    	T data = null;
    	if(!this.isEmpty()) {
	    	int count = 0;
	    	SingleNode<T> curr = this.front;
	    	
	    	while(count < n) {
	    		curr = curr.getNext();
	    		count++;
	    	}
	    	data = curr.getData();
    	}
    	return data;

    }

    /**
     * Determines whether two lists are identical.
     *
     * @param source The list to compare against this SingleList.
     * @return true if this SingleList contains the same values in the same order as
     *         source, false otherwise.
     */
    public boolean identical(final SingleList<T> source) {
    	SingleNode<T> curr = this.front;
    	SingleNode<T> source_curr = source.front;
    	boolean identical = false;
    	if(this.length == source.length) {
	    	while(curr.getNext() != null && curr.getData().compareTo(source_curr.getData()) == 0) {
	    		curr = curr.getNext();
	    		source_curr = source_curr.getNext();
	    	}
	    	if(curr.getData().compareTo(source_curr.getData()) == 0)
	    		identical = true;
    	}
    	return identical;
    }

    /**
     * Finds the first location of a value by key in this SingleList.
     *
     * @param key The value to search for.
     * @return The index of key in this SingleList, -1 otherwise.
     */
    public int index(final T key) {
    	// set current to front of list and i to 0
    	SingleNode<T> curr = this.front;
    	int i = 0;
    	// If list is not empty, has more than one value, or the front is not the key value
    	if(!this.isEmpty()) {	
    		// If the next node has the key value or the node after that is null end loop
	    	while(curr.getNext() != null && curr.getData().compareTo(key) != 0) {
	    		// Advances current node and increments i
	    		curr = curr.getNext();	
	    		i++;
	    	}
	    	if(curr.getData().compareTo(key) != 0) 
	    		// after while loop if value after current is not the key value it is not in the list
	    		i = -1;
    	}	
    		
    	return i;
    	
    	
    }

    /**
     * Inserts data into this SingleList at index i. If i greater than the length of
     * this SingleList, append value to the end of this SingleList.
     *
     * @param i    The index to insert the new value at.
     * @param data The new value to insert into this SingleList.
     */
    public void insert(int i, final T data) {
    	SingleNode<T> node = new SingleNode<T>(data, null);
    	if(!this.isEmpty()) {
        	SingleNode<T> curr = this.front;

    		int count = 0;
    		if(i == 0) {
    			node.setNext(this.front);
        		this.front = node;
    		}
    		else {
	    		while(curr.getNext() != null && count < i - 1) {
	    			curr = curr.getNext();
	    			count++;
	    		}
	    		node.setNext(curr.getNext());
	    		
	    		if(curr.getNext() == null) {
	    			this.rear = node;	
	    		}
	    		curr.setNext(node);
    		}

    	}
    	else {
    		this.front = node;
    		this.rear = node;
    	}
    	this.length++;

    }

    /**
     * Inserts data into the front of this SingleList.
     *
     * @param data The value to insert into the front of this SingleList.
     */
    public void prepend(final T data) {
    	SingleNode<T> node = new SingleNode<T>(data, null);
    	
    	if(this.isEmpty()) 
    		this.rear = node;
    	else 
    		node.setNext(this.front);
    	this.front = node;
    	this.length++;
    }

    /**
     * Finds the maximum value in this SingleList.
     *
     * @return The maximum value.
     */
    public T max() {
    	SingleNode<T> curr = this.front;
    	T max = null;
    	if(!this.isEmpty()) {
    		max = curr.getData();
    		while(curr != null) {
    			if(curr.getData().compareTo(max) > 0) 
    				max = curr.getData();
    			curr = curr.getNext();
    		}
    	}
    	return max;
    }

    /**
     * Finds the minimum value in this SingleList.
     *
     * @return The minimum value.
     */
    public T min() {

    	SingleNode<T> curr = this.front;
    	T min = null;
    	if(!this.isEmpty()) {
    		min = curr.getData();
    		while(curr != null) {
    			if(curr.getData().compareTo(min) < 0)
    				min = curr.getData();
    			curr = curr.getNext();
    		}
    	}
    	return min;
    }

    /**
     * Finds, removes, and returns the value in this SingleList that matches key.
     *
     * @param key The value to search for.
     * @return The value matching key, null otherwise.
     */
    public T remove(final T key) {
    	
    	SingleNode<T> curr = this.linearSearch(key);
    	T value = null;
    	// List is not empty and key is in list
    	if(this.length > 0 && curr != null) {	
    		// Normal case
	    	if(curr.getData() != key) { 
	    		// The value is the data in the node after current node
	    		value = curr.getNext().getData(); 
	    		
	    		// If data is at rear (set new rear)
	    		if(this.rear.getData() == curr.getNext().getData()) 
	    			// New rear becomes current node
	    			this.rear = curr;		
	    		
	    		// The node after the key value node becomes the new node after current node
	    		curr.setNext(curr.getNext().getNext());			
	    		
	    	}
	    	// Special Case: If the key is in the front node
	    	else if(curr.getData() == key) { 
	    		// The value to return becomes the current node value
	    		value = curr.getData();	
	    		
	    		// If there is only one node in the list, it will become empty
	    		if(this.length == 1) {	
	    			this.front = null;
	    			this.rear = null;	
	    		}
	    		// If there is more than one node left in the list
	    		else {	
	    			// The front becomes the one after the previous front
	    			this.front = this.front.getNext();	
	        		
	    		}
	    		
	    	}
	    	// As long as the list is not empty the length will decrease by one
	    	this.length--;	
    	}
    	
    	return value;
    }

    /**
     * Removes the value at the front of this SingleList.
     *
     * @return The value at the front of this SingleList.
     */
    public T removeFront() {
    	
    	T data = null;
    	if(!this.isEmpty()) {
    		data = this.front.getData();
    		if(this.length == 1) {
    			this.front = null;
    			this.rear = null;
    		}
    		else {
    			this.front = this.front.getNext();
    		}
    		
    		this.length--;
    	}
    	return data;
    }
    	

    /**
     * Reverses the order of the values in this SingleList.
     */
    public void reverse() {
    	// Declare traversal nodes
    	SingleNode<T> prev = null;
    	SingleNode<T> curr = this.front;
    	SingleNode<T> next = null;
    	
    	if(!this.isEmpty()) {
    		// While current node has not reached the end of the list
    		while (curr != null) {
    			// Set next node to the node after current node
    			next = curr.getNext();
    			// Set current's next to the previous node
    			curr.setNext(prev);
    			// Set previous to be the current
    			prev = curr;
    			// Set current to the next node in the list
    			curr = next;
    			
    		}
    		// At the end swap the rear and front nodes of the list
    		this.rear = this.front;
    		this.front = prev;
    		
    	}
    }

    /**
     * Splits the contents of this SingleList into the left and right SingleLists.
     * Moves nodes only - does not move data or call the high-level methods insert
     * or remove. this SingleList is empty when done. The first half of this
     * SingleList is moved to left, and the last half of this SingleList is moved to
     * right. If the resulting lengths are not the same, left should have one more
     * item than right. Order is preserved.
     *
     * @param left  The first SingleList to move nodes to.
     * @param right The second SingleList to move nodes to.
     */
    public void split(final SingleList<T> left, final SingleList<T> right) {
    	if(!this.isEmpty()) {
        	SingleNode<T> curr = this.front;
        	int count = 0;
        	while(curr != null) {
        		// check which list to insert into
        		if(count < this.length/2) {
        			// If left is empty insert into front
        			if(left.front == null) {
        				left.front = left.rear = curr;
        			}
        			// Otherwise insert into rear
        			else {
        				left.rear.setNext(curr);
        				left.rear = curr;
        			}
        			curr = curr.getNext();
        			left.rear.setNext(null);
        			left.length++;
        		}
        		else {
        			// If right is empty insert into front
        			if(right.front == null) {
        				right.front = right.rear = curr;
        			}
        			// Otherwise insert into rear
        			else {
        				right.rear.setNext(curr);
        				right.rear = curr;
        			}
        			curr = curr.getNext();
        			right.rear.setNext(null);
        			right.length++;
        		}
        		count++;
        	}
        	this.front = null;
        	this.rear = null;
        	this.length = 0;
    	  }

    }

    /**
     * Splits the contents of this SingleList into the left and right SingleLists.
     * Moves nodes only - does not move data or call the high-level methods insert
     * or remove. this SingleList is empty when done. Nodes are moved alternately
     * from this SingleList to left and right. Order is preserved.
     *
     * @param left  The first SingleList to move nodes to.
     * @param right The second SingleList to move nodes to.
     */
    public void splitAlternate(final SingleList<T> left, final SingleList<T> right) {

    	if(!this.isEmpty()) {
        	SingleNode<T> curr = this.front;
        	boolean alternate = true;
        	while(curr != null) {
        		// check which list to insert into
        		if(alternate) {
        			// If left is empty insert into front
        			if(left.front == null) {
        				left.front = left.rear = curr;
        			}
        			// Otherwise insert into rear
        			else {
        				left.rear.setNext(curr);
        				left.rear = curr;
        			}
        			curr = curr.getNext();
        			left.rear.setNext(null);
        			left.length++;
        		}
        		else {
        			// If right is empty insert into front
        			if(right.front == null) {
        				right.front = right.rear = curr;
        			}
        			// Otherwise insert into rear
        			else {
        				right.rear.setNext(curr);
        				right.rear = curr;
        			}
        			curr = curr.getNext();
        			right.rear.setNext(null);
        			right.length++;
        		}
        		// Advance current node and swap boolean
        		
        		alternate = !alternate;
        	}
        	this.front = null;
        	this.rear = null;
        	this.length = 0;
    	  }

        }

    /**
     * Creates a union of two other SingleLists into this SingleList. Copies data to
     * this list. left and right SingleLists are unchanged.
     *
     * @param left  The first SingleList to create a union from.
     * @param right The second SingleList to create a union from.
     */
    public void union(final SingleList<T> left, final SingleList<T> right) {
    	
    	if(this.isEmpty()) {
	    	SingleNode<T> curr = left.front;
	    	SingleNode<T> compare = right.front;
	    	boolean found = false;
	    	// While we haven't reached the end of the list
	    	while(curr != null) {
	    		// Look through the list and see if there are any duplicates
	    		while(compare != null && !found) {
	    			// If the compare node is equal to the current node we have a duplicate
	    			if(compare.getData().compareTo(curr.getData()) == 0) {
	    				this.append(curr.getData());
	    				found = true;
	    			}
	    			// Otherwise increment compare
	    			else
	    				compare = compare.getNext();
	    			
	    		}
    			curr = curr.getNext();
    			compare = right.front;
    			found = false;
	    		}
	    	}
	    	this.clean();
    	}
    }

