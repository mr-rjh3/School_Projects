"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019 09 26"
------------------------------------------------------------------------
"""

balloons = int(input('Enter number of balloons: '))
childeren = int (input('Enter number of children: '))

balloons_per_child = balloons // childeren
remaining_balloons = balloons % childeren

print('Each child will receive {} balloons'. format(balloons_per_child))
print('Balloons that won’t be distributed:', remaining_balloons)

