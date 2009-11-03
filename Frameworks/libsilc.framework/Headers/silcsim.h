/*

  silcsim.h

  Author: Pekka Riikonen <priikone@silcnet.org>

  Copyright (C) 2000 Pekka Riikonen

  The contents of this file are subject to one of the Licenses specified 
  in the COPYING file;  You may not use this file except in compliance 
  with the License.
  
  The software distributed under the License is distributed on an "AS IS"
  basis, in the hope that it will be useful, but WITHOUT WARRANTY OF ANY
  KIND, either expressed or implied.  See the COPYING file for more
  information.

*/

#ifndef SILCSIM_H
#define SILCSIM_H

typedef struct SilcSimStruct *SilcSim;

/* All SIM types. New types maybe freely added. */
typedef enum {
  SILC_SIM_NONE = 0,
  SILC_SIM_CIPHER,
  SILC_SIM_HASH,
} SilcSimType;

/* Flags used to retrieve the symbols from the library file. Default
   is that the symbols are resolved as they are loaded. However, if
   system doesn't support this we have no other choice but to do it lazy
   thus experience some overhead when using the symbol first time. */
#if defined(RTLD_NOW)
#define SILC_SIM_FLAGS RTLD_NOW
#elif defined(RTLD_LAZY)
#define SILC_SIM_FLAGS RTLD_LAZY
#else
#define SILC_SIM_FLAGS 0
#endif

/* Prototypes */
SilcSim silc_sim_alloc(SilcSimType type, const char *libname, 
		       SilcUInt32 flags);
void silc_sim_free(SilcSim sim);
int silc_sim_load(SilcSim sim);
int silc_sim_close(SilcSim sim);
const char *silc_sim_error(SilcSim sim);
void *silc_sim_getsym(SilcSim sim, const char *symbol);

#endif
