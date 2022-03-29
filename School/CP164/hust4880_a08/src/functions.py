"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2020-03-27"
------------------------------------------------------------------------
"""
from Letter import Letter
def do_comparisons(file_variable, bst):
    """
    -------------------------------------------------------
    Retrieves every letter in file_variable from bst. Generates
    comparisons in bst objects. Each Letter object in bst contains
    the number of comparisons found by searching for that Letter
    object in file_variable.
    Use: do_comparisons(file_variable, bst)
    -------------------------------------------------------
    Parameters:
        file_variable - the already open file containing data to evaluate (file)
        bst - the binary search tree containing 26 Letter objects
            to retrieve data from (BST)
    Returns:
        None
    -------------------------------------------------------
    """
    file_variable.seek(0)
    book = file_variable.read()
    for i in book:
        if(i.isalpha()):
            i = Letter(i.upper())
            bst.retrieve(i)
    return 

def comparison_total(bst):
    """
    -------------------------------------------------------
    Sums the comparison values of all Letter objects in bst.
    Use: total = comparison_total(bst)
    -------------------------------------------------------
    Parameters:
        bst - a binary search tree of Letter objects (BST)
    Returns:
        total - the total of all comparison fields in the bst
            Letter objects (int)
    -------------------------------------------------------
    """
    total = 0
    letters = bst.inorder()
    for i in letters:
        total += i.comparisons
    return total
    
def letter_table(bst):
    """
    -------------------------------------------------------
    Prints a table of letter counts for each Letter object in bst.
    Use: letter_table(bst)
    -------------------------------------------------------
    Parameters:
        bst - a binary search tree of Letter objects (BST)
    Returns:
        None
    -------------------------------------------------------
    """
    letters = bst.inorder()
    total = 0
    for i in letters:
        total += i.count
    
    print('Letter Count/Percent Table\n')
    print('Total Count: {:,}\n'.format(total))
    print('{}{:>7}{:>8}'.format('Letter','Count','%'))
    print('---------------------')
    
    for i in letters:
        print('{:>5}{:>8,}{:>7.2f}%'.format(i.letter,i.count,(i.count/total)*100))
    
            