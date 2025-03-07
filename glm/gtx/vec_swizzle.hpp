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

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<2, T, Q> xx(glm::vec<L, T, Q> const& v) {
		return glm::vec<2, T, Q>(v.x, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<2, T, Q> xy(glm::vec<L, T, Q> const& v) {
		return glm::vec<2, T, Q>(v.x, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<2, T, Q> xz(glm::vec<L, T, Q> const& v) {
		return glm::vec<2, T, Q>(v.x, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<2, T, Q> xw(glm::vec<L, T, Q> const& v) {
		return glm::vec<2, T, Q>(v.x, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<2, T, Q> yx(glm::vec<L, T, Q> const& v) {
		return glm::vec<2, T, Q>(v.y, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<2, T, Q> yy(glm::vec<L, T, Q> const& v) {
		return glm::vec<2, T, Q>(v.y, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<2, T, Q> yz(glm::vec<L, T, Q> const& v) {
		return glm::vec<2, T, Q>(v.y, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<2, T, Q> yw(glm::vec<L, T, Q> const& v) {
		return glm::vec<2, T, Q>(v.y, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<2, T, Q> zx(glm::vec<L, T, Q> const& v) {
		return glm::vec<2, T, Q>(v.z, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<2, T, Q> zy(glm::vec<L, T, Q> const& v) {
		return glm::vec<2, T, Q>(v.z, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<2, T, Q> zz(glm::vec<L, T, Q> const& v) {
		return glm::vec<2, T, Q>(v.z, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<2, T, Q> zw(glm::vec<L, T, Q> const& v) {
		return glm::vec<2, T, Q>(v.z, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<2, T, Q> wx(glm::vec<L, T, Q> const& v) {
		return glm::vec<2, T, Q>(v.w, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<2, T, Q> wy(glm::vec<L, T, Q> const& v) {
		return glm::vec<2, T, Q>(v.w, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<2, T, Q> wz(glm::vec<L, T, Q> const& v) {
		return glm::vec<2, T, Q>(v.w, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<2, T, Q> ww(glm::vec<L, T, Q> const& v) {
		return glm::vec<2, T, Q>(v.w, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> xxx(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.x, v.x, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> xxy(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.x, v.x, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> xxz(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.x, v.x, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> xxw(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.x, v.x, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> xyx(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.x, v.y, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> xyy(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.x, v.y, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> xyz(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.x, v.y, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> xyw(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.x, v.y, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> xzx(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.x, v.z, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> xzy(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.x, v.z, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> xzz(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.x, v.z, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> xzw(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.x, v.z, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> xwx(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.x, v.w, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> xwy(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.x, v.w, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> xwz(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.x, v.w, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> xww(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.x, v.w, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> yxx(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.y, v.x, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> yxy(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.y, v.x, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> yxz(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.y, v.x, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> yxw(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.y, v.x, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> yyx(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.y, v.y, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> yyy(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.y, v.y, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> yyz(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.y, v.y, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> yyw(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.y, v.y, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> yzx(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.y, v.z, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> yzy(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.y, v.z, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> yzz(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.y, v.z, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> yzw(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.y, v.z, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> ywx(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.y, v.w, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> ywy(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.y, v.w, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> ywz(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.y, v.w, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> yww(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.y, v.w, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> zxx(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.z, v.x, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> zxy(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.z, v.x, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> zxz(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.z, v.x, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> zxw(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.z, v.x, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> zyx(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.z, v.y, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> zyy(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.z, v.y, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> zyz(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.z, v.y, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> zyw(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.z, v.y, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> zzx(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.z, v.z, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> zzy(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.z, v.z, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> zzz(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.z, v.z, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> zzw(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.z, v.z, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> zwx(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.z, v.w, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> zwy(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.z, v.w, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> zwz(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.z, v.w, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> zww(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.z, v.w, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> wxx(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.w, v.x, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> wxy(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.w, v.x, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> wxz(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.w, v.x, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> wxw(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.w, v.x, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> wyx(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.w, v.y, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> wyy(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.w, v.y, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> wyz(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.w, v.y, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> wyw(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.w, v.y, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> wzx(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.w, v.z, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> wzy(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.w, v.z, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> wzz(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.w, v.z, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> wzw(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.w, v.z, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> wwx(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.w, v.w, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> wwy(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.w, v.w, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> wwz(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.w, v.w, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<3, T, Q> www(glm::vec<L, T, Q> const& v) {
		return glm::vec<3, T, Q>(v.w, v.w, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xxxx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.x, v.x, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xxxy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.x, v.x, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xxxz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.x, v.x, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xxxw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.x, v.x, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xxyx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.x, v.y, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xxyy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.x, v.y, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xxyz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.x, v.y, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xxyw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.x, v.y, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xxzx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.x, v.z, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xxzy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.x, v.z, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xxzz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.x, v.z, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xxzw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.x, v.z, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xxwx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.x, v.w, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xxwy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.x, v.w, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xxwz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.x, v.w, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xxww(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.x, v.w, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xyxx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.y, v.x, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xyxy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.y, v.x, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xyxz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.y, v.x, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xyxw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.y, v.x, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xyyx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.y, v.y, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xyyy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.y, v.y, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xyyz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.y, v.y, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xyyw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.y, v.y, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xyzx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.y, v.z, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xyzy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.y, v.z, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xyzz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.y, v.z, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xyzw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.y, v.z, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xywx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.y, v.w, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xywy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.y, v.w, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xywz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.y, v.w, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xyww(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.y, v.w, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xzxx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.z, v.x, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xzxy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.z, v.x, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xzxz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.z, v.x, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xzxw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.z, v.x, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xzyx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.z, v.y, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xzyy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.z, v.y, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xzyz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.z, v.y, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xzyw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.z, v.y, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xzzx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.z, v.z, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xzzy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.z, v.z, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xzzz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.z, v.z, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xzzw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.z, v.z, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xzwx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.z, v.w, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xzwy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.z, v.w, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xzwz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.z, v.w, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xzww(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.z, v.w, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xwxx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.w, v.x, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xwxy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.w, v.x, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xwxz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.w, v.x, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xwxw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.w, v.x, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xwyx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.w, v.y, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xwyy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.w, v.y, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xwyz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.w, v.y, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xwyw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.w, v.y, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xwzx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.w, v.z, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xwzy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.w, v.z, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xwzz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.w, v.z, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xwzw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.w, v.z, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xwwx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.w, v.w, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xwwy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.w, v.w, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xwwz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.w, v.w, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> xwww(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.x, v.w, v.w, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yxxx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.x, v.x, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yxxy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.x, v.x, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yxxz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.x, v.x, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yxxw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.x, v.x, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yxyx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.x, v.y, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yxyy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.x, v.y, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yxyz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.x, v.y, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yxyw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.x, v.y, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yxzx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.x, v.z, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yxzy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.x, v.z, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yxzz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.x, v.z, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yxzw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.x, v.z, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yxwx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.x, v.w, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yxwy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.x, v.w, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yxwz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.x, v.w, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yxww(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.x, v.w, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yyxx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.y, v.x, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yyxy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.y, v.x, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yyxz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.y, v.x, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yyxw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.y, v.x, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yyyx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.y, v.y, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yyyy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.y, v.y, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yyyz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.y, v.y, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yyyw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.y, v.y, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yyzx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.y, v.z, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yyzy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.y, v.z, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yyzz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.y, v.z, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yyzw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.y, v.z, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yywx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.y, v.w, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yywy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.y, v.w, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yywz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.y, v.w, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yyww(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.y, v.w, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yzxx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.z, v.x, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yzxy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.z, v.x, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yzxz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.z, v.x, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yzxw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.z, v.x, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yzyx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.z, v.y, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yzyy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.z, v.y, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yzyz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.z, v.y, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yzyw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.z, v.y, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yzzx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.z, v.z, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yzzy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.z, v.z, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yzzz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.z, v.z, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yzzw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.z, v.z, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yzwx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.z, v.w, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yzwy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.z, v.w, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yzwz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.z, v.w, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> yzww(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.z, v.w, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> ywxx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.w, v.x, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> ywxy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.w, v.x, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> ywxz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.w, v.x, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> ywxw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.w, v.x, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> ywyx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.w, v.y, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> ywyy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.w, v.y, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> ywyz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.w, v.y, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> ywyw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.w, v.y, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> ywzx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.w, v.z, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> ywzy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.w, v.z, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> ywzz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.w, v.z, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> ywzw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.w, v.z, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> ywwx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.w, v.w, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> ywwy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.w, v.w, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> ywwz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.w, v.w, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> ywww(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.y, v.w, v.w, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zxxx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.x, v.x, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zxxy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.x, v.x, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zxxz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.x, v.x, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zxxw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.x, v.x, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zxyx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.x, v.y, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zxyy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.x, v.y, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zxyz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.x, v.y, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zxyw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.x, v.y, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zxzx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.x, v.z, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zxzy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.x, v.z, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zxzz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.x, v.z, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zxzw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.x, v.z, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zxwx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.x, v.w, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zxwy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.x, v.w, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zxwz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.x, v.w, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zxww(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.x, v.w, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zyxx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.y, v.x, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zyxy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.y, v.x, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zyxz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.y, v.x, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zyxw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.y, v.x, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zyyx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.y, v.y, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zyyy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.y, v.y, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zyyz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.y, v.y, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zyyw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.y, v.y, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zyzx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.y, v.z, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zyzy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.y, v.z, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zyzz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.y, v.z, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zyzw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.y, v.z, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zywx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.y, v.w, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zywy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.y, v.w, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zywz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.y, v.w, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zyww(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.y, v.w, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zzxx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.z, v.x, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zzxy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.z, v.x, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zzxz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.z, v.x, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zzxw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.z, v.x, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zzyx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.z, v.y, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zzyy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.z, v.y, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zzyz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.z, v.y, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zzyw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.z, v.y, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zzzx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.z, v.z, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zzzy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.z, v.z, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zzzz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.z, v.z, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zzzw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.z, v.z, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zzwx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.z, v.w, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zzwy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.z, v.w, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zzwz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.z, v.w, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zzww(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.z, v.w, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zwxx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.w, v.x, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zwxy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.w, v.x, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zwxz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.w, v.x, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zwxw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.w, v.x, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zwyx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.w, v.y, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zwyy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.w, v.y, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zwyz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.w, v.y, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zwyw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.w, v.y, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zwzx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.w, v.z, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zwzy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.w, v.z, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zwzz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.w, v.z, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zwzw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.w, v.z, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zwwx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.w, v.w, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zwwy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.w, v.w, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zwwz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.w, v.w, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> zwww(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.z, v.w, v.w, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wxxx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.x, v.x, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wxxy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.x, v.x, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wxxz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.x, v.x, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wxxw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.x, v.x, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wxyx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.x, v.y, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wxyy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.x, v.y, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wxyz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.x, v.y, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wxyw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.x, v.y, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wxzx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.x, v.z, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wxzy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.x, v.z, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wxzz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.x, v.z, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wxzw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.x, v.z, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wxwx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.x, v.w, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wxwy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.x, v.w, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wxwz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.x, v.w, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wxww(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.x, v.w, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wyxx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.y, v.x, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wyxy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.y, v.x, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wyxz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.y, v.x, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wyxw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.y, v.x, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wyyx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.y, v.y, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wyyy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.y, v.y, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wyyz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.y, v.y, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wyyw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.y, v.y, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wyzx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.y, v.z, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wyzy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.y, v.z, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wyzz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.y, v.z, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wyzw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.y, v.z, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wywx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.y, v.w, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wywy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.y, v.w, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wywz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.y, v.w, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wyww(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.y, v.w, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wzxx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.z, v.x, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wzxy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.z, v.x, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wzxz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.z, v.x, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wzxw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.z, v.x, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wzyx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.z, v.y, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wzyy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.z, v.y, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wzyz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.z, v.y, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wzyw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.z, v.y, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wzzx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.z, v.z, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wzzy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.z, v.z, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wzzz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.z, v.z, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wzzw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.z, v.z, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wzwx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.z, v.w, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wzwy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.z, v.w, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wzwz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.z, v.w, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wzww(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.z, v.w, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wwxx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.w, v.x, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wwxy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.w, v.x, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wwxz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.w, v.x, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wwxw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.w, v.x, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wwyx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.w, v.y, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wwyy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.w, v.y, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wwyz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.w, v.y, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wwyw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.w, v.y, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wwzx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.w, v.z, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wwzy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.w, v.z, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wwzz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.w, v.z, v.z);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wwzw(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.w, v.z, v.w);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wwwx(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.w, v.w, v.x);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wwwy(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.w, v.w, v.y);
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wwwz(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.w, v.w, v.z);
	}

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<4, T, Q> wwww(glm::vec<L, T, Q> const& v) {
		return glm::vec<4, T, Q>(v.w, v.w, v.w, v.w);
	}


	/// @}
}//namespace glm
