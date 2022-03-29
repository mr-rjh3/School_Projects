"""
-------------------------------------------------------
linked version of the Priority Queue ADT.
-------------------------------------------------------
Author:  David Brown
ID:      999999999
Email:   dbrown@wlu.ca
Term:    Winter 2020
__updated__ = "2020-01-16"
-------------------------------------------------------
"""
from copy import deepcopy



class _PQ_Node:

    def __init__(self, value, _next):
        """
        -------------------------------------------------------
        Initializes a priority queue node that contains a copy of value
        and a link to the next node in the priority queue
        Use: node = _PQ_Node(value, _next)
        -------------------------------------------------------
        Parameters:
            value - value value for node (?)
            _next - another priority queue node (_PQ_Node)
        Returns:
            a new Priority_Queue object (_PQ_Node)
        -------------------------------------------------------
        """
        self._value = deepcopy(value)
        self._next = _next


class Priority_Queue:

    def __init__(self):
        """
        -------------------------------------------------------
        Initializes an empty priority queue.
        Use: pq = Priority_Queue()
        -------------------------------------------------------
        Returns:
            a new Priority_Queue object (Priority_Queue)
        -------------------------------------------------------
        """
        self._front = None
        self._rear = None
        self._count = 0

    def is_empty(self):
        """
        -------------------------------------------------------
        Determines if the priority queue is empty.
        Use: b = pq.is_empty()
        -------------------------------------------------------
        Returns:
            True if priority queue is empty, False otherwise.
        -------------------------------------------------------
        """

        

        return self._count == 0

    def __len__(self):
        """
        -------------------------------------------------------
        Returns the length of the priority queue.
        Use: n = len(pq)
        -------------------------------------------------------
        Returns:
            the number of values in the priority queue.
        -------------------------------------------------------
        """

        return self._count

    def insert(self, value):
            """
            -------------------------------------------------------
            A copy of value is inserted into the priority queue.
            Values are stored in priority order. 
            Use: pq.insert(value)
            -------------------------------------------------------
            Parameters:
                value - a data element (?)
            Returns:
                None
            -------------------------------------------------------
            """
            
            flag = True
            current = self._front
            previous = None
            
            if self._count == 0:
                self._front = _PQ_Node(value, None)
                self._rear = self._front
    
            while current != None and flag:
                if previous == None and value < current._value:
                    self._front = _PQ_Node(value, self._front)
                    flag = False
                    
                elif previous != None and previous._value < value < current._value:
                    previous._next = _PQ_Node(value, current)
                    flag = False
                    
                previous = current
                current = current._next
                
                    
            if previous != None and flag:
                previous._next = _PQ_Node(value, None)
                self._rear = previous._next
                
            self._count += 1
    
            return

    def remove(self):
        """
        -------------------------------------------------------
        Removes and returns the highest priority value from the priority queue.
        Use: value = pq.remove()
        -------------------------------------------------------
        Returns:
            value - the highest priority value in the priority queue -
                the value is removed from the priority queue. (?)
        -------------------------------------------------------
        """
        assert self._count > 0, "Cannot remove from an empty priority queue"
        
        value = self._front._value
        self._front = self._front._next
        self._count -= 1
    
        return value 

    def peek(self):
        """
        -------------------------------------------------------
        Peeks at the highest priority value of the priority queue.
        Use: v = pq.peek()
        -------------------------------------------------------
        Returns:
            value - a copy of the highest priority value in the priority queue -
                the value is not removed from the priority queue. (?)
        -------------------------------------------------------
        """
        assert self._count > 0, "Cannot peek at an empty priority queue"

        return deepcopy(self._front._value)

    def split_alt(self):
        """
        -------------------------------------------------------
        Splits a priority queue into two with values going to alternating
        priority queues. The source priority queue is empty when the method
        ends. The order of the values in source is preserved.
        Use: target1, target2 = source.split_alt()
        -------------------------------------------------------
        Returns:
            target1 - a priority queue that contains alternating values
                from the current queue (Priority_Queue)
            target2 - priority queue that contains  alternating values
                from the current queue  (Priority_Queue)
        -------------------------------------------------------
        """
        target1 = Priority_Queue()
        target2 = Priority_Queue()
        left = True
        while(self._count > 0):
            if(left):
                target1._move_front_to_rear(self)
            else:
                target2._move_front_to_rear(self)
            left = not left
        return target1, target2

    def split_key(self, key):
        """
        -------------------------------------------------------
        Splits a priority queue into two depending on an external
        priority key. The source priority queue is empty when the method
        ends. The order of the values in source is preserved.
        Use: target1, target2 = pq1.split_key(key)
        -------------------------------------------------------
        Parameters:
            key - a data object (?)
        Returns:
            target1 - a priority queue that contains all values
                with priority higher than key (Priority_Queue)
            target2 - priority queue that contains all values with
                priority lower than or equal to key (Priority_Queue)
        -------------------------------------------------------
        """
        target1 = Priority_Queue()
        target2 = Priority_Queue()
        while(self._front != None):
            if(self._front._value < key):
                target1._move_front_to_rear(self)
            elif(self._front._value >= key):
                target2._move_front_to_rear(self)
        return target1, target2
        

    def combine(self, source1, source2):
        """
        -------------------------------------------------------
        Combines two source queues into the current target priority queue. 
        When finished, the contents of source1 and source2 are inserted 
        into target and source1 and source2 are empty. Order is preserved
        with source1 elements having priority over source2 elements with the
        same priority value.
        (iterative algorithm)
        Use: target.combine(source1, source2)
        -------------------------------------------------------
        Parameters:
            source1 - a linked priority queue (Priority_Queue)
            source2 - a linked priority queue (Priority_Queue)
        Returns:
            None
        -------------------------------------------------------
        """
        if(source1._front != None and source2._front != None):
            while(source1._count != 0 and source2._count != 0):
                if(source1._front._value < source2._front._value):
                    self._move_front_to_rear(source1)
                elif(source2._front._value < source1._front._value):
                    self._move_front_to_rear(source2)
                        
            if(source1._count != 0):
                self._rear._next = source1._rear
                self._rear = source1._rear
                self._count += source1._count

            elif(source2._count != 0):
                self._rear._next = source2._rear
                self._rear = source2._rear
                self._count += source2._count


        elif(source1._front != None or source2._front == None):
            self._front = deepcopy(source1._front)
            self._rear = deepcopy(source1._rear)
            self._count += source1._count

        elif(source1._front == None or source2._front != None):
            self._front = deepcopy(source2._front)
            self._rear = deepcopy(source2._rear)
            self._count += source2._count
            
        source2._front = None
        source2._rear = None
        source2._count = 0    
        source1._front = None
        source1._rear = None
        source1._count = 0
        return 
        

    def _append_queue(self, source):
        """
        -------------------------------------------------------
        Appends the entire source queue to the rear of the target queue.
        The source queue becomes empty.
        Use: target._append_queue(source)
        -------------------------------------------------------
        Parameters:
            source - an linked-based queue (Queue)
        Returns:
            None
        -------------------------------------------------------
        """
        assert source._front is not None, "Cannot append an empty priority queue"


        # Your code here

        return

    def _move_front_to_rear(self, source):
        """
        -------------------------------------------------------
        Moves the front node from the source queue to the rear of the target queue.
        The target queue contains the old front node of the source queue.
        The source queue front is updated. Order is preserved.
        Use: target._move_front_to_rear(source)
        -------------------------------------------------------
        Parameters:
            source - a linked queue (Queue)
        Returns:
            None
        -------------------------------------------------------
        """
        assert source._front is not None, "Cannot move the front of an empty priority queue"

        node = source._front
        # Update the source list
        source._count -= 1
        source._front = source._front._next
        if source._front is None:
            # Clean up source list if empty.
            source._rear = None
        # Update the target list
        if self._rear is None:
            self._front = node
        else:
            self._rear._next = node
        node._next = None
        self._rear = node
        self._count += 1
        return


    def __iter__(self):
        """
        USE FOR TESTING ONLY
        -------------------------------------------------------
        Generates a Python iterator. Iterates through the queue
        from front to rear.
        Use: for value in pq:
        -------------------------------------------------------
        Returns:
            value - the next value in the priority queue (?)
        -------------------------------------------------------
        """
        current = self._front

        while current is not None:
            yield current._value
            current = current._next

p1 = Priority_Queue()
p2 = Priority_Queue()
p = Priority_Queue()
p1.insert(11)
p1.insert(22)
p1.insert(33)
p1.insert(44)

t1,t2 = p1.split_key(33)
print(t1._front._value, t1._rear._value)
print(t2._front._value, t2._rear._value)






