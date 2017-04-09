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
/// @ref gtx_angle
/// @file glm/gtx/angle.inl
/// @date 2015-05-10
/// @author Miroslav Knejp
///////////////////////////////////////////////////////////////////////////////////

namespace glm
{
	//////////////////////////////////////
	// Implicit basic constructors
	
	template <typename T, precision P>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR tangle<T, P>::tangle()
#		ifndef GLM_FORCE_NO_CTOR_INIT
			: _radians(0)
#		endif
	{}
	
	template <typename T, precision P>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR tangle<T, P>::tangle(tangle<T, P> const & other)
		: _radians(other._radians)
	{}
	
	template <typename T, precision P>
	template <precision Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR tangle<T, P>::tangle(tangle<T, Q> const & other)
		: _radians(other._radians)
	{}
	
	//////////////////////////////////////
	// Explicit basic constructors
	
	template <typename T, precision P>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR tangle<T, P>::tangle(ctor)
	{}
	
	//////////////////////////////////////
	// Assignment (compound) operators
	
	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tvec4<T, P> & tangle<T, P>::operator=(tangle<T, P> const & rhs)
	{
		this->_radians = rhs._radians;
		return *this;
	}
	
	template <typename T, precision P>
	template <typename U>
	GLM_FUNC_QUALIFIER tangle<T, P> & tangle<T, P>::operator=(tangle<U, P> const & rhs)
	{
		this->_radians = static_cast<T>(rhs._radians);
		return *this;
	}

	template <typename T, precision P>
	template <typename U>
	GLM_FUNC_QUALIFIER tangle<T, P> & tangle<T, P>::operator+=(tangle<U, P> const & rhs)
	{
		this->_radians += static_cast<T>(rhs._radians);
		return *this;
	}

	template <typename T, precision P>
	template <typename U>
	GLM_FUNC_QUALIFIER tangle<T, P> & tangle<T, P>::operator-=(tangle<U, P> const & rhs)
	{
		this->_radians -= static_cast<T>(rhs._radians);
		return *this;
	}

	template <typename T, precision P>
	template <typename U>
	GLM_FUNC_QUALIFIER tangle<T, P> & tangle<T, P>::operator*=(U rhs)
	{
		this->_radians *= static_cast<T>(rhs);
		return *this;
	}

	template <typename T, precision P>
	template <typename U>
	GLM_FUNC_QUALIFIER tangle<T, P> & tangle<T, P>::operator/=(U rhs)
	{
		this->_radians /= static_cast<T>(rhs);
		return *this;
	}
	
	//////////////////////////////////////
	// Explicit converting factory functions
	
	template <typename T, precision P>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR tangle<T, P>::tangle(T radians)
		: _radians(radians)
	{}

	template <typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR tangle<T> rad(T radians)
	{
		return tangle<T>(radians);
	}
	
	template <typename T>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR tangle<T> deg(T degrees)
	{
		// glm::radians is not constexpr
		return tangle<T>(degrees * static_cast<T>(0.01745329251994329576923690768489));
	}
	
	//////////////////////////////////////
	// Explicit converting value access
	
	template <typename T, precision P>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR T rad(tangle<T, P> angle)
	{
		return angle._radians;
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR T deg(tangle<T, P> angle)
	{
		// glm::degrees is not constexpr
		return angle._radians * static_cast<T>(57.295779513082320876798154814105);
	}
	
	//////////////////////////////////////
	// Unary arithmetic operators
	
	template <typename T, precision P>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR tangle<T, P> operator+(tangle<T, P> angle)
	{
		return angle;
	}
	
	template <typename T, precision P>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR tangle<T, P> operator-(tangle<T, P> angle)
	{
		return rad(-rad(angle));
	}
	
	//////////////////////////////////////
	// Binary arithmetic operators
	
	template <typename T, precision P>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR tangle<T, P> operator+(tangle<T, P> lhs, tangle<T, P> rhs)
	{
		return rad(rad(lhs) + rad(rhs));
	}
	
	template <typename T, precision P>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR tangle<T, P> operator-(tangle<T, P> lhs, tangle<T, P> rhs)
	{
		return rad(rad(lhs) - rad(rhs));
	}
	
	template <typename T, precision P>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR tangle<T, P> operator*(tangle<T, P> lhs, T rhs)
	{
		return rad(rad(lhs) * rhs);
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR tangle<T, P> operator*(T lhs, tangle<T, P> rhs)
	{
		return rad(lhs * rad(rhs));
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR tangle<T, P> operator/(tangle<T, P> lhs, T rhs)
	{
		return rad(rad(lhs) / rhs);
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR T operator/(tangle<T, P> lhs, tangle<T, P> rhs)
	{
		return rad(lhs) / rad(rhs);
	}

	//////////////////////////////////////
	// Comparison operators
	
	template <typename T, precision P>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR bool operator==(tangle<T, P> lhs, tangle<T, P> rhs)
	{
		return rad(lhs) == rad(rhs);
	}
	
	template <typename T, precision P>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR bool operator!=(tangle<T, P> lhs, tangle<T, P> rhs)
	{
		return rad(lhs) != rad(rhs);
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR bool operator<=(tangle<T, P> lhs, tangle<T, P> rhs)
	{
		return rad(lhs) <= rad(rhs);
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR bool operator>=(tangle<T, P> lhs, tangle<T, P> rhs)
	{
		return rad(lhs) >= rad(rhs);
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR bool operator<(tangle<T, P> lhs, tangle<T, P> rhs)
	{
		return rad(lhs) < rad(rhs);
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR bool operator>(tangle<T, P> lhs, tangle<T, P> rhs)
	{
		return rad(lhs) > rad(rhs);
	}
	
	//////////////////////////////////////
	// Common functions
	
	template <typename T, precision P>
	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tangle<T, P> abs(tangle<T, P> arg)
	{
		return rad(abs(rad(arg)));
	}
	
	template <typename T, precision P>
	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tangle<T, P> clamp(tangle<T, P> x, tangle<T, P> minVal, tangle<T, P> maxVal)
	{
		return rad(clamp(rad(x), rad(minVal), rad(maxVal)));
	}
	
	template <typename T, precision P>
	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tangle<T, P> max(tangle<T, P> lhs, tangle<T, P> rhs)
	{
		return rad(max(rad(lhs), rad(rhs)));
	}
	
	template <typename T, precision P>
	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tangle<T, P> min(tangle<T, P> lhs, tangle<T, P> rhs)
	{
		return rad(min(rad(lhs), rad(rhs)));
	}

	template <typename T, precision P, typename U>
	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tangle<T, P> mix(tangle<T, P> x, tangle<T, P> y, U a)
	{
		return rad(mix(rad(x), rad(y), a));
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tangle<T, P> mix(tangle<T, P> x, tangle<T, P> y, bool a)
	{
		return a ? y : x;
	}
	
	template <typename T, precision P>
	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tangle<T, P> mod(tangle<T, P> lhs, tangle<T, P> rhs)
	{
		return rad(mod(rad(lhs), rad(rhs)));
	}
	
	template <typename T, precision P>
	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ T sign(tangle<T, P> arg)
	{
		return sign(rad(arg));
	}

	//////////////////////////////////////
	// Special angle functions
	
	template <typename T, precision P>
	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tangle<T, P> normalize(tangle<T, P> arg)
	{
		tangle<T, P> x = mod(arg, deg(static_cast<T>(360)));
		return x < deg(static_cast<T>(0)) ? x + deg(static_cast<T>(360)) : x;
	}
	
	template <typename T, precision P>
	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tangle<T, P> distance(tangle<T, P> from, tangle<T, P> to)
	{
		if(abs(to - from) > deg(static_cast<T>(180)))
		{
			return (from > to ? to + deg(static_cast<T>(360)) : to - deg(static_cast<T>(360))) - from;
		}
		else
		{
			return to - from;
		}
	}

	//////////////////////////////////////
	// Trigonometric functions
	
	template <typename T, precision P>
	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ T cos(tangle<T, P> arg)
	{
		return std::cos(rad(arg));
	}
	
	template <typename T, precision P>
	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ T sin(tangle<T, P> arg)
	{
		return std::sin(rad(arg));
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ T tan(tangle<T, P> arg)
	{
		return std::tan(rad(arg));
	}

	template <typename T>
	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tangle<T> atan2(T y, T x)
	{
		return rad(std::atan2(y, x));
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tangle<T, P> atan2(tvec2<T, P> const & v)
	{
		return rad(std::atan2(v.y, v.x));
	}

//	template <typename T>
//	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tangle<T> acos(T arg)
//	{
//		return rad(std::acos(arg));
//	}
//
//	template <typename T>
//	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tangle<T> asin(T arg)
//	{
//		return rad(std::asin(arg));
//	}
//
//	template <typename T>
//	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tangle<T> atan(T arg)
//	{
//		return rad(std::atan(arg));
//	}

	//////////////////////////////////////
	// GLM_GTC_matrix_transform
	
	template<typename T, precision P>
	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tmat4x4<T, P> infinitePerspective(tangle<T, P> fovy, T aspect, T near)
	{
		return infinitePerspective(rad(fovy), aspect, near);
	}

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tmat4x4<T, P> perspective(tangle<T, P> fovy, T aspect, T near, T far)
	{
		return perspective(rad(fovy), aspect, near, far);
	}
	
	template<typename T, precision P>
	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tmat4x4<T, P> perspectiveFov(tangle<T, P> fov, T width, T height, T near, T far)
	{
		return prespectiveFov(rad(fov), width, height, near, far);
	}

	template<typename T , precision P>
	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tmat4x4<T, P> rotate(tmat4x4<T, P> const & m, tangle<T, P> angle, tvec3<T, P> const & axis)
	{
		return rotate(m, rad(angle), axis);
	}
	
	template<typename T, precision P>
	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tmat4x4<T, P> tweakedInfinitePerspective(tangle<T, P> fovy, T aspect, T near)
	{
		return tweakedInfinitePerspective(rad(fovy), aspect, near);
	}
	
	template<typename T, precision P>
	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tmat4x4<T, P> tweakedInfinitePerspective(tangle<T, P> fovy, T aspect, T near, T ep)
	{
		return tweakedInfinitePerspective(rad(fovy), aspect, near, ep);
	}

	//////////////////////////////////////
	// GLM_GTC_quaternion
	
//	template<typename T, precision P>
//	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tangle<T, P> angle(tquat<T, P> const & q);
	
	template<typename T , precision P>
	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tquat<T, P> angleAxis(tangle<T, P> angle, tvec3<T, P> const & axis)
	{
		return angleAxis(rad(angle), axis);
	}
	
//	template<typename T, precision P>
//	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tangle<T, P> pitch(tquat<T, P> const & q);
	
	template<typename T , precision P>
	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tquat<T, P> rotate(tquat< T, P > const & q, tangle<T, P> angle, tvec3<T, P> const & axis)
	{
		return rotate(q, rad(angle), axis);
	}
	
//	template<typename T, precision P>
//	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tangle<T, P> roll(tquat<T, P> const & q);

//	template<typename T, precision P>
//	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tangle<T, P> yaw(tquat<T, P> const & q);

	//////////////////////////////////////
	// GLM_GTX_fast_trigonometry
	
//	template<typename T>
//	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tangle<T> fastAcos(T x);
	
//	template<typename T>
//	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tangle<T> fastAsin(T x);
	
//	template<typename T>
//	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tangle<T> fastAtan(T y, T x);
	
//	template<typename T>
//	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tangle<T> fastAtan(T x);
	
	template<typename T, precision P>
	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ T fastCos(tangle<T, P> angle)
	{
		return fastCos(rad(angle));
	}
	
	template<typename T, precision P>
	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ T fastSin(tangle<T, P> angle)
	{
		return fastSin(rad(angle));
	}
	
	template<typename T, precision P>
	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ T fastTan(tangle<T, P> angle)
	{
		return fastTan(rad(angle));
	}

	//////////////////////////////////////
	// GLM_GTX_matrix_interpolation
	
	template<typename T, precision P>
	GLM_FUNC_QUALIFIER void axisAngle(tmat4x4<T, P> const & mat, tvec3<T, P> & axis, tangle<T, P> angle)
	{
		return axisAngle(mat, axis, rad(angle));
	}
 
	template<typename T, precision P>
	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tmat4x4<T, P> axisAngleMatrix(tvec3<T, P> const & axis, tangle<T, P> angle)
	{
		return axisAngleMatrix(axis, rad(angle));
	}
	
	//////////////////////////////////////
	// GLM_GTX_matrix_transform_2d
	
	template<typename T, precision P>
	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tmat3x3<T, P> rotate(tmat3x3<T, P> const & m, tangle<T, P> angle)
	{
		return rotate(m, rad(angle));
	}
	
	//////////////////////////////////////
	// GLM_GTX_rotate_normalized_axis
	
	template<typename T, precision P>
	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tmat4x4<T, P> rotateNormalizedAxis(tmat4x4<T, P> const & m, tangle<T, P> angle, tvec3<T, P> const & axis)
	{
		return rotateNormalizedAxis(m, rad(angle), axis);
	}
 
	template<typename T, precision P>
	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tquat<T, P> rotateNormalizedAxis(tquat<T, P> const & q, tangle<T, P> angle, tvec3<T, P> const & axis)
	{
		return rotateNormalizedAxis(q, rad(angle), axis);
	}
	
	//////////////////////////////////////
	// GLM_GTX_rotate_vector
	
	template<typename T, precision P>
	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tvec2<T, P> rotate(tvec2<T, P> const & v, tangle<T, P> angle)
	{
		return rotate(v, rad(angle));
	}
 
	template<typename T, precision P>
	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tvec3<T, P> rotate(tvec3<T, P> const & v, tangle<T, P> angle, tvec3<T, P> const & normal)
	{
		return rotate(v, rad(angle), normal);
	}
 
	template<typename T, precision P>
	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tvec4<T, P> rotate(tvec4<T, P> const & v, tangle<T, P> angle, tvec3<T, P> const & normal)
	{
		return rotate(v, rad(angle), normal);
	}
 
	template<typename T, precision P>
	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tvec3<T, P> rotateX(tvec3<T, P> const & v, tangle<T, P> angle)
	{
		return rotateX(v, rad(angle));
	}
 
	template<typename T, precision P>
	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tvec4<T, P> rotateX(tvec4<T, P> const & v, tangle<T, P> angle)
	{
		return rotateX(v, rad(angle));
	}
 
	template<typename T, precision P>
	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tvec3<T, P> rotateY(tvec3<T, P> const & v, tangle<T, P> angle)
	{
		return rotateY(v, rad(angle));
	}
 
	template<typename T, precision P>
	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tvec4<T, P> rotateY(tvec4<T, P> const & v, tangle<T, P> angle)
	{
		return rotateY(v, rad(angle));
	}
 
	template<typename T, precision P>
	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tvec3<T, P> rotateZ(tvec3<T, P> const & v, tangle<T, P> angle)
	{
		return rotateZ(v, rad(angle));
	}
 
	template<typename T, precision P>
	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tvec4<T, P> rotateZ(tvec4<T, P> const & v, tangle<T, P> angle)
	{
		return rotateZ(v, rad(angle));
	}
	
	//////////////////////////////////////
	// GLM_GTX_transform
	
	template<typename T, precision P>
	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tmat4x4< T, P > rotate(tangle<T, P> angle, tvec3< T, P > const & v)
	{
		return rotate(rad(angle), v);
	}
	
	//////////////////////////////////////
	// GLM_GTX_vector_angle
	
//	template<typename vecType>
//	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tangle<vecType::value_type> angle(vecType const & x, vecType const & y);
	
//	template<typename T, precision P>
//	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tangle<T> orientedAngle(tvec2<T, P> const & x, tvec2<T, P> const & y);
	
//	template<typename T, precision P>
//	GLM_FUNC_QUALIFIER /*GLM_CONSTEXPR*/ tangle<T> orientedAngle(tvec3<T, P> const & x, tvec3<T, P> const & y, tvec3<T, P> const &ref);
}
