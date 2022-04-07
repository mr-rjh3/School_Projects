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

from functions import magic_date

print("Enter a date.")
day = int(input("Day: "))
month = int(input("Month: "))
year = int(input("Year (2 digits): "))

magic = magic_date(day, month, year)

if(magic):
    print("{}/{}/{} is a magic date.".format(day,month,year))
else:
    print("{}/{}/{} is not a magic date.".format(day,month,year))



