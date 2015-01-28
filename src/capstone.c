/**************************************************************************//**
 * @file
 * @brief Simple LED Blink Demo for EFM32TG_STK3300
 * @version 3.20.5
 ******************************************************************************
 * @section License
 * <b>(C) Copyright 2014 Silicon Labs, http://www.silabs.com</b>
 *******************************************************************************
 *
 * This file is licensed under the Silabs License Agreement. See the file
 * "Silabs_License_Agreement.txt" for details. Before using this software for
 * any purpose, you must agree to the terms of that agreement.
 *
 ******************************************************************************/

#include <stdint.h>
#include <stdbool.h>
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "bsp.h"
#include "bsp_trace.h"
#include "em_gpio.h"
#include "iocontrols.h"
#include "frequency.h"


/**************************************************************************//**
 * @brief SysTick_Handler
 * Interrupt Service Routine for system tick counter
 *****************************************************************************/
void SysTick_Handler(void)
{
  msTicks++;       /* increment counter necessary in Delay()*/
}

/**************************************************************************//**
 * @brief  Main function
 *****************************************************************************/
int main(void)
{
  /* Chip errata */
  CHIP_Init();

  /* If first word of user data page is non-zero, enable eA Profiler trace */
  BSP_TraceProfilerSetup();

  /* Setup SysTick Timer for 1 msec interrupts  */
  if (SysTick_Config(CMU_ClockFreqGet(cmuClock_CORE) / 1000)) while (1) ;

  /* Initialize LED driver */
  BSP_PinsInit();

  /* Infinite blink loop */
  uint32_t bytetest[8]= {0,0,1,0,1,0,1,1};

  while (1)
  {
//	  toggle_with_delay(5000,1);
//	  toggle_with_delay(2000,1);
//	  toggle_with_delay(500,3);
//	  toggle_with_delay(1000,1);
//	  toggle_with_delay(6000,1);
	  send_byte(bytetest);
//	  send_bit(2);
//	  send_bit(0);
//	  send_bit(1);
//	  send_bit(1);
//	  send_bit(0);
  }
}
