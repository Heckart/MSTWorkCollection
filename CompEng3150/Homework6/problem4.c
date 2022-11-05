// 100 ms = 100(10^-3) = 100000(10^-6)
// n = td/tMC = 100000(10^-6) s/((1 cc/1MC)(1s/8(10^6)cc)) = 800000 MC
// Using a prescale factor of 1024 gives 781 ticks (> 255 so will need to use a loop with the timer 0 TOV0 interrupt).  Choose a prescale factor that gives a close to exact integer loop value => n = 800000/256 = 3125  3125 = 125 x 25 based on fosc = 8 MHz

#include <avr/io.h>

#define TOTALITERATIONS 25
#define TOTALHALFPERIODS 5

Void timerdelay();
Void delayroutine(); 

unsigned char numberIterations;  // need to iterate 25
unsigned char numberHalfPeriods;  // need to iterate 5 times


void main(void)
{
    DDRB = 0xff;   // PB2 AND OTHER BITS OF PORTB OUTPUT
    DDRD  = 0x00;
    PORTD = 0xff;  // PORTD INPUT WITH PULLUP
    DDRC = 0xff;  // portc output        
    
    numberIterations = 0; // initialize number of iterations
    numberHalfPeriods = 0; // initial number of half periods
    
    
    while (1) 
        {
        PORTC = PIND;
        delayroutine();
}
}
        
void delayroutine()
{
    
    if (numberIterations < TOTALITERATIONS)
    {
timerdelay();     
}
    else if (numberHalfPeriods < TOTALHALFPERIODS)
    {
        PORTB ^= 0x04;  // toggle PB2
        numberIterations = 0; // reset number of iterations for next half-wave
        timerdelay();
        numberHalfPeriods += 1;
    }
    else 
    {
        numberIterations = 0; // initialize number of iterations
        numberHalfPeriods = 0; // initial number of half periods
        timerdelay(); 
    }
    numberIterations += 1; // increment the total number of iterations
}

void timerdelay() 
{
TCNT0 = -125; // Timer 0 preload for 1 of TOTALITERATIONS
              // n = 800000/256 = 3125  3125 = 125 x 25 based on fosc = 8 MHz
    TCCR0 = 0x04;  // 00000100 => 100 clk/256
    While (!(TIFR & 1<<TOV0)); // wait for timer 0 overflow
    TCCR0 = 0x00;  // turn off Timer 0
    TIFR = 1<<TOV0;  // Reset TOV0 flag in TIFR
}
