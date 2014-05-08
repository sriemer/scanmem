#ifndef _TYPES_INC
#define _TYPES_INC

#include "config.h"

#include <stdint.h>
#include <inttypes.h>
#include <limits.h>

/* uintptr_t is optional */
#if !defined(HAVE_UINTPTR_T) || !HAVE_UINTPTR_T
#warning uintptr_t is not available! Using unsigned long.
#define uintptr_t unsigned long
#endif
#ifndef PRIxPTR
#warning No output format for uintptr_t available! Using unsigned long.
#define PRIxPTR "lx"
#endif
#define PTR_FMT "%"PRIxPTR
#ifndef UINTPTR_MAX
#warning No limits for uintptr_t available! Using unsigned long.
#ifndef ULONG_MAX
#warning ULONG_MAX is not defined!
#endif
#define UINTPTR_MAX ULONG_MAX
#endif

/* try to determine the size of a pointer */
#if UINTPTR_MAX == 4294967295UL
#define POINTER_FMT "%8"PRIxPTR
#elif UINTPTR_MAX == 18446744073709551615UL
#define POINTER_FMT "%12"PRIxPTR
#else
#define POINTER_FMT "%12"PRIxPTR
#endif

#endif
