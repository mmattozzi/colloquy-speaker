/*

  sha1.h

  Author: Pekka Riikonen <priikone@poseidon.pspt.fi>

  Copyright (C) 1997 - 2000 Pekka Riikonen

  The contents of this file are subject to one of the Licenses specified 
  in the COPYING file;  You may not use this file except in compliance 
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
  
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  information.

*/

#ifndef SHA1_H
#define SHA1_H

/* 
 * SILC Hash API for SHA1
 */

SILC_HASH_API_INIT(sha1);
SILC_HASH_API_UPDATE(sha1);
SILC_HASH_API_FINAL(sha1);
SILC_HASH_API_TRANSFORM(sha1);
SILC_HASH_API_CONTEXT_LEN(sha1);

#endif
