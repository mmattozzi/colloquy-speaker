/*

  silcmutex.h

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

/****h* silcutil/SILC Mutex Interface
 *
 * DESCRIPTION
 *
 * Interface for the SILC Mutex locking implementation. This is platform
 * independent mutual exclusion interface for applications that need
 * concurrency control.
 *
 ***/

#ifndef SILCMUTEX_H
#define SILCMUTEX_H

/****s* silcutil/SilcMutexAPI/SilcMutex
 *
 * NAME
 *
 *    typedef struct SilcMutexStruct *SilcMutex;
 *
 * DESCRIPTION
 *
 *    This context is the actual SILC Mutex and is allocated
 *    by silc_mutex_alloc and given as argument to all silc_mutex_*
 *    functions.  It is freed by the silc_mutex_free function.
 *
 ***/
typedef struct SilcMutexStruct *SilcMutex;

/****d* silcutil/SilcMutexAPI/SILC_MUTEX_DEFINE
 *
 * NAME
 *
 *    #define SILC_MUTEX_DEFINE(name) ...
 *
 * DESCRIPTION
 *
 *    This macro is used to define new mutex.  Use this macro in an
 *    environment that can be compiled with or without the SILC Mutex
 *    API. This is equivalent to defining SilcMutex `name'; directly.
 *
 * SOURCE
 */
#define SILC_MUTEX_DEFINE(name) SilcMutex name
/***/

/****f* silcutil/SilcMutexAPI/silc_mutex_alloc
 *
 * SYNOPSIS
 *
 *    bool silc_mutex_alloc(SilcMutex *mutex);
 *
 * DESCRIPTION
 *
 *    Allocates SILC Mutex object.  The mutex object must be allocated
 *    before it can be used.  It is freed by the silc_mutex_free function.
 *    This returns TRUE and allocated mutex in to the `mutex' and FALSE
 *    on error.
 *
 ***/
bool silc_mutex_alloc(SilcMutex *mutex);

/****f* silcutil/SilcMutexAPI/silc_mutex_recursive_alloc
 *
 * SYNOPSIS
 *
 *    bool silc_mutex_recursive_alloc(SilcMutex *mutex);
 *
 * DESCRIPTION
 *
 *    Allocates SILC Mutex object.  The mutex object must be allocated
 *    before it can be used.  It is freed by the silc_mutex_free function.
 *    This returns TRUE and allocated mutex in to the `mutex' and FALSE
 *    on error. This allocates a recursive mutex.
 *
 ***/
bool silc_mutex_recursive_alloc(SilcMutex *mutex);

/****f* silcutil/SilcMutexAPI/silc_mutex_free
 *
 * SYNOPSIS
 *
 *    void silc_mutex_free(SilcMutex mutex);
 *
 * DESCRIPTION
 *
 *    Free SILC Mutex object and frees all allocated memory.  If `mutex'
 *    is NULL this function has no effect.
 *
 ***/
void silc_mutex_free(SilcMutex mutex);

/****f* silcutil/SilcMutexAPI/silc_mutex_lock
 *
 * SYNOPSIS
 *
 *    void silc_mutex_lock(SilcMutex mutex);
 *
 * DESCRIPTION
 *
 *    Locks the mutex. If the mutex is locked by another thread the
 *    current thread will block until the other thread has issued
 *    silc_mutex_unlock for the mutex.  If `mutex' is NULL this function
 *    has no effect.
 *
 * NOTES
 *
 *    The caller must not call silc_mutex_lock for mutex that has been
 *    already locked in the current thread.  In this case deadlock will
 *    occur.
 *
 ***/
void silc_mutex_lock(SilcMutex mutex);

/****f* silcutil/SilcMutexAPI/silc_mutex_unlock
 *
 * SYNOPSIS
 *
 *    void silc_mutex_unlock(SilcMutex mutex);
 *
 * DESCRIPTION
 *
 *    Unlocks the mutex and thus releases it for another thread that
 *    may be waiting for the lock.  If `mutex' is NULL this function
 *    has no effect.
 *
 * NOTES
 *
 *    The caller must not call the silc_mutex_unlock for an unlocked
 *    mutex or mutex not locked by the current thread.  It is fatal
 *    error if this occurs.
 *
 ***/
void silc_mutex_unlock(SilcMutex mutex);

#endif
