#include <avr/io.h>

int main()
{
	DDRB = 0xFF;
	
	TCCR0 = 0x04;
	TCNT0 = -16;
	
	while (1)
	{
		while (!(TIFR & (1<<TOV0))){}
		TCCR0 = 0x00;
		TCNT0 = -16;
		PORTB ^= 0x02;
		TCCR0 = 0x04;
	}

	return 0;
}