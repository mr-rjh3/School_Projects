"""
-------------------------------------------------------
Linked version of the Set ADT.
-------------------------------------------------------
Author:  David Brown
ID:      999999999
Email:   dbrown@wlu.ca
Section: CP164 B, C
__updated__ = "2020-04-11"
-------------------------------------------------------
"""
# Imports
from copy import deepcopy


class _Set_Node:

    def __init__(self, value, next_):
        """
        -------------------------------------------------------
        Initializes a Set node that contains a copy of value
        and a link to another Set node.
        Use: node = _Set_Node(value, _next)
        -------------------------------------------------------
        Parameters:
            value - value for node (?)
            next_ - another Set node (_Set_Node)
        Returns:
            a new _Set_Node object (_Set_Node)
        -------------------------------------------------------
        """
        self._value = deepcopy(value)
        self._next = next_


class Set:

    def __init__(self):
        """
        -------------------------------------------------------
        Initializes an empty Set.
        Use: set = Set()
        -------------------------------------------------------
        Returns:
            A new Set object (Set)
        -------------------------------------------------------
        """
        self._front = None

    def __len__(self):
        """
        -------------------------------------------------------
        Returns the number of values in the Set.
        Use: n = len(set)
        -------------------------------------------------------
        Returns:
            the number of values in the Set (int)
        -------------------------------------------------------
        """
        curr = self._front
        count = 0
        while(curr != None):
            count += 1
            curr = curr._next
        return count

    def is_empty(self):
        """
        -------------------------------------------------------
        Determines if the Set is empty.
        Use: b = set.is_empty()
        -------------------------------------------------------
        Returns:
            True if the Set is empty, False otherwise.
        -------------------------------------------------------
        """
        return self._front == None

    def add(self, value):
        """
        ---------------------------------------------------------
        Adds value to the end of the Set, allows only one copy of value.
        Use: inserted = set.add(value)
        -------------------------------------------------------
        Parameters:
            value - a comparable data element (?)
        Returns:
            True if value is inserted, False otherwise (boolean)
        -------------------------------------------------------
        """
        inserted = False
        
        curr = self._front
        if(self._front != None):
            while(curr._next != None and curr._value != value):
                curr = curr._next
            if(curr._value != value):
                curr._next = _Set_Node(deepcopy(value), None)
                inserted = True
        else:
            self._front = _Set_Node(deepcopy(value), None)
            inserted = True
            
        return inserted

    def _linear_search(self, key):
        """
        -------------------------------------------------------
        Searches for the first occurrence of key in set.
        Private helper method.
        Use: prev, curr = self._linear_search(key)
        -------------------------------------------------------
        Parameters:
            key - a partial data element (?)
        Returns:
            prev - pointer to the node prev to the node containing key (_setNode)
            curr - pointer to the node containing key (_setNode)
        -------------------------------------------------------
        """
        curr = self._front
        prev = None
        while(curr != None and curr._value != key):
            prev = curr
            curr = curr._next
        return prev, curr
            

    def find(self, key):
        """
        -------------------------------------------------------
        Finds and returns a copy of the first value in set that matches key.
        Use: value = lst.find(key)
        -------------------------------------------------------
        Parameters:
            key - a partial data element (?)
        Returns:
            value - a copy of the full value matching key, otherwise None (?)
        -------------------------------------------------------
        """
        _, value_node = self._linear_search(key)
        value = deepcopy(value_node._value)
        return value
        
    
    def remove(self, key):
        """
        -------------------------------------------------------
        Finds, removes, and returns the value in set that matches key.
        Returns None if no matching value.
        Use: value = set.remove(key)
        -------------------------------------------------------
        Parameters:
            key - a partial data element (?)
        Returns:
            value - the full value matching key, otherwise None (?)
        -------------------------------------------------------
        """
        value = None
        prev, curr = self._linear_search(key)
        if(curr != None):
            value = curr._value
            if(curr == self._front):
                self._front = curr._next
            else:
                prev._next = curr._next
            
        return value

    def __contains__(self, key):
        """
        ---------------------------------------------------------
        Determines if the Set contains key.
        Use: b = key in set
        -------------------------------------------------------
        Parameters:
            key - a comparable data element (?)
        Returns:
            True if the Set contains key, False otherwise.
        -------------------------------------------------------
        """
        _, curr = self._linear_search(key)
        return curr != None

    def reverse(self):
        """
        -------------------------------------------------------
        Reverses the order of the elements in set.
        Use: source.reverse()
        -------------------------------------------------------
        Returns:
            None
        -------------------------------------------------------
        """
        curr = self._front
        prev = None
        while curr != None:
            next = curr._next
            curr._next = prev
            prev = curr
            curr = next
        self._front = prev
        return 
            
            
            
    def split_th(self):
        """
        -------------------------------------------------------
        Splits source into two parts. target1 contains the first half,
        target2 the second half. curr set becomes empty.
        Uses Tortoise/Hare algorithm.
        Use: target1, target2 = source.split_th()
        -------------------------------------------------------
        Returns:
            target1 - a new set with >= 50% of the original set (Set)
            target2 - a new set with <= 50% of the original set (Set)
        -------------------------------------------------------
        """
        target1 = Set()
        target2 = Set()
        if(not self.is_empty()):
            tortoise = self._front
            hare = self._front
            while(hare._next != None and hare._next._next != None):
                tortoise = tortoise._next
                hare = hare._next._next
                
            target2._front = tortoise._next
            tortoise._next = None
            target1._front = self._front
            self._front = None
        
        return target1, target2
    
    def combine(self, source1, source2):
        """
        -------------------------------------------------------
        Combines two source sets into the curr target set.
        When finished, the contents of source1 and source2 are interlaced
        into target and source1 and source2 are empty.
        Order of source values is preserved.
        (iterative algorithm)
        Use: target.combine(source1, source2)
        -------------------------------------------------------
        Parameters:
            source1 - an linked set (Set)
            source2 - an linked set (Set)
        Returns:
            None
        -------------------------------------------------------
        """
        while(not source1.is_empty() or not source2.is_empty()):
            if(source1._front is not None):
                self.add(source1.remove(source1._front._value))
            if(source2._front is not None):
                self.add(source2.remove(source2._front._value))
        return 

    def __iter__(self):
        """
        USE FOR TESTING ONLY
        -------------------------------------------------------
        Generates a Python iterator. Iterates through the set
        from first to last items.
        Use: for v in set:
        -------------------------------------------------------
        Returns:
            yields
            value - the next value in the set (?)
        -------------------------------------------------------
        """
        curr = self._front

        while curr is not None:
            yield curr._value
            curr = curr._next