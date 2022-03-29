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

MILK = 4 / 6
BUTTER = 8 / 6
FLOUR = 0.5 / 6
SALT = 2 / 6

number_of_mac = int(input("Enter servings of Mac & Cheese: "))

milk_serving = MILK * number_of_mac
butter_serving = BUTTER * number_of_mac
flour_serving = FLOUR * number_of_mac
salt_serving = SALT * number_of_mac

print("{} servings of Mac & Cheese requires:".format(number_of_mac))

print("milk (cups): {:.2f}".format(milk_serving))
print("butter (tablespoons): {:.2f}".format(butter_serving))
print("flour (cups): {:.2f}".format(flour_serving))
print("salt (teaspoons): {:.2f}".format(salt_serving))

