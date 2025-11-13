/// @ref ext_vector_int3_sized
/// @file glm/ext/vector_int3_sized.hpp
///
/// @defgroup ext_vector_int3_sized GLM_EXT_vector_int3_sized
/// @ingroup ext
///
/// Exposes sized signed integer vector of 3 components type.
///
/// Include <glm/ext/vector_int3_sized.hpp> to use the features of this extension.
///
/// @see ext_scalar_int_sized
/// @see ext_vector_uint3_sized

#pragma once

#include "../ext/vector_int3.hpp"
#include "../ext/scalar_int_sized.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_EXT_vector_int3_sized extension included")
#endif

namespace glm
{
	/// @addtogroup ext_vector_int3_sized
	/// @{

	/// 8 bit signed integer vector of 3 components type.
	///
	/// @see ext_vector_int3_sized
	typedef vec<3, int8, defaultp>		i8vec3;

	/// 16 bit signed integer vector of 3 components type.
	///
	/// @see ext_vector_int3_sized
	typedef vec<3, int16, defaultp>		i16vec3;

	/// 32 bit signed integer vector of 3 components type.
	///
	/// @see ext_vector_int3_sized
	typedef vec<3, int32, defaultp>		i32vec3;

	/// 64 bit signed integer vector of 3 components type.
	///
	/// @see ext_vector_int3_sized
	typedef vec<3, int64, defaultp>		i64vec3;

	/// @}
}//namespace glm

#if GLM_CONFIG_CTOR_INIT == GLM_DISABLE
static_assert(std::is_trivially_default_constructible<glm::i8vec3>::value);
static_assert(std::is_trivially_default_constructible<glm::i16vec3>::value);
static_assert(std::is_trivially_default_constructible<glm::i32vec3>::value);
static_assert(std::is_trivially_default_constructible<glm::i64vec3>::value);
#endif
static_assert(std::is_trivially_copy_assignable<glm::i8vec3>::value);
static_assert(std::is_trivially_copy_assignable<glm::i16vec3>::value);
static_assert(std::is_trivially_copy_assignable<glm::i32vec3>::value);
static_assert(std::is_trivially_copy_assignable<glm::i64vec3>::value);
static_assert(std::is_trivially_copyable<glm::i8vec3>::value);
static_assert(std::is_trivially_copyable<glm::i16vec3>::value);
static_assert(std::is_trivially_copyable<glm::i32vec3>::value);
static_assert(std::is_trivially_copyable<glm::i64vec3>::value);
static_assert(std::is_copy_constructible<glm::i8vec3>::value);
static_assert(std::is_copy_constructible<glm::i16vec3>::value);
static_assert(std::is_copy_constructible<glm::i32vec3>::value);
static_assert(std::is_copy_constructible<glm::i64vec3>::value);
static_assert(glm::i8vec3::length() == 3);
static_assert(glm::i16vec3::length() == 3);
static_assert(glm::i32vec3::length() == 3);
static_assert(glm::i64vec3::length() == 3);
