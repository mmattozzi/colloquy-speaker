/*

  rc5_internal.h

  Author: Pekka Riikonen <priikone@silcnet.org>

  Copyright (C) 1997 - 2000 Pekka Riikonen

  The contents of this file are subject to one of the Licenses specified 
  in the COPYING file;  You may not use this file except in compliance 
  with the License.
  
  The software distributed under the License is distributed on an "AS IS"
  basis, in the hope that it will be useful, but WITHOUT WARRANTY OF ANY
  KIND, either expressed or implied.  See the COPYING file for more
  information.

*/

#ifndef RC5_INTERNAL_H
#define RC5_INTERNAL_H

#include "ciphers_def.h"

/* RC5 definitions */
#define w	32	/* word size, in bits */
#define r	16	/* rounds */
#define b	16	/* minimum key size in bytes */
#define c	8	/* same for 128,  192 and 256 bits key */
#define t	34	/* size of table S, t = 2 * (r + 1) */

/* Cipher's context */
typedef struct {
  u32 out_key[t];
} RC5Context;

/* Prototypes */
int rc5_set_key(RC5Context *ctx, const SilcUInt32 in_key[], int key_len);
int rc5_encrypt(RC5Context *ctx, u32 *in, u32 *out);
int rc5_decrypt(RC5Context *ctx, u32 *in, u32 *out);

#endif
