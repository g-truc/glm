/// @ref ext_matrix_uint3x2_sized
/// @file glm/ext/matrix_uint3x2_sized.hpp
///
/// @see core (dependence)
///
/// @defgroup ext_matrix_uint3x2_sized GLM_EXT_matrix_uint3x2_sized
/// @ingroup ext
///
/// Include <glm/ext/matrix_uint3x2_sized.hpp> to use the features of this extension.
///
/// Defines a number of matrices with integer types.

#pragma once

// Dependency:
#include "../mat3x2.hpp"
#include "../ext/scalar_uint_sized.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_EXT_matrix_uint3x2_sized extension included")
#endif

namespace glm
{
	/// @addtogroup ext_matrix_uint3x2_sized
	/// @{

	/// 8 bit signed integer 3x2 matrix.
	///
	/// @see ext_matrix_uint3x2_sized
	typedef mat<3, 2, uint8, defaultp>				u8mat3x2;

	/// 16 bit signed integer 3x2 matrix.
	///
	/// @see ext_matrix_uint3x2_sized
	typedef mat<3, 2, uint16, defaultp>				u16mat3x2;

	/// 32 bit signed integer 3x2 matrix.
	///
	/// @see ext_matrix_uint3x2_sized
	typedef mat<3, 2, uint32, defaultp>				u32mat3x2;

	/// 64 bit signed integer 3x2 matrix.
	///
	/// @see ext_matrix_uint3x2_sized
	typedef mat<3, 2, uint64, defaultp>				u64mat3x2;

	/// @}
}//namespace glm

#if GLM_CONFIG_CTOR_INIT == GLM_DISABLE
static_assert(std::is_trivially_default_constructible<glm::u8mat3x2>::value);
static_assert(std::is_trivially_default_constructible<glm::u16mat3x2>::value);
static_assert(std::is_trivially_default_constructible<glm::u32mat3x2>::value);
static_assert(std::is_trivially_default_constructible<glm::u64mat3x2>::value);
#endif
static_assert(std::is_trivially_copy_assignable<glm::u8mat3x2>::value);
static_assert(std::is_trivially_copy_assignable<glm::u16mat3x2>::value);
static_assert(std::is_trivially_copy_assignable<glm::u32mat3x2>::value);
static_assert(std::is_trivially_copy_assignable<glm::u64mat3x2>::value);
static_assert(std::is_trivially_copyable<glm::u8mat3x2>::value);
static_assert(std::is_trivially_copyable<glm::u16mat3x2>::value);
static_assert(std::is_trivially_copyable<glm::u32mat3x2>::value);
static_assert(std::is_trivially_copyable<glm::u64mat3x2>::value);
static_assert(std::is_copy_constructible<glm::u8mat3x2>::value);
static_assert(std::is_copy_constructible<glm::u16mat3x2>::value);
static_assert(std::is_copy_constructible<glm::u32mat3x2>::value);
static_assert(std::is_copy_constructible<glm::u64mat3x2>::value);
static_assert(glm::u8mat3x2::length() == 3);
static_assert(glm::u16mat3x2::length() == 3);
static_assert(glm::u32mat3x2::length() == 3);
static_assert(glm::u64mat3x2::length() == 3);
