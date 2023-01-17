/*
 * man_gpio.c
 *
 *  Created on: Jan 14, 2023
 *      Author: abdo-
 */

#include "gpio.h"
#include <util/delay.h>

int main()
{
	gpio_init();

	uint8 level = 0xFF;
	while(1)
	{

		for( int j = 0; j < 3; j++)
		{
//			uint8 limit = (j == PORT_D? PIN_7: PIN_5);
//			for( i = PIN_0; i <= limit; i++)
//			{
//				gpio_writeChannel(j, i, level);
//				_delay_ms(100);
//			}
			gpio_writePort(j, level);
			_delay_ms(100);
		}
		level ^= 0xFF;
	}
}
