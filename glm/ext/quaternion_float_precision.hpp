/// @ref ext_quaternion_float_precision
/// @file glm/ext/quaternion_float_precision.hpp
///
/// @defgroup ext_quaternion_float_precision GLM_EXT_quaternion_float_precision
/// @ingroup ext
///
/// Exposes single-precision floating point quaternion type with various precision in term of ULPs.
///
/// Include <glm/ext/quaternion_float_precision.hpp> to use the features of this extension.

#pragma once

// Dependency:
#include "../detail/type_quat.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_EXT_quaternion_float_precision extension included")
#endif

namespace glm
{
	/// @addtogroup ext_quaternion_float_precision
	/// @{

	/// Quaternion of aligned single-precision floating-point numbers using high precision arithmetic in term of ULPs.
	///
	/// @see ext_quaternion_float_precision
	typedef qua<float, highp, sizeof(float) * 4>		aligned_highp_quat;

	/// Quaternion of packed single-precision floating-point numbers using high precision arithmetic in term of ULPs.
	///
	/// @see ext_quaternion_float_precision
	typedef qua<float, highp>							packed_highp_quat;

	/// Quaternion of aligned single-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	///
	/// @see ext_quaternion_float_precision
	typedef qua<float, mediump, sizeof(float) * 4>		aligned_mediump_quat;

	/// Quaternion of packed single-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	///
	/// @see ext_quaternion_float_precision
	typedef qua<float, mediump>							packed_mediump_quat;

	/// Quaternion of aligned single-precision floating-point numbers using low precision arithmetic in term of ULPs.
	///
	/// @see ext_quaternion_float_precision
	typedef qua<float, lowp, sizeof(float) * 4>			aligned_lowp_quat;

	/// Quaternion of packed single-precision floating-point numbers using low precision arithmetic in term of ULPs.
	///
	/// @see ext_quaternion_float_precision
	typedef qua<float, lowp>							packed_lowp_quat;

#ifdef GLM_FORCE_DEFAULT_ALIGNED_GENTYPES
	/// Quaternion of single-precision floating-point numbers using high precision arithmetic in term of ULPs.
	///
	/// @see ext_quaternion_float_precision
	typedef aligned_highp_quat							highp_quat;

	/// Quaternion of single-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	///
	/// @see ext_quaternion_float_precision
	typedef aligned_mediump_quat						mediump_quat;
	
	/// Quaternion of single-precision floating-point numbers using low precision arithmetic in term of ULPs.
	///
	/// @see ext_quaternion_float_precision
	typedef aligned_lowp_quat							lowp_quat;
#else
	/// Quaternion of single-precision floating-point numbers using high precision arithmetic in term of ULPs.
	///
	/// @see ext_quaternion_float_precision
	typedef packed_highp_quat							highp_quat;

	/// Quaternion of single-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	///
	/// @see ext_quaternion_float_precision
	typedef packed_mediump_quat							mediump_quat;
	
	/// Quaternion of single-precision floating-point numbers using low precision arithmetic in term of ULPs.
	///
	/// @see ext_quaternion_float_precision
	typedef packed_lowp_quat							lowp_quat;
#endif

	/// @}
} //namespace glm

#if GLM_CONFIG_CTOR_INIT == GLM_DISABLE
static_assert(std::is_trivially_default_constructible<glm::lowp_quat>::value);
static_assert(std::is_trivially_default_constructible<glm::mediump_quat>::value);
static_assert(std::is_trivially_default_constructible<glm::highp_quat>::value);
#endif
static_assert(std::is_trivially_copy_assignable<glm::lowp_quat>::value);
static_assert(std::is_trivially_copy_assignable<glm::mediump_quat>::value);
static_assert(std::is_trivially_copy_assignable<glm::highp_quat>::value);
static_assert(std::is_trivially_copyable<glm::lowp_quat>::value);
static_assert(std::is_trivially_copyable<glm::mediump_quat>::value);
static_assert(std::is_trivially_copyable<glm::highp_quat>::value);
static_assert(std::is_copy_constructible<glm::lowp_quat>::value);
static_assert(std::is_copy_constructible<glm::mediump_quat>::value);
static_assert(std::is_copy_constructible<glm::highp_quat>::value);
static_assert(glm::lowp_quat::length() == 4);
static_assert(glm::mediump_quat::length() == 4);
static_assert(glm::highp_quat::length() == 4);

static_assert(sizeof(glm::aligned_highp_quat) == 16);
static_assert(alignof(glm::aligned_highp_quat) == 16);
static_assert(sizeof(glm::packed_highp_quat) == 16);
static_assert(alignof(glm::packed_highp_quat) == 4);

static_assert(sizeof(glm::aligned_mediump_quat) == 16);
static_assert(alignof(glm::aligned_mediump_quat) == 16);
static_assert(sizeof(glm::packed_mediump_quat) == 16);
static_assert(alignof(glm::packed_mediump_quat) == 4);

static_assert(sizeof(glm::aligned_lowp_quat) == 16);
static_assert(alignof(glm::aligned_lowp_quat) == 16);
static_assert(sizeof(glm::packed_lowp_quat) == 16);
static_assert(alignof(glm::packed_lowp_quat) == 4);

static_assert(sizeof(glm::highp_quat) == 16);
static_assert(sizeof(glm::mediump_quat) == 16);
static_assert(sizeof(glm::lowp_quat) == 16);
#ifdef GLM_FORCE_DEFAULT_ALIGNED_GENTYPES
static_assert(alignof(glm::highp_quat) == 16);
static_assert(alignof(glm::mediump_quat) == 16);
static_assert(alignof(glm::lowp_quat) == 16);
#else
static_assert(alignof(glm::highp_quat) == 4);
static_assert(alignof(glm::mediump_quat) == 4);
static_assert(alignof(glm::lowp_quat) == 4);
#endif

