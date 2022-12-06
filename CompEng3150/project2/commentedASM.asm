; program to initialize neopixels and turn on LED when bright light sensed (off otherwise)


start:
    ; initialize stack pointer
    ldi r16,HIGH(RAMEND)
    out SPH,r16
    ldi r16,LOW(RAMEND)
    out SPL,r16
    RCALL NeoPixel_Init
    RCALL AD_Init
    LDI R24, 25 ; 0x19 is loaded into R24
    RCALL delay ; delay function (4,896,086 cycles or 612,011 micro seconds)
    nop

    sbi ddrc, 7 ; bit 7 in ddrc is set

    CALL tenToOne

while:
    RCALL Clear_Pixels
    RCALL Read_Light
    cpi r24, 5; what is this line of code doing with the light sensor value read?
    ;answer: R24, which holds the analog-to-digital converted light sensor value, is compared with 0x05. If 0x05 is >= R24, the program branches to nxt.
    brsh nxt
    cbi portc, 7; turn off led
    rjmp while
nxt: sbi portc, 7; turn on led
    rjmp while

    LDI R24, 25
    RCALL delay

    rjmp while

    rjmp start

                  ; R0    G0    B0,   R1    G1    B1,   R2    G2    B2,   R3    G3    B3,   R4    G4    B4,   R5    G5    B5,   R6    G6    B6,   R7    G7    B7,   R8    G8    B8,   R9    G9    B9
NP_Init_values: .DB 0x30, 0x00, 0x00, 0x30, 0x10, 0x00, 0x20, 0x20, 0x00, 0x10, 0x30, 0x00, 0x00, 0x30, 0x10, 0x00, 0x20, 0x20, 0x00, 0x10, 0x30, 0x00, 0x00, 0x30, 0x10, 0x00, 0x20, 0x20, 0x00, 0x10

NeoPixel_Init:
    PUSH R31 ; R31 (0) pushed onto stack
    PUSH R30 ; R30 (0) pushed onto stack
    PUSH R27 ; R27 (0) pushed onto stack
    PUSH R26 ; R26 (0) pushed onto stack
    PUSH R24 ; R24 (0) pushed onto stack
    PUSH R16 ; R16 (0x5F) pushed onto stack
    ; set PB0 to an output, initial value is '0'
    CBI 5,0 ; Bit 0 is cleared in PORTB
    SBI 4,0 ; Bit 0 is set in PORTB
    LDI R26, low(NeoPixel_Array) ; lower byte of NeoPixel_array (0x60) loaded into R26, X register = 0x60
    LDI R27, high(NeoPixel_Array) ; upper byte of NeoPixel_array (0x00) loaded into R27, Y register = 0x00
    LDI R30, low(NP_Init_values<<1) ; lower byte of NP_Init_values shifted left once (0x30) loaded into R30, Z register = 0x30
    LDI R31, high(NP_Init_values<<1) ; upper byte of NP_Init_values shifted left once (0x00) loaded into R31
    LDI R24, 30 ; 0x1E loaded into R24
NP_For_Loop:
    LPM R16,Z+ ; value pointed by the Z register is loaded into R16. Z and R30 are post incremented. ;
    ST X+,R16 ; X and R26 are incremented
    DEC R24 ; register 24 is decremented
    BRNE NP_For_Loop ; the NP_For_Loop branch will execute 30 times
    RCALL Update_Pixels ; pixel values are updated
    POP R16 ; stack is popped into R16
    POP R24 ; stack is popped into R16
    POP R26 ; stack is popped into R16
    POP R27 ; stack is popped into R16
    POP R30 ; stack is popped into R16
    POP R31 ; stack is popped into R16
    RET

Clear_Pixels:
    PUSH R27 ; R27 is pushed to the stack
    PUSH R26 ; R26 is pushed to the stack
    PUSH R24 ; R24 is pushed to the stack
    PUSH R16 ; R16 is pushed to the stack
    LDI R26, low(NeoPixel_Array) ; lower byte of NeoPixel_array (0x60) is stored in R26, X points to R26
    LDI R27, high(NeoPixel_Array); upper byte of NeoPixel_array (0x00) is stored in R27, Y points to R27
    LDI R24, 30 ; 0x1E loaded into R24
    LDI R16,0 ; 0x00 loaded into R16
CP_For_Loop:
    ST X+,R16 ; X and R16 are incremented
    DEC R24 ; R24 is decremented
    BRNE CP_For_Loop ; CP_For_Loop will repeat until R24 is 0. Should happen 30 times
    POP R16 ; stack is popped into R16
    POP R24 ; stack is popped into R24
    POP R26 ; stack is popped into R26
    POP R27 ; stack is popped into R27
    RET    

Update_Pixels:
    PUSH R27 ; R27 is pushed onto stack
    PUSH R26 ; R26 is pushed onto stack
    PUSH R24 ; R24 is pushed onto stack
    PUSH R22 ; R22 is pushed onto stack
    PUSH R20 ; R20 is pushed onto stack
    PUSH R16 ; R16 is pushed onto stack
    LDI R16,10 ; 0x0A is loaded into R16
    LDI R26, low(NeoPixel_Array) ; lower byte of NeoPixel_array (0x60) loaded into R26 and X register
    LDI R27, high(NeoPixel_Array) ; upper byte of NeoPixel_array (0x00) loaded into R27 and Y register;
UP_For_Loop:
    LD R24,X+ ; value pointed by the x register is loaded into R24. X/R26 is post incremented
    LD R22,X+ ; value pointed by the x register is loaded into R22. X/R26 is post incremented
    LD R20,X+ ; value pointed by the x register is loaded into R20. X/R26 is post incremented
    RCALL Send_Pixel ; neopixel values are sent
    DEC R16 ; R16 is decremented
    BRNE UP_For_Loop ; up_for_loop will continue until R16 equals 0. Should happen 10 times
    POP R16 ; stack is popped into R16
    POP R20 ; stack is popped into R20
    POP R22 ; stack is popped into R22
    POP R24 ; stack is popped into R24
    POP R26 ; stack is popped into R26
    POP R27 ; stack is popped into R27
    RET


Send_Pixel:
    ; Three parameters: R = R24, G = R22 and B = R20
    ; G needs to be sent first, then R and the B
    PUSH R24 ; R24 is pushed to the stack
    PUSH R23 ; R23 is pushed to the stack
    PUSH R22 ; R22 is pushed to the stack
    PUSH R21 ; R21 is pushed to the stack
    PUSH R20 ; R20 is pushed to the stack
    RCALL byte_loop ;
    MOV R22, R24 ; R24 is copied into R22
    RCALL byte_loop ;
    MOV R22, R20 ; R20 is copied into R20
    RCALL byte_loop
    POP R20 ; stack is popped into R20
    POP R21 ; stack is popped into R21
    POP R22 ; stack is popped into R22
    POP R23 ; stack is popped into R23
    POP R24 ; stack is popped into R24
    RET
byte_loop:
    LDI R23,8 ; 0x08 loaded into R23
    ;set PB0 to one
next_bit:
    SBI 5,0 ; Bit 0 is set in PORTB
    ROL R22 ; R22 is rotated left through carry
    BRCS send_one ; this process will continue until the carry bit equals 1
    CBI 5,0 ; Bit 0 is cleared in PORTB
    LDI R21,1          ; 14 clock cycles low
wait_zero_low:
    DEC R21 ; Register 21 is decremented
    BRNE wait_zero_low ; stay in wait zero low until R21 equals 0 (should only be once).
    RJMP exit_zero ; jump to the exit_zero branch
send_one:
    LDI R21,2           ; 14 clock cycles high
wait_one_high:
    DEC R21 ; decrement R21
    BRNE wait_one_high ; branch if r21 not equal to 0. should happen twice
    ; clear PB0 to zero
    CBI 5,0 ; clear bit 0 in PORTB
;    LDI R21,2          ; 7 clock cycles low
;wait_one_low:
;    DEC R21
;    BRNE wait_one_low
exit_zero:
    DEC R23 ; register 23 is decremented.
    BRNE next_bit ; next_bit branch will be called until r23 equals 0. Should happen 8 times.
    RET    

; Analog-to-Digital converter initialization code
; Do NOT need to comment this subroutine
AD_Init:
    PUSH R16
    LDI R16,0x96     ; Enable='1', Start ='0', Auto-Trigger='0', Flag='1' (to clear flag), IE='0' (disabled), Prescale=clock/64
    STS ADCSRA,R16
    LDI R16,0xE0     ; Ref = Internal, Left Justifed data, MUX=channel A0
    STS ADMUX,R16
    LDI R16,0x81
;    STS DIDR0,R16
    STS PORTF, R16
    POP R16
    RET

; subroutine to get analog light sensor value from Circuit Playground board
; which GPR stores the analog-to-digital converted light sensor value?
; answer: R24
Read_Light:
    PUSH R16
    LDS R16,ADMUX
    ANDI R16,0xE0
    STS ADMUX,R16
    LDS R16,ADCSRA
    ORI R16,0x50
    STS ADCSRA,R16
RL_while:
    LDS R16,ADCSRA
    ANDI R16,(1<<4)
    BREQ RL_while
    LDS R24,ADCH
    POP R16
    RET


; Delay routine based on nested loops using machine cycles
; delay lasts 4,896,086 cycles not including final ret!
delay:
   PUSH R24 ; R24 is pushed to the stack
   PUSH R18 ; R18 is pushed to the stack
   PUSH R17 ; R17 is pushed to the stack
d1:
    LDI R17,0xFF ; 0xFF is loaded into R17
d2:
    LDI R18,0xFF ; 0xFF is loaded into R18
d3:
    DEC R18 ; R18 is decremented
    BRNE d3 ; will branch to d3 255 times
    DEC R17 ; R17 is decremented
    BRNE d2    ; will branch to d2 255 times
    DEC R24 ; R24 is decremented
    BRNE d1 ; will branch to d1 25 times
    POP R17 ; stack is popped into R17
    POP R18 ; stack is popped into R18
    POP R24 ; stack is popped into R24
    ret

; subroutine to display neopixels in blue one neopixel at a time from neopixel position
; 1 to 10, then all neopixels will be off
tenToOne:
    PUSH R23 ; R23 is pushed onto stack
    PUSH R22 ; R22 is pushed onto stack
    PUSH R21 ; R21 is pushed onto stack
    PUSH R20 ; R20 is pushed onto stack
    PUSH R19 ; R19 is pushed onto stack
    PUSH R18 ; R18 is pushed onto stack
    PUSH R1 ; R1 is pushed onto stack
    PUSH R0 ; R0 is pushed onto stack

    LDI R23, 0X3F; BLUE VALUE
    LDI R21, 0X00; OFF VALUE

    LDI R19,0 ; 0x00 loaded into R19
    LDI R18,3; RGB - 3 color offset
    LDI R17,2; 0 index for R, 1 index for G, 2 index for B
neo_loop:    CALL Clear_Pixels
            
LDI R26, low(NeoPixel_Array) ; low byte of NeoPixel_array (0x60) is loaded into R26, X points to R26
    LDI R27, high(NeoPixel_Array) ; ; upper byte of NeoPixel_array (0x00) is stored in R27, Y points to R27
    
    ; CURRENT INDEX
    MUL R18,R19; 3*current index in NeoPixel_Array (RGB values at each of 10 NeoPixels)
    ; product stored in R1 R0 (since product always < 255 use R0 only)
    ADD R0,R17; CURRENT NEOPIXEL - GET B INDEX
    ADD R26,R0; R0 added to R26
    BRSH NOINC ; branch to NOINC if carry flag is cleared
    INC R27 ; increment R27
NOINC:     ST X,R23 ; store R23 in X
CALL Update_Pixels
    CALL DELAY
    INC R19 ; R19 is incremented
    CPI R19, 10 ; compare 0xA with R19
    BRNE neo_loop ; if R19 is not equal to 10, branch.

    CALL Clear_Pixels
    CALL Update_Pixels

    POP R0 ; stack is popped into R0
    POP R1 ; stack is popped into R1
    POP R18 ; stack is popped into R18
    POP R19 ; stack is popped into R19
    POP R20 ; stack is popped into R20
    POP R21 ; stack is popped into R21
    POP R22 ; stack is popped into R22
    POP R23 ; stack is popped into R23
    RET

.dseg
NeoPixel_Array: .byte 30   ; reserves 30 bytes for neopixels (RGB to 10 pixels)