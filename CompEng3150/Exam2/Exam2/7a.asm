SBI DDRD, 7
LDI R17, 0b10000000
LDI R18, 0
OUT PORTD, R18
BEGIN: RCALL DELAY
EOR R18, R17
OUT PORTD, R18
RJMP BEGIN
DELAY: LDI R21, -75
OUT TCNT0, R21
LDI R21, 0b00000011
OUT TCCR0, R21
AGAIN: SBIS TIFR, TOV0
RJMP AGAIN
LDI R21, 0b00000011
OUT TCCR0, R21
LDI R21, (1<<TOV0)
OUT TIFR, R21
RET