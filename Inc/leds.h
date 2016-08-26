
/* Define to prevent recursive inclusion */
#ifndef __LEDS_H__
#define __LEDS_H__

/* LED pin definitions */
#ifdef LEDS_L
  #include "leds_l.h"										// Left board
#endif

#ifdef LEDS_R
  #include "leds_r.h"										// Right board
#endif

void Init_LED(void);
void LED_SetBuffer(uint8_t adr, uint16_t value);
uint16_t LED_GetBuffer(uint8_t adr);
void LED_refreshV(uint8_t adr);
void LED_SetPixel(uint8_t x, uint8_t y, uint8_t pix);
void LED_setAll(void);
void LED_clrAll(void);

#endif
