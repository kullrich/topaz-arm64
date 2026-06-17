#ifndef SSE2NEON_COMPAT_H
#define SSE2NEON_COMPAT_H

#if defined(__aarch64__) || defined(__arm__) || defined(_M_ARM64)
    #include "sse2neon.h"
#else
    #include <emmintrin.h>
#endif

#endif /* SSE2NEON_COMPAT_H */
