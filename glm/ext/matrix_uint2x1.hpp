/// @ref ext_matrix_uint2x1
/// @file glm/ext/matrix_uint2x1.hpp
///
/// @see core (dependence)
///
/// @defgroup ext_matrix_uint2x1 GLM_EXT_matrix_uint2x1
/// @ingroup ext
///
/// Include <glm/ext/matrix_uint2x1.hpp> to use the features of this extension.
///
/// Defines a number of matrices with integer types.

#pragma once

// Dependency:
#include "../mat2x1.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_EXT_matrix_uint2x1 extension included")
#endif

namespace glm
{
	/// @addtogroup ext_matrix_uint2x1
	/// @{

	/// Unsigned integer 2x1 matrix.
	///
	/// @see ext_matrix_uint2x1
	typedef mat<2, 1, uint, defaultp>	umat2x1;

	/// @}
}//namespace glm

#if GLM_CONFIG_CTOR_INIT == GLM_DISABLE
static_assert(std::is_trivially_default_constructible<glm::umat2x1>::value);
#endif
static_assert(std::is_trivially_copy_assignable<glm::umat2x1>::value);
static_assert(std::is_trivially_copyable<glm::umat2x1>::value);
static_assert(std::is_copy_constructible<glm::umat2x1>::value);
static_assert(glm::umat2x1::length() == 2);

