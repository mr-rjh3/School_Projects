/*
-------------------------------------------------------
list_demo.s
A simple list demo program. Traverses all elements of an integer list.
R0: temp storage of value in list
R2: address of start of list
R3: address of end of list
-------------------------------------------------------
Author:  David Brown
ID:      999999999
Email:   dbrown@wlu.ca
Date:    2020-12-14
-------------------------------------------------------
*/
.org	0x1000	// Start at memory location 1000
.text  // Code section
.global _start
_start:

LDR    R2, =Data    // Store address of start of list
LDR    R3, =_Data   // Store address of end of list
MOV    R1, #0		// Initialize sum of list values
MOV    R5, #0		// Initialize count of list values
LDR    R6, [R2]		// Initialize minimum list value
LDR    R7, [R2]		// Initialize maximum list value

Loop:
LDR    R0, [R2], #4	// Read address with post-increment (R0 = *R2, R2 += 4)
ADD    R1, R0, R1	// Add list item into R5
ADD	   R5, R5, #1	// Increment count

CMP    R6, R0		// Compare current list value with current minimum
BLT Continue_to_Max // Branch to comparing max if current value is not a minimum
MOV    R6, R0		// If less than current minimum move current value into R6 

Continue_to_Max:
CMP    R7, R0		// Compare current list value with current maximum
BGT Continue		// Branch to end if current value is not a maximum
MOV    R7, R0		// If grater than current maximum move current value into R7 

Continue:
CMP    R3, R2       // Compare current address with end of list
BNE    Loop         // If not at end, continue

_stop:
B	_stop

.data
.align
Data:
.word   4,5,-9,0,3,0,8,-7,12    // The list of data
_Data:	// End of list address

.end