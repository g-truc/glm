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

	/// Quaternion of single-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		lowp_quat = qua<float, lowp>;

	/// Quaternion of single-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		mediump_quat = qua<float, mediump>;

	/// Quaternion of single-precision floating-point numbers using high precision arithmetic in term of ULPs.
	using		highp_quat = qua<float, highp>;

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
