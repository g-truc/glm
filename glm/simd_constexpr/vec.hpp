/// @ref core
/// @file glm/simd_constexpr/vec4.hpp

#pragma once
namespace glm 
{
	typedef vec<1, float, defaultp>		vec1;
	typedef vec<2, float, defaultp>		vec2;
	typedef vec<3, float, defaultp>		vec3;
	typedef vec<4, float, defaultp>		vec4;

	typedef vec<1, int, defaultp>		ivec1;
	typedef vec<2, int, defaultp>		ivec2;
	typedef vec<3, int, defaultp>		ivec3;
	typedef vec<4, int, defaultp>		ivec4;
	
	typedef vec<1, unsigned int, defaultp>		uvec1;
	typedef vec<2, unsigned int, defaultp>		uvec2;
	typedef vec<3, unsigned int, defaultp>		uvec3;
	typedef vec<4, unsigned int, defaultp>		uvec4;
	
	typedef vec<1, bool, defaultp>		bvec1;
	typedef vec<2, bool, defaultp>		bvec2;
	typedef vec<3, bool, defaultp>		bvec3;
	typedef vec<4, bool, defaultp>		bvec4;
}
#include "../detail/simd_constexpr/vec.hpp"
