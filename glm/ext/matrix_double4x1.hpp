/// @ref core
/// @file glm/ext/matrix_double4x1.hpp

#pragma once
#include "../detail/type_mat4x1.hpp"

namespace glm
{
	/// @addtogroup core_matrix
	/// @{

	/// 4 columns of 1 components matrix of double-precision floating-point numbers.
	typedef mat<4, 1, double, defaultp>		dmat4x1;

	/// @}
}//namespace glm

#if GLM_CONFIG_CTOR_INIT == GLM_DISABLE
static_assert(std::is_trivially_default_constructible<glm::dmat4x1>::value);
#endif
static_assert(std::is_trivially_copy_assignable<glm::dmat4x1>::value);
static_assert(std::is_trivially_copyable<glm::dmat4x1>::value);
static_assert(std::is_copy_constructible<glm::dmat4x1>::value);
static_assert(glm::dmat4x1::length() == 4);
