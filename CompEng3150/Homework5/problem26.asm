CBI DDRB,5
CBI DDRB,6
AGAIN: SBIS PINB,5
LDI R16, 0x55
OUT PORTC,R16; 5=0
SBIS PINB,5
RJMP AGAIN; 5=0
SBIC PINB,6
LDI R16, 0xAB
OUT PORTC,R16; 6=1, 5=1
SBIS PINB,6
LDI R16,0x55
OUT PORTC,R16; 6=0
RJMP AGAIN
