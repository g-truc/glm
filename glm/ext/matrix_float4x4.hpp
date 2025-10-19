/// @ref core
/// @file glm/ext/matrix_float4x4.hpp

#pragma once
#include "../detail/type_mat4x4.hpp"

namespace glm
{
	/// @ingroup core_matrix
	/// @{

	/// 4 columns of 4 components matrix of single-precision floating-point numbers.
	///
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.6 Matrices</a>
	typedef mat<4, 4, float, defaultp>			mat4x4;

	/// 4 columns of 4 components matrix of single-precision floating-point numbers.
	///
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.6 Matrices</a>
	typedef mat<4, 4, float, defaultp>			mat4;

	/// @}
}//namespace glm

#if GLM_CONFIG_CTOR_INIT == GLM_DISABLE
static_assert(std::is_trivially_default_constructible<glm::mat4x4>::value);
static_assert(std::is_trivially_default_constructible<glm::mat4>::value);
#endif
static_assert(std::is_trivially_copy_assignable<glm::mat4x4>::value);
static_assert(std::is_trivially_copy_assignable<glm::mat4>::value);
static_assert(std::is_trivially_copyable<glm::mat4x4>::value);
static_assert(std::is_trivially_copyable<glm::mat4>::value);
static_assert(std::is_copy_constructible<glm::mat4x4>::value);
static_assert(std::is_copy_constructible<glm::mat4>::value);
static_assert(glm::mat4x4::length() == 4);
static_assert(glm::mat4::length() == 4);
