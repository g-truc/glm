/// @ref core
/// @file glm/ext/matrix_double3x1.hpp

#pragma once
#include "../detail/type_mat3x1.hpp"

namespace glm
{
	/// @addtogroup core_matrix
	/// @{

	/// 3 columns of 1 components matrix of double-precision floating-point numbers.
	typedef mat<3, 1, double, defaultp>		dmat3x1;

	/// @}
}//namespace glm

#if GLM_CONFIG_CTOR_INIT == GLM_DISABLE
static_assert(std::is_trivially_default_constructible<glm::dmat3x1>::value);
#endif
static_assert(std::is_trivially_copy_assignable<glm::dmat3x1>::value);
static_assert(std::is_trivially_copyable<glm::dmat3x1>::value);
static_assert(std::is_copy_constructible<glm::dmat3x1>::value);
static_assert(glm::dmat3x1::length() == 3);
