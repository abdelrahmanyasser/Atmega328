/*
 * @author: Abdelrahman Yasser
 *  @breif: Gpio module driver for atmega328p
 */

#include "gpio.h"
/* Private */
static void gpio_setPinDirection(port_t port, pin_t pin, pinDirection_t direction);


/* Public */
void gpio_init(void)
{
    int i;
    for (i = 0; i < NUM_OF_CONFIG_PINS; i++ )
    {
        gpio_setPinDirection((gpioConfigSet[i]->port), (gpioConfigSet[i]->pin), (gpioConfigSet[i]->direction));

        /* Output default level (PIN_LOW) on output pins */
        if ((gpioConfigSet[i]->direction) == PIN_OUTPUT)
        {
            gpio_writeChannel((gpioConfigSet[i]->port), (gpioConfigSet[i]->pin), PIN_LOW);
        }
    }

}

void gpio_writeChannel(port_t port, pin_t pin, pinLevel_t level)
{
    switch(port)
    {
        case PORTA:
        if ( level == PIN_LOW)
        {
            CLEAR_BIT(PORTA, pin);
        }
        else
        {
            SET_BIT(PORTA, pin);
        }
        break;

        case PORTB:
        if ( level == PIN_LOW)
        {
            CLEAR_BIT(PORTB, pin);
        }
        else
        {
            SET_BIT(PORTB, pin);
        }
        break;

        case PORTC:
        if ( level == PIN_LOW)
        {
            CLEAR_BIT(PORTC, pin);
        }
        else
        {
            SET_BIT(PORTC, pin);
        }
        break;

        case PORTD:
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
        case PORTA:
        if ( PINA & (1<<pin) == 1)
        {
            return_value = PIN_HIGH;
        }
        else
        {
            return_value = PIN_LOW;
        }
        break;

        case PORTB:
        if ( PINB & (1<<pin) == 1)
        {
            return_value = PIN_HIGH;
        }
        else
        {
            return_value = PIN_LOW;
        }
        break;

        case PORTC:
        if ( PINC & (1<<pin) == 1)
        {
            return_value = PIN_HIGH;
        }
        else
        {
            return_value = PIN_LOW;
        }
        break;

        case PORTD:
        if ( PIND & (1<<pin) == 1)
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
        case PORTA:
        PORTA = level;
        break;

        case PORTB:
        PORTB = level;
        break;

        case PORTC:
        PORTC = level;
        break;

        case PORTD:
        PORTD = level;
        break;
    }
}

portLevel_t gpio_readPort(port_t port)
{
    portLevel_t return_level = 0;

    switch(port)
    {
        case PORTA:
        return_level = PINA;
        break;

        case PORTB:
        return_level = PINB;
        break;

        case PORTC:
        return_level = PINC;
        break;

        case PORTD:
        return_level = PIND;
        break;
    }
    return return_level;
}

static void gpio_setPinDirection(port_t port, pin_t pin, pinDirection_t direction)
{
    switch(port)
    {
        case PORTA:
        if (direction == PIN_OUTPUT)
        {
            SET_BIT(DDRA, pin);
        }
        else
        {
            CLEAR_BIT(DDRA, pin);
        }
        break;

        case PORTB:
        if (direction == PIN_OUTPUT)
        {
            SET_BIT(DDRB, pin);
        }
        else
        {
            CLEAR_BIT(DDRB, pin);
        }
        break;

        case PORTC:
        if (direction == PIN_OUTPUT)
        {
            SET_BIT(DDRC, pin);
        }
        else
        {
            CLEAR_BIT(DDRC, pin);
        }
        break;

        case PORTC:
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
