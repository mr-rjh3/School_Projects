"""
------------------------------------------------------------------------
[program description]
------------------------------------------------------------------------
Author: Riley Huston
ID:     190954880
Email:  hust4880@mylaurier.ca
__updated__ = "2020-01-06"
------------------------------------------------------------------------
"""
def _linear_search(self, key):
        """
        -------------------------------------------------------
        Searches for the first occurrence of key in the set.
        Private helper method - used only by other ADT methods.
        Use: i = self._linear_search(key)
        -------------------------------------------------------
        Parameters:
            key - a partial data element (?)
        Returns:
            i - the index of key in the set, -1 if key is not found (int)
        -------------------------------------------------------
        """
        flag = False
        i = -1
        id = 0
        if(len(self._values) <= 0):
            i = -1
        else:
            while(not flag):
                if(self._values[id] == key):
                    i = id
                    flag = True
                id += 1
        return i




'''
MAGIC METHODS:
__init__: used to construct class but is called using class name
__str__: used to format class into a string
__eq__: used to compare two objects together
__lt__: used to compare and see if two objects are less than each other
__le__: used to compare and see if two objects are less than or equal to another
'''

from Student import Student


ORIGIN = ("Canadian", "Chinese", "Indian", "Ethiopian",
          "Mexican", "Greek", "Japanese", "Italian", "American",
          "Scottish", "New Zealand", "English")

string = ''
for i in range(len(ORIGIN)):
    string += '{:2d} {}\n'.format(i, ORIGIN[i])
    
print(string)

some_student = Student("123456789", "Brown", "David", "M", "1962-10-24")
other_student = Student("123456789", "Brown", "David", "M", "1962-10-24")

print(some_student == other_student)