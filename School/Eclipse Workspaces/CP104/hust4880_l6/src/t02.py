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
from functions import sum_odd


num = int(input("Enter a number: "))
total = sum_odd(num)
print("The sum of all odd numbers from 1 to {} is: {}".format(num, total))