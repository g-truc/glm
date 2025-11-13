/// @ref core
/// @file glm/ext/matrix_float2x3.hpp

#pragma once
#include "../detail/type_mat2x3.hpp"

namespace glm
{
	/// @addtogroup core_matrix
	/// @{

	/// 2 columns of 3 components matrix of single-precision floating-point numbers.
	///
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.6 Matrices</a>
	typedef mat<2, 3, float, defaultp>		mat2x3;

	/// @}
}//namespace glm

#if GLM_CONFIG_CTOR_INIT == GLM_DISABLE
static_assert(std::is_trivially_default_constructible<glm::mat2x3>::value);
#endif
static_assert(std::is_trivially_copy_assignable<glm::mat2x3>::value);
static_assert(std::is_trivially_copyable<glm::mat2x3>::value);
static_assert(std::is_copy_constructible<glm::mat2x3>::value);
static_assert(glm::mat2x3::length() == 2);

