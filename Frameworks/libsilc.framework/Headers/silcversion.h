/*

  silcversion.h 

  Author: Pekka Riikonen <priikone@silcnet.org>

  Copyright (C) 1997 - 2005 Pekka Riikonen

  The contents of this file are subject to one of the Licenses specified 
  in the COPYING file;  You may not use this file except in compliance 
  with the License.

  The software distributed under the License is distributed on an "AS IS"
  basis, in the hope that it will be useful, but WITHOUT WARRANTY OF ANY
  KIND, either expressed or implied.  See the COPYING file for more
  information.

*/

#ifndef SILCVERSION_H
#define SILCVERSION_H

#ifdef __cplusplus
extern "C" {
#endif

#define SILC_VERSION_STRING "1.0"
#define SILC_DIST_VERSION_STRING "1.0"
#define SILC_PROTOCOL_VERSION_STRING "SILC-1.2-1.0 silc-toolkit"
#define SILC_NAME "SILC Toolkit"

/* SILC Protocol version number */
#define SILC_PROTOCOL_VERSION_CURRENT 12

/* SILC version string */
#define silc_version SILC_VERSION_STRING
#define silc_dist_version SILC_DIST_VERSION_STRING
#define silc_version_string SILC_PROTOCOL_VERSION_STRING
#define silc_name SILC_NAME
#define silc_fullname "Secure Internet Live Conferencing"

#ifdef __cplusplus
}
#endif

#endif /* SILCVERSION_H */
