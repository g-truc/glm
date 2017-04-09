///////////////////////////////////////////////////////////////////////////////////
/// OpenGL Mathematics (glm.g-truc.net)
///
/// Copyright (c) 2005 - 2015 G-Truc Creation (www.g-truc.net)
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
///
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
///
/// Restrictions:
///		By making use of the Software for military purposes, you choose to make
///		a Bunny unhappy.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
/// THE SOFTWARE.
///
/// @ref gtx_associated_min_max
/// @file glm/gtx/angle.hpp
/// @date 2015-05-10
/// @author Miroslav Knejp
///
/// @see core (dependence)
///
/// @defgroup gtx_angle GLM_GTX_angle
/// @ingroup gtx
///
/// @brief Defines a dedicated type and operations for angles taking care of the radians/degrees issue and enforcing semantically sane usage.
///
/// Applying these types consistently can prevent many problems related to
/// conversions between degrees and radians. Furthermore it only supports
/// operations which preserve the angle's dimension (under the assumption it is
/// not dimensionless) allowing the compiler to detect misuses in equations. By
/// not manually converting between degrees and radians everywhere in your
/// program you can even gain some extra speed efficiency.
///
/// Where ever you deal with angles (regardless if class members or function
/// arguments) always use fangle/dangle and let it deal with the calculations
/// necessary for radians/degrees conversions. Never again use a plain `float`
/// in interfaces to represent angles or worry about these nuisances.
///
/// The angle types should be no bigger than the datatype used for
/// representation (if they are complain to your compiler vendor), are
/// as efficient in copy and assignment operations as a native float or double,
/// and can be safely passed by-value without fear of performance problems.
///
/// <glm/gtx/angle.hpp> needs to be included to use this functionality.
///
/// This extension also adds convenience overloads accepting angles instead of
/// plain floats to the following extensions for improved semantic checking:
/// - @ref gtc_matrix_transform
/// - @ref gtc_quaternion
/// - @ref gtx_fast_trigonometry
/// - @ref gtx_matrix_interpolation
/// - @ref gtx_matrix_transform_2d
/// - @ref gtx_rotate_normalized_axis
/// - @ref gtx_rotate_vector
/// - @ref gtx_transform
/// - @ref gtx_vector_angle
/// In order to use these overloads the respective extension header must be
/// included before <glm/gtx/angle.hpp> otherwise calling them fails to compile.
/// This avoids making this extension implicitly dependent on those listed above.
///////////////////////////////////////////////////////////////////////////////////

#pragma once

// Dependency:
#include "../glm.hpp"

#if(defined(GLM_MESSAGES) && !defined(GLM_EXT_INCLUDED))
#	pragma message("GLM: GLM_GTX_angle included")
#endif

namespace glm
{
	/// @addtogroup gtx_angle
	/// @{
	
	template<typename T, precision P = defaultp>
	class tangle;

	//////////////////////////////////////
	// Explicit converting factory functions
	
	/// Create an angle from radians
	template <typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR tangle<T> rad(T radians);
	/// Create an angle from degrees
	template <typename T>
	GLM_FUNC_DECL GLM_CONSTEXPR tangle<T> deg(T degrees);
	
	//////////////////////////////////////
	// Explicit converting value access
	
	/// Extract an angle's magnitude converted to radians
	template <typename T, precision P>
	GLM_FUNC_DECL GLM_CONSTEXPR T rad(tangle<T, P> angle);
	/// Extract an angle's magnitude converted to degrees
	template <typename T, precision P>
	GLM_FUNC_DECL GLM_CONSTEXPR T deg(tangle<T, P> angle);
	
	//////////////////////////////////////
	// Generic angle class defintion
	
	template<typename T, precision P>
	class tangle
	{
	public:
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'angle' only accepts floating-point types");
		
		typedef tangle<T, P> type;
		typedef T value_type;
		
		//////////////////////////////////////
		// Implicit basic constructors
		
		GLM_FUNC_DECL GLM_CONSTEXPR tangle();
		GLM_FUNC_DECL GLM_CONSTEXPR tangle(tangle<T, P> const & other);
		template <precision Q>
		GLM_FUNC_DECL GLM_CONSTEXPR tangle(tangle<T, Q> const & other);
		
		//////////////////////////////////////
		// Explicit basic constructors
		
		GLM_FUNC_DECL GLM_CONSTEXPR explicit tangle(ctor);
		
		//////////////////////////////////////
		// Assignment (compound) operators
		
		GLM_FUNC_DECL tvec4<T, P> & operator=(tangle<T, P> const & rhs);
		
		template <typename U>
		GLM_FUNC_DECL tangle<T, P> & operator=(tangle<U, P> const & rhs);
		template <typename U>
		GLM_FUNC_DECL tangle<T, P> & operator+=(tangle<U, P> const & rhs);
		template <typename U>
		GLM_FUNC_DECL tangle<T, P> & operator-=(tangle<U, P> const & rhs);
		template <typename U>
		GLM_FUNC_DECL tangle<T, P> & operator*=(U rhs);
		template <typename U>
		GLM_FUNC_DECL tangle<T, P> & operator/=(U rhs);
		
	private:
		friend GLM_CONSTEXPR tangle rad<T>(T radians);
		friend GLM_CONSTEXPR tangle deg<T>(T degrees);
		
		friend GLM_CONSTEXPR T rad<T, P>(tangle radians);
		friend GLM_CONSTEXPR T deg<T, P>(tangle degrees);
		
		GLM_FUNC_DECL GLM_CONSTEXPR tangle(T radians);
		
		T _radians;
	};
	
	typedef tangle<float> fangle; // angle is already taken :(
	typedef tangle<double> dangle;

	//////////////////////////////////////
	// Unary arithmetic operators
	
	template <typename T, precision P>
	GLM_FUNC_DECL GLM_CONSTEXPR tangle<T, P> operator+(tangle<T, P> angle);
	template <typename T, precision P>
	GLM_FUNC_DECL GLM_CONSTEXPR tangle<T, P> operator-(tangle<T, P> angle);

	//////////////////////////////////////
	// Binary arithmetic operators
	
	template <typename T, precision P>
	GLM_FUNC_DECL GLM_CONSTEXPR tangle<T, P> operator+(tangle<T, P> lhs, tangle<T, P> rhs);
	template <typename T, precision P>
	GLM_FUNC_DECL GLM_CONSTEXPR tangle<T, P> operator-(tangle<T, P> lhs, tangle<T, P> rhs);
	template <typename T, precision P>
	GLM_FUNC_DECL GLM_CONSTEXPR tangle<T, P> operator*(tangle<T, P> lhs, T rhs);
	template <typename T, precision P>
	GLM_FUNC_DECL GLM_CONSTEXPR tangle<T, P> operator*(T lhs, tangle<T, P> rhs);
	template <typename T, precision P>
	GLM_FUNC_DECL GLM_CONSTEXPR tangle<T, P> operator/(tangle<T, P> lhs, T rhs);
	template <typename T, precision P>
	GLM_FUNC_DECL GLM_CONSTEXPR T operator/(tangle<T, P> lhs, tangle<T, P> rhs);

	//////////////////////////////////////
	// Comparison operators
	
	template <typename T, precision P>
	GLM_FUNC_DECL GLM_CONSTEXPR bool operator==(tangle<T, P> lhs, tangle<T, P> rhs);
	template <typename T, precision P>
	GLM_FUNC_DECL GLM_CONSTEXPR bool operator!=(tangle<T, P> lhs, tangle<T, P> rhs);
	template <typename T, precision P>
	GLM_FUNC_DECL GLM_CONSTEXPR bool operator<=(tangle<T, P> lhs, tangle<T, P> rhs);
	template <typename T, precision P>
	GLM_FUNC_DECL GLM_CONSTEXPR bool operator>=(tangle<T, P> lhs, tangle<T, P> rhs);
	template <typename T, precision P>
	GLM_FUNC_DECL GLM_CONSTEXPR bool operator<(tangle<T, P> lhs, tangle<T, P> rhs);
	template <typename T, precision P>
	GLM_FUNC_DECL GLM_CONSTEXPR bool operator>(tangle<T, P> lhs, tangle<T, P> rhs);
	
	//////////////////////////////////////
	// Common functions
	
	template <typename T, precision P>
	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tangle<T, P> abs(tangle<T, P> arg);
	template <typename T, precision P>
	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tangle<T, P> clamp(tangle<T, P> x, tangle<T, P> minVal, tangle<T, P> maxVal);
	template <typename T, precision P>
	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tangle<T, P> max(tangle<T, P> lhs, tangle<T, P> rhs);
	template <typename T, precision P>
	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tangle<T, P> min(tangle<T, P> lhs, tangle<T, P> rhs);
	template <typename T, precision P, typename U>
	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tangle<T, P> mix(tangle<T, P> x, tangle<T, P> y, U a);
	template <typename T, precision P>
	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tangle<T, P> mix(tangle<T, P> x, tangle<T, P> y, bool a);
	template <typename T, precision P>
	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tangle<T, P> mod(tangle<T, P> lhs, tangle<T, P> rhs);
	template <typename T, precision P>
	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ T sign(tangle<T, P> arg);

	//////////////////////////////////////
	// Special angle functions
	
	/// Normalize an angle's representation so lies within the interval [0; 2pi).
	template <typename T, precision P>
	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tangle<T, P> normalize(tangle<T, P> arg);
	/// Compute the shortest distance between two *normalized* angles, which is always in the range [-pi; +pi].
	template <typename T, precision P>
	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tangle<T, P> distance(tangle<T, P> from, tangle<T, P> to);
	
	//////////////////////////////////////
	// Trigonometric functions
	
	template <typename T, precision P>
	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ T cos(tangle<T, P> arg);
	template <typename T, precision P>
	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ T sin(tangle<T, P> arg);
	template <typename T, precision P>
	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ T tan(tangle<T, P> arg);
	template <typename T>
	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tangle<T> atan2(T y, T x);
	template <typename T, precision P>
	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tangle<T, P> atan2(tvec2<T, P> const & v);
	// TODO: These conflict with existing GLM functions :(
//	template <typename T>
//	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tangle<T> acos(T arg);
//	template <typename T>
//	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tangle<T> asin(T arg);
//	template <typename T>
//	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tangle<T> atan(T arg);

	//////////////////////////////////////
	// GLM_GTC_matrix_transform
	
	template<typename T, precision P>
	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tmat4x4<T, P> infinitePerspective(tangle<T, P> fovy, T aspect, T near);
	template<typename T, precision P>
	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tmat4x4<T, P> perspective(tangle<T, P> fovy, T aspect, T near, T far);
	template<typename T, precision P>
	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tmat4x4<T, P> perspectiveFov(tangle<T, P> fov, T width, T height, T near, T far);
	template<typename T , precision P>
	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tmat4x4<T, P> rotate(tmat4x4<T, P> const & m, tangle<T, P> angle, tvec3<T, P> const & axis);
	template<typename T, precision P>
	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tmat4x4<T, P> tweakedInfinitePerspective(tangle<T, P> fovy, T aspect, T near);
	template<typename T, precision P>
	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tmat4x4<T, P> tweakedInfinitePerspective(tangle<T, P> fovy, T aspect, T near, T ep);
	
	//////////////////////////////////////
	// GLM_GTC_quaternion
	
	template<typename T, precision P>
	struct tquat;
	
	// TODO: Some conflict with existing GTC functions :(
//	template<typename T, precision P>
//	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tangle<T, P> angle(tquat<T, P> const & q);
	template<typename T , precision P>
	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tquat<T, P> angleAxis(tangle<T, P> angle, tvec3<T, P> const & axis);
//	template<typename T, precision P>
//	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tangle<T, P> pitch(tquat<T, P> const & q);
	template<typename T , precision P>
	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tquat<T, P> rotate(tquat< T, P > const & q, tangle<T, P> angle, tvec3<T, P> const & axis);
//	template<typename T, precision P>
//	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tangle<T, P> roll(tquat<T, P> const & q);
//	template<typename T, precision P>
//	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tangle<T, P> yaw(tquat<T, P> const & q);

	//////////////////////////////////////
	// GLM_GTX_fast_trigonometry
	
	// TODO: Some conflict with existing GTX functions :(
//	template<typename T>
//	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tangle<T> fastAcos(T x);
//	template<typename T>
//	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tangle<T> fastAsin(T x);
//	template<typename T>
//	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tangle<T> fastAtan(T y, T x);
//	template<typename T>
//	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tangle<T> fastAtan(T x);
	template<typename T, precision P>
	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ T fastCos(tangle<T, P> angle);
	template<typename T, precision P>
	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ T fastSin(tangle<T, P> angle);
	template<typename T, precision P>
	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ T fastTan(tangle<T, P> angle);

	//////////////////////////////////////
	// GLM_GTX_matrix_interpolation
	
	template<typename T, precision P>
	GLM_FUNC_DECL void axisAngle(tmat4x4<T, P> const & mat, tvec3<T, P> & axis, tangle<T, P> angle);
 	template<typename T, precision P>
	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tmat4x4<T, P> axisAngleMatrix(tvec3<T, P> const & axis, tangle<T, P> angle);

	//////////////////////////////////////
	// GLM_GTX_matrix_transform_2d
	
	template<typename T, precision P>
	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tmat3x3<T, P> rotate(tmat3x3<T, P> const & m, tangle<T, P> angle);
	
	//////////////////////////////////////
	// GLM_GTX_rotate_normalized_axis

	template<typename T, precision P>
	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tmat4x4<T, P> rotateNormalizedAxis(tmat4x4<T, P> const & m, tangle<T, P> angle, tvec3<T, P> const & axis);
	template<typename T, precision P>
	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tquat<T, P> rotateNormalizedAxis(tquat<T, P> const & q, tangle<T, P> angle, tvec3<T, P> const & axis);
	
	//////////////////////////////////////
	// GLM_GTX_rotate_vector
	
	template<typename T, precision P>
	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tvec2<T, P> rotate(tvec2<T, P> const & v, tangle<T, P> angle);
	template<typename T, precision P>
	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tvec3<T, P> rotate(tvec3<T, P> const & v, tangle<T, P> angle, tvec3<T, P> const & normal);
	template<typename T, precision P>
	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tvec4<T, P> rotate(tvec4<T, P> const & v, tangle<T, P> angle, tvec3<T, P> const & normal);
	template<typename T, precision P>
	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tvec3<T, P> rotateX(tvec3<T, P> const & v, tangle<T, P> angle);
	template<typename T, precision P>
	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tvec4<T, P> rotateX(tvec4<T, P> const & v, tangle<T, P> angle);
	template<typename T, precision P>
	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tvec3<T, P> rotateY(tvec3<T, P> const & v, tangle<T, P> angle);
	template<typename T, precision P>
	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tvec4<T, P> rotateY(tvec4<T, P> const & v, tangle<T, P> angle);
	template<typename T, precision P>
	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tvec3<T, P> rotateZ(tvec3<T, P> const & v, tangle<T, P> angle);
	template<typename T, precision P>
	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tvec4<T, P> rotateZ(tvec4<T, P> const & v, tangle<T, P> angle);
	
	//////////////////////////////////////
	// GLM_GTX_transform

	template<typename T, precision P>
	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tmat4x4< T, P > rotate(tangle<T, P> angle, tvec3< T, P > const & v);
	
	//////////////////////////////////////
	// GLM_GTX_vector_angle

	// TODO: These conflict with existing GTX functions :(
//	template<typename vecType>
//	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tangle<vecType::value_type> angle(vecType const & x, vecType const & y);
//	template<typename T, precision P>
//	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tangle<T> orientedAngle(tvec2<T, P> const & x, tvec2<T, P> const & y);
//	template<typename T, precision P>
//	GLM_FUNC_DECL /*GLM_CONSTEXPR*/ tangle<T> orientedAngle(tvec3<T, P> const & x, tvec3<T, P> const & y, tvec3<T, P> const &ref);
	
	/// @}
} // namespace glm

#include "angle.inl"
