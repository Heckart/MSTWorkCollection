// generate a 1 kHz square wave on PB3 and at the same transferring data from PORTD to PORTA

// TIMER0 FOR SQUARE WAVE
// PORTD => INPUT, PORTA => OUTPUT
// 
// FOSC = 8 MHZ
// THALF = 0.5 X 1000 US = 500 US

// F = 1000 CYC/S => T = 1/F = S/1000 CYC = 10^-3 S => 1000 X 10^-6 US

// n = 500 us/[(1cc/1MC)(1s/8 10^6 cc)] = 4000 MCs

// clk/256 => n = 500 us/[(1cc/1MC)(256/8 10^6 cc)] = 15.6 (close to 16 or could choose 15)

#include <avr/io.h>


int main(void)
{
    DDRB = 0xff;  // PORTB output  DDRB = DDRB | 0B00001000;
    DDRD = 0x00;  // PORTD INPUT
    PORTD = 0xff; // PULLUP RESISTORS FOR PORTD
    DDRA = 0xff;  // PORTA output
    
    // 4000

    TCCR0 = 0x04; 0b00000100 for prescale of 256 for clk for ATmega32
    TCNT0 = -16;
        
    while(1)
    {    
    
        // use TIFR for ATmega32
        while (!(TIFR & (1<<TOV0))) {   //0000 0001
    
            PORTA = PIND;
        }
    
        TCCR0 = 0x00; // turn off timer 0 for reset

        TIFR = 0x01;   // write a 1 to TOV0 to reset overflow flag
        TCNT0 = -16;    // reset preload
        PORTB ^= 0x08; // 00001000
        TCCR0 = 0x04; // turn timer 0 back on
    
    }
    
    return 0;
}
