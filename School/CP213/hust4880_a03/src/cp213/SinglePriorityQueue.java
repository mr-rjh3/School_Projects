package cp213;

/**
 * A simple linked priority queue structure of <code>Node T</code> objects.
 * These data objects must be Comparable - i.e. they must provide the compareTo
 * method. Only the <code>T</code> data contained in the priority queue is
 * visible through the standard stack methods. Extends the
 * <code>SingleLink</code> class, which already defines the head node, length,
 * peek, isEmpty, and iterator.
 *
 * @author your name here
 * @version 2021-02-05
 * @param <T> data type for base data structure.
 */
public class SinglePriorityQueue<T extends Comparable<T>> extends SingleLink<T> {

    /**
     * Adds data to the SinglePriorityQueue. Data is stored in priority order, with
     * highest priority data at the front of the SinglePriorityQueue, and lowest at
     * the rear. Priority is determined by simple comparison - lower values have
     * higher priority. For example, 1 has a higher priority than 2 because 1 is a
     * lower value than 2. (Think of the phrase, "We're number one!" as an
     * indication of priority.)
     *
     * When inserting data to the priority queue, the queue must remain sorted.
     * Hence you need to find the proper location of inserting data. use the head
     * pointer to go through the queue. e.g., use SingleNode<T> current = this.head;
     *
     * use current = current.getNext(); to traverse the queue.
     *
     * To get access to the value inside a node of queue use current.getValue().
     *
     * @param data data to insert in sorted order in priority queue.
     */
    public void insert(final T data) {
    	
    	SingleNode<T> insert_node = new SingleNode<T>(data, null);
    	
    	
    	// first, see if the queue is empty
    	if(!this.isEmpty()) { 
    		
    		
    		// second, see if the data is less than or equal to the front
        	if(data.compareTo(this.front.getData()) <= 0) {
        		// if it is insert it into front
        		insert_node.setNext(this.front);
        		this.front = insert_node;
        	}
        	// Otherwise we must traverse the queue to find the appropriate place for the insert data
        	else {
        		// set 2 traversal nodes
        		SingleNode<T> prev = this.front;
            	SingleNode<T> curr = this.front.getNext();
            	boolean inserted = false;
        		// While the data has not been inserted and current node is not null (at the end of the list) loop
        		while(!inserted && curr != null) {
        			// If the insert data is less than or equal to the current node
        			if(data.compareTo(curr.getData()) <= 0) {
        				// insert the node behind the current node
        				prev.setNext(insert_node);
        				insert_node.setNext(curr);
        				inserted = true;
        			}
        			// Move current and previous nodes to the next nodes in the queue
        			prev = curr;
        			curr = curr.getNext();
        		}
        		// If the node was not inserted after the loop we reached the end of the queue
        		if(!inserted) {
        			// Insert node into the rear of the queue
        			prev.setNext(insert_node);
        			this.rear = insert_node;
        		}
        	}
    	}
    	// If the queue is empty we insert the data into the front / rear
    	else 
    		this.front = this.rear = insert_node;
    	// Increment length
    	this.length++;
    }

    /**
     * Returns the highest priority data in the SinglePriorityQueue. Decrements the
     * count.
     *
     * @return the highest priority data currently in the SinglePriorityQueue.
     */
    public T remove() {

    	T data = null;
    	if(!this.isEmpty()) {
    		data = this.front.getData();
    		this.front = this.front.getNext();
    		this.length--;
    	}
    	return data;

    }

    /**
     * Splits the contents of this SinglePriorityQueue into the higher and lower
     * SinglePriorityQueue. Moves nodes only - does not move data or call the
     * high-level methods insert or remove. this SinglePriorityQueue is empty when
     * done. Nodes with priority value higher than key are moved to the
     * SinglePriorityQueue higher. NOdes with a priority value lower than or equal
     * to key are moved to the SinglePriorityQueue lower.
     *
     * 1. if the queue is empty do nothing.
     *
     * 2. If the key is less than the value inside the head of the queue, the head
     * of the lower queue should point where currently the head of the queue is
     * pointing to, and the higher queue will be empty.
     *
     * 3. Otherwise, you go through the queue until you find the first node with a
     * value less than the key. Once found, the head of the lower queue should point
     * to that node. And the head of the higher pointer should point to the first
     * node in the queue.
     *
     * 4. If all node values bigger than Key, the lower queue will be empty.
     *
     * Remember because the key is class type you need to use compreTo when
     * comparing values. e.g., key.compareTo(this.head.getValue()) <= 0
     *
     * @param key    value to compare against node values in SinglePriorityQueue
     * @param higher an initially empty SinglePriorityQueue queue that ends up with
     *               all values with priority higher than key.
     * @param lower  an initially empty SinglePriorityQueue queue that ends up with
     *               all values with priority lower than or equal to key.
     */
    public void splitByKey(final T key, final SinglePriorityQueue<T> higher, final SinglePriorityQueue<T> lower) {
	    // Queue must not be empty
    	if(!this.isEmpty()) {
    		// Special Case: Front is equal to key
    		if(this.front.getData().compareTo(key) > 0) {
    			lower.front = this.front;
    			lower.rear = this.rear;
    			lower.length = this.length;	
    		}
    		else {
    			// Create Traversal node and integer to keep track of position
	        	SingleNode<T> curr = this.front;
	        	int count = 1;
	        	// While loop that goes through queue until curr's next is less or equal priority than key
	        	while (curr.getNext().getNext() != null && curr.getNext().getData().compareTo(key) <= 0) {
	        		curr = curr.getNext();
	        		count++;
	        	}
	        	// If we did not reach the end of the list then we found where we split the queue
	        	if(curr.getNext().getNext() != null) {
	        		// Set lower queue
	        		lower.front = curr.getNext();
	        		lower.rear = this.rear;
	        		lower.length = this.length - count;
	        		
	        		// Set higher queue
	        		curr.setNext(null);
	        		higher.front = this.front;
	        		higher.rear = curr;
	        		higher.length = count;
	
	        	}
	        	// Otherwise all values are of greater priority than key
	        	else {
	        		// Higher queue then would equal this queue
	        		higher.front = this.front;
	    			higher.rear = this.rear;
	    			higher.length = this.length;
	        	}
    		}
    		// Delete this queue
    		this.front = null;
    		this.rear = null;
    		this.length = 0;
	    }
    }
}