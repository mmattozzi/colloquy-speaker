/*

  rijndael.h

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

#ifndef RIJNDAEL_H
#define RIJNDAEL_H

/* 
 * SILC Crypto API for Rijndael
 */

SILC_CIPHER_API_SET_KEY(aes);
SILC_CIPHER_API_SET_KEY_WITH_STRING(aes);
SILC_CIPHER_API_CONTEXT_LEN(aes);
SILC_CIPHER_API_ENCRYPT_CBC(aes);
SILC_CIPHER_API_DECRYPT_CBC(aes);

#endif
