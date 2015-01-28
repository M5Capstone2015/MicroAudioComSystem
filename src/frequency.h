/*
 * frequency.h
 *
 *  Created on: Jan 24, 2015
 *      Author: Dan Thompson
 */

#ifndef FREQUENCY_H_
#define FREQUENCY_H_

#include "iocontrols.h"

#define BYTE_SIZE = 8
/**************************************************************************//**
 * @brief Toggles io with a set delay time a number of times
 * @param delayTime - delay times in Milliseconds (period will be twice this number), repetitions
 *****************************************************************************/
void toggle_with_delay(uint32_t delayTime, uint32_t repetitions)
{
	uint32_t i;
	for ( i=0; i<repetitions; i++ )
	  {
		  set_pin(0);
		  delay(delayTime);
		  clear_pin(0);
		  delay(delayTime);
	  }
}

/**************************************************************************//**
 * @brief Defines frequencies and lengths for 0,1, and header.
 * @param Bit: 0 = 0 bit, 1 = 1 bit, else = Header bit
 *****************************************************************************/
void send_bit(uint32_t bit)
{
	if((bit == 0))
	{
		toggle_with_delay(100,10);
	}
	else if((bit == 1))
	{
		toggle_with_delay(200,7);
	}
	else
	{
		toggle_with_delay(150,14);
	}
}
//works with 8000hz sampling
//void send_bit(uint32_t bit)
//{
//	if((bit == 0))
//	{
//		toggle_with_delay(1000,3);
//	}
//	else if((bit == 1))
//	{
//		toggle_with_delay(2000,3);
//	}
//	else
//	{
//		toggle_with_delay(500,3);
//	}
//}

void send_byte(uint32_t byte[])
{
	uint32_t i;
	send_bit(2);
	for ( i=0; i<8; i++ )
	  {
		send_bit(byte[i]);
	  }
}

#endif /* FREQUENCY_H_ */
