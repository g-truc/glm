/// @ref ext_vector_int4_sized
/// @file glm/ext/vector_int4_sized.hpp
///
/// @defgroup ext_vector_int4_sized GLM_EXT_vector_int4_sized
/// @ingroup ext
///
/// Exposes sized signed integer vector of 4 components type.
///
/// Include <glm/ext/vector_int4_sized.hpp> to use the features of this extension.
///
/// @see ext_scalar_int_sized
/// @see ext_vector_uint4_sized

#pragma once

#include "../ext/vector_int4.hpp"
#include "../ext/scalar_int_sized.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_EXT_vector_int4_sized extension included")
#endif

namespace glm
{
	/// @addtogroup ext_vector_int4_sized
	/// @{

	/// 8 bit signed integer vector of 4 components type.
	///
	/// @see ext_vector_int4_sized
	typedef vec<4, int8, defaultp>		i8vec4;

	/// 16 bit signed integer vector of 4 components type.
	///
	/// @see ext_vector_int4_sized
	typedef vec<4, int16, defaultp>		i16vec4;

	/// 32 bit signed integer vector of 4 components type.
	///
	/// @see ext_vector_int4_sized
	typedef vec<4, int32, defaultp>		i32vec4;

	/// 64 bit signed integer vector of 4 components type.
	///
	/// @see ext_vector_int4_sized
	typedef vec<4, int64, defaultp>		i64vec4;

	/// @}
}//namespace glm

#if GLM_CONFIG_CTOR_INIT == GLM_DISABLE
static_assert(std::is_trivially_default_constructible<glm::i8vec4>::value);
static_assert(std::is_trivially_default_constructible<glm::i16vec4>::value);
static_assert(std::is_trivially_default_constructible<glm::i32vec4>::value);
static_assert(std::is_trivially_default_constructible<glm::i64vec4>::value);
#endif
static_assert(std::is_trivially_copy_assignable<glm::i8vec4>::value);
static_assert(std::is_trivially_copy_assignable<glm::i16vec4>::value);
static_assert(std::is_trivially_copy_assignable<glm::i32vec4>::value);
static_assert(std::is_trivially_copy_assignable<glm::i64vec4>::value);
static_assert(std::is_trivially_copyable<glm::i8vec4>::value);
static_assert(std::is_trivially_copyable<glm::i16vec4>::value);
static_assert(std::is_trivially_copyable<glm::i32vec4>::value);
static_assert(std::is_trivially_copyable<glm::i64vec4>::value);
static_assert(std::is_copy_constructible<glm::i8vec4>::value);
static_assert(std::is_copy_constructible<glm::i16vec4>::value);
static_assert(std::is_copy_constructible<glm::i32vec4>::value);
static_assert(std::is_copy_constructible<glm::i64vec4>::value);
static_assert(glm::i8vec4::length() == 4);
static_assert(glm::i16vec4::length() == 4);
static_assert(glm::i32vec4::length() == 4);
static_assert(glm::i64vec4::length() == 4);
