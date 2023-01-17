/*
 * gbt_Cfg.c
 *
 *  Created on: Jan 17, 2023
 *      Author: abdo-
 */

#include "gpt_Cfg.h"

gpt_ConfigType gpt_ConfigSet0[] =
{
		{TIMER_0, 0x05, 250 }, /* Config timer 0 for 16 ms */
		{TIMER_1, 0x04, 62500/2},
		{TIMER_2, 0x07, 250 }
};

uint8 numOfConfiguredGpts = sizeof(gpt_ConfigSet0) / sizeof(gpt_ConfigType);
