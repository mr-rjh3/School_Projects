package cp213;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Utilities for working with Food objects.
 *
 * @author your name here
 * @version 2021-01-29
 */
public class FoodUtilities {

    /**
	 * Determines the average calories in a list of foods. No rounding necessary.
	 * Foods list parameter may be empty.
	 *
	 * @param foods a list of Food
	 * @return average calories in all Food objects
	 */
	public static int averageCalories(final ArrayList<Food> foods) {
		int total = 0;
		int avg = 0;
		for(Food f : foods)
			total += f.getCalories();
		
		avg = total/foods.size();
		return avg;
	}

    /**
     * Determines the average calories in a list of foods for a particular origin.
     * No rounding necessary. Foods list parameter may be empty.
     *
     * @param foods  a list of Food
     * @param origin the origin of the Food
     * @return average calories for all Foods of the specified origin
     */
    public static int averageCaloriesByOrigin(final ArrayList<Food> foods, final int origin) {
    	int total = 0;
    	int food_number = 0;
    	int avg = 0;
    	for(Food f : foods) {
    		if(f.getOrigin() == origin) {
    			total += f.getCalories();
    			food_number++;
    		}
    	}
    	avg = total/food_number;
    	return avg;
    }

    /**
     * Creates a list of foods by origin.
     *
     * @param foods  a list of Food
     * @param origin a food origin
     * @return a list of Food from origin
     */
    public static ArrayList<Food> getByOrigin(final ArrayList<Food> foods, final int origin) {
    	ArrayList<Food> ByOrigin = new ArrayList<Food>();
    	for(Food f : foods) {
    		if(f.getOrigin() == origin)
    			ByOrigin.add(f);
    	}
    	return ByOrigin;
    }

    /**
     * Creates a Food object by requesting data from a user. Uses the format:
     * 
     * <pre>
    Name: name
    Origins
     0 Canadian
     1 Chinese
    ...
    11 English
    Origin: origin number
    Vegetarian (Y/N): Y/N
    Calories: calories
     * </pre>
     *
     * @param keyboard a keyboard Scanner
     * @return a Food object
     */
    public static Food getFood(final Scanner keyboard) {
    	boolean isVeg = false;
    	String name;
    	int origin;
    	int calories;
    	System.out.print("Name: ");
    	name = keyboard.nextLine();
    	
    	System.out.print(Food.originsMenu());
    	System.out.print("Origin: ");
    	origin = keyboard.nextInt();
    	
    	System.out.print("Vegetarian (Y/N): ");
    	String yn = keyboard.next();
    	if(yn.toLowerCase().equals("y"))
    		isVeg = true;
    	else if(yn.toLowerCase().equals("n"))
    		isVeg = false;
    	
    	System.out.print("Calories: ");
    	calories = keyboard.nextInt();
    	
    	
    	Food new_food = new Food(name, origin, isVeg, calories);
    	return new_food;
    }

    /**
     * Creates a list of vegetarian foods.
     *
     * @param foods a list of Food
     * @return a list of vegetarian Food
     */
    public static ArrayList<Food> getVegetarian(final ArrayList<Food> foods) {
    	ArrayList<Food> veglist = new ArrayList<Food>();
    	for(Food f : foods) {
    		if(f.isVegetarian() == true)
    			veglist.add(f);
    	}
    	return veglist;
    }

    /**
     * Creates and returns a Food object from a line of string data.
     *
     * @param line a vertical bar-delimited line of food data in the format
     *             name|origin|isVegetarian|calories
     * @return the data from line as a Food object
     */
    public static Food readFood(final String line) {
    	String[] food_data = line.split("\\|");
    	
    	String name = food_data[0];
    	int origin = Integer.parseInt(food_data[1]);
    	boolean isVeg;
    	if(food_data[2].toLowerCase().equals("true"))
    		isVeg = true;
    	else
    		isVeg = false;
    	int calories = Integer.parseInt(food_data[3]);
    	
    	Food new_food = new Food(name, origin, isVeg, calories);
    	return new_food;
    }

    /**
     * Reads a file of food strings into a list of Food objects.
     *
     * @param fileIn a Scanner of a Food data file in the format
     *               name|origin|isVegetarian|calories
     * @return a list of Food
     */
    public static ArrayList<Food> readFoods(final Scanner fileIn) {
    	ArrayList<Food> foods = new ArrayList<Food>();
    	String line = "";
    	while(fileIn.hasNextLine()) {
        	line = fileIn.nextLine();
        	foods.add(FoodUtilities.readFood(line));
    	}
    	return foods;
    }

    /**
     * Searches for foods that fit certain conditions.
     *
     * @param foods        a list of Food
     * @param origin       the origin of the food; if -1, accept any origin
     * @param maxCalories  the maximum calories for the food; if 0, accept any
     * @param isVegetarian whether the food is vegetarian or not; if false accept
     *                     any
     * @return a list of foods that fit the conditions specified
     */
    public static ArrayList<Food> foodSearch(final ArrayList<Food> foods, final int origin, final int maxCalories,
	    final boolean isVegetarian) {
    	
    	ArrayList<Food> Searched = new ArrayList<Food>();
    	if(isVegetarian) {
	    	for(Food f : foods) {
	    		if((f.getOrigin() == origin || origin == -1) && f.getCalories() <= maxCalories && f.isVegetarian())
	    			Searched.add(f);
	    	}
    	}
    	else
	    	for(Food f : foods) {
	    		if((f.getOrigin() == origin || origin == -1) && f.getCalories() <= maxCalories)
	    			Searched.add(f);
	    	}
    	return Searched;
    	
    }

    /**
     * Writes the contents of a list of Food to a PrintStream.
     *
     * @param foods a list of Food
     * @param ps    the PrintStream to write to
     */
    public static void writeFoods(final ArrayList<Food> foods, PrintStream ps) {
    	for(Food f : foods) 
    		f.write(ps);
    }
}