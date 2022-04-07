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
from a2_functions import pocket_color
num = int(input("Enter a pocket number: "))
color = pocket_color(num)

if(color == None):
    print("The pocket number is incorrect.")
else:
    print("The selected pocket is {}".format(color))
