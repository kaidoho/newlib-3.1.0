#ifndef _SYS__PTHREADTYPES_H_
#define	_SYS__PTHREADTYPES_H_

#include <sys/lock.h>
#include <sys/slist.h>
#include <sys/_wait_q.h>

#ifdef __cplusplus
extern "C" {
#endif

#define PTHREAD_SCOPE_PROCESS 0
#define PTHREAD_SCOPE_SYSTEM  1

enum pthread_state {
	/* The thread structure is unallocated and available for reuse. */
	PTHREAD_TERMINATED = 0,
	/* The thread is running and joinable. */
	PTHREAD_JOINABLE,
	/* The thread is running and detached. */
	PTHREAD_DETACHED,
	/* A joinable thread exited and its return code is available. */
	PTHREAD_EXITED
};

/* Pthread detach/joinable */
#define PTHREAD_CREATE_JOINABLE     PTHREAD_JOINABLE
#define PTHREAD_CREATE_DETACHED     PTHREAD_DETACHED

/* Pthread cancellation */
#define _PTHREAD_CANCEL_POS	0
#define PTHREAD_CANCEL_ENABLE	(0U << _PTHREAD_CANCEL_POS)
#define PTHREAD_CANCEL_DISABLE	BIT(_PTHREAD_CANCEL_POS)

/* Passed to pthread_once */
#define PTHREAD_ONCE_INIT 1

/*
 *  Mutex attributes - type
 *
 *  PTHREAD_MUTEX_NORMAL: Owner of mutex cannot relock it. Attempting
 *      to relock will cause deadlock.
 *  PTHREAD_MUTEX_RECURSIVE: Owner can relock the mutex.
 *  PTHREAD_MUTEX_ERRORCHECK: If owner attempts to relock the mutex, an
 *      error is returned.
 *
 */
#define PTHREAD_MUTEX_NORMAL        0
#define PTHREAD_MUTEX_RECURSIVE     1
#define PTHREAD_MUTEX_ERRORCHECK    2
#define PTHREAD_MUTEX_DEFAULT       PTHREAD_MUTEX_NORMAL

/*
 *  Mutex attributes - protocol
 *
 *  PTHREAD_PRIO_NONE: Ownership of mutex does not affect priority.
 *  PTHREAD_PRIO_INHERIT: Owner's priority is boosted to the priority of
 *      highest priority thread blocked on the mutex.
 *  PTHREAD_PRIO_PROTECT:  Mutex has a priority ceiling.  The owner's
 *      priority is boosted to the highest priority ceiling of all mutexes
 *      owned (regardless of whether or not other threads are blocked on
 *      any of these mutexes).
 *  FIXME: Only PRIO_NONE is supported. Implement other protocols.
 */
#define PTHREAD_PRIO_NONE           0



typedef unsigned long useconds_t;

/* time related attributes */
typedef u32_t clockid_t;

typedef unsigned long timer_t;

typedef struct k_thread *k_tid_t;


/* Thread attributes */
typedef struct pthread_attr_t {
	int priority;
	void *stack;
	size_t stacksize;
	u32_t flags;
	u32_t delayedstart;
	u32_t schedpolicy;
	s32_t detachstate;
	u32_t initialized;
} pthread_attr_t;

typedef void *pthread_t;


/* Mutex */
typedef struct pthread_mutex {
	pthread_t owner;
	u16_t lock_count;
	int type;
	_wait_q_t wait_q;
} pthread_mutex_t;

typedef struct pthread_mutexattr {
	int type;
} pthread_mutexattr_t;

/* Condition variables */
typedef struct pthread_cond {
	_wait_q_t wait_q;
} pthread_cond_t;

typedef struct pthread_condattr {
} pthread_condattr_t;

/* Barrier */
typedef struct pthread_barrier {
	_wait_q_t wait_q;
	int max;
	int count;
} pthread_barrier_t;

typedef struct pthread_barrierattr {
} pthread_barrierattr_t;

typedef u32_t pthread_rwlockattr_t;

typedef struct pthread_rwlock_obj {
	struct _z_gthread_sem_t rd_sem;
	struct _z_gthread_sem_t wr_sem;
	struct _z_gthread_sem_t reader_active;/* blocks WR till reader has acquired lock */
	s32_t status;
	void* wr_owner;
} pthread_rwlock_t;


typedef u32_t pthread_once_t;

/* pthread_key */
typedef void *pthread_key_t;

typedef struct pthread_key_obj {
	/* List of pthread_key_data objects that contain thread
	 * specific data for the key
	 */
	sys_slist_t key_data_l;

	/* Optional destructor that is passed to pthread_key_create() */
	void (*destructor)(void *);
} pthread_key_obj;

typedef struct pthread_thread_data {
	sys_snode_t node;

	/* Key and thread specific data passed to pthread_setspecific() */
	pthread_key_obj *key;
	void *spec_data;
} pthread_thread_data;

typedef struct pthread_key_data {
	sys_snode_t node;
	pthread_thread_data thread_data;
} pthread_key_data;

/* POSIX Spin Lock Types */

#if defined(_POSIX_SPIN_LOCKS)
typedef struct {

  u32_t                  lock;
} pthread_spinlock_t;                        
#endif /* defined(_POSIX_SPIN_LOCKS) */

#ifdef __cplusplus
}
#endif

#endif /* ! _SYS__PTHREADTYPES_H_ */