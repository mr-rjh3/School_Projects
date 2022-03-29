"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019-11-29"
------------------------------------------------------------------------
"""
def add_matricies(a,b):
    """
    -------------------------------------------------------
    Description
    Use: 
    -------------------------------------------------------
    Parameters:
        
    Returns:
        
     -------------------------------------------------------
    """
    matrix_sum = []
    values = []
    counter = 0
    for i in range(len(a)):
        for j in a[i]:
            values.append(j)
    for i in range(len(b)):
        matrix_sum.append([])
        for j in b[i]:
            matrix_sum[i].append(values[counter] + j)
            counter += 1
    return matrix_sum
        