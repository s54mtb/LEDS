/**
  ******************************************************************************
  * @file    leds.c
  * @author  e.pavlin.si
  * @brief   LED driver module for left or right LEDS
	*          Define symbol LEDS_R to compile Right LEDS and LEDS_L to compile 
	*          for left LEDS
  ******************************************************************************
  * @attention
  *
  * <h2><center>http://e.pavlin.si</center></h2>
  * 
  * This is free and unencumbered software released into the public domain.
  * 
  * Anyone is free to copy, modify, publish, use, compile, sell, or
  * distribute this software, either in source code form or as a compiled
  * binary, for any purpose, commercial or non-commercial, and by any
  * means.
  * 
  * In  jurisdictions that recognize copyright laws, the author or authors
  * of this software dedicate any and all copyright interest in the
  * software to the public domain. We make this dedication for the benefit
  * of the public at large and to the detriment of our heirs and
  * successors. We intend this dedication to be an overt act of
  * relinquishment in perpetuity of all present and future rights to this
  * software under copyright law.
  * 
  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
  * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
  * OTHER DEALINGS IN THE SOFTWARE.

  * For more information, please refer to <http://unlicense.org>
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx.h"                  // Device header
#include "leds.h"												// LED driver 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/
HAL_StatusTypeDef LED_Timer_init(void);


/* Private variables ---------------------------------------------------------*/

/* TIM handle declaration */
TIM_HandleTypeDef    LED_TimHandle;

/* LED image frame buffer */
static uint16_t LED_frame[8];

/* Address decoder */
const uint8_t Led_addr_decoder[8] = LED_ADR_DECODE; 

/* Prescaler declaration */
uint32_t uwPrescalerValue = 0;

/* LED decoder Address counter */
static uint8_t LED_adr;



/**
  * @brief  Init LED pins, buffers and Timer
  * @param  None
  * @retval None
  */

void Init_LED(void)
{
	int i; 
	
	for (i=0; i<8; i++)
	{
		LED_frame[i] = 0;
	} 
	
	GPIO_InitTypeDef gpioinit;
	
  __HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
	
	
	  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_0|GPIO_PIN_1, GPIO_PIN_RESET);
	
	gpioinit.Mode = GPIO_MODE_OUTPUT_PP;
	gpioinit.Pull = GPIO_PULLDOWN;
	gpioinit.Speed = GPIO_SPEED_FREQ_HIGH;
	
	gpioinit.Pin = LED_MV1_PIN;
	HAL_GPIO_Init(LED_MV1_PORT, &gpioinit);

	gpioinit.Pin = LED_MV2_PIN;
	HAL_GPIO_Init(LED_MV2_PORT, &gpioinit);

	gpioinit.Pin = LED_MV3_PIN;
	HAL_GPIO_Init(LED_MV3_PORT, &gpioinit);
	
	gpioinit.Pin = LED_MV4_PIN;
	HAL_GPIO_Init(LED_MV4_PORT, &gpioinit);
	
	gpioinit.Pin = LED_MV5_PIN;
	HAL_GPIO_Init(LED_MV5_PORT, &gpioinit);
	
	gpioinit.Pin = LED_MV6_PIN;
	HAL_GPIO_Init(LED_MV6_PORT, &gpioinit);
	
	gpioinit.Pin = LED_MV7_PIN;
	HAL_GPIO_Init(LED_MV7_PORT, &gpioinit);
	
	gpioinit.Pin = LED_MV8_PIN;
	HAL_GPIO_Init(LED_MV8_PORT, &gpioinit);
	
	gpioinit.Pin = LED_MV9_PIN;
	HAL_GPIO_Init(LED_MV9_PORT, &gpioinit);
	
	gpioinit.Pin = LED_MV10_PIN;
	HAL_GPIO_Init(LED_MV10_PORT, &gpioinit);
	
	gpioinit.Pin = LED_A0_PIN;
	HAL_GPIO_Init(LED_A0_PORT, &gpioinit);
	
	gpioinit.Pin = LED_A1_PIN;
	HAL_GPIO_Init(LED_A1_PORT, &gpioinit);
	
	gpioinit.Pin = LED_A2_PIN;
	HAL_GPIO_Init(LED_A2_PORT, &gpioinit);
	
	LED_adr = 0;
	
	LED_Timer_init();
	
}


/**
  * @brief  Set hardware address decoder to logical address based on lookup table
  * @param  adr : Logical address (0...7)
  * @retval None
  */
void LED_set_adr(uint8_t adr)
{
	uint8_t hw_addr = Led_addr_decoder[adr];

	HAL_GPIO_WritePin(LED_A0_PORT, LED_A0_PIN, (GPIO_PinState)(hw_addr & 0x01) );
	hw_addr >>= 1;
	HAL_GPIO_WritePin(LED_A1_PORT, LED_A1_PIN, (GPIO_PinState)(hw_addr & 0x01) );
	hw_addr >>= 1;
	HAL_GPIO_WritePin(LED_A2_PORT, LED_A2_PIN, (GPIO_PinState)(hw_addr & 0x01) );
}


/**
  * @brief  Set second frame at address adr to value and set refresh flag
  * @param  adr : Logical address (0...7)
  * @param  value: new value at address 
  * @retval None
  */
void LED_SetBuffer(uint8_t adr, uint16_t value)
{
	if (adr<8)
	{
	  LED_frame[adr] = value;
	}
}

/**
  * @brief  Get value from main frame buffer 
  * @param  adr : Logical address (0...7)
  * @retval Value from frame buffer at address adr
  */
uint16_t LED_GetBuffer(uint8_t adr)
{
	if (adr<8)
	  return LED_frame[adr];
	else
		return 0;
}


/**
  * @brief  Set pin outputs based on frame buffer contents 
  * @param  val : 16 bit value 
  * @retval None
  */
void LED_SetVertical(uint16_t val)
{
	HAL_GPIO_WritePin(LED_MV1_PORT, LED_MV1_PIN, (GPIO_PinState)(val & 0x01) );
	val >>= 1;
	HAL_GPIO_WritePin(LED_MV2_PORT, LED_MV2_PIN, (GPIO_PinState)(val & 0x01) );
	val >>= 1;
	HAL_GPIO_WritePin(LED_MV3_PORT, LED_MV3_PIN, (GPIO_PinState)(val & 0x01) );
	val >>= 1;
	HAL_GPIO_WritePin(LED_MV4_PORT, LED_MV4_PIN, (GPIO_PinState)(val & 0x01) );
	val >>= 1;
	HAL_GPIO_WritePin(LED_MV5_PORT, LED_MV5_PIN, (GPIO_PinState)(val & 0x01) );
	val >>= 1;
	HAL_GPIO_WritePin(LED_MV6_PORT, LED_MV6_PIN, (GPIO_PinState)(val & 0x01) );
	val >>= 1;
	HAL_GPIO_WritePin(LED_MV7_PORT, LED_MV7_PIN, (GPIO_PinState)(val & 0x01) );
	val >>= 1;
	HAL_GPIO_WritePin(LED_MV8_PORT, LED_MV8_PIN, (GPIO_PinState)(val & 0x01) );
	val >>= 1;
	HAL_GPIO_WritePin(LED_MV9_PORT, LED_MV9_PIN, (GPIO_PinState)(val & 0x01) );
	val >>= 1;
	HAL_GPIO_WritePin(LED_MV10_PORT, LED_MV10_PIN, (GPIO_PinState)(val & 0x01) );
	val >>= 1;
}


/**
  * @brief  Set vertical values at specified horizontal address
  * @param  adr : Logical address (0...7)
  * @retval None
  */
void LED_refreshV(uint8_t adr)
{
	if (adr<8)
	{
		LED_SetVertical(0);
		LED_set_adr(adr);
		LED_SetVertical(LED_GetBuffer(adr));
	}
}


/**
  * @brief  Init timer 2
  * @param  None
  * @retval HAL Status: HAL_OK when Timer properly initialised
  */
HAL_StatusTypeDef LED_Timer_init(void)
{
	/*##-1- Configure the TIM peripheral #######################################*/
  /* -----------------------------------------------------------------------
    The TIM2 input clock (TIM2CLK)  is set to APB1 clock (PCLK1)
      TIM2CLK = PCLK1
      PCLK1 = HCLK
      => TIM2CLK = HCLK = SystemCoreClock
    To get TIM2 counter clock at 4800 KHz, the Prescaler is computed as following:
    Prescaler = (TIM2CLK / TIM2 counter clock) - 1
    Prescaler = (SystemCoreClock /4800 KHz) - 1

    Note:
     SystemCoreClock variable holds HCLK frequency and is defined in system_stm32f0xx.c file.
     Each time the core clock (HCLK) changes, user had to update SystemCoreClock
     variable value. Otherwise, any configuration based on this variable will be incorrect.
     This variable is updated in three ways:
      1) by calling CMSIS function SystemCoreClockUpdate()
      2) by calling HAL API function HAL_RCC_GetSysClockFreq()
      3) each time HAL_RCC_ClockConfig() is called to configure the system clock frequency
  ----------------------------------------------------------------------- */

  /* Compute the prescaler value to have TIMx counter clock equal to 4.8 MHz */
  uwPrescalerValue = (uint32_t)(SystemCoreClock / 4800000) - 1;
  
	  /* Set TIMx instance */
  LED_TimHandle.Instance = TIM2;

  /* Initialize TIMx peripheral as follows:
       + Period = 480 - 1   --->  4.8MHz/480 = 10kHz
       + Prescaler = (SystemCoreClock/4800000) - 1
       + ClockDivision = 0
       + Counter direction = Up
  */
  LED_TimHandle.Init.Period            = 480 - 1;   
  LED_TimHandle.Init.Prescaler         = uwPrescalerValue;
  LED_TimHandle.Init.ClockDivision     = 0;
  LED_TimHandle.Init.CounterMode       = TIM_COUNTERMODE_UP;
  LED_TimHandle.Init.RepetitionCounter = 0;
 
  if (HAL_TIM_Base_Init(&LED_TimHandle) != HAL_OK)
  {
    /* Initialization Error */
    return HAL_ERROR;
  }	
	
	/*##-2- Start the TIM Base generation in interrupt mode ####################*/
  /* Start Channel1 */
  if (HAL_TIM_Base_Start_IT(&LED_TimHandle) != HAL_OK)
  {
    /* Starting Error */
    return HAL_ERROR;
  }
	
	return HAL_OK;

}


/**
  * @brief  Period elapsed callback in non blocking mode
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM2)
	{
		LED_refreshV(LED_adr);
		LED_adr ++;
		if (LED_adr>7) LED_adr = 0;
	}
}



/**
  * @brief  Set pixel ad coordinate x,y
  * @param  x : 0...9
  * @param  y : 0...7
  * @param  pix : 0 or 1
  * @retval None
  */
void LED_SetPixel(uint8_t x, uint8_t y, uint8_t pix)
{
	uint16_t val = LED_GetBuffer(y);
	
	if ((x<LED_COLUMNS) & (y<LED_ROWS))
	{
		if (pix >0)
		{
		  LED_SetBuffer(y, val | 1<<x);
		}
		else 
		{
			LED_SetBuffer(y, val & (~(1<<x)&0x3ffU))  ;
		}
	}
}


void LED_clrAll(void)
{
	uint8_t a;
	for (a=0; a<LED_ROWS; a++)
	{
		LED_SetBuffer(a,0);
	}
}


void LED_setAll(void)
{
	uint8_t a;
	for (a=0; a<LED_ROWS; a++)
	{
		LED_SetBuffer(a,0x3ffU);
	}
}


