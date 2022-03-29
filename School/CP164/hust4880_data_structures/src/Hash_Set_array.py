"""
-------------------------------------------------------
Array-based list version of the Hash Set ADT.
-------------------------------------------------------
Author:  David Brown
ID:      999999999
Email:   dbrown@wlu.ca
Section: CP164 Spring 2019
__updated__ = "2019-05-31"
-------------------------------------------------------
"""
# Imports
# Use any appropriate data structure here.
from List_array import List
# Define the new_slot slot creation function.
new_slot = List

# Constants
SEP = '-' * 40


class Hash_Set:
    """
    -------------------------------------------------------
    Constants.
    -------------------------------------------------------
    """
    _LOAD_FACTOR = 20

    def __init__(self, slots):
        """
        -------------------------------------------------------
        Initializes an empty Hash_Set of size slots.
        Use: hs = Hash_Set(slots)
        -------------------------------------------------------
        Parameter:
            slots - number of initial slots in Hash Set (int > 0)
        Returns:
            A new Hash_Set object (Hash_Set)
        -------------------------------------------------------
        """
        self._slots = slots
        self._table = []
        self._count = 0

        # Define the empty slots.
        for _ in range(self._slots):
            self._table.append(new_slot())

    def __len__(self):
        """
        -------------------------------------------------------
        Returns the number of values in the Hash Set.
        Use: n = len(hs)
        -------------------------------------------------------
        Returns:
            the number of values in the Hash Set.
        -------------------------------------------------------
        """
        return self._count

    def is_empty(self):
        """
        -------------------------------------------------------
        Determines if the Hash Set is empty.
        Use: b = hs.is_empty()
        -------------------------------------------------------
        Returns:
            True if the Hash Set is empty, False otherwise.
        -------------------------------------------------------
        """
        return self._count == 0

    def _find_slot(self, key):
        """
        -------------------------------------------------------
        Returns the slot for a key value.
        Use: list = hs._find_slot(key)
        -------------------------------------------------------
        Returns:
            slot - list at the position of hash key in self._table
        -------------------------------------------------------
        """

        slot = self._table[hash(key) % self._slots]
        #slot = hash(key) % self._slots
        return slot


    def __contains__(self, key):
        """
        ---------------------------------------------------------
        Determines if the Hash Set contains key.
        Use: b = key in hs
        -------------------------------------------------------
        Parameters:
            key - a comparable data element (?)
        Returns:
            True if the Hash Set contains key, False otherwise.
        -------------------------------------------------------
        """

        # your code here


    def insert(self, value):
        """
        ---------------------------------------------------------
        Inserts value into the Hash Set, allows only one copy of value.
        Calls _rehash if the Hash Set _LOAD_FACTOR is exceeded.
        Use: inserted = hs.insert(value)
        -------------------------------------------------------
        Parameters:
            value - a comparable data element (?)
        Returns:
            inserted - True if value is inserted, False otherwise.
        -------------------------------------------------------
        """
        slot = self._find_slot(value)
        inserted = False
        if(value in slot):
            inserted = True

        if(inserted == False):
            slot.append(value)
            self._count += 1
            inserted = True
            
        if(self._count > (self._LOAD_FACTOR * self._slots)):
            self._rehash()
        return inserted
        
        '''
        inserted = False
        count = 0
        
        slot = self._find_slot(value)
        # Gives slot of the item
        
        while inserted == False and count < len(self._table[slot]):
            # If it hasn't been inserted yet, and there's still room to check..
            
            if self._table[slot][count] == value:
                # If an item in the list is equal to the value..
                inserted = True
                # It's been inserted !
            
            count += 1
        
        if inserted == False:
            # If it leaves / skips the while loop non-inserted, insert ! 
            
            self._table[slot].append(value)
            self._count += 1
            inserted = True
            
        if self._count > (self._LOAD_FACTOR * self._slots):
            self._rehash()
                
        return inserted
        '''
        
    def find(self, key):
        """
        ---------------------------------------------------------
        Returns the value identified by key.
        Use: value = hs.find(key)
        -------------------------------------------------------
        Parameters:
            key - a comparable data element (?)
        Returns:
            value - if it exists in the Hash Set, None otherwise.
        -------------------------------------------------------
        """

        # your code here


    def remove(self, key):
        """
        ---------------------------------------------------------
        Removes the value matching key from the Hash Set, if it exists.
        Use: value = hs.remove(key)
        -------------------------------------------------------
        Parameters:
            key - a comparable data element (?)
        Returns:
            value - if it exists in the Hash Set, None otherwise.
        -------------------------------------------------------
        """
        value = None
        count = 0
        slot = self._find_slot(key)
        found = False
        while (count < len(slot) and not found):
            if(slot[count] == key):
                value = slot.pop(count)
                found = True
            count += 1
        return value
        


    def _rehash(self):
        """
        ---------------------------------------------------------
        Increases the number of slots in the Hash Set and reallocates the
        existing data within the Hash Set to the new table.
        Use: hs._rehash()
        -------------------------------------------------------
        Returns:
            None
        -------------------------------------------------------
        """
        self._slots = 2 * self._slots + 1
        temp_list = self._table
            
        self._table = []
        for _ in range(self._slots):
            self._table.append(new_slot())
            
        for i in temp_list:
            for j in i:
                self.insert(j)
        return 
        '''
        old_table = self._table
        old_slots = self._slots
        
        self._table = []
        self._count = 0
        self._slots = (old_slots * 2) + 1
        
        for num in range(self._slots):
            self._table.append(new_slot())
            
        for list in old_table:
            for item in list:
                self.insert(item)
                self._count +=1

        '''
        
        

    def is_identical(self, target):
        """
        ---------------------------------------------------------
        Determines whether two hash sets are identical.
        Use: b = source.is_identical(target)
        -------------------------------------------------------
        Parameters:
             target - another hash set (Hash_Set)
        Returns:
            identical - True if this hash set contains the same values 
                as other in the same order, otherwise returns False.
        -------------------------------------------------------
        """

        # your code here


    def debug(self):
        """
        USE FOR TESTING ONLY
        ---------------------------------------------------------
        Prints the contents of the Hash Set starting at slot 0,
        showing the slot currently being printed. Used for
        debugging purposes.
        Use: hs.debug()
        -------------------------------------------------------
        Returns:
            None
        -------------------------------------------------------
        """

        print(self._slots,"Slots")
        for i in range(len(self._table)):
                ('============================')
                print('Slot', i)
                for j in self._table[i]:
                    print(j)


    def __iter__(self):
        """
        USE FOR TESTING ONLY
        -------------------------------------------------------
        Generates a Python iterator. Iterates through the hash set
        from first to last slots. Assumes slot has own iterator.
        Use: for v in q:
        -------------------------------------------------------
        Returns:
            yields
            value - the next value in the list (?)
        -------------------------------------------------------
        """
        for slot in self._table:
            for item in slot:
                yield item
