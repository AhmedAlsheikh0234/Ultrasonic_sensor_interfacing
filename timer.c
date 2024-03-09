/*
 * timer.c
 *
 * Created: 2/4/2024 4:34:10 AM
 *  Author: HaNdSyA---
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include "macros.h"
void timer2_overflow_init(void)
{
	set_bit(ASSR,AS2); //enabling external crystal
	set_bit(TCCR2,CS20);  //adjusting pre scaler(1/128) [for external clock 32768 Hz] to make T=1second
	set_bit(TCCR2,CS22);
	sei();                //enabling T2 interrupt source
	set_bit(TIMSK,TOIE2);

/*
void timer1int_incap_normal(void)
{
	TCCR1A=0;     // timer 1 normal mode(over flow)
	TIFR=(1<<ICF1);   //input capture flag zeroed to activate it
	TCCR1B=0xc2;   //rising edge, noise canceler with clk/8 prescaler
	
}
*/