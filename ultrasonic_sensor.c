/*
 * ultrasonic_sensor.c
 *
 * Created: 3/9/2024 12:23:00 AM
 *  Author: Ahmed Al-Sheikh
 */ 
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "LCD_driver.h"
#include "DIO_driver.h"
#include "ultrasonic.h"
#include "macros.h"
#include "led.h"
int main(void)
{
	unsigned short distance,rise_period,all_period,high_period;
	LCD_init();
	led_init('C',4);
	led_init('C',6);
	led_init('C',7);
	ultrasonic_init('D',0);
    while(1)
    {
		TCCR1A=0;         //timer 1 overflow
		TIFR=(1<<ICF1);   //clr input capture flag
		ultrasonic_send('D',0);
		TCCR1B=0xc1;    //noise canceler,rising edge and no prescaler
		while((TIFR&(1<<ICF1))==0);      //wait till flag clr
		rise_period=ICR1;            //time of rise
		TIFR=(1<<ICF1);           
		clr_bit(TCCR1B,ICES1);   //falling edge	 
		while((TIFR&(1<<ICF1))==0);
		all_period=ICR1;             //time untill fall
		TIFR=(1<<ICF1);     //clr flag
		TCNT1=0;    //zeroing counter1 
		high_period=all_period-rise_period;    //calculating counting time of high period for distance calculation(time of sound travel)
		distance=((high_period*34600)/(F_CPU*2));
		 // distance = (time) * (velocity of sound) divided by 2 as the distance is the total distance not distance of 1 way travel
		if (distance>=90)
		{
			LCD_clearscr();
			LCD_sendstring("out of range");
			led_off('C',4);
			led_off('C',6);
			led_off('C',7);
			_delay_ms(400);
			LCD_clearscr();
		} 
		else if (distance<=30)
		{
			LCD_clearscr();
			LCD_sendstring("Distance= ");
			LCD_sendnumber(distance);
			LCD_sendstring("cm");
			led_off('C',6);
			led_off('C',7);
			led_on('C',4);
			_delay_ms(400);	
		}
		else if(distance>30&&distance<=60)
		{
			LCD_clearscr();
			LCD_sendstring("Distance= ");
			LCD_sendnumber(distance);
			LCD_sendstring("cm");
			led_off('C',4);
			led_off('C',7);
			led_on('C',6);
			_delay_ms(400);
		}
		else if(distance>60&&distance<90)
		{
			LCD_clearscr();
			LCD_sendstring("Distance= ");
			LCD_sendnumber(distance);
			LCD_sendstring("cm");
			led_off('C',6);
			led_off('C',4);
			led_on('C',7);
			_delay_ms(400);
		}			
    }
}
