package cp213; // Replace with your login name 

import java.io.PrintStream;
import java.util.Arrays;
import java.util.Locale;
import java.util.Random;
import java.util.Scanner;

/**
 * @author Riley Huston 190954880
 *
 */
public class A01 {

    // Constants
    public static final String VOWELS = "aeiouAEIOU";
    public static final String ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    public static final int ALPHA_LENGTH = ALPHA.length();

    /**
     * Looks for a integer in an array of integers.
     *
     * @param values array of int
     * @param target value to search for
     * @return true if target in values, false otherwise
     */
    public static boolean contains(int[] values, int target) {

    	boolean found = false;
    	int i = 0;
    	while (!found && i < values.length) {
    		if (values[i] == target)
    			found = true;
    		else
    			i++;
    	}
    	return found;

    }

    /**
     * Determines if s is a palindrome. Ignores case, spaces, digits, and
     * punctuation in the string parameter s.
     *
     * @param s a string
     * @return true if s is a palindrome, false otherwise
     */
    public static boolean isPalindrome(final String s) {
    	String new_s = s.toLowerCase();
    	new_s = new_s.replaceAll(" ", "");
    	new_s = new_s.replaceAll("\\p{Punct}", "");
    	new_s = new_s.replaceAll("\\d", "");
    	boolean palindrome = true;
    	int i = 0;
    	int j = new_s.length() - 1;
    	while(palindrome && i < new_s.length() - 1) {
    		if(new_s.charAt(i) != new_s.charAt(j)) {
    			palindrome = false;
    		}
    		i++;
    		j--;
    	}
    	return palindrome; 
    }

    /**
     * Determines if name is a valid Java variable name. Variables names must start
     * with a letter or an underscore, but cannot be an underscore alone. The rest
     * of the variable name may consist of letters, numbers and underscores.
     *
     * @param name a string to test as a Java variable name
     * @return true if name is a valid Java variable name, false otherwise
     */
    public static boolean isValid(final String name) {
    	boolean valid = true;
    	int i = 1;
    	char[] ch_name;
    	ch_name = name.toCharArray();
    	if(ch_name[0] != '_' && (ch_name[0] < 'A' || ch_name[0] > 'Z') && (ch_name[0] < 'a' || ch_name[0] > 'z'))
    		valid = false;
        while(valid && i < ch_name.length) {
        	if(ch_name[i] != '_' && (ch_name[i] < 'A' || ch_name[i] > 'Z') && (ch_name[i] < 'a' || ch_name[i] > 'z') && (ch_name[i] < '0' || ch_name[i] > '9'))
        		valid = false;
        	i++;
        }
        return valid;
    }

    /**
     * Determines the smallest, largest, total, and average of the values in the 2D
     * list a. You may assume there is at least one value in a and that a is a
     * square matrix - i.e. the number of columns per row is the same. a must be
     * unchanged.
     *
     * @param a - a 2D list of numbers (2D list of double)
     *
     * @return a list of four double values containing the smallest number in a,the
     *         largest number in a, the total of all numbers in a, and the average
     *         of all numbers in a, in that order.
     */
    public static double[] matrixStats(double[][] a) {
    	double[] stats = {a[0][0], a[0][0], 0, 0};
        for(int i = 0; i < a.length; i++) {
        	for(int j = 0; j < a.length; j++) {
        		if(a[i][j] < stats[0])
        			stats[0] = a[i][j];
        		if(a[i][j] > stats[1])
        			stats[0] = a[i][j];
        		stats[2] += a[i][j];
        	}
        }
        stats[3] = stats[2]/(a.length*a.length);
        return stats;

    }

    /**
     * Sums and returns the total of a partial harmonic series. This series is the
     * sum of all terms 1/i, where i ranges from 1 to n (inclusive).
     *
     * @param n an integer
     * @return sum of partial harmonic series from 1 to n
     */
    public static double sumPartialHarmonic(int n) {
    	double sum = 0;
    	for(double i = 1; i <= n; i++) 
    		sum += 1/i;
    	
        return sum;

    }

    /**
     * Determines if a string is a good serial number. Good serial numbers are of
     * the form 'SN/nnnn-nnn', where 'n' is a digit.
     *
     * @param sn The serial number to test.
     * @return true if the serial number is valid in form, false otherwise.
     */
    public static boolean validSn(String sn) {
    	boolean valid = true;
    	int i = 3;
    	char[] sn_chars = sn.toCharArray();
    	if(!sn.startsWith("SN/") || sn_chars.length != 11 || sn_chars[7] != '-')
    		valid = false;
    	while(valid && i < sn_chars.length) {
    		if(sn_chars[i] != '-' && (sn_chars[i] < '0' || sn_chars[i] > '9'))
    			valid = false;
    		i++;
    		
    	}
        return valid;

    }

    /**
     * Evaluates serial numbers from a file. Writes valid serial numbers to
     * good_sns, and invalid serial numbers to bad_sns.
     *
     * @param fileIn  a file already open for reading
     * @param goodSns a file already open for writing
     * @param badSns  a file already open for writing
     */
    public static void validSnFile(Scanner fileIn, PrintStream goodSns, PrintStream badSns) {
    	String sn;
        while(fileIn.hasNextLine()) {
        	sn = fileIn.nextLine();
        	
        	if(A01.validSn(sn)) {
        		goodSns.println(sn);
        	}
        	else {
        		badSns.println(sn);
        	}
        }
    }
}