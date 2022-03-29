"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019-10-3"
------------------------------------------------------------------------
"""
import random

def math_quiz():
    """
    -------------------------------------------------------
    Gives user an addition question with two random integers between 0 and 999 and returns the solution
    Use: solution = math_quiz()
    -------------------------------------------------------
    Returns
    solution - The sum of the random integers (int >= 0)
    -------------------------------------------------------
    """
    n1 = random.randint(0,999)
    n2 = random.randint(0,999)
    solution = n1 + n2
    print("  ",n1)
    print("+ ",n2)
    return solution
