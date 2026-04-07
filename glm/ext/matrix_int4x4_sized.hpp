/// @ref ext_matrix_int4x4_sized
/// @file glm/ext/matrix_int4x4_sized.hpp
///
/// @see core (dependence)
///
/// @defgroup ext_matrix_int4x4_sized GLM_EXT_matrix_int4x4_sized
/// @ingroup ext
///
/// Include <glm/ext/matrix_int4x4_sized.hpp> to use the features of this extension.
///
/// Defines a number of matrices with integer types.

#pragma once

// Dependency:
#include "../mat4x4.hpp"
#include "../ext/scalar_int_sized.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_EXT_matrix_int4x4_sized extension included")
#endif

namespace glm
{
	/// @addtogroup ext_matrix_int4x4_sized
	/// @{

	/// 8 bit signed integer 4x4 matrix.
	///
	/// @see ext_matrix_int4x4_sized
	using				i8mat4x4 = mat<4, 4, int8, defaultp>;

	/// 16 bit signed integer 4x4 matrix.
	///
	/// @see ext_matrix_int4x4_sized
	using				i16mat4x4 = mat<4, 4, int16, defaultp>;

	/// 32 bit signed integer 4x4 matrix.
	///
	/// @see ext_matrix_int4x4_sized
	using				i32mat4x4 = mat<4, 4, int32, defaultp>;

	/// 64 bit signed integer 4x4 matrix.
	///
	/// @see ext_matrix_int4x4_sized
	using				i64mat4x4 = mat<4, 4, int64, defaultp>;


	/// 8 bit signed integer 4x4 matrix.
	///
	/// @see ext_matrix_int4x4_sized
	using				i8mat4 = mat<4, 4, int8, defaultp>;

	/// 16 bit signed integer 4x4 matrix.
	///
	/// @see ext_matrix_int4x4_sized
	using				i16mat4 = mat<4, 4, int16, defaultp>;

	/// 32 bit signed integer 4x4 matrix.
	///
	/// @see ext_matrix_int4x4_sized
	using				i32mat4 = mat<4, 4, int32, defaultp>;

	/// 64 bit signed integer 4x4 matrix.
	///
	/// @see ext_matrix_int4x4_sized
	using				i64mat4 = mat<4, 4, int64, defaultp>;

	/// @}
}//namespace glm

#if GLM_CONFIG_CTOR_INIT == GLM_DISABLE
static_assert(std::is_trivially_default_constructible<glm::i8mat4x4>::value);
static_assert(std::is_trivially_default_constructible<glm::i16mat4x4>::value);
static_assert(std::is_trivially_default_constructible<glm::i32mat4x4>::value);
static_assert(std::is_trivially_default_constructible<glm::i64mat4x4>::value);
static_assert(std::is_trivially_default_constructible<glm::i8mat4>::value);
static_assert(std::is_trivially_default_constructible<glm::i16mat4>::value);
static_assert(std::is_trivially_default_constructible<glm::i32mat4>::value);
static_assert(std::is_trivially_default_constructible<glm::i64mat4>::value);
#endif
static_assert(std::is_trivially_copy_assignable<glm::i8mat4x4>::value);
static_assert(std::is_trivially_copy_assignable<glm::i16mat4x4>::value);
static_assert(std::is_trivially_copy_assignable<glm::i32mat4x4>::value);
static_assert(std::is_trivially_copy_assignable<glm::i64mat4x4>::value);
static_assert(std::is_trivially_copy_assignable<glm::i8mat4>::value);
static_assert(std::is_trivially_copy_assignable<glm::i16mat4>::value);
static_assert(std::is_trivially_copy_assignable<glm::i32mat4>::value);
static_assert(std::is_trivially_copy_assignable<glm::i64mat4>::value);
static_assert(std::is_trivially_copyable<glm::i8mat4x4>::value);
static_assert(std::is_trivially_copyable<glm::i16mat4x4>::value);
static_assert(std::is_trivially_copyable<glm::i32mat4x4>::value);
static_assert(std::is_trivially_copyable<glm::i64mat4x4>::value);
static_assert(std::is_trivially_copyable<glm::i8mat4>::value);
static_assert(std::is_trivially_copyable<glm::i16mat4>::value);
static_assert(std::is_trivially_copyable<glm::i32mat4>::value);
static_assert(std::is_trivially_copyable<glm::i64mat4>::value);
static_assert(std::is_copy_constructible<glm::i8mat4x4>::value);
static_assert(std::is_copy_constructible<glm::i16mat4x4>::value);
static_assert(std::is_copy_constructible<glm::i32mat4x4>::value);
static_assert(std::is_copy_constructible<glm::i64mat4x4>::value);
static_assert(std::is_copy_constructible<glm::i8mat4>::value);
static_assert(std::is_copy_constructible<glm::i16mat4>::value);
static_assert(std::is_copy_constructible<glm::i32mat4>::value);
static_assert(std::is_copy_constructible<glm::i64mat4>::value);
static_assert(glm::i8mat4x4::length() == 4);
static_assert(glm::i16mat4x4::length() == 4);
static_assert(glm::i32mat4x4::length() == 4);
static_assert(glm::i64mat4x4::length() == 4);
static_assert(glm::i8mat4::length() == 4);
static_assert(glm::i16mat4::length() == 4);
static_assert(glm::i32mat4::length() == 4);
static_assert(glm::i64mat4::length() == 4);


