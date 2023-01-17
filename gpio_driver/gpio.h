/*
 * @author: Abdelrahman Yasser
 *  @breif: Gpio module driver for atmega328p
 */

#ifndef GPIO_H
#define GPIO_H

#include <avr/io.h>

/* Includes */
#include "std_types.h"
#include "bit_math.h"

/* Types */
typedef enum
{
    PIN_0,
    PIN_1,
    PIN_2,
    PIN_3,
    PIN_4,
    PIN_5,
    PIN_6,
    PIN_7
} pin_t;

typedef enum
{
    PORT_B,
    PORT_C,
    PORT_D
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
    uint8 port;
    uint8 pin;
    uint8 direction;
} pinConfig_t;

/* Public APIs */
void gpio_init(void);
void gpio_writeChannel(port_t port, pin_t pin, pinLevel_t level);
pinLevel_t gpio_readChannel(port_t port, pin_t pin);
void gpio_writePort(port_t port, portLevel_t level);
portLevel_t gpio_readPort(port_t port);

#endif
