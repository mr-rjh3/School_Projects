package cp213;

/**
 * A simple linked stack structure of <code>Node T</code> objects. Only the
 * <code>T</code> data contained in the stack is visible through the standard
 * stack methods. Extends the <code>SingleLink</code> class, which already
 * defines the head node, length, peek, isEmpty, and iterator.
 *
 * @author your name here
 * @version 2021-02-05
 * @param <T> the SingleStack data type.
 */
public class SingleStack<T> extends SingleLink<T> {

    /**
     * Returns the top data of the stack and removes that data from the stack. The
     * next node in the stack becomes the new top node. Decrements the stack length.
     *
     * @return The data at the top of the stack.
     */
    public T pop() {
    	T data = null;
    	if(!this.isEmpty()) {
    		data = this.front.getData();
    		this.front = this.front.getNext();
    		this.length--;
    	}
    	return data;
    	
    }

    /**
     * Adds data to the top of the stack. Increments the stack length.
     *
     *  
     */
    public void push(final T data) {
    	SingleNode<T> node = new SingleNode<T>(data, null);
    	if(!this.isEmpty()) {
    		node.setNext(this.front);
    	}	
    	this.front = node;
    	this.length++;
    }
}