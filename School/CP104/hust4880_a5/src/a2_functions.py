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
def pocket_color(num):
    """
    -------------------------------------------------------
    Determines the pocket color of a roulette wheel based on the number input
    Use: color = pocket_color(num)
    -------------------------------------------------------
    Parameters:
        x - The number on the roulette wheel's pocket (int)
    Returns:
        color - Color of the roulette wheel's pocket (str)
    -------------------------------------------------------
    """
    if(num == 0):
        color = 'green'
    elif(num >= 1 and num <= 10):
        if(num%2 == 0):
            color = 'black'
        else:
            color = 'red'
    elif(num >= 11 and num <= 18):
        if(num%2 == 0):
            color = 'red'
        else:
            color = 'black'
    elif(num >= 19 and num <= 28):
        if(num%2 == 0):
            color = 'black'
        else:
            color = 'red'
    elif(num >= 29 and num <= 36):
        if(num%2 == 0):
            color = 'red'
        else:
            color = 'black'
    else:
        color = None
    return color
