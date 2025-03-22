/// @ref gtx_vec_swizzle
/// @file glm/gtx/vec_swizzle.hpp
///
/// @see core (dependence)
///
/// @defgroup gtx_vec_swizzle GLM_GTX_vec_swizzle
/// @ingroup gtx
///
/// Include <glm/gtx/vec_swizzle.hpp> to use the features of this extension.
///
/// Functions to perform swizzle operation.

#pragma once

#include "../glm.hpp"

#ifndef GLM_ENABLE_EXPERIMENTAL
#	error "GLM: GLM_GTX_vec_swizzle is an experimental extension and may change in the future. Use #define GLM_ENABLE_EXPERIMENTAL before including it, if you really want to use it."
#elif GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_GTX_vec_swizzle extension included")
#endif

namespace glm {
	/// @addtogroup gtx_vec_swizzle
	/// @{

	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T, Q> xx(vec<L, T, Q> const& v) { return vec<2, T, Q>(v.x, v.x); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T, Q> xy(vec<L, T, Q> const& v) { return vec<2, T, Q>(v.x, v.y); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T, Q> xz(vec<L, T, Q> const& v) { return vec<2, T, Q>(v.x, v.z); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T, Q> xw(vec<L, T, Q> const& v) { return vec<2, T, Q>(v.x, v.w); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T, Q> yx(vec<L, T, Q> const& v) { return vec<2, T, Q>(v.y, v.x); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T, Q> yy(vec<L, T, Q> const& v) { return vec<2, T, Q>(v.y, v.y); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T, Q> yz(vec<L, T, Q> const& v) { return vec<2, T, Q>(v.y, v.z); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T, Q> yw(vec<L, T, Q> const& v) { return vec<2, T, Q>(v.y, v.w); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T, Q> zx(vec<L, T, Q> const& v) { return vec<2, T, Q>(v.z, v.x); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T, Q> zy(vec<L, T, Q> const& v) { return vec<2, T, Q>(v.z, v.y); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T, Q> zz(vec<L, T, Q> const& v) { return vec<2, T, Q>(v.z, v.z); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T, Q> zw(vec<L, T, Q> const& v) { return vec<2, T, Q>(v.z, v.w); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T, Q> wx(vec<L, T, Q> const& v) { return vec<2, T, Q>(v.w, v.x); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T, Q> wy(vec<L, T, Q> const& v) { return vec<2, T, Q>(v.w, v.y); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T, Q> wz(vec<L, T, Q> const& v) { return vec<2, T, Q>(v.w, v.z); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<2, T, Q> ww(vec<L, T, Q> const& v) { return vec<2, T, Q>(v.w, v.w); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> xxx(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.x, v.x, v.x); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> xxy(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.x, v.x, v.y); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> xxz(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.x, v.x, v.z); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> xxw(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.x, v.x, v.w); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> xyx(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.x, v.y, v.x); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> xyy(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.x, v.y, v.y); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> xyz(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.x, v.y, v.z); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> xyw(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.x, v.y, v.w); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> xzx(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.x, v.z, v.x); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> xzy(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.x, v.z, v.y); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> xzz(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.x, v.z, v.z); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> xzw(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.x, v.z, v.w); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> xwx(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.x, v.w, v.x); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> xwy(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.x, v.w, v.y); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> xwz(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.x, v.w, v.z); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> xww(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.x, v.w, v.w); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> yxx(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.y, v.x, v.x); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> yxy(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.y, v.x, v.y); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> yxz(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.y, v.x, v.z); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> yxw(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.y, v.x, v.w); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> yyx(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.y, v.y, v.x); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> yyy(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.y, v.y, v.y); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> yyz(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.y, v.y, v.z); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> yyw(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.y, v.y, v.w); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> yzx(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.y, v.z, v.x); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> yzy(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.y, v.z, v.y); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> yzz(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.y, v.z, v.z); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> yzw(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.y, v.z, v.w); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> ywx(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.y, v.w, v.x); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> ywy(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.y, v.w, v.y); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> ywz(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.y, v.w, v.z); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> yww(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.y, v.w, v.w); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> zxx(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.z, v.x, v.x); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> zxy(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.z, v.x, v.y); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> zxz(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.z, v.x, v.z); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> zxw(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.z, v.x, v.w); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> zyx(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.z, v.y, v.x); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> zyy(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.z, v.y, v.y); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> zyz(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.z, v.y, v.z); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> zyw(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.z, v.y, v.w); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> zzx(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.z, v.z, v.x); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> zzy(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.z, v.z, v.y); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> zzz(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.z, v.z, v.z); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> zzw(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.z, v.z, v.w); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> zwx(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.z, v.w, v.x); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> zwy(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.z, v.w, v.y); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> zwz(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.z, v.w, v.z); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> zww(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.z, v.w, v.w); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> wxx(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.w, v.x, v.x); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> wxy(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.w, v.x, v.y); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> wxz(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.w, v.x, v.z); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> wxw(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.w, v.x, v.w); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> wyx(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.w, v.y, v.x); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> wyy(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.w, v.y, v.y); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> wyz(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.w, v.y, v.z); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> wyw(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.w, v.y, v.w); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> wzx(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.w, v.z, v.x); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> wzy(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.w, v.z, v.y); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> wzz(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.w, v.z, v.z); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> wzw(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.w, v.z, v.w); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> wwx(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.w, v.w, v.x); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> wwy(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.w, v.w, v.y); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> wwz(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.w, v.w, v.z); }
	template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<3, T, Q> www(vec<L, T, Q> const& v) { return vec<3, T, Q>(v.w, v.w, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xxxx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.x, v.x, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xxxy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.x, v.x, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xxxz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.x, v.x, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xxxw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.x, v.x, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xxyx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.x, v.y, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xxyy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.x, v.y, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xxyz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.x, v.y, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xxyw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.x, v.y, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xxzx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.x, v.z, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xxzy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.x, v.z, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xxzz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.x, v.z, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xxzw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.x, v.z, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xxwx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.x, v.w, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xxwy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.x, v.w, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xxwz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.x, v.w, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xxww(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.x, v.w, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xyxx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.y, v.x, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xyxy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.y, v.x, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xyxz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.y, v.x, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xyxw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.y, v.x, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xyyx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.y, v.y, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xyyy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.y, v.y, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xyyz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.y, v.y, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xyyw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.y, v.y, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xyzx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.y, v.z, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xyzy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.y, v.z, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xyzz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.y, v.z, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xyzw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.y, v.z, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xywx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.y, v.w, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xywy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.y, v.w, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xywz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.y, v.w, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xyww(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.y, v.w, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xzxx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.z, v.x, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xzxy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.z, v.x, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xzxz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.z, v.x, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xzxw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.z, v.x, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xzyx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.z, v.y, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xzyy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.z, v.y, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xzyz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.z, v.y, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xzyw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.z, v.y, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xzzx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.z, v.z, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xzzy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.z, v.z, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xzzz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.z, v.z, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xzzw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.z, v.z, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xzwx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.z, v.w, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xzwy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.z, v.w, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xzwz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.z, v.w, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xzww(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.z, v.w, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xwxx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.w, v.x, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xwxy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.w, v.x, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xwxz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.w, v.x, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xwxw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.w, v.x, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xwyx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.w, v.y, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xwyy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.w, v.y, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xwyz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.w, v.y, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xwyw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.w, v.y, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xwzx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.w, v.z, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xwzy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.w, v.z, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xwzz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.w, v.z, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xwzw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.w, v.z, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xwwx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.w, v.w, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xwwy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.w, v.w, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xwwz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.w, v.w, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> xwww(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.x, v.w, v.w, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yxxx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.x, v.x, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yxxy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.x, v.x, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yxxz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.x, v.x, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yxxw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.x, v.x, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yxyx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.x, v.y, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yxyy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.x, v.y, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yxyz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.x, v.y, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yxyw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.x, v.y, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yxzx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.x, v.z, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yxzy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.x, v.z, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yxzz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.x, v.z, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yxzw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.x, v.z, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yxwx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.x, v.w, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yxwy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.x, v.w, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yxwz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.x, v.w, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yxww(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.x, v.w, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yyxx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.y, v.x, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yyxy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.y, v.x, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yyxz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.y, v.x, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yyxw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.y, v.x, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yyyx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.y, v.y, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yyyy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.y, v.y, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yyyz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.y, v.y, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yyyw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.y, v.y, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yyzx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.y, v.z, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yyzy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.y, v.z, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yyzz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.y, v.z, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yyzw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.y, v.z, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yywx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.y, v.w, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yywy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.y, v.w, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yywz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.y, v.w, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yyww(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.y, v.w, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yzxx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.z, v.x, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yzxy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.z, v.x, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yzxz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.z, v.x, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yzxw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.z, v.x, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yzyx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.z, v.y, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yzyy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.z, v.y, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yzyz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.z, v.y, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yzyw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.z, v.y, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yzzx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.z, v.z, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yzzy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.z, v.z, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yzzz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.z, v.z, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yzzw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.z, v.z, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yzwx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.z, v.w, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yzwy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.z, v.w, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yzwz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.z, v.w, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> yzww(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.z, v.w, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> ywxx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.w, v.x, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> ywxy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.w, v.x, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> ywxz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.w, v.x, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> ywxw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.w, v.x, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> ywyx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.w, v.y, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> ywyy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.w, v.y, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> ywyz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.w, v.y, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> ywyw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.w, v.y, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> ywzx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.w, v.z, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> ywzy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.w, v.z, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> ywzz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.w, v.z, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> ywzw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.w, v.z, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> ywwx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.w, v.w, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> ywwy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.w, v.w, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> ywwz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.w, v.w, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> ywww(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.y, v.w, v.w, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zxxx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.x, v.x, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zxxy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.x, v.x, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zxxz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.x, v.x, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zxxw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.x, v.x, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zxyx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.x, v.y, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zxyy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.x, v.y, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zxyz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.x, v.y, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zxyw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.x, v.y, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zxzx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.x, v.z, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zxzy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.x, v.z, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zxzz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.x, v.z, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zxzw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.x, v.z, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zxwx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.x, v.w, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zxwy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.x, v.w, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zxwz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.x, v.w, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zxww(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.x, v.w, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zyxx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.y, v.x, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zyxy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.y, v.x, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zyxz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.y, v.x, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zyxw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.y, v.x, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zyyx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.y, v.y, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zyyy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.y, v.y, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zyyz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.y, v.y, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zyyw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.y, v.y, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zyzx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.y, v.z, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zyzy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.y, v.z, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zyzz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.y, v.z, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zyzw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.y, v.z, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zywx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.y, v.w, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zywy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.y, v.w, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zywz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.y, v.w, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zyww(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.y, v.w, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zzxx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.z, v.x, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zzxy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.z, v.x, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zzxz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.z, v.x, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zzxw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.z, v.x, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zzyx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.z, v.y, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zzyy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.z, v.y, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zzyz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.z, v.y, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zzyw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.z, v.y, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zzzx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.z, v.z, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zzzy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.z, v.z, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zzzz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.z, v.z, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zzzw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.z, v.z, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zzwx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.z, v.w, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zzwy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.z, v.w, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zzwz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.z, v.w, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zzww(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.z, v.w, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zwxx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.w, v.x, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zwxy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.w, v.x, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zwxz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.w, v.x, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zwxw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.w, v.x, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zwyx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.w, v.y, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zwyy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.w, v.y, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zwyz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.w, v.y, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zwyw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.w, v.y, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zwzx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.w, v.z, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zwzy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.w, v.z, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zwzz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.w, v.z, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zwzw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.w, v.z, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zwwx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.w, v.w, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zwwy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.w, v.w, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zwwz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.w, v.w, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> zwww(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.z, v.w, v.w, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wxxx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.x, v.x, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wxxy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.x, v.x, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wxxz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.x, v.x, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wxxw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.x, v.x, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wxyx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.x, v.y, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wxyy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.x, v.y, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wxyz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.x, v.y, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wxyw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.x, v.y, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wxzx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.x, v.z, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wxzy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.x, v.z, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wxzz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.x, v.z, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wxzw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.x, v.z, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wxwx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.x, v.w, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wxwy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.x, v.w, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wxwz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.x, v.w, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wxww(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.x, v.w, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wyxx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.y, v.x, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wyxy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.y, v.x, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wyxz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.y, v.x, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wyxw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.y, v.x, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wyyx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.y, v.y, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wyyy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.y, v.y, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wyyz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.y, v.y, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wyyw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.y, v.y, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wyzx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.y, v.z, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wyzy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.y, v.z, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wyzz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.y, v.z, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wyzw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.y, v.z, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wywx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.y, v.w, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wywy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.y, v.w, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wywz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.y, v.w, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wyww(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.y, v.w, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wzxx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.z, v.x, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wzxy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.z, v.x, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wzxz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.z, v.x, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wzxw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.z, v.x, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wzyx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.z, v.y, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wzyy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.z, v.y, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wzyz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.z, v.y, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wzyw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.z, v.y, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wzzx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.z, v.z, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wzzy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.z, v.z, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wzzz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.z, v.z, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wzzw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.z, v.z, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wzwx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.z, v.w, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wzwy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.z, v.w, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wzwz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.z, v.w, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wzww(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.z, v.w, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wwxx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.w, v.x, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wwxy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.w, v.x, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wwxz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.w, v.x, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wwxw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.w, v.x, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wwyx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.w, v.y, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wwyy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.w, v.y, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wwyz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.w, v.y, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wwyw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.w, v.y, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wwzx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.w, v.z, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wwzy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.w, v.z, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wwzz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.w, v.z, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wwzw(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.w, v.z, v.w); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wwwx(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.w, v.w, v.x); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wwwy(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.w, v.w, v.y); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wwwz(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.w, v.w, v.z); }
	template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<4, T, Q> wwww(vec<4, T, Q> const& v) { return vec<4, T, Q>(v.w, v.w, v.w, v.w); }

	/// @}
}//namespace glm
