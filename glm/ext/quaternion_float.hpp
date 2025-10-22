/// @ref ext_quaternion_float
/// @file glm/ext/quaternion_float.hpp
///
/// @defgroup ext_quaternion_float GLM_EXT_quaternion_float
/// @ingroup ext
///
/// Exposes single-precision floating point quaternion type.
///
/// Include <glm/ext/quaternion_float.hpp> to use the features of this extension.
///
/// @see ext_quaternion_double
/// @see ext_quaternion_float_precision
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
#	pragma message("GLM: GLM_EXT_quaternion_float extension included")
#endif

namespace glm
{
	/// @addtogroup ext_quaternion_float
	/// @{

	/// Quaternion of aligned single-precision floating-point numbers.
	typedef qua<float, defaultp, sizeof(float) * 4>		aligned_quat;

	/// Quaternion of packed single-precision floating-point numbers.
	typedef qua<float, defaultp>						packed_quat;

#ifdef GLM_FORCE_DEFAULT_ALIGNED_GENTYPES
	/// Quaternion of single-precision floating-point numbers.
	typedef aligned_quat								quat;
#else
	/// Quaternion of single-precision floating-point numbers.
	typedef packed_quat									quat;
#endif

	/// @}
} //namespace glm

#if GLM_CONFIG_CTOR_INIT == GLM_DISABLE
static_assert(std::is_trivially_default_constructible<glm::quat>::value);
#endif
static_assert(std::is_trivially_copy_assignable<glm::quat>::value);
static_assert(std::is_trivially_copyable<glm::quat>::value);
static_assert(std::is_copy_constructible<glm::quat>::value);
static_assert(glm::quat::length() == 4);

static_assert(sizeof(glm::aligned_quat) == 16);
static_assert(alignof(glm::aligned_quat) == 16);
static_assert(sizeof(glm::packed_quat) == 16);
// static_assert(alignof(glm::packed_quat) == 4); FIXME

static_assert(sizeof(glm::quat) == 16);
#ifdef GLM_FORCE_DEFAULT_ALIGNED_GENTYPES
static_assert(alignof(glm::quat) == 16);
#else
static_assert(alignof(glm::quat) == 4);
#endif
