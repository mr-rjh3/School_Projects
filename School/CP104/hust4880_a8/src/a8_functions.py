"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019-11-12"
------------------------------------------------------------------------
"""


def sum_digit_string(my_str):
    """
    -------------------------------------------------------
    Sums all the digits in my_str, ignores non-digit characters
    Use: total = sum_digit_string (my_str)
    -------------------------------------------------------
    Parameters:
    my_str: string that has single-digit numbers (str)
    returns
    total: sum of all the single digit number (integer >= 0)
    -------------------------------------------------------
    """
    total = 0
    if(len(my_str) > 0):
        for i in my_str:
            if(i.isdigit()):
                total += int(i)
    else:
        total = None        
    return total

def find_frequent(my_str):
    """
    -------------------------------------------------------
    Finds the most frequent character in a string
    Use: frequent = find_frequent(my_str)
    -------------------------------------------------------
    Parameters:
        my_str - String that it will find the srequent character from (str)
    Returns:
        ch - The most frequent character in the string (str)
        None - if string is empty it will return none
     -------------------------------------------------------
    """
    ch = []
    frequent = 0
    if(len(my_str) > 0):
        for i in my_str:
            if(my_str.count(i) >= frequent and i != ' '):
                frequent = my_str.count(i)
        for i in my_str:
            if(frequent == my_str.count(i) and i != ' '):
                if(ch.count(i) < 1):
                    ch.append(i)
    else:
        ch = None
    return ch

def string_capitalizer(my_str):
    """
    -------------------------------------------------------
    Capitalizes all letters after either '.' or '?'
    Use: my_str = string_capitalizer(my_str)
    -------------------------------------------------------
    Parameters:
        my_str - The string you wish to capitalize (str)
    Returns:
        new_str - The string with the capitalization (str)
        None - returns none if my_str is empty (
     -------------------------------------------------------
    """
    new_str = ''
    capital = True
    if(my_str):
        for i in my_str:
            if(i == '.' or i == '?'):
                capital = True
                new_str += i
            elif(capital and i.isalpha()):
                capital = False
                new_str += i.upper()
            else:
                new_str += i
    else:
        new_str = None
        
    return new_str
    
def is_word_chain(my_list):
    """
    -------------------------------------------------------
    Determines whether the list passed is a word chain or not
    Use: is_chain = is_word_chain(my_list)
    -------------------------------------------------------
    Parameters:
        my_list - a list of strings (str)
    Returns:
        is_chain - returns as true is the list is a word chain and returns false if not (bool)
     -------------------------------------------------------
    """

    lst_ch = []
    is_chain = False
    for i in my_list:
        lst_ch.append(i[len(i) - 1])

    for i in range(len(my_list) - 1):
        if(((my_list[i+1])[0].lower()) == (lst_ch[i].lower())):
            is_chain = True
        else:
            is_chain = False
            break

    return is_chain
    
    
    
    