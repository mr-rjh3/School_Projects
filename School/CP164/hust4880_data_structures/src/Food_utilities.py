"""
-------------------------------------------------------
Food class utility functions.
-------------------------------------------------------
Author:  David Brown
ID:      999999999
Email:   dbrown@wlu.ca
Section: CP164 Winter 2020
__updated__ = "2020-01-10"
-------------------------------------------------------
"""
from Food import Food
from copy import deepcopy


def get_food():
    """
    -------------------------------------------------------
    Creates a food object by requesting data from a user.
    Use: f = get_food()
    -------------------------------------------------------
    Returns:
        food - a completed food object (Food).
    -------------------------------------------------------
    """
    Name = input("Name: ")
    print(Food.origins())
    Origin = int(input(": "))
    Veg = ''
    
    Veg = input('Vegetarian (Y/N): ').lower()
    if(Veg == 'y'):
        Veg = True
    else:
        Veg = False
        
    Calories = input("Calories: ")
    if(Calories == 'None'):
        Calories = None
    else:
        Calories = int(Calories)

    food = Food(Name, Origin, Veg, Calories)
    return food


def read_food(line):
    """
    -------------------------------------------------------
    Creates and returns a food object from a line of string data.
    Use: f = read_food(line)
    -------------------------------------------------------
    Parameters:
        line - a vertical bar-delimited line of food data in the format
          name|origin|is_vegetarian|calories (str)
    Returns:
        food - contains the data from line (Food)
    -------------------------------------------------------
    """

    food_v = line.split('|')
    if(food_v[2] == 'True'):
        food_v[2] = True
    elif(food_v[2] == 'False'):
        food_v[2] = False
        
    for i in food_v:
        print(i)
        
    food = Food(food_v[0],int(food_v[1]),food_v[2],int(food_v[3]))

    return food


def read_foods(file_variable):
    """
    -------------------------------------------------------
    Reads a file of food strings into a list of Food objects.
    Use: foods = read_food(file_variable)
    -------------------------------------------------------
    Parameters:
        file_variable - a file of food data (file)
    Returns:
        foods - a list of food objects (list of Food)
    -------------------------------------------------------
    """
    counter = 0
    foods = []
    for line in file_variable.readlines():
        
        counter += 1
        
        food = line.strip('\n').split('|')

        if(food[2] == 'True'):
            food[2] = True
        elif(food[2] == 'False'):
            food[2] = False
            
        foods.append(Food(food[0], int(food[1]), food[2], int(food[3])))
    
    return foods


def write_foods(file_variable, foods):
    """
    -------------------------------------------------------
    Writes a list of food objects to a file.
    file_variable contains the objects in foods as strings in the format
          name|origin|is_vegetarian|calories
    Use: write_foods(file_variable, foods)
    -------------------------------------------------------
    Parameters:
        file_variable - an open file of food data (file)
        foods - a list of Food objects (list of Food)
    Returns:
        None
    -------------------------------------------------------
    """
    for i in foods:
        string = '{}|{}|{}|{}\n'.format(i.name,i.origin,i.is_vegetarian,i.calories)
        file_variable.write(string)

    return


def get_vegetarian(foods):
    """
    -------------------------------------------------------
    Creates a list of vegetarian foods.
    Use: v = get_vegetarian(foods)
    -------------------------------------------------------
    Parameters:
        foods - a list of Food objects (list of Food)
    Returns:
        veggies - Food objects from foods that are vegetarian (list of Food)
    -------------------------------------------------------
    """

    veggies = []
    for i in foods:
        if(i.is_vegetarian):
            veggies.append(i)
            
    return veggies


def by_origin(foods, origin):
    """
    -------------------------------------------------------
    Creates a list of foods by origin.
    Use: v = by_origin(foods, origin)
    -------------------------------------------------------
    Parameters:
        foods - a list of Food objects (list of Food)
        origin - a food origin (int)
    Returns:
        origins - Food objects from foods that are of a particular origin (list of Food)
    -------------------------------------------------------
    """
    assert origin in range(len(Food.ORIGIN))
    origins = []
    
    for i in foods:
        if(i.origin == origin):
            origins.append(i)
    

    return origins


def average_calories(foods):
    """
    -------------------------------------------------------
    Determines the average calories in a list of foods.
    Use: avg = average_calories(foods)
    -------------------------------------------------------
    Parameters:
        foods - a list of Food objects (list of Food)
    Returns:
        avg - average calories in all Food objects of foods (int)
    -------------------------------------------------------
    """
    total = 0
    for i in foods:
        total += i.calories
    avg = total//len(foods)
    return avg


def calories_by_origin(foods, origin):
    """
    -------------------------------------------------------
    Determines the average calories in a list of foods.
    Use: a = calories_by_origin(foods, origin)
    -------------------------------------------------------
    Parameters:
        foods - a list of Food objects (list of Food)
        origin - the origin of the Food objects to find (int)
    Returns:
        avg - average calories for all Foods of the requested origin (int)
    -------------------------------------------------------
    """
    assert origin in range(len(Food.ORIGIN))
    total = 0
    count = 0
    for i in foods:
        if(i.origin == origin):
            total += i.calories
            count += 1
    avg = total//count

    return avg


def food_table(foods):
    """
    -------------------------------------------------------
    Prints a formatted table of foods, sorted by name.
    Use: food_table(foods)
    -------------------------------------------------------
    Parameters:
        foods - a list of Food objects (list of Food)
    Returns:
        None
    -------------------------------------------------------
    """
    

    print("""
Food                                Origin       Vegetarian Calories
----------------------------------- ------------ ---------- --------""")
    foods_copy = deepcopy(foods)
    foods_copy.sort()

    for i in foods_copy:
        print('{:<36}{:<13}{:<10}{:<11}'.format(i.name, Food.ORIGIN[i.origin],str(i.is_vegetarian),i.calories))

    return 



def food_search(foods, origin, max_cals, is_veg):
    """
    -------------------------------------------------------
    Searches for foods that fit certain conditions.
    Use: results = food_search(foods, origin, max_cals, is_veg)
    -------------------------------------------------------
    Parameters:
        foods - a list of Food objects (list of Food)
        origin - the origin of the food; if -1, accept any origin (int)
        max_cals - the maximum calories for the food; if 0, accept any calories value (int)
        is_veg - whether the food is vegetarian or not; if False accept any food (boolean)
    Returns:
        result - a list of foods that fit the conditions (list of Food)
            foods parameter must be unchanged
    -------------------------------------------------------
    """
    assert origin in range(-1, len(Food.ORIGIN))
    
    result = []
    for i in foods:
        if((i.origin == origin or origin == -1) and (i.calories <= max_cals or max_cals == -1) and (i.is_vegetarian or not is_veg)):
            result.append(i)
    return result
