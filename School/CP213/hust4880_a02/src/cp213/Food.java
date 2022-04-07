package cp213;

import java.io.PrintStream;

/**
 * Food class definition.
 *
 * @author your name here
 * @version 2021-01-29
 */
public class Food implements Comparable<Food> {

    // Constants
    public static final String ORIGINS[] = { "Canadian", "Chinese", "Indian", "Ethiopian", "Mexican", "Greek",
	    "Japanese", "Italian", "Moroccan", "Scottish", "Columbian", "English" };

    /**
     * Creates a string of food origins in the format:
     *
     * <pre>
Origins
 0 Canadian
 1 Chinese
...
11 English
     * </pre>
     *
     * @return A formatted numbered string of valid food origins.
     */
    public static String originsMenu() {
    	String Menu = "Origins\n";
    	int index = 0;
    	for(String origin : ORIGINS) {
    		Menu += String.format("%2d %s\n", index, origin);
    		index++;
    	}
    	return Menu;
    }

    // Attributes
    private String name = null;
    private int origin = 0;
    private boolean isVegetarian = false;
    private int calories = 0;

    /**
     * Food constructor.
     *
     * @param name         food name
     * @param origin       food origin code
     * @param isVegetarian whether food is vegetarian
     * @param calories     caloric content of food
     */
    public Food(final String name, final int origin, final boolean isVegetarian, final int calories) {
    	this.name = name;
    	this.origin = origin;
    	this.isVegetarian = isVegetarian;
    	this.calories = calories;
    }

    /*
     * (non-Javadoc) Compares this food against another food.
     *
     * @see java.lang.Comparable#compareTo(java.lang.Object)
     */
    /**
     * Foods are compared by name, then by origin if the names match.
     * Must ignore case.
     */
    @Override
    public int compareTo(final Food target) {
    	int compared;
    	compared = this.getName().compareToIgnoreCase(target.getName());
    	
    	if(compared == 0) {
	    	if(this.getOrigin() == target.getOrigin())
	    		compared = 0;
	    	else if(this.getOrigin() < target.getOrigin())
	    		compared = -1;
	    	else
	    		compared = 1;
    	}
    	
    	return compared;
    	
    }

    /**
     * Getter for calories attribute.
     *
     * @return calories
     */
    public int getCalories() {
    	return this.calories;
    }

    /**
     * Getter for name attribute.
     *
     * @return name
     */
    public String getName() {
    	return this.name;
    }

    /**
     * Getter for origin attribute.
     *
     * @return origin
     */
    public int getOrigin() {
    	return this.origin;
    }

    /**
     * Getter for string version of origin attribute.
     *
     * @return string version of origin
     */
    public String getOriginString() {
    	String[] origin_list = Food.ORIGINS;
    	return origin_list[this.origin];
    }

    /*
     * (non-Javadoc) Generates a hash value from a food name.
     *
     * @see java.lang.Object#hashCode()
     */
    @Override
    public int hashCode() {
	int hash = 0;

	for (int i = 0; i < this.name.length(); i++) {
	    hash += this.name.charAt(i);
	}
	return hash;
    }

    /**
     * Getter for isVegetarian attribute.
     *
     * @return isVegetarian
     */
    public boolean isVegetarian() {
    	return this.isVegetarian;
    }

    /**
     * Creates a formatted string of food key data.
     *
     * @return a food key as a string
     */
    public String key() {
	return String.format("%s, %d", this.name, this.origin);
    }

    /*
     * (non-Javadoc)
     *
     * @see java.lang.Object//toString() Creates a formatted string of food data.
     */
    /**
     * Returns a string version of a Food object in the form:
<pre>
Name:       name
Origin:     origin string
Vegetarian: true/false
Calories:   calories
</pre>
     */
    @Override
    public String toString() {
    	String food_str = "";
    	food_str = String.format("Name:       %s\n"
    						   + "Origin:     %s\n"
    						   + "Vegetarian: %b\n"
    						   + "Calories:   %d\n", this.getName(), ORIGINS[this.getOrigin()], this.isVegetarian(), this.getCalories());
    	return food_str;
    }

    /**
     * Writes a single line of food data to an open PrintStream. The contents of
     * food are written as a string in the format name|origin|isVegetarian|calories to ps.
     *
     * @param ps The PrintStream to write to.
     */
    public void write(final PrintStream ps) {
    	ps.println(String.format("%s|%s|%b|%d",this.getName(), this.getOrigin(), this.isVegetarian(), this.getCalories()));
    }

}