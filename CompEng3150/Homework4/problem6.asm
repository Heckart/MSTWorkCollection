.ORG0
LDI R31,0
LDI R30,0
LDI R16,0x36
ADD R30,R16
BRSH N_1
INC R31
N_1: LDI R16,0x57
ADD R30,R16
BRSH N_2
INC 31
N_2: LDI R16,0xA6
BRSH OVER
INC R31
OVER:
