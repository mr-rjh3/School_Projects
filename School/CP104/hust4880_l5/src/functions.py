"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019-10-10"
------------------------------------------------------------------------
"""
#Task 1
def magic_date(day, month, year):
    """
    -------------------------------------------------------
    Determines if a date is magic. A date is magic if the day
    times the month equals the year.
    Use: magic = magic_date(day, month, year)
    -------------------------------------------------------
    Parameters:
        day - numeric day (int > 0)
        month - numeric month (int > 0)
        year - numeric two-digit year (int > 0)
    Returns:
        magic - True if date is magic, False otherwise (boolean)
    -------------------------------------------------------
    """
    if(day * month == year):
        magic = True
    else:
        magic = False
    return magic
    
    
#Task 5
def is_leap(year):
    """
    -------------------------------------------------------
    Determines if a year is a leap year. Every year that is
    exactly divisible by four is a leap year, except for years
    that are exactly divisible by 100, but these centurial years
    are leap years if they are exactly divisible by 400. For
    example, the years 1700, 1800, and 1900 are not leap years,
    but the years 1600 and 2000 are.
    Use: result = is_leap(year)
    -------------------------------------------------------
    Parameters:
        year - a year (int > 0)
    Returns:
        result - True if year is a leap year,
            False otherwise (boolean)
    ------------------------------------------------------
    """
    
    if((year%100 == 0) and (year%400 == 0)):
        result = True
    elif((year%100 == 0) and (year%400 != 0)):
        result = False
    elif((year%100 != 0) and (year%4 == 0)):
        result = True
    else:
        result = False
    return result


#Task 8
def roman_numeral(n):
    """
    -------------------------------------------------------
    Convert 1-10 to Roman numerals.
    Use: numeral = roman_numeral(n)
    -------------------------------------------------------
    Parameters:
        n - number to convert to Roman numerals (int)
    Returns:
        numeral - Roman numeral version of n, None if n is not
          between 1 and 10 inclusive. (str)
    -------------------------------------------------------
    """
   
    if(n <= 3):
        numeral = n*('I')
    elif(n == 4):
        numeral = 'IV'
    elif(n <= 8):
        numeral = 'V' + (n - 5)*('I')
    elif(n == 9):
        numeral = 'IX'
    elif(n == 10):
        numeral = 'X'
    else:
        numeral = None
    return numeral    
    
#Task 11
def quadrant(x, y):
    """
    -------------------------------------------------------
    Determines location on a plane of an x, y coordinate.
    Use: location = quadrant(x, y)
    -------------------------------------------------------
    Parameters:
        x - x coordinate on a Cartesian plane (float)
        y - y coordinate on a Cartesian plane (float)
    Returns:
        location - name of: quadrant, axis, or origin of coordinate x, y (str)
    -------------------------------------------------------
    """
    if((x > 0) and (y > 0)):
        location = 'Quadrant 1'
    elif((x < 0) and (y > 0)):
        location = 'Quadrant 2'
    elif((x < 0) and (y < 0)):
        location = 'Quadrant 3'
    elif((x > 0) and (y < 0)):
        location = 'Quadrant 4'
    elif((x == 0) and (y != 0)):
        location = 'Y-Axis'
    elif((x != 0) and (y == 0)):
        location = 'X-Axis'
    else:
        location = 'Origin'
    return location

#Task 15
def fast_food():
    """
    -------------------------------------------------------
    Food order function.
    Prices:
        Burger: $6.00
        Wings: $8.00
        Fries combo: add $1.50
        Salad combo: add $2.00
    Use: price = fast_food()
    -------------------------------------------------------
    Returns:
        price - the price of one meal (float)
    -------------------------------------------------------
    """
    BURGER = 6.00
    WINGS = 8.00
    FRIES = 1.50
    SALAD = 2.00
    
    price = 0
    order = input("Order B - burger or W - wings: ")
    
    if(order == 'B'):
        price  += BURGER
    elif(order == 'W'):
        price += WINGS
        
    combo = input("Make it a combo? (Y/N): ")
    if(combo == 'Y'):
        side = input("Add F - fries or S - salad: ")
        if(side == 'F'):
            price  += FRIES
        elif(side == 'S'):
            price += SALAD
    return price
    
    
    