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

#include <sys/_timespec.h>

void zephyr_provides_crt0( void ) {}  

#define ZEPHYR_STUB(ret, func, body) \
ret zephyr_stub_##func body; \
ret func body


/* Threads */
/*
ZEPHYR_STUB( int, _z_gthread_create (_z_gthread_t *threadid, void *(*__func) (void *),  void *__args),{return 0;})
ZEPHYR_STUB( int, _z_gthread_join (_z_gthread_t threadid, void **value_ptr), {return 0;})
ZEPHYR_STUB( int, _z_gthread_detach (_z_gthread_t threadid), {return 0;}) 
ZEPHYR_STUB( int, _z_gthread_equal (_z_gthread_t t1, _z_gthread_t t2), {return 0;}) 
ZEPHYR_STUB( _z_gthread_t , _z_gthread_self (void), {return 0;})  
ZEPHYR_STUB( int , _z_gthread_yield (void), {return 0;})  
ZEPHYR_STUB( int , _z_gthread_once (_z_gthread_once_t *once, void (*__func) (void)) , {return 0;}) 
ZEPHYR_STUB( int , _z_gthread_key_create (_z_gthread_key_t *key, void (*__dtor) (void *)) , {return 0;}) 
ZEPHYR_STUB( int , _z_gthread_key_delete (_z_gthread_key_t key) , {return 0;}) 
ZEPHYR_STUB( void * , _z_gthread_getspecific (_z_gthread_key_t key) , {return NULL;}) 
ZEPHYR_STUB( int , _z_gthread_setspecific (_z_gthread_key_t key, const void * ptr) , {return 0;}) 
*/
ZEPHYR_STUB( int , _z_gthread_yield (void), {return 0;})  

/* Semaphore (non-recursive mutex) */
ZEPHYR_STUB( void , _z_gthread_sem_initialize (struct _z_gthread_sem_t *sem) , {return ;}) 
ZEPHYR_STUB( int , _z_gthread_sem_lock (struct _z_gthread_sem_t *sem) , {return 0;}) 
ZEPHYR_STUB( int , _z_gthread_sem_trylock (struct _z_gthread_sem_t *sem) , {return 0;}) 
ZEPHYR_STUB( int ,_z_gthread_sem_timedlock (struct _z_gthread_sem_t *sem,   const struct timespec *timeout) , {return 0;}) 
ZEPHYR_STUB( int , _z_gthread_sem_unlock (struct _z_gthread_sem_t *sem) , {return 0;}) 
ZEPHYR_STUB( int , _z_gthread_sem_destroy (struct _z_gthread_sem_t *sem) , {return 0;}) 

/* Recursive mutex */
ZEPHYR_STUB( void ,_z_gthread_mutex_initialize (struct _z_gthread_mutex_t *mtx) , {return ;}) 
ZEPHYR_STUB( int ,_z_gthread_mutex_lock (struct _z_gthread_mutex_t *mtx), {return 0;})  
ZEPHYR_STUB( int ,_z_gthread_mutex_trylock (struct _z_gthread_mutex_t *mtx) , {return 0;}) 
ZEPHYR_STUB( int ,_z_gthread_mutex_timedlock (struct _z_gthread_mutex_t *mtx,   const struct timespec *timeout) , {return 0;}) 
ZEPHYR_STUB( int ,_z_gthread_mutex_unlock (struct _z_gthread_mutex_t *mtx) , {return 0;}) 
ZEPHYR_STUB( int ,_z_gthread_mutex_destroy (struct _z_gthread_mutex_t *mtx) , {return 0;}) 

/* Conditions */
ZEPHYR_STUB( void ,_z_gthread_cond_initialize (struct _z_gthread_cond_t *cond) , {return ;}) 
ZEPHYR_STUB( int ,_z_gthread_cond_broadcast (struct _z_gthread_cond_t *cond) , {return 0;}) 
ZEPHYR_STUB( int ,_z_gthread_cond_signal (struct _z_gthread_cond_t *cond) , {return 0;}) 
ZEPHYR_STUB( int ,_z_gthread_cond_wait (struct _z_gthread_cond_t *cond, struct _z_gthread_sem_t *sem) , {return 0;}) 
ZEPHYR_STUB( int ,_z_gthread_cond_timedwait (struct _z_gthread_cond_t *cond, struct _z_gthread_sem_t *sem,  const struct timespec *timeout) , {return 0;}) 
ZEPHYR_STUB( int ,_z_gthread_cond_wait_recursive (struct _z_gthread_cond_t *cond, struct _z_gthread_mutex_t *mtx) , {return 0;}) 
ZEPHYR_STUB( int ,_z_gthread_cond_destroy (struct _z_gthread_cond_t *cond) , {return 0;}) 
ZEPHYR_STUB( void ,_exit(int status) ,{ while(1){}} )

/*
struct _z_gthread_sem_t _z_gthread_sem_initializer (void)
{
    struct _z_gthread_sem_t ret = { .dummy = {0, 0, 0, 0, 0, 0, 0, 0}};
    return ret;
}
*/
/*
struct _z_gthread_mutex_t _z_gthread_mutex_initializer (void)
{
    struct _z_gthread_mutex_t ret = { .dummy = {0, 0, 0, 0, 0, 0, 0, 0}};
    return ret;
}
*/
/*
struct _z_gthread_cond_t _z_gthread_cond_initializer (void)
{
    struct _z_gthread_cond_t ret = { .dummy = {0, 0, 0, 0, 0, 0, 0, 0}};
    return ret;
}
*/