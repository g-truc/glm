/// @ref ext_quaternion_double_precision
/// @file glm/ext/quaternion_double_precision.hpp
///
/// @defgroup ext_quaternion_double_precision GLM_EXT_quaternion_double_precision
/// @ingroup ext
///
/// Exposes double-precision floating point quaternion type with various precision in term of ULPs.
///
/// Include <glm/ext/quaternion_double_precision.hpp> to use the features of this extension.

#pragma once

// Dependency:
#include "../detail/type_quat.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_EXT_quaternion_double_precision extension included")
#endif

namespace glm
{
	/// @addtogroup ext_quaternion_double_precision
	/// @{

	/// Quaternion of aligned double-precision floating-point numbers using high precision arithmetic in term of ULPs.
	///
	/// @see ext_quaternion_double_precision
	typedef qua<double, highp, sizeof(double) * 4>		aligned_highp_dquat;

	/// Quaternion of packed double-precision floating-point numbers using high precision arithmetic in term of ULPs.
	///
	/// @see ext_quaternion_double_precision
	typedef qua<double, highp>							packed_highp_dquat;

	/// Quaternion of aligned double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	///
	/// @see ext_quaternion_double_precision
	typedef qua<double, mediump, sizeof(double) * 4>	aligned_mediump_dquat;

	/// Quaternion of packed double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	///
	/// @see ext_quaternion_double_precision
	typedef qua<double, mediump>						packed_mediump_dquat;

	/// Quaternion of aligned double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	///
	/// @see ext_quaternion_double_precision
	typedef qua<double, lowp, sizeof(double) * 4>		aligned_lowp_dquat;

	/// Quaternion of packed double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	///
	/// @see ext_quaternion_double_precision
	typedef qua<double, lowp>							packed_lowp_dquat;

#ifdef GLM_FORCE_DEFAULT_ALIGNED_GENTYPES
	/// Quaternion of double-precision floating-point numbers using high precision arithmetic in term of ULPs.
	///
	/// @see ext_quaternion_double_precision
	typedef aligned_highp_dquat							highp_dquat;

	/// Quaternion of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	///
	/// @see ext_quaternion_double_precision
	typedef aligned_mediump_dquat						mediump_dquat;
	
	/// Quaternion of double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	///
	/// @see ext_quaternion_double_precision
	typedef aligned_lowp_dquat							lowp_dquat;
#else
	/// Quaternion of double-precision floating-point numbers using high precision arithmetic in term of ULPs.
	///
	/// @see ext_quaternion_double_precision
	typedef packed_highp_dquat							highp_dquat;

	/// Quaternion of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	///
	/// @see ext_quaternion_double_precision
	typedef packed_mediump_dquat						mediump_dquat;
	
	/// Quaternion of double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	///
	/// @see ext_quaternion_double_precision
	typedef packed_lowp_dquat							lowp_dquat;
#endif

	/// @}
} //namespace glm

#if GLM_CONFIG_CTOR_INIT == GLM_DISABLE
static_assert(std::is_trivially_default_constructible<glm::lowp_dquat>::value);
static_assert(std::is_trivially_default_constructible<glm::mediump_dquat>::value);
static_assert(std::is_trivially_default_constructible<glm::highp_dquat>::value);
#endif
static_assert(std::is_trivially_copy_assignable<glm::lowp_dquat>::value);
static_assert(std::is_trivially_copy_assignable<glm::mediump_dquat>::value);
static_assert(std::is_trivially_copy_assignable<glm::highp_dquat>::value);
static_assert(std::is_trivially_copyable<glm::lowp_dquat>::value);
static_assert(std::is_trivially_copyable<glm::mediump_dquat>::value);
static_assert(std::is_trivially_copyable<glm::highp_dquat>::value);
static_assert(std::is_copy_constructible<glm::lowp_dquat>::value);
static_assert(std::is_copy_constructible<glm::mediump_dquat>::value);
static_assert(std::is_copy_constructible<glm::highp_dquat>::value);
static_assert(glm::lowp_dquat::length() == 4);
static_assert(glm::mediump_dquat::length() == 4);
static_assert(glm::highp_dquat::length() == 4);

static_assert(sizeof(glm::aligned_highp_dquat) == 32);
static_assert(alignof(glm::aligned_highp_dquat) == 32);
static_assert(sizeof(glm::packed_highp_dquat) == 32);
static_assert(alignof(glm::packed_highp_dquat) == 8);

static_assert(sizeof(glm::aligned_mediump_dquat) == 32);
static_assert(alignof(glm::aligned_mediump_dquat) == 32);
static_assert(sizeof(glm::packed_mediump_dquat) == 32);
static_assert(alignof(glm::packed_mediump_dquat) == 8);

static_assert(sizeof(glm::aligned_lowp_dquat) == 32);
static_assert(alignof(glm::aligned_lowp_dquat) == 32);
static_assert(sizeof(glm::packed_lowp_dquat) == 32);
static_assert(alignof(glm::packed_lowp_dquat) == 8);

static_assert(sizeof(glm::highp_dquat) == 32);
static_assert(sizeof(glm::mediump_dquat) == 32);
static_assert(sizeof(glm::lowp_dquat) == 32);
#ifdef GLM_FORCE_DEFAULT_ALIGNED_GENTYPES
static_assert(alignof(glm::highp_dquat) == 32);
static_assert(alignof(glm::mediump_dquat) == 32);
static_assert(alignof(glm::lowp_dquat) == 32);
#else
static_assert(alignof(glm::highp_dquat) == 8);
static_assert(alignof(glm::mediump_dquat) == 8);
static_assert(alignof(glm::lowp_dquat) == 8);
#endif
