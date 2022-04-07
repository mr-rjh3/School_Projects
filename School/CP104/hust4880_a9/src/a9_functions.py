"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2019-11-20"
------------------------------------------------------------------------
"""
def sum_numbers(my_file):
    """
    -------------------------------------------------------
    Determines the sum of all numbers in a file
    Use: numbers, total = sum_numbers(my_file)
    -------------------------------------------------------
    Parameters:
        my_file - a file that contains the numbers you wish to find the sum of
    Returns:
        numbers - the numbers in the file
        total - total sum of numbers in the file
     -------------------------------------------------------
    """
    numbers = []
    total = 0
    lines = my_file.readline()
    my_str = lines.strip().split(' ')
    for i in my_str:
        if(i.isnumeric() and int(i) > 0):
            numbers.append(int(i)) 
            total += int(i)
            
    return numbers, total
    
def find_median(my_file):
    """
    -------------------------------------------------------
    determines the median of a group of numbers
    Use: numbers, median = find_median(my_file)
    -------------------------------------------------------
    Parameters:
        my_file - file that contains numbers in groups of three per line (file)
    Returns:
        numbers - list of the numbers in the file (list)
        median - the median of the numbers found in the file (Float)
     -------------------------------------------------------
    """
    line = my_file.readline()
    numbers = []
    median = None
    
    while(line != ''):
        numbers += line.strip().split(' ')

        line = my_file.readline()
        
    for i in range(len(numbers)):
        numbers[i] = int(numbers[i])
    
    numbers.sort()

    median_index = (len(numbers))/2
    
    if(len(numbers) != 0):
        if(len(numbers)%2 == 0):
            median = ((numbers[int(median_index)])+(numbers[int(median_index-1)]))/2
        else:
            median = numbers[int(median_index)]

    return numbers, median

def analysis_file(file_in):
    """
    -------------------------------------------------------
    Determines the amount of Uppercase letters, lowercase letters, digits, and spaces
    are in a file
    Use: upper, lower, digit, space = analysis_file(file_in)
    -------------------------------------------------------
    Parameters:
        file_in - File that you wish to analyze
    Returns:
        upper - Number of uppercase letters in file (int)
        lower - Number of lowercase letters in file (int)
        digit - Number of digits in file (int)
        space - Number of white spaces in file (int)
     -------------------------------------------------------
    """
        
    line = file_in.readline()
    my_str = ''
    
    upper = 0
    lower = 0
    digit = 0
    space = 0
    
    
    while(line != ''):
        my_str += line
        line = file_in.readline()
    
    for i in my_str:
        if(i.isupper()):
            upper+=1
        elif(i.islower()):
            lower += 1       
        elif(i.isdigit()):
            digit += 1
        elif(i.isspace()):
            space += 1
            
    return upper, lower, digit, space

def valid_sn(txt_srl):
    """
    -------------------------------------------------------
    determines if the serial number given is valid or not
    Use: valid = valid_sn(txt_srl)
    -------------------------------------------------------
    Parameters:
        txt_srl - the serial number that is to be validated (str)
    Returns:
        valid - True if the serial number is valid, false otherwise (bool)
     -------------------------------------------------------
    """
    if(len(txt_srl) == 11 and txt_srl[0] == 'S' and txt_srl[1] == 'N' and txt_srl[2] == '/' and txt_srl[3:6].isnumeric() and txt_srl[7] == '-' and txt_srl[8:].isnumeric()):
        valid = True
        
    else:
        valid = False
        
    return valid
    
    
def valid_sn_file(srl_file, valid_file, invalid_file):    
    """
    -------------------------------------------------------
    Determines the validity of serial numbers and writes valid numbers into a file and
    invalid numbers into another seperate file
    Use: valid_sn_file(srl_file, valid_file, invalid_file)
    -------------------------------------------------------
    Parameters:
        srl_file - file that contains all serial numbers
        valid_file - file that all valid serial numbers are written to
        invalid_file - file that all invalid serial numbers are written to
    Returns:
        None
     -------------------------------------------------------
    """
    line = srl_file.readline()
    counter_v = 0
    counter_i = 0
    
    while(line != ''):
        
        my_str = my_str = line.strip()
        if(valid_sn(my_str)):
            valid_file.write(line)
            counter_v += 1
        else:
            invalid_file.write(line)
            counter_i += 1
        line = srl_file.readline()
    
    if(counter_v == 0):
        valid_file.write('None')
    if(counter_i == 0):
        invalid_file.write('None')
        
    return None
    
    
    
    
    
    