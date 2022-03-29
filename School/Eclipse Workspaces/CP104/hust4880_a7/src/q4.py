"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019-11-06"
------------------------------------------------------------------------
"""

from a7_functions import keep_positive_numbers, find_value

lst = keep_positive_numbers()

target = int(input("Enter a target = "))

location = find_value(target)

print("Target exists at location(s): {}".format(location))