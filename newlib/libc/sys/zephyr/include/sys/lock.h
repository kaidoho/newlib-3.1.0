/*
 * Copyright (c) 2020, Markus Bernd Moessner
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __SYS_LOCK_H__
#define __SYS_LOCK_H__

#include <sys/cdefs.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

struct _z_gthread_cond_t {
   unsigned int dummy[8];
};

struct _z_gthread_sem_t {
   unsigned int dummy[4];
};

struct _z_gthread_mutex_t {
    unsigned int dummy[5];
};


struct timespec;


/* Newlib lock structs */
typedef struct _z_gthread_sem_t    _LOCK_T;
typedef struct _z_gthread_mutex_t  _LOCK_RECURSIVE_T;

/* These functions are implemented in the source of Zephyr OS*/
/*
int _z_gthread_create (_z_gthread_t *threadid, void *(*__func) (void *),  void *__args);
int _z_gthread_join (_z_gthread_t , void **);
int _z_gthread_detach (_z_gthread_t );
int _z_gthread_equal (_z_gthread_t , _z_gthread_t );
_z_gthread_t _z_gthread_self (void);
int _z_gthread_yield (void);

int _z_gthread_once (_z_gthread_once_t *, void (*__func) (void));
int _z_gthread_key_create (_z_gthread_key_t *, void (*__dtor) (void *));
int _z_gthread_key_delete (_z_gthread_key_t );
void * _z_gthread_getspecific (_z_gthread_key_t );
int _z_gthread_setspecific (_z_gthread_key_t , const void *);
*/
int _z_gthread_yield (void);

//struct _z_gthread_sem_t _z_gthread_sem_initializer (void);
void _z_gthread_sem_initialize (struct _z_gthread_sem_t *);
int _z_gthread_sem_lock (struct _z_gthread_sem_t *);
int _z_gthread_sem_trylock (struct _z_gthread_sem_t *);
int _z_gthread_sem_timedlock (struct _z_gthread_sem_t *, const struct timespec *);
int _z_gthread_sem_unlock (struct _z_gthread_sem_t *);
int _z_gthread_sem_destroy (struct _z_gthread_sem_t *);

//struct _z_gthread_mutex_t _z_gthread_mutex_initializer(void);
void _z_gthread_mutex_initialize(struct _z_gthread_mutex_t *);
int _z_gthread_mutex_lock (struct _z_gthread_mutex_t *);
int _z_gthread_mutex_trylock (struct _z_gthread_mutex_t *);
int _z_gthread_mutex_timedlock (struct _z_gthread_mutex_t *, const struct timespec *);
int _z_gthread_mutex_unlock (struct _z_gthread_mutex_t *);
int _z_gthread_mutex_destroy (struct _z_gthread_mutex_t *);

//struct __z_gthread_cond_t _z_gthread_cond_initializer (void);
void _z_gthread_cond_initialize (struct _z_gthread_cond_t *);
int _z_gthread_cond_broadcast (struct _z_gthread_cond_t *);
int _z_gthread_cond_signal (struct _z_gthread_cond_t *);
int _z_gthread_cond_wait (struct _z_gthread_cond_t *, struct _z_gthread_sem_t *);
int _z_gthread_cond_timedwait (struct _z_gthread_cond_t *, struct _z_gthread_sem_t *, const struct timespec *);
int _z_gthread_cond_wait_recursive (struct _z_gthread_cond_t *, struct _z_gthread_mutex_t *);
int _z_gthread_cond_destroy (struct _z_gthread_cond_t *);


#define _z_gthread_sem_initializer { 0,0,0,0,0,0,0,0 }
#define _z_gthread_mutex_initializer { 0,0,0,0 }
#define _z_gthread_cond_initializer { 0,0,0,0,0 }

/* Newlib lock functions */
#define __LOCK_INIT(class, lock) \
    class _LOCK_T lock = _z_gthread_sem_initializer

#define __LOCK_INIT_RECURSIVE(class, lock) \
    class _LOCK_RECURSIVE_T lock = _z_gthread_mutex_initializer
/*
#define __LOCK_INIT(class,lock) \
    class _LOCK_T lock = _z_gthread_sem_initializer()

#define __LOCK_INIT_RECURSIVE(class,lock) \
    class _LOCK_RECURSIVE_T lock = _z_gthread_mutex_initializer()
*/

#define __lock_init(_lock) _z_gthread_sem_initialize(&_lock)
#define __lock_acquire(_lock) _z_gthread_sem_lock(&_lock)
#define __lock_try_acquire(lock) _struct _z_gthread_sem_trylock(&_lock)
#define __lock_release(_lock) _z_gthread_sem_unlock(&_lock)
#define __lock_close(_lock) _z_gthread_sem_destroy(&_lock)

#define __lock_init_recursive(_lock) _z_gthread_mutex_initialize(&_lock)
#define __lock_acquire_recursive(_lock) _z_gthread_mutex_lock(&_lock)
#define __lock_try_acquire_recursive(lock) _struct _z_gthread_mutex_trylock(&_lock)
#define __lock_release_recursive(_lock) _z_gthread_mutex_unlock(&_lock)
#define __lock_close_recursive(_lock) _z_gthread_mutex_destroy(&_lock)

#ifdef __cplusplus
}
#endif

#endif /* !__SYS_LOCK_H__ */
