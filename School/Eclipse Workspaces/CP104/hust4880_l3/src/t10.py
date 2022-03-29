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

cost = float(input("Food charge: $"))
tax = float(input("Sales tax in (%) "))
tip = float(input("Tip in (%) "))

tax_cost = cost * (tax / 100)
tip_cost = cost * (tip / 100)
total = cost + tax_cost + tip_cost
print()
print("Cost of meal:")
print("Subtotal: ${:7.2f}".format(cost))
print("     Tax: ${:7.2f}".format(tax_cost))
print("     Tip: ${:7.2f}".format(tip_cost) )
print("------------------")
print("   Total: ${:7.2f}".format(total))