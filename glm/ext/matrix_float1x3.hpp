/// @ref core
/// @file glm/ext/matrix_float1x3.hpp

#pragma once
#include "../detail/type_mat1x3.hpp"

namespace glm
{
	/// @addtogroup core_matrix
	/// @{

	/// 1 columns of 3 components matrix of single-precision floating-point numbers.
	typedef mat<1, 3, float, defaultp>		mat1x3;

	/// @}
}//namespace glm

#if GLM_CONFIG_CTOR_INIT == GLM_DISABLE
static_assert(std::is_trivially_default_constructible<glm::mat1x3>::value);
#endif
static_assert(std::is_trivially_copy_assignable<glm::mat1x3>::value);
static_assert(std::is_trivially_copyable<glm::mat1x3>::value);
static_assert(std::is_copy_constructible<glm::mat1x3>::value);
static_assert(glm::mat1x3::length() == 1);

