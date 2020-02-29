#ifndef __WAIT_Q_H__
#define __WAIT_Q_H__

#include <sys/dlist.h>


#ifdef __cplusplus
extern "C" {
#endif


#ifdef CONFIG_WAITQ_SCALABLE

typedef struct {
	struct _priq_rb waitq;
} _wait_q_t;

extern bool z_priq_rb_lessthan(struct rbnode *a, struct rbnode *b);

#define Z_WAIT_Q_INIT(wait_q) { { { .lessthan_fn = z_priq_rb_lessthan } } }

#else

typedef struct {
	sys_dlist_t waitq;
} _wait_q_t;

#define Z_WAIT_Q_INIT(wait_q) { SYS_DLIST_STATIC_INIT(&(wait_q)->waitq) }

#endif

#ifdef __cplusplus
}
#endif

#endif /* !__WAIT_Q_H__ */