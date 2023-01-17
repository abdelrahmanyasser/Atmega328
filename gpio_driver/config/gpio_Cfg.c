/*
 * @author: Abdelrahman Yasser
 *  @breif: configuration .c for Gpio module driver for atmega328p
 */

#include "gpio.h"
#include "gpio_Cfg.h"

pinConfig_t gpioConfigSet[] = 
{
	    {PORT_B, PIN_0, PIN_OUTPUT},
	    {PORT_B, PIN_1, PIN_OUTPUT},
	    {PORT_B, PIN_2, PIN_OUTPUT},
	    {PORT_B, PIN_3, PIN_OUTPUT},
	    {PORT_B, PIN_4, PIN_OUTPUT},
	    {PORT_B, PIN_5, PIN_OUTPUT},

	    {PORT_C, PIN_0, PIN_OUTPUT},
	    {PORT_C, PIN_1, PIN_OUTPUT},
	    {PORT_C, PIN_2, PIN_OUTPUT},
	    {PORT_C, PIN_3, PIN_OUTPUT},
	    {PORT_C, PIN_4, PIN_OUTPUT},
	    {PORT_C, PIN_5, PIN_OUTPUT},


	    {PORT_D, PIN_0, PIN_OUTPUT},
	    {PORT_D, PIN_1, PIN_OUTPUT},
	    {PORT_D, PIN_2, PIN_OUTPUT},
	    {PORT_D, PIN_3, PIN_OUTPUT},
	    {PORT_D, PIN_4, PIN_OUTPUT},
	    {PORT_D, PIN_5, PIN_OUTPUT},
	    {PORT_D, PIN_6, PIN_OUTPUT},
	    {PORT_D, PIN_7, PIN_OUTPUT}
};

uint8 numOfConfiguredPins = sizeof(gpioConfigSet) / sizeof(pinConfig_t);
