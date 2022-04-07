package cp213;

/**
 * Sample testing for Assignment 3 Data Structures.
 *
 * @author Riley Huston
 * @version 2021-02-05
 */
public class A03Main {

    /**
     * Note that not all the data structure methods are called in this main. The
     * main method is just an illustration of how you may test your code. Test your
     * code thoroughly.
     *
     * When you start, comment out all code in the main, and un-comment as you add
     * code to the class.
     *
     * @param args (unused)
     */
    public static void main(String[] args) {
	final String LINE = new String(new char[40]).replace("\0", "-");
	
	
	SingleList<Integer> list = new SingleList<>();
	SingleList<Integer> left = new SingleList<>();
	SingleList<Integer> right = new SingleList<>();
	System.out.println(LINE);
	System.out.println("SingleList");
	System.out.println("Empty: " + list.isEmpty());
	System.out.println("Add values: ");

	for(int i = 0; i < 6; i++) {
		list.append(i);
		left.append(i);
		right.append(i);
	}
	
	
	System.out.println("Empty: " + list.isEmpty());
	System.out.println("Peek: " + list.peek());
	System.out.print("Remove: ");
	System.out.print(list.remove(6) + " | ");
	System.out.print(list.remove(0) + " | ");
	System.out.print(list.remove(3) + " | ");
	System.out.print(list.remove(2) + " | ");
	System.out.print(list.remove(5) + " | ");
	System.out.print(list.remove(1) + " | ");
	System.out.print(list.remove(4) + " | ");
	System.out.println(list.remove(6));
	System.out.println("Empty: " + list.isEmpty());
	for(int i = 0; i < 6; i++) {
		left.append(i);
	}
	left.clean();
	list.combine(left, right);
	System.out.println("Peek: " + list.peek());
	list.reverse();
	System.out.println("Peek: " + list.peek());
	list.reverse();
	System.out.println("Peek: " + list.peek());
	System.out.println("Contains: " + list.contains(-1) + " " + list.contains(5));
	System.out.println("Count: " + list.count(4));
	list.clean();
	System.out.println("Find: " + list.find(4));
	System.out.println("Get: " + list.get(4));
	for(int i = 0; i < 6; i++) {
		left.append(i);
		right.append(i);
	}
	right.append(10);
	System.out.println("Identical: " + list.identical(left));
	System.out.println("Index: " + list.index(4));
	list.insert(4, 10);
	list.insert(7, 11);
	list.insert(0, 12);
	list.insert(10, 13);
	System.out.println("Max: " + list.max());
	System.out.println("Min: " + list.min());
	list.prepend(50);
	System.out.println("Remove Front: " + list.removeFront());
	list.prepend(20);
	System.out.println("Remove Front: " + list.removeFront());
	list.split(left, right);
	list.splitAlternate(left, right);
	list.union(left, right);
	
	System.out.println("Clear list:");

	while (!list.isEmpty()) {
	    System.out.println("list Removed: " + list.removeFront());
	}
	while (!left.isEmpty()) {
	    System.out.println("left Removed: " + left.removeFront());
	}
	while (!right.isEmpty()) {
	    System.out.println("right Removed: " + right.removeFront());
	}


	// Test SingleStack
	SingleStack<Integer> stack = new SingleStack<>();
	System.out.println(LINE);
	System.out.println("SingleStack");
	System.out.println("Empty: " + stack.isEmpty());
	System.out.println("Add values: ");

	for (int i = 0; i < 6; i++) {
	    stack.push(i);
	}
	System.out.println("Empty: " + stack.isEmpty());
	System.out.println("Peek: " + stack.peek());
	System.out.println("Clear stack:");

	while (!stack.isEmpty()) {
	    System.out.println("Popped: " + stack.pop());
	}

	// Test SingleQueue
	SingleQueue<Integer> target = new SingleQueue<>();
	SingleQueue<Integer> queue_left = new SingleQueue<>();
	SingleQueue<Integer> queue_right = new SingleQueue<>();
	System.out.println(LINE);
	System.out.println("SingleQueue");
	System.out.println("Empty: " + target.isEmpty());
	System.out.println("Add values:");

	queue_left.insert(1);
	queue_right.insert(2);
	queue_left.insert(3);
	queue_right.insert(4);
	queue_right.insert(5);
	queue_right.insert(6);
	queue_right.insert(7);

	target.combine(queue_left, queue_right);
	
	System.out.println("Empty: " + target.isEmpty());
	System.out.println("Peek: " + target.peek());

	// Test SinglePriorityQueue
	SinglePriorityQueue<Integer> pq = new SinglePriorityQueue<>();
	SinglePriorityQueue<Integer> higher = new SinglePriorityQueue<>();
	SinglePriorityQueue<Integer> lower = new SinglePriorityQueue<>();
	System.out.println(LINE);
	System.out.println("SinglePriorityQueue");
	System.out.println("Empty: " + pq.isEmpty());
	System.out.println("Add values:");

	
	pq.insert(0);
	pq.insert(1);
	pq.insert(8);
	pq.insert(3);
	pq.insert(5);
	pq.insert(2);
	
	
	System.out.println("Empty: " + pq.isEmpty());
	System.out.println("Peek: " + pq.peek());
	pq.splitByKey(10, higher, lower);
	System.out.println("Clear queue:");
	System.out.println(LINE);
}
}

