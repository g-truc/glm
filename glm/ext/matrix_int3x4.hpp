/// @ref ext_matrix_int3x4
/// @file glm/ext/matrix_int3x4.hpp
///
/// @see core (dependence)
///
/// @defgroup ext_matrix_int3x4 GLM_EXT_matrix_int3x4
/// @ingroup ext
///
/// Include <glm/ext/matrix_int3x4.hpp> to use the features of this extension.
///
/// Defines a number of matrices with integer types.

#pragma once

// Dependency:
#include "../mat3x4.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_EXT_matrix_int3x4 extension included")
#endif

namespace glm
{
	/// @addtogroup ext_matrix_int3x4
	/// @{

	/// Signed integer 3x4 matrix.
	///
	/// @see ext_matrix_int3x4
	typedef mat<3, 4, int, defaultp>	imat3x4;

	/// @}
}//namespace glm

#if GLM_CONFIG_CTOR_INIT == GLM_DISABLE
static_assert(std::is_trivially_default_constructible<glm::imat3x4>::value);
#endif
static_assert(std::is_trivially_copy_assignable<glm::imat3x4>::value);
static_assert(std::is_trivially_copyable<glm::imat3x4>::value);
static_assert(std::is_copy_constructible<glm::imat3x4>::value);
static_assert(glm::imat3x4::length() == 3);
