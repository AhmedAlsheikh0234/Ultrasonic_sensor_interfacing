/*
 * led.c
 *
 * Created: 3/9/2024 2:17:44 AM
 *  Author: HaNdSyA---
 */
#include <avr/io.h>
#include "DIO_driver.h"
void led_init(unsigned char PORT,unsigned char PIN)
{
		DIO_setpindir(PORT,PIN,1);
}
void led_on(unsigned char PORT,unsigned char PIN)
{
	DIO_pinwrite(PORT,PIN,1);
}
void led_off(unsigned char PORT,unsigned char PIN)
{
	DIO_pinwrite(PORT,PIN,0);
}
void led_toggle(unsigned char PORT,unsigned char PIN)
{
	DIO_togglepin(PORT,PIN);
}
