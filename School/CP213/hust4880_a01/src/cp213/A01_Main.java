package cp213;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;

/**
 * @author Riley Huston: 190954880
 *
 */
public class A01_Main {
    // Constants
    public static final String SEP = "-".repeat(40);
    public static final String CIPHERTEXT = "AVIBROWNZCEFGHJKLMPQSTUXYD"; // for testing substitute method

    public static void main(String[] args)  {
    	
    	
    	System.out.println(SEP+ " Contains "  + SEP); // DONE
	    	int[] list = {0,1,2};
	    	System.out.println(A01.contains(list, 2));
	    	
    	System.out.println(SEP + " isPalindrome " + SEP);
    		String s = "RaCe   c12312ar....";
    		System.out.println(A01.isPalindrome(s));
    	System.out.println(SEP + " isValid " + SEP);
    		String name = "_Hello_";
    		System.out.println(A01.isValid(name));
    	
    	System.out.println(SEP + " matrixStats " + SEP);
    		double[][] a = new double[5][5];
	    	for(double i = 0; i < 5; i++) {
	    		for(double j = 0; j < 5; j++) {
	    			a[(int)i][(int)j] = j;
	    			System.out.print(j + " ");
	    		}
	    		System.out.println();
	    	}
    		System.out.println(Arrays.toString(A01.matrixStats(a)));

    	System.out.println(SEP + " sumPartialHarmonic " + SEP);
    		System.out.println(A01.sumPartialHarmonic(5));
    	
    	System.out.println(SEP + " validSn " + SEP);
    		String sn = "SN/1092-123";
    		System.out.println(A01.validSn(sn));
    	
    	System.out.println(SEP + " validSnFile " + SEP);
    		
    		try {
    			Scanner fileIn = new Scanner(new File("fileIn.txt"));
    			PrintStream goodSns = new PrintStream(new File("goodSns.txt"));
    			PrintStream badSns = new PrintStream(new File("badSns.txt"));
    			A01.validSnFile(fileIn, goodSns, badSns);
    			System.out.println("Complete, closing files...");
    			fileIn.close();
    			goodSns.close();
    			badSns.close();
    		} catch(Exception e) {
    			System.out.println("oops");
    		}
    		
    		
    		

   }

}