
/* Define to prevent recursive inclusion */
#ifndef __LEDS_H__
#define __LEDS_H__


#ifdef LEDS_L
  #include "leds_l.h"										// Left board
#endif

#ifdef LEDS_R
  #include "leds_r.h"										// Right board
#endif


#endif
