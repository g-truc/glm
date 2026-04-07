/// @ref core
/// @file glm/ext/matrix_float3x1.hpp

#pragma once
#include "../detail/type_mat3x1.hpp"

namespace glm
{
	/// @addtogroup core_matrix
	/// @{

	/// 3 columns of 1 components matrix of single-precision floating-point numbers.
	typedef mat<3, 1, float, defaultp>		mat3x1;

	/// @}
}//namespace glm

#if GLM_CONFIG_CTOR_INIT == GLM_DISABLE
static_assert(std::is_trivially_default_constructible<glm::mat3x1>::value);
#endif
static_assert(std::is_trivially_copy_assignable<glm::mat3x1>::value);
static_assert(std::is_trivially_copyable<glm::mat3x1>::value);
static_assert(std::is_copy_constructible<glm::mat3x1>::value);
static_assert(glm::mat3x1::length() == 1);

