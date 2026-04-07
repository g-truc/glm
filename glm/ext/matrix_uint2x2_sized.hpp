/// @ref ext_matrix_uint2x2_sized
/// @file glm/ext/matrix_uint2x2_sized.hpp
///
/// @see core (dependence)
///
/// @defgroup ext_matrix_uint2x2_sized GLM_EXT_matrix_uint2x2_sized
/// @ingroup ext
///
/// Include <glm/ext/matrix_uint2x2_sized.hpp> to use the features of this extension.
///
/// Defines a number of matrices with integer types.

#pragma once

// Dependency:
#include "../mat2x2.hpp"
#include "../ext/scalar_uint_sized.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_EXT_matrix_uint2x2_sized extension included")
#endif

namespace glm
{
	/// @addtogroup ext_matrix_uint2x2_sized
	/// @{

	/// 8 bit unsigned integer 2x2 matrix.
	///
	/// @see ext_matrix_uint2x2_sized
	using				u8mat2x2 = mat<2, 2, uint8, defaultp>;

	/// 16 bit unsigned integer 2x2 matrix.
	///
	/// @see ext_matrix_uint2x2_sized
	using				u16mat2x2 = mat<2, 2, uint16, defaultp>;

	/// 32 bit unsigned integer 2x2 matrix.
	///
	/// @see ext_matrix_uint2x2_sized
	using				u32mat2x2 = mat<2, 2, uint32, defaultp>;

	/// 64 bit unsigned integer 2x2 matrix.
	///
	/// @see ext_matrix_uint2x2_sized
	using				u64mat2x2 = mat<2, 2, uint64, defaultp>;


	/// 8 bit unsigned integer 2x2 matrix.
	///
	/// @see ext_matrix_uint2x2_sized
	using				u8mat2 = mat<2, 2, uint8, defaultp>;

	/// 16 bit unsigned integer 2x2 matrix.
	///
	/// @see ext_matrix_uint2x2_sized
	using				u16mat2 = mat<2, 2, uint16, defaultp>;

	/// 32 bit unsigned integer 2x2 matrix.
	///
	/// @see ext_matrix_uint2x2_sized
	using				u32mat2 = mat<2, 2, uint32, defaultp>;

	/// 64 bit unsigned integer 2x2 matrix.
	///
	/// @see ext_matrix_uint2x2_sized
	using				u64mat2 = mat<2, 2, uint64, defaultp>;

	/// @}
}//namespace glm

#if GLM_CONFIG_CTOR_INIT == GLM_DISABLE
static_assert(std::is_trivially_default_constructible<glm::u8mat2x2>::value);
static_assert(std::is_trivially_default_constructible<glm::u16mat2x2>::value);
static_assert(std::is_trivially_default_constructible<glm::u32mat2x2>::value);
static_assert(std::is_trivially_default_constructible<glm::u64mat2x2>::value);
static_assert(std::is_trivially_default_constructible<glm::u8mat2>::value);
static_assert(std::is_trivially_default_constructible<glm::u16mat2>::value);
static_assert(std::is_trivially_default_constructible<glm::u32mat2>::value);
static_assert(std::is_trivially_default_constructible<glm::u64mat2>::value);
#endif
static_assert(std::is_trivially_copy_assignable<glm::u8mat2x2>::value);
static_assert(std::is_trivially_copy_assignable<glm::u16mat2x2>::value);
static_assert(std::is_trivially_copy_assignable<glm::u32mat2x2>::value);
static_assert(std::is_trivially_copy_assignable<glm::u64mat2x2>::value);
static_assert(std::is_trivially_copy_assignable<glm::u8mat2>::value);
static_assert(std::is_trivially_copy_assignable<glm::u16mat2>::value);
static_assert(std::is_trivially_copy_assignable<glm::u32mat2>::value);
static_assert(std::is_trivially_copy_assignable<glm::u64mat2>::value);
static_assert(std::is_trivially_copyable<glm::u8mat2x2>::value);
static_assert(std::is_trivially_copyable<glm::u16mat2x2>::value);
static_assert(std::is_trivially_copyable<glm::u32mat2x2>::value);
static_assert(std::is_trivially_copyable<glm::u64mat2x2>::value);
static_assert(std::is_trivially_copyable<glm::u8mat2>::value);
static_assert(std::is_trivially_copyable<glm::u16mat2>::value);
static_assert(std::is_trivially_copyable<glm::u32mat2>::value);
static_assert(std::is_trivially_copyable<glm::u64mat2>::value);
static_assert(std::is_copy_constructible<glm::u8mat2x2>::value);
static_assert(std::is_copy_constructible<glm::u16mat2x2>::value);
static_assert(std::is_copy_constructible<glm::u32mat2x2>::value);
static_assert(std::is_copy_constructible<glm::u64mat2x2>::value);
static_assert(std::is_copy_constructible<glm::u8mat2>::value);
static_assert(std::is_copy_constructible<glm::u16mat2>::value);
static_assert(std::is_copy_constructible<glm::u32mat2>::value);
static_assert(std::is_copy_constructible<glm::u64mat2>::value);
static_assert(glm::u8mat2x2::length() == 2);
static_assert(glm::u16mat2x2::length() == 2);
static_assert(glm::u32mat2x2::length() == 2);
static_assert(glm::u64mat2x2::length() == 2);
static_assert(glm::u8mat2::length() == 2);
static_assert(glm::u16mat2::length() == 2);
static_assert(glm::u32mat2::length() == 2);
static_assert(glm::u64mat2::length() == 2);
