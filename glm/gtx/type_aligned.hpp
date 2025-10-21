/// @ref gtx_type_aligned
/// @file glm/gtx/type_aligned.hpp
///
/// @see core (dependence)
/// @see gtc_quaternion (dependence)
///
/// @defgroup gtx_type_aligned GLM_GTX_type_aligned
/// @ingroup gtx
///
/// Include <glm/gtx/type_aligned.hpp> to use the features of this extension.
///
/// Defines aligned types.

#pragma once

// Dependency:
#include "../gtc/type_precision.hpp"
#include "../gtc/quaternion.hpp"
#include "../gtc/type_aligned.hpp"

#ifndef GLM_ENABLE_EXPERIMENTAL
#	pragma message("GLM: GLM_GTX_type_aligned is an experimental extension and may change in the future. Use #define GLM_ENABLE_EXPERIMENTAL before including it, if you really want to use it.")
#elif GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_GTX_type_aligned extension included")
#endif

namespace glm
{
	///////////////////////////
	// Signed int vector types

	/// @addtogroup gtx_type_aligned
	/// @{

	/// Default qualifier 8 bit signed integer aligned scalar type.
	/// @see gtx_type_aligned
	typedef vec<1, int8, aligned_highp>		aligned_i8vec1;

	/// Default qualifier 8 bit signed integer aligned vector of 2 components type.
	/// @see gtx_type_aligned
	typedef vec<2, int8, aligned_highp>		aligned_i8vec2;

	/// Default qualifier 8 bit signed integer aligned vector of 3 components type.
	/// @see gtx_type_aligned
	typedef vec<3, int8, aligned_highp>		aligned_i8vec3;

	/// Default qualifier 8 bit signed integer aligned vector of 4 components type.
	/// @see gtx_type_aligned
	typedef vec<4, int8, aligned_highp>		aligned_i8vec4;


	/// Default qualifier 16 bit signed integer aligned scalar type.
	/// @see gtx_type_aligned
	typedef vec<1, int16, aligned_highp>	aligned_i16vec1;

	/// Default qualifier 16 bit signed integer aligned vector of 2 components type.
	/// @see gtx_type_aligned
	typedef vec<2, int16, aligned_highp>	aligned_i16vec2;

	/// Default qualifier 16 bit signed integer aligned vector of 3 components type.
	/// @see gtx_type_aligned
	typedef vec<3, int16, aligned_highp>	aligned_i16vec3;

	/// Default qualifier 16 bit signed integer aligned vector of 4 components type.
	/// @see gtx_type_aligned
	typedef vec<4, int16, aligned_highp>	aligned_i16vec4;


	/// Default qualifier 32 bit signed integer aligned scalar type.
	/// @see gtx_type_aligned
	typedef vec<1, int32, aligned_highp>	aligned_i32vec1;

	/// Default qualifier 32 bit signed integer aligned vector of 2 components type.
	/// @see gtx_type_aligned
	typedef vec<2, int32, aligned_highp>	aligned_i32vec2;

	/// Default qualifier 32 bit signed integer aligned vector of 3 components type.
	/// @see gtx_type_aligned
	typedef vec<3, int32, aligned_highp>	aligned_i32vec3;

	/// Default qualifier 32 bit signed integer aligned vector of 4 components type.
	/// @see gtx_type_aligned
	typedef vec<4, int32, aligned_highp>	aligned_i32vec4;


	/// Default qualifier 64 bit signed integer aligned scalar type.
	/// @see gtx_type_aligned
	typedef vec<1, int64, aligned_highp>	aligned_i64vec1;

	/// Default qualifier 64 bit signed integer aligned vector of 2 components type.
	/// @see gtx_type_aligned
	typedef vec<2, int64, aligned_highp>	aligned_i64vec2;

	/// Default qualifier 64 bit signed integer aligned vector of 3 components type.
	/// @see gtx_type_aligned
	typedef vec<3, int64, aligned_highp>	aligned_i64vec3;

	/// Default qualifier 64 bit signed integer aligned vector of 4 components type.
	/// @see gtx_type_aligned
	typedef vec<4, int64, aligned_highp>	aligned_i64vec4;


	/////////////////////////////
	// Unsigned int vector types

	/// Default qualifier 8 bit unsigned integer aligned scalar type.
	/// @see gtx_type_aligned
	typedef vec<1, uint8, aligned_highp>	aligned_u8vec1;

	/// Default qualifier 8 bit unsigned integer aligned vector of 2 components type.
	/// @see gtx_type_aligned
	typedef vec<2, uint8, aligned_highp>	aligned_u8vec2;

	/// Default qualifier 8 bit unsigned integer aligned vector of 3 components type.
	/// @see gtx_type_aligned
	typedef vec<3, uint8, aligned_highp>	aligned_u8vec3;

	/// Default qualifier 8 bit unsigned integer aligned vector of 4 components type.
	/// @see gtx_type_aligned
	typedef vec<4, uint8, aligned_highp>	aligned_u8vec4;


	/// Default qualifier 16 bit unsigned integer aligned scalar type.
	/// @see gtx_type_aligned
	typedef vec<1, uint16, aligned_highp>	aligned_u16vec1;

	/// Default qualifier 16 bit unsigned integer aligned vector of 2 components type.
	/// @see gtx_type_aligned
	typedef vec<2, uint16, aligned_highp>	aligned_u16vec2;

	/// Default qualifier 16 bit unsigned integer aligned vector of 3 components type.
	/// @see gtx_type_aligned
	typedef vec<3, uint16, aligned_highp>	aligned_u16vec3;

	/// Default qualifier 16 bit unsigned integer aligned vector of 4 components type.
	/// @see gtx_type_aligned
	typedef vec<4, uint16, aligned_highp>	aligned_u16vec4;


	/// Default qualifier 32 bit unsigned integer aligned scalar type.
	/// @see gtx_type_aligned
	typedef vec<1, uint32, aligned_highp>	aligned_u32vec1;

	/// Default qualifier 32 bit unsigned integer aligned vector of 2 components type.
	/// @see gtx_type_aligned
	typedef vec<2, uint32, aligned_highp>	aligned_u32vec2;

	/// Default qualifier 32 bit unsigned integer aligned vector of 3 components type.
	/// @see gtx_type_aligned
	typedef vec<3, uint32, aligned_highp>	aligned_u32vec3;

	/// Default qualifier 32 bit unsigned integer aligned vector of 4 components type.
	/// @see gtx_type_aligned
	typedef vec<4, uint32, aligned_highp>	aligned_u32vec4;


	/// Default qualifier 64 bit unsigned integer aligned scalar type.
	/// @see gtx_type_aligned
	typedef vec<1, uint64, aligned_highp>	aligned_u64vec1;

	/// Default qualifier 64 bit unsigned integer aligned vector of 2 components type.
	/// @see gtx_type_aligned
	typedef vec<2, uint64, aligned_highp>	aligned_u64vec2;

	/// Default qualifier 64 bit unsigned integer aligned vector of 3 components type.
	/// @see gtx_type_aligned
	typedef vec<3, uint64, aligned_highp>	aligned_u64vec3;

	/// Default qualifier 64 bit unsigned integer aligned vector of 4 components type.
	/// @see gtx_type_aligned
	typedef vec<4, uint64, aligned_highp>	aligned_u64vec4;


	//////////////////////
	// Float vector types

	/// Single-qualifier floating-point aligned vector of 1 component.
	/// @see gtx_type_aligned
	typedef vec<1, float, aligned_highp>	aligned_fvec1;

	/// Single-qualifier floating-point aligned vector of 2 components.
	/// @see gtx_type_aligned
	typedef vec<2, float, aligned_highp>	aligned_fvec2;

	/// Single-qualifier floating-point aligned vector of 3 components.
	/// @see gtx_type_aligned
	typedef vec<3, float, aligned_highp>	aligned_fvec3;

	/// Single-qualifier floating-point aligned vector of 4 components.
	/// @see gtx_type_aligned
	typedef vec<4, float, aligned_highp>	aligned_fvec4;


	/// Single-qualifier floating-point aligned vector of 1 component.
	/// @see gtx_type_aligned
	typedef vec<1, float, aligned_highp>	aligned_f32vec1;

	/// Single-qualifier floating-point aligned vector of 2 components.
	/// @see gtx_type_aligned
	typedef vec<2, float, aligned_highp>	aligned_f32vec2;

	/// Single-qualifier floating-point aligned vector of 3 components.
	/// @see gtx_type_aligned
	typedef vec<3, float, aligned_highp>	aligned_f32vec3;

	/// Single-qualifier floating-point aligned vector of 4 components.
	/// @see gtx_type_aligned
	typedef vec<4, float, aligned_highp>	aligned_f32vec4;


	/// Double-qualifier floating-point aligned vector of 1 component.
	/// @see gtx_type_aligned
	typedef vec<1, double, aligned_highp>	aligned_f64vec1;

	/// Double-qualifier floating-point aligned vector of 2 components.
	/// @see gtx_type_aligned
	typedef vec<2, double, aligned_highp>	aligned_f64vec2;

	/// Double-qualifier floating-point aligned vector of 3 components.
	/// @see gtx_type_aligned
	typedef vec<3, double, aligned_highp>	aligned_f64vec3;

	/// Double-qualifier floating-point aligned vector of 4 components.
	/// @see gtx_type_aligned
	typedef vec<4, double, aligned_highp>	aligned_f64vec4;

	//////////////////////
	// Float matrix types
/*
	/// Single-qualifier floating-point aligned 2x2 matrix.
	/// @see gtx_type_aligned
	GLM_ALIGNED_TYPEDEF(fmat2x2, aligned_fmat2, 16);

	/// Single-qualifier floating-point aligned 3x3 matrix.
	/// @see gtx_type_aligned
	GLM_ALIGNED_TYPEDEF(fmat3x3, aligned_fmat3, 16);

	/// Single-qualifier floating-point aligned 4x4 matrix.
	/// @see gtx_type_aligned
	GLM_ALIGNED_TYPEDEF(fmat4x4, aligned_fmat4, 16);


	/// Single-qualifier floating-point aligned 2x2 matrix.
	/// @see gtx_type_aligned
	GLM_ALIGNED_TYPEDEF(fmat2x2, aligned_fmat2x2, 16);

	/// Single-qualifier floating-point aligned 2x3 matrix.
	/// @see gtx_type_aligned
	GLM_ALIGNED_TYPEDEF(fmat2x3, aligned_fmat2x3, 16);

	/// Single-qualifier floating-point aligned 2x4 matrix.
	/// @see gtx_type_aligned
	GLM_ALIGNED_TYPEDEF(fmat2x4, aligned_fmat2x4, 16);

	/// Single-qualifier floating-point aligned 3x2 matrix.
	/// @see gtx_type_aligned
	GLM_ALIGNED_TYPEDEF(fmat3x2, aligned_fmat3x2, 16);

	/// Single-qualifier floating-point aligned 3x3 matrix.
	/// @see gtx_type_aligned
	GLM_ALIGNED_TYPEDEF(fmat3x3, aligned_fmat3x3, 16);

	/// Single-qualifier floating-point aligned 3x4 matrix.
	/// @see gtx_type_aligned
	GLM_ALIGNED_TYPEDEF(fmat3x4, aligned_fmat3x4, 16);

	/// Single-qualifier floating-point aligned 4x2 matrix.
	/// @see gtx_type_aligned
	GLM_ALIGNED_TYPEDEF(fmat4x2, aligned_fmat4x2, 16);

	/// Single-qualifier floating-point aligned 4x3 matrix.
	/// @see gtx_type_aligned
	GLM_ALIGNED_TYPEDEF(fmat4x3, aligned_fmat4x3, 16);

	/// Single-qualifier floating-point aligned 4x4 matrix.
	/// @see gtx_type_aligned
	GLM_ALIGNED_TYPEDEF(fmat4x4, aligned_fmat4x4, 16);


	/// Single-qualifier floating-point aligned 1x1 matrix.
	/// @see gtx_type_aligned
	//typedef detail::tmat1x1<f32, defaultp> f32mat1;

	/// Single-qualifier floating-point aligned 2x2 matrix.
	/// @see gtx_type_aligned
	GLM_ALIGNED_TYPEDEF(f32mat2x2, aligned_f32mat2, 16);

	/// Single-qualifier floating-point aligned 3x3 matrix.
	/// @see gtx_type_aligned
	GLM_ALIGNED_TYPEDEF(f32mat3x3, aligned_f32mat3, 16);

	/// Single-qualifier floating-point aligned 4x4 matrix.
	/// @see gtx_type_aligned
	GLM_ALIGNED_TYPEDEF(f32mat4x4, aligned_f32mat4, 16);


	/// Single-qualifier floating-point aligned 1x1 matrix.
	/// @see gtx_type_aligned
	//typedef f32 f32mat1x1;

	/// Single-qualifier floating-point aligned 2x2 matrix.
	/// @see gtx_type_aligned
	GLM_ALIGNED_TYPEDEF(f32mat2x2, aligned_f32mat2x2, 16);

	/// Single-qualifier floating-point aligned 2x3 matrix.
	/// @see gtx_type_aligned
	GLM_ALIGNED_TYPEDEF(f32mat2x3, aligned_f32mat2x3, 16);

	/// Single-qualifier floating-point aligned 2x4 matrix.
	/// @see gtx_type_aligned
	GLM_ALIGNED_TYPEDEF(f32mat2x4, aligned_f32mat2x4, 16);

	/// Single-qualifier floating-point aligned 3x2 matrix.
	/// @see gtx_type_aligned
	GLM_ALIGNED_TYPEDEF(f32mat3x2, aligned_f32mat3x2, 16);

	/// Single-qualifier floating-point aligned 3x3 matrix.
	/// @see gtx_type_aligned
	GLM_ALIGNED_TYPEDEF(f32mat3x3, aligned_f32mat3x3, 16);

	/// Single-qualifier floating-point aligned 3x4 matrix.
	/// @see gtx_type_aligned
	GLM_ALIGNED_TYPEDEF(f32mat3x4, aligned_f32mat3x4, 16);

	/// Single-qualifier floating-point aligned 4x2 matrix.
	/// @see gtx_type_aligned
	GLM_ALIGNED_TYPEDEF(f32mat4x2, aligned_f32mat4x2, 16);

	/// Single-qualifier floating-point aligned 4x3 matrix.
	/// @see gtx_type_aligned
	GLM_ALIGNED_TYPEDEF(f32mat4x3, aligned_f32mat4x3, 16);

	/// Single-qualifier floating-point aligned 4x4 matrix.
	/// @see gtx_type_aligned
	GLM_ALIGNED_TYPEDEF(f32mat4x4, aligned_f32mat4x4, 16);


#	ifndef GLM_FORCE_SINGLE_ONLY

	/// Double-qualifier floating-point aligned 1x1 matrix.
	/// @see gtx_type_aligned
	//typedef detail::tmat1x1<f64, defaultp> f64mat1;

	/// Double-qualifier floating-point aligned 2x2 matrix.
	/// @see gtx_type_aligned
	GLM_ALIGNED_TYPEDEF(f64mat2x2, aligned_f64mat2, 32);

	/// Double-qualifier floating-point aligned 3x3 matrix.
	/// @see gtx_type_aligned
	GLM_ALIGNED_TYPEDEF(f64mat3x3, aligned_f64mat3, 32);

	/// Double-qualifier floating-point aligned 4x4 matrix.
	/// @see gtx_type_aligned
	GLM_ALIGNED_TYPEDEF(f64mat4x4, aligned_f64mat4, 32);


	/// Double-qualifier floating-point aligned 1x1 matrix.
	/// @see gtx_type_aligned
	//typedef f64 f64mat1x1;

	/// Double-qualifier floating-point aligned 2x2 matrix.
	/// @see gtx_type_aligned
	GLM_ALIGNED_TYPEDEF(f64mat2x2, aligned_f64mat2x2, 32);

	/// Double-qualifier floating-point aligned 2x3 matrix.
	/// @see gtx_type_aligned
	GLM_ALIGNED_TYPEDEF(f64mat2x3, aligned_f64mat2x3, 32);

	/// Double-qualifier floating-point aligned 2x4 matrix.
	/// @see gtx_type_aligned
	GLM_ALIGNED_TYPEDEF(f64mat2x4, aligned_f64mat2x4, 32);

	/// Double-qualifier floating-point aligned 3x2 matrix.
	/// @see gtx_type_aligned
	GLM_ALIGNED_TYPEDEF(f64mat3x2, aligned_f64mat3x2, 32);

	/// Double-qualifier floating-point aligned 3x3 matrix.
	/// @see gtx_type_aligned
	GLM_ALIGNED_TYPEDEF(f64mat3x3, aligned_f64mat3x3, 32);

	/// Double-qualifier floating-point aligned 3x4 matrix.
	/// @see gtx_type_aligned
	GLM_ALIGNED_TYPEDEF(f64mat3x4, aligned_f64mat3x4, 32);

	/// Double-qualifier floating-point aligned 4x2 matrix.
	/// @see gtx_type_aligned
	GLM_ALIGNED_TYPEDEF(f64mat4x2, aligned_f64mat4x2, 32);

	/// Double-qualifier floating-point aligned 4x3 matrix.
	/// @see gtx_type_aligned
	GLM_ALIGNED_TYPEDEF(f64mat4x3, aligned_f64mat4x3, 32);

	/// Double-qualifier floating-point aligned 4x4 matrix.
	/// @see gtx_type_aligned
	GLM_ALIGNED_TYPEDEF(f64mat4x4, aligned_f64mat4x4, 32);

#	endif//GLM_FORCE_SINGLE_ONLY


	//////////////////////////
	// Quaternion types

	/// Single-qualifier floating-point aligned quaternion.
	/// @see gtx_type_aligned
	GLM_ALIGNED_TYPEDEF(quat, aligned_quat, 16);

	/// Single-qualifier floating-point aligned quaternion.
	/// @see gtx_type_aligned
	GLM_ALIGNED_TYPEDEF(quat, aligned_fquat, 16);

	/// Double-qualifier floating-point aligned quaternion.
	/// @see gtx_type_aligned
	GLM_ALIGNED_TYPEDEF(dquat, aligned_dquat, 32);

	/// Single-qualifier floating-point aligned quaternion.
	/// @see gtx_type_aligned
	GLM_ALIGNED_TYPEDEF(f32quat, aligned_f32quat, 16);

#	ifndef GLM_FORCE_SINGLE_ONLY

	/// Double-qualifier floating-point aligned quaternion.
	/// @see gtx_type_aligned
	GLM_ALIGNED_TYPEDEF(f64quat, aligned_f64quat, 32);

#	endif//GLM_FORCE_SINGLE_ONLY
*/
	/// @}
}//namespace glm

#include "type_aligned.inl"
