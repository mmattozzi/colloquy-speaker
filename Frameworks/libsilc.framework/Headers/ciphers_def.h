/*

  ciphers_def.h

  Author: Pekka Riikonen <priikone@silcnet.org>

  Copyright (C) 1999 - 2000 Pekka Riikonen

  The contents of this file are subject to one of the Licenses specified 
  in the COPYING file;  You may not use this file except in compliance 
  with the License.
  
  The software distributed under the License is distributed on an "AS IS"
  basis, in the hope that it will be useful, but WITHOUT WARRANTY OF ANY
  KIND, either expressed or implied.  See the COPYING file for more
  information.

*/

#ifndef CIPHERS_DEF_H
#define CIPHERS_DEF_H

/* General definitions for algorithms */
typedef unsigned char u1byte;
typedef SilcUInt32 u4byte;
typedef SilcUInt32 u32;

#define rotr(x, nr) (((x) >> ((int)(nr))) | ((x) << (32 - (int)(nr))))
#define rotl(x, nr) (((x) << ((int)(nr))) | ((x) >> (32 - (int)(nr))))
#define byte(x, nr) ((x) >> (nr * 8) & 255)

/* Byte key to words */
#define SILC_GET_WORD_KEY(s, d, len)		\
do {						\
  int _i;					\
  for (_i = 0; _i < (len / 8) / 4; _i++)	\
    SILC_GET32_LSB(d[_i], s + (_i * 4));	\
} while(0);

/* CBC mode macros. */

#define SILC_CBC_GET_IV(d, s) 			\
do {						\
  SILC_GET32_LSB(d[0], &s[0]);			\
  SILC_GET32_LSB(d[1], &s[4]);			\
  SILC_GET32_LSB(d[2], &s[8]);			\
  SILC_GET32_LSB(d[3], &s[12]);			\
} while(0);

#define SILC_CBC_PUT_IV(s, d)			\
do {						\
  SILC_PUT32_LSB(s[0], &d[0]);			\
  SILC_PUT32_LSB(s[1], &d[4]);			\
  SILC_PUT32_LSB(s[2], &d[8]);			\
  SILC_PUT32_LSB(s[3], &d[12]);			\
} while(0);

#define SILC_CBC_ENC_PRE(d, s)			\
do {						\
  SILC_GET32_X_LSB(d[0], &s[0]);		\
  SILC_GET32_X_LSB(d[1], &s[4]);		\
  SILC_GET32_X_LSB(d[2], &s[8]);		\
  SILC_GET32_X_LSB(d[3], &s[12]);		\
} while(0);

#define SILC_CBC_ENC_POST(s, d, t)		\
do {						\
  SILC_PUT32_LSB(s[0], &d[0]);			\
  SILC_PUT32_LSB(s[1], &d[4]);			\
  SILC_PUT32_LSB(s[2], &d[8]);			\
  SILC_PUT32_LSB(s[3], &d[12]);			\
						\
  d += 16;					\
  t += 16;					\
} while(0);

#define SILC_CBC_DEC_PRE(d, s)			\
do {						\
  SILC_GET32_LSB(d[0], &s[0]);			\
  SILC_GET32_LSB(d[1], &s[4]);			\
  SILC_GET32_LSB(d[2], &s[8]);			\
  SILC_GET32_LSB(d[3], &s[12]);			\
} while(0);

#define SILC_CBC_DEC_POST(s, d, p, t, siv)	\
do {						\
  s[0] ^= siv[0];				\
  s[1] ^= siv[1];				\
  s[2] ^= siv[2];				\
  s[3] ^= siv[3];				\
						\
  SILC_PUT32_LSB(s[0], &d[0]);			\
  SILC_PUT32_LSB(s[1], &d[4]);			\
  SILC_PUT32_LSB(s[2], &d[8]);			\
  SILC_PUT32_LSB(s[3], &d[12]);			\
						\
  siv[0] = t[0];				\
  siv[1] = t[1];				\
  siv[2] = t[2];				\
  siv[3] = t[3];				\
						\
  d += 16;					\
  p += 16;					\
} while(0);

#endif
