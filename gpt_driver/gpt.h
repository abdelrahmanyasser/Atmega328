/*
 * gbt.h
 *
 *  Created on: Jan 17, 2023
 *      Author: abdo-
 */

#ifndef GPT_H_
#define GPT_H_

#include "std_types.h"

typedef enum
{
	TIMER_0 = 0,
	TIMER_1 = 1,
	TIMER_2 = 2
} gpt_ChannelType;


typedef struct
{
	gpt_ChannelType channelId;
	uint8 prescaler;
	uint16 top;
} gpt_ConfigType;

void gpt_init(void);
void gpt_start(gpt_ChannelType channel);
void gpt_stop(gpt_ChannelType channel);
void gpt_setCallBack(gpt_ChannelType channel, void(* notification)(void));


#endif /* GPT_H_ */
