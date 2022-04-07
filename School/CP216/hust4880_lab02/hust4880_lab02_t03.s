/*
-------------------------------------------------------
l02_t03.s
Copies contents of one vector to another.
-------------------------------------------------------
Author:  David Brown
ID:      999999999
Email:   dbrown@wlu.ca
Date:    2020-12-13
-------------------------------------------------------
*/
.org	0x1000	// Start at memory location 1000
.text  // Code section
.global _start
_start:

.text	// code section
// Copy contents of first element of Vec1 to Vec2
LDR	R0, =Vec1
LDR	R1, =Vec2
LDR	R2, [R0]
STR	R2, [R1]
// Copy contents of second element of Vec1 to Vec2
ADD	R0, R0, #4 		// Changed to add 4 instead of 2
ADD	R1, R1, #4 		// Changed to add 4 instead of 2
LDR	R2, [R0]
STR	R2, [R1]
// Copy contents of second element of Vec1 to Vec2
ADD	R0, R0, #4		// Changed register to R0
ADD	R1, R1, #4
LDR	R2, [R0]
STR	R2, [R1]		//Changed register in square brakets to R1
// End program
_stop:
B _stop

.data	// Initialized data section
Vec1:
.word	1, 2, 3
		
.bss	// Uninitialized data section
Vec2:		
.space	12 			// Changed .word to .space and is now allocating space for 12 bytes instead of 6

.end