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
from functions import matrix_transpose, generate_matrix_num, print_matrix_num
a = generate_matrix_num(5, 3, -10, 10, 'int')
a = [[1,2,3,4],[1,2,3,4]]
b = matrix_transpose(a)
print()
print()
print_matrix_num(b, 'int')