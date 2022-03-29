"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2020-01-29"
------------------------------------------------------------------------
"""
from Stack_array import Stack

def stack_split_alt(source):
    """
    -------------------------------------------------------
    Splits the source stack into separate target stacks.
    When finished source stack is empty. Values are
    pushed alternately onto the returned target stacks.
    Use: target1, target2 = stack_split_alt(source)
    -------------------------------------------------------
    Parameters:
        source - the stack to split into two parts (Stack)
    Returns:
        target1 - contains alternating values from source (Stack)
        target2 - contains other alternating values from source (Stack)
    -------------------------------------------------------
    """
    target1 = Stack()
    target2 = Stack()
    count = 0
    while(not source.is_empty()):
        count += 1
        if(count%2 != 0):
            target1.push(source.pop())
        else:
            target2.push(source.pop())
    return target1, target2

def stack_combine(source1, source2):
    """
    -------------------------------------------------------
    Combines two source stacks into a target stack.
    When finished, the contents of source1 and source2 are interlaced
    into target and source1 and source2 are empty.
    Use: target = stack_combine(source1, source2)
    -------------------------------------------------------
    Parameters:
        source1 - a stack (Stack)
        source2 - another stack (Stack)
    Returns:
        target - the contents of the source1 and source2
            are interlaced into target (Stack)
    -------------------------------------------------------
    """
    target = Stack()
    
    while((not source1.is_empty()) or (not source2.is_empty())):
        if(not source1.is_empty()):
            target.push(source1.pop())
        if(not source2.is_empty()):
            target.push(source2.pop())
    
    return target

def is_palindrome_stack(string):
    """
    -------------------------------------------------------
    Determines if string is a palindrome. Ignores case, spaces, and
    punctuation in string.
    Use: palindrome = is_palindrome_stack(string)
    -------------------------------------------------------
    Parameters:
        string - a string (str)
    Returns:
        palindrome - True if string is a palindrome, False otherwise (bool)
    -------------------------------------------------------
    """
    str_stack = Stack()
    ogstr = ''
    nxstr = ''
    for c in string:
        if(c.isalpha()):
            str_stack.push(c.lower())
            ogstr += c.lower()
    
    while(not str_stack.is_empty()):
        nxstr += str_stack.pop()
        
    if(ogstr == nxstr):
        palindrome = True
    else:
        palindrome = False
        
    return palindrome

# Constants
OPERATORS = "+-*/"

def postfix(string):
    """
    -------------------------------------------------------
    Evaluates a postfix expression.
    Use: answer = postfix(string)
    -------------------------------------------------------
    Parameters:
        string - the postfix string to evaluate (str)
    Returns:
        answer - the result of evaluating string (float)
    -------------------------------------------------------
    """
    
    operands = Stack()
    split_string = string.split(' ')
    for c in split_string:
        
        if(c.isnumeric()):
            operands.push(c)
        elif(c in OPERATORS):
            value1 = operands.pop()
            value2 = operands.pop()
            if(c == '+'):
                operands.push(int(value2)+int(value1))
            elif(c == '-'):
                operands.push(int(value2)-int(value1))
            elif(c == '*'):
                operands.push(int(value2)*int(value1))
            elif(c == '/'):
                operands.push(int(value2)/int(value1))

    answer = operands.pop()
    return answer

def stack_maze(maze):
    """
    -------------------------------------------------------
    Solves a maze using Depth-First search.
    Use: path = stack_maze(maze)
    -------------------------------------------------------
    Parameters:
        maze - dictionary of points in a maze, where each point
            represents a corridor end or a branch. Dictionary
            keys are the name of the point followed by a list of
            branches, if any. First point is named 'Start', exit
            is named 'X' (dict)
    Returns:
        path - list of points visited before the exit is reached,
            None if there is no exit (list of str)
    -------------------------------------------------------
    """
    key = 'Start'
    path = ['Start']
    stack = Stack()
    flag = True
    
    while(flag):
        for i in maze[key]:
            if(i not in path):
                stack.push(i)
        key = stack.pop()
        path.append(key)
        
        if(key == 'X'):
            flag = False
        elif(len(path) >= len(maze)):
            flag = False
            path = None
        
    return path

