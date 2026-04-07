/// @ref gtc_matrix_integer
/// @file glm/gtc/matrix_integer.hpp
///
/// @see core (dependence)
///
/// @defgroup gtc_matrix_integer GLM_GTC_matrix_integer
/// @ingroup gtc
///
/// Include <glm/gtc/matrix_integer.hpp> to use the features of this extension.
///
/// Defines a number of matrices with integer types.

#pragma once

// Dependency:
#include "../mat2x2.hpp"
#include "../mat2x3.hpp"
#include "../mat2x4.hpp"
#include "../mat3x2.hpp"
#include "../mat3x3.hpp"
#include "../mat3x4.hpp"
#include "../mat4x2.hpp"
#include "../mat4x3.hpp"
#include "../mat4x4.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_GTC_matrix_integer extension included")
#endif

namespace glm
{
	/// @addtogroup gtc_matrix_integer
	/// @{

	/// High-qualifier signed integer 2x2 matrix.
	/// @see gtc_matrix_integer
	using				highp_imat2 = mat<2, 2, int, highp>;

	/// High-qualifier signed integer 3x3 matrix.
	/// @see gtc_matrix_integer
	using				highp_imat3 = mat<3, 3, int, highp>;

	/// High-qualifier signed integer 4x4 matrix.
	/// @see gtc_matrix_integer
	using				highp_imat4 = mat<4, 4, int, highp>;

	/// High-qualifier signed integer 2x2 matrix.
	/// @see gtc_matrix_integer
	using				highp_imat2x2 = mat<2, 2, int, highp>;

	/// High-qualifier signed integer 2x3 matrix.
	/// @see gtc_matrix_integer
	using				highp_imat2x3 = mat<2, 3, int, highp>;

	/// High-qualifier signed integer 2x4 matrix.
	/// @see gtc_matrix_integer
	using				highp_imat2x4 = mat<2, 4, int, highp>;

	/// High-qualifier signed integer 3x2 matrix.
	/// @see gtc_matrix_integer
	using				highp_imat3x2 = mat<3, 2, int, highp>;

	/// High-qualifier signed integer 3x3 matrix.
	/// @see gtc_matrix_integer
	using				highp_imat3x3 = mat<3, 3, int, highp>;

	/// High-qualifier signed integer 3x4 matrix.
	/// @see gtc_matrix_integer
	using				highp_imat3x4 = mat<3, 4, int, highp>;

	/// High-qualifier signed integer 4x2 matrix.
	/// @see gtc_matrix_integer
	using				highp_imat4x2 = mat<4, 2, int, highp>;

	/// High-qualifier signed integer 4x3 matrix.
	/// @see gtc_matrix_integer
	using				highp_imat4x3 = mat<4, 3, int, highp>;

	/// High-qualifier signed integer 4x4 matrix.
	/// @see gtc_matrix_integer
	using				highp_imat4x4 = mat<4, 4, int, highp>;


	/// Medium-qualifier signed integer 2x2 matrix.
	/// @see gtc_matrix_integer
	using			mediump_imat2 = mat<2, 2, int, mediump>;

	/// Medium-qualifier signed integer 3x3 matrix.
	/// @see gtc_matrix_integer
	using			mediump_imat3 = mat<3, 3, int, mediump>;

	/// Medium-qualifier signed integer 4x4 matrix.
	/// @see gtc_matrix_integer
	using			mediump_imat4 = mat<4, 4, int, mediump>;


	/// Medium-qualifier signed integer 2x2 matrix.
	/// @see gtc_matrix_integer
	using			mediump_imat2x2 = mat<2, 2, int, mediump>;

	/// Medium-qualifier signed integer 2x3 matrix.
	/// @see gtc_matrix_integer
	using			mediump_imat2x3 = mat<2, 3, int, mediump>;

	/// Medium-qualifier signed integer 2x4 matrix.
	/// @see gtc_matrix_integer
	using			mediump_imat2x4 = mat<2, 4, int, mediump>;

	/// Medium-qualifier signed integer 3x2 matrix.
	/// @see gtc_matrix_integer
	using			mediump_imat3x2 = mat<3, 2, int, mediump>;

	/// Medium-qualifier signed integer 3x3 matrix.
	/// @see gtc_matrix_integer
	using			mediump_imat3x3 = mat<3, 3, int, mediump>;

	/// Medium-qualifier signed integer 3x4 matrix.
	/// @see gtc_matrix_integer
	using			mediump_imat3x4 = mat<3, 4, int, mediump>;

	/// Medium-qualifier signed integer 4x2 matrix.
	/// @see gtc_matrix_integer
	using			mediump_imat4x2 = mat<4, 2, int, mediump>;

	/// Medium-qualifier signed integer 4x3 matrix.
	/// @see gtc_matrix_integer
	using			mediump_imat4x3 = mat<4, 3, int, mediump>;

	/// Medium-qualifier signed integer 4x4 matrix.
	/// @see gtc_matrix_integer
	using			mediump_imat4x4 = mat<4, 4, int, mediump>;


	/// Low-qualifier signed integer 2x2 matrix.
	/// @see gtc_matrix_integer
	using				lowp_imat2 = mat<2, 2, int, lowp>;

	/// Low-qualifier signed integer 3x3 matrix.
	/// @see gtc_matrix_integer
	using				lowp_imat3 = mat<3, 3, int, lowp>;

	/// Low-qualifier signed integer 4x4 matrix.
	/// @see gtc_matrix_integer
	using				lowp_imat4 = mat<4, 4, int, lowp>;


	/// Low-qualifier signed integer 2x2 matrix.
	/// @see gtc_matrix_integer
	using				lowp_imat2x2 = mat<2, 2, int, lowp>;

	/// Low-qualifier signed integer 2x3 matrix.
	/// @see gtc_matrix_integer
	using				lowp_imat2x3 = mat<2, 3, int, lowp>;

	/// Low-qualifier signed integer 2x4 matrix.
	/// @see gtc_matrix_integer
	using				lowp_imat2x4 = mat<2, 4, int, lowp>;

	/// Low-qualifier signed integer 3x2 matrix.
	/// @see gtc_matrix_integer
	using				lowp_imat3x2 = mat<3, 2, int, lowp>;

	/// Low-qualifier signed integer 3x3 matrix.
	/// @see gtc_matrix_integer
	using				lowp_imat3x3 = mat<3, 3, int, lowp>;

	/// Low-qualifier signed integer 3x4 matrix.
	/// @see gtc_matrix_integer
	using				lowp_imat3x4 = mat<3, 4, int, lowp>;

	/// Low-qualifier signed integer 4x2 matrix.
	/// @see gtc_matrix_integer
	using				lowp_imat4x2 = mat<4, 2, int, lowp>;

	/// Low-qualifier signed integer 4x3 matrix.
	/// @see gtc_matrix_integer
	using				lowp_imat4x3 = mat<4, 3, int, lowp>;

	/// Low-qualifier signed integer 4x4 matrix.
	/// @see gtc_matrix_integer
	using				lowp_imat4x4 = mat<4, 4, int, lowp>;


	/// High-qualifier unsigned integer 2x2 matrix.
	/// @see gtc_matrix_integer
	using				highp_umat2 = mat<2, 2, uint, highp>;

	/// High-qualifier unsigned integer 3x3 matrix.
	/// @see gtc_matrix_integer
	using				highp_umat3 = mat<3, 3, uint, highp>;

	/// High-qualifier unsigned integer 4x4 matrix.
	/// @see gtc_matrix_integer
	using				highp_umat4 = mat<4, 4, uint, highp>;

	/// High-qualifier unsigned integer 2x2 matrix.
	/// @see gtc_matrix_integer
	using				highp_umat2x2 = mat<2, 2, uint, highp>;

	/// High-qualifier unsigned integer 2x3 matrix.
	/// @see gtc_matrix_integer
	using				highp_umat2x3 = mat<2, 3, uint, highp>;

	/// High-qualifier unsigned integer 2x4 matrix.
	/// @see gtc_matrix_integer
	using				highp_umat2x4 = mat<2, 4, uint, highp>;

	/// High-qualifier unsigned integer 3x2 matrix.
	/// @see gtc_matrix_integer
	using				highp_umat3x2 = mat<3, 2, uint, highp>;

	/// High-qualifier unsigned integer 3x3 matrix.
	/// @see gtc_matrix_integer
	using				highp_umat3x3 = mat<3, 3, uint, highp>;

	/// High-qualifier unsigned integer 3x4 matrix.
	/// @see gtc_matrix_integer
	using				highp_umat3x4 = mat<3, 4, uint, highp>;

	/// High-qualifier unsigned integer 4x2 matrix.
	/// @see gtc_matrix_integer
	using				highp_umat4x2 = mat<4, 2, uint, highp>;

	/// High-qualifier unsigned integer 4x3 matrix.
	/// @see gtc_matrix_integer
	using				highp_umat4x3 = mat<4, 3, uint, highp>;

	/// High-qualifier unsigned integer 4x4 matrix.
	/// @see gtc_matrix_integer
	using				highp_umat4x4 = mat<4, 4, uint, highp>;


	/// Medium-qualifier unsigned integer 2x2 matrix.
	/// @see gtc_matrix_integer
	using			mediump_umat2 = mat<2, 2, uint, mediump>;

	/// Medium-qualifier unsigned integer 3x3 matrix.
	/// @see gtc_matrix_integer
	using			mediump_umat3 = mat<3, 3, uint, mediump>;

	/// Medium-qualifier unsigned integer 4x4 matrix.
	/// @see gtc_matrix_integer
	using			mediump_umat4 = mat<4, 4, uint, mediump>;


	/// Medium-qualifier unsigned integer 2x2 matrix.
	/// @see gtc_matrix_integer
	using			mediump_umat2x2 = mat<2, 2, uint, mediump>;

	/// Medium-qualifier unsigned integer 2x3 matrix.
	/// @see gtc_matrix_integer
	using			mediump_umat2x3 = mat<2, 3, uint, mediump>;

	/// Medium-qualifier unsigned integer 2x4 matrix.
	/// @see gtc_matrix_integer
	using			mediump_umat2x4 = mat<2, 4, uint, mediump>;

	/// Medium-qualifier unsigned integer 3x2 matrix.
	/// @see gtc_matrix_integer
	using			mediump_umat3x2 = mat<3, 2, uint, mediump>;

	/// Medium-qualifier unsigned integer 3x3 matrix.
	/// @see gtc_matrix_integer
	using			mediump_umat3x3 = mat<3, 3, uint, mediump>;

	/// Medium-qualifier unsigned integer 3x4 matrix.
	/// @see gtc_matrix_integer
	using			mediump_umat3x4 = mat<3, 4, uint, mediump>;

	/// Medium-qualifier unsigned integer 4x2 matrix.
	/// @see gtc_matrix_integer
	using			mediump_umat4x2 = mat<4, 2, uint, mediump>;

	/// Medium-qualifier unsigned integer 4x3 matrix.
	/// @see gtc_matrix_integer
	using			mediump_umat4x3 = mat<4, 3, uint, mediump>;

	/// Medium-qualifier unsigned integer 4x4 matrix.
	/// @see gtc_matrix_integer
	using			mediump_umat4x4 = mat<4, 4, uint, mediump>;


	/// Low-qualifier unsigned integer 2x2 matrix.
	/// @see gtc_matrix_integer
	using				lowp_umat2 = mat<2, 2, uint, lowp>;

	/// Low-qualifier unsigned integer 3x3 matrix.
	/// @see gtc_matrix_integer
	using				lowp_umat3 = mat<3, 3, uint, lowp>;

	/// Low-qualifier unsigned integer 4x4 matrix.
	/// @see gtc_matrix_integer
	using				lowp_umat4 = mat<4, 4, uint, lowp>;


	/// Low-qualifier unsigned integer 2x2 matrix.
	/// @see gtc_matrix_integer
	using				lowp_umat2x2 = mat<2, 2, uint, lowp>;

	/// Low-qualifier unsigned integer 2x3 matrix.
	/// @see gtc_matrix_integer
	using				lowp_umat2x3 = mat<2, 3, uint, lowp>;

	/// Low-qualifier unsigned integer 2x4 matrix.
	/// @see gtc_matrix_integer
	using				lowp_umat2x4 = mat<2, 4, uint, lowp>;

	/// Low-qualifier unsigned integer 3x2 matrix.
	/// @see gtc_matrix_integer
	using				lowp_umat3x2 = mat<3, 2, uint, lowp>;

	/// Low-qualifier unsigned integer 3x3 matrix.
	/// @see gtc_matrix_integer
	using				lowp_umat3x3 = mat<3, 3, uint, lowp>;

	/// Low-qualifier unsigned integer 3x4 matrix.
	/// @see gtc_matrix_integer
	using				lowp_umat3x4 = mat<3, 4, uint, lowp>;

	/// Low-qualifier unsigned integer 4x2 matrix.
	/// @see gtc_matrix_integer
	using				lowp_umat4x2 = mat<4, 2, uint, lowp>;

	/// Low-qualifier unsigned integer 4x3 matrix.
	/// @see gtc_matrix_integer
	using				lowp_umat4x3 = mat<4, 3, uint, lowp>;

	/// Low-qualifier unsigned integer 4x4 matrix.
	/// @see gtc_matrix_integer
	using				lowp_umat4x4 = mat<4, 4, uint, lowp>;



	/// Signed integer 2x2 matrix.
	/// @see gtc_matrix_integer
	using				imat2 = mat<2, 2, int, defaultp>;

	/// Signed integer 3x3 matrix.
	/// @see gtc_matrix_integer
	using				imat3 = mat<3, 3, int, defaultp>;

	/// Signed integer 4x4 matrix.
	/// @see gtc_matrix_integer
	using				imat4 = mat<4, 4, int, defaultp>;

	/// Signed integer 2x2 matrix.
	/// @see gtc_matrix_integer
	using				imat2x2 = mat<2, 2, int, defaultp>;

	/// Signed integer 2x3 matrix.
	/// @see gtc_matrix_integer
	using				imat2x3 = mat<2, 3, int, defaultp>;

	/// Signed integer 2x4 matrix.
	/// @see gtc_matrix_integer
	using				imat2x4 = mat<2, 4, int, defaultp>;

	/// Signed integer 3x2 matrix.
	/// @see gtc_matrix_integer
	using				imat3x2 = mat<3, 2, int, defaultp>;

	/// Signed integer 3x3 matrix.
	/// @see gtc_matrix_integer
	using				imat3x3 = mat<3, 3, int, defaultp>;

	/// Signed integer 3x4 matrix.
	/// @see gtc_matrix_integer
	using				imat3x4 = mat<3, 4, int, defaultp>;

	/// Signed integer 4x2 matrix.
	/// @see gtc_matrix_integer
	using				imat4x2 = mat<4, 2, int, defaultp>;

	/// Signed integer 4x3 matrix.
	/// @see gtc_matrix_integer
	using				imat4x3 = mat<4, 3, int, defaultp>;

	/// Signed integer 4x4 matrix.
	/// @see gtc_matrix_integer
	using				imat4x4 = mat<4, 4, int, defaultp>;



	/// Unsigned integer 2x2 matrix.
	/// @see gtc_matrix_integer
	using				umat2 = mat<2, 2, uint, defaultp>;

	/// Unsigned integer 3x3 matrix.
	/// @see gtc_matrix_integer
	using				umat3 = mat<3, 3, uint, defaultp>;

	/// Unsigned integer 4x4 matrix.
	/// @see gtc_matrix_integer
	using				umat4 = mat<4, 4, uint, defaultp>;

	/// Unsigned integer 2x2 matrix.
	/// @see gtc_matrix_integer
	using				umat2x2 = mat<2, 2, uint, defaultp>;

	/// Unsigned integer 2x3 matrix.
	/// @see gtc_matrix_integer
	using				umat2x3 = mat<2, 3, uint, defaultp>;

	/// Unsigned integer 2x4 matrix.
	/// @see gtc_matrix_integer
	using				umat2x4 = mat<2, 4, uint, defaultp>;

	/// Unsigned integer 3x2 matrix.
	/// @see gtc_matrix_integer
	using				umat3x2 = mat<3, 2, uint, defaultp>;

	/// Unsigned integer 3x3 matrix.
	/// @see gtc_matrix_integer
	using				umat3x3 = mat<3, 3, uint, defaultp>;

	/// Unsigned integer 3x4 matrix.
	/// @see gtc_matrix_integer
	using				umat3x4 = mat<3, 4, uint, defaultp>;

	/// Unsigned integer 4x2 matrix.
	/// @see gtc_matrix_integer
	using				umat4x2 = mat<4, 2, uint, defaultp>;

	/// Unsigned integer 4x3 matrix.
	/// @see gtc_matrix_integer
	using				umat4x3 = mat<4, 3, uint, defaultp>;

	/// Unsigned integer 4x4 matrix.
	/// @see gtc_matrix_integer
	using				umat4x4 = mat<4, 4, uint, defaultp>;

	/// @}
}//namespace glm
