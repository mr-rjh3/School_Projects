package cp213;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.text.NumberFormat;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Main method and table generation methods for Assignment 4.
 *
 * @author your name here
 * @author David Brown
 * @version 2021-02-18
 */
public class A04Main {

    public static final NumberFormat NF = NumberFormat.getInstance();
    public static final String ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    public static final String POPULAR = "ETAOINSHRDLUCMPFYWGBVKJXZQ";
    public static final String SPLIT = "MFTCJPWADHKNRUYBEIGLOQSVXZ";
    public static final String SEPARATOR = "------------------------------";

    public static final String[] STRING_DATA = new String[] { ALPHABET, SPLIT, POPULAR };
    public static final String FILENAME = "decline.txt";

    /**
     * Print a formatted table of character counts and percentages in the format:
     *
     * <pre>
     * Character Table for Comparisons File
     *
     * Char    Count Percent
     *    A  206,946    8.17
     *    B   37,498    1.48
     *    ...
     * </pre>
     *
     * Note: your data may not match this as it is file dependent.
     *
     * @param tree The BST to generate the table from.
     */
    private static void characterTable(final BST<Character> tree) {

		for(CountedData<Character> data : tree.inOrder()) {
			System.out.println(data.getData() + " " + data.getCount());
		}

    }

    /**
     * Fill a tree by inserting all letters from a string into the tree. Letters
     * must be converted to upper-case. Non-letters are ignored. The order that
     * letters are inserted into the tree determine its shape.
     *
     * @param tree   The BST/AVL/PopularityTree to fill.
     * @param string The string to read into the tree.
     */
    private static void fillTree(final BST<Character> tree, final String string) {
    	char[] strs = string.toCharArray();
    	for(char c : strs) {
    		CountedData<Character> letter = new CountedData<Character>(Character.toUpperCase(c));
    		tree.insert(letter);
    	}

    }

    /**
     * Determine the number of comparisons to retrieve the contents of a file from a
     * tree. Attempt to retrieve every letter in the file from tree. All letters
     * must be converted to upper case.
     *
     * @param tree The BST to process.
     * @param file The file to process.
     * @return The number of comparisons necessary to find every letter in file in
     *         tree.
     * @throws FileNotFoundException Thrown if file not found.
     */
    private static int retrieve(final BST<Character> tree, final Scanner fileScan)  {
    	String line;
    	while(fileScan.hasNextLine()) {
    		line = fileScan.nextLine();
    		for(char c : line.toCharArray()) {
    			CountedData<Character> key = new CountedData<Character>(Character.toUpperCase(c));
    					tree.retrieve(key);
    		}
    		
    	}
    	return tree.getComparisons();
    	

    }

    /**
     * Program for Assignment 4.
     *
     * @param args unused
     * @throws IOException If error on files.
     */
    public static void main(final String[] args) throws IOException {
    	
//    	BST<Integer> tree = new BST<>();
//    	CountedData<Integer> data = new CountedData<>(5);
//    	tree.insert(data);
//    	data = new CountedData<>(7);
//    	tree.insert(data);
//    	data = new CountedData<>(2);
//    	tree.insert(data);
//    	data = new CountedData<>(1);
//    	tree.insert(data);
//    	data = new CountedData<>(8);
//    	tree.insert(data);
//    	System.out.println(tree.contains(data));
//    	data = new CountedData<>(0);
//    	System.out.println(tree.contains(data));
    	
    	
	final File comparisonsFile = new File(FILENAME);

	for (final String string : STRING_DATA) {
	    int minComparisons = Integer.MAX_VALUE;
	    String treeType = null;
	    String minTree = null;
	    System.out.println("Data String: " + string);
	    System.out.println();
	    final ArrayList<BST<Character>> trees = new ArrayList<>();
	    trees.add(new BST<Character>());
	    trees.add(new PopularityTree<Character>());
	    trees.add(new AVL<Character>());

	    for (final BST<Character> tree : trees) {
		treeType = tree.getClass().getSimpleName();
		System.out.println("  Tree Type: " + treeType);
		A04Main.fillTree(tree, string);
		final Scanner fileScan = new Scanner(comparisonsFile);
		final int comparisons = A04Main.retrieve(tree, fileScan);
		fileScan.close();
		System.out.println("  Height: " + tree.getHeight());
		System.out.println("  Comparisons: " + NF.format(comparisons));

		if (comparisons < minComparisons) {
		    minComparisons = comparisons;
		    minTree = treeType;
		}
		System.out.println();
	    }
	    System.out.println("Tree with minimum comparisons: " + minTree);
	    System.out.println(SEPARATOR);
	}
	final PopularityTree<Character> bst = new PopularityTree<>();
	A04Main.fillTree(bst, ALPHABET);
	final Scanner fileScan = new Scanner(comparisonsFile);
	A04Main.retrieve(bst, fileScan);
	fileScan.close();
	System.out.println("Character Table for Comparisons File");
	System.out.println();
	A04Main.characterTable(bst);
	
    }
    
}