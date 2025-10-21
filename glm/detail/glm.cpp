/// @ref core
/// @file glm/glm.cpp

#ifndef GLM_ENABLE_EXPERIMENTAL
#define GLM_ENABLE_EXPERIMENTAL
#endif
#include "../gtx/dual_quaternion.hpp"
#include "../gtc/vec1.hpp"
#include "../gtc/quaternion.hpp"
#include "../ext/scalar_int_sized.hpp"
#include "../ext/scalar_uint_sized.hpp"
#include "../glm.hpp"
#include "../ext.hpp"

namespace glm
{
// tvec1 type explicit instantiation
template struct vec<1, uint8, packed_lowp>;
template struct vec<1, uint16, packed_lowp>;
template struct vec<1, uint32, packed_lowp>;
template struct vec<1, uint64, packed_lowp>;
template struct vec<1, int8, packed_lowp>;
template struct vec<1, int16, packed_lowp>;
template struct vec<1, int32, packed_lowp>;
template struct vec<1, int64, packed_lowp>;
template struct vec<1, float32, packed_lowp>;
template struct vec<1, float64, packed_lowp>;

template struct vec<1, uint8, packed_mediump>;
template struct vec<1, uint16, packed_mediump>;
template struct vec<1, uint32, packed_mediump>;
template struct vec<1, uint64, packed_mediump>;
template struct vec<1, int8, packed_mediump>;
template struct vec<1, int16, packed_mediump>;
template struct vec<1, int32, packed_mediump>;
template struct vec<1, int64, packed_mediump>;
template struct vec<1, float32, packed_mediump>;
template struct vec<1, float64, packed_mediump>;

template struct vec<1, uint8, packed_highp>;
template struct vec<1, uint16, packed_highp>;
template struct vec<1, uint32, packed_highp>;
template struct vec<1, uint64, packed_highp>;
template struct vec<1, int8, packed_highp>;
template struct vec<1, int16, packed_highp>;
template struct vec<1, int32, packed_highp>;
template struct vec<1, int64, packed_highp>;
template struct vec<1, float32, packed_highp>;
template struct vec<1, float64, packed_highp>;

// tvec2 type explicit instantiation
template struct vec<2, uint8, packed_lowp>;
template struct vec<2, uint16, packed_lowp>;
template struct vec<2, uint32, packed_lowp>;
template struct vec<2, uint64, packed_lowp>;
template struct vec<2, int8, packed_lowp>;
template struct vec<2, int16, packed_lowp>;
template struct vec<2, int32, packed_lowp>;
template struct vec<2, int64, packed_lowp>;
template struct vec<2, float32, packed_lowp>;
template struct vec<2, float64, packed_lowp>;

template struct vec<2, uint8, packed_mediump>;
template struct vec<2, uint16, packed_mediump>;
template struct vec<2, uint32, packed_mediump>;
template struct vec<2, uint64, packed_mediump>;
template struct vec<2, int8, packed_mediump>;
template struct vec<2, int16, packed_mediump>;
template struct vec<2, int32, packed_mediump>;
template struct vec<2, int64, packed_mediump>;
template struct vec<2, float32, packed_mediump>;
template struct vec<2, float64, packed_mediump>;

template struct vec<2, uint8, packed_highp>;
template struct vec<2, uint16, packed_highp>;
template struct vec<2, uint32, packed_highp>;
template struct vec<2, uint64, packed_highp>;
template struct vec<2, int8, packed_highp>;
template struct vec<2, int16, packed_highp>;
template struct vec<2, int32, packed_highp>;
template struct vec<2, int64, packed_highp>;
template struct vec<2, float32, packed_highp>;
template struct vec<2, float64, packed_highp>;

// tvec3 type explicit instantiation
template struct vec<3, uint8, packed_lowp>;
template struct vec<3, uint16, packed_lowp>;
template struct vec<3, uint32, packed_lowp>;
template struct vec<3, uint64, packed_lowp>;
template struct vec<3, int8, packed_lowp>;
template struct vec<3, int16, packed_lowp>;
template struct vec<3, int32, packed_lowp>;
template struct vec<3, int64, packed_lowp>;
template struct vec<3, float32, packed_lowp>;
template struct vec<3, float64, packed_lowp>;

template struct vec<3, uint8, packed_mediump>;
template struct vec<3, uint16, packed_mediump>;
template struct vec<3, uint32, packed_mediump>;
template struct vec<3, uint64, packed_mediump>;
template struct vec<3, int8, packed_mediump>;
template struct vec<3, int16, packed_mediump>;
template struct vec<3, int32, packed_mediump>;
template struct vec<3, int64, packed_mediump>;
template struct vec<3, float32, packed_mediump>;
template struct vec<3, float64, packed_mediump>;

template struct vec<3, uint8, packed_highp>;
template struct vec<3, uint16, packed_highp>;
template struct vec<3, uint32, packed_highp>;
template struct vec<3, uint64, packed_highp>;
template struct vec<3, int8, packed_highp>;
template struct vec<3, int16, packed_highp>;
template struct vec<3, int32, packed_highp>;
template struct vec<3, int64, packed_highp>;
template struct vec<3, float32, packed_highp>;
template struct vec<3, float64, packed_highp>;

// tvec4 type explicit instantiation
template struct vec<4, uint8, packed_lowp>;
template struct vec<4, uint16, packed_lowp>;
template struct vec<4, uint32, packed_lowp>;
template struct vec<4, uint64, packed_lowp>;
template struct vec<4, int8, packed_lowp>;
template struct vec<4, int16, packed_lowp>;
template struct vec<4, int32, packed_lowp>;
template struct vec<4, int64, packed_lowp>;
template struct vec<4, float32, packed_lowp>;
template struct vec<4, float64, packed_lowp>;

template struct vec<4, uint8, packed_mediump>;
template struct vec<4, uint16, packed_mediump>;
template struct vec<4, uint32, packed_mediump>;
template struct vec<4, uint64, packed_mediump>;
template struct vec<4, int8, packed_mediump>;
template struct vec<4, int16, packed_mediump>;
template struct vec<4, int32, packed_mediump>;
template struct vec<4, int64, packed_mediump>;
template struct vec<4, float32, packed_mediump>;
template struct vec<4, float64, packed_mediump>;

template struct vec<4, uint8, packed_highp>;
template struct vec<4, uint16, packed_highp>;
template struct vec<4, uint32, packed_highp>;
template struct vec<4, uint64, packed_highp>;
template struct vec<4, int8, packed_highp>;
template struct vec<4, int16, packed_highp>;
template struct vec<4, int32, packed_highp>;
template struct vec<4, int64, packed_highp>;
template struct vec<4, float32, packed_highp>;
template struct vec<4, float64, packed_highp>;

// tmat2x2 type explicit instantiation
template struct mat<2, 2, float32, packed_lowp>;
template struct mat<2, 2, float64, packed_lowp>;

template struct mat<2, 2, float32, packed_mediump>;
template struct mat<2, 2, float64, packed_mediump>;

template struct mat<2, 2, float32, packed_highp>;
template struct mat<2, 2, float64, packed_highp>;

// tmat2x3 type explicit instantiation
template struct mat<2, 3, float32, packed_lowp>;
template struct mat<2, 3, float64, packed_lowp>;

template struct mat<2, 3, float32, packed_mediump>;
template struct mat<2, 3, float64, packed_mediump>;

template struct mat<2, 3, float32, packed_highp>;
template struct mat<2, 3, float64, packed_highp>;

// tmat2x4 type explicit instantiation
template struct mat<2, 4, float32, packed_lowp>;
template struct mat<2, 4, float64, packed_lowp>;

template struct mat<2, 4, float32, packed_mediump>;
template struct mat<2, 4, float64, packed_mediump>;

template struct mat<2, 4, float32, packed_highp>;
template struct mat<2, 4, float64, packed_highp>;

// tmat3x2 type explicit instantiation
template struct mat<3, 2, float32, packed_lowp>;
template struct mat<3, 2, float64, packed_lowp>;

template struct mat<3, 2, float32, packed_mediump>;
template struct mat<3, 2, float64, packed_mediump>;

template struct mat<3, 2, float32, packed_highp>;
template struct mat<3, 2, float64, packed_highp>;

// tmat3x3 type explicit instantiation
template struct mat<3, 3, float32, packed_lowp>;
template struct mat<3, 3, float64, packed_lowp>;

template struct mat<3, 3, float32, packed_mediump>;
template struct mat<3, 3, float64, packed_mediump>;

template struct mat<3, 3, float32, packed_highp>;
template struct mat<3, 3, float64, packed_highp>;

// tmat3x4 type explicit instantiation
template struct mat<3, 4, float32, packed_lowp>;
template struct mat<3, 4, float64, packed_lowp>;

template struct mat<3, 4, float32, packed_mediump>;
template struct mat<3, 4, float64, packed_mediump>;

template struct mat<3, 4, float32, packed_highp>;
template struct mat<3, 4, float64, packed_highp>;

// tmat4x2 type explicit instantiation
template struct mat<4, 2, float32, packed_lowp>;
template struct mat<4, 2, float64, packed_lowp>;

template struct mat<4, 2, float32, packed_mediump>;
template struct mat<4, 2, float64, packed_mediump>;

template struct mat<4, 2, float32, packed_highp>;
template struct mat<4, 2, float64, packed_highp>;

// tmat4x3 type explicit instantiation
template struct mat<4, 3, float32, packed_lowp>;
template struct mat<4, 3, float64, packed_lowp>;

template struct mat<4, 3, float32, packed_mediump>;
template struct mat<4, 3, float64, packed_mediump>;

template struct mat<4, 3, float32, packed_highp>;
template struct mat<4, 3, float64, packed_highp>;

// tmat4x4 type explicit instantiation
template struct mat<4, 4, float32, packed_lowp>;
template struct mat<4, 4, float64, packed_lowp>;

template struct mat<4, 4, float32, packed_mediump>;
template struct mat<4, 4, float64, packed_mediump>;

template struct mat<4, 4, float32, packed_highp>;
template struct mat<4, 4, float64, packed_highp>;

// tquat type explicit instantiation
template struct qua<float32, packed_lowp>;
template struct qua<float64, packed_lowp>;

template struct qua<float32, packed_mediump>;
template struct qua<float64, packed_mediump>;

template struct qua<float32, packed_highp>;
template struct qua<float64, packed_highp>;

//tdualquat type explicit instantiation
template struct tdualquat<float32, packed_lowp>;
template struct tdualquat<float64, packed_lowp>;

template struct tdualquat<float32, packed_mediump>;
template struct tdualquat<float64, packed_mediump>;

template struct tdualquat<float32, packed_highp>;
template struct tdualquat<float64, packed_highp>;

// tvec1 type explicit instantiation
template struct vec<1, uint8, aligned_lowp>;
template struct vec<1, uint16, aligned_lowp>;
template struct vec<1, uint32, aligned_lowp>;
template struct vec<1, uint64, aligned_lowp>;
template struct vec<1, int8, aligned_lowp>;
template struct vec<1, int16, aligned_lowp>;
template struct vec<1, int32, aligned_lowp>;
template struct vec<1, int64, aligned_lowp>;
template struct vec<1, float32, aligned_lowp>;
template struct vec<1, float64, aligned_lowp>;

template struct vec<1, uint8, aligned_mediump>;
template struct vec<1, uint16, aligned_mediump>;
template struct vec<1, uint32, aligned_mediump>;
template struct vec<1, uint64, aligned_mediump>;
template struct vec<1, int8, aligned_mediump>;
template struct vec<1, int16, aligned_mediump>;
template struct vec<1, int32, aligned_mediump>;
template struct vec<1, int64, aligned_mediump>;
template struct vec<1, float32, aligned_mediump>;
template struct vec<1, float64, aligned_mediump>;

template struct vec<1, uint8, aligned_highp>;
template struct vec<1, uint16, aligned_highp>;
template struct vec<1, uint32, aligned_highp>;
template struct vec<1, uint64, aligned_highp>;
template struct vec<1, int8, aligned_highp>;
template struct vec<1, int16, aligned_highp>;
template struct vec<1, int32, aligned_highp>;
template struct vec<1, int64, aligned_highp>;
template struct vec<1, float32, aligned_highp>;
template struct vec<1, float64, aligned_highp>;

// tvec2 type explicit instantiation
template struct vec<2, uint8, aligned_lowp>;
template struct vec<2, uint16, aligned_lowp>;
template struct vec<2, uint32, aligned_lowp>;
template struct vec<2, uint64, aligned_lowp>;
template struct vec<2, int8, aligned_lowp>;
template struct vec<2, int16, aligned_lowp>;
template struct vec<2, int32, aligned_lowp>;
template struct vec<2, int64, aligned_lowp>;
template struct vec<2, float32, aligned_lowp>;
template struct vec<2, float64, aligned_lowp>;

template struct vec<2, uint8, aligned_mediump>;
template struct vec<2, uint16, aligned_mediump>;
template struct vec<2, uint32, aligned_mediump>;
template struct vec<2, uint64, aligned_mediump>;
template struct vec<2, int8, aligned_mediump>;
template struct vec<2, int16, aligned_mediump>;
template struct vec<2, int32, aligned_mediump>;
template struct vec<2, int64, aligned_mediump>;
template struct vec<2, float32, aligned_mediump>;
template struct vec<2, float64, aligned_mediump>;

template struct vec<2, uint8, aligned_highp>;
template struct vec<2, uint16, aligned_highp>;
template struct vec<2, uint32, aligned_highp>;
template struct vec<2, uint64, aligned_highp>;
template struct vec<2, int8, aligned_highp>;
template struct vec<2, int16, aligned_highp>;
template struct vec<2, int32, aligned_highp>;
template struct vec<2, int64, aligned_highp>;
template struct vec<2, float32, aligned_highp>;
template struct vec<2, float64, aligned_highp>;

// tvec3 type explicit instantiation
template struct vec<3, uint8, aligned_lowp>;
template struct vec<3, uint16, aligned_lowp>;
template struct vec<3, uint32, aligned_lowp>;
template struct vec<3, uint64, aligned_lowp>;
template struct vec<3, int8, aligned_lowp>;
template struct vec<3, int16, aligned_lowp>;
template struct vec<3, int32, aligned_lowp>;
template struct vec<3, int64, aligned_lowp>;
template struct vec<3, float32, aligned_lowp>;
template struct vec<3, float64, aligned_lowp>;

template struct vec<3, uint8, aligned_mediump>;
template struct vec<3, uint16, aligned_mediump>;
template struct vec<3, uint32, aligned_mediump>;
template struct vec<3, uint64, aligned_mediump>;
template struct vec<3, int8, aligned_mediump>;
template struct vec<3, int16, aligned_mediump>;
template struct vec<3, int32, aligned_mediump>;
template struct vec<3, int64, aligned_mediump>;
template struct vec<3, float32, aligned_mediump>;
template struct vec<3, float64, aligned_mediump>;

template struct vec<3, uint8, aligned_highp>;
template struct vec<3, uint16, aligned_highp>;
template struct vec<3, uint32, aligned_highp>;
template struct vec<3, uint64, aligned_highp>;
template struct vec<3, int8, aligned_highp>;
template struct vec<3, int16, aligned_highp>;
template struct vec<3, int32, aligned_highp>;
template struct vec<3, int64, aligned_highp>;
template struct vec<3, float32, aligned_highp>;
template struct vec<3, float64, aligned_highp>;

// tvec4 type explicit instantiation
template struct vec<4, uint8, aligned_lowp>;
template struct vec<4, uint16, aligned_lowp>;
template struct vec<4, uint32, aligned_lowp>;
template struct vec<4, uint64, aligned_lowp>;
template struct vec<4, int8, aligned_lowp>;
template struct vec<4, int16, aligned_lowp>;
template struct vec<4, int32, aligned_lowp>;
template struct vec<4, int64, aligned_lowp>;
template struct vec<4, float32, aligned_lowp>;
template struct vec<4, float64, aligned_lowp>;

template struct vec<4, uint8, aligned_mediump>;
template struct vec<4, uint16, aligned_mediump>;
template struct vec<4, uint32, aligned_mediump>;
template struct vec<4, uint64, aligned_mediump>;
template struct vec<4, int8, aligned_mediump>;
template struct vec<4, int16, aligned_mediump>;
template struct vec<4, int32, aligned_mediump>;
template struct vec<4, int64, aligned_mediump>;
template struct vec<4, float32, aligned_mediump>;
template struct vec<4, float64, aligned_mediump>;

template struct vec<4, uint8, aligned_highp>;
template struct vec<4, uint16, aligned_highp>;
template struct vec<4, uint32, aligned_highp>;
template struct vec<4, uint64, aligned_highp>;
template struct vec<4, int8, aligned_highp>;
template struct vec<4, int16, aligned_highp>;
template struct vec<4, int32, aligned_highp>;
template struct vec<4, int64, aligned_highp>;
template struct vec<4, float32, aligned_highp>;
template struct vec<4, float64, aligned_highp>;

// tmat2x2 type explicit instantiation
template struct mat<2, 2, float32, aligned_lowp>;
template struct mat<2, 2, float64, aligned_lowp>;

template struct mat<2, 2, float32, aligned_mediump>;
template struct mat<2, 2, float64, aligned_mediump>;

template struct mat<2, 2, float32, aligned_highp>;
template struct mat<2, 2, float64, aligned_highp>;

// tmat2x3 type explicit instantiation
template struct mat<2, 3, float32, aligned_lowp>;
template struct mat<2, 3, float64, aligned_lowp>;

template struct mat<2, 3, float32, aligned_mediump>;
template struct mat<2, 3, float64, aligned_mediump>;

template struct mat<2, 3, float32, aligned_highp>;
template struct mat<2, 3, float64, aligned_highp>;

// tmat2x4 type explicit instantiation
template struct mat<2, 4, float32, aligned_lowp>;
template struct mat<2, 4, float64, aligned_lowp>;

template struct mat<2, 4, float32, aligned_mediump>;
template struct mat<2, 4, float64, aligned_mediump>;

template struct mat<2, 4, float32, aligned_highp>;
template struct mat<2, 4, float64, aligned_highp>;

// tmat3x2 type explicit instantiation
template struct mat<3, 2, float32, aligned_lowp>;
template struct mat<3, 2, float64, aligned_lowp>;

template struct mat<3, 2, float32, aligned_mediump>;
template struct mat<3, 2, float64, aligned_mediump>;

template struct mat<3, 2, float32, aligned_highp>;
template struct mat<3, 2, float64, aligned_highp>;

// tmat3x3 type explicit instantiation
template struct mat<3, 3, float32, aligned_lowp>;
template struct mat<3, 3, float64, aligned_lowp>;

template struct mat<3, 3, float32, aligned_mediump>;
template struct mat<3, 3, float64, aligned_mediump>;

template struct mat<3, 3, float32, aligned_highp>;
template struct mat<3, 3, float64, aligned_highp>;

// tmat3x4 type explicit instantiation
template struct mat<3, 4, float32, aligned_lowp>;
template struct mat<3, 4, float64, aligned_lowp>;

template struct mat<3, 4, float32, aligned_mediump>;
template struct mat<3, 4, float64, aligned_mediump>;

template struct mat<3, 4, float32, aligned_highp>;
template struct mat<3, 4, float64, aligned_highp>;

// tmat4x2 type explicit instantiation
template struct mat<4, 2, float32, aligned_lowp>;
template struct mat<4, 2, float64, aligned_lowp>;

template struct mat<4, 2, float32, aligned_mediump>;
template struct mat<4, 2, float64, aligned_mediump>;

template struct mat<4, 2, float32, aligned_highp>;
template struct mat<4, 2, float64, aligned_highp>;

// tmat4x3 type explicit instantiation
template struct mat<4, 3, float32, aligned_lowp>;
template struct mat<4, 3, float64, aligned_lowp>;

template struct mat<4, 3, float32, aligned_mediump>;
template struct mat<4, 3, float64, aligned_mediump>;

template struct mat<4, 3, float32, aligned_highp>;
template struct mat<4, 3, float64, aligned_highp>;

// tmat4x4 type explicit instantiation
template struct mat<4, 4, float32, aligned_lowp>;
template struct mat<4, 4, float64, aligned_lowp>;

template struct mat<4, 4, float32, aligned_mediump>;
template struct mat<4, 4, float64, aligned_mediump>;

template struct mat<4, 4, float32, aligned_highp>;
template struct mat<4, 4, float64, aligned_highp>;
/* FIXME
// tquat type explicit instantiation
template struct qua<float32, aligned_lowp>;
template struct qua<float64, aligned_lowp>;

template struct qua<float32, aligned_mediump>;
template struct qua<float64, aligned_mediump>;

template struct qua<float32, aligned_highp>;
template struct qua<float64, aligned_highp>;
*/
//tdualquat type explicit instantiation
template struct tdualquat<float32, aligned_lowp>;
template struct tdualquat<float64, aligned_lowp>;

template struct tdualquat<float32, aligned_mediump>;
template struct tdualquat<float64, aligned_mediump>;

template struct tdualquat<float32, aligned_highp>;
template struct tdualquat<float64, aligned_highp>;

}//namespace glm

