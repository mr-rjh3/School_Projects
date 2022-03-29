"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019-11-12"
------------------------------------------------------------------------
"""
from a8_functions import sum_digit_string

my_str = input("Enter digits: ")
total = sum_digit_string(my_str)
print("The sum of those digits is {}".format(total))
