"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2020-01-22"
------------------------------------------------------------------------
"""
from copy import deepcopy
from Stack_array import Stack
from Queue_array import Queue
from Priority_Queue_array import Priority_Queue
from array import array
from List_array import List

def array_to_stack(stack, source):
    """
    -------------------------------------------------------
    Pushes contents of source onto stack. At finish, source is empty.
    Last value in source is at bottom of stack,
    first value in source is on top of stack.
    Use: array_to_stack(stack, source)
    -------------------------------------------------------
    Parameters:
        stack - a Stack object (Stack)
        source - a Python list (list)
    Returns:
        None
    -------------------------------------------------------
    """

    while len(source) > 0:
        stack.push(source.pop())
    return 

def stack_to_array(stack, target):
    """
    -------------------------------------------------------
    Pops contents of stack into target. At finish, stack is empty.
    Top value of stack is at end of target,
    bottom value of stack is at beginning of target.
    Use: stack_to_array(stack, target)
    -------------------------------------------------------
    Parameters:
        stack - a Stack object (Stack)
        target - a Python list (list)
    Returns:
        None
    -------------------------------------------------------
    """
    temp_list = []
    while not stack.is_empty():
        temp_list.append(stack.pop())
    
    while len(temp_list) > 0:
        target.append(deepcopy(temp_list.pop()))
        
    return 
    
def stack_test(source):
    """
    -------------------------------------------------------
    Tests the methods of Stack for empty and
    non-empty stacks using the data in source:
    is_empty, push, pop, peek
    (Testing pop and peek while empty throws exceptions)
    Use: stack_test(source)
    -------------------------------------------------------
    Parameters:
        source - list of data (list of ?)
    Returns:
        None
    -------------------------------------------------------
    """
    stack = Stack()
    value = source[0]
    array_to_stack(stack, deepcopy(source))

    print('Stack:\n',stack)
    print('Is stack empty:\n',stack.is_empty())
    stack.push(value)
    print('Stack after pushing first value of source list:\n',stack)
    print('Peek:\n',stack.peek())
    stack.pop()
    print('Stack after pop:\n',stack)
    print('Stack passes all tests')
    
    return 


def array_to_queue(queue, source):
    """
    -------------------------------------------------------
    Inserts contents of source into queue. At finish, source is empty.
    Last value in source is at rear of queue,
    first value in source is at front of queue.
    Use: array_to_queue(queue, source)
    -------------------------------------------------------
    Parameters:
        queue - a Queue object (Queue)
        source - a Python list (list)
    Returns:
        None
    -------------------------------------------------------
    """

    while (len(source) != 0):
        queue.insert(source.pop(0))

def queue_to_array(queue, target):
    """
    -------------------------------------------------------
    Removes contents of queue into target. At finish, queue is empty.
    Front value of queue is at front of target,
    rear value of queue is at end of target.
    Use: queue_to_array(queue, target)
    -------------------------------------------------------
    Parameters:
        queue - a Queue object (Queue)
        target - a Python list (list)
    Returns:
        None
    -------------------------------------------------------
    """
    
    while (len(queue) != 0):
        target.append(queue.remove())

def array_to_pq(pq, source):
    """
    -------------------------------------------------------
    Inserts contents of source into pq. At finish, source is empty.
    Last value in source is at rear of pq,
    first value in source is at front of pq.
    Use: array_to_pq(pq, source)
    -------------------------------------------------------
    Parameters:
        pq - a Priority_Queue object (Priority_Queue)
        source - a Python list (list)
    Returns:
        None
    -------------------------------------------------------
    """
    while (len(source) != 0):
        pq.insert(source.pop(0))
    

def pq_to_array(pq, target):
    """
    -------------------------------------------------------
    Removes contents of pq into target. At finish, pq is empty.
    Highest priority value in pq is at front of target,
    lowest priority value in pq is at end of target.
    Use: pq_to_array(pq, target)
    -------------------------------------------------------
    Parameters:
        pq - a Priority_Queue object (Priority_Queue)
        target - a Python list (list)
    Returns:
        None
    -------------------------------------------------------
    """
    while (len(pq) != 0):
        target.append(pq.remove())
        
        
def queue_test(a):
    """
    -------------------------------------------------------
    Tests queue implementation.
    Tests the methods of Queue are tested for both empty and
    non-empty queues using the data in a:
        is_empty, insert, remove, peek, len
    Use: queue_test(a)
    -------------------------------------------------------
    Parameters:
        a - list of data (list of ?)
    Returns:
        None
    -------------------------------------------------------
    """
    q = Queue()
    print(len(q))
    q.insert(a[0])
    print(len(q))
    print(q.peek())
    
    array_to_queue(q, a)
    
    print(q.is_empty())
    print(len(q))
   
    q.remove()
    print(len(q))

    
   
    
    return
    
def priority_queue_test(a):
    """
    -------------------------------------------------------
    Tests priority queue implementation.
    Test the methods of Priority_Queue are tested for both empty and
    non-empty priority queues using the data in a:
        is_empty, insert, remove, peek
    Use: pq_test(a)
    -------------------------------------------------------
    Parameters:
        a - list of data (list of ?)
    Returns:
        None
    -------------------------------------------------------
    """
    pq = Priority_Queue()
    print(len(pq))
    pq.insert(a[0])
    array_to_pq(pq, a)
    print(len(pq))
    print(pq.peek())
    
    print(pq.is_empty())
    print(len(pq))
    
    pq.remove()
    print(len(pq))

    return


def array_to_list(llist, source):
    """
    -------------------------------------------------------
    Appends contests of source to llist. At finish, source is empty.
    Last element in source is at rear of llist,
    first element in source is at front of llist.
    Use: array_to_list(llist, source)
    -------------------------------------------------------
    Parameters:
        llist - a List object (List)
        source - a Python list (list)
    Returns:
        None
    -------------------------------------------------------
    """
    while (len(source) > 0):
        llist.append(source.pop(0))
        
    return None
    
    
    

def list_to_array(llist, target):
    """
    -------------------------------------------------------
    Removes contents of llist into target. At finish, llist is empty.
    Front element of llist is at front of target,
    rear element of llist is at rear of target.
    Use: list_to_array(llist, target)
    -------------------------------------------------------
    Parameters:
        llist - a List object (List)
        target - a Python list (list)
    Returns:
        None
    -------------------------------------------------------
    """
    while (len(llist) > 0):
        target.append(llist.pop(0))
        
    return None

def list_test(source):
    """
    -------------------------------------------------------
    Tests List implementation.
    The methods of List are tested for both empty and
    non-empty lists using the data in source
    Use: list_test(source)
    -------------------------------------------------------
    Parameters:
        source - list of data (list of ?)
    Returns:
        None
    -------------------------------------------------------
    """
    lst = List()
    print(lst.is_empty())
    lst.insert(0, source[0])
    lst.remove(source[0])
    print(lst.count(source[0]))
    
    print()
    
    lst.append(source[0])
    lst.index(source[0])
    print(lst.find(source[0]))
    print()
    print(lst.max())
    print()
    print(lst.min())


    return

def has_balanced_brackets(s):
    """
    -------------------------------------------------------
    Determines whether a string contains balanced brackets or not.
    Must use a Stack to do so.
    Use: b = balanced_brackets(s)
    -------------------------------------------------------
    Parameters:
        s - a string (str)
    Returns:
        balanced - True if s contains balanced brackets, False otherwise (boolean)
    -------------------------------------------------------
    """
    brackets = '([{'
    stk = Stack()
    balanced = True
    i = 0
    
    while(balanced and i == len(s)):
        if(s[i] in brackets):
            stk.push(s[i])
        elif(s[i] == ')'):
            if(stk.pop() != '('):
                balanced = False
        elif(s[i] == ']'):
            if(stk.pop() != '['):
                balanced = False
        elif(s[i] == '}'):
            if(stk.pop() != '{'):
                balanced = False
        i += 1
    if(not stk.is_empty()):
        balanced = False
    
    return balanced

print(has_balanced_brackets('[{]}}'))
    
    
    
    
    
    
    
    
    
    
    