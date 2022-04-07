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
from a4_functions import quadrant
x = int(input("Enter x coordinate: "))
y = int(input("Enter y coordinate: "))

location = quadrant(x, y)

print("The point ({}, {}) lies in {}".format(x, y, location))