#pragma once

#include "detail/qualifier.hpp"

namespace glm
{
	using				int8 = std::int8_t;
	using			int16 = std::int16_t;
	using			int32 = std::int32_t;
	using			int64 = std::int64_t;

	using			uint8 = std::uint8_t;
	using			uint16 = std::uint16_t;
	using			uint32 = std::uint32_t;
	using			uint64 = std::uint64_t;

	// Scalar int

	using					lowp_i8 = int8;
	using					mediump_i8 = int8;
	using					highp_i8 = int8;
	using					i8 = int8;

	using					lowp_int8 = int8;
	using					mediump_int8 = int8;
	using					highp_int8 = int8;

	using					lowp_int8_t = int8;
	using					mediump_int8_t = int8;
	using					highp_int8_t = int8;
	using					int8_t = int8;

	using					lowp_i16 = int16;
	using					mediump_i16 = int16;
	using					highp_i16 = int16;
	using					i16 = int16;

	using					lowp_int16 = int16;
	using					mediump_int16 = int16;
	using					highp_int16 = int16;

	using					lowp_int16_t = int16;
	using					mediump_int16_t = int16;
	using					highp_int16_t = int16;
	using					int16_t = int16;

	using					lowp_i32 = int32;
	using					mediump_i32 = int32;
	using					highp_i32 = int32;
	using					i32 = int32;

	using					lowp_int32 = int32;
	using					mediump_int32 = int32;
	using					highp_int32 = int32;

	using					lowp_int32_t = int32;
	using					mediump_int32_t = int32;
	using					highp_int32_t = int32;
	using					int32_t = int32;

	using					lowp_i64 = int64;
	using					mediump_i64 = int64;
	using					highp_i64 = int64;
	using					i64 = int64;

	using					lowp_int64 = int64;
	using					mediump_int64 = int64;
	using					highp_int64 = int64;

	using					lowp_int64_t = int64;
	using					mediump_int64_t = int64;
	using					highp_int64_t = int64;
	using					int64_t = int64;

	// Scalar uint

	using			uint = unsigned int;

	using					lowp_u8 = uint8;
	using					mediump_u8 = uint8;
	using					highp_u8 = uint8;
	using					u8 = uint8;

	using					lowp_uint8 = uint8;
	using					mediump_uint8 = uint8;
	using					highp_uint8 = uint8;

	using					lowp_uint8_t = uint8;
	using					mediump_uint8_t = uint8;
	using					highp_uint8_t = uint8;
	using					uint8_t = uint8;

	using					lowp_u16 = uint16;
	using					mediump_u16 = uint16;
	using					highp_u16 = uint16;
	using					u16 = uint16;

	using					lowp_uint16 = uint16;
	using					mediump_uint16 = uint16;
	using					highp_uint16 = uint16;

	using					lowp_uint16_t = uint16;
	using					mediump_uint16_t = uint16;
	using					highp_uint16_t = uint16;
	using					uint16_t = uint16;

	using					lowp_u32 = uint32;
	using					mediump_u32 = uint32;
	using					highp_u32 = uint32;
	using					u32 = uint32;

	using					lowp_uint32 = uint32;
	using					mediump_uint32 = uint32;
	using					highp_uint32 = uint32;

	using					lowp_uint32_t = uint32;
	using					mediump_uint32_t = uint32;
	using					highp_uint32_t = uint32;
	using					uint32_t = uint32;

	using					lowp_u64 = uint64;
	using					mediump_u64 = uint64;
	using					highp_u64 = uint64;
	using					u64 = uint64;

	using					lowp_uint64 = uint64;
	using					mediump_uint64 = uint64;
	using					highp_uint64 = uint64;

	using					lowp_uint64_t = uint64;
	using					mediump_uint64_t = uint64;
	using					highp_uint64_t = uint64;
	using					uint64_t = uint64;

	// Scalar float

	using					lowp_f32 = float;
	using					mediump_f32 = float;
	using					highp_f32 = float;
	using					f32 = float;

	using					lowp_float32 = float;
	using					mediump_float32 = float;
	using					highp_float32 = float;
	using					float32 = float;

	using					lowp_float32_t = float;
	using					mediump_float32_t = float;
	using					highp_float32_t = float;
	using					float32_t = float;


	using					lowp_f64 = double;
	using					mediump_f64 = double;
	using					highp_f64 = double;
	using					f64 = double;

	using					lowp_float64 = double;
	using					mediump_float64 = double;
	using					highp_float64 = double;
	using					float64 = double;

	using					lowp_float64_t = double;
	using					mediump_float64_t = double;
	using					highp_float64_t = double;
	using					float64_t = double;

	// Vector bool

	using		lowp_bvec1 = vec<1, bool, lowp>;
	using		lowp_bvec2 = vec<2, bool, lowp>;
	using		lowp_bvec3 = vec<3, bool, lowp>;
	using		lowp_bvec4 = vec<4, bool, lowp>;

	using	mediump_bvec1 = vec<1, bool, mediump>;
	using	mediump_bvec2 = vec<2, bool, mediump>;
	using	mediump_bvec3 = vec<3, bool, mediump>;
	using	mediump_bvec4 = vec<4, bool, mediump>;

	using		highp_bvec1 = vec<1, bool, highp>;
	using		highp_bvec2 = vec<2, bool, highp>;
	using		highp_bvec3 = vec<3, bool, highp>;
	using		highp_bvec4 = vec<4, bool, highp>;

	using	bvec1 = vec<1, bool, defaultp>;
	using	bvec2 = vec<2, bool, defaultp>;
	using	bvec3 = vec<3, bool, defaultp>;
	using	bvec4 = vec<4, bool, defaultp>;

	// Vector int

	using		lowp_ivec1 = vec<1, int, lowp>;
	using		lowp_ivec2 = vec<2, int, lowp>;
	using		lowp_ivec3 = vec<3, int, lowp>;
	using		lowp_ivec4 = vec<4, int, lowp>;

	using	mediump_ivec1 = vec<1, int, mediump>;
	using	mediump_ivec2 = vec<2, int, mediump>;
	using	mediump_ivec3 = vec<3, int, mediump>;
	using	mediump_ivec4 = vec<4, int, mediump>;

	using		highp_ivec1 = vec<1, int, highp>;
	using		highp_ivec2 = vec<2, int, highp>;
	using		highp_ivec3 = vec<3, int, highp>;
	using		highp_ivec4 = vec<4, int, highp>;

	using	ivec1 = vec<1, int, defaultp>;
	using	ivec2 = vec<2, int, defaultp>;
	using	ivec3 = vec<3, int, defaultp>;
	using	ivec4 = vec<4, int, defaultp>;

	using		lowp_i8vec1 = vec<1, i8, lowp>;
	using		lowp_i8vec2 = vec<2, i8, lowp>;
	using		lowp_i8vec3 = vec<3, i8, lowp>;
	using		lowp_i8vec4 = vec<4, i8, lowp>;

	using		mediump_i8vec1 = vec<1, i8, mediump>;
	using		mediump_i8vec2 = vec<2, i8, mediump>;
	using		mediump_i8vec3 = vec<3, i8, mediump>;
	using		mediump_i8vec4 = vec<4, i8, mediump>;

	using		highp_i8vec1 = vec<1, i8, highp>;
	using		highp_i8vec2 = vec<2, i8, highp>;
	using		highp_i8vec3 = vec<3, i8, highp>;
	using		highp_i8vec4 = vec<4, i8, highp>;

	using	i8vec1 = vec<1, i8, defaultp>;
	using	i8vec2 = vec<2, i8, defaultp>;
	using	i8vec3 = vec<3, i8, defaultp>;
	using	i8vec4 = vec<4, i8, defaultp>;

	using		lowp_i16vec1 = vec<1, i16, lowp>;
	using		lowp_i16vec2 = vec<2, i16, lowp>;
	using		lowp_i16vec3 = vec<3, i16, lowp>;
	using		lowp_i16vec4 = vec<4, i16, lowp>;

	using	mediump_i16vec1 = vec<1, i16, mediump>;
	using	mediump_i16vec2 = vec<2, i16, mediump>;
	using	mediump_i16vec3 = vec<3, i16, mediump>;
	using	mediump_i16vec4 = vec<4, i16, mediump>;

	using		highp_i16vec1 = vec<1, i16, highp>;
	using		highp_i16vec2 = vec<2, i16, highp>;
	using		highp_i16vec3 = vec<3, i16, highp>;
	using		highp_i16vec4 = vec<4, i16, highp>;

	using	i16vec1 = vec<1, i16, defaultp>;
	using	i16vec2 = vec<2, i16, defaultp>;
	using	i16vec3 = vec<3, i16, defaultp>;
	using	i16vec4 = vec<4, i16, defaultp>;

	using		lowp_i32vec1 = vec<1, i32, lowp>;
	using		lowp_i32vec2 = vec<2, i32, lowp>;
	using		lowp_i32vec3 = vec<3, i32, lowp>;
	using		lowp_i32vec4 = vec<4, i32, lowp>;

	using	mediump_i32vec1 = vec<1, i32, mediump>;
	using	mediump_i32vec2 = vec<2, i32, mediump>;
	using	mediump_i32vec3 = vec<3, i32, mediump>;
	using	mediump_i32vec4 = vec<4, i32, mediump>;

	using		highp_i32vec1 = vec<1, i32, highp>;
	using		highp_i32vec2 = vec<2, i32, highp>;
	using		highp_i32vec3 = vec<3, i32, highp>;
	using		highp_i32vec4 = vec<4, i32, highp>;

	using	i32vec1 = vec<1, i32, defaultp>;
	using	i32vec2 = vec<2, i32, defaultp>;
	using	i32vec3 = vec<3, i32, defaultp>;
	using	i32vec4 = vec<4, i32, defaultp>;

	using		lowp_i64vec1 = vec<1, i64, lowp>;
	using		lowp_i64vec2 = vec<2, i64, lowp>;
	using		lowp_i64vec3 = vec<3, i64, lowp>;
	using		lowp_i64vec4 = vec<4, i64, lowp>;

	using	mediump_i64vec1 = vec<1, i64, mediump>;
	using	mediump_i64vec2 = vec<2, i64, mediump>;
	using	mediump_i64vec3 = vec<3, i64, mediump>;
	using	mediump_i64vec4 = vec<4, i64, mediump>;

	using		highp_i64vec1 = vec<1, i64, highp>;
	using		highp_i64vec2 = vec<2, i64, highp>;
	using		highp_i64vec3 = vec<3, i64, highp>;
	using		highp_i64vec4 = vec<4, i64, highp>;

	using	i64vec1 = vec<1, i64, defaultp>;
	using	i64vec2 = vec<2, i64, defaultp>;
	using	i64vec3 = vec<3, i64, defaultp>;
	using	i64vec4 = vec<4, i64, defaultp>;

	// Vector uint

	using		lowp_uvec1 = vec<1, uint, lowp>;
	using		lowp_uvec2 = vec<2, uint, lowp>;
	using		lowp_uvec3 = vec<3, uint, lowp>;
	using		lowp_uvec4 = vec<4, uint, lowp>;

	using	mediump_uvec1 = vec<1, uint, mediump>;
	using	mediump_uvec2 = vec<2, uint, mediump>;
	using	mediump_uvec3 = vec<3, uint, mediump>;
	using	mediump_uvec4 = vec<4, uint, mediump>;

	using		highp_uvec1 = vec<1, uint, highp>;
	using		highp_uvec2 = vec<2, uint, highp>;
	using		highp_uvec3 = vec<3, uint, highp>;
	using		highp_uvec4 = vec<4, uint, highp>;

	using	uvec1 = vec<1, uint, defaultp>;
	using	uvec2 = vec<2, uint, defaultp>;
	using	uvec3 = vec<3, uint, defaultp>;
	using	uvec4 = vec<4, uint, defaultp>;

	using		lowp_u8vec1 = vec<1, u8, lowp>;
	using		lowp_u8vec2 = vec<2, u8, lowp>;
	using		lowp_u8vec3 = vec<3, u8, lowp>;
	using		lowp_u8vec4 = vec<4, u8, lowp>;

	using		mediump_u8vec1 = vec<1, u8, mediump>;
	using		mediump_u8vec2 = vec<2, u8, mediump>;
	using		mediump_u8vec3 = vec<3, u8, mediump>;
	using		mediump_u8vec4 = vec<4, u8, mediump>;

	using		highp_u8vec1 = vec<1, u8, highp>;
	using		highp_u8vec2 = vec<2, u8, highp>;
	using		highp_u8vec3 = vec<3, u8, highp>;
	using		highp_u8vec4 = vec<4, u8, highp>;

	using	u8vec1 = vec<1, u8, defaultp>;
	using	u8vec2 = vec<2, u8, defaultp>;
	using	u8vec3 = vec<3, u8, defaultp>;
	using	u8vec4 = vec<4, u8, defaultp>;

	using		lowp_u16vec1 = vec<1, u16, lowp>;
	using		lowp_u16vec2 = vec<2, u16, lowp>;
	using		lowp_u16vec3 = vec<3, u16, lowp>;
	using		lowp_u16vec4 = vec<4, u16, lowp>;

	using	mediump_u16vec1 = vec<1, u16, mediump>;
	using	mediump_u16vec2 = vec<2, u16, mediump>;
	using	mediump_u16vec3 = vec<3, u16, mediump>;
	using	mediump_u16vec4 = vec<4, u16, mediump>;

	using		highp_u16vec1 = vec<1, u16, highp>;
	using		highp_u16vec2 = vec<2, u16, highp>;
	using		highp_u16vec3 = vec<3, u16, highp>;
	using		highp_u16vec4 = vec<4, u16, highp>;

	using	u16vec1 = vec<1, u16, defaultp>;
	using	u16vec2 = vec<2, u16, defaultp>;
	using	u16vec3 = vec<3, u16, defaultp>;
	using	u16vec4 = vec<4, u16, defaultp>;

	using		lowp_u32vec1 = vec<1, u32, lowp>;
	using		lowp_u32vec2 = vec<2, u32, lowp>;
	using		lowp_u32vec3 = vec<3, u32, lowp>;
	using		lowp_u32vec4 = vec<4, u32, lowp>;

	using	mediump_u32vec1 = vec<1, u32, mediump>;
	using	mediump_u32vec2 = vec<2, u32, mediump>;
	using	mediump_u32vec3 = vec<3, u32, mediump>;
	using	mediump_u32vec4 = vec<4, u32, mediump>;

	using		highp_u32vec1 = vec<1, u32, highp>;
	using		highp_u32vec2 = vec<2, u32, highp>;
	using		highp_u32vec3 = vec<3, u32, highp>;
	using		highp_u32vec4 = vec<4, u32, highp>;

	using	u32vec1 = vec<1, u32, defaultp>;
	using	u32vec2 = vec<2, u32, defaultp>;
	using	u32vec3 = vec<3, u32, defaultp>;
	using	u32vec4 = vec<4, u32, defaultp>;

	using		lowp_u64vec1 = vec<1, u64, lowp>;
	using		lowp_u64vec2 = vec<2, u64, lowp>;
	using		lowp_u64vec3 = vec<3, u64, lowp>;
	using		lowp_u64vec4 = vec<4, u64, lowp>;

	using	mediump_u64vec1 = vec<1, u64, mediump>;
	using	mediump_u64vec2 = vec<2, u64, mediump>;
	using	mediump_u64vec3 = vec<3, u64, mediump>;
	using	mediump_u64vec4 = vec<4, u64, mediump>;

	using		highp_u64vec1 = vec<1, u64, highp>;
	using		highp_u64vec2 = vec<2, u64, highp>;
	using		highp_u64vec3 = vec<3, u64, highp>;
	using		highp_u64vec4 = vec<4, u64, highp>;

	using	u64vec1 = vec<1, u64, defaultp>;
	using	u64vec2 = vec<2, u64, defaultp>;
	using	u64vec3 = vec<3, u64, defaultp>;
	using	u64vec4 = vec<4, u64, defaultp>;

	// Vector float

	using			lowp_vec1 = vec<1, float, lowp>;
	using			lowp_vec2 = vec<2, float, lowp>;
	using			lowp_vec3 = vec<3, float, lowp>;
	using			lowp_vec4 = vec<4, float, lowp>;

	using		mediump_vec1 = vec<1, float, mediump>;
	using		mediump_vec2 = vec<2, float, mediump>;
	using		mediump_vec3 = vec<3, float, mediump>;
	using		mediump_vec4 = vec<4, float, mediump>;

	using		highp_vec1 = vec<1, float, highp>;
	using		highp_vec2 = vec<2, float, highp>;
	using		highp_vec3 = vec<3, float, highp>;
	using		highp_vec4 = vec<4, float, highp>;

	using		vec1 = vec<1, float, defaultp>;
	using		vec2 = vec<2, float, defaultp>;
	using		vec3 = vec<3, float, defaultp>;
	using		vec4 = vec<4, float, defaultp>;

	using			lowp_fvec1 = vec<1, float, lowp>;
	using			lowp_fvec2 = vec<2, float, lowp>;
	using			lowp_fvec3 = vec<3, float, lowp>;
	using			lowp_fvec4 = vec<4, float, lowp>;

	using		mediump_fvec1 = vec<1, float, mediump>;
	using		mediump_fvec2 = vec<2, float, mediump>;
	using		mediump_fvec3 = vec<3, float, mediump>;
	using		mediump_fvec4 = vec<4, float, mediump>;

	using		highp_fvec1 = vec<1, float, highp>;
	using		highp_fvec2 = vec<2, float, highp>;
	using		highp_fvec3 = vec<3, float, highp>;
	using		highp_fvec4 = vec<4, float, highp>;

	using		fvec1 = vec<1, f32, defaultp>;
	using		fvec2 = vec<2, f32, defaultp>;
	using		fvec3 = vec<3, f32, defaultp>;
	using		fvec4 = vec<4, f32, defaultp>;

	using			lowp_f32vec1 = vec<1, f32, lowp>;
	using			lowp_f32vec2 = vec<2, f32, lowp>;
	using			lowp_f32vec3 = vec<3, f32, lowp>;
	using			lowp_f32vec4 = vec<4, f32, lowp>;

	using		mediump_f32vec1 = vec<1, f32, mediump>;
	using		mediump_f32vec2 = vec<2, f32, mediump>;
	using		mediump_f32vec3 = vec<3, f32, mediump>;
	using		mediump_f32vec4 = vec<4, f32, mediump>;

	using			highp_f32vec1 = vec<1, f32, highp>;
	using			highp_f32vec2 = vec<2, f32, highp>;
	using			highp_f32vec3 = vec<3, f32, highp>;
	using			highp_f32vec4 = vec<4, f32, highp>;

	using		f32vec1 = vec<1, f32, defaultp>;
	using		f32vec2 = vec<2, f32, defaultp>;
	using		f32vec3 = vec<3, f32, defaultp>;
	using		f32vec4 = vec<4, f32, defaultp>;

	using			lowp_dvec1 = vec<1, f64, lowp>;
	using			lowp_dvec2 = vec<2, f64, lowp>;
	using			lowp_dvec3 = vec<3, f64, lowp>;
	using			lowp_dvec4 = vec<4, f64, lowp>;

	using		mediump_dvec1 = vec<1, f64, mediump>;
	using		mediump_dvec2 = vec<2, f64, mediump>;
	using		mediump_dvec3 = vec<3, f64, mediump>;
	using		mediump_dvec4 = vec<4, f64, mediump>;

	using			highp_dvec1 = vec<1, f64, highp>;
	using			highp_dvec2 = vec<2, f64, highp>;
	using			highp_dvec3 = vec<3, f64, highp>;
	using			highp_dvec4 = vec<4, f64, highp>;

	using		dvec1 = vec<1, f64, defaultp>;
	using		dvec2 = vec<2, f64, defaultp>;
	using		dvec3 = vec<3, f64, defaultp>;
	using		dvec4 = vec<4, f64, defaultp>;

	using			lowp_f64vec1 = vec<1, f64, lowp>;
	using			lowp_f64vec2 = vec<2, f64, lowp>;
	using			lowp_f64vec3 = vec<3, f64, lowp>;
	using			lowp_f64vec4 = vec<4, f64, lowp>;

	using		mediump_f64vec1 = vec<1, f64, mediump>;
	using		mediump_f64vec2 = vec<2, f64, mediump>;
	using		mediump_f64vec3 = vec<3, f64, mediump>;
	using		mediump_f64vec4 = vec<4, f64, mediump>;

	using			highp_f64vec1 = vec<1, f64, highp>;
	using			highp_f64vec2 = vec<2, f64, highp>;
	using			highp_f64vec3 = vec<3, f64, highp>;
	using			highp_f64vec4 = vec<4, f64, highp>;

	using		f64vec1 = vec<1, f64, defaultp>;
	using		f64vec2 = vec<2, f64, defaultp>;
	using		f64vec3 = vec<3, f64, defaultp>;
	using		f64vec4 = vec<4, f64, defaultp>;

	// Matrix NxN

	using		lowp_mat2 = mat<2, 2, f32, lowp>;
	using		lowp_mat3 = mat<3, 3, f32, lowp>;
	using		lowp_mat4 = mat<4, 4, f32, lowp>;

	using		mediump_mat2 = mat<2, 2, f32, mediump>;
	using		mediump_mat3 = mat<3, 3, f32, mediump>;
	using		mediump_mat4 = mat<4, 4, f32, mediump>;

	using		highp_mat2 = mat<2, 2, f32, highp>;
	using		highp_mat3 = mat<3, 3, f32, highp>;
	using		highp_mat4 = mat<4, 4, f32, highp>;

	using	mat2 = mat<2, 2, f32, defaultp>;
	using	mat3 = mat<3, 3, f32, defaultp>;
	using	mat4 = mat<4, 4, f32, defaultp>;

	using		lowp_fmat2 = mat<2, 2, f32, lowp>;
	using		lowp_fmat3 = mat<3, 3, f32, lowp>;
	using		lowp_fmat4 = mat<4, 4, f32, lowp>;

	using		mediump_fmat2 = mat<2, 2, f32, mediump>;
	using		mediump_fmat3 = mat<3, 3, f32, mediump>;
	using		mediump_fmat4 = mat<4, 4, f32, mediump>;

	using		highp_fmat2 = mat<2, 2, f32, highp>;
	using		highp_fmat3 = mat<3, 3, f32, highp>;
	using		highp_fmat4 = mat<4, 4, f32, highp>;

	using	fmat2 = mat<2, 2, f32, defaultp>;
	using	fmat3 = mat<3, 3, f32, defaultp>;
	using	fmat4 = mat<4, 4, f32, defaultp>;

	using		lowp_f32mat2 = mat<2, 2, f32, lowp>;
	using		lowp_f32mat3 = mat<3, 3, f32, lowp>;
	using		lowp_f32mat4 = mat<4, 4, f32, lowp>;

	using		mediump_f32mat2 = mat<2, 2, f32, mediump>;
	using		mediump_f32mat3 = mat<3, 3, f32, mediump>;
	using		mediump_f32mat4 = mat<4, 4, f32, mediump>;

	using		highp_f32mat2 = mat<2, 2, f32, highp>;
	using		highp_f32mat3 = mat<3, 3, f32, highp>;
	using		highp_f32mat4 = mat<4, 4, f32, highp>;

	using	f32mat2 = mat<2, 2, f32, defaultp>;
	using	f32mat3 = mat<3, 3, f32, defaultp>;
	using	f32mat4 = mat<4, 4, f32, defaultp>;

	using		lowp_dmat2 = mat<2, 2, f64, lowp>;
	using		lowp_dmat3 = mat<3, 3, f64, lowp>;
	using		lowp_dmat4 = mat<4, 4, f64, lowp>;

	using		mediump_dmat2 = mat<2, 2, f64, mediump>;
	using		mediump_dmat3 = mat<3, 3, f64, mediump>;
	using		mediump_dmat4 = mat<4, 4, f64, mediump>;

	using		highp_dmat2 = mat<2, 2, f64, highp>;
	using		highp_dmat3 = mat<3, 3, f64, highp>;
	using		highp_dmat4 = mat<4, 4, f64, highp>;

	using	dmat2 = mat<2, 2, f64, defaultp>;
	using	dmat3 = mat<3, 3, f64, defaultp>;
	using	dmat4 = mat<4, 4, f64, defaultp>;

	using		lowp_f64mat2 = mat<2, 2, f64, lowp>;
	using		lowp_f64mat3 = mat<3, 3, f64, lowp>;
	using		lowp_f64mat4 = mat<4, 4, f64, lowp>;

	using		mediump_f64mat2 = mat<2, 2, f64, mediump>;
	using		mediump_f64mat3 = mat<3, 3, f64, mediump>;
	using		mediump_f64mat4 = mat<4, 4, f64, mediump>;

	using		highp_f64mat2 = mat<2, 2, f64, highp>;
	using		highp_f64mat3 = mat<3, 3, f64, highp>;
	using		highp_f64mat4 = mat<4, 4, f64, highp>;

	using	f64mat2 = mat<2, 2, f64, defaultp>;
	using	f64mat3 = mat<3, 3, f64, defaultp>;
	using	f64mat4 = mat<4, 4, f64, defaultp>;

	// Matrix MxN

	using		lowp_mat2x2 = mat<2, 2, f32, lowp>;
	using		lowp_mat2x3 = mat<2, 3, f32, lowp>;
	using		lowp_mat2x4 = mat<2, 4, f32, lowp>;
	using		lowp_mat3x2 = mat<3, 2, f32, lowp>;
	using		lowp_mat3x3 = mat<3, 3, f32, lowp>;
	using		lowp_mat3x4 = mat<3, 4, f32, lowp>;
	using		lowp_mat4x2 = mat<4, 2, f32, lowp>;
	using		lowp_mat4x3 = mat<4, 3, f32, lowp>;
	using		lowp_mat4x4 = mat<4, 4, f32, lowp>;

	using		mediump_mat2x2 = mat<2, 2, f32, mediump>;
	using		mediump_mat2x3 = mat<2, 3, f32, mediump>;
	using		mediump_mat2x4 = mat<2, 4, f32, mediump>;
	using		mediump_mat3x2 = mat<3, 2, f32, mediump>;
	using		mediump_mat3x3 = mat<3, 3, f32, mediump>;
	using		mediump_mat3x4 = mat<3, 4, f32, mediump>;
	using		mediump_mat4x2 = mat<4, 2, f32, mediump>;
	using		mediump_mat4x3 = mat<4, 3, f32, mediump>;
	using		mediump_mat4x4 = mat<4, 4, f32, mediump>;

	using		highp_mat2x2 = mat<2, 2, f32, highp>;
	using		highp_mat2x3 = mat<2, 3, f32, highp>;
	using		highp_mat2x4 = mat<2, 4, f32, highp>;
	using		highp_mat3x2 = mat<3, 2, f32, highp>;
	using		highp_mat3x3 = mat<3, 3, f32, highp>;
	using		highp_mat3x4 = mat<3, 4, f32, highp>;
	using		highp_mat4x2 = mat<4, 2, f32, highp>;
	using		highp_mat4x3 = mat<4, 3, f32, highp>;
	using		highp_mat4x4 = mat<4, 4, f32, highp>;

	using	mat2x2 = mat<2, 2, f32, defaultp>;
	using	mat2x3 = mat<2, 3, f32, defaultp>;
	using	mat2x4 = mat<2, 4, f32, defaultp>;
	using	mat3x2 = mat<3, 2, f32, defaultp>;
	using	mat3x3 = mat<3, 3, f32, defaultp>;
	using	mat3x4 = mat<3, 4, f32, defaultp>;
	using	mat4x2 = mat<4, 2, f32, defaultp>;
	using	mat4x3 = mat<4, 3, f32, defaultp>;
	using	mat4x4 = mat<4, 4, f32, defaultp>;

	using		lowp_fmat2x2 = mat<2, 2, f32, lowp>;
	using		lowp_fmat2x3 = mat<2, 3, f32, lowp>;
	using		lowp_fmat2x4 = mat<2, 4, f32, lowp>;
	using		lowp_fmat3x2 = mat<3, 2, f32, lowp>;
	using		lowp_fmat3x3 = mat<3, 3, f32, lowp>;
	using		lowp_fmat3x4 = mat<3, 4, f32, lowp>;
	using		lowp_fmat4x2 = mat<4, 2, f32, lowp>;
	using		lowp_fmat4x3 = mat<4, 3, f32, lowp>;
	using		lowp_fmat4x4 = mat<4, 4, f32, lowp>;

	using		mediump_fmat2x2 = mat<2, 2, f32, mediump>;
	using		mediump_fmat2x3 = mat<2, 3, f32, mediump>;
	using		mediump_fmat2x4 = mat<2, 4, f32, mediump>;
	using		mediump_fmat3x2 = mat<3, 2, f32, mediump>;
	using		mediump_fmat3x3 = mat<3, 3, f32, mediump>;
	using		mediump_fmat3x4 = mat<3, 4, f32, mediump>;
	using		mediump_fmat4x2 = mat<4, 2, f32, mediump>;
	using		mediump_fmat4x3 = mat<4, 3, f32, mediump>;
	using		mediump_fmat4x4 = mat<4, 4, f32, mediump>;

	using		highp_fmat2x2 = mat<2, 2, f32, highp>;
	using		highp_fmat2x3 = mat<2, 3, f32, highp>;
	using		highp_fmat2x4 = mat<2, 4, f32, highp>;
	using		highp_fmat3x2 = mat<3, 2, f32, highp>;
	using		highp_fmat3x3 = mat<3, 3, f32, highp>;
	using		highp_fmat3x4 = mat<3, 4, f32, highp>;
	using		highp_fmat4x2 = mat<4, 2, f32, highp>;
	using		highp_fmat4x3 = mat<4, 3, f32, highp>;
	using		highp_fmat4x4 = mat<4, 4, f32, highp>;

	using	fmat2x2 = mat<2, 2, f32, defaultp>;
	using	fmat2x3 = mat<2, 3, f32, defaultp>;
	using	fmat2x4 = mat<2, 4, f32, defaultp>;
	using	fmat3x2 = mat<3, 2, f32, defaultp>;
	using	fmat3x3 = mat<3, 3, f32, defaultp>;
	using	fmat3x4 = mat<3, 4, f32, defaultp>;
	using	fmat4x2 = mat<4, 2, f32, defaultp>;
	using	fmat4x3 = mat<4, 3, f32, defaultp>;
	using	fmat4x4 = mat<4, 4, f32, defaultp>;

	using		lowp_f32mat2x2 = mat<2, 2, f32, lowp>;
	using		lowp_f32mat2x3 = mat<2, 3, f32, lowp>;
	using		lowp_f32mat2x4 = mat<2, 4, f32, lowp>;
	using		lowp_f32mat3x2 = mat<3, 2, f32, lowp>;
	using		lowp_f32mat3x3 = mat<3, 3, f32, lowp>;
	using		lowp_f32mat3x4 = mat<3, 4, f32, lowp>;
	using		lowp_f32mat4x2 = mat<4, 2, f32, lowp>;
	using		lowp_f32mat4x3 = mat<4, 3, f32, lowp>;
	using		lowp_f32mat4x4 = mat<4, 4, f32, lowp>;
	
	using		mediump_f32mat2x2 = mat<2, 2, f32, mediump>;
	using		mediump_f32mat2x3 = mat<2, 3, f32, mediump>;
	using		mediump_f32mat2x4 = mat<2, 4, f32, mediump>;
	using		mediump_f32mat3x2 = mat<3, 2, f32, mediump>;
	using		mediump_f32mat3x3 = mat<3, 3, f32, mediump>;
	using		mediump_f32mat3x4 = mat<3, 4, f32, mediump>;
	using		mediump_f32mat4x2 = mat<4, 2, f32, mediump>;
	using		mediump_f32mat4x3 = mat<4, 3, f32, mediump>;
	using		mediump_f32mat4x4 = mat<4, 4, f32, mediump>;

	using		highp_f32mat2x2 = mat<2, 2, f32, highp>;
	using		highp_f32mat2x3 = mat<2, 3, f32, highp>;
	using		highp_f32mat2x4 = mat<2, 4, f32, highp>;
	using		highp_f32mat3x2 = mat<3, 2, f32, highp>;
	using		highp_f32mat3x3 = mat<3, 3, f32, highp>;
	using		highp_f32mat3x4 = mat<3, 4, f32, highp>;
	using		highp_f32mat4x2 = mat<4, 2, f32, highp>;
	using		highp_f32mat4x3 = mat<4, 3, f32, highp>;
	using		highp_f32mat4x4 = mat<4, 4, f32, highp>;

	using	f32mat2x2 = mat<2, 2, f32, defaultp>;
	using	f32mat2x3 = mat<2, 3, f32, defaultp>;
	using	f32mat2x4 = mat<2, 4, f32, defaultp>;
	using	f32mat3x2 = mat<3, 2, f32, defaultp>;
	using	f32mat3x3 = mat<3, 3, f32, defaultp>;
	using	f32mat3x4 = mat<3, 4, f32, defaultp>;
	using	f32mat4x2 = mat<4, 2, f32, defaultp>;
	using	f32mat4x3 = mat<4, 3, f32, defaultp>;
	using	f32mat4x4 = mat<4, 4, f32, defaultp>;

	using		lowp_dmat2x2 = mat<2, 2, double, lowp>;
	using		lowp_dmat2x3 = mat<2, 3, double, lowp>;
	using		lowp_dmat2x4 = mat<2, 4, double, lowp>;
	using		lowp_dmat3x2 = mat<3, 2, double, lowp>;
	using		lowp_dmat3x3 = mat<3, 3, double, lowp>;
	using		lowp_dmat3x4 = mat<3, 4, double, lowp>;
	using		lowp_dmat4x2 = mat<4, 2, double, lowp>;
	using		lowp_dmat4x3 = mat<4, 3, double, lowp>;
	using		lowp_dmat4x4 = mat<4, 4, double, lowp>;

	using	mediump_dmat2x2 = mat<2, 2, double, mediump>;
	using	mediump_dmat2x3 = mat<2, 3, double, mediump>;
	using	mediump_dmat2x4 = mat<2, 4, double, mediump>;
	using	mediump_dmat3x2 = mat<3, 2, double, mediump>;
	using	mediump_dmat3x3 = mat<3, 3, double, mediump>;
	using	mediump_dmat3x4 = mat<3, 4, double, mediump>;
	using	mediump_dmat4x2 = mat<4, 2, double, mediump>;
	using	mediump_dmat4x3 = mat<4, 3, double, mediump>;
	using	mediump_dmat4x4 = mat<4, 4, double, mediump>;

	using	highp_dmat2x2 = mat<2, 2, double, highp>;
	using	highp_dmat2x3 = mat<2, 3, double, highp>;
	using	highp_dmat2x4 = mat<2, 4, double, highp>;
	using	highp_dmat3x2 = mat<3, 2, double, highp>;
	using	highp_dmat3x3 = mat<3, 3, double, highp>;
	using	highp_dmat3x4 = mat<3, 4, double, highp>;
	using	highp_dmat4x2 = mat<4, 2, double, highp>;
	using	highp_dmat4x3 = mat<4, 3, double, highp>;
	using	highp_dmat4x4 = mat<4, 4, double, highp>;

	using	dmat2x2 = mat<2, 2, double, defaultp>;
	using	dmat2x3 = mat<2, 3, double, defaultp>;
	using	dmat2x4 = mat<2, 4, double, defaultp>;
	using	dmat3x2 = mat<3, 2, double, defaultp>;
	using	dmat3x3 = mat<3, 3, double, defaultp>;
	using	dmat3x4 = mat<3, 4, double, defaultp>;
	using	dmat4x2 = mat<4, 2, double, defaultp>;
	using	dmat4x3 = mat<4, 3, double, defaultp>;
	using	dmat4x4 = mat<4, 4, double, defaultp>;

	using		lowp_f64mat2x2 = mat<2, 2, f64, lowp>;
	using		lowp_f64mat2x3 = mat<2, 3, f64, lowp>;
	using		lowp_f64mat2x4 = mat<2, 4, f64, lowp>;
	using		lowp_f64mat3x2 = mat<3, 2, f64, lowp>;
	using		lowp_f64mat3x3 = mat<3, 3, f64, lowp>;
	using		lowp_f64mat3x4 = mat<3, 4, f64, lowp>;
	using		lowp_f64mat4x2 = mat<4, 2, f64, lowp>;
	using		lowp_f64mat4x3 = mat<4, 3, f64, lowp>;
	using		lowp_f64mat4x4 = mat<4, 4, f64, lowp>;

	using		mediump_f64mat2x2 = mat<2, 2, f64, mediump>;
	using		mediump_f64mat2x3 = mat<2, 3, f64, mediump>;
	using		mediump_f64mat2x4 = mat<2, 4, f64, mediump>;
	using		mediump_f64mat3x2 = mat<3, 2, f64, mediump>;
	using		mediump_f64mat3x3 = mat<3, 3, f64, mediump>;
	using		mediump_f64mat3x4 = mat<3, 4, f64, mediump>;
	using		mediump_f64mat4x2 = mat<4, 2, f64, mediump>;
	using		mediump_f64mat4x3 = mat<4, 3, f64, mediump>;
	using		mediump_f64mat4x4 = mat<4, 4, f64, mediump>;

	using		highp_f64mat2x2 = mat<2, 2, f64, highp>;
	using		highp_f64mat2x3 = mat<2, 3, f64, highp>;
	using		highp_f64mat2x4 = mat<2, 4, f64, highp>;
	using		highp_f64mat3x2 = mat<3, 2, f64, highp>;
	using		highp_f64mat3x3 = mat<3, 3, f64, highp>;
	using		highp_f64mat3x4 = mat<3, 4, f64, highp>;
	using		highp_f64mat4x2 = mat<4, 2, f64, highp>;
	using		highp_f64mat4x3 = mat<4, 3, f64, highp>;
	using		highp_f64mat4x4 = mat<4, 4, f64, highp>;

	using	f64mat2x2 = mat<2, 2, f64, defaultp>;
	using	f64mat2x3 = mat<2, 3, f64, defaultp>;
	using	f64mat2x4 = mat<2, 4, f64, defaultp>;
	using	f64mat3x2 = mat<3, 2, f64, defaultp>;
	using	f64mat3x3 = mat<3, 3, f64, defaultp>;
	using	f64mat3x4 = mat<3, 4, f64, defaultp>;
	using	f64mat4x2 = mat<4, 2, f64, defaultp>;
	using	f64mat4x3 = mat<4, 3, f64, defaultp>;
	using	f64mat4x4 = mat<4, 4, f64, defaultp>;

	// Signed integer matrix MxN

	using		lowp_imat2x2 = mat<2, 2, int, lowp>;
	using		lowp_imat2x3 = mat<2, 3, int, lowp>;
	using		lowp_imat2x4 = mat<2, 4, int, lowp>;
	using		lowp_imat3x2 = mat<3, 2, int, lowp>;
	using		lowp_imat3x3 = mat<3, 3, int, lowp>;
	using		lowp_imat3x4 = mat<3, 4, int, lowp>;
	using		lowp_imat4x2 = mat<4, 2, int, lowp>;
	using		lowp_imat4x3 = mat<4, 3, int, lowp>;
	using		lowp_imat4x4 = mat<4, 4, int, lowp>;

	using		mediump_imat2x2 = mat<2, 2, int, mediump>;
	using		mediump_imat2x3 = mat<2, 3, int, mediump>;
	using		mediump_imat2x4 = mat<2, 4, int, mediump>;
	using		mediump_imat3x2 = mat<3, 2, int, mediump>;
	using		mediump_imat3x3 = mat<3, 3, int, mediump>;
	using		mediump_imat3x4 = mat<3, 4, int, mediump>;
	using		mediump_imat4x2 = mat<4, 2, int, mediump>;
	using		mediump_imat4x3 = mat<4, 3, int, mediump>;
	using		mediump_imat4x4 = mat<4, 4, int, mediump>;

	using		highp_imat2x2 = mat<2, 2, int, highp>;
	using		highp_imat2x3 = mat<2, 3, int, highp>;
	using		highp_imat2x4 = mat<2, 4, int, highp>;
	using		highp_imat3x2 = mat<3, 2, int, highp>;
	using		highp_imat3x3 = mat<3, 3, int, highp>;
	using		highp_imat3x4 = mat<3, 4, int, highp>;
	using		highp_imat4x2 = mat<4, 2, int, highp>;
	using		highp_imat4x3 = mat<4, 3, int, highp>;
	using		highp_imat4x4 = mat<4, 4, int, highp>;

	using	imat2x2 = mat<2, 2, int, defaultp>;
	using	imat2x3 = mat<2, 3, int, defaultp>;
	using	imat2x4 = mat<2, 4, int, defaultp>;
	using	imat3x2 = mat<3, 2, int, defaultp>;
	using	imat3x3 = mat<3, 3, int, defaultp>;
	using	imat3x4 = mat<3, 4, int, defaultp>;
	using	imat4x2 = mat<4, 2, int, defaultp>;
	using	imat4x3 = mat<4, 3, int, defaultp>;
	using	imat4x4 = mat<4, 4, int, defaultp>;


	using		lowp_i8mat2x2 = mat<2, 2, int8, lowp>;
	using		lowp_i8mat2x3 = mat<2, 3, int8, lowp>;
	using		lowp_i8mat2x4 = mat<2, 4, int8, lowp>;
	using		lowp_i8mat3x2 = mat<3, 2, int8, lowp>;
	using		lowp_i8mat3x3 = mat<3, 3, int8, lowp>;
	using		lowp_i8mat3x4 = mat<3, 4, int8, lowp>;
	using		lowp_i8mat4x2 = mat<4, 2, int8, lowp>;
	using		lowp_i8mat4x3 = mat<4, 3, int8, lowp>;
	using		lowp_i8mat4x4 = mat<4, 4, int8, lowp>;

	using	mediump_i8mat2x2 = mat<2, 2, int8, mediump>;
	using	mediump_i8mat2x3 = mat<2, 3, int8, mediump>;
	using	mediump_i8mat2x4 = mat<2, 4, int8, mediump>;
	using	mediump_i8mat3x2 = mat<3, 2, int8, mediump>;
	using	mediump_i8mat3x3 = mat<3, 3, int8, mediump>;
	using	mediump_i8mat3x4 = mat<3, 4, int8, mediump>;
	using	mediump_i8mat4x2 = mat<4, 2, int8, mediump>;
	using	mediump_i8mat4x3 = mat<4, 3, int8, mediump>;
	using	mediump_i8mat4x4 = mat<4, 4, int8, mediump>;

	using		highp_i8mat2x2 = mat<2, 2, int8, highp>;
	using		highp_i8mat2x3 = mat<2, 3, int8, highp>;
	using		highp_i8mat2x4 = mat<2, 4, int8, highp>;
	using		highp_i8mat3x2 = mat<3, 2, int8, highp>;
	using		highp_i8mat3x3 = mat<3, 3, int8, highp>;
	using		highp_i8mat3x4 = mat<3, 4, int8, highp>;
	using		highp_i8mat4x2 = mat<4, 2, int8, highp>;
	using		highp_i8mat4x3 = mat<4, 3, int8, highp>;
	using		highp_i8mat4x4 = mat<4, 4, int8, highp>;

	using	i8mat2x2 = mat<2, 2, int8, defaultp>;
	using	i8mat2x3 = mat<2, 3, int8, defaultp>;
	using	i8mat2x4 = mat<2, 4, int8, defaultp>;
	using	i8mat3x2 = mat<3, 2, int8, defaultp>;
	using	i8mat3x3 = mat<3, 3, int8, defaultp>;
	using	i8mat3x4 = mat<3, 4, int8, defaultp>;
	using	i8mat4x2 = mat<4, 2, int8, defaultp>;
	using	i8mat4x3 = mat<4, 3, int8, defaultp>;
	using	i8mat4x4 = mat<4, 4, int8, defaultp>;


	using		lowp_i16mat2x2 = mat<2, 2, int16, lowp>;
	using		lowp_i16mat2x3 = mat<2, 3, int16, lowp>;
	using		lowp_i16mat2x4 = mat<2, 4, int16, lowp>;
	using		lowp_i16mat3x2 = mat<3, 2, int16, lowp>;
	using		lowp_i16mat3x3 = mat<3, 3, int16, lowp>;
	using		lowp_i16mat3x4 = mat<3, 4, int16, lowp>;
	using		lowp_i16mat4x2 = mat<4, 2, int16, lowp>;
	using		lowp_i16mat4x3 = mat<4, 3, int16, lowp>;
	using		lowp_i16mat4x4 = mat<4, 4, int16, lowp>;

	using	mediump_i16mat2x2 = mat<2, 2, int16, mediump>;
	using	mediump_i16mat2x3 = mat<2, 3, int16, mediump>;
	using	mediump_i16mat2x4 = mat<2, 4, int16, mediump>;
	using	mediump_i16mat3x2 = mat<3, 2, int16, mediump>;
	using	mediump_i16mat3x3 = mat<3, 3, int16, mediump>;
	using	mediump_i16mat3x4 = mat<3, 4, int16, mediump>;
	using	mediump_i16mat4x2 = mat<4, 2, int16, mediump>;
	using	mediump_i16mat4x3 = mat<4, 3, int16, mediump>;
	using	mediump_i16mat4x4 = mat<4, 4, int16, mediump>;

	using		highp_i16mat2x2 = mat<2, 2, int16, highp>;
	using		highp_i16mat2x3 = mat<2, 3, int16, highp>;
	using		highp_i16mat2x4 = mat<2, 4, int16, highp>;
	using		highp_i16mat3x2 = mat<3, 2, int16, highp>;
	using		highp_i16mat3x3 = mat<3, 3, int16, highp>;
	using		highp_i16mat3x4 = mat<3, 4, int16, highp>;
	using		highp_i16mat4x2 = mat<4, 2, int16, highp>;
	using		highp_i16mat4x3 = mat<4, 3, int16, highp>;
	using		highp_i16mat4x4 = mat<4, 4, int16, highp>;

	using	i16mat2x2 = mat<2, 2, int16, defaultp>;
	using	i16mat2x3 = mat<2, 3, int16, defaultp>;
	using	i16mat2x4 = mat<2, 4, int16, defaultp>;
	using	i16mat3x2 = mat<3, 2, int16, defaultp>;
	using	i16mat3x3 = mat<3, 3, int16, defaultp>;
	using	i16mat3x4 = mat<3, 4, int16, defaultp>;
	using	i16mat4x2 = mat<4, 2, int16, defaultp>;
	using	i16mat4x3 = mat<4, 3, int16, defaultp>;
	using	i16mat4x4 = mat<4, 4, int16, defaultp>;


	using		lowp_i32mat2x2 = mat<2, 2, int32, lowp>;
	using		lowp_i32mat2x3 = mat<2, 3, int32, lowp>;
	using		lowp_i32mat2x4 = mat<2, 4, int32, lowp>;
	using		lowp_i32mat3x2 = mat<3, 2, int32, lowp>;
	using		lowp_i32mat3x3 = mat<3, 3, int32, lowp>;
	using		lowp_i32mat3x4 = mat<3, 4, int32, lowp>;
	using		lowp_i32mat4x2 = mat<4, 2, int32, lowp>;
	using		lowp_i32mat4x3 = mat<4, 3, int32, lowp>;
	using		lowp_i32mat4x4 = mat<4, 4, int32, lowp>;

	using	mediump_i32mat2x2 = mat<2, 2, int32, mediump>;
	using	mediump_i32mat2x3 = mat<2, 3, int32, mediump>;
	using	mediump_i32mat2x4 = mat<2, 4, int32, mediump>;
	using	mediump_i32mat3x2 = mat<3, 2, int32, mediump>;
	using	mediump_i32mat3x3 = mat<3, 3, int32, mediump>;
	using	mediump_i32mat3x4 = mat<3, 4, int32, mediump>;
	using	mediump_i32mat4x2 = mat<4, 2, int32, mediump>;
	using	mediump_i32mat4x3 = mat<4, 3, int32, mediump>;
	using	mediump_i32mat4x4 = mat<4, 4, int32, mediump>;

	using		highp_i32mat2x2 = mat<2, 2, int32, highp>;
	using		highp_i32mat2x3 = mat<2, 3, int32, highp>;
	using		highp_i32mat2x4 = mat<2, 4, int32, highp>;
	using		highp_i32mat3x2 = mat<3, 2, int32, highp>;
	using		highp_i32mat3x3 = mat<3, 3, int32, highp>;
	using		highp_i32mat3x4 = mat<3, 4, int32, highp>;
	using		highp_i32mat4x2 = mat<4, 2, int32, highp>;
	using		highp_i32mat4x3 = mat<4, 3, int32, highp>;
	using		highp_i32mat4x4 = mat<4, 4, int32, highp>;

	using	i32mat2x2 = mat<2, 2, int32, defaultp>;
	using	i32mat2x3 = mat<2, 3, int32, defaultp>;
	using	i32mat2x4 = mat<2, 4, int32, defaultp>;
	using	i32mat3x2 = mat<3, 2, int32, defaultp>;
	using	i32mat3x3 = mat<3, 3, int32, defaultp>;
	using	i32mat3x4 = mat<3, 4, int32, defaultp>;
	using	i32mat4x2 = mat<4, 2, int32, defaultp>;
	using	i32mat4x3 = mat<4, 3, int32, defaultp>;
	using	i32mat4x4 = mat<4, 4, int32, defaultp>;


	using		lowp_i64mat2x2 = mat<2, 2, int64, lowp>;
	using		lowp_i64mat2x3 = mat<2, 3, int64, lowp>;
	using		lowp_i64mat2x4 = mat<2, 4, int64, lowp>;
	using		lowp_i64mat3x2 = mat<3, 2, int64, lowp>;
	using		lowp_i64mat3x3 = mat<3, 3, int64, lowp>;
	using		lowp_i64mat3x4 = mat<3, 4, int64, lowp>;
	using		lowp_i64mat4x2 = mat<4, 2, int64, lowp>;
	using		lowp_i64mat4x3 = mat<4, 3, int64, lowp>;
	using		lowp_i64mat4x4 = mat<4, 4, int64, lowp>;

	using	mediump_i64mat2x2 = mat<2, 2, int64, mediump>;
	using	mediump_i64mat2x3 = mat<2, 3, int64, mediump>;
	using	mediump_i64mat2x4 = mat<2, 4, int64, mediump>;
	using	mediump_i64mat3x2 = mat<3, 2, int64, mediump>;
	using	mediump_i64mat3x3 = mat<3, 3, int64, mediump>;
	using	mediump_i64mat3x4 = mat<3, 4, int64, mediump>;
	using	mediump_i64mat4x2 = mat<4, 2, int64, mediump>;
	using	mediump_i64mat4x3 = mat<4, 3, int64, mediump>;
	using	mediump_i64mat4x4 = mat<4, 4, int64, mediump>;

	using		highp_i64mat2x2 = mat<2, 2, int64, highp>;
	using		highp_i64mat2x3 = mat<2, 3, int64, highp>;
	using		highp_i64mat2x4 = mat<2, 4, int64, highp>;
	using		highp_i64mat3x2 = mat<3, 2, int64, highp>;
	using		highp_i64mat3x3 = mat<3, 3, int64, highp>;
	using		highp_i64mat3x4 = mat<3, 4, int64, highp>;
	using		highp_i64mat4x2 = mat<4, 2, int64, highp>;
	using		highp_i64mat4x3 = mat<4, 3, int64, highp>;
	using		highp_i64mat4x4 = mat<4, 4, int64, highp>;

	using	i64mat2x2 = mat<2, 2, int64, defaultp>;
	using	i64mat2x3 = mat<2, 3, int64, defaultp>;
	using	i64mat2x4 = mat<2, 4, int64, defaultp>;
	using	i64mat3x2 = mat<3, 2, int64, defaultp>;
	using	i64mat3x3 = mat<3, 3, int64, defaultp>;
	using	i64mat3x4 = mat<3, 4, int64, defaultp>;
	using	i64mat4x2 = mat<4, 2, int64, defaultp>;
	using	i64mat4x3 = mat<4, 3, int64, defaultp>;
	using	i64mat4x4 = mat<4, 4, int64, defaultp>;


	// Unsigned integer matrix MxN

	using		lowp_umat2x2 = mat<2, 2, uint, lowp>;
	using		lowp_umat2x3 = mat<2, 3, uint, lowp>;
	using		lowp_umat2x4 = mat<2, 4, uint, lowp>;
	using		lowp_umat3x2 = mat<3, 2, uint, lowp>;
	using		lowp_umat3x3 = mat<3, 3, uint, lowp>;
	using		lowp_umat3x4 = mat<3, 4, uint, lowp>;
	using		lowp_umat4x2 = mat<4, 2, uint, lowp>;
	using		lowp_umat4x3 = mat<4, 3, uint, lowp>;
	using		lowp_umat4x4 = mat<4, 4, uint, lowp>;

	using	mediump_umat2x2 = mat<2, 2, uint, mediump>;
	using	mediump_umat2x3 = mat<2, 3, uint, mediump>;
	using	mediump_umat2x4 = mat<2, 4, uint, mediump>;
	using	mediump_umat3x2 = mat<3, 2, uint, mediump>;
	using	mediump_umat3x3 = mat<3, 3, uint, mediump>;
	using	mediump_umat3x4 = mat<3, 4, uint, mediump>;
	using	mediump_umat4x2 = mat<4, 2, uint, mediump>;
	using	mediump_umat4x3 = mat<4, 3, uint, mediump>;
	using	mediump_umat4x4 = mat<4, 4, uint, mediump>;

	using		highp_umat2x2 = mat<2, 2, uint, highp>;
	using		highp_umat2x3 = mat<2, 3, uint, highp>;
	using		highp_umat2x4 = mat<2, 4, uint, highp>;
	using		highp_umat3x2 = mat<3, 2, uint, highp>;
	using		highp_umat3x3 = mat<3, 3, uint, highp>;
	using		highp_umat3x4 = mat<3, 4, uint, highp>;
	using		highp_umat4x2 = mat<4, 2, uint, highp>;
	using		highp_umat4x3 = mat<4, 3, uint, highp>;
	using		highp_umat4x4 = mat<4, 4, uint, highp>;

	using	umat2x2 = mat<2, 2, uint, defaultp>;
	using	umat2x3 = mat<2, 3, uint, defaultp>;
	using	umat2x4 = mat<2, 4, uint, defaultp>;
	using	umat3x2 = mat<3, 2, uint, defaultp>;
	using	umat3x3 = mat<3, 3, uint, defaultp>;
	using	umat3x4 = mat<3, 4, uint, defaultp>;
	using	umat4x2 = mat<4, 2, uint, defaultp>;
	using	umat4x3 = mat<4, 3, uint, defaultp>;
	using	umat4x4 = mat<4, 4, uint, defaultp>;


	using		lowp_u8mat2x2 = mat<2, 2, uint8, lowp>;
	using		lowp_u8mat2x3 = mat<2, 3, uint8, lowp>;
	using		lowp_u8mat2x4 = mat<2, 4, uint8, lowp>;
	using		lowp_u8mat3x2 = mat<3, 2, uint8, lowp>;
	using		lowp_u8mat3x3 = mat<3, 3, uint8, lowp>;
	using		lowp_u8mat3x4 = mat<3, 4, uint8, lowp>;
	using		lowp_u8mat4x2 = mat<4, 2, uint8, lowp>;
	using		lowp_u8mat4x3 = mat<4, 3, uint8, lowp>;
	using		lowp_u8mat4x4 = mat<4, 4, uint8, lowp>;

	using	mediump_u8mat2x2 = mat<2, 2, uint8, mediump>;
	using	mediump_u8mat2x3 = mat<2, 3, uint8, mediump>;
	using	mediump_u8mat2x4 = mat<2, 4, uint8, mediump>;
	using	mediump_u8mat3x2 = mat<3, 2, uint8, mediump>;
	using	mediump_u8mat3x3 = mat<3, 3, uint8, mediump>;
	using	mediump_u8mat3x4 = mat<3, 4, uint8, mediump>;
	using	mediump_u8mat4x2 = mat<4, 2, uint8, mediump>;
	using	mediump_u8mat4x3 = mat<4, 3, uint8, mediump>;
	using	mediump_u8mat4x4 = mat<4, 4, uint8, mediump>;

	using		highp_u8mat2x2 = mat<2, 2, uint8, highp>;
	using		highp_u8mat2x3 = mat<2, 3, uint8, highp>;
	using		highp_u8mat2x4 = mat<2, 4, uint8, highp>;
	using		highp_u8mat3x2 = mat<3, 2, uint8, highp>;
	using		highp_u8mat3x3 = mat<3, 3, uint8, highp>;
	using		highp_u8mat3x4 = mat<3, 4, uint8, highp>;
	using		highp_u8mat4x2 = mat<4, 2, uint8, highp>;
	using		highp_u8mat4x3 = mat<4, 3, uint8, highp>;
	using		highp_u8mat4x4 = mat<4, 4, uint8, highp>;

	using	u8mat2x2 = mat<2, 2, uint8, defaultp>;
	using	u8mat2x3 = mat<2, 3, uint8, defaultp>;
	using	u8mat2x4 = mat<2, 4, uint8, defaultp>;
	using	u8mat3x2 = mat<3, 2, uint8, defaultp>;
	using	u8mat3x3 = mat<3, 3, uint8, defaultp>;
	using	u8mat3x4 = mat<3, 4, uint8, defaultp>;
	using	u8mat4x2 = mat<4, 2, uint8, defaultp>;
	using	u8mat4x3 = mat<4, 3, uint8, defaultp>;
	using	u8mat4x4 = mat<4, 4, uint8, defaultp>;


	using		lowp_u16mat2x2 = mat<2, 2, uint16, lowp>;
	using		lowp_u16mat2x3 = mat<2, 3, uint16, lowp>;
	using		lowp_u16mat2x4 = mat<2, 4, uint16, lowp>;
	using		lowp_u16mat3x2 = mat<3, 2, uint16, lowp>;
	using		lowp_u16mat3x3 = mat<3, 3, uint16, lowp>;
	using		lowp_u16mat3x4 = mat<3, 4, uint16, lowp>;
	using		lowp_u16mat4x2 = mat<4, 2, uint16, lowp>;
	using		lowp_u16mat4x3 = mat<4, 3, uint16, lowp>;
	using		lowp_u16mat4x4 = mat<4, 4, uint16, lowp>;

	using	mediump_u16mat2x2 = mat<2, 2, uint16, mediump>;
	using	mediump_u16mat2x3 = mat<2, 3, uint16, mediump>;
	using	mediump_u16mat2x4 = mat<2, 4, uint16, mediump>;
	using	mediump_u16mat3x2 = mat<3, 2, uint16, mediump>;
	using	mediump_u16mat3x3 = mat<3, 3, uint16, mediump>;
	using	mediump_u16mat3x4 = mat<3, 4, uint16, mediump>;
	using	mediump_u16mat4x2 = mat<4, 2, uint16, mediump>;
	using	mediump_u16mat4x3 = mat<4, 3, uint16, mediump>;
	using	mediump_u16mat4x4 = mat<4, 4, uint16, mediump>;

	using	highp_u16mat2x2 = mat<2, 2, uint16, highp>;
	using	highp_u16mat2x3 = mat<2, 3, uint16, highp>;
	using	highp_u16mat2x4 = mat<2, 4, uint16, highp>;
	using	highp_u16mat3x2 = mat<3, 2, uint16, highp>;
	using	highp_u16mat3x3 = mat<3, 3, uint16, highp>;
	using	highp_u16mat3x4 = mat<3, 4, uint16, highp>;
	using	highp_u16mat4x2 = mat<4, 2, uint16, highp>;
	using	highp_u16mat4x3 = mat<4, 3, uint16, highp>;
	using	highp_u16mat4x4 = mat<4, 4, uint16, highp>;

	using	u16mat2x2 = mat<2, 2, uint16, defaultp>;
	using	u16mat2x3 = mat<2, 3, uint16, defaultp>;
	using	u16mat2x4 = mat<2, 4, uint16, defaultp>;
	using	u16mat3x2 = mat<3, 2, uint16, defaultp>;
	using	u16mat3x3 = mat<3, 3, uint16, defaultp>;
	using	u16mat3x4 = mat<3, 4, uint16, defaultp>;
	using	u16mat4x2 = mat<4, 2, uint16, defaultp>;
	using	u16mat4x3 = mat<4, 3, uint16, defaultp>;
	using	u16mat4x4 = mat<4, 4, uint16, defaultp>;


	using		lowp_u32mat2x2 = mat<2, 2, uint32, lowp>;
	using		lowp_u32mat2x3 = mat<2, 3, uint32, lowp>;
	using		lowp_u32mat2x4 = mat<2, 4, uint32, lowp>;
	using		lowp_u32mat3x2 = mat<3, 2, uint32, lowp>;
	using		lowp_u32mat3x3 = mat<3, 3, uint32, lowp>;
	using		lowp_u32mat3x4 = mat<3, 4, uint32, lowp>;
	using		lowp_u32mat4x2 = mat<4, 2, uint32, lowp>;
	using		lowp_u32mat4x3 = mat<4, 3, uint32, lowp>;
	using		lowp_u32mat4x4 = mat<4, 4, uint32, lowp>;

	using	mediump_u32mat2x2 = mat<2, 2, uint32, mediump>;
	using	mediump_u32mat2x3 = mat<2, 3, uint32, mediump>;
	using	mediump_u32mat2x4 = mat<2, 4, uint32, mediump>;
	using	mediump_u32mat3x2 = mat<3, 2, uint32, mediump>;
	using	mediump_u32mat3x3 = mat<3, 3, uint32, mediump>;
	using	mediump_u32mat3x4 = mat<3, 4, uint32, mediump>;
	using	mediump_u32mat4x2 = mat<4, 2, uint32, mediump>;
	using	mediump_u32mat4x3 = mat<4, 3, uint32, mediump>;
	using	mediump_u32mat4x4 = mat<4, 4, uint32, mediump>;

	using	highp_u32mat2x2 = mat<2, 2, uint32, highp>;
	using	highp_u32mat2x3 = mat<2, 3, uint32, highp>;
	using	highp_u32mat2x4 = mat<2, 4, uint32, highp>;
	using	highp_u32mat3x2 = mat<3, 2, uint32, highp>;
	using	highp_u32mat3x3 = mat<3, 3, uint32, highp>;
	using	highp_u32mat3x4 = mat<3, 4, uint32, highp>;
	using	highp_u32mat4x2 = mat<4, 2, uint32, highp>;
	using	highp_u32mat4x3 = mat<4, 3, uint32, highp>;
	using	highp_u32mat4x4 = mat<4, 4, uint32, highp>;

	using	u32mat2x2 = mat<2, 2, uint32, defaultp>;
	using	u32mat2x3 = mat<2, 3, uint32, defaultp>;
	using	u32mat2x4 = mat<2, 4, uint32, defaultp>;
	using	u32mat3x2 = mat<3, 2, uint32, defaultp>;
	using	u32mat3x3 = mat<3, 3, uint32, defaultp>;
	using	u32mat3x4 = mat<3, 4, uint32, defaultp>;
	using	u32mat4x2 = mat<4, 2, uint32, defaultp>;
	using	u32mat4x3 = mat<4, 3, uint32, defaultp>;
	using	u32mat4x4 = mat<4, 4, uint32, defaultp>;


	using		lowp_u64mat2x2 = mat<2, 2, uint64, lowp>;
	using		lowp_u64mat2x3 = mat<2, 3, uint64, lowp>;
	using		lowp_u64mat2x4 = mat<2, 4, uint64, lowp>;
	using		lowp_u64mat3x2 = mat<3, 2, uint64, lowp>;
	using		lowp_u64mat3x3 = mat<3, 3, uint64, lowp>;
	using		lowp_u64mat3x4 = mat<3, 4, uint64, lowp>;
	using		lowp_u64mat4x2 = mat<4, 2, uint64, lowp>;
	using		lowp_u64mat4x3 = mat<4, 3, uint64, lowp>;
	using		lowp_u64mat4x4 = mat<4, 4, uint64, lowp>;

	using	mediump_u64mat2x2 = mat<2, 2, uint64, mediump>;
	using	mediump_u64mat2x3 = mat<2, 3, uint64, mediump>;
	using	mediump_u64mat2x4 = mat<2, 4, uint64, mediump>;
	using	mediump_u64mat3x2 = mat<3, 2, uint64, mediump>;
	using	mediump_u64mat3x3 = mat<3, 3, uint64, mediump>;
	using	mediump_u64mat3x4 = mat<3, 4, uint64, mediump>;
	using	mediump_u64mat4x2 = mat<4, 2, uint64, mediump>;
	using	mediump_u64mat4x3 = mat<4, 3, uint64, mediump>;
	using	mediump_u64mat4x4 = mat<4, 4, uint64, mediump>;

	using	highp_u64mat2x2 = mat<2, 2, uint64, highp>;
	using	highp_u64mat2x3 = mat<2, 3, uint64, highp>;
	using	highp_u64mat2x4 = mat<2, 4, uint64, highp>;
	using	highp_u64mat3x2 = mat<3, 2, uint64, highp>;
	using	highp_u64mat3x3 = mat<3, 3, uint64, highp>;
	using	highp_u64mat3x4 = mat<3, 4, uint64, highp>;
	using	highp_u64mat4x2 = mat<4, 2, uint64, highp>;
	using	highp_u64mat4x3 = mat<4, 3, uint64, highp>;
	using	highp_u64mat4x4 = mat<4, 4, uint64, highp>;

	using	u64mat2x2 = mat<2, 2, uint64, defaultp>;
	using	u64mat2x3 = mat<2, 3, uint64, defaultp>;
	using	u64mat2x4 = mat<2, 4, uint64, defaultp>;
	using	u64mat3x2 = mat<3, 2, uint64, defaultp>;
	using	u64mat3x3 = mat<3, 3, uint64, defaultp>;
	using	u64mat3x4 = mat<3, 4, uint64, defaultp>;
	using	u64mat4x2 = mat<4, 2, uint64, defaultp>;
	using	u64mat4x3 = mat<4, 3, uint64, defaultp>;
	using	u64mat4x4 = mat<4, 4, uint64, defaultp>;

	// Quaternion

	using			lowp_quat = qua<float, lowp>;
	using			mediump_quat = qua<float, mediump>;
	using			highp_quat = qua<float, highp>;
	using		quat = qua<float, defaultp>;

	using			lowp_fquat = qua<float, lowp>;
	using			mediump_fquat = qua<float, mediump>;
	using			highp_fquat = qua<float, highp>;
	using		fquat = qua<float, defaultp>;

	using				lowp_f32quat = qua<f32, lowp>;
	using			mediump_f32quat = qua<f32, mediump>;
	using				highp_f32quat = qua<f32, highp>;
	using			f32quat = qua<f32, defaultp>;

	using			lowp_dquat = qua<double, lowp>;
	using		mediump_dquat = qua<double, mediump>;
	using			highp_dquat = qua<double, highp>;
	using		dquat = qua<double, defaultp>;

	using				lowp_f64quat = qua<f64, lowp>;
	using			mediump_f64quat = qua<f64, mediump>;
	using				highp_f64quat = qua<f64, highp>;
	using			f64quat = qua<f64, defaultp>;
}//namespace glm


