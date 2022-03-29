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
from functions import roman_numeral

n = int(input("Enter a number from 1 to 10: "))

numeral = roman_numeral(n)

print("The Roman numeral equivalent of {} is {}".format(n, numeral))