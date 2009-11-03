/*

  rsa.h

  Author: Pekka Riikonen <priikone@silcnet.org>

  Copyright (C) 1997 - 2003 Pekka Riikonen

  The contents of this file are subject to one of the Licenses specified 
  in the COPYING file;  You may not use this file except in compliance 
  with the License.

  The software distributed under the License is distributed on an "AS IS"
  basis, in the hope that it will be useful, but WITHOUT WARRANTY OF ANY
  KIND, either expressed or implied.  See the COPYING file for more
  information.

*/

#ifndef RSA_H
#define RSA_H

/*
 * SILC PKCS API for RSA
 */

SILC_PKCS_API_INIT(rsa);
SILC_PKCS_API_CLEAR_KEYS(rsa);
SILC_PKCS_API_GET_PUBLIC_KEY(rsa);
SILC_PKCS_API_GET_PRIVATE_KEY(rsa);
SILC_PKCS_API_SET_PUBLIC_KEY(rsa);
SILC_PKCS_API_SET_PRIVATE_KEY(rsa);
SILC_PKCS_API_CONTEXT_LEN(rsa);
SILC_PKCS_API_ENCRYPT(rsa);
SILC_PKCS_API_DECRYPT(rsa);
SILC_PKCS_API_SIGN(rsa);
SILC_PKCS_API_VERIFY(rsa);

SILC_PKCS_API_ENCRYPT(pkcs1);
SILC_PKCS_API_DECRYPT(pkcs1);
SILC_PKCS_API_SIGN(pkcs1);
SILC_PKCS_API_VERIFY(pkcs1);


#endif
