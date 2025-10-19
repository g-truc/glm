/// @ref ext_vector_int1_sized
/// @file glm/ext/vector_int1_sized.hpp
///
/// @defgroup ext_vector_int1_sized GLM_EXT_vector_int1_sized
/// @ingroup ext
///
/// Exposes sized signed integer vector types.
///
/// Include <glm/ext/vector_int1_sized.hpp> to use the features of this extension.
///
/// @see ext_scalar_int_sized
/// @see ext_vector_uint1_sized

#pragma once

#include "../ext/vector_int1.hpp"
#include "../ext/scalar_int_sized.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_EXT_vector_int1_sized extension included")
#endif

namespace glm
{
	/// @addtogroup ext_vector_int1_sized
	/// @{

	/// 8 bit signed integer vector of 1 component type.
	///
	/// @see ext_vector_int1_sized
	typedef vec<1, int8, defaultp>	i8vec1;

	/// 16 bit signed integer vector of 1 component type.
	///
	/// @see ext_vector_int1_sized
	typedef vec<1, int16, defaultp>	i16vec1;

	/// 32 bit signed integer vector of 1 component type.
	///
	/// @see ext_vector_int1_sized
	typedef vec<1, int32, defaultp>	i32vec1;

	/// 64 bit signed integer vector of 1 component type.
	///
	/// @see ext_vector_int1_sized
	typedef vec<1, int64, defaultp>	i64vec1;

	/// @}
}//namespace glm

#if GLM_CONFIG_CTOR_INIT == GLM_DISABLE
static_assert(std::is_trivially_default_constructible<glm::i8vec1>::value);
static_assert(std::is_trivially_default_constructible<glm::i16vec1>::value);
static_assert(std::is_trivially_default_constructible<glm::i32vec1>::value);
static_assert(std::is_trivially_default_constructible<glm::i64vec1>::value);
#endif
static_assert(std::is_trivially_copy_assignable<glm::i8vec1>::value);
static_assert(std::is_trivially_copy_assignable<glm::i16vec1>::value);
static_assert(std::is_trivially_copy_assignable<glm::i32vec1>::value);
static_assert(std::is_trivially_copy_assignable<glm::i64vec1>::value);
static_assert(std::is_trivially_copyable<glm::i8vec1>::value);
static_assert(std::is_trivially_copyable<glm::i16vec1>::value);
static_assert(std::is_trivially_copyable<glm::i32vec1>::value);
static_assert(std::is_trivially_copyable<glm::i64vec1>::value);
static_assert(std::is_copy_constructible<glm::i8vec1>::value);
static_assert(std::is_copy_constructible<glm::i16vec1>::value);
static_assert(std::is_copy_constructible<glm::i32vec1>::value);
static_assert(std::is_copy_constructible<glm::i64vec1>::value);
static_assert(glm::i8vec1::length() == 1);
static_assert(glm::i16vec1::length() == 1);
static_assert(glm::i32vec1::length() == 1);
static_assert(glm::i64vec1::length() == 1);

