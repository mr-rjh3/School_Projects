"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019 09 24"
------------------------------------------------------------------------
"""

p = float(input("Mortgage principal ($): "))
n = (float(input("Number of years: ")) * 12)
i = (float(input("Yearly interest rate (%): ")) / 12) / 100


m = p * ((i*(1 + i)**n) / (((1 + i)**n) - 1))
print("The monthly payments are: {:,.2f}".format(m))