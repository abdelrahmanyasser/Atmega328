/*
 * @author: Abdelrahman Yasser
 *  @breif: configuration .c for Gpio module driver for atmega328p
 */

#include "gpio.h"

pinConfig_t gpioConfigSet[NUM_OF_CONFIG_PINS] = 
{
    {PORTA, PIN0, PIN_OUTPUT},
    {PORTA, PIN1, PIN_OUTPUT},
    {PORTA, PIN2, PIN_OUTPUT},
    {PORTA, PIN3, PIN_OUTPUT},
    {PORTA, PIN4, PIN_OUTPUT},
    {PORTA, PIN5, PIN_OUTPUT},
    {PORTA, PIN6, PIN_OUTPUT},
    {PORTA, PIN7, PIN_OUTPUT},

    {PORTB, PIN0, PIN_OUTPUT},
    {PORTB, PIN1, PIN_OUTPUT}
}