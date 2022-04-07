"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019-11-21"
------------------------------------------------------------------------
"""

def customer_record(fv, n):
    """
    -------------------------------------------------------
    Find the n-th record in a comma-delimited sequential file.
    Records are numbered starting with 0.
    Use: result = customer_record(fv, n)
    -------------------------------------------------------
    Parameters:
        fv - file to search (file - open for reading)
        n - the number of the record to return (int > 0)
    Returns:
        result - a list of the fields of the n-th record if it exists,
            an empty list otherwise (list)
    -------------------------------------------------------
    """
    line = fv.readline()
    x = 0
    
    while(line != '' and x < n):
        line = fv.readline()
        x += 1
    if(line == ''):
        result = []
    else:
        result = line.strip().split(',')
    return result


def number_stats(fv):
    """
    -------------------------------------------------------
    Returns statistics on the numbers in a file.
    Assumes file is not empty.
    Use: smallest, largest, total, average = number_stats(fv)
    -------------------------------------------------------
    Parameters:
        fv - file to search (file - open for reading)
    Returns:
        smallest - smallest number (int)
        largest - largest number (int)
        total - sum of all the numbers in the file (int)
        average - average of all the numbers (float)
    ------------------------------------------------------
    """
    line = fv.readline()
    total = 0
    smallest = int(line)
    largest = 0
    length = 0
    
    while(line != ''):
        num = int(line)

        total += num
        length += 1
        if(num < smallest):
            smallest = num
        elif(num > largest):
            largest = num
            
        line = fv.readline()
        

    average = total / length
    return smallest, largest, total, average
    
    
def count_frequency_word(fv, word):
    """
    -------------------------------------------------------
    Counts the number of appearances of word in fv.
    Case is significant - line in file must match word in case.
    Use: count = count_frequency_word(fv, word)
    -------------------------------------------------------
    Parameters:
        fv - file to search (file - open for reading)
        word - the word to search for it in fv (str)
    Returns:
        count - the number of appearance of word in fv (int)
    ------------------------------------------------------
    """
    line = fv.readline()
    line = line.strip()

    count = 0
    while(line != ''):
        line = line.strip()
        if(line == word):
            count += 1
        line = fv.readline()
        
    return count


def find_shortest(fv):
    """
    -------------------------------------------------------
    Finds the first word with shortest length in fv.
    Assumes file is not empty.
    Use: word = find_shortest(fv)
    -------------------------------------------------------
    Parameters:
        fv - file to search (file - open for reading)
    Returns:
        word - the first word with the shortest length in fv (str)
    ------------------------------------------------------
    """
    line = fv.readline()
    line = line.strip()
    short = len(line)
    word = line
    
    while(line != ''):
        line = line.strip()
        length = len(line)
        
        if(length < short):
            word = line

        line = fv.readline()
        
    return word
        
        
def file_copy_n(fv_1, fv_2, n):
    """
    -------------------------------------------------------
    Copies n record from fv_1 (starting from the beginning of the file) to fv2
    Use: file_copy_n(fv_1, fv_2, n)
    -------------------------------------------------------
    Parameters:
        fv_1 - file to search (file - open for reading)
        fv_2 - file to search (file - open for appending)
    Returns:
        None
    ------------------------------------------------------
    """

    line = fv_1.readline()
    x = 0
    
    while(line != '' and x < n):
        fv_2.write('{}'.format(line))
        x += 1
        line = fv_1.readline()
    return
        
        
