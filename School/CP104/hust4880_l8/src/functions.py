"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019-11-07"
------------------------------------------------------------------------
"""
from random import randint

def get_month_name(m):
    """
    -------------------------------------------------------
    Returns the name of a month given its number.
    Use: name = get_month_name(m)
    -------------------------------------------------------
    Parameters:
        m - month number (int 1 <= m <= 12)
    Returns:
        name - matching month, 1 = "January", 12 = "December" (str)
    -------------------------------------------------------
    """

    months = ['January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December']
    name = months[m-1]
    return name

def generate_integer_list(n, low, high):
    """
    -------------------------------------------------------
    Generates a list of random integers.
    Requires import: from random import randint
    Use: values = generate_integer_list(n, low, high)
    -------------------------------------------------------
    Parameters:
        n - number of values to generate (int, > 0)
        low - low value range (int)
        high - high value range (int, > low)
    Returns:
        values - a list of random integers (list of int)
    -------------------------------------------------------
    """
    values = []
    for i in range (n):
        values.append(randint(low, high))
    return values


def list_stats(values):
    """
    -------------------------------------------------------
    Returns statistics about values in a list.
    values has at least one element.
    Use: smallest, largest, total, average = list_stats(values)
    -------------------------------------------------------
    Parameters:
        values - a list of values (list of float)
    Returns:
        smallest - the smallest number in values (float)
        largest - the largest number in values (float)
        total - total of numbers in list (float)
        average - the average numbers in values (float)
    -------------------------------------------------------
    """
    total = 0
    smallest = values[0]
    largest = values[0]
    for i in values:
        if(i <= smallest):
            smallest = i
    
    for i in values:
        if(i >= largest):
            largest = i
        
            
    for i in values:
        total += i
    
    average = total/len(values)
    
    return smallest, largest, total, average


def linear_search(a, v):
    """
    -------------------------------------------------------
    Searches through a for the value v and returns its index.
    Use: index = linear_search(a, v)
    -------------------------------------------------------
    Parameters:
        a - a list of values (list of ?).
        v - can be compared to values in a (?).
    Returns:
        index - the index of the location of v in a, -1 if not found (int).
    -------------------------------------------------------
    """
    index = -1
    n = 0
    while(n < len(a)):
        if(a[n] == v):
            index = n
            break
        n += 1
    return index

def union(source1, source2):
    """
    -------------------------------------------------------
    Returns a list that is the union of the contents of source1 and source2.
    Every element that appears at least once in either source1 and source2
    must appear once and only once in target.
    Use: target = union(source1, source2)
    -------------------------------------------------------
    Parameters:
        source1 - a list (list of ?)
        source2 - a list (list of ?)
    Returns:
        target - the union of source1 and source2 (list of ?)
    -------------------------------------------------------
    """
    target = []
    for i in source1:
        while(source1.count(i) > 1):
            source1.remove(i)
            
        target.append(i)
    print(source1)
    for i in source2:
        while(source2.count(i) > 1):
            source2.remove(i)
        target.append(i)
    print(source2)
    print(target)
    for i in target:
        while(target.count(i) > 1):
            target.remove(i)
            print(i)
            
    return target
    
