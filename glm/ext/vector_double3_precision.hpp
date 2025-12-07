/// @ref core
/// @file glm/ext/vector_double3_precision.hpp

#pragma once
#include "../detail/type_vec3.hpp"

namespace glm
{
	/// @addtogroup core_vector_precision
	/// @{

	/// 3 components vector of high double-qualifier floating-point numbers.
	/// There is no guarantee on the actual qualifier.
	///
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.5 Vectors</a>
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.7.2 Precision Qualifier</a>
	typedef vec<3, double, highp>		highp_dvec3;

	/// 3 components vector of medium double-qualifier floating-point numbers.
	/// There is no guarantee on the actual qualifier.
	///
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.5 Vectors</a>
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.7.2 Precision Qualifier</a>
	typedef vec<3, double, mediump>		mediump_dvec3;

	/// 3 components vector of low double-qualifier floating-point numbers.
	/// There is no guarantee on the actual qualifier.
	///
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.5 Vectors</a>
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.7.2 Precision Qualifier</a>
	typedef vec<3, double, lowp>		lowp_dvec3;

	/// @}
}//namespace glm

#if GLM_CONFIG_CTOR_INIT == GLM_DISABLE
static_assert(std::is_trivially_default_constructible<glm::highp_dvec3>::value);
static_assert(std::is_trivially_default_constructible<glm::mediump_dvec3>::value);
static_assert(std::is_trivially_default_constructible<glm::lowp_dvec3>::value);
#endif
static_assert(std::is_trivially_copy_assignable<glm::highp_dvec3>::value);
static_assert(std::is_trivially_copy_assignable<glm::mediump_dvec3>::value);
static_assert(std::is_trivially_copy_assignable<glm::lowp_dvec3>::value);
static_assert(std::is_trivially_copyable<glm::highp_dvec3>::value);
static_assert(std::is_trivially_copyable<glm::mediump_dvec3>::value);
static_assert(std::is_trivially_copyable<glm::lowp_dvec3>::value);
static_assert(std::is_copy_constructible<glm::highp_dvec3>::value);
static_assert(std::is_copy_constructible<glm::mediump_dvec3>::value);
static_assert(std::is_copy_constructible<glm::lowp_dvec3>::value);
static_assert(glm::highp_dvec3::length() == 3);
static_assert(glm::mediump_dvec3::length() == 3);
static_assert(glm::lowp_dvec3::length() == 3);
static_assert(sizeof(glm::highp_dvec3) == sizeof(glm::mediump_dvec3));
static_assert(sizeof(glm::highp_dvec3) == sizeof(glm::lowp_dvec3));
