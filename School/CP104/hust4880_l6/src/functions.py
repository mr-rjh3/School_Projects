"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019-10-24"
------------------------------------------------------------------------
"""

def sum_odd(num):
    """
    -------------------------------------------------------
    Sums and returns the total of all odd numbers from 1 to num (inclusive).
    Use: total = sum_odd(num)
    -------------------------------------------------------
    Parameters:
        num - an integer (int > 0)
    Returns:
        total - sum of all odd numbers from 1 to num (int)
    ------------------------------------------------------
    """
    total = 0
    for i in range (1, num + 1, 2):
        total += i
    return total



def draw_triangle(height, char):
    """
    -------------------------------------------------------
    Prints a triangle of height characters using
    the char character.
    Use: draw_triangle(height, char)
    -------------------------------------------------------
    Parameters:
        height - number of characters high (int > 0)
        char - the character to draw with (str, len() == 1)
    Returns:
        None
    ------------------------------------------------------
    """
    str = char
    sp = " "
    space = ""
    for i in range (height):
        space = sp*((height - i) - 1)
        print(space, str)
        str += 2*char
        
    return None
        
        
        
def bottles_of_beer(n):
    """
    -------------------------------------------------------
    Prints n verses of the song "99 Bottles of Beer on the Wall".
    Use: bottles_of_beer(n)
    -------------------------------------------------------
    Parameters:
        n - number of verses of the song to print (int > 0)
    Returns:
        None
    ------------------------------------------------------
    """
    if(n > 2):
        for i in range (n, 1, -1):  
            print("{} bottles of beer on the wall, {} bottles of beer.".format(i, i))
            print("Take one down, pass it around, {} bottles of beer on the wall.".format(i - 1))
            
    elif(n == 2):
        print("{} bottles of beer on the wall, {} bottles of beer.".format(n, n))
        print("Take one down, pass it around, {} bottle of beer on the wall.".format(n - 1))

    print("{} bottle of beer on the wall, {} bottle of beer.".format(n, n))
    print("Take one down, pass it around, no more bottles of beer on the wall.")
    
    return None
        

def lumber(b_min, b_max, b_inc, h_min, h_max, h_inc):
    """
    -------------------------------------------------------
    Create a table of the engineering properties of lumber.
    Given the base and height of a piece of lumber in inches,
    different properties of a piece of lumber are calculated as:
        cross-sectional area = base × height
        moment of inertia = base × height^3 / 12
        section modulus = base × height^2 / 6
    Use: lumber(b_min, b_max, b_inc, h_min, h_max, h_inc)
    -------------------------------------------------------
    Parameters:
        b_min - minimum value of base (int > 0)
        b_max - maximum value of base (int > b_min)
        b_inc - increment in base value (int > 0)
        h_min - minimum value of height (int > 0)
        h_max - maximum value of height (int > h_min)
        h_inc - increment in height value (int > 0)
    Returns:
        None
    ------------------------------------------------------
    """
    print("{:<0s}  {:<6s}  {:<14s}  {:<31s}  {:<41s}".format("Base", "Height", "Cross-Sectional Area", "Moment of Inertia", "Section Modulus"))