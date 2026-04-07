/// @ref core
/// @file glm/ext/matrix_double4x1_precision.hpp

#pragma once
#include "../detail/type_mat4x1.hpp"

namespace glm
{
	/// @addtogroup core_matrix_precision
	/// @{

	/// 4 columns of 1 components matrix of double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	typedef mat<4, 1, double, lowp>		lowp_dmat4x1;

	/// 4 columns of 1 components matrix of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	typedef mat<4, 1, double, mediump>	mediump_dmat4x1;

	/// 4 columns of 1 components matrix of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	typedef mat<4, 1, double, highp>	highp_dmat4x1;

	/// @}
}//namespace glm

#if GLM_CONFIG_CTOR_INIT == GLM_DISABLE
static_assert(std::is_trivially_default_constructible<glm::lowp_dmat4x1>::value);
static_assert(std::is_trivially_default_constructible<glm::mediump_dmat4x1>::value);
static_assert(std::is_trivially_default_constructible<glm::highp_dmat4x1>::value);
#endif
static_assert(std::is_trivially_copy_assignable<glm::lowp_dmat4x1>::value);
static_assert(std::is_trivially_copy_assignable<glm::mediump_dmat4x1>::value);
static_assert(std::is_trivially_copy_assignable<glm::highp_dmat4x1>::value);
static_assert(std::is_trivially_copyable<glm::lowp_dmat4x1>::value);
static_assert(std::is_trivially_copyable<glm::mediump_dmat4x1>::value);
static_assert(std::is_trivially_copyable<glm::highp_dmat4x1>::value);
static_assert(std::is_copy_constructible<glm::lowp_dmat4x1>::value);
static_assert(std::is_copy_constructible<glm::mediump_dmat4x1>::value);
static_assert(std::is_copy_constructible<glm::highp_dmat4x1>::value);
static_assert(glm::lowp_dmat4x1::length() == 4);
static_assert(glm::mediump_dmat4x1::length() == 4);
static_assert(glm::highp_dmat4x1::length() == 4);
