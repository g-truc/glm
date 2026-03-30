/// @ref core
/// @file glm/ext/matrix_float1x2.hpp

#pragma once
#include "../detail/type_mat1x2.hpp"

namespace glm
{
	/// @addtogroup core_matrix
	/// @{

	/// 1 columns of 2 components matrix of single-precision floating-point numbers.
	typedef mat<1, 2, float, defaultp>		mat1x2;

	/// @}
}//namespace glm

#if GLM_CONFIG_CTOR_INIT == GLM_DISABLE
static_assert(std::is_trivially_default_constructible<glm::mat1x2>::value);
#endif
static_assert(std::is_trivially_copy_assignable<glm::mat1x2>::value);
static_assert(std::is_trivially_copyable<glm::mat1x2>::value);
static_assert(std::is_copy_constructible<glm::mat1x2>::value);
static_assert(glm::mat1x2::length() == 1);

