/// @ref core
/// @file glm/ext/matrix_double2x4.hpp

#pragma once
#include "../detail/type_mat2x4.hpp"

namespace glm
{
	/// @addtogroup core_matrix
	/// @{

	/// 2 columns of 4 components matrix of double-precision floating-point numbers.
	///
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.6 Matrices</a>
	typedef mat<2, 4, double, defaultp>		dmat2x4;

	/// @}
}//namespace glm

#if GLM_CONFIG_CTOR_INIT == GLM_DISABLE
static_assert(std::is_trivially_default_constructible<glm::dmat2x4>::value);
#endif
static_assert(std::is_trivially_copy_assignable<glm::dmat2x4>::value);
static_assert(std::is_trivially_copyable<glm::dmat2x4>::value);
static_assert(std::is_copy_constructible<glm::dmat2x4>::value);
static_assert(glm::dmat2x4::length() == 2);
