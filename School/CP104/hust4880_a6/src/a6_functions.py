"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019-10-22"
------------------------------------------------------------------------
"""
from math import sqrt

HOUSE_GROWTH = 0.05
MILLION = 1000000

def calc_profit(principal, year):
    """
    -------------------------------------------------------
    Calculates the amount of growth per year of investment in a house
    Use: calc_profit(principal, year)
    -------------------------------------------------------
    Parameters:
        principal - Amount of money to invest in the house (int or float > 0)
        year - the number of year of investment (int > 0)
    Returns:
        None
     -------------------------------------------------------
    """
    total = principal
    print("Year Value (Million Dollars)")
    print("---- -----------------------")
    for i in range (year):
        total += total*HOUSE_GROWTH
        print("{:4d} {:23.6f}".format(i+1,total/MILLION))
    return None

def perfect_square(num):
    """
    -------------------------------------------------------
    Prints all perfect squares between 1 and the input number
    Use: perfect_square(num)
    -------------------------------------------------------
    Parameters:
        num - the function print all perfect squares below this number (int >= 0)
    Returns:
        None
     -------------------------------------------------------
    """
    perfect_squares = []
    if(num >= 0):
        for i in range (1, num):
            if(sqrt(i) == int(sqrt(i))):
                perfect_squares.append(i)
        
        print("Perfect squares below {} are: ".format(num), end = '')
        
        for i in range (len(perfect_squares)):
            if(i == len(perfect_squares) - 1):
                print(perfect_squares[i])
            else:
                print(perfect_squares[i], end = ', ')
    
    else:
        print("You did not enter a positive integer")
    return None
    
def factorial(n):
    """
    -------------------------------------------------------
    Determines the factorial of the input number
    Use: factorial = factorial(n)
    -------------------------------------------------------
    Parameters:
        n - the number of the factorial (int > 0)
    Returns:
        factorial - the factorial of n, returns -1 if invalid value is used (int > 0 or int = -1)
     -------------------------------------------------------
    """ 
    factorial = 1
    if(n > 0):
        for i in range (1, n + 1, 1):
            factorial *= i
    else:
        factorial = -1
    return factorial

def is_prime(num):
    """
    -------------------------------------------------------
    Determines if the input number is a prime number 
    (Only divisible by itself and 1)
    Use: prime = is_prime(num)
    -------------------------------------------------------
    Parameters:
        num - the number to check if prime (int > 0)
    Returns:
        prime - true if num is prime, false otherwise (bool)
     -------------------------------------------------------
    """
    is_divisible = []
    for i in range (1,num+1):
        if(num%i == 0):
            is_divisible.append(i)
    if(len(is_divisible) == 2):
        prime = True
    elif(num == 1):
        prime = True
    else:
        prime = False
    return prime
 
 
 
