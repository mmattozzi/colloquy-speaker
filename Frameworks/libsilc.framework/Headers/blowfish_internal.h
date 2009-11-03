/*

  blowfish_internal.h

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

#ifndef BLOWFISH_INTERNAL_H
#define BLOWFISH_INTERNAL_H

#include "ciphers_def.h"

/* Cipher's context */
typedef struct blow_key
{
    u32 P[18];
    u32 S[1024];
} BlowfishContext;

/* Prototypes */
int blowfish_encrypt(BlowfishContext *ctx, 
		     u32 *in_blk, u32 *out_blk, int size);
int blowfish_decrypt(BlowfishContext *ctx, 
		     u32 *in_blk, u32 *out_blk, int size);
int blowfish_set_key(BlowfishContext *ctx,
		     unsigned char *key, int keybytes);

#endif
