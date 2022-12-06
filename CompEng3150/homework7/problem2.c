#include <avr/io.h>
#include <avr/interrupt.h>

ISR(TIMER0_OVF_vect);

int main()
{
	TCCR0=0x04;
	TCNT0=-16;
	TIMSK=0x01;
	DDRB=0xFF;
	DDRA=0xFF;
	DDRD=0x00;
	PORTD=0xFF;
	sei();
	while(1);
	return 0;
}

ISR(TIMER0_OVF_vect);
{
	PORTB^=0x08;
	PORTA=PIND;
	TCNT0=-16;
}