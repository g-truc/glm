/// @ref gtx_quaternion
/// @file glm/gtx/quaternion.hpp
///
/// @see core (dependence)
/// @see gtx_extented_min_max (dependence)
///
/// @defgroup gtx_quaternion GLM_GTX_quaternion
/// @ingroup gtx
///
/// Include <glm/gtx/quaternion.hpp> to use the features of this extension.
///
/// Extented quaternion types and functions

#pragma once

// Dependency:
#include "../glm.hpp"
#include "../gtc/constants.hpp"
#include "../gtc/quaternion.hpp"
#include "../gtx/norm.hpp"

#include "../experimental.hpp"
#ifndef GLM_ENABLE_EXPERIMENTAL
#	error "GLM: GLM_GTX_quaternion is an experimental extension and may change in the future. Use #define GLM_ENABLE_EXPERIMENTAL before including it, if you really want to use it."
#endif

#if GLM_MESSAGES == GLM_MESSAGES_ENABLED && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_GTX_quaternion extension included")
#endif

namespace glm
{
	/// @addtogroup gtx_quaternion
	/// @{

	/// Create an identity quaternion.
	///
	/// @see gtx_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL tquat<T, Q> quat_identity();

	/// Compute a cross product between a quaternion and a vector.
	///
	/// @see gtx_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> cross(
		tquat<T, Q> const& q,
		vec<3, T, Q> const& v);

	//! Compute a cross product between a vector and a quaternion.
	///
	/// @see gtx_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> cross(
		vec<3, T, Q> const& v,
		tquat<T, Q> const& q);

	//! Compute a point on a path according squad equation. 
	//! q1 and q2 are control points; s1 and s2 are intermediate control points.
	///
	/// @see gtx_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL tquat<T, Q> squad(
		tquat<T, Q> const& q1,
		tquat<T, Q> const& q2,
		tquat<T, Q> const& s1,
		tquat<T, Q> const& s2,
		T const& h);

	//! Returns an intermediate control point for squad interpolation.
	///
	/// @see gtx_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL tquat<T, Q> intermediate(
		tquat<T, Q> const& prev,
		tquat<T, Q> const& curr,
		tquat<T, Q> const& next);

	//! Returns a exp of a quaternion.
	///
	/// @see gtx_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL tquat<T, Q> exp(
		tquat<T, Q> const& q);

	//! Returns a log of a quaternion.
	///
	/// @see gtx_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL tquat<T, Q> log(
		tquat<T, Q> const& q);

	/// Returns x raised to the y power.
	///
	/// @see gtx_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL tquat<T, Q> pow(
		tquat<T, Q> const& x,
		T const& y);

	//! Returns quarternion square root.
	///
	/// @see gtx_quaternion
	//template<typename T, qualifier Q>
	//tquat<T, Q> sqrt(
	//	tquat<T, Q> const& q);

	//! Rotates a 3 components vector by a quaternion.
	///
	/// @see gtx_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> rotate(
		tquat<T, Q> const& q,
		vec<3, T, Q> const& v);

	/// Rotates a 4 components vector by a quaternion.
	///
	/// @see gtx_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<4, T, Q> rotate(
		tquat<T, Q> const& q,
		vec<4, T, Q> const& v);

	/// Extract the real component of a quaternion.
	///
	/// @see gtx_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL T extractRealComponent(
		tquat<T, Q> const& q);

	/// Converts a quaternion to a 3 * 3 matrix.
	///
	/// @see gtx_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL mat<3, 3, T, Q> toMat3(
		tquat<T, Q> const& x){return mat3_cast(x);}

	/// Converts a quaternion to a 4 * 4 matrix.
	///
	/// @see gtx_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL mat<4, 4, T, Q> toMat4(
		tquat<T, Q> const& x){return mat4_cast(x);}

	/// Converts a 3 * 3 matrix to a quaternion.
	///
	/// @see gtx_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL tquat<T, Q> toQuat(
		mat<3, 3, T, Q> const& x){return quat_cast(x);}

	/// Converts a 4 * 4 matrix to a quaternion.
	///
	/// @see gtx_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL tquat<T, Q> toQuat(
		mat<4, 4, T, Q> const& x){return quat_cast(x);}

	/// Quaternion interpolation using the rotation short path.
	///
	/// @see gtx_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL tquat<T, Q> shortMix(
		tquat<T, Q> const& x,
		tquat<T, Q> const& y,
		T const& a);

	/// Quaternion normalized linear interpolation.
	///
	/// @see gtx_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL tquat<T, Q> fastMix(
		tquat<T, Q> const& x,
		tquat<T, Q> const& y,
		T const& a);

	/// Compute the rotation between two vectors.
	/// param orig vector, needs to be normalized
	/// param dest vector, needs to be normalized
	///
	/// @see gtx_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL tquat<T, Q> rotation(
		vec<3, T, Q> const& orig, 
		vec<3, T, Q> const& dest);

	/// Build a look at quaternion based on the default handedness.
	///
	/// @param direction Desired forward direction. Needs to be normalized.
	/// @param up Up vector, how the camera is oriented. Typically (0, 1, 0).
	template<typename T, qualifier Q>
	GLM_FUNC_DECL tquat<T, Q> quatLookAt(
		vec<3, T, Q> const& direction,
		vec<3, T, Q> const& up);

	/// Build a right-handed look at quaternion.
	///
	/// @param direction Desired forward direction onto which the -z-axis gets mapped. Needs to be normalized.
	/// @param up Up vector, how the camera is oriented. Typically (0, 1, 0).
	template<typename T, qualifier Q>
	GLM_FUNC_DECL tquat<T, Q> quatLookAtRH(
		vec<3, T, Q> const& direction,
		vec<3, T, Q> const& up);

	/// Build a left-handed look at quaternion.
	///
	/// @param direction Desired forward direction onto which the +z-axis gets mapped. Needs to be normalized.
	/// @param up Up vector, how the camera is oriented. Typically (0, 1, 0).
	template<typename T, qualifier Q>
	GLM_FUNC_DECL tquat<T, Q> quatLookAtLH(
		vec<3, T, Q> const& direction,
		vec<3, T, Q> const& up);
	
	/// Returns the squared length of x.
	/// 
	/// @see gtx_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL T length2(tquat<T, Q> const& q);

	/// @}
}//namespace glm

#include "quaternion.inl"
