/*

  none.h

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
/*
 * $Id: none.h,v 1.1.1.1.4.1 2005/04/30 15:31:26 priikone Exp $
 * $Log: none.h,v $
 * Revision 1.1.1.1.4.1  2005/04/30 15:31:26  priikone
 * 	Header changes.
 *
 * Revision 1.1.1.1  2000/06/27 11:36:54  priikone
 * 	Importet from internal CVS/Added Log headers.
 *
 *
 */

#ifndef NONE_H
#define NONE_H

/* 
 * SILC Crypto API for None cipher (ie. no cipher) :)
 */

SILC_CIPHER_API_SET_KEY(none);
SILC_CIPHER_API_SET_KEY_WITH_STRING(none);
SILC_CIPHER_API_CONTEXT_LEN(none);
SILC_CIPHER_API_ENCRYPT_CBC(none);
SILC_CIPHER_API_DECRYPT_CBC(none);

#endif
