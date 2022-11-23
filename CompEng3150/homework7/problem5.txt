#include <avr/io.h>
#include <avr/interrupt.h>

ISR(TIMER0_OVF_vect);

int main()
{
	DDRB=(DDRB|0x01);
	DDRC=0xFF;
	DDRD=0x00;
	PORTD=0xFF;
	
	TCNT0=-20;
	TCCR0=0x02;
	TIMSK=0x01;
	sei();
	while(1);
	return 0;
}

ISR(TIMER0_OVF_vect);
{
	PORTC=PIND;
	PORTB^=(0x01);
	TCNT0=-20;
}