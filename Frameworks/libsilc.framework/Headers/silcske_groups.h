/*

  silcske_groups.h 

  Author: Pekka Riikonen <priikone@silcnet.org>

  Copyright (C) 2000 - 2002 Pekka Riikonen

  The contents of this file are subject to one of the Licenses specified 
  in the COPYING file;  You may not use this file except in compliance 
  with the License.

  The software distributed under the License is distributed on an "AS IS"
  basis, in the hope that it will be useful, but WITHOUT WARRANTY OF ANY
  KIND, either expressed or implied.  See the COPYING file for more
  information.

*/

/****h* silcske/SKE Diffie Hellman Groups
 *
 * DESCRIPTION
 *
 * This interface defines the Diffie Hellman group management and utility
 * functions for the SKE.  They can be used find DH groups by group number,
 * and group name.  These routines are used during the SKE session by the
 * SKE library. However, application may use these as well if needed.
 *
 ***/

#ifndef SILCSKE_GROUPS_H
#define SILCSKE_GROUPS_H

#include "silcske_status.h"

/****s* silcske/SilcSKEGroups/SilcSKEDiffieHellmanGroup
 *
 * NAME
 * 
 *    typedef struct SilcSKEDiffieHellmanGroupStruct 
 *                     *SilcSKEDiffieHellmanGroup;
 *
 * DESCRIPTION
 *
 *    This context represents one Diffie Hellman group, and is returned
 *    by the utility functions for finding correct groups.  The context
 *    is freed by calling the silc_ske_group_free function.
 *
 ***/
typedef struct SilcSKEDiffieHellmanGroupStruct *SilcSKEDiffieHellmanGroup;

/* Prototypes */

/****f* silcske/SilcSKEGroups/silc_ske_group_get_by_number
 *
 * SYNOPSIS
 *
 *    SilcSKEStatus 
 *    silc_ske_group_get_by_number(int number,
 *                                 SilcSKEDiffieHellmanGroup *ret);
 *
 * DESCRIPTION
 *
 *    Returns the Diffie Hellman group into the `ret' pointer by
 *    group number indicated by the `number'.  Returns error status
 *    if the group was not found.
 *
 ***/
SilcSKEStatus silc_ske_group_get_by_number(int number,
					   SilcSKEDiffieHellmanGroup *ret);

/****f* silcske/SilcSKEGroups/silc_ske_group_get_by_name
 *
 * SYNOPSIS
 *
 *    SilcSKEStatus 
 *    silc_ske_get_group_by_name(const char *name,
 *                               SilcSKEDiffieHellmanGroup *ret);
 *
 * DESCRIPTION
 *
 *    Returns the Diffie Hellman group into the `ret' pointer by
 *    group name indicated by the `name'.  Returns error status
 *    if the group was not found.
 *
 ***/
SilcSKEStatus silc_ske_group_get_by_name(const char *name,
					 SilcSKEDiffieHellmanGroup *ret);

/****f* silcske/SilcSKEGroups/silc_ske_group_free
 *
 * SYNOPSIS
 *
 *    void silc_ske_group_free(SilcSKEDiffieHellmanGroup group);
 *
 * DESCRIPTION
 *
 *    Free the Diffie Hellman group indicated by the `group'.
 *
 ***/
void silc_ske_group_free(SilcSKEDiffieHellmanGroup group);

/****f* silcske/SilcSKEGroups/silc_ske_get_supported_groups
 *
 * SYNOPSIS
 *
 *    char *silc_ske_get_supported_groups();
 *
 * DESCRIPTION
 *
 *    Returns a comma separated list of support Diffie Hellman groups.
 *    This can be used to get the list of supported groups for SKE
 *    packets.
 *
 ***/
char *silc_ske_get_supported_groups();

/****f* silcske/SilcSKEGroups/silc_ske_group_get_number
 *
 * SYNOPSIS
 *
 *    int silc_ske_group_get_number(SilcSKEDiffieHellmanGroup group);
 *
 * DESCRIPTION
 *
 *    Return the group number of the group indicated by the `group'.
 *
 ***/
int silc_ske_group_get_number(SilcSKEDiffieHellmanGroup group);

/****f* silcske/SilcSKEGroups/silc_ske_group_get_name
 *
 * SYNOPSIS
 *
 *    const char *silc_ske_group_get_name(SilcSKEDiffieHellmanGroup group);
 *
 * DESCRIPTION
 *
 *    Return the group name of the group indicated by the `group'.
 *
 ***/
const char *silc_ske_group_get_name(SilcSKEDiffieHellmanGroup group);

#endif /* SILCSKE_GROUPS_H */
