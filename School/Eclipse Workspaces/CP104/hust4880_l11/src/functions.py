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
import random

def generate_matrix_num(rows, cols, low, high, value_type):
    """
    -------------------------------------------------------
    Generates a 2D list of numbers of the given type, 'float' or 'int'.
    (To generate random float number use random.uniform and to
    generate random integer number use random.randint)
    Use: matrix = generate_matrix_num(rows, cols, low, high, value_type)
    -------------------------------------------------------
    Parameters:
        rows - number of rows in the list (int > 0)
        cols - number of columns (int > 0)
        low - low value of range (float)
        high - high value of range (float > low)
        value_type - type of values in the list, 'float' or 'int' (str)
    Returns:
        matrix - a 2D list of random numbers (2D list of float/int)
    -------------------------------------------------------
    """
    matrix = []
    for i in range(rows):
        matrix.append([])
        for j in range(cols):
            if(value_type == 'float'):
                matrix[i].append(random.uniform(low,high))
            elif(value_type == 'int'):
                matrix[i].append(random.randint(low,high))
                
    return matrix


def print_matrix_num(matrix, value_type):
    """
    -------------------------------------------------------
    Prints the contents of a 2D list in a formatted table.
    Prints float values with 2 decimal points and prints row and
    column headings.
    Use: print_matrix_num(matrix, 'float')
    Use: print_matrix_num(matrix, 'int')
    -------------------------------------------------------
    Parameters:
        matrix - a 2D list of values (2D list)
        value_type - type of values in the list, 'float' or 'int' (str)
    Returns:
        None.
    -------------------------------------------------------
    """
    counter = 0
    print('{:9.0f}'.format(0), end = '')
    
    for i in matrix:
        len_col = len(i)
        
    for i in range (1, len_col):
            print('{:7.0f}'.format(i), end = '')
        
        
    if(value_type == 'float'):
        
        for i in range(len(matrix)):
            
            print('\n {}'.format(counter), end = '')
            
            for j in range(len(matrix[i])):
                print('{:7.2f}'.format(matrix[i][j]), end = '')
            
            counter += 1
       
       
            
    if(value_type == 'int'):
            
        for i in range(len(matrix)):
            print('\n {}'.format(counter), end = '')
            
            for j in range(len(matrix[i])):
                print('{:7d}'.format(matrix[i][j]), end = '')
            
            counter += 1
            
    return None


def stats(matrix):
    """
    -------------------------------------------------------
    Returns statistics on a 2D list.
        Use: smallest, largest, total, average = stats(matrix)
    -------------------------------------------------------
    Parameters:
        matrix - a 2D list of numbers (2D list of float/int)
    Returns:
        smallest - the smallest number in matrix (float/int)
        largest - the largest number in matrix (float/int)
        total - the total of the numbers in matrix (float/int)
        average - the average of numbers in matrix (float/int)
    -------------------------------------------------------
    """
    largest = matrix[0][0]
    
    smallest = matrix[0][0]
    total = 0
    counter = 0
    for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                total += matrix[i][j]
                counter += 1
                if(matrix[i][j] >= largest):
                    largest = matrix[i][j]
                elif(matrix[i][j]<= smallest):
                    smallest = matrix[i][j]
    average = total/counter
    return smallest, largest, total, average


def scalar_multiply(matrix, num):
    """
    -------------------------------------------------------
    Update matrix by multiplying each element of matrix by num.
    Use: scalar_multiply(matrix, num)
    -------------------------------------------------------
    Parameters:
        matrix - the matrix to multiply (2D list of int/float)
        num - the number to multiply by (int/float)
    Returns:
        None
    ------------------------------------------------------
    """
    for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                matrix[i][j] *= num
              
    return None


def matrix_transpose(a):
    """
    -------------------------------------------------------
    Transpose the contents of matrix a.
    Use: b = matrix_transpose(a):
    -------------------------------------------------------
    Parameters:
        a - a 2D list (2D list of ?)
    Returns:
        b - the transposed matrix (2D list of ?)
    ------------------------------------------------------
    """
    
    b = []

    for i in a:
        len_col = len(i)

    for j in range(len_col):
        b.append([])

        for i in range(len(a)):
            b[j].append(a[i][j])
        
    
    return b
       
def matrix_equal(matrix1, matrix2):
    """
    -------------------------------------------------------
    Compares two matrices to see if they are equal - i.e. have the
    same contents in the same locations.
    Use: equal = matrix_equal(matrix1, matrix2)
    -------------------------------------------------------
    Parameters:
        matrix1 - the first matrix (2D list of ?)
        matrix2 - the second matrix (2D list of ?)
    Returns:
        equal - True if matrix1 and matrix2 are equal,
            False otherwise (boolean)
    ------------------------------------------------------
    """
    if(len(matrix1) == len(matrix2)):
        for i in range(len(matrix1)):
            if(len(matrix1[i]) == len(matrix2[i])):
                for j in range(len(matrix1[i])):
                    if(matrix1[i][j] != matrix2[i][j]):
                        equal = False
                        break
                    else:
                        equal = True
            else:
                equal = False
                break
    else:
        equal = False
        
    return equal
              
              
              
               
               