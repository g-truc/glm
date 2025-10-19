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

	/// Quaternion of double-precision floating-point numbers using high precision arithmetic in term of ULPs.
	///
	/// @see ext_quaternion_double_precision
	typedef qua<double, lowp>		lowp_dquat;

	/// Quaternion of medium double-qualifier floating-point numbers using high precision arithmetic in term of ULPs.
	///
	/// @see ext_quaternion_double_precision
	typedef qua<double, mediump>	mediump_dquat;

	/// Quaternion of high double-qualifier floating-point numbers using high precision arithmetic in term of ULPs.
	///
	/// @see ext_quaternion_double_precision
	typedef qua<double, highp>		highp_dquat;

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
