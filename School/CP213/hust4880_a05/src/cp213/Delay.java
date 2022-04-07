package cp213;

import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

/**
 * Fakes
 *
 * @author your name here
 * @author David Brown
 * @version 2021-03-19
 */
public class Delay implements Callable<Boolean> {

    /**
     * Tests the call to a Delay object. Creates a thread pool with a single thread,
     * then assigns the result of a Delay call to a Boolean Future object. Pauses
     * until the Future object returns a result from its Delay call.
     *
     * @param args Ignored.
     */
    public static void main(final String[] args) {
	try {
	    // Create a thread pool consisting of a single thread.
	    final ExecutorService threadPool = Executors.newSingleThreadExecutor();
	    System.out.println("Submitting");
	    // Create a new Delay object and run its call method in its own thread.
	    final Delay delay = new Delay();
	    final Future<Boolean> future = threadPool.submit(delay);
	    // Get the result of the Delay call. There will be a noticeable delay.
	    final Boolean result = future.get().booleanValue();
	    System.out.println("Result: " + result);
	    // Stop the thread and exit the program.
	    future.cancel(true);
	    System.exit(0);
	} catch (final InterruptedException e) {
	    e.printStackTrace();
	} catch (final ExecutionException e) {
	    e.printStackTrace();
	}
    }

    /**
     * Update this code to: - generate a random sleep time to between 20 seconds and
     * 40 seconds - generate a result of true 90% of the time, and false the
     * remaining 10%.
     *
     * @return a random True or False
     * @throws Exception Required, but can be ignored.
     */
    @Override
    public Boolean call() throws Exception {
	final Boolean result = true;
	Thread.sleep(2000);
	return result;
    }

}