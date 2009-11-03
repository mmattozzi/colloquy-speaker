/*

  md5.h

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

#ifndef MD5_H
#define MD5_H

/* 
 * SILC Hash API for MD5
 */

SILC_HASH_API_INIT(md5);
SILC_HASH_API_UPDATE(md5);
SILC_HASH_API_FINAL(md5);
SILC_HASH_API_TRANSFORM(md5);
SILC_HASH_API_CONTEXT_LEN(md5);

#endif
