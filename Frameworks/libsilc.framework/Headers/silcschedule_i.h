/*

  silcschedule_i.h.

  Author: Pekka Riikonen <priikone@silcnet.org>

  Copyright (C) 2001 - 2005 Pekka Riikonen

  The contents of this file are subject to one of the Licenses specified 
  in the COPYING file;  You may not use this file except in compliance 
  with the License.
  
  The software distributed under the License is distributed on an "AS IS"
  basis, in the hope that it will be useful, but WITHOUT WARRANTY OF ANY
  KIND, either expressed or implied.  See the COPYING file for more
  information.

*/

#ifndef SILCSCHEDULE_I_H
#define SILCSCHEDULE_I_H

#include "silcincludes.h"

/* Schedule FD structure. Includes the file descriptors that the scheduler
   will listen. This is given as argument to the silc_select function. */
typedef struct {
  SilcUInt32 fd;       		/* The file descriptor (or handle on WIN32) */
  SilcUInt16 events;		/* Mask of task events, if events is 0 then
				   the fd must be omitted. */
  SilcUInt16 revents;		/* Returned events mask */
} *SilcScheduleFd;

#endif
