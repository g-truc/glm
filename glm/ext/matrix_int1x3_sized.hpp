/// @ref ext_matrix_int1x3_sized
/// @file glm/ext/matrix_int1x3_sized.hpp
///
/// @see core (dependence)
///
/// @defgroup ext_matrix_int1x3_sized GLM_EXT_matrix_int1x3_sized
/// @ingroup ext
///
/// Include <glm/ext/matrix_int1x3_sized.hpp> to use the features of this extension.
///
/// Defines a number of matrices with integer types.

#pragma once

// Dependency:
#include "../mat1x3.hpp"
#include "../ext/scalar_int_sized.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_EXT_matrix_int1x3_sized extension included")
#endif

namespace glm
{
	/// @addtogroup ext_matrix_int1x3_sized
	/// @{

	/// 8 bit signed integer 1x3 matrix.
	///
	/// @see ext_matrix_int1x3_sized
	typedef mat<1, 3, int8, defaultp>				i8mat1x3;

	/// 16 bit signed integer 1x3 matrix.
	///
	/// @see ext_matrix_int1x3_sized
	typedef mat<1, 3, int16, defaultp>				i16mat1x3;

	/// 32 bit signed integer 1x3 matrix.
	///
	/// @see ext_matrix_int1x3_sized
	typedef mat<1, 3, int32, defaultp>				i32mat1x3;

	/// 64 bit signed integer 1x3 matrix.
	///
	/// @see ext_matrix_int1x3_sized
	typedef mat<1, 3, int64, defaultp>				i64mat1x3;

	/// @}
}//namespace glm

#if GLM_CONFIG_CTOR_INIT == GLM_DISABLE
static_assert(std::is_trivially_default_constructible<glm::i8mat1x3>::value);
static_assert(std::is_trivially_default_constructible<glm::i16mat1x3>::value);
static_assert(std::is_trivially_default_constructible<glm::i32mat1x3>::value);
static_assert(std::is_trivially_default_constructible<glm::i64mat1x3>::value);
#endif
static_assert(std::is_trivially_copy_assignable<glm::i8mat1x3>::value);
static_assert(std::is_trivially_copy_assignable<glm::i16mat1x3>::value);
static_assert(std::is_trivially_copy_assignable<glm::i32mat1x3>::value);
static_assert(std::is_trivially_copy_assignable<glm::i64mat1x3>::value);
static_assert(std::is_trivially_copyable<glm::i8mat1x3>::value);
static_assert(std::is_trivially_copyable<glm::i16mat1x3>::value);
static_assert(std::is_trivially_copyable<glm::i32mat1x3>::value);
static_assert(std::is_trivially_copyable<glm::i64mat1x3>::value);
static_assert(std::is_copy_constructible<glm::i8mat1x3>::value);
static_assert(std::is_copy_constructible<glm::i16mat1x3>::value);
static_assert(std::is_copy_constructible<glm::i32mat1x3>::value);
static_assert(std::is_copy_constructible<glm::i64mat1x3>::value);
static_assert(glm::i8mat1x3::length() == 1);
static_assert(glm::i16mat1x3::length() == 1);
static_assert(glm::i32mat1x3::length() == 1);
static_assert(glm::i64mat1x3::length() == 1);
