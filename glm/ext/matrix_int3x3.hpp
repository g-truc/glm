/// @ref ext_matrix_int3x3
/// @file glm/ext/matrix_int3x3.hpp
///
/// @see core (dependence)
///
/// @defgroup ext_matrix_int3x3 GLM_EXT_matrix_int3x3
/// @ingroup ext
///
/// Include <glm/ext/matrix_int3x3.hpp> to use the features of this extension.
///
/// Defines a number of matrices with integer types.

#pragma once

// Dependency:
#include "../mat3x3.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_EXT_matrix_int3x3 extension included")
#endif

namespace glm
{
	/// @addtogroup ext_matrix_int3x3
	/// @{

	/// Signed integer 3x3 matrix.
	///
	/// @see ext_matrix_int3x3
	typedef mat<3, 3, int, defaultp>	imat3x3;

	/// Signed integer 3x3 matrix.
	///
	/// @see ext_matrix_int3x3
	typedef mat<3, 3, int, defaultp>	imat3;

	/// @}
}//namespace glm

#if GLM_CONFIG_CTOR_INIT == GLM_DISABLE
static_assert(std::is_trivially_default_constructible<glm::imat3x3>::value);
static_assert(std::is_trivially_default_constructible<glm::imat3>::value);
#endif
static_assert(std::is_trivially_copy_assignable<glm::imat3x3>::value);
static_assert(std::is_trivially_copy_assignable<glm::imat3>::value);
static_assert(std::is_trivially_copyable<glm::imat3x3>::value);
static_assert(std::is_trivially_copyable<glm::imat3>::value);
static_assert(std::is_copy_constructible<glm::imat3x3>::value);
static_assert(std::is_copy_constructible<glm::imat3>::value);
static_assert(glm::imat3x3::length() == 3);
static_assert(glm::imat3::length() == 3);

