/*
-------------------------------------------------------
sub_read.s
Uses a subroutine to read strings from the UART into memory.
-------------------------------------------------------
Author:  David Brown
ID:      999999999
Email:   dbrown@wlu.ca
Date:    2020-12-14
-------------------------------------------------------
*/
// Constants
.equ SIZE, 20    	// Size of string buffer storage (bytes)
.text  // Code section
.org	0x1000	// Start at memory location 1000
.global _start
_start:

MOV    R5, #SIZE
LDR    R4, =First
BL	   ReadString
LDR    R4, =Second
BL	   ReadString
LDR    R4, =Third
BL     ReadString
LDR    R4, =Last
BL     ReadString
    
_stop:
B	_stop

// Subroutine constants
.equ UART_BASE, 0xff201000     // UART base address
.equ VALID, 0x8000	// Valid data in UART mask
.equ DATA, 0x00FF	// Actual data in UART mask
.equ ENTER, 0x0A	// End of line character

ReadString:
/*
-------------------------------------------------------
Reads an ENTER terminated string from the UART.
-------------------------------------------------------
Parameters:
  R4 - address of string buffer
  R5 - size of string buffer
Uses:
  R0 - holds character to print
  R1 - address of UART
-------------------------------------------------------
*/
STMFD  SP!, {R0-R1, R4-R5, LR}
LDR R1, =UART_BASE
Loop:
LDR R0, [R1]
TST  R0, #VALID     // check if there is new data
BEQ  _end           // if no data, return 0
AND R0, R0, #DATA   // Magic
CMP  R0, #ENTER 	// Check if data is equal to ENTER
BEQ  _end      		// Branch to stop if equal to ENTER
STRB R0, [R4]       // store the character in memory
ADD  R4, R4, #1     // move to next byte in storage buffer
CMP  R4, R5         // end program if buffer full
BEQ  _end

B Loop
_end:
LDMFD  SP!, {R0-R1, R4-R5, PC}

	
.data	
.align
// The list of strings
First:
.space  SIZE
Second:
.space	SIZE
Third:
.space	SIZE
Last:
.space	SIZE
_Last:    // End of list address

.end