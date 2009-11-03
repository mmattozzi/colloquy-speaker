/*

  rc5.h

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

#ifndef RC5_H
#define RC5_H

/* 
 * SILC Crypto API for RC5
 */

SILC_CIPHER_API_SET_KEY(rc5);
SILC_CIPHER_API_SET_KEY_WITH_STRING(rc5);
SILC_CIPHER_API_CONTEXT_LEN(rc5);
SILC_CIPHER_API_ENCRYPT_CBC(rc5);
SILC_CIPHER_API_DECRYPT_CBC(rc5);

#endif
