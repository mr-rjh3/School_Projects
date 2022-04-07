// Constants
.equ UART_BASE, 0xff201000     // UART base address
.equ SIZE, 80        // Size of string buffer storage (bytes)
.equ VALID, 0x8000   // Valid data in UART mask
.equ DATA, 0x00ff
.org    0x1000       // Start at memory location 1000
.text  // Code section
.global _start
_start:

// read a string from the UART
LDR  R1, =UART_BASE
LDR  R4, =READ_STRING
ADD  R5, R4, #SIZE // store address of end of buffer

LOOP:
LDR  R0, [R1] 	   // read the UART data register
TST R0, #VALID
BEQ  _stop
AND R0, R0, #DATA
STR R0, [R1]
CMP  R0, #0x0a	   // Check if data is equal to ENTER
BEQ  _stop         // Branch to stop if equal to ENTER
STRB  R0, [R4]      // copy the character to the UART DATA field
ADD  R4, R4, #1    // move to next byte in storage buffer
CMP  R4, R5        // end program if buffer full
BEQ  _stop
B    LOOP

_stop:
B    _stop

.data  // Data section
// Set aside storage for a string
READ_STRING:
.space    SIZE

.end