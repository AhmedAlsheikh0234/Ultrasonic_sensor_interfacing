/*
 * ultrasonic.c
 *
 * Created: 3/9/2024 2:32:58 AM
 *  Author: HaNdSyA---
 */ 
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "macros.h"
void ultrasonic_init(unsigned char PORT,unsigned char PIN)
{
	switch(PORT)
	{
		case 'A':
		case 'a':
		set_bit(DDRA,PIN);
		break;
		
		case 'B':
		case 'b':
		set_bit(DDRB,PIN);
		break;
		
		case 'C':
		case 'c':
		set_bit(DDRC,PIN);
		break;
		
		case 'D':
		case 'd':
		set_bit(DDRD,PIN);
		break;
		default:
		break;
	}
}
void ultrasonic_send(unsigned char PORT,unsigned char PIN)
{
	switch(PORT)
	{
		case 'A':
		case 'a':
		set_bit(PORTA,PIN);
		_delay_us(30);
		clr_bit(PORTA,PIN);
		break;
		
		case 'B':
		case 'b':
		set_bit(PORTB,PIN);
		_delay_us(30);
		clr_bit(PORTB,PIN);
		break;
		
		case 'C':
		case 'c':
		set_bit(PORTC,PIN);
		_delay_us(30);
		clr_bit(PORTC,PIN);
		break;
		
		case 'D':
		case 'd':
		set_bit(PORTD,PIN);
		_delay_us(30);
		clr_bit(PORTD,PIN);
		break;
		default:
		break;
	}
}