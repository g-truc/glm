/// @ref ext_matrix_uint1x1_sized
/// @file glm/ext/matrix_uint1x1_sized.hpp
///
/// @see core (dependence)
///
/// @defgroup ext_matrix_uint1x1_sized GLM_EXT_matrix_uint1x1_sized
/// @ingroup ext
///
/// Include <glm/ext/matrix_uint1x1_sized.hpp> to use the features of this extension.
///
/// Defines a number of matrices with integer types.

#pragma once

// Dependency:
#include "../mat1x1.hpp"
#include "../ext/scalar_uint_sized.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_EXT_matrix_uint1x1_sized extension included")
#endif

namespace glm
{
	/// @addtogroup ext_matrix_uint1x1_sized
	/// @{

	/// 8 bit unsigned integer 1x1 matrix.
	///
	/// @see ext_matrix_uint1x1_sized
	typedef mat<1, 1, uint8, defaultp>				u8mat1x1;

	/// 16 bit unsigned integer 1x1 matrix.
	///
	/// @see ext_matrix_uint1x1_sized
	typedef mat<1, 1, uint16, defaultp>				u16mat1x1;

	/// 32 bit unsigned integer 1x1 matrix.
	///
	/// @see ext_matrix_uint1x1_sized
	typedef mat<1, 1, uint32, defaultp>				u32mat1x1;

	/// 64 bit unsigned integer 1x1 matrix.
	///
	/// @see ext_matrix_uint1x1_sized
	typedef mat<1, 1, uint64, defaultp>				u64mat1x1;


	/// 8 bit unsigned integer 1x1 matrix.
	///
	/// @see ext_matrix_uint1x1_sized
	typedef mat<1, 1, uint8, defaultp>				u8mat1;

	/// 16 bit unsigned integer 1x1 matrix.
	///
	/// @see ext_matrix_uint1x1_sized
	typedef mat<1, 1, uint16, defaultp>				u16mat1;

	/// 32 bit unsigned integer 1x1 matrix.
	///
	/// @see ext_matrix_uint1x1_sized
	typedef mat<1, 1, uint32, defaultp>				u32mat1;

	/// 64 bit unsigned integer 1x1 matrix.
	///
	/// @see ext_matrix_uint1x1_sized
	typedef mat<1, 1, uint64, defaultp>				u64mat1;

	/// @}
}//namespace glm

#if GLM_CONFIG_CTOR_INIT == GLM_DISABLE
static_assert(std::is_trivially_default_constructible<glm::u8mat1x1>::value);
static_assert(std::is_trivially_default_constructible<glm::u16mat1x1>::value);
static_assert(std::is_trivially_default_constructible<glm::u32mat1x1>::value);
static_assert(std::is_trivially_default_constructible<glm::u64mat1x1>::value);
static_assert(std::is_trivially_default_constructible<glm::u8mat1>::value);
static_assert(std::is_trivially_default_constructible<glm::u16mat1>::value);
static_assert(std::is_trivially_default_constructible<glm::u32mat1>::value);
static_assert(std::is_trivially_default_constructible<glm::u64mat1>::value);
#endif
static_assert(std::is_trivially_copy_assignable<glm::u8mat1x1>::value);
static_assert(std::is_trivially_copy_assignable<glm::u16mat1x1>::value);
static_assert(std::is_trivially_copy_assignable<glm::u32mat1x1>::value);
static_assert(std::is_trivially_copy_assignable<glm::u64mat1x1>::value);
static_assert(std::is_trivially_copy_assignable<glm::u8mat1>::value);
static_assert(std::is_trivially_copy_assignable<glm::u16mat1>::value);
static_assert(std::is_trivially_copy_assignable<glm::u32mat1>::value);
static_assert(std::is_trivially_copy_assignable<glm::u64mat1>::value);
static_assert(std::is_trivially_copyable<glm::u8mat1x1>::value);
static_assert(std::is_trivially_copyable<glm::u16mat1x1>::value);
static_assert(std::is_trivially_copyable<glm::u32mat1x1>::value);
static_assert(std::is_trivially_copyable<glm::u64mat1x1>::value);
static_assert(std::is_trivially_copyable<glm::u8mat1>::value);
static_assert(std::is_trivially_copyable<glm::u16mat1>::value);
static_assert(std::is_trivially_copyable<glm::u32mat1>::value);
static_assert(std::is_trivially_copyable<glm::u64mat1>::value);
static_assert(std::is_copy_constructible<glm::u8mat1x1>::value);
static_assert(std::is_copy_constructible<glm::u16mat1x1>::value);
static_assert(std::is_copy_constructible<glm::u32mat1x1>::value);
static_assert(std::is_copy_constructible<glm::u64mat1x1>::value);
static_assert(std::is_copy_constructible<glm::u8mat1>::value);
static_assert(std::is_copy_constructible<glm::u16mat1>::value);
static_assert(std::is_copy_constructible<glm::u32mat1>::value);
static_assert(std::is_copy_constructible<glm::u64mat1>::value);
static_assert(glm::u8mat1x1::length() == 1);
static_assert(glm::u16mat1x1::length() == 1);
static_assert(glm::u32mat1x1::length() == 1);
static_assert(glm::u64mat1x1::length() == 1);
static_assert(glm::u8mat1::length() == 1);
static_assert(glm::u16mat1::length() == 1);
static_assert(glm::u32mat1::length() == 1);
static_assert(glm::u64mat1::length() == 1);
