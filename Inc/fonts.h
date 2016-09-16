/**
  ******************************************************************************
  * @file    fonts.h
  * @author  e.pavlin.si
  * @brief   Fonts header file
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

							    

#ifndef __FONTS_H__
#define __FONTS_H__

/**  ------->>>> MODIFY HERE <<<<--------------------------------*/
/* Font selection -----------------------------------------------*/
/* select desired fonts. (Simply comment out those not needed)   */
/* --------------------------------------------------------------*/
#define EN_FIVE_DOT
//#define EN_SIX_DOT
//#define EN_SEVEN_DOT
//#define EN_NINE_DOT
/* --------------------------------------------------------------*/
/* --------------------------------------------------------------*/
/* --------------------------------------------------------------*/


/* define number labels for the font selections */
typedef enum
{
#ifdef EN_FIVE_DOT
	FONT_FIVE_DOT,
#endif

#ifdef EN_SIX_DOT
	FONT_SIX_DOT,
#endif

#ifdef EN_SEVEN_DOT
	FONT_SEVEN_DOT,
#endif


	FONT_COUNT
} FONT_BASE;

struct FONT_DEF 
{
   unsigned char store_width;            	/* glyph storage width in bytes */
   unsigned char glyph_height;  		 			/* glyph height for storage */
   const unsigned char *glyph_table;      /* font table start address in memory */
   unsigned char fixed_width;            	/* fixed width of glyphs. If zero */
																					/* then use the width table. */
   const unsigned char *width_table; 	 		/* variable width table start adress */
   unsigned char glyph_beg;			 	 				/* start ascii offset in table */
   unsigned char glyph_end;				 				/* end ascii offset in table */
   unsigned char glyph_def;				 				/*  for undefined glyph  */
};

/* font definition tables for the fonts */
extern const struct FONT_DEF fonts[FONT_COUNT];

/* glyph bitmap and width tables for the fonts */ 
#ifdef EN_FIVE_DOT
  extern const unsigned char five_dot_glyph_table[];
  extern const unsigned char five_dot_width_table[];
#endif

#ifdef EN_SIX_DOT
  extern const unsigned char six_dot_glyph_table[];
  extern const unsigned char six_dot_width_table[];
#endif

#ifdef EN_SEVEN_DOT
#define DEG_CHAR ('~'+1)
  extern const unsigned char seven_dot_glyph_table[];
  extern const unsigned char seven_dot_width_table[];
#endif

#ifdef EN_NINE_DOT
  extern const unsigned char  nine_dot_glyph_table[];
#endif


#endif
