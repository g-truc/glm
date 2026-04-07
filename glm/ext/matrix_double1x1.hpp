/// @ref core
/// @file glm/ext/matrix_double1x1.hpp

#pragma once
#include "../detail/type_mat1x1.hpp"

namespace glm
{
	/// @addtogroup core_matrix
	/// @{

	/// 1 columns of 1 components matrix of double-precision floating-point numbers.
	typedef mat<1, 1, double, defaultp>		dmat1x1;

	/// 1 columns of 1 components matrix of double-precision floating-point numbers.
	typedef mat<1, 1, double, defaultp>		dmat1;

	/// @}
}//namespace glm

#if GLM_CONFIG_CTOR_INIT == GLM_DISABLE
static_assert(std::is_trivially_default_constructible<glm::dmat1x1>::value);
static_assert(std::is_trivially_default_constructible<glm::dmat1>::value);
#endif
static_assert(std::is_trivially_copy_assignable<glm::dmat1x1>::value);
static_assert(std::is_trivially_copy_assignable<glm::dmat1>::value);
static_assert(std::is_trivially_copyable<glm::dmat1x1>::value);
static_assert(std::is_trivially_copyable<glm::dmat1>::value);
static_assert(std::is_copy_constructible<glm::dmat1x1>::value);
static_assert(std::is_copy_constructible<glm::dmat1>::value);
static_assert(glm::dmat1x1::length() == 1);
static_assert(glm::dmat1::length() == 1);

