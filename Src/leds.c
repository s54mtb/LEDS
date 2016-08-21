/**
  ******************************************************************************
  * @file    leds.c
  * @author  e.pavlin.si
  * @version V0.0.0
  * @date    2016
  * @brief   LEDs driver.
  *          ...........
  *          ....
  */
#include "stm32f0xx.h"                  // Device header
#include "leds.h"												// LED driver 


static uint16_t LED_frame[8];

const uint8_t Led_addr_decoder[8] = LED_ADR_DECODE; 

void Init_LED(void)
{
	GPIO_InitTypeDef gpioinit;
	
  __HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
	
	
	  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_0|GPIO_PIN_1, GPIO_PIN_RESET);
	
	gpioinit.Mode = GPIO_MODE_OUTPUT_PP;
	gpioinit.Pull = GPIO_NOPULL;
	gpioinit.Speed = GPIO_SPEED_FREQ_MEDIUM;
	
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
	
	
}


void LED_set_adr(uint8_t adr)
{
	uint8_t hw_addr = Led_addr_decoder[adr];

	HAL_GPIO_WritePin(LED_A0_PORT, LED_A0_PIN, (GPIO_PinState)(hw_addr & 0x01) );
	hw_addr >>= 1;
	HAL_GPIO_WritePin(LED_A1_PORT, LED_A1_PIN, (GPIO_PinState)(hw_addr & 0x01) );
	hw_addr >>= 1;
	HAL_GPIO_WritePin(LED_A2_PORT, LED_A2_PIN, (GPIO_PinState)(hw_addr & 0x01) );
}


void LED_SetBuffer(uint8_t adr, uint16_t value)
{
	if (adr<8)
	  LED_frame[adr] = value;
}

uint16_t LED_GetBuffer(uint8_t adr)
{
	if (adr<8)
	  return LED_frame[adr];
	else
		return 0;
}

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


void LED_refreshV(uint8_t adr)
{
	if (adr<8)
	{
		LED_set_adr(adr);
		LED_SetVertical(LED_GetBuffer(adr));
	}
}




