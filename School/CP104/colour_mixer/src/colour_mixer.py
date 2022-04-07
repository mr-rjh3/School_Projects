"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston, Ivan Lin
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019 10 1"
------------------------------------------------------------------------
"""
'''
Color Mixer
The colors red, blue, and yellow are known as the primary colors because they cannot be made by mixing
other colors. When you mix two primary colors, you get a secondary color, as shown here:
1. When you mix red and blue, you get purple.
2. When you mix red and yellow, you get orange.
3. When you mix blue and yellow, you get green.
Design a program that prompts the user to enter the names of two primary colors to mix. If the user enters
anything other than "red," "blue," or "yellow," the program should display an error message. Otherwise, the
program should display the name of the secondary color that results.
# Question
'''

colour1, colour2 = input("Enter two primary colours: ").split()

if((colour1 == "red" and colour2 == "blue") or (colour1 == "blue" and colour2 == "red")):
    print("The mixture of those two colours is purple")
elif((colour1 == "red" and colour2 == "yellow") or (colour1 == "yellow" and colour2 == "red")):
    print("The mixture of those two colours is orange")
elif((colour1 == "blue" and colour2 == "yellow") or (colour1 == "yellow" and colour2 == "blue")):
    print("The mixture of those two colours is green")
else:
    print("ERROR: Input is not a primary colour")
    
