/*

  stacktrace.h 

  Author: Pekka Riikonen <priikone@silcnet.org>

  Copyright (C) 2002 Pekka Riikonen

  The contents of this file are subject to one of the Licenses specified 
  in the COPYING file;  You may not use this file except in compliance 
  with the License.

  The software distributed under the License is distributed on an "AS IS"
  basis, in the hope that it will be useful, but WITHOUT WARRANTY OF ANY
  KIND, either expressed or implied.  See the COPYING file for more
  information.

*/

#ifndef STACKTRACE_H
#define STACKTRACE_H

#ifndef SILCMEMORY_H
#error "Do not include internal header file directly"
#endif

#if defined(__GNUC__) && defined(__i386__)

#undef strdup
#define silc_malloc(s)      silc_st_malloc((s), __FILE__, __LINE__)
#define silc_calloc(i, s)   silc_st_calloc((i), (s), __FILE__, __LINE__)
#define silc_realloc(p, s)  silc_st_realloc((p), (s), __FILE__, __LINE__)
#define silc_free(p)        silc_st_free((p), __FILE__, __LINE__)
#define silc_memdup(p, s)   silc_st_memdup((p), (s), __FILE__, __LINE__)
#define strdup(s)           silc_st_strdup((s), __FILE__, __LINE__)

void *silc_st_malloc(size_t size, const char *file, int line);
void *silc_st_calloc(size_t items, size_t size, const char *file, int line);
void *silc_st_realloc(void *ptr, size_t size, const char *file, int line);
void silc_st_free(void *ptr, const char *file, int line);
void *silc_st_memdup(const void *ptr, size_t size, const char *file, int line);
void *silc_st_strdup(const char *string, const char *file, int line);
void silc_st_dump(void);

#else
#error "memory allocation stack trace not supported on this platform"
#endif /* __GNUC__ && __i386__ */

#endif /* STACKTRACE_H */
