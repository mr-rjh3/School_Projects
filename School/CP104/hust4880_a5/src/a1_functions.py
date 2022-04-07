"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019-10-10"
------------------------------------------------------------------------
"""
def max_three(x, y, z):
    """
    -------------------------------------------------------
    Determines the average between the two smallest of the three numbers input in the function
    Use: avg = max_three(x, y, z)
    -------------------------------------------------------
    Parameters:
        x - The first number (float)
        y - The second number (float)
        z - The third number (float)
    Returns:
        avg - The average of the two smallest numbers (float)
    -------------------------------------------------------
    """
    avg = 0
    if(x < y < z):
        avg = (x + y)/2
    elif(x < z < y):
        avg = (x + z)/2
    elif(y < z < x):
        avg = (y + z)/2
    elif(y < x < z):
        avg = (y + x)/2
    elif(z < x < y):
        avg = (z + x)/2
    elif(z < y < x):
        avg = (z + y)/2
    return avg
    
