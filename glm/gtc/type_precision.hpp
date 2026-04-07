/// @ref gtc_type_precision
/// @file glm/gtc/type_precision.hpp
///
/// @see core (dependence)
/// @see gtc_quaternion (dependence)
///
/// @defgroup gtc_type_precision GLM_GTC_type_precision
/// @ingroup gtc
///
/// Include <glm/gtc/type_precision.hpp> to use the features of this extension.
///
/// Defines specific C++-based qualifier types.

#pragma once

// Dependency:
#include "../gtc/quaternion.hpp"
#include "../gtc/vec1.hpp"
#include "../ext/vector_int1_sized.hpp"
#include "../ext/vector_int2_sized.hpp"
#include "../ext/vector_int3_sized.hpp"
#include "../ext/vector_int4_sized.hpp"
#include "../ext/scalar_int_sized.hpp"
#include "../ext/vector_uint1_sized.hpp"
#include "../ext/vector_uint2_sized.hpp"
#include "../ext/vector_uint3_sized.hpp"
#include "../ext/vector_uint4_sized.hpp"
#include "../ext/scalar_uint_sized.hpp"
#include "../detail/type_vec2.hpp"
#include "../detail/type_vec3.hpp"
#include "../detail/type_vec4.hpp"
#include "../detail/type_mat2x2.hpp"
#include "../detail/type_mat2x3.hpp"
#include "../detail/type_mat2x4.hpp"
#include "../detail/type_mat3x2.hpp"
#include "../detail/type_mat3x3.hpp"
#include "../detail/type_mat3x4.hpp"
#include "../detail/type_mat4x2.hpp"
#include "../detail/type_mat4x3.hpp"
#include "../detail/type_mat4x4.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_GTC_type_precision extension included")
#endif

namespace glm
{
	///////////////////////////
	// Signed int vector types

	/// @addtogroup gtc_type_precision
	/// @{

	/// Low qualifier 8 bit signed integer type.
	/// @see gtc_type_precision
	using lowp_int8 = detail::int8;

	/// Low qualifier 16 bit signed integer type.
	/// @see gtc_type_precision
	using lowp_int16 = detail::int16;

	/// Low qualifier 32 bit signed integer type.
	/// @see gtc_type_precision
	using lowp_int32 = detail::int32;

	/// Low qualifier 64 bit signed integer type.
	/// @see gtc_type_precision
	using lowp_int64 = detail::int64;

	/// Low qualifier 8 bit signed integer type.
	/// @see gtc_type_precision
	using lowp_int8_t = detail::int8;

	/// Low qualifier 16 bit signed integer type.
	/// @see gtc_type_precision
	using lowp_int16_t = detail::int16;

	/// Low qualifier 32 bit signed integer type.
	/// @see gtc_type_precision
	using lowp_int32_t = detail::int32;

	/// Low qualifier 64 bit signed integer type.
	/// @see gtc_type_precision
	using lowp_int64_t = detail::int64;

	/// Low qualifier 8 bit signed integer type.
	/// @see gtc_type_precision
	using lowp_i8 = detail::int8;

	/// Low qualifier 16 bit signed integer type.
	/// @see gtc_type_precision
	using lowp_i16 = detail::int16;

	/// Low qualifier 32 bit signed integer type.
	/// @see gtc_type_precision
	using lowp_i32 = detail::int32;

	/// Low qualifier 64 bit signed integer type.
	/// @see gtc_type_precision
	using lowp_i64 = detail::int64;

	/// Medium qualifier 8 bit signed integer type.
	/// @see gtc_type_precision
	using mediump_int8 = detail::int8;

	/// Medium qualifier 16 bit signed integer type.
	/// @see gtc_type_precision
	using mediump_int16 = detail::int16;

	/// Medium qualifier 32 bit signed integer type.
	/// @see gtc_type_precision
	using mediump_int32 = detail::int32;

	/// Medium qualifier 64 bit signed integer type.
	/// @see gtc_type_precision
	using mediump_int64 = detail::int64;

	/// Medium qualifier 8 bit signed integer type.
	/// @see gtc_type_precision
	using mediump_int8_t = detail::int8;

	/// Medium qualifier 16 bit signed integer type.
	/// @see gtc_type_precision
	using mediump_int16_t = detail::int16;

	/// Medium qualifier 32 bit signed integer type.
	/// @see gtc_type_precision
	using mediump_int32_t = detail::int32;

	/// Medium qualifier 64 bit signed integer type.
	/// @see gtc_type_precision
	using mediump_int64_t = detail::int64;

	/// Medium qualifier 8 bit signed integer type.
	/// @see gtc_type_precision
	using mediump_i8 = detail::int8;

	/// Medium qualifier 16 bit signed integer type.
	/// @see gtc_type_precision
	using mediump_i16 = detail::int16;

	/// Medium qualifier 32 bit signed integer type.
	/// @see gtc_type_precision
	using mediump_i32 = detail::int32;

	/// Medium qualifier 64 bit signed integer type.
	/// @see gtc_type_precision
	using mediump_i64 = detail::int64;

	/// High qualifier 8 bit signed integer type.
	/// @see gtc_type_precision
	using highp_int8 = detail::int8;

	/// High qualifier 16 bit signed integer type.
	/// @see gtc_type_precision
	using highp_int16 = detail::int16;

	/// High qualifier 32 bit signed integer type.
	/// @see gtc_type_precision
	using highp_int32 = detail::int32;

	/// High qualifier 64 bit signed integer type.
	/// @see gtc_type_precision
	using highp_int64 = detail::int64;

	/// High qualifier 8 bit signed integer type.
	/// @see gtc_type_precision
	using highp_int8_t = detail::int8;

	/// High qualifier 16 bit signed integer type.
	/// @see gtc_type_precision
	using highp_int16_t = detail::int16;

	/// 32 bit signed integer type.
	/// @see gtc_type_precision
	using highp_int32_t = detail::int32;

	/// High qualifier 64 bit signed integer type.
	/// @see gtc_type_precision
	using highp_int64_t = detail::int64;

	/// High qualifier 8 bit signed integer type.
	/// @see gtc_type_precision
	using highp_i8 = detail::int8;

	/// High qualifier 16 bit signed integer type.
	/// @see gtc_type_precision
	using highp_i16 = detail::int16;

	/// High qualifier 32 bit signed integer type.
	/// @see gtc_type_precision
	using highp_i32 = detail::int32;

	/// High qualifier 64 bit signed integer type.
	/// @see gtc_type_precision
	using highp_i64 = detail::int64;

	/// 8 bit signed integer type.
	/// @see gtc_type_precision
	using std::int8_t;

	/// 16 bit signed integer type.
	/// @see gtc_type_precision
	using std::int16_t;

	/// 32 bit signed integer type.
	/// @see gtc_type_precision
	using std::int32_t;

	/// 64 bit signed integer type.
	/// @see gtc_type_precision
	using std::int64_t;

	/// 8 bit signed integer type.
	/// @see gtc_type_precision
	using i8 = detail::int8;

	/// 16 bit signed integer type.
	/// @see gtc_type_precision
	using i16 = detail::int16;

	/// 32 bit signed integer type.
	/// @see gtc_type_precision
	using i32 = detail::int32;

	/// 64 bit signed integer type.
	/// @see gtc_type_precision
	using i64 = detail::int64;

	/////////////////////////////
	// Unsigned int vector types

	/// Low qualifier 8 bit unsigned integer type.
	/// @see gtc_type_precision
	using lowp_uint8 = detail::uint8;

	/// Low qualifier 16 bit unsigned integer type.
	/// @see gtc_type_precision
	using lowp_uint16 = detail::uint16;

	/// Low qualifier 32 bit unsigned integer type.
	/// @see gtc_type_precision
	using lowp_uint32 = detail::uint32;

	/// Low qualifier 64 bit unsigned integer type.
	/// @see gtc_type_precision
	using lowp_uint64 = detail::uint64;

	/// Low qualifier 8 bit unsigned integer type.
	/// @see gtc_type_precision
	using lowp_uint8_t = detail::uint8;

	/// Low qualifier 16 bit unsigned integer type.
	/// @see gtc_type_precision
	using lowp_uint16_t = detail::uint16;

	/// Low qualifier 32 bit unsigned integer type.
	/// @see gtc_type_precision
	using lowp_uint32_t = detail::uint32;

	/// Low qualifier 64 bit unsigned integer type.
	/// @see gtc_type_precision
	using lowp_uint64_t = detail::uint64;

	/// Low qualifier 8 bit unsigned integer type.
	/// @see gtc_type_precision
	using lowp_u8 = detail::uint8;

	/// Low qualifier 16 bit unsigned integer type.
	/// @see gtc_type_precision
	using lowp_u16 = detail::uint16;

	/// Low qualifier 32 bit unsigned integer type.
	/// @see gtc_type_precision
	using lowp_u32 = detail::uint32;

	/// Low qualifier 64 bit unsigned integer type.
	/// @see gtc_type_precision
	using lowp_u64 = detail::uint64;

	/// Medium qualifier 8 bit unsigned integer type.
	/// @see gtc_type_precision
	using mediump_uint8 = detail::uint8;

	/// Medium qualifier 16 bit unsigned integer type.
	/// @see gtc_type_precision
	using mediump_uint16 = detail::uint16;

	/// Medium qualifier 32 bit unsigned integer type.
	/// @see gtc_type_precision
	using mediump_uint32 = detail::uint32;

	/// Medium qualifier 64 bit unsigned integer type.
	/// @see gtc_type_precision
	using mediump_uint64 = detail::uint64;

	/// Medium qualifier 8 bit unsigned integer type.
	/// @see gtc_type_precision
	using mediump_uint8_t = detail::uint8;

	/// Medium qualifier 16 bit unsigned integer type.
	/// @see gtc_type_precision
	using mediump_uint16_t = detail::uint16;

	/// Medium qualifier 32 bit unsigned integer type.
	/// @see gtc_type_precision
	using mediump_uint32_t = detail::uint32;

	/// Medium qualifier 64 bit unsigned integer type.
	/// @see gtc_type_precision
	using mediump_uint64_t = detail::uint64;

	/// Medium qualifier 8 bit unsigned integer type.
	/// @see gtc_type_precision
	using mediump_u8 = detail::uint8;

	/// Medium qualifier 16 bit unsigned integer type.
	/// @see gtc_type_precision
	using mediump_u16 = detail::uint16;

	/// Medium qualifier 32 bit unsigned integer type.
	/// @see gtc_type_precision
	using mediump_u32 = detail::uint32;

	/// Medium qualifier 64 bit unsigned integer type.
	/// @see gtc_type_precision
	using mediump_u64 = detail::uint64;

	/// High qualifier 8 bit unsigned integer type.
	/// @see gtc_type_precision
	using highp_uint8 = detail::uint8;

	/// High qualifier 16 bit unsigned integer type.
	/// @see gtc_type_precision
	using highp_uint16 = detail::uint16;

	/// High qualifier 32 bit unsigned integer type.
	/// @see gtc_type_precision
	using highp_uint32 = detail::uint32;

	/// High qualifier 64 bit unsigned integer type.
	/// @see gtc_type_precision
	using highp_uint64 = detail::uint64;

	/// High qualifier 8 bit unsigned integer type.
	/// @see gtc_type_precision
	using highp_uint8_t = detail::uint8;

	/// High qualifier 16 bit unsigned integer type.
	/// @see gtc_type_precision
	using highp_uint16_t = detail::uint16;

	/// High qualifier 32 bit unsigned integer type.
	/// @see gtc_type_precision
	using highp_uint32_t = detail::uint32;

	/// High qualifier 64 bit unsigned integer type.
	/// @see gtc_type_precision
	using highp_uint64_t = detail::uint64;

	/// High qualifier 8 bit unsigned integer type.
	/// @see gtc_type_precision
	using highp_u8 = detail::uint8;

	/// High qualifier 16 bit unsigned integer type.
	/// @see gtc_type_precision
	using highp_u16 = detail::uint16;

	/// High qualifier 32 bit unsigned integer type.
	/// @see gtc_type_precision
	using highp_u32 = detail::uint32;

	/// High qualifier 64 bit unsigned integer type.
	/// @see gtc_type_precision
	using highp_u64 = detail::uint64;

	/// Default qualifier 8 bit unsigned integer type.
	/// @see gtc_type_precision
	using std::uint8_t;

	/// Default qualifier 16 bit unsigned integer type.
	/// @see gtc_type_precision
	using std::uint16_t;

	/// Default qualifier 32 bit unsigned integer type.
	/// @see gtc_type_precision
	using std::uint32_t;

	/// Default qualifier 64 bit unsigned integer type.
	/// @see gtc_type_precision
	using std::uint64_t;

	/// Default qualifier 8 bit unsigned integer type.
	/// @see gtc_type_precision
	using u8 = detail::uint8;

	/// Default qualifier 16 bit unsigned integer type.
	/// @see gtc_type_precision
	using u16 = detail::uint16;

	/// Default qualifier 32 bit unsigned integer type.
	/// @see gtc_type_precision
	using u32 = detail::uint32;

	/// Default qualifier 64 bit unsigned integer type.
	/// @see gtc_type_precision
	using u64 = detail::uint64;





	//////////////////////
	// Float vector types

	/// Single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using float32 = float;

	/// Double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using float64 = double;

	/// Low 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using lowp_float32 = float32;

	/// Low 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using lowp_float64 = float64;

	/// Low 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using lowp_float32_t = float32;

	/// Low 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using lowp_float64_t = float64;

	/// Low 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using lowp_f32 = float32;

	/// Low 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using lowp_f64 = float64;

	/// Low 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using lowp_float32 = float32;

	/// Low 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using lowp_float64 = float64;

	/// Low 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using lowp_float32_t = float32;

	/// Low 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using lowp_float64_t = float64;

	/// Low 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using lowp_f32 = float32;

	/// Low 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using lowp_f64 = float64;


	/// Low 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using lowp_float32 = float32;

	/// Low 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using lowp_float64 = float64;

	/// Low 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using lowp_float32_t = float32;

	/// Low 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using lowp_float64_t = float64;

	/// Low 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using lowp_f32 = float32;

	/// Low 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using lowp_f64 = float64;


	/// Medium 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using mediump_float32 = float32;

	/// Medium 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using mediump_float64 = float64;

	/// Medium 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using mediump_float32_t = float32;

	/// Medium 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using mediump_float64_t = float64;

	/// Medium 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using mediump_f32 = float32;

	/// Medium 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using mediump_f64 = float64;


	/// High 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using highp_float32 = float32;

	/// High 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using highp_float64 = float64;

	/// High 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using highp_float32_t = float32;

	/// High 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using highp_float64_t = float64;

	/// High 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using highp_f32 = float32;

	/// High 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using highp_f64 = float64;


#if(defined(GLM_PRECISION_LOWP_FLOAT))
	/// Default 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using float32_t = lowp_float32_t;

	/// Default 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using float64_t = lowp_float64_t;

	/// Default 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using f32 = lowp_f32;

	/// Default 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using f64 = lowp_f64;

#elif(defined(GLM_PRECISION_MEDIUMP_FLOAT))
	/// Default 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using float32_t = mediump_float32;

	/// Default 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using float64_t = mediump_float64;

	/// Default 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using f32 = mediump_float32;

	/// Default 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using f64 = mediump_float64;

#else//(defined(GLM_PRECISION_HIGHP_FLOAT))

	/// Default 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using float32_t = highp_float32_t;

	/// Default 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using float64_t = highp_float64_t;

	/// Default 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using f32 = highp_float32_t;

	/// Default 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using f64 = highp_float64_t;
#endif


	/// Low single-qualifier floating-point vector of 1 component.
	/// @see gtc_type_precision
	using lowp_fvec1 = vec<1, float, lowp>;

	/// Low single-qualifier floating-point vector of 2 components.
	/// @see gtc_type_precision
	using lowp_fvec2 = vec<2, float, lowp>;

	/// Low single-qualifier floating-point vector of 3 components.
	/// @see gtc_type_precision
	using lowp_fvec3 = vec<3, float, lowp>;

	/// Low single-qualifier floating-point vector of 4 components.
	/// @see gtc_type_precision
	using lowp_fvec4 = vec<4, float, lowp>;


	/// Medium single-qualifier floating-point vector of 1 component.
	/// @see gtc_type_precision
	using mediump_fvec1 = vec<1, float, mediump>;

	/// Medium Single-qualifier floating-point vector of 2 components.
	/// @see gtc_type_precision
	using mediump_fvec2 = vec<2, float, mediump>;

	/// Medium Single-qualifier floating-point vector of 3 components.
	/// @see gtc_type_precision
	using mediump_fvec3 = vec<3, float, mediump>;

	/// Medium Single-qualifier floating-point vector of 4 components.
	/// @see gtc_type_precision
	using mediump_fvec4 = vec<4, float, mediump>;


	/// High single-qualifier floating-point vector of 1 component.
	/// @see gtc_type_precision
	using highp_fvec1 = vec<1, float, highp>;

	/// High Single-qualifier floating-point vector of 2 components.
	/// @see core_precision
	using highp_fvec2 = vec<2, float, highp>;

	/// High Single-qualifier floating-point vector of 3 components.
	/// @see core_precision
	using highp_fvec3 = vec<3, float, highp>;

	/// High Single-qualifier floating-point vector of 4 components.
	/// @see core_precision
	using highp_fvec4 = vec<4, float, highp>;


	/// Low single-qualifier floating-point vector of 1 component.
	/// @see gtc_type_precision
	using lowp_f32vec1 = vec<1, f32, lowp>;

	/// Low single-qualifier floating-point vector of 2 components.
	/// @see core_precision
	using lowp_f32vec2 = vec<2, f32, lowp>;

	/// Low single-qualifier floating-point vector of 3 components.
	/// @see core_precision
	using lowp_f32vec3 = vec<3, f32, lowp>;

	/// Low single-qualifier floating-point vector of 4 components.
	/// @see core_precision
	using lowp_f32vec4 = vec<4, f32, lowp>;

	/// Medium single-qualifier floating-point vector of 1 component.
	/// @see gtc_type_precision
	using mediump_f32vec1 = vec<1, f32, mediump>;

	/// Medium single-qualifier floating-point vector of 2 components.
	/// @see core_precision
	using mediump_f32vec2 = vec<2, f32, mediump>;

	/// Medium single-qualifier floating-point vector of 3 components.
	/// @see core_precision
	using mediump_f32vec3 = vec<3, f32, mediump>;

	/// Medium single-qualifier floating-point vector of 4 components.
	/// @see core_precision
	using mediump_f32vec4 = vec<4, f32, mediump>;

	/// High single-qualifier floating-point vector of 1 component.
	/// @see gtc_type_precision
	using highp_f32vec1 = vec<1, f32, highp>;

	/// High single-qualifier floating-point vector of 2 components.
	/// @see gtc_type_precision
	using highp_f32vec2 = vec<2, f32, highp>;

	/// High single-qualifier floating-point vector of 3 components.
	/// @see gtc_type_precision
	using highp_f32vec3 = vec<3, f32, highp>;

	/// High single-qualifier floating-point vector of 4 components.
	/// @see gtc_type_precision
	using highp_f32vec4 = vec<4, f32, highp>;


	/// Low double-qualifier floating-point vector of 1 component.
	/// @see gtc_type_precision
	using lowp_f64vec1 = vec<1, f64, lowp>;

	/// Low double-qualifier floating-point vector of 2 components.
	/// @see gtc_type_precision
	using lowp_f64vec2 = vec<2, f64, lowp>;

	/// Low double-qualifier floating-point vector of 3 components.
	/// @see gtc_type_precision
	using lowp_f64vec3 = vec<3, f64, lowp>;

	/// Low double-qualifier floating-point vector of 4 components.
	/// @see gtc_type_precision
	using lowp_f64vec4 = vec<4, f64, lowp>;

	/// Medium double-qualifier floating-point vector of 1 component.
	/// @see gtc_type_precision
	using mediump_f64vec1 = vec<1, f64, mediump>;

	/// Medium double-qualifier floating-point vector of 2 components.
	/// @see gtc_type_precision
	using mediump_f64vec2 = vec<2, f64, mediump>;

	/// Medium double-qualifier floating-point vector of 3 components.
	/// @see gtc_type_precision
	using mediump_f64vec3 = vec<3, f64, mediump>;

	/// Medium double-qualifier floating-point vector of 4 components.
	/// @see gtc_type_precision
	using mediump_f64vec4 = vec<4, f64, mediump>;

	/// High double-qualifier floating-point vector of 1 component.
	/// @see gtc_type_precision
	using highp_f64vec1 = vec<1, f64, highp>;

	/// High double-qualifier floating-point vector of 2 components.
	/// @see gtc_type_precision
	using highp_f64vec2 = vec<2, f64, highp>;

	/// High double-qualifier floating-point vector of 3 components.
	/// @see gtc_type_precision
	using highp_f64vec3 = vec<3, f64, highp>;

	/// High double-qualifier floating-point vector of 4 components.
	/// @see gtc_type_precision
	using highp_f64vec4 = vec<4, f64, highp>;



	//////////////////////
	// Float matrix types

	/// Low single-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef lowp_f32 lowp_fmat1x1;

	/// Low single-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	using lowp_fmat2x2 = mat<2, 2, f32, lowp>;

	/// Low single-qualifier floating-point 2x3 matrix.
	/// @see gtc_type_precision
	using lowp_fmat2x3 = mat<2, 3, f32, lowp>;

	/// Low single-qualifier floating-point 2x4 matrix.
	/// @see gtc_type_precision
	using lowp_fmat2x4 = mat<2, 4, f32, lowp>;

	/// Low single-qualifier floating-point 3x2 matrix.
	/// @see gtc_type_precision
	using lowp_fmat3x2 = mat<3, 2, f32, lowp>;

	/// Low single-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	using lowp_fmat3x3 = mat<3, 3, f32, lowp>;

	/// Low single-qualifier floating-point 3x4 matrix.
	/// @see gtc_type_precision
	using lowp_fmat3x4 = mat<3, 4, f32, lowp>;

	/// Low single-qualifier floating-point 4x2 matrix.
	/// @see gtc_type_precision
	using lowp_fmat4x2 = mat<4, 2, f32, lowp>;

	/// Low single-qualifier floating-point 4x3 matrix.
	/// @see gtc_type_precision
	using lowp_fmat4x3 = mat<4, 3, f32, lowp>;

	/// Low single-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	using lowp_fmat4x4 = mat<4, 4, f32, lowp>;

	/// Low single-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef lowp_fmat1x1 lowp_fmat1;

	/// Low single-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	using lowp_fmat2 = lowp_fmat2x2;

	/// Low single-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	using lowp_fmat3 = lowp_fmat3x3;

	/// Low single-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	using lowp_fmat4 = lowp_fmat4x4;


	/// Medium single-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef mediump_f32 mediump_fmat1x1;

	/// Medium single-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	using mediump_fmat2x2 = mat<2, 2, f32, mediump>;

	/// Medium single-qualifier floating-point 2x3 matrix.
	/// @see gtc_type_precision
	using mediump_fmat2x3 = mat<2, 3, f32, mediump>;

	/// Medium single-qualifier floating-point 2x4 matrix.
	/// @see gtc_type_precision
	using mediump_fmat2x4 = mat<2, 4, f32, mediump>;

	/// Medium single-qualifier floating-point 3x2 matrix.
	/// @see gtc_type_precision
	using mediump_fmat3x2 = mat<3, 2, f32, mediump>;

	/// Medium single-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	using mediump_fmat3x3 = mat<3, 3, f32, mediump>;

	/// Medium single-qualifier floating-point 3x4 matrix.
	/// @see gtc_type_precision
	using mediump_fmat3x4 = mat<3, 4, f32, mediump>;

	/// Medium single-qualifier floating-point 4x2 matrix.
	/// @see gtc_type_precision
	using mediump_fmat4x2 = mat<4, 2, f32, mediump>;

	/// Medium single-qualifier floating-point 4x3 matrix.
	/// @see gtc_type_precision
	using mediump_fmat4x3 = mat<4, 3, f32, mediump>;

	/// Medium single-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	using mediump_fmat4x4 = mat<4, 4, f32, mediump>;

	/// Medium single-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef mediump_fmat1x1 mediump_fmat1;

	/// Medium single-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	using mediump_fmat2 = mediump_fmat2x2;

	/// Medium single-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	using mediump_fmat3 = mediump_fmat3x3;

	/// Medium single-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	using mediump_fmat4 = mediump_fmat4x4;


	/// High single-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef highp_f32 highp_fmat1x1;

	/// High single-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	using highp_fmat2x2 = mat<2, 2, f32, highp>;

	/// High single-qualifier floating-point 2x3 matrix.
	/// @see gtc_type_precision
	using highp_fmat2x3 = mat<2, 3, f32, highp>;

	/// High single-qualifier floating-point 2x4 matrix.
	/// @see gtc_type_precision
	using highp_fmat2x4 = mat<2, 4, f32, highp>;

	/// High single-qualifier floating-point 3x2 matrix.
	/// @see gtc_type_precision
	using highp_fmat3x2 = mat<3, 2, f32, highp>;

	/// High single-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	using highp_fmat3x3 = mat<3, 3, f32, highp>;

	/// High single-qualifier floating-point 3x4 matrix.
	/// @see gtc_type_precision
	using highp_fmat3x4 = mat<3, 4, f32, highp>;

	/// High single-qualifier floating-point 4x2 matrix.
	/// @see gtc_type_precision
	using highp_fmat4x2 = mat<4, 2, f32, highp>;

	/// High single-qualifier floating-point 4x3 matrix.
	/// @see gtc_type_precision
	using highp_fmat4x3 = mat<4, 3, f32, highp>;

	/// High single-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	using highp_fmat4x4 = mat<4, 4, f32, highp>;

	/// High single-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef highp_fmat1x1 highp_fmat1;

	/// High single-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	using highp_fmat2 = highp_fmat2x2;

	/// High single-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	using highp_fmat3 = highp_fmat3x3;

	/// High single-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	using highp_fmat4 = highp_fmat4x4;


	/// Low single-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef f32 lowp_f32mat1x1;

	/// Low single-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	using lowp_f32mat2x2 = mat<2, 2, f32, lowp>;

	/// Low single-qualifier floating-point 2x3 matrix.
	/// @see gtc_type_precision
	using lowp_f32mat2x3 = mat<2, 3, f32, lowp>;

	/// Low single-qualifier floating-point 2x4 matrix.
	/// @see gtc_type_precision
	using lowp_f32mat2x4 = mat<2, 4, f32, lowp>;

	/// Low single-qualifier floating-point 3x2 matrix.
	/// @see gtc_type_precision
	using lowp_f32mat3x2 = mat<3, 2, f32, lowp>;

	/// Low single-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	using lowp_f32mat3x3 = mat<3, 3, f32, lowp>;

	/// Low single-qualifier floating-point 3x4 matrix.
	/// @see gtc_type_precision
	using lowp_f32mat3x4 = mat<3, 4, f32, lowp>;

	/// Low single-qualifier floating-point 4x2 matrix.
	/// @see gtc_type_precision
	using lowp_f32mat4x2 = mat<4, 2, f32, lowp>;

	/// Low single-qualifier floating-point 4x3 matrix.
	/// @see gtc_type_precision
	using lowp_f32mat4x3 = mat<4, 3, f32, lowp>;

	/// Low single-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	using lowp_f32mat4x4 = mat<4, 4, f32, lowp>;

	/// Low single-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef detail::tmat1x1<f32, lowp> lowp_f32mat1;

	/// Low single-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	using lowp_f32mat2 = lowp_f32mat2x2;

	/// Low single-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	using lowp_f32mat3 = lowp_f32mat3x3;

	/// Low single-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	using lowp_f32mat4 = lowp_f32mat4x4;


	/// High single-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef f32 mediump_f32mat1x1;

	/// Low single-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	using mediump_f32mat2x2 = mat<2, 2, f32, mediump>;

	/// Medium single-qualifier floating-point 2x3 matrix.
	/// @see gtc_type_precision
	using mediump_f32mat2x3 = mat<2, 3, f32, mediump>;

	/// Medium single-qualifier floating-point 2x4 matrix.
	/// @see gtc_type_precision
	using mediump_f32mat2x4 = mat<2, 4, f32, mediump>;

	/// Medium single-qualifier floating-point 3x2 matrix.
	/// @see gtc_type_precision
	using mediump_f32mat3x2 = mat<3, 2, f32, mediump>;

	/// Medium single-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	using mediump_f32mat3x3 = mat<3, 3, f32, mediump>;

	/// Medium single-qualifier floating-point 3x4 matrix.
	/// @see gtc_type_precision
	using mediump_f32mat3x4 = mat<3, 4, f32, mediump>;

	/// Medium single-qualifier floating-point 4x2 matrix.
	/// @see gtc_type_precision
	using mediump_f32mat4x2 = mat<4, 2, f32, mediump>;

	/// Medium single-qualifier floating-point 4x3 matrix.
	/// @see gtc_type_precision
	using mediump_f32mat4x3 = mat<4, 3, f32, mediump>;

	/// Medium single-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	using mediump_f32mat4x4 = mat<4, 4, f32, mediump>;

	/// Medium single-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef detail::tmat1x1<f32, mediump> f32mat1;

	/// Medium single-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	using mediump_f32mat2 = mediump_f32mat2x2;

	/// Medium single-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	using mediump_f32mat3 = mediump_f32mat3x3;

	/// Medium single-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	using mediump_f32mat4 = mediump_f32mat4x4;


	/// High single-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef f32 highp_f32mat1x1;

	/// High single-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	using highp_f32mat2x2 = mat<2, 2, f32, highp>;

	/// High single-qualifier floating-point 2x3 matrix.
	/// @see gtc_type_precision
	using highp_f32mat2x3 = mat<2, 3, f32, highp>;

	/// High single-qualifier floating-point 2x4 matrix.
	/// @see gtc_type_precision
	using highp_f32mat2x4 = mat<2, 4, f32, highp>;

	/// High single-qualifier floating-point 3x2 matrix.
	/// @see gtc_type_precision
	using highp_f32mat3x2 = mat<3, 2, f32, highp>;

	/// High single-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	using highp_f32mat3x3 = mat<3, 3, f32, highp>;

	/// High single-qualifier floating-point 3x4 matrix.
	/// @see gtc_type_precision
	using highp_f32mat3x4 = mat<3, 4, f32, highp>;

	/// High single-qualifier floating-point 4x2 matrix.
	/// @see gtc_type_precision
	using highp_f32mat4x2 = mat<4, 2, f32, highp>;

	/// High single-qualifier floating-point 4x3 matrix.
	/// @see gtc_type_precision
	using highp_f32mat4x3 = mat<4, 3, f32, highp>;

	/// High single-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	using highp_f32mat4x4 = mat<4, 4, f32, highp>;

	/// High single-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef detail::tmat1x1<f32, highp> f32mat1;

	/// High single-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	using highp_f32mat2 = highp_f32mat2x2;

	/// High single-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	using highp_f32mat3 = highp_f32mat3x3;

	/// High single-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	using highp_f32mat4 = highp_f32mat4x4;


	/// Low double-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef f64 lowp_f64mat1x1;

	/// Low double-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	using lowp_f64mat2x2 = mat<2, 2, f64, lowp>;

	/// Low double-qualifier floating-point 2x3 matrix.
	/// @see gtc_type_precision
	using lowp_f64mat2x3 = mat<2, 3, f64, lowp>;

	/// Low double-qualifier floating-point 2x4 matrix.
	/// @see gtc_type_precision
	using lowp_f64mat2x4 = mat<2, 4, f64, lowp>;

	/// Low double-qualifier floating-point 3x2 matrix.
	/// @see gtc_type_precision
	using lowp_f64mat3x2 = mat<3, 2, f64, lowp>;

	/// Low double-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	using lowp_f64mat3x3 = mat<3, 3, f64, lowp>;

	/// Low double-qualifier floating-point 3x4 matrix.
	/// @see gtc_type_precision
	using lowp_f64mat3x4 = mat<3, 4, f64, lowp>;

	/// Low double-qualifier floating-point 4x2 matrix.
	/// @see gtc_type_precision
	using lowp_f64mat4x2 = mat<4, 2, f64, lowp>;

	/// Low double-qualifier floating-point 4x3 matrix.
	/// @see gtc_type_precision
	using lowp_f64mat4x3 = mat<4, 3, f64, lowp>;

	/// Low double-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	using lowp_f64mat4x4 = mat<4, 4, f64, lowp>;

	/// Low double-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef lowp_f64mat1x1 lowp_f64mat1;

	/// Low double-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	using lowp_f64mat2 = lowp_f64mat2x2;

	/// Low double-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	using lowp_f64mat3 = lowp_f64mat3x3;

	/// Low double-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	using lowp_f64mat4 = lowp_f64mat4x4;


	/// Medium double-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef f64 Highp_f64mat1x1;

	/// Medium double-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	using mediump_f64mat2x2 = mat<2, 2, f64, mediump>;

	/// Medium double-qualifier floating-point 2x3 matrix.
	/// @see gtc_type_precision
	using mediump_f64mat2x3 = mat<2, 3, f64, mediump>;

	/// Medium double-qualifier floating-point 2x4 matrix.
	/// @see gtc_type_precision
	using mediump_f64mat2x4 = mat<2, 4, f64, mediump>;

	/// Medium double-qualifier floating-point 3x2 matrix.
	/// @see gtc_type_precision
	using mediump_f64mat3x2 = mat<3, 2, f64, mediump>;

	/// Medium double-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	using mediump_f64mat3x3 = mat<3, 3, f64, mediump>;

	/// Medium double-qualifier floating-point 3x4 matrix.
	/// @see gtc_type_precision
	using mediump_f64mat3x4 = mat<3, 4, f64, mediump>;

	/// Medium double-qualifier floating-point 4x2 matrix.
	/// @see gtc_type_precision
	using mediump_f64mat4x2 = mat<4, 2, f64, mediump>;

	/// Medium double-qualifier floating-point 4x3 matrix.
	/// @see gtc_type_precision
	using mediump_f64mat4x3 = mat<4, 3, f64, mediump>;

	/// Medium double-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	using mediump_f64mat4x4 = mat<4, 4, f64, mediump>;

	/// Medium double-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef mediump_f64mat1x1 mediump_f64mat1;

	/// Medium double-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	using mediump_f64mat2 = mediump_f64mat2x2;

	/// Medium double-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	using mediump_f64mat3 = mediump_f64mat3x3;

	/// Medium double-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	using mediump_f64mat4 = mediump_f64mat4x4;

	/// High double-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef f64 highp_f64mat1x1;

	/// High double-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	using highp_f64mat2x2 = mat<2, 2, f64, highp>;

	/// High double-qualifier floating-point 2x3 matrix.
	/// @see gtc_type_precision
	using highp_f64mat2x3 = mat<2, 3, f64, highp>;

	/// High double-qualifier floating-point 2x4 matrix.
	/// @see gtc_type_precision
	using highp_f64mat2x4 = mat<2, 4, f64, highp>;

	/// High double-qualifier floating-point 3x2 matrix.
	/// @see gtc_type_precision
	using highp_f64mat3x2 = mat<3, 2, f64, highp>;

	/// High double-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	using highp_f64mat3x3 = mat<3, 3, f64, highp>;

	/// High double-qualifier floating-point 3x4 matrix.
	/// @see gtc_type_precision
	using highp_f64mat3x4 = mat<3, 4, f64, highp>;

	/// High double-qualifier floating-point 4x2 matrix.
	/// @see gtc_type_precision
	using highp_f64mat4x2 = mat<4, 2, f64, highp>;

	/// High double-qualifier floating-point 4x3 matrix.
	/// @see gtc_type_precision
	using highp_f64mat4x3 = mat<4, 3, f64, highp>;

	/// High double-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	using highp_f64mat4x4 = mat<4, 4, f64, highp>;

	/// High double-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef highp_f64mat1x1 highp_f64mat1;

	/// High double-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	using highp_f64mat2 = highp_f64mat2x2;

	/// High double-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	using highp_f64mat3 = highp_f64mat3x3;

	/// High double-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	using highp_f64mat4 = highp_f64mat4x4;


	/////////////////////////////
	// Signed int vector types

	/// Low qualifier signed integer vector of 1 component type.
	/// @see gtc_type_precision
	using		lowp_ivec1 = vec<1, int, lowp>;

	/// Low qualifier signed integer vector of 2 components type.
	/// @see gtc_type_precision
	using		lowp_ivec2 = vec<2, int, lowp>;

	/// Low qualifier signed integer vector of 3 components type.
	/// @see gtc_type_precision
	using		lowp_ivec3 = vec<3, int, lowp>;

	/// Low qualifier signed integer vector of 4 components type.
	/// @see gtc_type_precision
	using		lowp_ivec4 = vec<4, int, lowp>;


	/// Medium qualifier signed integer vector of 1 component type.
	/// @see gtc_type_precision
	using	mediump_ivec1 = vec<1, int, mediump>;

	/// Medium qualifier signed integer vector of 2 components type.
	/// @see gtc_type_precision
	using	mediump_ivec2 = vec<2, int, mediump>;

	/// Medium qualifier signed integer vector of 3 components type.
	/// @see gtc_type_precision
	using	mediump_ivec3 = vec<3, int, mediump>;

	/// Medium qualifier signed integer vector of 4 components type.
	/// @see gtc_type_precision
	using	mediump_ivec4 = vec<4, int, mediump>;


	/// High qualifier signed integer vector of 1 component type.
	/// @see gtc_type_precision
	using		highp_ivec1 = vec<1, int, highp>;

	/// High qualifier signed integer vector of 2 components type.
	/// @see gtc_type_precision
	using		highp_ivec2 = vec<2, int, highp>;

	/// High qualifier signed integer vector of 3 components type.
	/// @see gtc_type_precision
	using		highp_ivec3 = vec<3, int, highp>;

	/// High qualifier signed integer vector of 4 components type.
	/// @see gtc_type_precision
	using		highp_ivec4 = vec<4, int, highp>;


	/// Low qualifier 8 bit signed integer vector of 1 component type.
	/// @see gtc_type_precision
	using		lowp_i8vec1 = vec<1, i8, lowp>;

	/// Low qualifier 8 bit signed integer vector of 2 components type.
	/// @see gtc_type_precision
	using		lowp_i8vec2 = vec<2, i8, lowp>;

	/// Low qualifier 8 bit signed integer vector of 3 components type.
	/// @see gtc_type_precision
	using		lowp_i8vec3 = vec<3, i8, lowp>;

	/// Low qualifier 8 bit signed integer vector of 4 components type.
	/// @see gtc_type_precision
	using		lowp_i8vec4 = vec<4, i8, lowp>;


	/// Medium qualifier 8 bit signed integer scalar type.
	/// @see gtc_type_precision
	using		mediump_i8vec1 = vec<1, i8, mediump>;

	/// Medium qualifier 8 bit signed integer vector of 2 components type.
	/// @see gtc_type_precision
	using		mediump_i8vec2 = vec<2, i8, mediump>;

	/// Medium qualifier 8 bit signed integer vector of 3 components type.
	/// @see gtc_type_precision
	using		mediump_i8vec3 = vec<3, i8, mediump>;

	/// Medium qualifier 8 bit signed integer vector of 4 components type.
	/// @see gtc_type_precision
	using		mediump_i8vec4 = vec<4, i8, mediump>;


	/// High qualifier 8 bit signed integer scalar type.
	/// @see gtc_type_precision
	using		highp_i8vec1 = vec<1, i8, highp>;

	/// High qualifier 8 bit signed integer vector of 2 components type.
	/// @see gtc_type_precision
	using		highp_i8vec2 = vec<2, i8, highp>;

	/// High qualifier 8 bit signed integer vector of 3 components type.
	/// @see gtc_type_precision
	using		highp_i8vec3 = vec<3, i8, highp>;

	/// High qualifier 8 bit signed integer vector of 4 components type.
	/// @see gtc_type_precision
	using		highp_i8vec4 = vec<4, i8, highp>;


	/// Low qualifier 16 bit signed integer scalar type.
	/// @see gtc_type_precision
	using		lowp_i16vec1 = vec<1, i16, lowp>;

	/// Low qualifier 16 bit signed integer vector of 2 components type.
	/// @see gtc_type_precision
	using		lowp_i16vec2 = vec<2, i16, lowp>;

	/// Low qualifier 16 bit signed integer vector of 3 components type.
	/// @see gtc_type_precision
	using		lowp_i16vec3 = vec<3, i16, lowp>;

	/// Low qualifier 16 bit signed integer vector of 4 components type.
	/// @see gtc_type_precision
	using		lowp_i16vec4 = vec<4, i16, lowp>;


	/// Medium qualifier 16 bit signed integer scalar type.
	/// @see gtc_type_precision
	using	mediump_i16vec1 = vec<1, i16, mediump>;

	/// Medium qualifier 16 bit signed integer vector of 2 components type.
	/// @see gtc_type_precision
	using	mediump_i16vec2 = vec<2, i16, mediump>;

	/// Medium qualifier 16 bit signed integer vector of 3 components type.
	/// @see gtc_type_precision
	using	mediump_i16vec3 = vec<3, i16, mediump>;

	/// Medium qualifier 16 bit signed integer vector of 4 components type.
	/// @see gtc_type_precision
	using	mediump_i16vec4 = vec<4, i16, mediump>;


	/// High qualifier 16 bit signed integer scalar type.
	/// @see gtc_type_precision
	using		highp_i16vec1 = vec<1, i16, highp>;

	/// High qualifier 16 bit signed integer vector of 2 components type.
	/// @see gtc_type_precision
	using		highp_i16vec2 = vec<2, i16, highp>;

	/// High qualifier 16 bit signed integer vector of 3 components type.
	/// @see gtc_type_precision
	using		highp_i16vec3 = vec<3, i16, highp>;

	/// High qualifier 16 bit signed integer vector of 4 components type.
	/// @see gtc_type_precision
	using		highp_i16vec4 = vec<4, i16, highp>;


	/// Low qualifier 32 bit signed integer scalar type.
	/// @see gtc_type_precision
	using		lowp_i32vec1 = vec<1, i32, lowp>;

	/// Low qualifier 32 bit signed integer vector of 2 components type.
	/// @see gtc_type_precision
	using		lowp_i32vec2 = vec<2, i32, lowp>;

	/// Low qualifier 32 bit signed integer vector of 3 components type.
	/// @see gtc_type_precision
	using		lowp_i32vec3 = vec<3, i32, lowp>;

	/// Low qualifier 32 bit signed integer vector of 4 components type.
	/// @see gtc_type_precision
	using		lowp_i32vec4 = vec<4, i32, lowp>;


	/// Medium qualifier 32 bit signed integer scalar type.
	/// @see gtc_type_precision
	using	mediump_i32vec1 = vec<1, i32, mediump>;

	/// Medium qualifier 32 bit signed integer vector of 2 components type.
	/// @see gtc_type_precision
	using	mediump_i32vec2 = vec<2, i32, mediump>;

	/// Medium qualifier 32 bit signed integer vector of 3 components type.
	/// @see gtc_type_precision
	using	mediump_i32vec3 = vec<3, i32, mediump>;

	/// Medium qualifier 32 bit signed integer vector of 4 components type.
	/// @see gtc_type_precision
	using	mediump_i32vec4 = vec<4, i32, mediump>;


	/// High qualifier 32 bit signed integer scalar type.
	/// @see gtc_type_precision
	using		highp_i32vec1 = vec<1, i32, highp>;

	/// High qualifier 32 bit signed integer vector of 2 components type.
	/// @see gtc_type_precision
	using		highp_i32vec2 = vec<2, i32, highp>;

	/// High qualifier 32 bit signed integer vector of 3 components type.
	/// @see gtc_type_precision
	using		highp_i32vec3 = vec<3, i32, highp>;

	/// High qualifier 32 bit signed integer vector of 4 components type.
	/// @see gtc_type_precision
	using		highp_i32vec4 = vec<4, i32, highp>;


	/// Low qualifier 64 bit signed integer scalar type.
	/// @see gtc_type_precision
	using		lowp_i64vec1 = vec<1, i64, lowp>;

	/// Low qualifier 64 bit signed integer vector of 2 components type.
	/// @see gtc_type_precision
	using		lowp_i64vec2 = vec<2, i64, lowp>;

	/// Low qualifier 64 bit signed integer vector of 3 components type.
	/// @see gtc_type_precision
	using		lowp_i64vec3 = vec<3, i64, lowp>;

	/// Low qualifier 64 bit signed integer vector of 4 components type.
	/// @see gtc_type_precision
	using		lowp_i64vec4 = vec<4, i64, lowp>;


	/// Medium qualifier 64 bit signed integer scalar type.
	/// @see gtc_type_precision
	using	mediump_i64vec1 = vec<1, i64, mediump>;

	/// Medium qualifier 64 bit signed integer vector of 2 components type.
	/// @see gtc_type_precision
	using	mediump_i64vec2 = vec<2, i64, mediump>;

	/// Medium qualifier 64 bit signed integer vector of 3 components type.
	/// @see gtc_type_precision
	using	mediump_i64vec3 = vec<3, i64, mediump>;

	/// Medium qualifier 64 bit signed integer vector of 4 components type.
	/// @see gtc_type_precision
	using	mediump_i64vec4 = vec<4, i64, mediump>;


	/// High qualifier 64 bit signed integer scalar type.
	/// @see gtc_type_precision
	using		highp_i64vec1 = vec<1, i64, highp>;

	/// High qualifier 64 bit signed integer vector of 2 components type.
	/// @see gtc_type_precision
	using		highp_i64vec2 = vec<2, i64, highp>;

	/// High qualifier 64 bit signed integer vector of 3 components type.
	/// @see gtc_type_precision
	using		highp_i64vec3 = vec<3, i64, highp>;

	/// High qualifier 64 bit signed integer vector of 4 components type.
	/// @see gtc_type_precision
	using		highp_i64vec4 = vec<4, i64, highp>;


	/////////////////////////////
	// Unsigned int vector types

	/// Low qualifier unsigned integer vector of 1 component type.
	/// @see gtc_type_precision
	using		lowp_uvec1 = vec<1, uint, lowp>;

	/// Low qualifier unsigned integer vector of 2 components type.
	/// @see gtc_type_precision
	using		lowp_uvec2 = vec<2, uint, lowp>;

	/// Low qualifier unsigned integer vector of 3 components type.
	/// @see gtc_type_precision
	using		lowp_uvec3 = vec<3, uint, lowp>;

	/// Low qualifier unsigned integer vector of 4 components type.
	/// @see gtc_type_precision
	using		lowp_uvec4 = vec<4, uint, lowp>;


	/// Medium qualifier unsigned integer vector of 1 component type.
	/// @see gtc_type_precision
	using	mediump_uvec1 = vec<1, uint, mediump>;

	/// Medium qualifier unsigned integer vector of 2 components type.
	/// @see gtc_type_precision
	using	mediump_uvec2 = vec<2, uint, mediump>;

	/// Medium qualifier unsigned integer vector of 3 components type.
	/// @see gtc_type_precision
	using	mediump_uvec3 = vec<3, uint, mediump>;

	/// Medium qualifier unsigned integer vector of 4 components type.
	/// @see gtc_type_precision
	using	mediump_uvec4 = vec<4, uint, mediump>;


	/// High qualifier unsigned integer vector of 1 component type.
	/// @see gtc_type_precision
	using		highp_uvec1 = vec<1, uint, highp>;

	/// High qualifier unsigned integer vector of 2 components type.
	/// @see gtc_type_precision
	using		highp_uvec2 = vec<2, uint, highp>;

	/// High qualifier unsigned integer vector of 3 components type.
	/// @see gtc_type_precision
	using		highp_uvec3 = vec<3, uint, highp>;

	/// High qualifier unsigned integer vector of 4 components type.
	/// @see gtc_type_precision
	using		highp_uvec4 = vec<4, uint, highp>;


	/// Low qualifier 8 bit unsigned integer scalar type.
	/// @see gtc_type_precision
	using		lowp_u8vec1 = vec<1, u8, lowp>;

	/// Low qualifier 8 bit unsigned integer vector of 2 components type.
	/// @see gtc_type_precision
	using		lowp_u8vec2 = vec<2, u8, lowp>;

	/// Low qualifier 8 bit unsigned integer vector of 3 components type.
	/// @see gtc_type_precision
	using		lowp_u8vec3 = vec<3, u8, lowp>;

	/// Low qualifier 8 bit unsigned integer vector of 4 components type.
	/// @see gtc_type_precision
	using		lowp_u8vec4 = vec<4, u8, lowp>;


	/// Medium qualifier 8 bit unsigned integer scalar type.
	/// @see gtc_type_precision
	using		mediump_u8vec1 = vec<1, u8, mediump>;

	/// Medium qualifier 8 bit unsigned integer vector of 2 components type.
	/// @see gtc_type_precision
	using		mediump_u8vec2 = vec<2, u8, mediump>;

	/// Medium qualifier 8 bit unsigned integer vector of 3 components type.
	/// @see gtc_type_precision
	using		mediump_u8vec3 = vec<3, u8, mediump>;

	/// Medium qualifier 8 bit unsigned integer vector of 4 components type.
	/// @see gtc_type_precision
	using		mediump_u8vec4 = vec<4, u8, mediump>;


	/// High qualifier 8 bit unsigned integer scalar type.
	/// @see gtc_type_precision
	using		highp_u8vec1 = vec<1, u8, highp>;

	/// High qualifier 8 bit unsigned integer vector of 2 components type.
	/// @see gtc_type_precision
	using		highp_u8vec2 = vec<2, u8, highp>;

	/// High qualifier 8 bit unsigned integer vector of 3 components type.
	/// @see gtc_type_precision
	using		highp_u8vec3 = vec<3, u8, highp>;

	/// High qualifier 8 bit unsigned integer vector of 4 components type.
	/// @see gtc_type_precision
	using		highp_u8vec4 = vec<4, u8, highp>;


	/// Low qualifier 16 bit unsigned integer scalar type.
	/// @see gtc_type_precision
	using		lowp_u16vec1 = vec<1, u16, lowp>;

	/// Low qualifier 16 bit unsigned integer vector of 2 components type.
	/// @see gtc_type_precision
	using		lowp_u16vec2 = vec<2, u16, lowp>;

	/// Low qualifier 16 bit unsigned integer vector of 3 components type.
	/// @see gtc_type_precision
	using		lowp_u16vec3 = vec<3, u16, lowp>;

	/// Low qualifier 16 bit unsigned integer vector of 4 components type.
	/// @see gtc_type_precision
	using		lowp_u16vec4 = vec<4, u16, lowp>;


	/// Medium qualifier 16 bit unsigned integer scalar type.
	/// @see gtc_type_precision
	using	mediump_u16vec1 = vec<1, u16, mediump>;

	/// Medium qualifier 16 bit unsigned integer vector of 2 components type.
	/// @see gtc_type_precision
	using	mediump_u16vec2 = vec<2, u16, mediump>;

	/// Medium qualifier 16 bit unsigned integer vector of 3 components type.
	/// @see gtc_type_precision
	using	mediump_u16vec3 = vec<3, u16, mediump>;

	/// Medium qualifier 16 bit unsigned integer vector of 4 components type.
	/// @see gtc_type_precision
	using	mediump_u16vec4 = vec<4, u16, mediump>;


	/// High qualifier 16 bit unsigned integer scalar type.
	/// @see gtc_type_precision
	using		highp_u16vec1 = vec<1, u16, highp>;

	/// High qualifier 16 bit unsigned integer vector of 2 components type.
	/// @see gtc_type_precision
	using		highp_u16vec2 = vec<2, u16, highp>;

	/// High qualifier 16 bit unsigned integer vector of 3 components type.
	/// @see gtc_type_precision
	using		highp_u16vec3 = vec<3, u16, highp>;

	/// High qualifier 16 bit unsigned integer vector of 4 components type.
	/// @see gtc_type_precision
	using		highp_u16vec4 = vec<4, u16, highp>;


	/// Low qualifier 32 bit unsigned integer scalar type.
	/// @see gtc_type_precision
	using		lowp_u32vec1 = vec<1, u32, lowp>;

	/// Low qualifier 32 bit unsigned integer vector of 2 components type.
	/// @see gtc_type_precision
	using		lowp_u32vec2 = vec<2, u32, lowp>;

	/// Low qualifier 32 bit unsigned integer vector of 3 components type.
	/// @see gtc_type_precision
	using		lowp_u32vec3 = vec<3, u32, lowp>;

	/// Low qualifier 32 bit unsigned integer vector of 4 components type.
	/// @see gtc_type_precision
	using		lowp_u32vec4 = vec<4, u32, lowp>;


	/// Medium qualifier 32 bit unsigned integer scalar type.
	/// @see gtc_type_precision
	using	mediump_u32vec1 = vec<1, u32, mediump>;

	/// Medium qualifier 32 bit unsigned integer vector of 2 components type.
	/// @see gtc_type_precision
	using	mediump_u32vec2 = vec<2, u32, mediump>;

	/// Medium qualifier 32 bit unsigned integer vector of 3 components type.
	/// @see gtc_type_precision
	using	mediump_u32vec3 = vec<3, u32, mediump>;

	/// Medium qualifier 32 bit unsigned integer vector of 4 components type.
	/// @see gtc_type_precision
	using	mediump_u32vec4 = vec<4, u32, mediump>;


	/// High qualifier 32 bit unsigned integer scalar type.
	/// @see gtc_type_precision
	using		highp_u32vec1 = vec<1, u32, highp>;

	/// High qualifier 32 bit unsigned integer vector of 2 components type.
	/// @see gtc_type_precision
	using		highp_u32vec2 = vec<2, u32, highp>;

	/// High qualifier 32 bit unsigned integer vector of 3 components type.
	/// @see gtc_type_precision
	using		highp_u32vec3 = vec<3, u32, highp>;

	/// High qualifier 32 bit unsigned integer vector of 4 components type.
	/// @see gtc_type_precision
	using		highp_u32vec4 = vec<4, u32, highp>;


	/// Low qualifier 64 bit unsigned integer scalar type.
	/// @see gtc_type_precision
	using		lowp_u64vec1 = vec<1, u64, lowp>;

	/// Low qualifier 64 bit unsigned integer vector of 2 components type.
	/// @see gtc_type_precision
	using		lowp_u64vec2 = vec<2, u64, lowp>;

	/// Low qualifier 64 bit unsigned integer vector of 3 components type.
	/// @see gtc_type_precision
	using		lowp_u64vec3 = vec<3, u64, lowp>;

	/// Low qualifier 64 bit unsigned integer vector of 4 components type.
	/// @see gtc_type_precision
	using		lowp_u64vec4 = vec<4, u64, lowp>;


	/// Medium qualifier 64 bit unsigned integer scalar type.
	/// @see gtc_type_precision
	using	mediump_u64vec1 = vec<1, u64, mediump>;

	/// Medium qualifier 64 bit unsigned integer vector of 2 components type.
	/// @see gtc_type_precision
	using	mediump_u64vec2 = vec<2, u64, mediump>;

	/// Medium qualifier 64 bit unsigned integer vector of 3 components type.
	/// @see gtc_type_precision
	using	mediump_u64vec3 = vec<3, u64, mediump>;

	/// Medium qualifier 64 bit unsigned integer vector of 4 components type.
	/// @see gtc_type_precision
	using	mediump_u64vec4 = vec<4, u64, mediump>;


	/// High qualifier 64 bit unsigned integer scalar type.
	/// @see gtc_type_precision
	using		highp_u64vec1 = vec<1, u64, highp>;

	/// High qualifier 64 bit unsigned integer vector of 2 components type.
	/// @see gtc_type_precision
	using		highp_u64vec2 = vec<2, u64, highp>;

	/// High qualifier 64 bit unsigned integer vector of 3 components type.
	/// @see gtc_type_precision
	using		highp_u64vec3 = vec<3, u64, highp>;

	/// High qualifier 64 bit unsigned integer vector of 4 components type.
	/// @see gtc_type_precision
	using		highp_u64vec4 = vec<4, u64, highp>;


	//////////////////////
	// Float vector types

	/// 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using float32_t = float32;

	/// 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	using f32 = float32;

#	ifndef GLM_FORCE_SINGLE_ONLY

		/// 64 bit double-qualifier floating-point scalar.
		/// @see gtc_type_precision
		using float64_t = float64;

		/// 64 bit double-qualifier floating-point scalar.
		/// @see gtc_type_precision
		using f64 = float64;
#	endif//GLM_FORCE_SINGLE_ONLY

	/// Single-qualifier floating-point vector of 1 component.
	/// @see gtc_type_precision
	using fvec1 = vec<1, float, defaultp>;

	/// Single-qualifier floating-point vector of 2 components.
	/// @see gtc_type_precision
	using fvec2 = vec<2, float, defaultp>;

	/// Single-qualifier floating-point vector of 3 components.
	/// @see gtc_type_precision
	using fvec3 = vec<3, float, defaultp>;

	/// Single-qualifier floating-point vector of 4 components.
	/// @see gtc_type_precision
	using fvec4 = vec<4, float, defaultp>;


	/// Single-qualifier floating-point vector of 1 component.
	/// @see gtc_type_precision
	using f32vec1 = vec<1, f32, defaultp>;

	/// Single-qualifier floating-point vector of 2 components.
	/// @see gtc_type_precision
	using f32vec2 = vec<2, f32, defaultp>;

	/// Single-qualifier floating-point vector of 3 components.
	/// @see gtc_type_precision
	using f32vec3 = vec<3, f32, defaultp>;

	/// Single-qualifier floating-point vector of 4 components.
	/// @see gtc_type_precision
	using f32vec4 = vec<4, f32, defaultp>;

#	ifndef GLM_FORCE_SINGLE_ONLY
		/// Double-qualifier floating-point vector of 1 component.
		/// @see gtc_type_precision
		using f64vec1 = vec<1, f64, defaultp>;

		/// Double-qualifier floating-point vector of 2 components.
		/// @see gtc_type_precision
		using f64vec2 = vec<2, f64, defaultp>;

		/// Double-qualifier floating-point vector of 3 components.
		/// @see gtc_type_precision
		using f64vec3 = vec<3, f64, defaultp>;

		/// Double-qualifier floating-point vector of 4 components.
		/// @see gtc_type_precision
		using f64vec4 = vec<4, f64, defaultp>;
#	endif//GLM_FORCE_SINGLE_ONLY


	//////////////////////
	// Float matrix types

	/// Single-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef detail::tmat1x1<f32> fmat1;

	/// Single-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	using fmat2 = mat<2, 2, f32, defaultp>;

	/// Single-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	using fmat3 = mat<3, 3, f32, defaultp>;

	/// Single-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	using fmat4 = mat<4, 4, f32, defaultp>;


	/// Single-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef f32 fmat1x1;

	/// Single-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	using fmat2x2 = mat<2, 2, f32, defaultp>;

	/// Single-qualifier floating-point 2x3 matrix.
	/// @see gtc_type_precision
	using fmat2x3 = mat<2, 3, f32, defaultp>;

	/// Single-qualifier floating-point 2x4 matrix.
	/// @see gtc_type_precision
	using fmat2x4 = mat<2, 4, f32, defaultp>;

	/// Single-qualifier floating-point 3x2 matrix.
	/// @see gtc_type_precision
	using fmat3x2 = mat<3, 2, f32, defaultp>;

	/// Single-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	using fmat3x3 = mat<3, 3, f32, defaultp>;

	/// Single-qualifier floating-point 3x4 matrix.
	/// @see gtc_type_precision
	using fmat3x4 = mat<3, 4, f32, defaultp>;

	/// Single-qualifier floating-point 4x2 matrix.
	/// @see gtc_type_precision
	using fmat4x2 = mat<4, 2, f32, defaultp>;

	/// Single-qualifier floating-point 4x3 matrix.
	/// @see gtc_type_precision
	using fmat4x3 = mat<4, 3, f32, defaultp>;

	/// Single-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	using fmat4x4 = mat<4, 4, f32, defaultp>;


	/// Single-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef detail::tmat1x1<f32, defaultp> f32mat1;

	/// Single-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	using f32mat2 = mat<2, 2, f32, defaultp>;

	/// Single-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	using f32mat3 = mat<3, 3, f32, defaultp>;

	/// Single-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	using f32mat4 = mat<4, 4, f32, defaultp>;


	/// Single-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef f32 f32mat1x1;

	/// Single-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	using f32mat2x2 = mat<2, 2, f32, defaultp>;

	/// Single-qualifier floating-point 2x3 matrix.
	/// @see gtc_type_precision
	using f32mat2x3 = mat<2, 3, f32, defaultp>;

	/// Single-qualifier floating-point 2x4 matrix.
	/// @see gtc_type_precision
	using f32mat2x4 = mat<2, 4, f32, defaultp>;

	/// Single-qualifier floating-point 3x2 matrix.
	/// @see gtc_type_precision
	using f32mat3x2 = mat<3, 2, f32, defaultp>;

	/// Single-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	using f32mat3x3 = mat<3, 3, f32, defaultp>;

	/// Single-qualifier floating-point 3x4 matrix.
	/// @see gtc_type_precision
	using f32mat3x4 = mat<3, 4, f32, defaultp>;

	/// Single-qualifier floating-point 4x2 matrix.
	/// @see gtc_type_precision
	using f32mat4x2 = mat<4, 2, f32, defaultp>;

	/// Single-qualifier floating-point 4x3 matrix.
	/// @see gtc_type_precision
	using f32mat4x3 = mat<4, 3, f32, defaultp>;

	/// Single-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	using f32mat4x4 = mat<4, 4, f32, defaultp>;


#	ifndef GLM_FORCE_SINGLE_ONLY

	/// Double-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef detail::tmat1x1<f64, defaultp> f64mat1;

	/// Double-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	using f64mat2 = mat<2, 2, f64, defaultp>;

	/// Double-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	using f64mat3 = mat<3, 3, f64, defaultp>;

	/// Double-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	using f64mat4 = mat<4, 4, f64, defaultp>;


	/// Double-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef f64 f64mat1x1;

	/// Double-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	using f64mat2x2 = mat<2, 2, f64, defaultp>;

	/// Double-qualifier floating-point 2x3 matrix.
	/// @see gtc_type_precision
	using f64mat2x3 = mat<2, 3, f64, defaultp>;

	/// Double-qualifier floating-point 2x4 matrix.
	/// @see gtc_type_precision
	using f64mat2x4 = mat<2, 4, f64, defaultp>;

	/// Double-qualifier floating-point 3x2 matrix.
	/// @see gtc_type_precision
	using f64mat3x2 = mat<3, 2, f64, defaultp>;

	/// Double-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	using f64mat3x3 = mat<3, 3, f64, defaultp>;

	/// Double-qualifier floating-point 3x4 matrix.
	/// @see gtc_type_precision
	using f64mat3x4 = mat<3, 4, f64, defaultp>;

	/// Double-qualifier floating-point 4x2 matrix.
	/// @see gtc_type_precision
	using f64mat4x2 = mat<4, 2, f64, defaultp>;

	/// Double-qualifier floating-point 4x3 matrix.
	/// @see gtc_type_precision
	using f64mat4x3 = mat<4, 3, f64, defaultp>;

	/// Double-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	using f64mat4x4 = mat<4, 4, f64, defaultp>;

#	endif//GLM_FORCE_SINGLE_ONLY

	//////////////////////////
	// Quaternion types

	/// Single-qualifier floating-point quaternion.
	/// @see gtc_type_precision
	using f32quat = qua<f32, defaultp>;

	/// Low single-qualifier floating-point quaternion.
	/// @see gtc_type_precision
	using lowp_f32quat = qua<f32, lowp>;

	/// Low double-qualifier floating-point quaternion.
	/// @see gtc_type_precision
	using lowp_f64quat = qua<f64, lowp>;

	/// Medium single-qualifier floating-point quaternion.
	/// @see gtc_type_precision
	using mediump_f32quat = qua<f32, mediump>;

#	ifndef GLM_FORCE_SINGLE_ONLY

	/// Medium double-qualifier floating-point quaternion.
	/// @see gtc_type_precision
	using mediump_f64quat = qua<f64, mediump>;

	/// High single-qualifier floating-point quaternion.
	/// @see gtc_type_precision
	using highp_f32quat = qua<f32, highp>;

	/// High double-qualifier floating-point quaternion.
	/// @see gtc_type_precision
	using highp_f64quat = qua<f64, highp>;

	/// Double-qualifier floating-point quaternion.
	/// @see gtc_type_precision
	using f64quat = qua<f64, defaultp>;

#	endif//GLM_FORCE_SINGLE_ONLY

	/// @}
}//namespace glm

#include "type_precision.inl"
