/// @ref gtc_quaternion
/// @file glm/gtc/quaternion.hpp
///
/// @see core (dependence)
/// @see gtc_constants (dependence)
///
/// @defgroup gtc_quaternion GLM_GTC_quaternion
/// @ingroup gtc
///
/// Include <glm/gtc/quaternion.hpp> to use the features of this extension.
///
/// Defines a templated quaternion type and several quaternion operations.

#pragma once

// Dependency:
#include "../mat3x3.hpp"
#include "../mat4x4.hpp"
#include "../vec3.hpp"
#include "../vec4.hpp"
#include "../gtc/constants.hpp"

#if GLM_MESSAGES == GLM_MESSAGES_ENABLED && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_GTC_quaternion extension included")
#endif

namespace glm
{
	/// @addtogroup gtc_quaternion
	/// @{

	template<typename T, qualifier Q = defaultp>
	struct tquat
	{
		// -- Implementation detail --

		typedef tquat<T, Q> type;
		typedef T value_type;

		// -- Data --

#		if GLM_HAS_ALIGNED_TYPE
#			if GLM_COMPILER & GLM_COMPILER_GCC
#				pragma GCC diagnostic push
#				pragma GCC diagnostic ignored "-Wpedantic"
#			endif
#			if GLM_COMPILER & GLM_COMPILER_CLANG
#				pragma clang diagnostic push
#				pragma clang diagnostic ignored "-Wgnu-anonymous-struct"
#				pragma clang diagnostic ignored "-Wnested-anon-types"
#			endif
		
			union
			{
				struct { T x, y, z, w;};
				typename detail::storage<T, sizeof(T) * 4, detail::is_aligned<Q>::value>::type data;
			};
		
#			if GLM_COMPILER & GLM_COMPILER_CLANG
#				pragma clang diagnostic pop
#			endif
#			if GLM_COMPILER & GLM_COMPILER_GCC
#				pragma GCC diagnostic pop
#			endif
#		else
			T x, y, z, w;
#		endif

		// -- Component accesses --

		typedef length_t length_type;
		/// Return the count of components of a quaternion
		GLM_FUNC_DECL static GLM_CONSTEXPR length_type length(){return 4;}

		GLM_FUNC_DECL T & operator[](length_type i);
		GLM_FUNC_DECL T const& operator[](length_type i) const;

		// -- Implicit basic constructors --

		GLM_FUNC_DECL GLM_CONSTEXPR tquat() GLM_DEFAULT;
		GLM_FUNC_DECL GLM_CONSTEXPR tquat(tquat<T, Q> const& q) GLM_DEFAULT;
		template<qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR tquat(tquat<T, P> const& q);

		// -- Explicit basic constructors --

		GLM_FUNC_DECL GLM_CONSTEXPR tquat(T s, vec<3, T, Q> const& v);
		GLM_FUNC_DECL GLM_CONSTEXPR tquat(T w, T x, T y, T z);

		// -- Conversion constructors --

		template<typename U, qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR GLM_EXPLICIT tquat(tquat<U, P> const& q);

		/// Explicit conversion operators
#		if GLM_HAS_EXPLICIT_CONVERSION_OPERATORS
			GLM_FUNC_DECL explicit operator mat<3, 3, T, Q>();
			GLM_FUNC_DECL explicit operator mat<4, 4, T, Q>();
#		endif

		/// Create a quaternion from two normalized axis
		///
		/// @param u A first normalized axis
		/// @param v A second normalized axis
		/// @see gtc_quaternion
		/// @see http://lolengine.net/blog/2013/09/18/beautiful-maths-quaternion-from-vectors
		GLM_FUNC_DECL tquat(vec<3, T, Q> const& u, vec<3, T, Q> const& v);

		/// Build a quaternion from euler angles (pitch, yaw, roll), in radians.
		GLM_FUNC_DECL GLM_EXPLICIT tquat(vec<3, T, Q> const& eulerAngles);
		GLM_FUNC_DECL GLM_EXPLICIT tquat(mat<3, 3, T, Q> const& q);
		GLM_FUNC_DECL GLM_EXPLICIT tquat(mat<4, 4, T, Q> const& q);

		// -- Unary arithmetic operators --

		GLM_FUNC_DECL tquat<T, Q> & operator=(tquat<T, Q> const& q) GLM_DEFAULT;

		template<typename U>
		GLM_FUNC_DECL tquat<T, Q> & operator=(tquat<U, Q> const& q);
		template<typename U>
		GLM_FUNC_DECL tquat<T, Q> & operator+=(tquat<U, Q> const& q);
		template<typename U>
		GLM_FUNC_DECL tquat<T, Q> & operator-=(tquat<U, Q> const& q);
		template<typename U>
		GLM_FUNC_DECL tquat<T, Q> & operator*=(tquat<U, Q> const& q);
		template<typename U>
		GLM_FUNC_DECL tquat<T, Q> & operator*=(U s);
		template<typename U>
		GLM_FUNC_DECL tquat<T, Q> & operator/=(U s);
	};

	// -- Unary bit operators --

	template<typename T, qualifier Q>
	GLM_FUNC_DECL tquat<T, Q> operator+(tquat<T, Q> const& q);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL tquat<T, Q> operator-(tquat<T, Q> const& q);

	// -- Binary operators --

	template<typename T, qualifier Q>
	GLM_FUNC_DECL tquat<T, Q> operator+(tquat<T, Q> const& q, tquat<T, Q> const& p);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL tquat<T, Q> operator-(tquat<T, Q> const& q, tquat<T, Q> const& p);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL tquat<T, Q> operator*(tquat<T, Q> const& q, tquat<T, Q> const& p);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator*(tquat<T, Q> const& q, vec<3, T, Q> const& v);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator*(vec<3, T, Q> const& v, tquat<T, Q> const& q);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<4, T, Q> operator*(tquat<T, Q> const& q, vec<4, T, Q> const& v);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<4, T, Q> operator*(vec<4, T, Q> const& v, tquat<T, Q> const& q);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL tquat<T, Q> operator*(tquat<T, Q> const& q, T const& s);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL tquat<T, Q> operator*(T const& s, tquat<T, Q> const& q);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL tquat<T, Q> operator/(tquat<T, Q> const& q, T const& s);

	// -- Boolean operators --

	template<typename T, qualifier Q>
	GLM_FUNC_DECL bool operator==(tquat<T, Q> const& q1, tquat<T, Q> const& q2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL bool operator!=(tquat<T, Q> const& q1, tquat<T, Q> const& q2);

	/// Returns the length of the quaternion.
	/// 
	/// @tparam T Floating-point scalar types.
	///
	/// @see gtc_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL T length(tquat<T, Q> const& q);

	/// Returns the normalized quaternion.
	/// 
	/// @tparam T Floating-point scalar types.
	///
	/// @see gtc_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL tquat<T, Q> normalize(tquat<T, Q> const& q);
		
	/// Returns dot product of q1 and q2, i.e., q1[0] * q2[0] + q1[1] * q2[1] + ...
	/// 
	/// @tparam T Floating-point scalar types.
	///
	/// @see gtc_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL T dot(tquat<T, Q> const& x, tquat<T, Q> const& y);

	/// Spherical linear interpolation of two quaternions.
	/// The interpolation is oriented and the rotation is performed at constant speed.
	/// For short path spherical linear interpolation, use the slerp function.
	/// 
	/// @param x A quaternion
	/// @param y A quaternion
	/// @param a Interpolation factor. The interpolation is defined beyond the range [0, 1].
	/// @tparam T Floating-point scalar types.
	///
	/// @see - slerp(tquat<T, Q> const& x, tquat<T, Q> const& y, T const& a)
	/// @see gtc_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL tquat<T, Q> mix(tquat<T, Q> const& x, tquat<T, Q> const& y, T a);

	/// Linear interpolation of two quaternions.
	/// The interpolation is oriented.
	/// 
	/// @param x A quaternion
	/// @param y A quaternion
	/// @param a Interpolation factor. The interpolation is defined in the range [0, 1].
	/// @tparam T Floating-point scalar types.
	///
	/// @see gtc_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL tquat<T, Q> lerp(tquat<T, Q> const& x, tquat<T, Q> const& y, T a);

	/// Spherical linear interpolation of two quaternions.
	/// The interpolation always take the short path and the rotation is performed at constant speed.
	/// 
	/// @param x A quaternion
	/// @param y A quaternion
	/// @param a Interpolation factor. The interpolation is defined beyond the range [0, 1].
	/// @tparam T Floating-point scalar types.
	///
	/// @see gtc_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL tquat<T, Q> slerp(tquat<T, Q> const& x, tquat<T, Q> const& y, T a);

	/// Returns the q conjugate.
	/// 
	/// @tparam T Floating-point scalar types.
	///
	/// @see gtc_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL tquat<T, Q> conjugate(tquat<T, Q> const& q);

	/// Returns the q inverse.
	/// 
	/// @tparam T Floating-point scalar types.
	///
	/// @see gtc_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL tquat<T, Q> inverse(tquat<T, Q> const& q);

	/// Rotates a quaternion from a vector of 3 components axis and an angle.
	/// 
	/// @param q Source orientation
	/// @param angle Angle expressed in radians.
	/// @param axis Axis of the rotation
	/// @tparam T Floating-point scalar types.
	///
	/// @see gtc_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL tquat<T, Q> rotate(tquat<T, Q> const& q, T const& angle, vec<3, T, Q> const& axis);

	/// Returns euler angles, pitch as x, yaw as y, roll as z.
	/// The result is expressed in radians.
	///
	/// @tparam T Floating-point scalar types.
	///
	/// @see gtc_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> eulerAngles(tquat<T, Q> const& x);

	/// Returns roll value of euler angles expressed in radians.
	///
	/// @tparam T Floating-point scalar types.
	///
	/// @see gtc_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL T roll(tquat<T, Q> const& x);

	/// Returns pitch value of euler angles expressed in radians.
	///
	/// @tparam T Floating-point scalar types.
	///
	/// @see gtc_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL T pitch(tquat<T, Q> const& x);

	/// Returns yaw value of euler angles expressed in radians.
	///
	/// @tparam T Floating-point scalar types.
	///
	/// @see gtc_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL T yaw(tquat<T, Q> const& x);

	/// Converts a quaternion to a 3 * 3 matrix.
	/// 
	/// @tparam T Floating-point scalar types.
	///
	/// @see gtc_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL mat<3, 3, T, Q> mat3_cast(tquat<T, Q> const& x);

	/// Converts a quaternion to a 4 * 4 matrix.
	/// 
	/// @tparam T Floating-point scalar types.
	///
	/// @see gtc_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL mat<4, 4, T, Q> mat4_cast(tquat<T, Q> const& x);

	/// Converts a 3 * 3 matrix to a quaternion.
	/// 
	/// @tparam T Floating-point scalar types.
	///
	/// @see gtc_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL tquat<T, Q> quat_cast(mat<3, 3, T, Q> const& x);

	/// Converts a 4 * 4 matrix to a quaternion.
	/// 
	/// @tparam T Floating-point scalar types.
	///
	/// @see gtc_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL tquat<T, Q> quat_cast(mat<4, 4, T, Q> const& x);

	/// Returns the quaternion rotation angle.
	///
	/// @tparam T Floating-point scalar types.
	///
	/// @see gtc_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL T angle(tquat<T, Q> const& x);

	/// Returns the q rotation axis.
	///
	/// @tparam T Floating-point scalar types.
	///
	/// @see gtc_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> axis(tquat<T, Q> const& x);

	/// Build a quaternion from an angle and a normalized axis.
	///
	/// @param angle Angle expressed in radians.
	/// @param axis Axis of the quaternion, must be normalized.
	/// @tparam T Floating-point scalar types.
	///
	/// @see gtc_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL tquat<T, Q> angleAxis(T const& angle, vec<3, T, Q> const& axis);

	/// Returns the component-wise comparison result of x < y.
	/// 
	/// @tparam T Floating-point scalar types.
	///
	/// @see gtc_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<4, bool, Q> lessThan(tquat<T, Q> const& x, tquat<T, Q> const& y);

	/// Returns the component-wise comparison of result x <= y.
	///
	/// @tparam T Floating-point scalar types.
	///
	/// @see gtc_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<4, bool, Q> lessThanEqual(tquat<T, Q> const& x, tquat<T, Q> const& y);

	/// Returns the component-wise comparison of result x > y.
	///
	/// @tparam T Floating-point scalar types.
	///
	/// @see gtc_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<4, bool, Q> greaterThan(tquat<T, Q> const& x, tquat<T, Q> const& y);

	/// Returns the component-wise comparison of result x >= y.
	///
	/// @tparam T Floating-point scalar types.
	///
	/// @see gtc_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<4, bool, Q> greaterThanEqual(tquat<T, Q> const& x, tquat<T, Q> const& y);

	/// Returns the component-wise comparison of result x == y.
	///
	/// @tparam T Floating-point scalar types.
	///
	/// @see gtc_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<4, bool, Q> equal(tquat<T, Q> const& x, tquat<T, Q> const& y);

	/// Returns the component-wise comparison of result x != y.
	/// 
	/// @tparam T Floating-point scalar types.
	///
	/// @see gtc_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<4, bool, Q> notEqual(tquat<T, Q> const& x, tquat<T, Q> const& y);

	/// Returns true if x holds a NaN (not a number)
	/// representation in the underlying implementation's set of
	/// floating point representations. Returns false otherwise,
	/// including for implementations with no NaN
	/// representations.
	/// 
	/// /!\ When using compiler fast math, this function may fail.
	/// 
	/// @tparam T Floating-point scalar types.
	///
	/// @see gtc_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<4, bool, Q> isnan(tquat<T, Q> const& x);

	/// Returns true if x holds a positive infinity or negative
	/// infinity representation in the underlying implementation's
	/// set of floating point representations. Returns false
	/// otherwise, including for implementations with no infinity
	/// representations.
	/// 
	/// @tparam T Floating-point scalar types.
	///
	/// @see gtc_quaternion
	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<4, bool, Q> isinf(tquat<T, Q> const& x);

	/// @}
} //namespace glm

#include "quaternion.inl"
