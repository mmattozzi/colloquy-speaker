/*

  silclog_i.h

  Author: Pekka Riikonen <priikone@silcnet.org>

  Copyright (C) 2005 Pekka Riikonen

  The contents of this file are subject to one of the Licenses specified 
  in the COPYING file;  You may not use this file except in compliance 
  with the License.

  The software distributed under the License is distributed on an "AS IS"
  basis, in the hope that it will be useful, but WITHOUT WARRANTY OF ANY
  KIND, either expressed or implied.  See the COPYING file for more
  information.

*/

#ifndef SILCLOG_I_H
#define SILCLOG_I_H

#ifndef SILCLOG_H
#error "Do not include this header directly"
#endif

#if defined(WIN32)
#ifndef __FUNCTION__
#define __FUNCTION__ ""
#endif
#endif

void silc_log_output(SilcLogType type, char *string);
void silc_log_output_debug(char *file, const char *function,
			   int line, char *string);
void silc_log_output_hexdump(char *file, const char *function,
			     int line, void *data_in,
			     SilcUInt32 len, char *string);

#endif /* SILCLOG_I_H */
