/// @ref core
/// @file glm/ext/matrix_double4x3.hpp

#pragma once
#include "../detail/type_mat4x3.hpp"

namespace glm
{
	/// @addtogroup core_matrix
	/// @{

	/// 4 columns of 3 components matrix of double-precision floating-point numbers.
	///
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.6 Matrices</a>
	typedef mat<4, 3, double, defaultp>		dmat4x3;

	/// @}
}//namespace glm

#if GLM_CONFIG_CTOR_INIT == GLM_DISABLE
static_assert(std::is_trivially_default_constructible<glm::dmat4x3>::value);
#endif
static_assert(std::is_trivially_copy_assignable<glm::dmat4x3>::value);
static_assert(std::is_trivially_copyable<glm::dmat4x3>::value);
static_assert(std::is_copy_constructible<glm::dmat4x3>::value);
static_assert(glm::dmat4x3::length() == 4);
