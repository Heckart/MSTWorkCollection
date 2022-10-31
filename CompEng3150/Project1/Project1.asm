.DEF outerLoop=R31
.DEF innerLoop=R30
.DEF increment=R29
.DEF decrement=R28
.DEF count=R20
.DEF opposite=R26
.DEF maximum=R25
.DEF temp=R24
.DEF offset=R23
.DEF middleLoop=R22

.DEF speakeron=R16
.DEF speakeroff=R17
.DEF ledon=R18
.DEF ledoff=R19

;.equ PORTF    = 0x0e ; uncomment for simulation
;.equ DDRF = 0x0d ; comment for flashing to board
;.equ PINF = 0x0c

.ORG 0
LDI temp, HIGH(RAMEND) ; moving stack pointer
OUT SPH, temp
LDI temp, LOW(RAMEND)
OUT SPL, temp

LDI temp, 0b11101111 ; temporary load
OUT DDRD, temp ; left button input
COM temp ; flip the bits for output
OUT PORTD, temp ; enable pull-up resistor
LDI temp, 0b10111111 ; temporary load
OUT DDRF, temp ; right button input
COM temp ; flip the bits for output
OUT PORTF, temp ; enable pull-up resistor
SBI DDRC, 7
SBI DDRC, 6

LDI outerLoop, 0  ; initializing variable (register) values
LDI innerLoop, 0
LDI count, 1 ; count starts at 0
LDI opposite, 0
LDI maximum, 25
LDI temp, 0
LDI offset, 0
LDI speakeron, 0b01000000
LDI speakeroff, 0b00000000
LDI ledon, 0b10000000
LDI ledoff, 0b00000000
LDI increment, 0
LDI decrement, 0

OUT PORTC, ledoff ; led starts out off by default (ACTIVE HIGH)

main: LDI offset, 12 ; offset for tracking presses (3 = max 1 press per .45 s)          OFFSET IS 24 for testing
    MOV opposite, maximum ; move 25 into opposite
    MOV temp, count ; move current count into temp
    SUB opposite, temp ; make opposite = 25 - count
    DEC temp ; check if count is = 0
    BREQ offLoop ; skip the on cycle if there is no count    BRLO  TO BREQ
    INC temp ; otherwise reset the count 
    onLoop: OUT PORTC, ledon ; turn LED on
        CALL partialDelay ; enter the delay/polling loop
        DEC offset ; check for time to read button
        BRNE skipOn
        LDI offset, 12 ; reset offset (button timing)
        SBRC increment, 0
        ADD count, increment ; add increment if button was pressed
        SBRC decrement, 0
        SUB count, decrement ; subtract decrement if button was pressed
        SBIC PIND, 4 ; check if left button is still pressed                     DEBOUNCE PROTECTIONS HAVE BEEN COMMENTED OUT
        DEC count ; if it still being pressed, subtract the next increment off
        SBIC PINF, 6 ; check if right button is still pressed
        INC count ; if it still being pressed, add the next increment on
        LDI increment, 0 ; reset increment and decrement values
        LDI decrement, 0 ;
        skipOn: DEC temp ; decrement the counter
            BRNE onLoop ; loop until 0 
    DEC opposite ; check if count is >0
    BREQ after ; skip the on cycle if there is no count
    INC opposite ; otherwise reset the count
    offLoop: OUT PORTC, ledoff ; turn LED off
        CALL partialDelay ; enter the delay/polling loop
        DEC offset ; check for time to read button
        BRNE skipOff
        LDI offset, 12 ; reset offset (button timing)
        SBRC increment, 0
        ADD count, increment ; add increment if button was pressed
        SBRC decrement, 0
        SUB count, decrement ; subtract decrement if button was pressed
        SBIC PIND, 4 ; check if left button is still pressed                     DEBOUNCE PROTECTIONS HAVE BEEN COMMENTED OUT
        DEC count ; if it still being pressed, subtract the next increment off
        SBIC PINF, 6 ; check if right button is still pressed
        INC count ; if it still being pressed, add the next increment on
        LDI increment, 0 ; reset increment and decrement values
        LDI decrement, 0 ;
        skipOff: DEC opposite ; decrement the counter
            BRNE offLoop ; loop until counter = 0 
    after: MOV temp, count ; move count into temp for checks
        SUBI temp, 25 ; check if count is greater than maximum
        BRNE check ; skip if there is not an overflow
        CALL NOISE500 ; if there is a carry, send the sound (500 Hz)
        LDI count, 1 ; reset the count
    check: MOV temp, count ; move count into temp for checks
        INC temp
        DEC temp 
        BRNE end ; skip if there is not a zero
        CALL NOISE1 ; if there is a carry, send the sound (1 kHz)
        LDI count, 24 ; reset the count
    end: RJMP main

; partialDelay - ~0.15 sec delay (8MHz clock) TODO: time to 0.15 s
; Registers used: R31 (outer loop iterator), R30 (inner loop iterator), R29 (increment flag), R28 (decrement flag), R22 (middle loop iterator)
; Timing info: prior increment and decrement ()
partialDelay: LDI outerLoop, 3 ; initialize outermost loop to 3
    partialLoop1:LDI middleLoop, 120 ; middle loop count to 120
        partialLoop2: LDI innerLoop, 255 ; inner loop count to 255
            partialLoop3: SBRC increment, 0 ; check if prior increment has occurred
                RJMP skipIncrementStart ; skip if there has been an increment (left button press)
                SBIC PIND, 4 ; check if left button is pressed
                INC increment ; set increment
                skipIncrementEnd: SBRC decrement, 0 ; check if prior decrement has occurred
                RJMP skipDecrementStart ; skip if there has been a decrement (right button press)
                SBIC PINF, 6 ; check if right button is pressed
                INC decrement ; set decrement
                skipDecrementEnd: DEC innerLoop ; decrement inner loop
                BRNE partialLoop3 ; jump to inner loop
            DEC middleLoop ; decrement middle loop
            BRNE partialLoop2 ; jump to middle loop
        DEC outerLoop ; decrement outer loop
        BRNE partialLoop1 ; jump to outer loop
    RET ; exit delay function  ; SBRC/SBRS/SBIS are all 1/2/3 cycles
    skipIncrementStart: RJMP skipIncrementEnd ; additional RJMPs to balance branches
    skipDecrementStart: RJMP skipDecrementEnd

 DELAY500: // DELAY LOOP FOR 500 HZ LASTS 8000 MACHINE CYCLES
    LDI middleLoop, 242
    LOOP2:
        LDI innerLoop, 10;
        LOOP1:
            DEC innerLoop
            BRNE LOOP1
        DEC middleLoop
        BRNE LOOP2
    RET

DELAY1: // DELAY LOOP FOR 1K HZ LASTS 4000 MACHINE CYCLES
    LDI middleLoop, 166 
    LOOP4:
        LDI innerLoop, 7
        LOOP3:
            DEC innerLoop
            BRNE LOOP3
        DEC middleLoop
        BRNE LOOP4
    NOP
    NOP
    RET

WAVEGEN500:
    SBI PORTC, 6; // TURN ON SPEAKER (HIGH PART OF SQUARE WAVE)
    CALL DELAY500; // WAIT
    NOP
    NOP
    NOP
    NOP
    CBI PORTC, 6; // TURN OFF SPEAKER (LOW PART OF SQUARE WAVE)
    CALL DELAY500
    RET

WAVEGEN1:
    SBI PORTC, 6; // TURN ON SPEAKER (HIGH PART OF SQUARE WAVE)
    CALL DELAY1; // WAIT
    NOP
    NOP
    NOP
    NOP
    CBI PORTC, 6; // TURN OFF SPEAKER (LOW PART OF SQUARE WAVE)
    CALL DELAY1 // WAIT
    RET

NOISE500:
    LDI outerLoop, 150 // ((8000MC/(8*10^6)Hz)*150)= 0.15s
    REPEATL:
        CALL WAVEGEN500
        DEC outerLoop
        BRNE REPEATL
    RET

NOISE1:
    LDI R21, 2  // 150 * 2 = 300
    LDI outerLoop, 150  // ((4000MC/(8*10^6)Hz)*300)= 0.15s
    REPEATr2:
        REPEATr1:
            CALL WAVEGEN1
            DEC outerLoop
            BRNE REPEATr1
        DEC R21
        BRNE REPEATr2
    RET
