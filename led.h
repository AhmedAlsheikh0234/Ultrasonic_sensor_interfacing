/*
 * led.h
 *
 * Created: 3/9/2024 2:18:09 AM
 *  Author: HaNdSyA---
 */ 


#ifndef LED_H_
#define LED_H_
void led_init(unsigned char PORT,unsigned char PIN);
void led_on(unsigned char PORT,unsigned char PIN);
void led_off(unsigned char PORT,unsigned char PIN);
void led_toggle(unsigned char PORT,unsigned char PIN);


#endif /* LED_INIT_H_ */