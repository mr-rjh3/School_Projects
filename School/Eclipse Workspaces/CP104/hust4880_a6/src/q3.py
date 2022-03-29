"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019-10-23"
------------------------------------------------------------------------
"""
from a6_functions import factorial

n = int(input("Enter a positive integer: "))
factorial = factorial(n)
if(factorial > 0):
    print('{}! = {}'.format(n, factorial))
else:
    print("You did not enter a positive integer")