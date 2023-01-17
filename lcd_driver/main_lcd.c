/*
 * man_gpio.c
 *
 *  Created on: Jan 14, 2023
 *      Author: abdo-
 */

#include "gpio.h"
#include "lcd.h"
#include <util/delay.h>

int main()
{
	gpio_init();
	LCD_init();

	const char me_string[] = "Iam Abdelrahman";
	const char hello[] = "Hello!";
	LCD_displayString(hello);
	while(1)
	{
	}
}
