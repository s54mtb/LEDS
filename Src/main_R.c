/**
  ******************************************************************************
  * @file    main_R.c
  * @author  e.pavlin.si
  * @brief   Main module for right LEDS
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
#include "stm32f0xx_hal.h"
#include "leds.h"
#include "graphics.h"
#include "fonts.h"

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc;
/* Variable used to get converted value */
__IO uint16_t uhADCxConvertedValue = 0;

I2C_HandleTypeDef hi2c1;

/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC_Init(void);
static void MX_I2C1_Init(void);

/* Private function prototypes -----------------------------------------------*/


int main(void)
{


	uint32_t i=0,j,k;
	uint8_t x=103,y=104,xo=103,yo=104;
	int8_t dx=1, dy=1;
	
		char str[3], ch;

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ADC_Init();
  MX_I2C1_Init();

  Init_LED();

	/* Infinite loop */
  while (1)
  {
				str[1] =0;
		for (ch = 32; ch<0x7f; ch++)
		{
			LED_clrAll();
		  str[0] = ch;
		  graphics_text(0,0,FONT_FIVE_DOT,str);
			for (i=0; i<1000000; i++);
		}
	  

		
//		for (k=0; k<50000; k++)
//		{
//		xo = x;
//		HAL_ADC_Start(&hadc);
//		HAL_ADC_PollForConversion(&hadc, 10);
//		uhADCxConvertedValue = HAL_ADC_GetValue(&hadc);
//		x = (4200 - uhADCxConvertedValue) / 400;
//		

//			for (i=0; i<10; i++)
//			{
//					for (j=0; j<8; j++)
//					{
//					if (x>i)
//						LED_SetPixel(i,j,1);
//					else
//						LED_SetPixel(i,j,0);
//					}
//			}
//		}
//		
//    		
//		for (i=0; i<50; i++)
//		{
//			LED_setAll();
//			for (j=0; j<50000-i*i; j++);
//			LED_clrAll();
//			for (j=0; j<100000-i*i; j++);
//			
//		}
//		
//	
//			for (xo=0; xo<10; xo++)
//				for (yo=0; yo<8; yo++)
//					{
//						LED_SetPixel(xo,yo,0);
//					}
//			

//		
//		for (x=0; x<10; x++)
//			for (y=0; y<8; y++)
//				{
//					LED_SetPixel(x,y,1);
//					for (i=0; i<50000; i++);
//				}
//				
//		for (x=0; x<10; x++)
//			for (y=0; y<8; y++)
//				{
//					LED_SetPixel(x,y,0);
//					for (i=0; i<50000; i++);
//				}

//		for (y=0; y<8; y++)
//			for (x=0; x<10; x++)
//				{
//					LED_SetPixel(x,y,1);
//					for (i=0; i<500000; i++);
//				}
//				
//		for (y=0; y<8; y++)
//			for (x=0; x<10; x++)
//				{
//					LED_SetPixel(x,y,0);
//					for (i=0; i<50000; i++);
//				}

//				
//		for (y=0; y<8; y++)
//			for (x=0; x<10; x++)
//				{
//					LED_SetPixel(x,y,1);
//					for (i=0; i<150000; i++);
//					LED_SetPixel(x,y,0);
//					for (i=0; i<50000; i++);
//				}
//				
//    for (j=0; j<1000*10000; j++)
//		{
//			i++; 
//			if (i>10000) 
//			{
//				i = 0;
//				x+=dx;
//				y+=dy;
//				if (x>109) {dx = -1; x = 109;}
//				if (x<100) {dx = 1; x = 100;}
//				if (y>107) {dy = -1; y = 107;}
//				if (y<100) {dy = 1; y = 100;}
//				for (xo=0; xo<10; xo++)
//					for (yo=0; yo<8; yo++)
//						{
//							LED_SetPixel(xo,yo,0);
//						}
//				LED_SetPixel(x-100,y-100,1);		
//			}
//		}
//		
  }


}




/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_PeriphCLKInitTypeDef PeriphClkInit;

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI14|RCC_OSCILLATORTYPE_HSI48;
  RCC_OscInitStruct.HSI48State = RCC_HSI48_ON;
  RCC_OscInitStruct.HSI14State = RCC_HSI14_ON;
  RCC_OscInitStruct.HSI14CalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI48;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1);

  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_I2C1;
  PeriphClkInit.I2c1ClockSelection = RCC_I2C1CLKSOURCE_SYSCLK;
  HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit);

  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}


/* ADC init function */
static void MX_ADC_Init(void)
{

  ADC_ChannelConfTypeDef sConfig;

    /**Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion) 
    */
  hadc.Instance = ADC1;
  hadc.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV1;
  hadc.Init.Resolution = ADC_RESOLUTION_12B;
  hadc.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc.Init.ScanConvMode = ADC_SCAN_DIRECTION_FORWARD;
  hadc.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  hadc.Init.LowPowerAutoWait = DISABLE;
  hadc.Init.LowPowerAutoPowerOff = DISABLE;
  hadc.Init.ContinuousConvMode = ENABLE;
  hadc.Init.DiscontinuousConvMode = DISABLE;
  hadc.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc.Init.DMAContinuousRequests = DISABLE;
  hadc.Init.Overrun = ADC_OVR_DATA_PRESERVED;
  if (HAL_ADC_Init(&hadc) != HAL_OK)
  {
    //Error_Handler();
  }

    /**Configure for the selected ADC regular channel to be converted. 
    */
  sConfig.Channel = ADC_CHANNEL_0;
  sConfig.Rank = ADC_RANK_CHANNEL_NUMBER;
  sConfig.SamplingTime = ADC_SAMPLETIME_13CYCLES_5;
//  if (HAL_ADC_ConfigChannel(&hadc, &sConfig) != HAL_OK)
//  {
//    //Error_Handler();
//  }

    /**Configure for the selected ADC regular channel to be converted. 
    */
  sConfig.Channel = ADC_CHANNEL_1;
  if (HAL_ADC_ConfigChannel(&hadc, &sConfig) != HAL_OK)
  {
    //Error_Handler();
  }

}

/* I2C1 init function */
void MX_I2C1_Init(void)
{

  hi2c1.Instance = I2C1;
  hi2c1.Init.Timing = 0x20303E5D;
  hi2c1.Init.OwnAddress1 = 112;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_ENABLE;
  HAL_I2C_Init(&hi2c1);

    /**Configure Analogue filter 
    */
  HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE);

}

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{
//	GPIO_InitTypeDef gpioinit;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
	
//	gpioinit.Pin = GPIO_PIN_0
	

}


#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{

}

#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
