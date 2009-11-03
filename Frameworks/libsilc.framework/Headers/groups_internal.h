/*

  groups_internal.h

  Author: Pekka Riikonen <priikone@silcnet.org>

  Copyright (C) 2000 - 2001 Pekka Riikonen

  The contents of this file are subject to one of the Licenses specified 
  in the COPYING file;  You may not use this file except in compliance 
  with the License.
  
  The software distributed under the License is distributed on an "AS IS"
  basis, in the hope that it will be useful, but WITHOUT WARRANTY OF ANY
  KIND, either expressed or implied.  See the COPYING file for more
  information.

*/

#ifndef GROUPS_INTERNAL_H
#define GROUPS_INTERNAL_H

/* Diffie Hellman Group. Defines the group name, prime, largest prime 
   factor (group order) and generator. */
struct SilcSKEDiffieHellmanGroupDefStruct {
  int number;
  char *name;
  char *group;
  char *group_order;
  char *generator;
};

struct SilcSKEDiffieHellmanGroupStruct {
  int number;
  char *name;
  SilcMPInt group;
  SilcMPInt group_order;
  SilcMPInt generator;
};

/* List of defined groups. */
extern const struct SilcSKEDiffieHellmanGroupDefStruct silc_ske_groups[];

#endif
