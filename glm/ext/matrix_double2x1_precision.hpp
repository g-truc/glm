/// @ref core
/// @file glm/ext/matrix_double2x1_precision.hpp

#pragma once
#include "../detail/type_mat2x1.hpp"

namespace glm
{
	/// @addtogroup core_matrix_precision
	/// @{

	/// 2 columns of 1 components matrix of double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	typedef mat<2, 1, double, lowp>		lowp_dmat2x1;

	/// 2 columns of 1 components matrix of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	typedef mat<2, 1, double, mediump>	mediump_dmat2x1;

	/// 2 columns of 1 components matrix of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	typedef mat<2, 1, double, highp>	highp_dmat2x1;

	/// @}
}//namespace glm

#if GLM_CONFIG_CTOR_INIT == GLM_DISABLE
static_assert(std::is_trivially_default_constructible<glm::lowp_dmat2x1>::value);
static_assert(std::is_trivially_default_constructible<glm::mediump_dmat2x1>::value);
static_assert(std::is_trivially_default_constructible<glm::highp_dmat2x1>::value);
#endif
static_assert(std::is_trivially_copy_assignable<glm::lowp_dmat2x1>::value);
static_assert(std::is_trivially_copy_assignable<glm::mediump_dmat2x1>::value);
static_assert(std::is_trivially_copy_assignable<glm::highp_dmat2x1>::value);
static_assert(std::is_trivially_copyable<glm::lowp_dmat2x1>::value);
static_assert(std::is_trivially_copyable<glm::mediump_dmat2x1>::value);
static_assert(std::is_trivially_copyable<glm::highp_dmat2x1>::value);
static_assert(std::is_copy_constructible<glm::lowp_dmat2x1>::value);
static_assert(std::is_copy_constructible<glm::mediump_dmat2x1>::value);
static_assert(std::is_copy_constructible<glm::highp_dmat2x1>::value);
static_assert(glm::lowp_dmat2x1::length() == 2);
static_assert(glm::mediump_dmat2x1::length() == 2);
static_assert(glm::highp_dmat2x1::length() == 2);
