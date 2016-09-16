/**
  ******************************************************************************
  * @file    graphics.c
  * @author  e.pavlin.si
  * @brief   Graphics routines
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

#include "stm32f0xx.h"                  // Device header
			    
#include "graphics.h"
#include "fonts.h"
#include "leds.h" 


void graphics_Glyph(unsigned char left, unsigned char top,
			   unsigned char width, unsigned char height,
			   const unsigned char *glyph, unsigned char store_width)
{
	unsigned char x,y,b,glyph_idx, bitmask;
	const unsigned char *glyph_scan = glyph;

	for (x=0; x<width; x++)
	{
		for (y=0; y<height; y++)
		{
			glyph_idx = (x / width) + y*store_width;
			b = glyph_scan[glyph_idx];
			bitmask = 1<<(7-(x % 8));
			if (b & bitmask)
				LED_SetPixel(left+width-x,top+y,1);
			else 
			  LED_SetPixel(left+width-x,top+y,0);
		}
	}
}

void graphics_text(unsigned char left, unsigned char top, unsigned char font, const char *str)
{
	unsigned char x = left;
	unsigned char glyph;
 	unsigned char width;
	unsigned char height;
	unsigned char store_width;
	const unsigned char *glyph_ptr;
	
  while(*str != 0x00)
  {
		glyph = (unsigned char)*str;

		/* check to make sure the symbol is a legal one */
		/* if not then just replace it with the default character */
		if((glyph < fonts[font].glyph_beg) || (glyph > fonts[font].glyph_end))
		{
			glyph = fonts[font].glyph_def;
		}
		

		/* make zero based index into the font data arrays */
		glyph -= fonts[font].glyph_beg;
		width = fonts[font].fixed_width;	/* check if it is a fixed width */
		if(width == 0)
		{
			width=fonts[font].width_table[glyph];	/* get the variable width instead */
		}

		height = fonts[font].glyph_height;
		store_width = fonts[font].store_width;

		glyph_ptr = fonts[font].glyph_table + ((unsigned int)glyph * (unsigned int)store_width * (unsigned int)height);

//		/* range check / limit things here */
//		if(x > LED_COLUMNS-1)
//		{
//			x = LED_COLUMNS-1;
//		}
//		if((x + width) > LED_COLUMNS)
//		{
//			width = LED_COLUMNS - x + 1;
//		}
//		if(top > LED_ROWS-1)
//		{
//			top = LED_ROWS-1;
//		}
//		if((top + height) > LED_ROWS)
//		{
//			height = LED_ROWS - top + 1;
//		}

		graphics_Glyph(x,top,width,height,glyph_ptr,store_width);  /* plug symbol into buffer */
		

		str++;								/* point to next character in string */
	}
	
}

