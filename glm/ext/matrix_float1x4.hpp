/// @ref core
/// @file glm/ext/matrix_float1x4.hpp

#pragma once
#include "../detail/type_mat1x4.hpp"

namespace glm
{
	/// @addtogroup core_matrix
	/// @{

	/// 1 columns of 4 components matrix of single-precision floating-point numbers.
	typedef mat<1, 4, float, defaultp>		mat1x4;

	/// @}
}//namespace glm

#if GLM_CONFIG_CTOR_INIT == GLM_DISABLE
static_assert(std::is_trivially_default_constructible<glm::mat1x4>::value);
#endif
static_assert(std::is_trivially_copy_assignable<glm::mat1x4>::value);
static_assert(std::is_trivially_copyable<glm::mat1x4>::value);
static_assert(std::is_copy_constructible<glm::mat1x4>::value);
static_assert(glm::mat1x4::length() == 1);

