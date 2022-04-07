/*
-------------------------------------------------------
palindrome.s
Subroutines for determining if a string is a palindrome.
-------------------------------------------------------
Author:
ID:
Email:
Date:
-------------------------------------------------------
*/
.org    0x1000    // Start at memory location 1000
.text  // Code section
.global _start
_start:

// Test a string to see if it is a palindrome
/*
LDR    R4, =test1
LDR    R5, =_test1 - 2
BL     PrintString
BL     PrintEnter
BL     Palindrome
LDR    R4, =palindromeStr
BL     PrintString
BL     PrintTrueFalse
BL     PrintEnter

LDR    R4, =test2
LDR    R5, =_test2 - 2
BL     PrintString
BL     PrintEnter
BL     Palindrome
LDR    R4, =palindromeStr
BL     PrintString
BL     PrintTrueFalse
BL     PrintEnter
*/
LDR    R4, =test3
LDR    R5, =_test3 - 2
BL     PrintString
BL     PrintEnter
BL     Palindrome
LDR    R4, =palindromeStr
BL     PrintString
BL     PrintTrueFalse
BL     PrintEnter

_stop:
B    _stop

//-------------------------------------------------------

// Constants
.equ UART_BASE, 0xff201000     // UART base address
.equ ENTER, 0x0a     // enter character
.equ VALID, 0x8000   // Valid data in UART mask
.equ DIFF, 'a' - 'A' // Difference between upper and lower case letters

//-------------------------------------------------------
PrintChar:
/*
-------------------------------------------------------
Prints single character to UART.
-------------------------------------------------------
Parameters:
  R2 - address of character to print
Uses:
  R1 - address of UART
-------------------------------------------------------
*/
STMFD  SP!, {R1, LR}
LDR    R1, =UART_BASE   // Load UART base address
STRB   R2, [R1]         // copy the character to the UART DATA field
LDMFD  SP!, {R1, PC}

//-------------------------------------------------------
PrintString:
/*
-------------------------------------------------------
Prints a null terminated string to the UART.
-------------------------------------------------------
Parameters:
  R4 - address of string
Uses:
  R1 - address of UART
  R2 - current character to print
-------------------------------------------------------
*/
STMFD  SP!, {R1-R2, R4, LR}
LDR    R1, =UART_BASE
psLOOP:
LDRB   R2, [R4], #1     // load a single byte from the string
CMP    R2, #0           // compare to null character
BEQ    _PrintString     // stop when the null character is found
STRB   R2, [R1]         // else copy the character to the UART DATA field
B      psLOOP
_PrintString:
LDMFD  SP!, {R1-R2, R4, PC}

//-------------------------------------------------------
PrintEnter:
/*
-------------------------------------------------------
Prints the ENTER character to the UART.
-------------------------------------------------------
Uses:
  R2 - holds ENTER character
-------------------------------------------------------
*/
STMFD  SP!, {R2, LR}
MOV    R2, #ENTER       // Load ENTER character
BL     PrintChar
LDMFD  SP!, {R2, PC}

//-------------------------------------------------------
PrintTrueFalse:
/*
-------------------------------------------------------
Prints "T" or "F" as appropriate
-------------------------------------------------------
Parameter
  R0 - input parameter of 0 (false) or 1 (true)
Uses:
  R2 - 'T' or 'F' character to print
-------------------------------------------------------
*/
STMFD  SP!, {R2, LR}
CMP    R0, #0           // Is R0 False?
MOVEQ  R2, #'F'         // load "False" message
MOVNE  R2, #'T'         // load "True" message
BL     PrintChar
LDMFD  SP!, {R2, PC}

//-------------------------------------------------------
isLowerCase:
/*
-------------------------------------------------------
Determines if a character is a lower case letter.
-------------------------------------------------------
Parameters
  R2 - character to test
Returns:
  R0 - returns True (1) if lower case, False (0) otherwise
-------------------------------------------------------
*/
MOV    R0, #0           // default False
CMP    R2, #'a'
BLT    _isLowerCase     // less than 'a', return False
CMP    R2, #'z'
MOVLE  R0, #1           // less than or equal to 'z', return True
_isLowerCase:
MOV    PC, LR

//-------------------------------------------------------
isUpperCase:
/*
-------------------------------------------------------
Determines if a character is an upper case letter.
-------------------------------------------------------
Parameters
  R2 - character to test
Returns:
  R0 - returns True (1) if upper case, False (0) otherwise
-------------------------------------------------------
*/
MOV    R0, #0           // default False
CMP    R2, #'A'
BLT    _isUpperCase     // less than 'A', return False
CMP    R2, #'Z'
MOVLE  R0, #1           // less than or equal to 'Z', return True
_isUpperCase:
MOV    PC, LR

//-------------------------------------------------------
isLetter:
/*
-------------------------------------------------------
Determines if a character is a letter.
-------------------------------------------------------
Parameters
  R2 - character to test
Returns:
  R0 - returns True (1) if letter, False (0) otherwise
-------------------------------------------------------
*/
STMFD  SP!, {LR}
BL     isLowerCase      // test for lowercase
CMP    R0, #0
BLEQ   isUpperCase      // not lowercase? Test for uppercase.
LDMFD  SP!, {PC}

//-------------------------------------------------------
toLower:
/*
-------------------------------------------------------
Converts a character to lower case.
-------------------------------------------------------
Parameters
  R2 - character to convert
Returns:
  R2 - lowercase version of character
-------------------------------------------------------
*/
STMFD  SP!, {LR}
BL     isUpperCase      // test for upper case
CMP    R0, #0
ADDNE  R2, #DIFF        // Convert to lower case
LDMFD  SP!, {PC}

//-------------------------------------------------------
Palindrome:
/*
-------------------------------------------------------
Determines if a string is a palindrome.
-------------------------------------------------------
Parameters
  R4 - address of first character of string to test
  R5 - address of last character of string to test
Uses:
  R? - ?
Returns:
  R0 - returns True (1) if palindrome, False (0) otherwise
-------------------------------------------------------
*/

STMFD  SP!, {R1-R2, R4-R5, LR}

_checkletter:
LDRB   R2, [R4] 

BL isLetter
CMP R0, #0
ADDEQ R4, R4, #1	// if it is not a letter then move to next letter in memory
BEQ _checkletter

BL toLower
MOV R1, R2

LDRB   R2, [R5] 
BL isLetter
CMP R0, #0
ADDEQ R5, R5, #-1	// if it is not a letter then move to next letter in memory
BEQ _checkletter

BL toLower

MOV R0, #1	// Default true

CMP    R4, R5          // At middle of string?
BGE    _Palindrome        // Base Case: leave subroutine

ADD    R4, #1
ADD    R5, #-1

CMP R1, R2
MOVNE R0, #0
BNE _Palindrome


BL     Palindrome         // General Case: Make recursive call

_Palindrome:
LDMFD  SP!, {R1-R2, R4-R5, PC}

// Swap characters, move towards middle of string
/*
BL isLetter
CMP R0, #0
BEQ _notLetter
_notLetter:
*/




//-------------------------------------------------------
.data
.align
palindromeStr:
.asciz "Pal: "
test1:
.asciz "02otto231"
_test1:
test2:
.asciz "RaceCar"
_test2:
test3:
.asciz "A man, a plan, a canal, Panama!"
_test3:

.end