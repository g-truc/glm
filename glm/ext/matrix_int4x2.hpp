/// @ref ext_matrix_int4x2
/// @file glm/ext/matrix_int4x2.hpp
///
/// @see core (dependence)
///
/// @defgroup ext_matrix_int4x2 GLM_EXT_matrix_int4x2
/// @ingroup ext
///
/// Include <glm/ext/matrix_int4x2.hpp> to use the features of this extension.
///
/// Defines a number of matrices with integer types.

#pragma once

// Dependency:
#include "../mat4x2.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_EXT_matrix_int4x2 extension included")
#endif

namespace glm
{
	/// @addtogroup ext_matrix_int4x2
	/// @{

	/// Signed integer 4x2 matrix.
	///
	/// @see ext_matrix_int4x2
	typedef mat<4, 2, int, defaultp>	imat4x2;

	/// @}
}//namespace glm

#if GLM_CONFIG_CTOR_INIT == GLM_DISABLE
static_assert(std::is_trivially_default_constructible<glm::imat4x2>::value);
#endif
static_assert(std::is_trivially_copy_assignable<glm::imat4x2>::value);
static_assert(std::is_trivially_copyable<glm::imat4x2>::value);
static_assert(std::is_copy_constructible<glm::imat4x2>::value);
static_assert(glm::imat4x2::length() == 4);
