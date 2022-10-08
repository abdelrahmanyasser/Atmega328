/*
 * @author: Abdelrahman Yasser
 *  @breif: Gpio module driver for atmega328p
 */

#ifndef GPIO_H
#define GPIO_H

/* Includes */
#include "gpio_Cfg.h"

/* Constant macros */
#define SET_BIT(reg, bit) ((reg |= (1 << (bit)))
#define CLEAR_BIT(reg, bit) ((reg &= ~(1 << (bit)))

/* Types */
typedef enum
{
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
} pin_t;

typedef enum
{
    PORTA,
    PORTB,
    PORTC,
    PORTD
} port_t;

typedef enum
{
    PIN_INPUT,
    PIN_OUTPUT
} pinDirection_t;

typedef enum
{
    PORT_INPUT = 0x00,
    PORT_OUTPUT = 0xFF
} portDirection_t;

typedef enum
{
    PIN_LOW,
    PIN_HIGH
} pinLevel_t;

typedef uint8 portLevel_t;

/* Pull resistor not supported for simplicity */
#if (PULL_RESISTOR_CONFIG == 1)
typedef enum
{
    PULL_OFF,
    PULL_UP
} pullResistor_t;
#endif

typedef struct
{
    port_t port;
    pin_t pin;
    pinDir_t direction;
} pinConfig_t;

/* Public APIs */
void gpio_init(void);
void gpio_writeChannel(port_t port, pin_t pin, pinLevel_t level);
pinLevel_t gpio_readChannel(port_t port, pin_t pin);
void gpio_writePort(port_t port, portLevel_t level);
portLevel_t gpio_readPort(port_t port);

#endif