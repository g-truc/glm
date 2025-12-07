/// @ref core
/// @file glm/ext/vector_double2_precision.hpp

#pragma once
#include "../detail/type_vec2.hpp"

namespace glm
{
	/// @addtogroup core_vector_precision
	/// @{

	/// 2 components vector of high double-qualifier floating-point numbers.
	///
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.5 Vectors</a>
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.7.2 Precision Qualifier</a>
	typedef vec<2, double, highp>		highp_dvec2;

	/// 2 components vector of medium double-qualifier floating-point numbers.
	///
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.5 Vectors</a>
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.7.2 Precision Qualifier</a>
	typedef vec<2, double, mediump>		mediump_dvec2;

	/// 2 components vector of low double-qualifier floating-point numbers.
	///
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.5 Vectors</a>
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.7.2 Precision Qualifier</a>
	typedef vec<2, double, lowp>		lowp_dvec2;

	/// @}
}//namespace glm

#if GLM_CONFIG_CTOR_INIT == GLM_DISABLE
static_assert(std::is_trivially_default_constructible<glm::highp_dvec2>::value);
static_assert(std::is_trivially_default_constructible<glm::mediump_dvec2>::value);
static_assert(std::is_trivially_default_constructible<glm::lowp_dvec2>::value);
#endif
static_assert(std::is_trivially_copy_assignable<glm::highp_dvec2>::value);
static_assert(std::is_trivially_copy_assignable<glm::mediump_dvec2>::value);
static_assert(std::is_trivially_copy_assignable<glm::lowp_dvec2>::value);
static_assert(std::is_trivially_copyable<glm::highp_dvec2>::value);
static_assert(std::is_trivially_copyable<glm::mediump_dvec2>::value);
static_assert(std::is_trivially_copyable<glm::lowp_dvec2>::value);
static_assert(std::is_copy_constructible<glm::highp_dvec2>::value);
static_assert(std::is_copy_constructible<glm::mediump_dvec2>::value);
static_assert(std::is_copy_constructible<glm::lowp_dvec2>::value);
static_assert(glm::highp_dvec2::length() == 2);
static_assert(glm::mediump_dvec2::length() == 2);
static_assert(glm::lowp_dvec2::length() == 2);
static_assert(sizeof(glm::highp_dvec2) == sizeof(glm::mediump_dvec2));
static_assert(sizeof(glm::highp_dvec2) == sizeof(glm::lowp_dvec2));

