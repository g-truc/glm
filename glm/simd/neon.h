/// @ref simd_neon
/// @file glm/simd/neon.h

#pragma once

#if GLM_ARCH & GLM_ARCH_NEON_BIT
#include <arm_neon.h>

namespace glm {
	namespace neon {
		static inline float32x4_t dupq_lane(float32x4_t vsrc, int lane) {
			switch(lane) {
				default: assert(false); //Unreachable code executed!
#if GLM_ARCH & GLM_ARCH_ARMV8_BIT
				case 0: return vdupq_laneq_f32(vsrc, 0);
				case 1: return vdupq_laneq_f32(vsrc, 1);
				case 2: return vdupq_laneq_f32(vsrc, 2);
				case 3: return vdupq_laneq_f32(vsrc, 3);
#else
				case 0: return vdupq_n_f32(vgetq_lane_f32(vsrc, 0));
				case 1: return vdupq_n_f32(vgetq_lane_f32(vsrc, 1));
				case 2: return vdupq_n_f32(vgetq_lane_f32(vsrc, 2));
				case 3: return vdupq_n_f32(vgetq_lane_f32(vsrc, 3));
#endif
			}
			return vdupq_n_f32(0.0f);
		}

		static inline float32x2_t dup_lane(float32x4_t vsrc, int lane) {
			switch(lane) {
				default: assert(false); //Unreachable code executed!
#if GLM_ARCH & GLM_ARCH_ARMV8_BIT
				case 0: return vdup_laneq_f32(vsrc, 0);
				case 1: return vdup_laneq_f32(vsrc, 1);
				case 2: return vdup_laneq_f32(vsrc, 2);
				case 3: return vdup_laneq_f32(vsrc, 3);
#else
				case 0: return vdup_n_f32(vgetq_lane_f32(vsrc, 0));
				case 1: return vdup_n_f32(vgetq_lane_f32(vsrc, 1));
				case 2: return vdup_n_f32(vgetq_lane_f32(vsrc, 2));
				case 3: return vdup_n_f32(vgetq_lane_f32(vsrc, 3));
#endif
			}
			return vdup_n_f32(0.0f);
		}

		static inline float32x4_t copy_lane(float32x4_t vdst, int dlane, float32x4_t vsrc, int slane) {
#if GLM_ARCH & GLM_ARCH_ARMV8_BIT
			switch(dlane) {
				default:
				case 0:
					switch(slane) {
						default: assert(false); //Unreachable code executed!
						case 0: return vcopyq_laneq_f32(vdst, 0, vsrc, 0);
						case 1: return vcopyq_laneq_f32(vdst, 0, vsrc, 1);
						case 2: return vcopyq_laneq_f32(vdst, 0, vsrc, 2);
						case 3: return vcopyq_laneq_f32(vdst, 0, vsrc, 3);
					}
					break;
				case 1:
					switch(slane) {
						default: assert(false); //Unreachable code executed!
						case 0: return vcopyq_laneq_f32(vdst, 1, vsrc, 0);
						case 1: return vcopyq_laneq_f32(vdst, 1, vsrc, 1);
						case 2: return vcopyq_laneq_f32(vdst, 1, vsrc, 2);
						case 3: return vcopyq_laneq_f32(vdst, 1, vsrc, 3);
					}
					break;
				case 2:
					switch(slane) {
						default: assert(false); //Unreachable code executed!
						case 0: return vcopyq_laneq_f32(vdst, 2, vsrc, 0);
						case 1: return vcopyq_laneq_f32(vdst, 2, vsrc, 1);
						case 2: return vcopyq_laneq_f32(vdst, 2, vsrc, 2);
						case 3: return vcopyq_laneq_f32(vdst, 2, vsrc, 3);
					}
					break;
				case 3:
					switch(slane) {
						default: assert(false); //Unreachable code executed!
						case 0: return vcopyq_laneq_f32(vdst, 3, vsrc, 0);
						case 1: return vcopyq_laneq_f32(vdst, 3, vsrc, 1);
						case 2: return vcopyq_laneq_f32(vdst, 3, vsrc, 2);
						case 3: return vcopyq_laneq_f32(vdst, 3, vsrc, 3);
					}
					break;
			}
#else

			float l;
			switch(slane) {
				default: assert(false); //Unreachable code executed!
				case 0: l = vgetq_lane_f32(vsrc, 0); break;
				case 1: l = vgetq_lane_f32(vsrc, 1); break;
				case 2: l = vgetq_lane_f32(vsrc, 2); break;
				case 3: l = vgetq_lane_f32(vsrc, 3); break;
			}
			switch(dlane) {
				default: assert(false); //Unreachable code executed!
				case 0: return vsetq_lane_f32(l, vdst, 0);
				case 1: return vsetq_lane_f32(l, vdst, 1);
				case 2: return vsetq_lane_f32(l, vdst, 2);
				case 3: return vsetq_lane_f32(l, vdst, 3);
			}
#endif
			return vdupq_n_f32(0.0f);
		}

		static inline float32x4_t mul_lane(float32x4_t v, float32x4_t vlane, int lane) {
#if GLM_ARCH & GLM_ARCH_ARMV8_BIT
			switch(lane) {
				default: assert(false); return vdupq_n_f32(0.0f); //Unreachable code executed!
				case 0: return vmulq_laneq_f32(v, vlane, 0); break;
				case 1: return vmulq_laneq_f32(v, vlane, 1); break;
				case 2: return vmulq_laneq_f32(v, vlane, 2); break;
				case 3: return vmulq_laneq_f32(v, vlane, 3); break;
			}
#else
			return vmulq_f32(v, dupq_lane(vlane, lane));
#endif
		}

		static inline float32x4_t madd_lane(float32x4_t acc, float32x4_t v, float32x4_t vlane, int lane) {
#if GLM_ARCH & GLM_ARCH_ARMV8_BIT
#ifdef GLM_CONFIG_FORCE_FMA
#	define FMADD_LANE(acc, x, y, L) do { asm volatile ("fmla %0.4s, %1.4s, %2.4s" : "+w"(acc) : "w"(x), "w"(dup_lane(y, L))); } while(0)
#else
#	define FMADD_LANE(acc, x, y, L) do { acc = vmlaq_laneq_f32(acc, x, y, L); } while(0)
#endif

			switch(lane) { 
				case 0: 
					FMADD_LANE(acc, v, vlane, 0);
					return acc;
				case 1:
					FMADD_LANE(acc, v, vlane, 1);
					return acc;
				case 2:
					FMADD_LANE(acc, v, vlane, 2);
					return acc;
				case 3:
					FMADD_LANE(acc, v, vlane, 3);
					return acc;
				default: 
					assert(false); //Unreachable code executed!
			}
			return vdupq_n_f32(0.0f);
#	undef FMADD_LANE
#else
			return vaddq_f32(acc, vmulq_f32(v, dupq_lane(vlane, lane)));
#endif
		}
	} //namespace neon
} // namespace glm
#endif // GLM_ARCH & GLM_ARCH_NEON_BIT
