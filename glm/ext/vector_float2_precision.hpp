/// @ref core
/// @file glm/ext/vector_float2_precision.hpp

#pragma once
#include "../detail/type_vec2.hpp"

namespace glm
{
	/// @addtogroup core_vector_precision
	/// @{

	/// 2 components vector of high single-qualifier floating-point numbers.
	///
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.5 Vectors</a>
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.7.2 Precision Qualifier</a>
	typedef vec<2, float, highp>		highp_vec2;

	/// 2 components vector of medium single-qualifier floating-point numbers.
	///
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.5 Vectors</a>
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.7.2 Precision Qualifier</a>
	typedef vec<2, float, mediump>		mediump_vec2;

	/// 2 components vector of low single-qualifier floating-point numbers.
	///
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.5 Vectors</a>
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.7.2 Precision Qualifier</a>
	typedef vec<2, float, lowp>			lowp_vec2;

	/// @}
}//namespace glm

#if GLM_CONFIG_CTOR_INIT == GLM_DISABLE
static_assert(std::is_trivially_default_constructible<glm::highp_vec2>::value);
static_assert(std::is_trivially_default_constructible<glm::mediump_vec2>::value);
static_assert(std::is_trivially_default_constructible<glm::lowp_vec2>::value);
#endif
static_assert(std::is_trivially_copy_assignable<glm::highp_vec2>::value);
static_assert(std::is_trivially_copy_assignable<glm::mediump_vec2>::value);
static_assert(std::is_trivially_copy_assignable<glm::lowp_vec2>::value);
static_assert(std::is_trivially_copyable<glm::highp_vec2>::value);
static_assert(std::is_trivially_copyable<glm::mediump_vec2>::value);
static_assert(std::is_trivially_copyable<glm::lowp_vec2>::value);
static_assert(std::is_copy_constructible<glm::highp_vec2>::value);
static_assert(std::is_copy_constructible<glm::mediump_vec2>::value);
static_assert(std::is_copy_constructible<glm::lowp_vec2>::value);
static_assert(glm::highp_vec2::length() == 2);
static_assert(glm::mediump_vec2::length() == 2);
static_assert(glm::lowp_vec2::length() == 2);
static_assert(sizeof(glm::highp_vec2) == sizeof(glm::mediump_vec2));
static_assert(sizeof(glm::highp_vec2) == sizeof(glm::lowp_vec2));

