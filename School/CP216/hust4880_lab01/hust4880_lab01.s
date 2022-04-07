/*
-------------------------------------------------------
Lab 01
Intro
-------------------------------------------------------
Author:  Riley Huston
ID:      190954880
Email:   hust4880@mylaurier.ca
Date:    2021-01-20
-------------------------------------------------------
*/
.org    0x1000  // Start at memory location 1000
.text  // Code section
.global _start
_start:

MOV R0, #9       // Store decimal 9 in register R0
MOV R1, #14     // Store hex E (decimal 14) in register R1
ADD R2, R1, R0  // Add the contents of R0 and R1 and put result in R2
MOV R3, #8     // Store decimal 9 in register R3
ADD R3, R3, R3 // Add R3 with itself and put result in R3
ADD R4, R3, #4  // You cannot add 2 immediate values with the ADD instruction one must be a register


// End program
_stop:
B   _stop