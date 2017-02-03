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

#ifndef SYS_MMAN_H
#define SYS_MMAN_H

#include <sys/types.h>

#ifdef __cplusplus
#define __pvoid(a) reinterpret_cast<void *>(a)
#else
#define __pvoid(a) ((void *)(a))
#endif

/*
 * currently unsupported:
 *
 * [ADV] POSIX_MADV_DONTNEED
 * [ADV] POSIX_MADV_NORMAL
 * [ADV] POSIX_MADV_RANDOM
 * [ADV] POSIX_MADV_SEQUENTIAL
 * [ADV] POSIX_MADV_WILLNEED
 * [ADV] posix_madvise()
 *
 * [TYM] POSIX_TYPED_MEM_ALLOCATE
 * [TYM] POSIX_TYPED_MEM_ALLOCATE_CONTIG
 * [TYM] POSIX_TYPED_MEM_MAP_ALLOCATABLE
 * [TYM] struct posix_typed_mem_info
 * [TYM] posix_mem_offset()
 * [TYM] posix_typed_mem_get_info()
 * [TYM] posix_typed_mem_open()
 *
 */

#ifdef __cplusplus
extern "C" {
#endif

/*
 * protection options
 */
#define PROT_READ       0x00000001U     /* Page can be read */
#define PROT_WRITE      0x00000002U     /* Page can be written */
#define PROT_EXEC       0x00000004U     /* Page can be executed */
#define PROT_NONE       0x00000000U     /* Page cannot be accessed */

/*
 * flag options
 */
#define MAP_SHARED      0x00000001U     /* Share changes */
#define MAP_PRIVATE     0x00000002U     /* Changes are private */
#define MAP_FIXED       0x00000010U     /* Interpret addr exactly */

/*
 * msync() flags
 */
#define MS_ASYNC        0x00000001U     /* [XSI|SIO] Perform asynchronous writes */
#define MS_INVALIDATE   0x00000002U     /* [XSI|SIO] Invalidate mappings */
#define MS_SYNC         0x00000010U     /* [XSI|SIO] Perform synchronous writes */

/*
 * mlockall() flags
 */
#define MCL_CURRENT     0x00000001U     /* [ML] Lock currently mapped pages */
#define MCL_FUTURE      0x00000002U     /* [ML] Lock pages that become mapped */

/*
 * mmap() failed
 */
#define MAP_FAILED      __pvoid(-1)

/* __BEGIN_DECLS */

int    mlock(const void *, size_t);                     /* [MLR] */
int    mlockall(int);                                   /* [ML] */
void  *mmap(void *, size_t, int, int, int, off_t);
int    mprotect(void *, size_t, int);
int    msync(void *, size_t, int);                      /* [XSI|SIO] */
int    munlock(const void *, size_t);                   /* [MLR] */
int    munlockall(void);                                /* [ML] */
int    munmap(void *, size_t);
int    shm_open(const char *, int, mode_t);             /* [SHM] */
int    shm_unlink(const char *);                        /* [SHM] */

/* __END_DECLS */

#ifdef __cplusplus
}
#endif

#endif
