"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019-09-26"
------------------------------------------------------------------------
"""

pay = float(input("Hourly rate of pay: $"))
hours = float(input("Hours worked in the week: "))

total = pay * hours

print("Total pay for the week: ${:,.2f}".format(total))