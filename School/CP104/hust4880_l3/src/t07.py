"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019 M09 25"
------------------------------------------------------------------------
"""

flyers = int(input("Number of flyers: "))
volunteers = int(input("Number of volunteers: "))

print("Flyers per volunteer: ", flyers // volunteers)
print("Flyers per volunteer: ", flyers % volunteers)