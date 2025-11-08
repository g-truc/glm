/// @ref ext_quaternion_double
/// @file glm/ext/quaternion_double.hpp
///
/// @defgroup ext_quaternion_double GLM_EXT_quaternion_double
/// @ingroup ext
///
/// Exposes double-precision floating point quaternion type.
///
/// Include <glm/ext/quaternion_double.hpp> to use the features of this extension.
///
/// @see ext_quaternion_float
/// @see ext_quaternion_double_precision
/// @see ext_quaternion_common
/// @see ext_quaternion_exponential
/// @see ext_quaternion_geometric
/// @see ext_quaternion_relational
/// @see ext_quaternion_transform
/// @see ext_quaternion_trigonometric

#pragma once

// Dependency:
#include "../detail/type_quat.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_EXT_quaternion_double extension included")
#endif

namespace glm
{
	/// @addtogroup ext_quaternion_double
	/// @{

	/// Quaternion of aligned double-precision floating-point numbers.
	typedef qua<double, defaultp, sizeof(double) * 4>	aligned_dquat;

	/// Quaternion of packed double-precision floating-point numbers.
	typedef qua<double, defaultp>						packed_dquat;

#ifdef GLM_FORCE_DEFAULT_ALIGNED_GENTYPES
	/// Quaternion of double-precision floating-point numbers.
	typedef aligned_dquat								dquat;
#else
	/// Quaternion of double-precision floating-point numbers.
	typedef packed_dquat								dquat;
#endif

	/// @}
} //namespace glm

#if GLM_CONFIG_CTOR_INIT == GLM_DISABLE
static_assert(std::is_trivially_default_constructible<glm::dquat>::value);
#endif
static_assert(std::is_trivially_copy_assignable<glm::dquat>::value);
static_assert(std::is_trivially_copyable<glm::dquat>::value);
static_assert(std::is_copy_constructible<glm::dquat>::value);
static_assert(glm::dquat::length() == 4);

static_assert(sizeof(glm::aligned_dquat) == 32);
static_assert(alignof(glm::aligned_dquat) == 32);
static_assert(sizeof(glm::packed_dquat) == 32);
// static_assert(alignof(glm::packed_dquat) == 8); FIXME

static_assert(sizeof(glm::dquat) == 32);
#ifdef GLM_FORCE_DEFAULT_ALIGNED_GENTYPES
static_assert(alignof(glm::dquat) == 32);
#else
static_assert(alignof(glm::dquat) == 8);
#endif

