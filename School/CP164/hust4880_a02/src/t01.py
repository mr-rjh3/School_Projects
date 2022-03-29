"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2020-01-22"
------------------------------------------------------------------------
"""
from Food_utilities import by_origin, read_foods

fv = open('foods.txt','r')
foods = read_foods(fv)
fv.close()
for i in by_origin(foods, 1):
    print(i)
