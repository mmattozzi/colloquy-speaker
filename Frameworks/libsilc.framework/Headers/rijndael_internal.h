/*

  rijndael_internal.h

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

#ifndef RIJNDAEL_INTERNAL_H
#define RIJNDAEL_INTERNAL_H

#include "ciphers_def.h"

/* Cipher's context */
typedef struct {
  u4byte e_key[60];
  u4byte d_key[60];
  u4byte k_len;
} RijndaelContext;

/* Prototypes */
u4byte *rijndael_set_key(RijndaelContext *ctx,
			 const u4byte in_key[], const u4byte key_len);
void rijndael_encrypt(RijndaelContext *ctx,
		      const u4byte in_blk[4], u4byte out_blk[4]);
void rijndael_decrypt(RijndaelContext *ctx,
		      const u4byte in_blk[4], u4byte out_blk[4]);

#endif
