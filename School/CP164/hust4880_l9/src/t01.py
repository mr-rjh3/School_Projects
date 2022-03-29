"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2020-03-26"
------------------------------------------------------------------------
"""
from functions import hash_table
from Food_utilities import read_foods

fv = open('foods.txt', 'r')
foods = read_foods(fv)
fv.close()


hash_table(7, foods)
