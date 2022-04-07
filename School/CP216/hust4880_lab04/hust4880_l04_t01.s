// Constants
.equ UART_BASE, 0xff201000     // UART base address
.equ SIZE, 80        // Size of string buffer storage (bytes)
.equ VALID, 0x8000   // Valid data in UART mask
.equ ENTER, 0x0a	
.org    0x1000       // Start at memory location 1000
.text  // Code section
.global _start
_start:

// read a string from the UART
LDR  R1, =UART_BASE

LOOP:
LDR  R0, [R1] 	   // read the UART data register
TST R0, #VALID
BEQ _stop

STR  R0, [R1]      // copy the character to the UART DATA field
CMP  R0, #ENTER	   // Check if data is equal to ENTER
BEQ  _stop
B    LOOP

_stop:
B    _stop

.data  // Data section

.end