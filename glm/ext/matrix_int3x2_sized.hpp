/// @ref ext_matrix_int3x2_sized
/// @file glm/ext/matrix_int3x2_sized.hpp
///
/// @see core (dependence)
///
/// @defgroup ext_matrix_int3x2_sized GLM_EXT_matrix_int3x2_sized
/// @ingroup ext
///
/// Include <glm/ext/matrix_int3x2_sized.hpp> to use the features of this extension.
///
/// Defines a number of matrices with integer types.

#pragma once

// Dependency:
#include "../mat3x2.hpp"
#include "../ext/scalar_int_sized.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_EXT_matrix_int3x2_sized extension included")
#endif

namespace glm
{
	/// @addtogroup ext_matrix_int3x2_sized
	/// @{

	/// 8 bit signed integer 3x2 matrix.
	///
	/// @see ext_matrix_int3x2_sized
	typedef mat<3, 2, int8, defaultp>				i8mat3x2;

	/// 16 bit signed integer 3x2 matrix.
	///
	/// @see ext_matrix_int3x2_sized
	typedef mat<3, 2, int16, defaultp>				i16mat3x2;

	/// 32 bit signed integer 3x2 matrix.
	///
	/// @see ext_matrix_int3x2_sized
	typedef mat<3, 2, int32, defaultp>				i32mat3x2;

	/// 64 bit signed integer 3x2 matrix.
	///
	/// @see ext_matrix_int3x2_sized
	typedef mat<3, 2, int64, defaultp>				i64mat3x2;

	/// @}
}//namespace glm

#if GLM_CONFIG_CTOR_INIT == GLM_DISABLE
static_assert(std::is_trivially_default_constructible<glm::i8mat3x2>::value);
static_assert(std::is_trivially_default_constructible<glm::i16mat3x2>::value);
static_assert(std::is_trivially_default_constructible<glm::i32mat3x2>::value);
static_assert(std::is_trivially_default_constructible<glm::i64mat3x2>::value);
#endif
static_assert(std::is_trivially_copy_assignable<glm::i8mat3x2>::value);
static_assert(std::is_trivially_copy_assignable<glm::i16mat3x2>::value);
static_assert(std::is_trivially_copy_assignable<glm::i32mat3x2>::value);
static_assert(std::is_trivially_copy_assignable<glm::i64mat3x2>::value);
static_assert(std::is_trivially_copyable<glm::i8mat3x2>::value);
static_assert(std::is_trivially_copyable<glm::i16mat3x2>::value);
static_assert(std::is_trivially_copyable<glm::i32mat3x2>::value);
static_assert(std::is_trivially_copyable<glm::i64mat3x2>::value);
static_assert(std::is_copy_constructible<glm::i8mat3x2>::value);
static_assert(std::is_copy_constructible<glm::i16mat3x2>::value);
static_assert(std::is_copy_constructible<glm::i32mat3x2>::value);
static_assert(std::is_copy_constructible<glm::i64mat3x2>::value);
static_assert(glm::i8mat3x2::length() == 3);
static_assert(glm::i16mat3x2::length() == 3);
static_assert(glm::i32mat3x2::length() == 3);
static_assert(glm::i64mat3x2::length() == 3);
