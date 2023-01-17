/*
 * gbt.c
 *
 *  Created on: Jan 17, 2023
 *      Author: abdo-
 */

#include "gpt.h"
#include "gpt_Cfg.h"
#include "bit_math.h"

#include <avr/io.h> /* for register and bit definitions */
#include <avr/interrupt.h> /* for Interrupt vector definitions */

static uint8 gpt_initStatus = 0;
static void _gpt_initTimer0(void);
static void _gpt_initTimer1(void);
static void _gpt_initTimer2(void);

/*
 * Call back function pointers for TIMER0, TIMER1 and TIMER2
 */
static void (*volatile g_callBackPtrTmr0)(void) = NULL;
static void (*volatile g_callBackPtrTmr1)(void) = NULL;
static void (*volatile g_callBackPtrTmr2)(void) = NULL;

void gpt_init(void)
{
	for(int i = 0; i < numOfConfiguredGpts; i++)
	{
		if(BIT_IS_SET(gpt_initStatus ,gpt_ConfigSet0[i].channelId) )
		{
			/* Already initialized */
			continue;
		}

		switch(gpt_ConfigSet0[i].channelId)
		{
		case TIMER_0: _gpt_initTimer0();
			break;
		case TIMER_1: _gpt_initTimer1();
			break;
		case TIMER_2: _gpt_initTimer2();
			break;
		default: continue; /*invalid ID */
		}

		/* Raise initialization flag */
		SET_BIT(gpt_initStatus, gpt_ConfigSet0[i].channelId);
	}
}

void _gpt_initTimer0(void)
{
	TCCR0A = 0x02;						 /* CTC mode */
	TCNT0 = 0;							 /* Initial bottom value */
	OCR0A = gpt_ConfigSet0[TIMER_0].top; /* Top value */
	TIMSK0 = 0x02;						 /* OC0A interrupt enable */

}

void _gpt_initTimer1(void)
{
	TCCR1A = 0;						 	 /* CTC mode */
	TCCR1B = 0x08;
	TCNT1 = 0;							 /* Initial bottom value */
	OCR1A = gpt_ConfigSet0[TIMER_1].top; /* Top value */
	TIMSK1 = 0x02;						 /* OC1A interrupt enable */
}

void _gpt_initTimer2(void)
{
	TCCR2A = 0x02;						 /* CTC mode */
	TCNT2 = 0;							 /* Initial bottom value */
	OCR2A = gpt_ConfigSet0[TIMER_2].top; /* Top value */
	TIMSK2 = 0x02;						 /* OC2A interrupt enable */
}

void gpt_start(gpt_ChannelType channel)
{
	switch(channel)
	{
	case TIMER_0: TCCR0B = (gpt_ConfigSet0[TIMER_0].prescaler) & 0x07;
		break;
	case TIMER_1: TCCR1B = (TCCR1B & 0xF8) | ((gpt_ConfigSet0[TIMER_1].prescaler) & 0x07);
		break;
	case TIMER_2: TCCR2B = (gpt_ConfigSet0[TIMER_2].prescaler) & 0x07;
		break;
	default: return;
	}
}

void gpt_stop(gpt_ChannelType channel)
{
	switch(channel)
		{
		case TIMER_0: TCCR0B &= ~0x07;
			break;
		case TIMER_1: TCCR1B &= ~0x07;
			break;
		case TIMER_2: TCCR2B &= ~0x07;
			break;
		default: return;
		}
}

void gpt_setCallBack(gpt_ChannelType channel, void(*notification)(void))
{
	switch(channel)
		{
		case TIMER_0: g_callBackPtrTmr0 = notification;
			break;
		case TIMER_1: g_callBackPtrTmr1 = notification;
			break;
		case TIMER_2: g_callBackPtrTmr2 = notification;
			break;
		}
}


/* Timer0 ISR CTC mode */
ISR(TIMER0_COMPA_vect) {
	if( g_callBackPtrTmr0 != NULL)
		g_callBackPtrTmr0();
}

/* Timer1 ISR CTC mode channel a */
ISR(TIMER1_COMPA_vect) {
	if( g_callBackPtrTmr1 != NULL)
		g_callBackPtrTmr1();
}

/* Timer2 ISR CTC mode */
ISR(TIMER2_COMPA_vect) {
	if( g_callBackPtrTmr2 != NULL)
		g_callBackPtrTmr2();
}
