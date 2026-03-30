/// @ref core
/// @file glm/ext/matrix_float4x1.hpp

#pragma once
#include "../detail/type_mat4x1.hpp"

namespace glm
{
	/// @addtogroup core_matrix
	/// @{

	/// 4 columns of 1 components matrix of single-precision floating-point numbers.
	typedef mat<4, 1, float, defaultp>		mat4x1;

	/// @}
}//namespace glm

#if GLM_CONFIG_CTOR_INIT == GLM_DISABLE
static_assert(std::is_trivially_default_constructible<glm::mat4x1>::value);
#endif
static_assert(std::is_trivially_copy_assignable<glm::mat4x1>::value);
static_assert(std::is_trivially_copyable<glm::mat4x1>::value);
static_assert(std::is_copy_constructible<glm::mat4x1>::value);
static_assert(glm::mat4x1::length() == 4);

