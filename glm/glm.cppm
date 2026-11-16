module;

#include <cassert>
#include <cmath>
#include <cstdarg>
#include <cstdio>

#include "./simd/platform.h"

#if GLM_ARCH & GLM_ARCH_SSE2_BIT
#	include <immintrin.h>
#endif

#if GLM_ARCH & GLM_ARCH_X86 && GLM_COMPILER & GLM_COMPILER_VC
#	include <intrin.h>
#endif

#if GLM_ARCH & GLM_ARCH_NEON_BIT
#	include <arm_neon.h>
#endif

#define GLM_CXX_MODULE

export module glm;

import std;

#include "./glm.hpp"
#include "./ext.hpp"

#if defined(_MSC_VER) // Workaround
// Partial template specialization doesn't need to be exported explicitly, but this may not work otherwise on MSVC.
export namespace std {
	using std::hash; // See GLM_GTX_hash
}
#endif
