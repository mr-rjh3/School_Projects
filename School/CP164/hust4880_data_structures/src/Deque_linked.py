"""
-------------------------------------------------------
Linked version of the Deque ADT.
-------------------------------------------------------
Author:  David Brown
ID:      999999999
Email:   dbrown@wlu.ca
Term:    Winter 2020
__updated__ = "2020-01-16"
-------------------------------------------------------
"""
# Imports
from copy import deepcopy


class _Deque_Node:

    def __init__(self, value, _prev, _next):
        """
        -------------------------------------------------------
        Initializes a deque node.
        Use: node = _Deque_Node(value, _prev, _next)
        -------------------------------------------------------
        Parameters:
            value - value value for node (?)
            _prev - another deque node (_Deque_Node)
            _next - another deque node (_Deque_Node)
        Returns:
            a new _Deque_Node object (_Deque_Node)

        -------------------------------------------------------
        """
        self._value = deepcopy(value)
        self._prev = _prev
        self._next = _next


class Deque:

    def __init__(self):
        """
        -------------------------------------------------------
        Initializes an empty deque.
        Use: d = deque()
        -------------------------------------------------------
        Returns:
            a new Deque object (Deque)
        -------------------------------------------------------
        """
        self._front = None
        self._rear = None
        self._count = 0

    def is_empty(self):
        """
        -------------------------------------------------------
        Determines if the deque is empty.
        Use: b = deque.is_empty()
        -------------------------------------------------------
        Returns:
            True if the deque is empty, False otherwise.
        -------------------------------------------------------
        """
        
        return self._count == 0

    def __len__(self):
        """
        -------------------------------------------------------
        Returns the size of the deque.
        Use: n = len(deque)
        -------------------------------------------------------
        Returns:
            the number of values in the deque (int)
        -------------------------------------------------------
        """
        
        return self._count

    def insert_front(self, value):
        """
        -------------------------------------------------------
        Inserts a copy of value into the front of the deque.
        Use: deque.insert_front(value)
        -------------------------------------------------------
        Parameters:
            value - a data element (?)
        Returns:
            None
        -------------------------------------------------------
        """
        if(self._front != None):
            self._front._prev = _Deque_Node(value, None, self._front)
            self._front = self._front._prev
        else:
            self._front = _Deque_Node(value, None, None)
            self._rear = self._front
        self._count += 1
        return

    def insert_rear(self, value):
        """
        -------------------------------------------------------
        Inserts a copy of value into the rear of the deque.
        Use: deque.insert_rear(value)
        -------------------------------------------------------
        Parameters:
            value - a data element (?)
        Returns:
            None
        -------------------------------------------------------
        """
        if(self._front != None):
            self._rear._next = _Deque_Node(value, self._rear, None)
            self._rear = self._rear._next
        else:
            self._front = _Deque_Node(value, None, None)
            self._rear = self._front
        self._count += 1
        return

    def remove_front(self):
        """
        -------------------------------------------------------
        Removes and returns value from the front of the deque.
        Use: v = deque.remove_front()
        -------------------------------------------------------
        Returns:
            value - the value at the front of deque (?)
        -------------------------------------------------------
        """
        assert self._front is not None, "Cannot remove from an empty deque"
        value = self._front._value
        if(self._count > 1):
            self._front = self._front._next
            self._front._prev = None
        else:    
            self._front = None
            self._rear = None
        self._count -= 1
        return value

    def remove_rear(self):
        """
        -------------------------------------------------------
        Removes and returns value from the rear of the deque.
        Use: v = deque.remove_rear()
        -------------------------------------------------------
        Returns:
            value - the value at the rear of deque (?)
        -------------------------------------------------------
        """
        assert self._rear is not None, "Cannot remove from an empty deque"
        value = self._rear._value
        if(self._count > 1):
            self._rear = self._rear._prev
            self._rear._next = None
        else:    
            self._front = None
            self._rear = None
        self._count -= 1
        return value
        

    def peek_front(self):
        """
        -------------------------------------------------------
        Peeks at the front of deque.
        Use: v = deque.peek_front()
        -------------------------------------------------------
        Returns:
            value - a copy of the value at the front of deque (?)
        -------------------------------------------------------
        """
        assert self._front is not None, "Cannot peek at an empty deque"


        return deepcopy(self._front._value)

    def peek_rear(self):
        """
        -------------------------------------------------------
        Peeks at the rear of deque.
        Use: v = deque.peek_rear()
        -------------------------------------------------------
        Returns:
            value - a copy of the value at the rear of deque (?)
        -------------------------------------------------------
        """
        assert self._rear is not None, "Cannot peek at an empty deque"


        return deepcopy(self._rear._value)

    def _swap(self, l, r):
        """
        -------------------------------------------------------
        Swaps two nodes within a deque. l has taken the place of r, 
        r has taken the place of l and _front and _rear are updated 
        as appropriate. Data is not moved.
        Use: self._swap(self, l, r):
        -------------------------------------------------------
        Parameters:
            l - a pointer to a deque node (_Deque_Node)
            r - a pointer to a deque node (_Deque_Node)
        Returns:
            None
        -------------------------------------------------------
        """
        assert l is not None and r is not None, "nodes to swap cannot be None"
        if(self._count > 1):
            if(l != self._front and l != self._rear and r != self._front and r != self._rear):
                if(l._next == r):
                    l._prev._next = r
                    r._prev._next = l
                    l_old = deepcopy(l)
                    l._prev = r
                    l._next = r._next
                    r._prev = l_old._prev
                    r._next = l
                elif(l._prev == r):
                    r._prev._next = l
                    l._prev._next = r
                    r_old = deepcopy(r)
                    r._prev = l
                    r._next = l._next
                    l._prev = r_old._prev
                    l._next = r
                    
            elif(l == self._front and r == self._rear):
                l._next._prev = r
                r._prev._next = l
                l._prev = r._prev
                r._next = l._next
                l._next = None
                r._prev = None
                self._front = r
                self._rear = l
                
                
            elif(l == self._front and r != self._rear):
                l._next._prev = r
                r._prev._next = l
                l._prev = r._prev
                l._next = r._next
                r._next = r._prev
                r._prev = None
                self._front = r
                
            elif(l == self._rear and r != self._front):
                r._next._prev = l
                l._prev._next = r
                r._prev._next = l
                l._prev = r._prev
                l._next = r._next
                r._prev = l._next
                r._next = None
                self._rear = r
                
                
        
        return

    def __iter__(self):
        """
        USE FOR TESTING ONLY
        -------------------------------------------------------
        Generates a Python iterator. Iterates through the deque
        from front to rear.
        Use: for v in d:
        -------------------------------------------------------
        Returns:
            yields
            value - the next value in the deque (?)
        -------------------------------------------------------
        """
        current = self._front

        while current is not None:
            yield current._value
            current = current._next
 
