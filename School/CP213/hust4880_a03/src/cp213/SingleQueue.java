package cp213;

/**
 * A simple linked queue structure of <code>Node T</code> objects. Only the
 * <code>T</code> data contained in the queue is visible through the standard
 * queue methods. Extends the <code>SingleLink</code> class, which already
 * defines the head node, length, peek, isEmpty, and iterator.
 *
 * @author your name here
 * @version 2021-02-05
 * @param <T> the SingleQueue data type.
 */
public class SingleQueue<T> extends SingleLink<T> {

    /**
     * Combines the contents of the left and right SingleQueues into the current SingleQueue.
     * Moves nodes only - does not move data or call the high-level methods insert
     * or remove. left and right SingleQueues are empty when done. Nodes are moved
     * alternately from left and right to this SingleQueue.
     *
     * You have two queues called left and right queues. You remove nodes from these
     * two queues to create a new queue (current queue).
     *
     * If the current queue is empty or not, it should not make a difference to you.
     * you just get nodes from the right and left queues and add them to the current
     * queue. Do not use insert and remove methods. . Use moveFront method included
     * in the class.
     *
     * Remember to remove a node from the list you have to update the reference or
     * the pointer that is pointing to the current node.
     *
     * The getNext () and setNext() methods from SingleNode class can be used for
     * these purpose.
     *
     * Do not assume that both right and left queues are of the same length.
     *
     * @param left  The first SingleQueue to extract nodes from.
     * @param right The second SingleQueue to extract nodes from.
     */
    public void combine(final SingleQueue<T> left, final SingleQueue<T> right) {
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
     * Adds data to the rear of the queue. Increments the queue length.
     *
     * @param data The data to added to the rear of the queue.
     */
    public void insert(final T data) {

    	SingleNode<T> node = new SingleNode<T>(data, null);
    	if(!this.isEmpty()) 
    		this.rear.setNext(node);
    	else 
    		this.front = node;
    	
    	this.rear = node;
    	this.length++;

    }

    /**
     * Returns the front data of the queue and removes that data from the queue. The
     * next node in the queue becomes the new first node. Decrements the queue
     * length.
     *
     * @return The data at the front of the queue.
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
     * Splits the contents of the current SingleQueue into the left and right SingleQueues.
     * Moves nodes only - does not move data or call the high-level methods insert
     * or remove. this SingleQueue is empty when done. Nodes are moved alternately from
     * this SingleQueue to left and right.
     *
     * This is the opposite of the combine method.
     *
     * @param left  The first SingleQueue to move nodes to.
     * @param right The second SingleQueue to move nodes to.
     */
    public void split(final SingleQueue<T> left, final SingleQueue<T> right) {

    if(!this.isEmpty()) {
    	SingleNode<T> curr = this.front;
    	boolean alternate = true;
    	while(curr.getNext() != null) {
    		// check which queue to insert into
    		if(alternate) {
    			// If left is empty insert into front
    			if(this.front == null) {
    				left.front = curr;
    				left.rear = curr;
    			}
    			// Otherwise insert into rear
    			else {
    				left.rear.setNext(curr);
    				left.rear = curr;
    			}
    			left.length++;
    		}
    		else {
    			// If right is empty insert into front
    			if(right.front == null) {
    				right.front = curr;
    				right.rear = curr;
    			}
    			// Otherwise insert into rear
    			else {
    				right.rear.setNext(curr);
    				right.rear = curr;
    			}
    			right.length++;
    		}
    		// Advance current node and swap boolean
    		curr = curr.getNext();
    		alternate = !alternate;
    	}
    	this.front = null;
    	this.rear = null;
    	this.length = 0;
	  }

    }

}