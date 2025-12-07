/// @ref core
/// @file glm/ext/vector_double3.hpp

#pragma once
#include "../detail/type_vec3.hpp"

namespace glm
{
	/// @addtogroup core_vector
	/// @{

	/// 3 components vector of double-precision floating-point numbers.
	///
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.5 Vectors</a>
	typedef vec<3, double, defaultp>		dvec3;

	/// @}
}//namespace glm

#if GLM_CONFIG_CTOR_INIT == GLM_DISABLE
static_assert(std::is_trivially_default_constructible<glm::dvec3>::value);
#endif
static_assert(std::is_trivially_copy_assignable<glm::dvec3>::value);
static_assert(std::is_trivially_copyable<glm::dvec3>::value);
static_assert(std::is_copy_constructible<glm::dvec3>::value);
static_assert(glm::dvec3::length() == 3);
