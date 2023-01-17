/*
 * main_gpt.c
 *
 *  Created on: Jan 17, 2023
 *      Author: abdo-
 */

#include "gpt.h"
#include <avr/io.h>
#include "bit_math.h"

void toggleLed_8bit_1hz(void)
{
	static uint8 seconds = 0;
	static uint8 count = 0;
	if(count > 62)
	{
		seconds++;
		PORTB ^= (1<<5);
		count = 0;
		if(seconds >= 5)
		{
			gpt_stop(TIMER_2);
		}
	}
	else
	{
		count++;
	}
}

void toggleLed_16bit_half_hz(void)
{
	static uint8 seconds = 0;
	PORTB ^= (1<<5);
	seconds++;
	if(seconds >= 40)
	{
		gpt_stop(TIMER_1);
	}
}

int main()
{
	gpt_init();
	//gpt_setCallBack(TIMER_0, toggleLed_8bit_1hz);
	gpt_setCallBack(TIMER_1, toggleLed_16bit_half_hz);
	//gpt_setCallBack(TIMER_2, toggleLed_8bit_1hz);
	DDRB |= (1 << 5);	/* set PB5 as output */
	PORTB &= ~(1 << 5);	/* initial value 0 */

	SET_BIT(SREG, 7);
	//gpt_start(TIMER_0);
	gpt_start(TIMER_1);
	while(1);

}
