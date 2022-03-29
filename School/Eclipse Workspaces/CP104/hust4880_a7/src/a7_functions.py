"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019-11-05"
------------------------------------------------------------------------
"""

def win_game():
    """
    -------------------------------------------------------
    Takes user input of either "red" or "green" and returns the amount of each types in a list
    press enter without input to end
    Use: game_list = win_game()
    -------------------------------------------------------
    Parameters:
        None
    Returns:
        game_list - List of the number of times red and green was input (Integer List)
     -------------------------------------------------------
    """
        
    redn = 0
    greenn = 0
    color = ' '
    while(color != ''):
        color = input('Enter "red" or "green" or press ENTER to stop: ')
        if(color.lower() == 'red'):
            redn += 1
        elif(color.lower() == 'green'):
            greenn += 1
    game_list = [redn, greenn]
    return game_list


def display_pattern(num_lines):
    """
    -------------------------------------------------------
    Displays a triangle using the character "#" that is filled with spaces
    Use: display_pattern(num_lines)
    -------------------------------------------------------
    Parameters:
        num_lines - the height of the triangle
    Returns:
        None
     -------------------------------------------------------
    """
    for i in range (1, num_lines + 1):
        str = i * '#'
        if(len(str) > 2 and len(str) < num_lines):
            str = '#' + ((i-2) * ' ') + '#'
        print(str)
        
    return None
        
        
        
def keep_positive_numbers():
    """
    -------------------------------------------------------
    Takes user input and adds only positive integers from the input to a list
    entering the number 0 stops input
    Use: lst = keep_positive_numbers()
    -------------------------------------------------------
    Parameters:
        None
    Returns:
        lst - the list of positive integers (integer list)
     -------------------------------------------------------
    """
        
    lst = []
    x = -1
    while(True):
        try:
            x = int(input("Enter a positive integer: "))
            if(x > 0):
                lst.append(x)
            elif(x == 0):
                break
        except:
            print('', end = '')
    return lst
                
                
def find_value(lst, target):
    """
    -------------------------------------------------------
    Finds the location(s) of a value input by the user in a given list if it exists
    Use: location = find_value(lst, target)
    -------------------------------------------------------
    Parameters:
        lst - the list that the function searches through (List)
        target - the value that the function searches the list for
    Returns:
        location - the location(s) of the target value in the list (list)
     -------------------------------------------------------
    """
        
    location = []
    n = 0
    print("List entered: {}".format(lst))
    for i in lst:
        if(i == target):
            location.append(n)
        n += 1
    return location

        
        
        
    
    