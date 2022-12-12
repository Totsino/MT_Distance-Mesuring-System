/*
 * main.c
 *
 *  Created on: Oct 19, 2021
 *      Author: Youssef
 */


#include  <stdio.h>
#include "avr/io.h"
#include "lcd.h"
#include "icu.h"
#include "ultrasonic.h"





int main(){
	/* */
	SREG |= 1<<7;/* Enable Global Interrupt*/
	uint16 dist=0;

	LCD_init(); /* Initialize LCD */
	Ultrasonic_init(); /* Initialize Ultrasonic */
	LCD_displayStringRowColumn(0,0,"Distance =    cm");

	while(1){
		dist = Ultrasonic_readDistance();
		LCD_moveCursor(0,10);
		LCD_intgerToString(dist+2); /* +2 is optional just to maintain The Error between Ultrasonic Value and LCD Value */
		LCD_displayString(" ");

	}

}
