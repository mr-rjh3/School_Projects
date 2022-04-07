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
def quadrant(x, y):
    """
    -------------------------------------------------------
    Determines location on a plane of an x, y coordinate.
    Use: location = quadrant(x, y)
    -------------------------------------------------------
    Parameters:
        x - x coordinate on a Cartesian plane (float)
        y - y coordinate on a Cartesian plane (float)
    Returns:
        location - name of the quadrant the the point (x, y) is in (str)
    -------------------------------------------------------
    """
    if((x >= 0) and (y >= 0)):
        location = 'Q1'
    elif((x < 0) and (y > 0)):
        location = 'Q2'
    elif((x < 0) and (y < 0)):
        location = 'Q3'
    elif((x > 0) and (y < 0)):
        location = 'Q4'
    elif((x == 0) and (y < 0)):
        location = 'Q3'
        
    return location



