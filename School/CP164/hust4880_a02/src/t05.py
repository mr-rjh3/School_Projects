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
from Food_utilities import food_search, read_foods

fv = open('foods.txt','r')
foods = read_foods(fv)
fv.close()
for i in food_search(foods, 1, 200, True):
    print(i)