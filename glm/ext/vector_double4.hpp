/// @ref core
/// @file glm/ext/vector_double4.hpp

#pragma once
#include "../detail/type_vec4.hpp"

namespace glm
{
	/// @addtogroup core_vector
	/// @{

	/// 4 components vector of double-precision floating-point numbers.
	///
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.5 Vectors</a>
	typedef vec<4, double, defaultp>		dvec4;

	/// @}
}//namespace glm

#if GLM_CONFIG_CTOR_INIT == GLM_DISABLE
static_assert(std::is_trivially_default_constructible<glm::dvec4>::value);
#endif
static_assert(std::is_trivially_copy_assignable<glm::dvec4>::value);
static_assert(std::is_trivially_copyable<glm::dvec4>::value);
static_assert(std::is_copy_constructible<glm::dvec4>::value);
static_assert(glm::dvec4::length() == 4);
