"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019-10-3"
------------------------------------------------------------------------
"""
def num_day(day_int):
    """
    -------------------------------------------------------
    Determines the weekday corresponding to the users input
    Use: num_day(day_int)
    -------------------------------------------------------
    Parameters:
    day_int - The number the user enters to determine weekday (1 <= int <= 7)
    -------------------------------------------------------
    """
    if(day_int == 1):
        print("The number {} corresponds to Monday".format(day_int))
    elif(day_int == 2):
        print("The number {} corresponds to Tuesday".format(day_int))
    elif(day_int == 3):
        print("The number {} corresponds to Wednesday".format(day_int))
    elif(day_int == 4):
        print("The number {} corresponds to Thursday".format(day_int))
    elif(day_int == 5):
        print("The number {} corresponds to Friday".format(day_int))
    elif(day_int == 6):
        print("The number {} corresponds to Saturday".format(day_int))
    elif(day_int == 7):
        print("The number {} corresponds to Sunday".format(day_int))
    else:
        print("Sorry, that is not a valid number.")
    
    