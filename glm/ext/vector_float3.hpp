/// @ref core
/// @file glm/ext/vector_float3.hpp

#pragma once
#include "../detail/type_vec3.hpp"

namespace glm
{
	/// @addtogroup core_vector
	/// @{

	/// 3 components vector of single-precision floating-point numbers.
	///
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.5 Vectors</a>
	typedef vec<3, float, defaultp>		vec3;

	/// @}
}//namespace glm

#if GLM_CONFIG_CTOR_INIT == GLM_DISABLE
static_assert(std::is_trivially_default_constructible<glm::vec3>::value);
#endif
static_assert(std::is_trivially_copy_assignable<glm::vec3>::value);
static_assert(std::is_trivially_copyable<glm::vec3>::value);
static_assert(std::is_copy_constructible<glm::vec3>::value);
static_assert(glm::vec3::length() == 3);
