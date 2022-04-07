package test;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;

public class Test {

	public static void main(String[] args) {
		Double a = new Double(1);
		double b = new Double(1);
		double c = new Double(1);
		
		ArrayList<Integer> mylist = new ArrayList<Integer>();
		mylist.add(a);
		mylist.add(b);
		mylist.add(c);
		mylist.get(0).doubleValue();
	}
}
