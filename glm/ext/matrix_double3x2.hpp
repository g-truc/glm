/// @ref core
/// @file glm/ext/matrix_double3x2.hpp

#pragma once
#include "../detail/type_mat3x2.hpp"

namespace glm
{
	/// @addtogroup core_matrix
	/// @{

	/// 3 columns of 2 components matrix of double-precision floating-point numbers.
	///
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.6 Matrices</a>
	typedef mat<3, 2, double, defaultp>		dmat3x2;

	/// @}
}//namespace glm

#if GLM_CONFIG_CTOR_INIT == GLM_DISABLE
static_assert(std::is_trivially_default_constructible<glm::dmat3x2>::value);
#endif
static_assert(std::is_trivially_copy_assignable<glm::dmat3x2>::value);
static_assert(std::is_trivially_copyable<glm::dmat3x2>::value);
static_assert(std::is_copy_constructible<glm::dmat3x2>::value);
static_assert(glm::dmat3x2::length() == 3);
