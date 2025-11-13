/// @ref core
/// @file glm/ext/matrix_double3x3_precision.hpp

#pragma once
#include "../detail/type_mat3x3.hpp"

namespace glm
{
	/// @addtogroup core_matrix_precision
	/// @{

	/// 3 columns of 3 components matrix of double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	///
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.6 Matrices</a>
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.7.2 Precision Qualifier</a>
	typedef mat<3, 3, double, lowp>		lowp_dmat3;

	/// 3 columns of 3 components matrix of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	///
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.6 Matrices</a>
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.7.2 Precision Qualifier</a>
	typedef mat<3, 3, double, mediump>	mediump_dmat3;

	/// 3 columns of 3 components matrix of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	///
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.6 Matrices</a>
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.7.2 Precision Qualifier</a>
	typedef mat<3, 3, double, highp>	highp_dmat3;

	/// 3 columns of 3 components matrix of double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	///
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.6 Matrices</a>
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.7.2 Precision Qualifier</a>
	typedef mat<3, 3, double, lowp>		lowp_dmat3x3;

	/// 3 columns of 3 components matrix of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	///
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.6 Matrices</a>
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.7.2 Precision Qualifier</a>
	typedef mat<3, 3, double, mediump>	mediump_dmat3x3;

	/// 3 columns of 3 components matrix of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	///
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.6 Matrices</a>
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.7.2 Precision Qualifier</a>
	typedef mat<3, 3, double, highp>	highp_dmat3x3;

	/// @}
}//namespace glm

#if GLM_CONFIG_CTOR_INIT == GLM_DISABLE
static_assert(std::is_trivially_default_constructible<glm::lowp_dmat3x3>::value);
static_assert(std::is_trivially_default_constructible<glm::mediump_dmat3x3>::value);
static_assert(std::is_trivially_default_constructible<glm::highp_dmat3x3>::value);
static_assert(std::is_trivially_default_constructible<glm::lowp_dmat3>::value);
static_assert(std::is_trivially_default_constructible<glm::mediump_dmat3>::value);
static_assert(std::is_trivially_default_constructible<glm::highp_dmat3>::value);
#endif
static_assert(std::is_trivially_copy_assignable<glm::lowp_dmat3x3>::value);
static_assert(std::is_trivially_copy_assignable<glm::mediump_dmat3x3>::value);
static_assert(std::is_trivially_copy_assignable<glm::highp_dmat3x3>::value);
static_assert(std::is_trivially_copy_assignable<glm::lowp_dmat3>::value);
static_assert(std::is_trivially_copy_assignable<glm::mediump_dmat3>::value);
static_assert(std::is_trivially_copy_assignable<glm::highp_dmat3>::value);
static_assert(std::is_trivially_copyable<glm::lowp_dmat3x3>::value);
static_assert(std::is_trivially_copyable<glm::mediump_dmat3x3>::value);
static_assert(std::is_trivially_copyable<glm::highp_dmat3x3>::value);
static_assert(std::is_trivially_copyable<glm::lowp_dmat3>::value);
static_assert(std::is_trivially_copyable<glm::mediump_dmat3>::value);
static_assert(std::is_trivially_copyable<glm::highp_dmat3>::value);
static_assert(std::is_copy_constructible<glm::lowp_dmat3x3>::value);
static_assert(std::is_copy_constructible<glm::mediump_dmat3x3>::value);
static_assert(std::is_copy_constructible<glm::highp_dmat3x3>::value);
static_assert(std::is_copy_constructible<glm::lowp_dmat3>::value);
static_assert(std::is_copy_constructible<glm::mediump_dmat3>::value);
static_assert(std::is_copy_constructible<glm::highp_dmat3>::value);
static_assert(glm::lowp_dmat3x3::length() == 3);
static_assert(glm::mediump_dmat3x3::length() == 3);
static_assert(glm::highp_dmat3x3::length() == 3);
static_assert(glm::lowp_dmat3::length() == 3);
static_assert(glm::mediump_dmat3::length() == 3);
static_assert(glm::highp_dmat3::length() == 3);
