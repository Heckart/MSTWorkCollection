#include <avr/io.h>

void main()
{
DDRC = 0xff;
DDRB &= 0b11111011; // make PB2 an input, keep other bits the same
PORTB |= 0b00000100; // pull-up resister for PB2
TCNT0 = 10;
TCCR0 = 0x06; // Timer 0 falling-edge counter

While(1)
{
PORTC = TCNT0;
If (TIFR & 1<<TOV0)  // note that this if statement is not included in the assembly 
// program above, this if statement shows how to reset the counter after the counter 
// has overflowed
{    
TCNT0 = 10;
TIFR = 1<<TOV0;
        }
}
}
