/// @ref core
/// @file glm/ext/vector_int2.hpp

#pragma once
#include "../detail/type_vec2.hpp"

namespace glm
{
	/// @addtogroup core_vector
	/// @{

	/// 2 components vector of signed integer numbers.
	///
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.5 Vectors</a>
	typedef vec<2, int, defaultp>		ivec2;

	/// @}
}//namespace glm

#if GLM_CONFIG_CTOR_INIT == GLM_DISABLE
static_assert(std::is_trivially_default_constructible<glm::ivec2>::value);
#endif
static_assert(std::is_trivially_copy_assignable<glm::ivec2>::value);
static_assert(std::is_trivially_copyable<glm::ivec2>::value);
static_assert(std::is_copy_constructible<glm::ivec2>::value);
static_assert(glm::ivec2::length() == 2);

