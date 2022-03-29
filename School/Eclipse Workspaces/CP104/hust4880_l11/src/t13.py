"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019-11-28"
------------------------------------------------------------------------
"""
from functions import scalar_multiply, generate_matrix_num, print_matrix_num


matrix = generate_matrix_num(3,5,-10,10,'int')
print_matrix_num(matrix, 'int')
print()
scalar_multiply(matrix, 5)
print_matrix_num(matrix, 'int')