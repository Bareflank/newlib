/* ---------------------------------------------------------------------------*/
/* bareflank: start                                                           */
/* ---------------------------------------------------------------------------*/
/* POSIX compliant pthread header                                             */

/*
 * Bareflank Hypervisor
 *
 * Copyright (C) 2015 Assured Information Security, Inc.
 * Author: Rian Quinn        <quinnr@ainfosec.com>
 * Author: Brendan Kerrigan  <kerriganb@ainfosec.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef PTHREAD_H
#define PTHREAD_H

#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * constants
 */
#define PTHREAD_BARRIER_SERIAL_THREAD       0x00000001U
#define PTHREAD_CANCEL_ASYNCHRONOUS         0x00000001U
#define PTHREAD_CANCEL_ENABLE               0x00000002U
#define PTHREAD_CANCEL_DEFERRED             0x00000004U
#define PTHREAD_CANCEL_DISABLE              0x00000008U
#define PTHREAD_CANCELED                    0x00000001U
#define PTHREAD_CREATE_DETACHED             0x00000001U
#define PTHREAD_CREATE_JOINABLE             0x00000002U

#define PTHREAD_EXPLICIT_SCHED              0x00000001U     /* [TPS] */
#define PTHREAD_INHERIT_SCHED               0x00000002U     /* [TPS] */

#define PTHREAD_MUTEX_DEFAULT               0x00000001U
#define PTHREAD_MUTEX_ERRORCHECK            0x00000002U
#define PTHREAD_MUTEX_NORMAL                0x00000004U
#define PTHREAD_MUTEX_RECURSIVE             0x00000008U
#define PTHREAD_MUTEX_ROBUST                0x00000010U
#define PTHREAD_MUTEX_STALLED               0x00000020U
#define PTHREAD_ONCE_INIT                   0x00000000U

#define PTHREAD_PRIO_INHERIT                0x00000001U     /* [RPI|TPI] */

#define PTHREAD_PRIO_NONE                   0x00000002U     /* [MC1] */

#define PTHREAD_PRIO_PROTECT                0x00000004U     /* [RPP|TPP] */

#define PTHREAD_PROCESS_SHARED              0x00000001U
#define PTHREAD_PROCESS_PRIVATE             0x00000002U

#define PTHREAD_SCOPE_PROCESS               0x00000001U     /* [TPS] */
#define PTHREAD_SCOPE_SYSTEM                0x00000002U     /* [TPS] */

/*
 * initializers
 */
#define PTHREAD_COND_INITIALIZER            0x00000000U
#define PTHREAD_MUTEX_INITIALIZER           0x00000000U
#define PTHREAD_RWLOCK_INITIALIZER          0x00000000U

/*
 * types
 */
typedef int64_t pthread_attr_t;             /* Used to identify a thread attribute object. */
typedef int64_t pthread_barrier_t;          /* Used to identify a barrier. */
typedef int64_t pthread_barrierattr_t;      /* Used to define a barrier attributes object. */
typedef int64_t pthread_cond_t;             /* Used for condition variables. */
typedef int64_t pthread_condattr_t;         /* Used to identify a condition attribute object. */
typedef int64_t pthread_key_t;              /* Used for thread-specific data keys. */
typedef int64_t pthread_mutex_t;            /* Used for mutexes. */
typedef int64_t pthread_mutexattr_t;        /* Used to identify a mutex attribute object. */
typedef int64_t pthread_once_t;             /* Used for dynamic package initialization. */
typedef int64_t pthread_rwlock_t;           /* Used for read-write locks. */
typedef int64_t pthread_rwlockattr_t;       /* Used for read-write lock attributes. */
typedef int64_t pthread_spinlock_t;         /* Used to identify a spin lock. */
typedef int64_t pthread_t;                  /* Used to identify a thread. */

/* __BEGIN_DECLS */

int   pthread_atfork(void (*)(void), void (*)(void),void(*)(void));
int   pthread_attr_destroy(pthread_attr_t *);
int   pthread_attr_getdetachstate(const pthread_attr_t *, int *);
int   pthread_attr_getguardsize(const pthread_attr_t *, size_t *);
int   pthread_attr_getinheritsched(const pthread_attr_t *, int *);              /* [TPS] */
int   pthread_attr_getschedparam(const pthread_attr_t *, struct sched_param *);
int   pthread_attr_getschedpolicy(const pthread_attr_t *, int *);               /* [TPS] */
int   pthread_attr_getscope(const pthread_attr_t *, int *);                     /* [TPS] */
int   pthread_attr_getstack(const pthread_attr_t *, void **, size_t *);         /* [TSA TSS] */
int   pthread_attr_getstacksize(const pthread_attr_t *, size_t *);              /* [TSS] */
int   pthread_attr_init(pthread_attr_t *);
int   pthread_attr_setdetachstate(pthread_attr_t *, int);
int   pthread_attr_setguardsize(pthread_attr_t *, size_t);
int   pthread_attr_setinheritsched(pthread_attr_t *, int);                      /* [TPS] */
int   pthread_attr_setschedparam(pthread_attr_t *, const struct sched_param *);
int   pthread_attr_setschedpolicy(pthread_attr_t *, int);                       /* [TPS] */
int   pthread_attr_setscope(pthread_attr_t *, int);                             /* [TPS] */
int   pthread_attr_setstack(pthread_attr_t *, void *, size_t);                  /* [TSA TSS] */
int   pthread_attr_setstacksize(pthread_attr_t *, size_t);                      /* [TSS] */
int   pthread_barrier_destroy(pthread_barrier_t *);
int   pthread_barrier_init(pthread_barrier_t *, const pthread_barrierattr_t *, unsigned);
int   pthread_barrier_wait(pthread_barrier_t *);
int   pthread_barrierattr_destroy(pthread_barrierattr_t *);
int   pthread_barrierattr_getpshared(const pthread_barrierattr_t *, int *);     /* [TSH] */
int   pthread_barrierattr_init(pthread_barrierattr_t *);
int   pthread_barrierattr_setpshared(pthread_barrierattr_t *, int);             /* [TSH] */
int   pthread_cancel(pthread_t);
int   pthread_cond_broadcast(pthread_cond_t *);
int   pthread_cond_destroy(pthread_cond_t *);
int   pthread_cond_init(pthread_cond_t *,const pthread_condattr_t *);
int   pthread_cond_signal(pthread_cond_t *);
int   pthread_cond_timedwait(pthread_cond_t *, pthread_mutex_t *, const struct timespec *);
int   pthread_cond_wait(pthread_cond_t *, pthread_mutex_t *);
int   pthread_condattr_destroy(pthread_condattr_t *);
int   pthread_condattr_getclock(const pthread_condattr_t *, clockid_t *);
int   pthread_condattr_getpshared(const pthread_condattr_t *, int *);           /* [TSH] */
int   pthread_condattr_init(pthread_condattr_t *);
int   pthread_condattr_setclock(pthread_condattr_t *, clockid_t);
int   pthread_condattr_setpshared(pthread_condattr_t *, int);                   /* [TSH] */
int   pthread_create(pthread_t *, const pthread_attr_t *, void *(*)(void*), void *);
int   pthread_detach(pthread_t);
int   pthread_equal(pthread_t, pthread_t);
void  pthread_exit(void *);
int   pthread_getconcurrency(void);                                             /* [OB XSI] */
int   pthread_getcpuclockid(pthread_t, clockid_t *);                            /* [TCT] */
int   pthread_getschedparam(pthread_t, int *, struct sched_param *);            /* [TPS] */
void *pthread_getspecific(pthread_key_t);
int   pthread_join(pthread_t, void **);
int   pthread_key_create(pthread_key_t *, void (*)(void*));
int   pthread_key_delete(pthread_key_t);
int   pthread_mutex_consistent(pthread_mutex_t *);
int   pthread_mutex_destroy(pthread_mutex_t *);
int   pthread_mutex_getprioceiling(const pthread_mutex_t *, int *);             /* [RPP|TPP] */
int   pthread_mutex_init(pthread_mutex_t *, const pthread_mutexattr_t *);
int   pthread_mutex_lock(pthread_mutex_t *);
int   pthread_mutex_setprioceiling(pthread_mutex_t *, int, int *);              /* [RPP|TPP] */
int   pthread_mutex_timedlock(pthread_mutex_t *, const struct timespec *);
int   pthread_mutex_trylock(pthread_mutex_t *);
int   pthread_mutex_unlock(pthread_mutex_t *);
int   pthread_mutexattr_destroy(pthread_mutexattr_t *);
int   pthread_mutexattr_getprioceiling(const pthread_mutexattr_t *, int *);     /* [RPP|TPP] */
int   pthread_mutexattr_getprotocol(const pthread_mutexattr_t *, int *);        /* [MC1] */
int   pthread_mutexattr_getpshared(const pthread_mutexattr_t *, int *);         /* [TSH] */
int   pthread_mutexattr_getrobust(const pthread_mutexattr_t *, int *);
int   pthread_mutexattr_gettype(const pthread_mutexattr_t *, int *);
int   pthread_mutexattr_init(pthread_mutexattr_t *);
int   pthread_mutexattr_setprioceiling(pthread_mutexattr_t *, int);             /* [RPP|TPP] */
int   pthread_mutexattr_setprotocol(pthread_mutexattr_t *, int);                /* [MC1] */
int   pthread_mutexattr_setpshared(pthread_mutexattr_t *, int);                 /* [TSH] */
int   pthread_mutexattr_setrobust(pthread_mutexattr_t *, int);
int   pthread_mutexattr_settype(pthread_mutexattr_t *, int);
int   pthread_once(pthread_once_t *, void (*)(void));
int   pthread_rwlock_destroy(pthread_rwlock_t *);
int   pthread_rwlock_init(pthread_rwlock_t *, const pthread_rwlockattr_t *);
int   pthread_rwlock_rdlock(pthread_rwlock_t *);
int   pthread_rwlock_timedrdlock(pthread_rwlock_t *, const struct timespec *);
int   pthread_rwlock_timedwrlock(pthread_rwlock_t *, const struct timespec *);
int   pthread_rwlock_tryrdlock(pthread_rwlock_t *);
int   pthread_rwlock_trywrlock(pthread_rwlock_t *);
int   pthread_rwlock_unlock(pthread_rwlock_t *);
int   pthread_rwlock_wrlock(pthread_rwlock_t *);
int   pthread_rwlockattr_destroy(pthread_rwlockattr_t *);
int   pthread_rwlockattr_getpshared(const pthread_rwlockattr_t *, int *);       /* [TSH] */
int   pthread_rwlockattr_init(pthread_rwlockattr_t *);
int   pthread_rwlockattr_setpshared(pthread_rwlockattr_t *, int);               /* [TSH] */
pthread_t pthread_self(void);
int   pthread_setcancelstate(int, int *);
int   pthread_setcanceltype(int, int *);
int   pthread_setconcurrency(int);                                              /* [OB XSI] */
int   pthread_setschedparam(pthread_t, int, const struct sched_param *);        /* [TPS] */
int   pthread_setschedprio(pthread_t, int);                                     /* [TPS] */
int   pthread_setspecific(pthread_key_t, const void *);
int   pthread_spin_destroy(pthread_spinlock_t *);
int   pthread_spin_init(pthread_spinlock_t *, int);
int   pthread_spin_lock(pthread_spinlock_t *);
int   pthread_spin_trylock(pthread_spinlock_t *);
int   pthread_spin_unlock(pthread_spinlock_t *);
void  pthread_testcancel(void);

/* __END_DECLS */

#ifdef __cplusplus
}
#endif

#endif

/* ---------------------------------------------------------------------------*/
/* bareflank: end                                                             */
/* ---------------------------------------------------------------------------*/