"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019 09 23"
------------------------------------------------------------------------
"""

Ldog = float(input("Number of large dogs groomed: "))
Sdog = float(input("Number of small dogs groomed: "))

total = (Ldog * 75.0) + (Sdog * 50.0)

print("Total earned for the day: ${:,.2f}".format(total))