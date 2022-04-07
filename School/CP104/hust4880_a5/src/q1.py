"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019-10-08"
------------------------------------------------------------------------
"""
from a1_functions import max_three
x = float(input("Please enter your first number: "))
y = float(input("Please enter your second number: "))
z = float(input("Please enter your third number: "))

avg = max_three(x, y, z)
print("The average of the two smaller values is: {:.1f}".format(avg))
