/*
 * @author: Abdelrahman Yasser
 *  @breif: Gpio module driver for atmega328p
 */

/* Includes */
#include <avr/io.h> /* for register names */

#include "gpio.h"
#include "gpio_Cfg.h"

/* Private */
static void gpio_setPinDirection(port_t port, pin_t pin, pinDirection_t direction);


/* Public */
void gpio_init(void)
{
    int i;
    for (i = 0; i < numOfConfiguredPins; i++ )
    {
        gpio_setPinDirection((gpioConfigSet[i].port), (gpioConfigSet[i].pin), (gpioConfigSet[i].direction));

        /* Output default level (PIN_LOW) on output pins */
        if ((gpioConfigSet[i].direction) == PIN_OUTPUT)
        {
            gpio_writeChannel((gpioConfigSet[i].port), (gpioConfigSet[i].pin), PIN_LOW);
        }
    }

}

void gpio_writeChannel(port_t port, pin_t pin, pinLevel_t level)
{
    switch(port)
    {
        case PORT_B:
        if ( level == PIN_LOW)
        {
            CLEAR_BIT(PORTB, pin);
        }
        else
        {
            SET_BIT(PORTB, pin);
        }
        break;

        case PORT_C:
        if ( level == PIN_LOW)
        {
            CLEAR_BIT(PORTC, pin);
        }
        else
        {
            SET_BIT(PORTC, pin);
        }
        break;

        case PORT_D:
        if ( level == PIN_LOW)
        {
            CLEAR_BIT(PORTD, pin);
        }
        else
        {
            SET_BIT(PORTD, pin);
        }
        break;
    }

}

pinLevel_t gpio_readChannel(port_t port, pin_t pin)
{
    pinLevel_t return_value = 0;

    switch(port)
    {
        case PORT_B:
        if (BIT_IS_SET(PINB, pin))
        {
            return_value = PIN_HIGH;
        }
        else
        {
            return_value = PIN_LOW;
        }
        break;

        case PORT_C:
        if (BIT_IS_SET(PINC, pin))
        {
            return_value = PIN_HIGH;
        }
        else
        {
            return_value = PIN_LOW;
        }
        break;

        case PORT_D:
        if ( BIT_IS_SET(PIND, pin))
        {
            return_value = PIN_HIGH;
        }
        else
        {
            return_value = PIN_LOW;
        }
        break;

    }
    return return_value;
}

void gpio_writePort(port_t port, portLevel_t level)
{
    switch(port)
    {
        case PORT_B:
        PORTB = level;
        break;

        case PORT_C:
        PORTC = level;
        break;

        case PORT_D:
        PORTD = level;
        break;
    }
}

portLevel_t gpio_readPort(port_t port)
{
    portLevel_t return_level = 0;

    switch(port)
    {
        case PORT_B:
        return_level = PINB;
        break;

        case PORT_C:
        return_level = PINC;
        break;

        case PORT_D:
        return_level = PIND;
        break;
    }
    return return_level;
}

static void gpio_setPinDirection(port_t port, pin_t pin, pinDirection_t direction)
{
    switch(port)
    {
        case PORT_B:
        if (direction == PIN_OUTPUT)
        {
            SET_BIT(DDRB, pin);
        }
        else
        {
            CLEAR_BIT(DDRB, pin);
        }
        break;

        case PORT_C:
        if (direction == PIN_OUTPUT)
        {
            SET_BIT(DDRC, pin);
        }
        else
        {
            CLEAR_BIT(DDRC, pin);
        }
        break;

        case PORT_D:
        if (direction == PIN_OUTPUT)
        {
            SET_BIT(DDRD, pin);
        }
        else
        {
            CLEAR_BIT(DDRD, pin);
        }
        break;
    }
}
