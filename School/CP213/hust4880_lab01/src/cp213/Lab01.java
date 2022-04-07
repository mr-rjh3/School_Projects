package cp213;

import java.util.Scanner;

public class Lab01 {

    /**
     * @param a
     * @param b
     * @return
     */
    public static int gcd(int a, int b) {
    	int gcd = 1;
        for(int i = 1; i <= a && i <= b; i++) {
        	if(a % i == 0 && b % i == 0)
        		gcd = i;
        }
        
        return gcd;
    }

    /**
     * @param args
     */
    public static void main(String[] args) {
        try (Scanner keyboard = new Scanner(System.in)){
            int a = 1;
            int b = 1;
            int c = 1;
            while(a != 0 && b != 0) {	            
            	
	            // Read an integer from the keyboard.
	            System.out.println("Enter a (0 to quit): ");
	            a = keyboard.nextInt();
	            
	            if(a != 0) {
		            System.out.println("Enter b (0 to quit): ");
		            b = keyboard.nextInt();
		            
		            if(b != 0) {
		            	// gcd function call
		            	c = Lab01.gcd( a, b );
		            	System.out.println("The gcd of " + a + " and " + b + " is " + c);
		            }
	            }
            }
        }
    }

}
