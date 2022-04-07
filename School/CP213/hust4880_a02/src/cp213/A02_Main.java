package cp213;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * @author Your name and id here
 * @version 20201-01-29
 */
public class A02_Main {
    // Constants
    public static final String SEP = "-".repeat(40);

    public static void main(String[] args) {
    	ArrayList<Food> foods = new ArrayList<Food>();
    	
    	try {
			Scanner fileIn = new Scanner(new File("foods.txt"));
			PrintStream fileout = new PrintStream(new File("foods_w.txt"));
			foods = FoodUtilities.readFoods(fileIn);
			FoodUtilities.writeFoods(foods, fileout);
			System.out.println("Complete, closing files...");
			fileIn.close();
			fileout.close();
			System.out.println(SEP);
			for(Food i : foods)
				System.out.println(i);
			System.out.println(SEP+"averageCalories");
			System.out.println(FoodUtilities.averageCalories(foods));
			
			System.out.println(SEP+"averageCaloriesByOrigin");
			System.out.println(FoodUtilities.averageCaloriesByOrigin(foods, 4));
			
			System.out.println(SEP+"foodSearch");
			System.out.println(FoodUtilities.foodSearch(foods, 0, 100, false));
			
			System.out.println(SEP+"getByOrigin");
			System.out.println(FoodUtilities.getByOrigin(foods, 4));
			System.out.println(SEP+"getVegetarian");
			System.out.println(FoodUtilities.getVegetarian(foods));
			
			Food w;
			w = new Food;
			System.out.println(w);
			
		} catch(Exception e) {
			System.out.println("oops");
		}
    	
    	
    	
    	
   }
}