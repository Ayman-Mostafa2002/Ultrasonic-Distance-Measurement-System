/*
 * app.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Ayman_Mostafa
 */
#include "lcd.h"
#include "ultrasonic.h"
#include <avr/io.h>

int main(void)

{	uint16 distance = 0;
	SREG |= (1<<7);
	LCD_init();
	Ultrasonic_init();
	LCD_moveCursor(0,0);
	LCD_displayString("Distance=    CM");

	while(1)
	{
		/* calculate the distance */
		distance = Ultrasonic_readDistance();
		/* display the distance on LCD screen */
		LCD_moveCursor(0,10);
		if(distance >= 100)
		{
			LCD_intgerToString(distance);
		}
		else
		{
			LCD_intgerToString(distance);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}

	}
}

