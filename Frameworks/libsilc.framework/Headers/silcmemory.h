/*

  silcmemory.h 

  Author: Pekka Riikonen <priikone@silcnet.org>

  Copyright (C) 1999 - 2002 Pekka Riikonen

  The contents of this file are subject to one of the Licenses specified 
  in the COPYING file;  You may not use this file except in compliance 
  with the License.

  The software distributed under the License is distributed on an "AS IS"
  basis, in the hope that it will be useful, but WITHOUT WARRANTY OF ANY
  KIND, either expressed or implied.  See the COPYING file for more
  information.

*/

/****h* silcutil/SILC Memory Interface
 *
 * DESCRIPTION
 *
 * Basic utility functions for allocating memory. All SILC routines, and
 * applications use these functions when they need to allocate, manipulate
 * and free memory.
 *
 * Currently all allocation routines assert() that the memory was allocated
 * successfully. Hence, if memory allocation fails it is fatal error.
 *
 ***/

#ifndef SILCMEMORY_H
#define SILCMEMORY_H

/* Prototypes */

#ifndef SILC_STACKTRACE

/****f* silcutil/SilcMemoryAPI/silc_malloc
 *
 * SYNOPSIS
 *
 *    void *silc_malloc(size_t size);
 *
 * DESCRIPTION
 *
 *    Allocates memory of `size' bytes and returns pointer to the allocated
 *    memory area.  Free the memory by calling silc_free.
 *
 ***/
void *silc_malloc(size_t size);

/****f* silcutil/SilcMemoryAPI/silc_calloc
 *
 * SYNOPSIS
 *
 *    void *silc_calloc(size_t items, size_t size);
 *
 * DESCRIPTION
 *
 *    Allocates memory of for an array of `items' elements of `size' bytes
 *    and returns pointer to the allocated memory area.  The memory area is
 *    also zeroed.  Free the memory by calling silc_free.
 *
 ***/
void *silc_calloc(size_t items, size_t size);

/****f* silcutil/SilcMemoryAPI/silc_realloc
 *
 * SYNOPSIS
 *
 *    void *silc_realloc(void *ptr, size_t size);
 *
 * DESCRIPTION
 *
 *    Change the size of the memory block indicated by `ptr' to the new
 *    size of `size' bytes.  The contents of `ptr' will not be changed.
 *    If `ptr' is NULL the call is equivalent to silc_malloc.  If the
 *    `size' is zero (0) the call is equivalent to silc_free.  Free the
 *    memory by calling silc_free.
 *
 * NOTES
 *
 *    The pointer returned to the reallocated memory area might not be
 *    same as `ptr'.
 *
 ***/
void *silc_realloc(void *ptr, size_t size);

/****f* silcutil/SilcMemoryAPI/silc_free
 *
 * SYNOPSIS
 *
 *    void silc_free(void *ptr);
 *
 * DESCRIPTION
 *
 *    Frees the memory area indicated by the `ptr'. If `ptr' is NULL no
 *    operation is performed.
 *
 ***/
void silc_free(void *ptr);

/****f* silcutil/SilcMemoryAPI/silc_memdup
 *
 * SYNOPSIS
 *
 *    void *silc_memdup(const void *ptr, size_t size);
 *
 * DESCRIPTION
 *
 *    Duplicates the memory area indicated by `ptr' which is of size
 *    of `size' bytes. Returns pointer to the duplicated memory area.
 *    This NULL terminates the dupped memory area by allocating `size' + 1
 *    bytes, so this function can be used to duplicate strings that does
 *    not have NULL termination.
 *
 ***/
void *silc_memdup(const void *ptr, size_t size);

#else

#include "stacktrace.h"
#endif /* SILC_STACKTRACE */

#endif /* SILCMEMORY_H */
