/// @ref core
/// @file glm/ext/matrix_double2x1.hpp

#pragma once
#include "../detail/type_mat2x1.hpp"

namespace glm
{
	/// @addtogroup core_matrix
	/// @{

	/// 1 columns of 2 components matrix of double-precision floating-point numbers.
	typedef mat<2, 1, double, defaultp>		dmat2x1;

	/// @}
}//namespace glm

#if GLM_CONFIG_CTOR_INIT == GLM_DISABLE
static_assert(std::is_trivially_default_constructible<glm::dmat2x1>::value);
#endif
static_assert(std::is_trivially_copy_assignable<glm::dmat2x1>::value);
static_assert(std::is_trivially_copyable<glm::dmat2x1>::value);
static_assert(std::is_copy_constructible<glm::dmat2x1>::value);
static_assert(glm::dmat2x1::length() == 2);
