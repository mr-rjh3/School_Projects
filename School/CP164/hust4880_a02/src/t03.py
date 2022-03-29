"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2020-01-23"
------------------------------------------------------------------------
"""
from Food_utilities import calories_by_origin, read_foods

fv = open('foods.txt','r')
foods = read_foods(fv)
fv.close()

print(calories_by_origin(foods, 1))