/// @ref gtc_type_aligned
/// @file glm/gtc/type_aligned.hpp
///
/// @see core (dependence)
///
/// @defgroup gtc_type_aligned GLM_GTC_type_aligned
/// @ingroup gtc
///
/// Include <glm/gtc/type_aligned.hpp> to use the features of this extension.
///
/// Aligned types allowing SIMD optimizations of vectors and matrices types

#pragma once

#if (GLM_CONFIG_ALIGNED_GENTYPES == GLM_DISABLE)
#	error "GLM: Aligned gentypes require to enable C++ language extensions. Define GLM_FORCE_ALIGNED_GENTYPES before including GLM headers to use aligned types."
#endif

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
# pragma message("GLM: GLM_GTC_type_aligned extension included")
#endif

#include "../mat4x4.hpp"
#include "../mat4x3.hpp"
#include "../mat4x2.hpp"
#include "../mat3x4.hpp"
#include "../mat3x3.hpp"
#include "../mat3x2.hpp"
#include "../mat2x4.hpp"
#include "../mat2x3.hpp"
#include "../mat2x2.hpp"
#include "../gtc/quaternion.hpp"
#include "../gtc/vec1.hpp"
#include "../vec2.hpp"
#include "../vec3.hpp"
#include "../vec4.hpp"

namespace glm
{
	/// @addtogroup gtc_type_aligned
	/// @{

	// -- *vec1 --

	/// 1 component vector aligned in memory of single-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using	aligned_highp_vec1 = vec<1, float, aligned_highp>;

	/// 1 component vector aligned in memory of single-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	aligned_mediump_vec1 = vec<1, float, aligned_mediump>;

	/// 1 component vector aligned in memory of single-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		aligned_lowp_vec1 = vec<1, float, aligned_lowp>;

	/// 1 component vector aligned in memory of double-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using	aligned_highp_dvec1 = vec<1, double, aligned_highp>;

	/// 1 component vector aligned in memory of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	aligned_mediump_dvec1 = vec<1, double, aligned_mediump>;

	/// 1 component vector aligned in memory of double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using	aligned_lowp_dvec1 = vec<1, double, aligned_lowp>;

	/// 1 component vector aligned in memory of signed integer numbers.
	using		aligned_highp_ivec1 = vec<1, int, aligned_highp>;

	/// 1 component vector aligned in memory of signed integer numbers.
	using	aligned_mediump_ivec1 = vec<1, int, aligned_mediump>;

	/// 1 component vector aligned in memory of signed integer numbers.
	using		aligned_lowp_ivec1 = vec<1, int, aligned_lowp>;

	/// 1 component vector aligned in memory of unsigned integer numbers.
	using		aligned_highp_uvec1 = vec<1, uint, aligned_highp>;

	/// 1 component vector aligned in memory of unsigned integer numbers.
	using	aligned_mediump_uvec1 = vec<1, uint, aligned_mediump>;

	/// 1 component vector aligned in memory of unsigned integer numbers.
	using		aligned_lowp_uvec1 = vec<1, uint, aligned_lowp>;

	/// 1 component vector aligned in memory of bool values.
	using		aligned_highp_bvec1 = vec<1, bool, aligned_highp>;

	/// 1 component vector aligned in memory of bool values.
	using	aligned_mediump_bvec1 = vec<1, bool, aligned_mediump>;

	/// 1 component vector aligned in memory of bool values.
	using		aligned_lowp_bvec1 = vec<1, bool, aligned_lowp>;

	/// 1 component vector tightly packed in memory of single-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		packed_highp_vec1 = vec<1, float, packed_highp>;

	/// 1 component vector tightly packed in memory of single-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	packed_mediump_vec1 = vec<1, float, packed_mediump>;

	/// 1 component vector tightly packed in memory of single-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		packed_lowp_vec1 = vec<1, float, packed_lowp>;

	/// 1 component vector tightly packed in memory of double-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using	packed_highp_dvec1 = vec<1, double, packed_highp>;

	/// 1 component vector tightly packed in memory of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	packed_mediump_dvec1 = vec<1, double, packed_mediump>;

	/// 1 component vector tightly packed in memory of double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		packed_lowp_dvec1 = vec<1, double, packed_lowp>;

	/// 1 component vector tightly packed in memory of signed integer numbers.
	using		packed_highp_ivec1 = vec<1, int, packed_highp>;

	/// 1 component vector tightly packed in memory of signed integer numbers.
	using		packed_mediump_ivec1 = vec<1, int, packed_mediump>;

	/// 1 component vector tightly packed in memory of signed integer numbers.
	using		packed_lowp_ivec1 = vec<1, int, packed_lowp>;

	/// 1 component vector tightly packed in memory of unsigned integer numbers.
	using		packed_highp_uvec1 = vec<1, uint, packed_highp>;

	/// 1 component vector tightly packed in memory of unsigned integer numbers.
	using	packed_mediump_uvec1 = vec<1, uint, packed_mediump>;

	/// 1 component vector tightly packed in memory of unsigned integer numbers.
	using		packed_lowp_uvec1 = vec<1, uint, packed_lowp>;

	/// 1 component vector tightly packed in memory of bool values.
	using		packed_highp_bvec1 = vec<1, bool, packed_highp>;

	/// 1 component vector tightly packed in memory of bool values.
	using	packed_mediump_bvec1 = vec<1, bool, packed_mediump>;

	/// 1 component vector tightly packed in memory of bool values.
	using		packed_lowp_bvec1 = vec<1, bool, packed_lowp>;

	// -- *vec2 --

	/// 2 components vector aligned in memory of single-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using	aligned_highp_vec2 = vec<2, float, aligned_highp>;

	/// 2 components vector aligned in memory of single-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	aligned_mediump_vec2 = vec<2, float, aligned_mediump>;

	/// 2 components vector aligned in memory of single-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		aligned_lowp_vec2 = vec<2, float, aligned_lowp>;

	/// 2 components vector aligned in memory of double-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using	aligned_highp_dvec2 = vec<2, double, aligned_highp>;

	/// 2 components vector aligned in memory of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	aligned_mediump_dvec2 = vec<2, double, aligned_mediump>;

	/// 2 components vector aligned in memory of double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using	aligned_lowp_dvec2 = vec<2, double, aligned_lowp>;

	/// 2 components vector aligned in memory of signed integer numbers.
	using		aligned_highp_ivec2 = vec<2, int, aligned_highp>;

	/// 2 components vector aligned in memory of signed integer numbers.
	using	aligned_mediump_ivec2 = vec<2, int, aligned_mediump>;

	/// 2 components vector aligned in memory of signed integer numbers.
	using		aligned_lowp_ivec2 = vec<2, int, aligned_lowp>;

	/// 2 components vector aligned in memory of unsigned integer numbers.
	using		aligned_highp_uvec2 = vec<2, uint, aligned_highp>;

	/// 2 components vector aligned in memory of unsigned integer numbers.
	using	aligned_mediump_uvec2 = vec<2, uint, aligned_mediump>;

	/// 2 components vector aligned in memory of unsigned integer numbers.
	using		aligned_lowp_uvec2 = vec<2, uint, aligned_lowp>;

	/// 2 components vector aligned in memory of bool values.
	using		aligned_highp_bvec2 = vec<2, bool, aligned_highp>;

	/// 2 components vector aligned in memory of bool values.
	using	aligned_mediump_bvec2 = vec<2, bool, aligned_mediump>;

	/// 2 components vector aligned in memory of bool values.
	using		aligned_lowp_bvec2 = vec<2, bool, aligned_lowp>;

	/// 2 components vector tightly packed in memory of single-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		packed_highp_vec2 = vec<2, float, packed_highp>;

	/// 2 components vector tightly packed in memory of single-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	packed_mediump_vec2 = vec<2, float, packed_mediump>;

	/// 2 components vector tightly packed in memory of single-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		packed_lowp_vec2 = vec<2, float, packed_lowp>;

	/// 2 components vector tightly packed in memory of double-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using	packed_highp_dvec2 = vec<2, double, packed_highp>;

	/// 2 components vector tightly packed in memory of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	packed_mediump_dvec2 = vec<2, double, packed_mediump>;

	/// 2 components vector tightly packed in memory of double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		packed_lowp_dvec2 = vec<2, double, packed_lowp>;

	/// 2 components vector tightly packed in memory of signed integer numbers.
	using		packed_highp_ivec2 = vec<2, int, packed_highp>;

	/// 2 components vector tightly packed in memory of signed integer numbers.
	using		packed_mediump_ivec2 = vec<2, int, packed_mediump>;

	/// 2 components vector tightly packed in memory of signed integer numbers.
	using		packed_lowp_ivec2 = vec<2, int, packed_lowp>;

	/// 2 components vector tightly packed in memory of unsigned integer numbers.
	using		packed_highp_uvec2 = vec<2, uint, packed_highp>;

	/// 2 components vector tightly packed in memory of unsigned integer numbers.
	using	packed_mediump_uvec2 = vec<2, uint, packed_mediump>;

	/// 2 components vector tightly packed in memory of unsigned integer numbers.
	using		packed_lowp_uvec2 = vec<2, uint, packed_lowp>;

	/// 2 components vector tightly packed in memory of bool values.
	using		packed_highp_bvec2 = vec<2, bool, packed_highp>;

	/// 2 components vector tightly packed in memory of bool values.
	using	packed_mediump_bvec2 = vec<2, bool, packed_mediump>;

	/// 2 components vector tightly packed in memory of bool values.
	using		packed_lowp_bvec2 = vec<2, bool, packed_lowp>;

	// -- *vec3 --

	/// 3 components vector aligned in memory of single-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using	aligned_highp_vec3 = vec<3, float, aligned_highp>;

	/// 3 components vector aligned in memory of single-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	aligned_mediump_vec3 = vec<3, float, aligned_mediump>;

	/// 3 components vector aligned in memory of single-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		aligned_lowp_vec3 = vec<3, float, aligned_lowp>;

	/// 3 components vector aligned in memory of double-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using	aligned_highp_dvec3 = vec<3, double, aligned_highp>;

	/// 3 components vector aligned in memory of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	aligned_mediump_dvec3 = vec<3, double, aligned_mediump>;

	/// 3 components vector aligned in memory of double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using	aligned_lowp_dvec3 = vec<3, double, aligned_lowp>;

	/// 3 components vector aligned in memory of signed integer numbers.
	using		aligned_highp_ivec3 = vec<3, int, aligned_highp>;

	/// 3 components vector aligned in memory of signed integer numbers.
	using	aligned_mediump_ivec3 = vec<3, int, aligned_mediump>;

	/// 3 components vector aligned in memory of signed integer numbers.
	using		aligned_lowp_ivec3 = vec<3, int, aligned_lowp>;

	/// 3 components vector aligned in memory of unsigned integer numbers.
	using		aligned_highp_uvec3 = vec<3, uint, aligned_highp>;

	/// 3 components vector aligned in memory of unsigned integer numbers.
	using	aligned_mediump_uvec3 = vec<3, uint, aligned_mediump>;

	/// 3 components vector aligned in memory of unsigned integer numbers.
	using		aligned_lowp_uvec3 = vec<3, uint, aligned_lowp>;

	/// 3 components vector aligned in memory of bool values.
	using		aligned_highp_bvec3 = vec<3, bool, aligned_highp>;

	/// 3 components vector aligned in memory of bool values.
	using	aligned_mediump_bvec3 = vec<3, bool, aligned_mediump>;

	/// 3 components vector aligned in memory of bool values.
	using		aligned_lowp_bvec3 = vec<3, bool, aligned_lowp>;

	/// 3 components vector tightly packed in memory of single-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		packed_highp_vec3 = vec<3, float, packed_highp>;

	/// 3 components vector tightly packed in memory of single-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	packed_mediump_vec3 = vec<3, float, packed_mediump>;

	/// 3 components vector tightly packed in memory of single-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		packed_lowp_vec3 = vec<3, float, packed_lowp>;

	/// 3 components vector tightly packed in memory of double-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using	packed_highp_dvec3 = vec<3, double, packed_highp>;

	/// 3 components vector tightly packed in memory of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	packed_mediump_dvec3 = vec<3, double, packed_mediump>;

	/// 3 components vector tightly packed in memory of double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		packed_lowp_dvec3 = vec<3, double, packed_lowp>;

	/// 3 components vector tightly packed in memory of signed integer numbers.
	using		packed_highp_ivec3 = vec<3, int, packed_highp>;

	/// 3 components vector tightly packed in memory of signed integer numbers.
	using		packed_mediump_ivec3 = vec<3, int, packed_mediump>;

	/// 3 components vector tightly packed in memory of signed integer numbers.
	using		packed_lowp_ivec3 = vec<3, int, packed_lowp>;

	/// 3 components vector tightly packed in memory of unsigned integer numbers.
	using		packed_highp_uvec3 = vec<3, uint, packed_highp>;

	/// 3 components vector tightly packed in memory of unsigned integer numbers.
	using	packed_mediump_uvec3 = vec<3, uint, packed_mediump>;

	/// 3 components vector tightly packed in memory of unsigned integer numbers.
	using		packed_lowp_uvec3 = vec<3, uint, packed_lowp>;

	/// 3 components vector tightly packed in memory of bool values.
	using		packed_highp_bvec3 = vec<3, bool, packed_highp>;

	/// 3 components vector tightly packed in memory of bool values.
	using	packed_mediump_bvec3 = vec<3, bool, packed_mediump>;

	/// 3 components vector tightly packed in memory of bool values.
	using		packed_lowp_bvec3 = vec<3, bool, packed_lowp>;

	// -- *vec4 --

	/// 4 components vector aligned in memory of single-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using	aligned_highp_vec4 = vec<4, float, aligned_highp>;

	/// 4 components vector aligned in memory of single-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	aligned_mediump_vec4 = vec<4, float, aligned_mediump>;

	/// 4 components vector aligned in memory of single-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		aligned_lowp_vec4 = vec<4, float, aligned_lowp>;

	/// 4 components vector aligned in memory of double-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using	aligned_highp_dvec4 = vec<4, double, aligned_highp>;

	/// 4 components vector aligned in memory of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	aligned_mediump_dvec4 = vec<4, double, aligned_mediump>;

	/// 4 components vector aligned in memory of double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using	aligned_lowp_dvec4 = vec<4, double, aligned_lowp>;

	/// 4 components vector aligned in memory of signed integer numbers.
	using		aligned_highp_ivec4 = vec<4, int, aligned_highp>;

	/// 4 components vector aligned in memory of signed integer numbers.
	using	aligned_mediump_ivec4 = vec<4, int, aligned_mediump>;

	/// 4 components vector aligned in memory of signed integer numbers.
	using		aligned_lowp_ivec4 = vec<4, int, aligned_lowp>;

	/// 4 components vector aligned in memory of unsigned integer numbers.
	using		aligned_highp_uvec4 = vec<4, uint, aligned_highp>;

	/// 4 components vector aligned in memory of unsigned integer numbers.
	using	aligned_mediump_uvec4 = vec<4, uint, aligned_mediump>;

	/// 4 components vector aligned in memory of unsigned integer numbers.
	using		aligned_lowp_uvec4 = vec<4, uint, aligned_lowp>;

	/// 4 components vector aligned in memory of bool values.
	using		aligned_highp_bvec4 = vec<4, bool, aligned_highp>;

	/// 4 components vector aligned in memory of bool values.
	using	aligned_mediump_bvec4 = vec<4, bool, aligned_mediump>;

	/// 4 components vector aligned in memory of bool values.
	using		aligned_lowp_bvec4 = vec<4, bool, aligned_lowp>;

	/// 4 components vector tightly packed in memory of single-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		packed_highp_vec4 = vec<4, float, packed_highp>;

	/// 4 components vector tightly packed in memory of single-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	packed_mediump_vec4 = vec<4, float, packed_mediump>;

	/// 4 components vector tightly packed in memory of single-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		packed_lowp_vec4 = vec<4, float, packed_lowp>;

	/// 4 components vector tightly packed in memory of double-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using	packed_highp_dvec4 = vec<4, double, packed_highp>;

	/// 4 components vector tightly packed in memory of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	packed_mediump_dvec4 = vec<4, double, packed_mediump>;

	/// 4 components vector tightly packed in memory of double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		packed_lowp_dvec4 = vec<4, double, packed_lowp>;

	/// 4 components vector tightly packed in memory of signed integer numbers.
	using		packed_highp_ivec4 = vec<4, int, packed_highp>;

	/// 4 components vector tightly packed in memory of signed integer numbers.
	using		packed_mediump_ivec4 = vec<4, int, packed_mediump>;

	/// 4 components vector tightly packed in memory of signed integer numbers.
	using		packed_lowp_ivec4 = vec<4, int, packed_lowp>;

	/// 4 components vector tightly packed in memory of unsigned integer numbers.
	using		packed_highp_uvec4 = vec<4, uint, packed_highp>;

	/// 4 components vector tightly packed in memory of unsigned integer numbers.
	using	packed_mediump_uvec4 = vec<4, uint, packed_mediump>;

	/// 4 components vector tightly packed in memory of unsigned integer numbers.
	using		packed_lowp_uvec4 = vec<4, uint, packed_lowp>;

	/// 4 components vector tightly packed in memory of bool values.
	using		packed_highp_bvec4 = vec<4, bool, packed_highp>;

	/// 4 components vector tightly packed in memory of bool values.
	using	packed_mediump_bvec4 = vec<4, bool, packed_mediump>;

	/// 4 components vector tightly packed in memory of bool values.
	using		packed_lowp_bvec4 = vec<4, bool, packed_lowp>;

	// -- *mat2 --

	/// 2 by 2 matrix aligned in memory of single-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		aligned_highp_mat2 = mat<2, 2, float, aligned_highp>;

	/// 2 by 2 matrix aligned in memory of single-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	aligned_mediump_mat2 = mat<2, 2, float, aligned_mediump>;

	/// 2 by 2 matrix aligned in memory of single-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		aligned_lowp_mat2 = mat<2, 2, float, aligned_lowp>;

	/// 2 by 2 matrix aligned in memory of double-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using	aligned_highp_dmat2 = mat<2, 2, double, aligned_highp>;

	/// 2 by 2 matrix aligned in memory of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	aligned_mediump_dmat2 = mat<2, 2, double, aligned_mediump>;

	/// 2 by 2 matrix aligned in memory of double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		aligned_lowp_dmat2 = mat<2, 2, double, aligned_lowp>;

	/// 2 by 2 matrix tightly packed in memory of single-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		packed_highp_mat2 = mat<2, 2, float, packed_highp>;

	/// 2 by 2 matrix tightly packed in memory of single-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	packed_mediump_mat2 = mat<2, 2, float, packed_mediump>;

	/// 2 by 2 matrix tightly packed in memory of single-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		packed_lowp_mat2 = mat<2, 2, float, packed_lowp>;

	/// 2 by 2 matrix tightly packed in memory of double-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		packed_highp_dmat2 = mat<2, 2, double, packed_highp>;

	/// 2 by 2 matrix tightly packed in memory of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	packed_mediump_dmat2 = mat<2, 2, double, packed_mediump>;

	/// 2 by 2 matrix tightly packed in memory of double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		packed_lowp_dmat2 = mat<2, 2, double, packed_lowp>;

	// -- *mat3 --

	/// 3 by 3 matrix aligned in memory of single-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		aligned_highp_mat3 = mat<3, 3, float, aligned_highp>;

	/// 3 by 3 matrix aligned in memory of single-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	aligned_mediump_mat3 = mat<3, 3, float, aligned_mediump>;

	/// 3 by 3 matrix aligned in memory of single-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		aligned_lowp_mat3 = mat<3, 3, float, aligned_lowp>;

	/// 3 by 3 matrix aligned in memory of double-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using	aligned_highp_dmat3 = mat<3, 3, double, aligned_highp>;

	/// 3 by 3 matrix aligned in memory of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	aligned_mediump_dmat3 = mat<3, 3, double, aligned_mediump>;

	/// 3 by 3 matrix aligned in memory of double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		aligned_lowp_dmat3 = mat<3, 3, double, aligned_lowp>;

	/// 3 by 3 matrix tightly packed in memory of single-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		packed_highp_mat3 = mat<3, 3, float, packed_highp>;

	/// 3 by 3 matrix tightly packed in memory of single-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	packed_mediump_mat3 = mat<3, 3, float, packed_mediump>;

	/// 3 by 3 matrix tightly packed in memory of single-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		packed_lowp_mat3 = mat<3, 3, float, packed_lowp>;

	/// 3 by 3 matrix tightly packed in memory of double-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		packed_highp_dmat3 = mat<3, 3, double, packed_highp>;

	/// 3 by 3 matrix tightly packed in memory of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	packed_mediump_dmat3 = mat<3, 3, double, packed_mediump>;

	/// 3 by 3 matrix tightly packed in memory of double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		packed_lowp_dmat3 = mat<3, 3, double, packed_lowp>;

	// -- *mat4 --

	/// 4 by 4 matrix aligned in memory of single-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		aligned_highp_mat4 = mat<4, 4, float, aligned_highp>;

	/// 4 by 4 matrix aligned in memory of single-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	aligned_mediump_mat4 = mat<4, 4, float, aligned_mediump>;

	/// 4 by 4 matrix aligned in memory of single-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		aligned_lowp_mat4 = mat<4, 4, float, aligned_lowp>;

	/// 4 by 4 matrix aligned in memory of double-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using	aligned_highp_dmat4 = mat<4, 4, double, aligned_highp>;

	/// 4 by 4 matrix aligned in memory of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	aligned_mediump_dmat4 = mat<4, 4, double, aligned_mediump>;

	/// 4 by 4 matrix aligned in memory of double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		aligned_lowp_dmat4 = mat<4, 4, double, aligned_lowp>;

	/// 4 by 4 matrix tightly packed in memory of single-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		packed_highp_mat4 = mat<4, 4, float, packed_highp>;

	/// 4 by 4 matrix tightly packed in memory of single-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	packed_mediump_mat4 = mat<4, 4, float, packed_mediump>;

	/// 4 by 4 matrix tightly packed in memory of single-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		packed_lowp_mat4 = mat<4, 4, float, packed_lowp>;

	/// 4 by 4 matrix tightly packed in memory of double-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		packed_highp_dmat4 = mat<4, 4, double, packed_highp>;

	/// 4 by 4 matrix tightly packed in memory of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	packed_mediump_dmat4 = mat<4, 4, double, packed_mediump>;

	/// 4 by 4 matrix tightly packed in memory of double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		packed_lowp_dmat4 = mat<4, 4, double, packed_lowp>;

	// -- *mat2x2 --

	/// 2 by 2 matrix aligned in memory of single-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		aligned_highp_mat2x2 = mat<2, 2, float, aligned_highp>;

	/// 2 by 2 matrix aligned in memory of single-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	aligned_mediump_mat2x2 = mat<2, 2, float, aligned_mediump>;

	/// 2 by 2 matrix aligned in memory of single-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		aligned_lowp_mat2x2 = mat<2, 2, float, aligned_lowp>;

	/// 2 by 2 matrix aligned in memory of double-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using	aligned_highp_dmat2x2 = mat<2, 2, double, aligned_highp>;

	/// 2 by 2 matrix aligned in memory of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	aligned_mediump_dmat2x2 = mat<2, 2, double, aligned_mediump>;

	/// 2 by 2 matrix aligned in memory of double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		aligned_lowp_dmat2x2 = mat<2, 2, double, aligned_lowp>;

	/// 2 by 2 matrix tightly packed in memory of single-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		packed_highp_mat2x2 = mat<2, 2, float, packed_highp>;

	/// 2 by 2 matrix tightly packed in memory of single-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	packed_mediump_mat2x2 = mat<2, 2, float, packed_mediump>;

	/// 2 by 2 matrix tightly packed in memory of single-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		packed_lowp_mat2x2 = mat<2, 2, float, packed_lowp>;

	/// 2 by 2 matrix tightly packed in memory of double-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		packed_highp_dmat2x2 = mat<2, 2, double, packed_highp>;

	/// 2 by 2 matrix tightly packed in memory of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	packed_mediump_dmat2x2 = mat<2, 2, double, packed_mediump>;

	/// 2 by 2 matrix tightly packed in memory of double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		packed_lowp_dmat2x2 = mat<2, 2, double, packed_lowp>;

	// -- *mat2x3 --

	/// 2 by 3 matrix aligned in memory of single-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		aligned_highp_mat2x3 = mat<2, 3, float, aligned_highp>;

	/// 2 by 3 matrix aligned in memory of single-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	aligned_mediump_mat2x3 = mat<2, 3, float, aligned_mediump>;

	/// 2 by 3 matrix aligned in memory of single-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		aligned_lowp_mat2x3 = mat<2, 3, float, aligned_lowp>;

	/// 2 by 3 matrix aligned in memory of double-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using	aligned_highp_dmat2x3 = mat<2, 3, double, aligned_highp>;

	/// 2 by 3 matrix aligned in memory of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	aligned_mediump_dmat2x3 = mat<2, 3, double, aligned_mediump>;

	/// 2 by 3 matrix aligned in memory of double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		aligned_lowp_dmat2x3 = mat<2, 3, double, aligned_lowp>;

	/// 2 by 3 matrix tightly packed in memory of single-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		packed_highp_mat2x3 = mat<2, 3, float, packed_highp>;

	/// 2 by 3 matrix tightly packed in memory of single-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	packed_mediump_mat2x3 = mat<2, 3, float, packed_mediump>;

	/// 2 by 3 matrix tightly packed in memory of single-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		packed_lowp_mat2x3 = mat<2, 3, float, packed_lowp>;

	/// 2 by 3 matrix tightly packed in memory of double-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		packed_highp_dmat2x3 = mat<2, 3, double, packed_highp>;

	/// 2 by 3 matrix tightly packed in memory of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	packed_mediump_dmat2x3 = mat<2, 3, double, packed_mediump>;

	/// 2 by 3 matrix tightly packed in memory of double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		packed_lowp_dmat2x3 = mat<2, 3, double, packed_lowp>;

	// -- *mat2x4 --

	/// 2 by 4 matrix aligned in memory of single-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		aligned_highp_mat2x4 = mat<2, 4, float, aligned_highp>;

	/// 2 by 4 matrix aligned in memory of single-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	aligned_mediump_mat2x4 = mat<2, 4, float, aligned_mediump>;

	/// 2 by 4 matrix aligned in memory of single-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		aligned_lowp_mat2x4 = mat<2, 4, float, aligned_lowp>;

	/// 2 by 4 matrix aligned in memory of double-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using	aligned_highp_dmat2x4 = mat<2, 4, double, aligned_highp>;

	/// 2 by 4 matrix aligned in memory of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	aligned_mediump_dmat2x4 = mat<2, 4, double, aligned_mediump>;

	/// 2 by 4 matrix aligned in memory of double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		aligned_lowp_dmat2x4 = mat<2, 4, double, aligned_lowp>;

	/// 2 by 4 matrix tightly packed in memory of single-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		packed_highp_mat2x4 = mat<2, 4, float, packed_highp>;

	/// 2 by 4 matrix tightly packed in memory of single-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	packed_mediump_mat2x4 = mat<2, 4, float, packed_mediump>;

	/// 2 by 4 matrix tightly packed in memory of single-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		packed_lowp_mat2x4 = mat<2, 4, float, packed_lowp>;

	/// 2 by 4 matrix tightly packed in memory of double-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		packed_highp_dmat2x4 = mat<2, 4, double, packed_highp>;

	/// 2 by 4 matrix tightly packed in memory of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	packed_mediump_dmat2x4 = mat<2, 4, double, packed_mediump>;

	/// 2 by 4 matrix tightly packed in memory of double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		packed_lowp_dmat2x4 = mat<2, 4, double, packed_lowp>;

	// -- *mat3x2 --

	/// 3 by 2 matrix aligned in memory of single-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		aligned_highp_mat3x2 = mat<3, 2, float, aligned_highp>;

	/// 3 by 2 matrix aligned in memory of single-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	aligned_mediump_mat3x2 = mat<3, 2, float, aligned_mediump>;

	/// 3 by 2 matrix aligned in memory of single-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		aligned_lowp_mat3x2 = mat<3, 2, float, aligned_lowp>;

	/// 3 by 2 matrix aligned in memory of double-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using	aligned_highp_dmat3x2 = mat<3, 2, double, aligned_highp>;

	/// 3 by 2 matrix aligned in memory of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	aligned_mediump_dmat3x2 = mat<3, 2, double, aligned_mediump>;

	/// 3 by 2 matrix aligned in memory of double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		aligned_lowp_dmat3x2 = mat<3, 2, double, aligned_lowp>;

	/// 3 by 2 matrix tightly packed in memory of single-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		packed_highp_mat3x2 = mat<3, 2, float, packed_highp>;

	/// 3 by 2 matrix tightly packed in memory of single-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	packed_mediump_mat3x2 = mat<3, 2, float, packed_mediump>;

	/// 3 by 2 matrix tightly packed in memory of single-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		packed_lowp_mat3x2 = mat<3, 2, float, packed_lowp>;

	/// 3 by 2 matrix tightly packed in memory of double-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		packed_highp_dmat3x2 = mat<3, 2, double, packed_highp>;

	/// 3 by 2 matrix tightly packed in memory of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	packed_mediump_dmat3x2 = mat<3, 2, double, packed_mediump>;

	/// 3 by 2 matrix tightly packed in memory of double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		packed_lowp_dmat3x2 = mat<3, 2, double, packed_lowp>;

	// -- *mat3x3 --

	/// 3 by 3 matrix aligned in memory of single-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		aligned_highp_mat3x3 = mat<3, 3, float, aligned_highp>;

	/// 3 by 3 matrix aligned in memory of single-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	aligned_mediump_mat3x3 = mat<3, 3, float, aligned_mediump>;

	/// 3 by 3 matrix aligned in memory of single-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		aligned_lowp_mat3x3 = mat<3, 3, float, aligned_lowp>;

	/// 3 by 3 matrix aligned in memory of double-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using	aligned_highp_dmat3x3 = mat<3, 3, double, aligned_highp>;

	/// 3 by 3 matrix aligned in memory of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	aligned_mediump_dmat3x3 = mat<3, 3, double, aligned_mediump>;

	/// 3 by 3 matrix aligned in memory of double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		aligned_lowp_dmat3x3 = mat<3, 3, double, aligned_lowp>;

	/// 3 by 3 matrix tightly packed in memory of single-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		packed_highp_mat3x3 = mat<3, 3, float, packed_highp>;

	/// 3 by 3 matrix tightly packed in memory of single-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	packed_mediump_mat3x3 = mat<3, 3, float, packed_mediump>;

	/// 3 by 3 matrix tightly packed in memory of single-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		packed_lowp_mat3x3 = mat<3, 3, float, packed_lowp>;

	/// 3 by 3 matrix tightly packed in memory of double-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		packed_highp_dmat3x3 = mat<3, 3, double, packed_highp>;

	/// 3 by 3 matrix tightly packed in memory of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	packed_mediump_dmat3x3 = mat<3, 3, double, packed_mediump>;

	/// 3 by 3 matrix tightly packed in memory of double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		packed_lowp_dmat3x3 = mat<3, 3, double, packed_lowp>;

	// -- *mat3x4 --

	/// 3 by 4 matrix aligned in memory of single-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		aligned_highp_mat3x4 = mat<3, 4, float, aligned_highp>;

	/// 3 by 4 matrix aligned in memory of single-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	aligned_mediump_mat3x4 = mat<3, 4, float, aligned_mediump>;

	/// 3 by 4 matrix aligned in memory of single-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		aligned_lowp_mat3x4 = mat<3, 4, float, aligned_lowp>;

	/// 3 by 4 matrix aligned in memory of double-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using	aligned_highp_dmat3x4 = mat<3, 4, double, aligned_highp>;

	/// 3 by 4 matrix aligned in memory of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	aligned_mediump_dmat3x4 = mat<3, 4, double, aligned_mediump>;

	/// 3 by 4 matrix aligned in memory of double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		aligned_lowp_dmat3x4 = mat<3, 4, double, aligned_lowp>;

	/// 3 by 4 matrix tightly packed in memory of single-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		packed_highp_mat3x4 = mat<3, 4, float, packed_highp>;

	/// 3 by 4 matrix tightly packed in memory of single-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	packed_mediump_mat3x4 = mat<3, 4, float, packed_mediump>;

	/// 3 by 4 matrix tightly packed in memory of single-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		packed_lowp_mat3x4 = mat<3, 4, float, packed_lowp>;

	/// 3 by 4 matrix tightly packed in memory of double-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		packed_highp_dmat3x4 = mat<3, 4, double, packed_highp>;

	/// 3 by 4 matrix tightly packed in memory of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	packed_mediump_dmat3x4 = mat<3, 4, double, packed_mediump>;

	/// 3 by 4 matrix tightly packed in memory of double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		packed_lowp_dmat3x4 = mat<3, 4, double, packed_lowp>;

	// -- *mat4x2 --

	/// 4 by 2 matrix aligned in memory of single-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		aligned_highp_mat4x2 = mat<4, 2, float, aligned_highp>;

	/// 4 by 2 matrix aligned in memory of single-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	aligned_mediump_mat4x2 = mat<4, 2, float, aligned_mediump>;

	/// 4 by 2 matrix aligned in memory of single-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		aligned_lowp_mat4x2 = mat<4, 2, float, aligned_lowp>;

	/// 4 by 2 matrix aligned in memory of double-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using	aligned_highp_dmat4x2 = mat<4, 2, double, aligned_highp>;

	/// 4 by 2 matrix aligned in memory of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	aligned_mediump_dmat4x2 = mat<4, 2, double, aligned_mediump>;

	/// 4 by 2 matrix aligned in memory of double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		aligned_lowp_dmat4x2 = mat<4, 2, double, aligned_lowp>;

	/// 4 by 2 matrix tightly packed in memory of single-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		packed_highp_mat4x2 = mat<4, 2, float, packed_highp>;

	/// 4 by 2 matrix tightly packed in memory of single-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	packed_mediump_mat4x2 = mat<4, 2, float, packed_mediump>;

	/// 4 by 2 matrix tightly packed in memory of single-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		packed_lowp_mat4x2 = mat<4, 2, float, packed_lowp>;

	/// 4 by 2 matrix tightly packed in memory of double-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		packed_highp_dmat4x2 = mat<4, 2, double, packed_highp>;

	/// 4 by 2 matrix tightly packed in memory of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	packed_mediump_dmat4x2 = mat<4, 2, double, packed_mediump>;

	/// 4 by 2 matrix tightly packed in memory of double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		packed_lowp_dmat4x2 = mat<4, 2, double, packed_lowp>;

	// -- *mat4x3 --

	/// 4 by 3 matrix aligned in memory of single-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		aligned_highp_mat4x3 = mat<4, 3, float, aligned_highp>;

	/// 4 by 3 matrix aligned in memory of single-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	aligned_mediump_mat4x3 = mat<4, 3, float, aligned_mediump>;

	/// 4 by 3 matrix aligned in memory of single-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		aligned_lowp_mat4x3 = mat<4, 3, float, aligned_lowp>;

	/// 4 by 3 matrix aligned in memory of double-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using	aligned_highp_dmat4x3 = mat<4, 3, double, aligned_highp>;

	/// 4 by 3 matrix aligned in memory of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	aligned_mediump_dmat4x3 = mat<4, 3, double, aligned_mediump>;

	/// 4 by 3 matrix aligned in memory of double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		aligned_lowp_dmat4x3 = mat<4, 3, double, aligned_lowp>;

	/// 4 by 3 matrix tightly packed in memory of single-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		packed_highp_mat4x3 = mat<4, 3, float, packed_highp>;

	/// 4 by 3 matrix tightly packed in memory of single-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	packed_mediump_mat4x3 = mat<4, 3, float, packed_mediump>;

	/// 4 by 3 matrix tightly packed in memory of single-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		packed_lowp_mat4x3 = mat<4, 3, float, packed_lowp>;

	/// 4 by 3 matrix tightly packed in memory of double-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		packed_highp_dmat4x3 = mat<4, 3, double, packed_highp>;

	/// 4 by 3 matrix tightly packed in memory of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	packed_mediump_dmat4x3 = mat<4, 3, double, packed_mediump>;

	/// 4 by 3 matrix tightly packed in memory of double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		packed_lowp_dmat4x3 = mat<4, 3, double, packed_lowp>;

	// -- *mat4x4 --

	/// 4 by 4 matrix aligned in memory of single-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		aligned_highp_mat4x4 = mat<4, 4, float, aligned_highp>;

	/// 4 by 4 matrix aligned in memory of single-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	aligned_mediump_mat4x4 = mat<4, 4, float, aligned_mediump>;

	/// 4 by 4 matrix aligned in memory of single-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		aligned_lowp_mat4x4 = mat<4, 4, float, aligned_lowp>;

	/// 4 by 4 matrix aligned in memory of double-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using	aligned_highp_dmat4x4 = mat<4, 4, double, aligned_highp>;

	/// 4 by 4 matrix aligned in memory of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	aligned_mediump_dmat4x4 = mat<4, 4, double, aligned_mediump>;

	/// 4 by 4 matrix aligned in memory of double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		aligned_lowp_dmat4x4 = mat<4, 4, double, aligned_lowp>;

	/// 4 by 4 matrix tightly packed in memory of single-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		packed_highp_mat4x4 = mat<4, 4, float, packed_highp>;

	/// 4 by 4 matrix tightly packed in memory of single-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	packed_mediump_mat4x4 = mat<4, 4, float, packed_mediump>;

	/// 4 by 4 matrix tightly packed in memory of single-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		packed_lowp_mat4x4 = mat<4, 4, float, packed_lowp>;

	/// 4 by 4 matrix tightly packed in memory of double-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		packed_highp_dmat4x4 = mat<4, 4, double, packed_highp>;

	/// 4 by 4 matrix tightly packed in memory of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	packed_mediump_dmat4x4 = mat<4, 4, double, packed_mediump>;

	/// 4 by 4 matrix tightly packed in memory of double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		packed_lowp_dmat4x4 = mat<4, 4, double, packed_lowp>;

	// -- *quat --

	/// quaternion aligned in memory of single-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		aligned_highp_quat = qua<float, aligned_highp>;

	/// quaternion aligned in memory of single-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using		aligned_mediump_quat = qua<float, aligned_mediump>;

	/// quaternion aligned in memory of single-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		aligned_lowp_quat = qua<float, aligned_lowp>;

	/// quaternion aligned in memory of double-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		aligned_highp_dquat = qua<double, aligned_highp>;

	/// quaternion aligned in memory of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using	aligned_mediump_dquat = qua<double, aligned_mediump>;

	/// quaternion aligned in memory of double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		aligned_lowp_dquat = qua<double, aligned_lowp>;

	/// quaternion tightly packed in memory of single-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		packed_highp_quat = qua<float, packed_highp>;

	/// quaternion tightly packed in memory of single-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using		packed_mediump_quat = qua<float, packed_mediump>;

	/// quaternion tightly packed in memory of single-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using			packed_lowp_quat = qua<float, packed_lowp>;

	/// quaternion tightly packed in memory of double-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		packed_highp_dquat = qua<double, packed_highp>;

	/// quaternion tightly packed in memory of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	using		packed_mediump_dquat = qua<double, packed_mediump>;

	/// quaternion tightly packed in memory of double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	using		packed_lowp_dquat = qua<double, packed_lowp>;

	// -- default --

#if(defined(GLM_PRECISION_LOWP_FLOAT))
	using			aligned_vec1 = aligned_lowp_vec1;
	using			aligned_vec2 = aligned_lowp_vec2;
	using			aligned_vec3 = aligned_lowp_vec3;
	using			aligned_vec4 = aligned_lowp_vec4;
	using			packed_vec1 = packed_lowp_vec1;
	using			packed_vec2 = packed_lowp_vec2;
	using			packed_vec3 = packed_lowp_vec3;
	using			packed_vec4 = packed_lowp_vec4;

	using			aligned_mat2 = aligned_lowp_mat2;
	using			aligned_mat3 = aligned_lowp_mat3;
	using			aligned_mat4 = aligned_lowp_mat4;
	using			packed_mat2 = packed_lowp_mat2;
	using			packed_mat3 = packed_lowp_mat3;
	using			packed_mat4 = packed_lowp_mat4;

	using			aligned_mat2x2 = aligned_lowp_mat2x2;
	using			aligned_mat2x3 = aligned_lowp_mat2x3;
	using			aligned_mat2x4 = aligned_lowp_mat2x4;
	using			aligned_mat3x2 = aligned_lowp_mat3x2;
	using			aligned_mat3x3 = aligned_lowp_mat3x3;
	using			aligned_mat3x4 = aligned_lowp_mat3x4;
	using			aligned_mat4x2 = aligned_lowp_mat4x2;
	using			aligned_mat4x3 = aligned_lowp_mat4x3;
	using			aligned_mat4x4 = aligned_lowp_mat4x4;
	using			packed_mat2x2 = packed_lowp_mat2x2;
	using			packed_mat2x3 = packed_lowp_mat2x3;
	using			packed_mat2x4 = packed_lowp_mat2x4;
	using			packed_mat3x2 = packed_lowp_mat3x2;
	using			packed_mat3x3 = packed_lowp_mat3x3;
	using			packed_mat3x4 = packed_lowp_mat3x4;
	using			packed_mat4x2 = packed_lowp_mat4x2;
	using			packed_mat4x3 = packed_lowp_mat4x3;
	using			packed_mat4x4 = packed_lowp_mat4x4;

	using			aligned_quat = aligned_lowp_quat;
	using			packed_quat = packed_lowp_quat;
#elif(defined(GLM_PRECISION_MEDIUMP_FLOAT))
	using		aligned_vec1 = aligned_mediump_vec1;
	using		aligned_vec2 = aligned_mediump_vec2;
	using		aligned_vec3 = aligned_mediump_vec3;
	using		aligned_vec4 = aligned_mediump_vec4;
	using			packed_vec1 = packed_mediump_vec1;
	using			packed_vec2 = packed_mediump_vec2;
	using			packed_vec3 = packed_mediump_vec3;
	using			packed_vec4 = packed_mediump_vec4;

	using		aligned_mat2 = aligned_mediump_mat2;
	using		aligned_mat3 = aligned_mediump_mat3;
	using		aligned_mat4 = aligned_mediump_mat4;
	using			packed_mat2 = packed_mediump_mat2;
	using			packed_mat3 = packed_mediump_mat3;
	using			packed_mat4 = packed_mediump_mat4;

	using		aligned_mat2x2 = aligned_mediump_mat2x2;
	using		aligned_mat2x3 = aligned_mediump_mat2x3;
	using		aligned_mat2x4 = aligned_mediump_mat2x4;
	using		aligned_mat3x2 = aligned_mediump_mat3x2;
	using		aligned_mat3x3 = aligned_mediump_mat3x3;
	using		aligned_mat3x4 = aligned_mediump_mat3x4;
	using		aligned_mat4x2 = aligned_mediump_mat4x2;
	using		aligned_mat4x3 = aligned_mediump_mat4x3;
	using		aligned_mat4x4 = aligned_mediump_mat4x4;
	using		packed_mat2x2 = packed_mediump_mat2x2;
	using		packed_mat2x3 = packed_mediump_mat2x3;
	using		packed_mat2x4 = packed_mediump_mat2x4;
	using		packed_mat3x2 = packed_mediump_mat3x2;
	using		packed_mat3x3 = packed_mediump_mat3x3;
	using		packed_mat3x4 = packed_mediump_mat3x4;
	using		packed_mat4x2 = packed_mediump_mat4x2;
	using		packed_mat4x3 = packed_mediump_mat4x3;
	using		packed_mat4x4 = packed_mediump_mat4x4;

	using		aligned_quat = aligned_mediump_quat;
	using			packed_quat = packed_mediump_quat;
#else //defined(GLM_PRECISION_HIGHP_FLOAT)
	/// 1 component vector aligned in memory of single-precision floating-point numbers.
	using			aligned_vec1 = aligned_highp_vec1;

	/// 2 components vector aligned in memory of single-precision floating-point numbers.
	using			aligned_vec2 = aligned_highp_vec2;

	/// 3 components vector aligned in memory of single-precision floating-point numbers.
	using			aligned_vec3 = aligned_highp_vec3;

	/// 4 components vector aligned in memory of single-precision floating-point numbers.
	using 			aligned_vec4 = aligned_highp_vec4;

	/// 1 component vector tightly packed in memory of single-precision floating-point numbers.
	using			packed_vec1 = packed_highp_vec1;

	/// 2 components vector tightly packed in memory of single-precision floating-point numbers.
	using			packed_vec2 = packed_highp_vec2;

	/// 3 components vector tightly packed in memory of single-precision floating-point numbers.
	using			packed_vec3 = packed_highp_vec3;

	/// 4 components vector tightly packed in memory of single-precision floating-point numbers.
	using			packed_vec4 = packed_highp_vec4;

	/// 2 by 2 matrix tightly aligned in memory of single-precision floating-point numbers.
	using			aligned_mat2 = aligned_highp_mat2;

	/// 3 by 3 matrix tightly aligned in memory of single-precision floating-point numbers.
	using			aligned_mat3 = aligned_highp_mat3;

	/// 4 by 4 matrix tightly aligned in memory of single-precision floating-point numbers.
	using			aligned_mat4 = aligned_highp_mat4;

	/// 2 by 2 matrix tightly packed in memory of single-precision floating-point numbers.
	using			packed_mat2 = packed_highp_mat2;

	/// 3 by 3 matrix tightly packed in memory of single-precision floating-point numbers.
	using			packed_mat3 = packed_highp_mat3;

	/// 4 by 4 matrix tightly packed in memory of single-precision floating-point numbers.
	using			packed_mat4 = packed_highp_mat4;

	/// 2 by 2 matrix tightly aligned in memory of single-precision floating-point numbers.
	using		aligned_mat2x2 = aligned_highp_mat2x2;

	/// 2 by 3 matrix tightly aligned in memory of single-precision floating-point numbers.
	using		aligned_mat2x3 = aligned_highp_mat2x3;

	/// 2 by 4 matrix tightly aligned in memory of single-precision floating-point numbers.
	using		aligned_mat2x4 = aligned_highp_mat2x4;

	/// 3 by 2 matrix tightly aligned in memory of single-precision floating-point numbers.
	using		aligned_mat3x2 = aligned_highp_mat3x2;

	/// 3 by 3 matrix tightly aligned in memory of single-precision floating-point numbers.
	using		aligned_mat3x3 = aligned_highp_mat3x3;

	/// 3 by 4 matrix tightly aligned in memory of single-precision floating-point numbers.
	using		aligned_mat3x4 = aligned_highp_mat3x4;

	/// 4 by 2 matrix tightly aligned in memory of single-precision floating-point numbers.
	using		aligned_mat4x2 = aligned_highp_mat4x2;

	/// 4 by 3 matrix tightly aligned in memory of single-precision floating-point numbers.
	using		aligned_mat4x3 = aligned_highp_mat4x3;

	/// 4 by 4 matrix tightly aligned in memory of single-precision floating-point numbers.
	using		aligned_mat4x4 = aligned_highp_mat4x4;

	/// 2 by 2 matrix tightly packed in memory of single-precision floating-point numbers.
	using			packed_mat2x2 = packed_highp_mat2x2;

	/// 2 by 3 matrix tightly packed in memory of single-precision floating-point numbers.
	using			packed_mat2x3 = packed_highp_mat2x3;

	/// 2 by 4 matrix tightly packed in memory of single-precision floating-point numbers.
	using			packed_mat2x4 = packed_highp_mat2x4;

	/// 3 by 2 matrix tightly packed in memory of single-precision floating-point numbers.
	using			packed_mat3x2 = packed_highp_mat3x2;

	/// 3 by 3 matrix tightly packed in memory of single-precision floating-point numbers.
	using			packed_mat3x3 = packed_highp_mat3x3;

	/// 3 by 4 matrix tightly packed in memory of single-precision floating-point numbers.
	using			packed_mat3x4 = packed_highp_mat3x4;

	/// 4 by 2 matrix tightly packed in memory of single-precision floating-point numbers.
	using			packed_mat4x2 = packed_highp_mat4x2;

	/// 4 by 3 matrix tightly packed in memory of single-precision floating-point numbers.
	using			packed_mat4x3 = packed_highp_mat4x3;

	/// 4 by 4 matrix tightly packed in memory of single-precision floating-point numbers.
	using			packed_mat4x4 = packed_highp_mat4x4;

	/// quaternion tightly aligned in memory of single-precision floating-point numbers.
	using			aligned_quat = aligned_highp_quat;

	/// quaternion tightly packed in memory of single-precision floating-point numbers.
	using			packed_quat = packed_highp_quat;
#endif//GLM_PRECISION

#if(defined(GLM_PRECISION_LOWP_DOUBLE))
	using			aligned_dvec1 = aligned_lowp_dvec1;
	using			aligned_dvec2 = aligned_lowp_dvec2;
	using			aligned_dvec3 = aligned_lowp_dvec3;
	using			aligned_dvec4 = aligned_lowp_dvec4;
	using			packed_dvec1 = packed_lowp_dvec1;
	using			packed_dvec2 = packed_lowp_dvec2;
	using			packed_dvec3 = packed_lowp_dvec3;
	using			packed_dvec4 = packed_lowp_dvec4;

	using			aligned_dmat2 = aligned_lowp_dmat2;
	using			aligned_dmat3 = aligned_lowp_dmat3;
	using			aligned_dmat4 = aligned_lowp_dmat4;
	using			packed_dmat2 = packed_lowp_dmat2;
	using			packed_dmat3 = packed_lowp_dmat3;
	using			packed_dmat4 = packed_lowp_dmat4;

	using		aligned_dmat2x2 = aligned_lowp_dmat2x2;
	using		aligned_dmat2x3 = aligned_lowp_dmat2x3;
	using		aligned_dmat2x4 = aligned_lowp_dmat2x4;
	using		aligned_dmat3x2 = aligned_lowp_dmat3x2;
	using		aligned_dmat3x3 = aligned_lowp_dmat3x3;
	using		aligned_dmat3x4 = aligned_lowp_dmat3x4;
	using		aligned_dmat4x2 = aligned_lowp_dmat4x2;
	using		aligned_dmat4x3 = aligned_lowp_dmat4x3;
	using		aligned_dmat4x4 = aligned_lowp_dmat4x4;
	using			packed_dmat2x2 = packed_lowp_dmat2x2;
	using			packed_dmat2x3 = packed_lowp_dmat2x3;
	using			packed_dmat2x4 = packed_lowp_dmat2x4;
	using			packed_dmat3x2 = packed_lowp_dmat3x2;
	using			packed_dmat3x3 = packed_lowp_dmat3x3;
	using			packed_dmat3x4 = packed_lowp_dmat3x4;
	using			packed_dmat4x2 = packed_lowp_dmat4x2;
	using			packed_dmat4x3 = packed_lowp_dmat4x3;
	using			packed_dmat4x4 = packed_lowp_dmat4x4;

	using			aligned_dquat = aligned_lowp_dquat;
	using			packed_dquat = packed_lowp_dquat;
#elif(defined(GLM_PRECISION_MEDIUMP_DOUBLE))
	using		aligned_dvec1 = aligned_mediump_dvec1;
	using		aligned_dvec2 = aligned_mediump_dvec2;
	using		aligned_dvec3 = aligned_mediump_dvec3;
	using		aligned_dvec4 = aligned_mediump_dvec4;
	using		packed_dvec1 = packed_mediump_dvec1;
	using		packed_dvec2 = packed_mediump_dvec2;
	using		packed_dvec3 = packed_mediump_dvec3;
	using		packed_dvec4 = packed_mediump_dvec4;

	using		aligned_dmat2 = aligned_mediump_dmat2;
	using		aligned_dmat3 = aligned_mediump_dmat3;
	using		aligned_dmat4 = aligned_mediump_dmat4;
	using		packed_dmat2 = packed_mediump_dmat2;
	using		packed_dmat3 = packed_mediump_dmat3;
	using		packed_dmat4 = packed_mediump_dmat4;

	using		aligned_dmat2x2 = aligned_mediump_dmat2x2;
	using		aligned_dmat2x3 = aligned_mediump_dmat2x3;
	using		aligned_dmat2x4 = aligned_mediump_dmat2x4;
	using		aligned_dmat3x2 = aligned_mediump_dmat3x2;
	using		aligned_dmat3x3 = aligned_mediump_dmat3x3;
	using		aligned_dmat3x4 = aligned_mediump_dmat3x4;
	using		aligned_dmat4x2 = aligned_mediump_dmat4x2;
	using		aligned_dmat4x3 = aligned_mediump_dmat4x3;
	using		aligned_dmat4x4 = aligned_mediump_dmat4x4;
	using		packed_dmat2x2 = packed_mediump_dmat2x2;
	using		packed_dmat2x3 = packed_mediump_dmat2x3;
	using		packed_dmat2x4 = packed_mediump_dmat2x4;
	using		packed_dmat3x2 = packed_mediump_dmat3x2;
	using		packed_dmat3x3 = packed_mediump_dmat3x3;
	using		packed_dmat3x4 = packed_mediump_dmat3x4;
	using		packed_dmat4x2 = packed_mediump_dmat4x2;
	using		packed_dmat4x3 = packed_mediump_dmat4x3;
	using		packed_dmat4x4 = packed_mediump_dmat4x4;

	using		aligned_dquat = aligned_mediump_dquat;
	using		packed_dquat = packed_mediump_dquat;
#else //defined(GLM_PRECISION_HIGHP_DOUBLE)
	/// 1 component vector aligned in memory of double-precision floating-point numbers.
	using			aligned_dvec1 = aligned_highp_dvec1;

	/// 2 components vector aligned in memory of double-precision floating-point numbers.
	using			aligned_dvec2 = aligned_highp_dvec2;

	/// 3 components vector aligned in memory of double-precision floating-point numbers.
	using			aligned_dvec3 = aligned_highp_dvec3;

	/// 4 components vector aligned in memory of double-precision floating-point numbers.
	using			aligned_dvec4 = aligned_highp_dvec4;

	/// 1 component vector tightly packed in memory of double-precision floating-point numbers.
	using			packed_dvec1 = packed_highp_dvec1;

	/// 2 components vector tightly packed in memory of double-precision floating-point numbers.
	using			packed_dvec2 = packed_highp_dvec2;

	/// 3 components vector tightly packed in memory of double-precision floating-point numbers.
	using			packed_dvec3 = packed_highp_dvec3;

	/// 4 components vector tightly packed in memory of double-precision floating-point numbers.
	using			packed_dvec4 = packed_highp_dvec4;

	/// 2 by 2 matrix tightly aligned in memory of double-precision floating-point numbers.
	using			aligned_dmat2 = aligned_highp_dmat2;

	/// 3 by 3 matrix tightly aligned in memory of double-precision floating-point numbers.
	using			aligned_dmat3 = aligned_highp_dmat3;

	/// 4 by 4 matrix tightly aligned in memory of double-precision floating-point numbers.
	using			aligned_dmat4 = aligned_highp_dmat4;

	/// 2 by 2 matrix tightly packed in memory of double-precision floating-point numbers.
	using			packed_dmat2 = packed_highp_dmat2;

	/// 3 by 3 matrix tightly packed in memory of double-precision floating-point numbers.
	using			packed_dmat3 = packed_highp_dmat3;

	/// 4 by 4 matrix tightly packed in memory of double-precision floating-point numbers.
	using			packed_dmat4 = packed_highp_dmat4;

	/// 2 by 2 matrix tightly aligned in memory of double-precision floating-point numbers.
	using		aligned_dmat2x2 = aligned_highp_dmat2x2;

	/// 2 by 3 matrix tightly aligned in memory of double-precision floating-point numbers.
	using		aligned_dmat2x3 = aligned_highp_dmat2x3;

	/// 2 by 4 matrix tightly aligned in memory of double-precision floating-point numbers.
	using		aligned_dmat2x4 = aligned_highp_dmat2x4;

	/// 3 by 2 matrix tightly aligned in memory of double-precision floating-point numbers.
	using		aligned_dmat3x2 = aligned_highp_dmat3x2;

	/// 3 by 3 matrix tightly aligned in memory of double-precision floating-point numbers.
	using		aligned_dmat3x3 = aligned_highp_dmat3x3;

	/// 3 by 4 matrix tightly aligned in memory of double-precision floating-point numbers.
	using		aligned_dmat3x4 = aligned_highp_dmat3x4;

	/// 4 by 2 matrix tightly aligned in memory of double-precision floating-point numbers.
	using		aligned_dmat4x2 = aligned_highp_dmat4x2;

	/// 4 by 3 matrix tightly aligned in memory of double-precision floating-point numbers.
	using		aligned_dmat4x3 = aligned_highp_dmat4x3;

	/// 4 by 4 matrix tightly aligned in memory of double-precision floating-point numbers.
	using		aligned_dmat4x4 = aligned_highp_dmat4x4;

	/// 2 by 2 matrix tightly packed in memory of double-precision floating-point numbers.
	using		packed_dmat2x2 = packed_highp_dmat2x2;

	/// 2 by 3 matrix tightly packed in memory of double-precision floating-point numbers.
	using		packed_dmat2x3 = packed_highp_dmat2x3;

	/// 2 by 4 matrix tightly packed in memory of double-precision floating-point numbers.
	using		packed_dmat2x4 = packed_highp_dmat2x4;

	/// 3 by 2 matrix tightly packed in memory of double-precision floating-point numbers.
	using		packed_dmat3x2 = packed_highp_dmat3x2;

	/// 3 by 3 matrix tightly packed in memory of double-precision floating-point numbers.
	using		packed_dmat3x3 = packed_highp_dmat3x3;

	/// 3 by 4 matrix tightly packed in memory of double-precision floating-point numbers.
	using		packed_dmat3x4 = packed_highp_dmat3x4;

	/// 4 by 2 matrix tightly packed in memory of double-precision floating-point numbers.
	using		packed_dmat4x2 = packed_highp_dmat4x2;

	/// 4 by 3 matrix tightly packed in memory of double-precision floating-point numbers.
	using		packed_dmat4x3 = packed_highp_dmat4x3;

	/// 4 by 4 matrix tightly packed in memory of double-precision floating-point numbers.
	using		packed_dmat4x4 = packed_highp_dmat4x4;

	/// quaternion tightly aligned in memory of double-precision floating-point numbers.
	using			aligned_dquat = aligned_highp_dquat;

	/// quaternion tightly packed in memory of double-precision floating-point numbers.
	using			packed_dquat = packed_highp_dquat;
#endif//GLM_PRECISION

#if(defined(GLM_PRECISION_LOWP_INT))
	using			aligned_ivec1 = aligned_lowp_ivec1;
	using			aligned_ivec2 = aligned_lowp_ivec2;
	using			aligned_ivec3 = aligned_lowp_ivec3;
	using			aligned_ivec4 = aligned_lowp_ivec4;
#elif(defined(GLM_PRECISION_MEDIUMP_INT))
	using		aligned_ivec1 = aligned_mediump_ivec1;
	using		aligned_ivec2 = aligned_mediump_ivec2;
	using		aligned_ivec3 = aligned_mediump_ivec3;
	using		aligned_ivec4 = aligned_mediump_ivec4;
#else //defined(GLM_PRECISION_HIGHP_INT)
	/// 1 component vector aligned in memory of signed integer numbers.
	using			aligned_ivec1 = aligned_highp_ivec1;

	/// 2 components vector aligned in memory of signed integer numbers.
	using			aligned_ivec2 = aligned_highp_ivec2;

	/// 3 components vector aligned in memory of signed integer numbers.
	using			aligned_ivec3 = aligned_highp_ivec3;

	/// 4 components vector aligned in memory of signed integer numbers.
	using			aligned_ivec4 = aligned_highp_ivec4;

	/// 1 component vector tightly packed in memory of signed integer numbers.
	using			packed_ivec1 = packed_highp_ivec1;

	/// 2 components vector tightly packed in memory of signed integer numbers.
	using			packed_ivec2 = packed_highp_ivec2;

	/// 3 components vector tightly packed in memory of signed integer numbers.
	using			packed_ivec3 = packed_highp_ivec3;

	/// 4 components vector tightly packed in memory of signed integer numbers.
	using			packed_ivec4 = packed_highp_ivec4;
#endif//GLM_PRECISION

	// -- Unsigned integer definition --

#if(defined(GLM_PRECISION_LOWP_UINT))
	using			aligned_uvec1 = aligned_lowp_uvec1;
	using			aligned_uvec2 = aligned_lowp_uvec2;
	using			aligned_uvec3 = aligned_lowp_uvec3;
	using			aligned_uvec4 = aligned_lowp_uvec4;
#elif(defined(GLM_PRECISION_MEDIUMP_UINT))
	using		aligned_uvec1 = aligned_mediump_uvec1;
	using		aligned_uvec2 = aligned_mediump_uvec2;
	using		aligned_uvec3 = aligned_mediump_uvec3;
	using		aligned_uvec4 = aligned_mediump_uvec4;
#else //defined(GLM_PRECISION_HIGHP_UINT)
	/// 1 component vector aligned in memory of unsigned integer numbers.
	using			aligned_uvec1 = aligned_highp_uvec1;

	/// 2 components vector aligned in memory of unsigned integer numbers.
	using			aligned_uvec2 = aligned_highp_uvec2;

	/// 3 components vector aligned in memory of unsigned integer numbers.
	using			aligned_uvec3 = aligned_highp_uvec3;

	/// 4 components vector aligned in memory of unsigned integer numbers.
	using			aligned_uvec4 = aligned_highp_uvec4;

	/// 1 component vector tightly packed in memory of unsigned integer numbers.
	using			packed_uvec1 = packed_highp_uvec1;

	/// 2 components vector tightly packed in memory of unsigned integer numbers.
	using			packed_uvec2 = packed_highp_uvec2;

	/// 3 components vector tightly packed in memory of unsigned integer numbers.
	using			packed_uvec3 = packed_highp_uvec3;

	/// 4 components vector tightly packed in memory of unsigned integer numbers.
	using			packed_uvec4 = packed_highp_uvec4;
#endif//GLM_PRECISION

#if(defined(GLM_PRECISION_LOWP_BOOL))
	using			aligned_bvec1 = aligned_lowp_bvec1;
	using			aligned_bvec2 = aligned_lowp_bvec2;
	using			aligned_bvec3 = aligned_lowp_bvec3;
	using			aligned_bvec4 = aligned_lowp_bvec4;
#elif(defined(GLM_PRECISION_MEDIUMP_BOOL))
	using		aligned_bvec1 = aligned_mediump_bvec1;
	using		aligned_bvec2 = aligned_mediump_bvec2;
	using		aligned_bvec3 = aligned_mediump_bvec3;
	using		aligned_bvec4 = aligned_mediump_bvec4;
#else //defined(GLM_PRECISION_HIGHP_BOOL)
	/// 1 component vector aligned in memory of bool values.
	using			aligned_bvec1 = aligned_highp_bvec1;

	/// 2 components vector aligned in memory of bool values.
	using			aligned_bvec2 = aligned_highp_bvec2;

	/// 3 components vector aligned in memory of bool values.
	using			aligned_bvec3 = aligned_highp_bvec3;

	/// 4 components vector aligned in memory of bool values.
	using			aligned_bvec4 = aligned_highp_bvec4;

	/// 1 components vector tightly packed in memory of bool values.
	using			packed_bvec1 = packed_highp_bvec1;

	/// 2 components vector tightly packed in memory of bool values.
	using			packed_bvec2 = packed_highp_bvec2;

	/// 3 components vector tightly packed in memory of bool values.
	using			packed_bvec3 = packed_highp_bvec3;

	/// 4 components vector tightly packed in memory of bool values.
	using			packed_bvec4 = packed_highp_bvec4;
#endif//GLM_PRECISION

	/// @}
}//namespace glm
