/// @ref core
/// @file glm/ext/matrix_double3x3.hpp

#pragma once
#include "../detail/type_mat3x3.hpp"

namespace glm
{
	/// @addtogroup core_matrix
	/// @{

	/// 3 columns of 3 components matrix of double-precision floating-point numbers.
	///
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.6 Matrices</a>
	typedef mat<3, 3, double, defaultp>		dmat3x3;

	/// 3 columns of 3 components matrix of double-precision floating-point numbers.
	///
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.6 Matrices</a>
	typedef mat<3, 3, double, defaultp>		dmat3;

	/// @}
}//namespace glm

#if GLM_CONFIG_CTOR_INIT == GLM_DISABLE
static_assert(std::is_trivially_default_constructible<glm::dmat3x3>::value);
static_assert(std::is_trivially_default_constructible<glm::dmat3>::value);
#endif
static_assert(std::is_trivially_copy_assignable<glm::dmat3x3>::value);
static_assert(std::is_trivially_copy_assignable<glm::dmat3>::value);
static_assert(std::is_trivially_copyable<glm::dmat3x3>::value);
static_assert(std::is_trivially_copyable<glm::dmat3>::value);
static_assert(std::is_copy_constructible<glm::dmat3x3>::value);
static_assert(std::is_copy_constructible<glm::dmat3>::value);
static_assert(glm::dmat3x3::length() == 3);
static_assert(glm::dmat3::length() == 3);

