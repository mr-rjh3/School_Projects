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

from functions import is_leap


year = int(input("Enter a year (>0): "))

if(is_leap(year)):
    print("{} is a leap year".format(year))
else:
    print("{} is not a leap year".format(year))