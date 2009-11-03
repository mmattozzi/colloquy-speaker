/*

  twofish_internal.h

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

#ifndef TWOFISH_INTERNAL_H
#define TWOFISH_INTERNAL_H

#include "ciphers_def.h"

/* Cipher's context */
typedef struct {
  u4byte k_len;
  u4byte l_key[40];
  u4byte s_key[4];
} TwofishContext;

/* Prototypes */
u4byte *twofish_set_key(TwofishContext *ctx,
			const u4byte in_key[], const u4byte key_len);
void twofish_encrypt(TwofishContext *ctx,
		     const u4byte in_blk[4], u4byte out_blk[]);
void twofish_decrypt(TwofishContext *ctx,
		     const u4byte in_blk[4], u4byte out_blk[4]);

#endif
