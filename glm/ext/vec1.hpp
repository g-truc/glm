/// @ref ext_vec1
/// @file glm/ext/vec1.hpp
///
/// @see core (dependence)
///
/// @defgroup ext_vec1 GLM_EXT_vec1
/// @ingroup ext
///
/// Include <glm/ext/vec1.hpp> to use the features of this extension.
///
/// Add vec1, ivec1, uvec1 and bvec1 types.

#pragma once

#include "../fwd.hpp"
#include "../detail/type_vec.hpp"
#if GLM_SWIZZLE == GLM_SWIZZLE_OPERATOR
#	include "../detail/_swizzle.hpp"
#elif GLM_SWIZZLE == GLM_SWIZZLE_FUNCTION
#	include "../detail/_swizzle_func.hpp"
#endif
#include <cstddef>

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_EXT_vec1 extension included")
#endif

namespace glm
{
	/// @addtogroup ext_vec1
	/// @{

	template<typename T, qualifier Q>
	struct vec<1, T, Q>
	{
		// -- Implementation detail --

		typedef T value_type;
		typedef vec<1, T, Q> type;
		typedef vec<1, bool, Q> bool_type;

		// -- Data --

#		if GLM_HAS_ANONYMOUS_STRUCT
			union
			{
				T x;
				T r;
				T s;

				typename detail::storage<1, T, detail::is_aligned<Q>::value>::type data;
/*
#				if GLM_SWIZZLE == GLM_SWIZZLE_OPERATOR
					_GLM_SWIZZLE1_2_MEMBERS(T, Q, x)
					_GLM_SWIZZLE1_2_MEMBERS(T, Q, r)
					_GLM_SWIZZLE1_2_MEMBERS(T, Q, s)
					_GLM_SWIZZLE1_3_MEMBERS(T, Q, x)
					_GLM_SWIZZLE1_3_MEMBERS(T, Q, r)
					_GLM_SWIZZLE1_3_MEMBERS(T, Q, s)
					_GLM_SWIZZLE1_4_MEMBERS(T, Q, x)
					_GLM_SWIZZLE1_4_MEMBERS(T, Q, r)
					_GLM_SWIZZLE1_4_MEMBERS(T, Q, s)
#				endif
*/
			};
#		else
			union {T x, r, s;};
/*
#			if GLM_SWIZZLE == GLM_SWIZZLE_FUNCTION
				GLM_SWIZZLE_GEN_VEC_FROM_VEC1(T, Q)
#			endif
*/
#		endif

		// -- Component accesses --

		/// Return the count of components of the vector
		typedef length_t length_type;
		GLM_FUNC_DECL static GLM_CONSTEXPR_CXX11 length_type length(){return 1;}

		GLM_FUNC_DECL T & operator[](length_type i);
		GLM_FUNC_DECL GLM_CONSTEXPR_CXX14 T const& operator[](length_type i) const;

		// -- Implicit basic constructors --

		GLM_FUNC_DECL GLM_CONSTEXPR_CXX11 vec() GLM_DEFAULT_CTOR;
		GLM_FUNC_DECL GLM_CONSTEXPR_CXX11 vec(vec const& v) GLM_DEFAULT;
		template<qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR_CXX11 vec(vec<1, T, P> const& v);

		// -- Explicit basic constructors --

		GLM_FUNC_DECL GLM_CONSTEXPR_CXX11 explicit vec(T scalar);

		// -- Conversion vector constructors --

		/// Explicit conversions (From section 5.4.1 Conversion and scalar constructors of GLSL 1.30.08 specification)
		template<typename U, qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR_CXX11 GLM_EXPLICIT vec(vec<2, U, P> const& v);
		/// Explicit conversions (From section 5.4.1 Conversion and scalar constructors of GLSL 1.30.08 specification)
		template<typename U, qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR_CXX11 GLM_EXPLICIT vec(vec<3, U, P> const& v);
		/// Explicit conversions (From section 5.4.1 Conversion and scalar constructors of GLSL 1.30.08 specification)
		template<typename U, qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR_CXX11 GLM_EXPLICIT vec(vec<4, U, P> const& v);

		/// Explicit conversions (From section 5.4.1 Conversion and scalar constructors of GLSL 1.30.08 specification)
		template<typename U, qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR_CXX11 GLM_EXPLICIT vec(vec<1, U, P> const& v);

		// -- Swizzle constructors --
/*
#		if GLM_SWIZZLE == GLM_SWIZZLE_OPERATOR
			template<int E0>
			GLM_FUNC_DECL tvec(detail::_swizzle<1, T, Q, E0, -1,-2,-3> const& that)
			{
				*this = that();
			}
#		endif//GLM_SWIZZLE == GLM_SWIZZLE_OPERATOR
*/
		// -- Unary arithmetic operators --

		GLM_FUNC_DECL vec & operator=(vec const& v);

		template<typename U>
		GLM_FUNC_DECL vec & operator=(vec<1, U, Q> const& v);
		template<typename U>
		GLM_FUNC_DECL vec & operator+=(U scalar);
		template<typename U>
		GLM_FUNC_DECL vec & operator+=(vec<1, U, Q> const& v);
		template<typename U>
		GLM_FUNC_DECL vec & operator-=(U scalar);
		template<typename U>
		GLM_FUNC_DECL vec & operator-=(vec<1, U, Q> const& v);
		template<typename U>
		GLM_FUNC_DECL vec & operator*=(U scalar);
		template<typename U>
		GLM_FUNC_DECL vec & operator*=(vec<1, U, Q> const& v);
		template<typename U>
		GLM_FUNC_DECL vec & operator/=(U scalar);
		template<typename U>
		GLM_FUNC_DECL vec & operator/=(vec<1, U, Q> const& v);

		// -- Increment and decrement operators --

		GLM_FUNC_DECL vec & operator++();
		GLM_FUNC_DECL vec & operator--();
		GLM_FUNC_DECL vec operator++(int);
		GLM_FUNC_DECL vec operator--(int);

		// -- Unary bit operators --

		template<typename U>
		GLM_FUNC_DECL vec & operator%=(U scalar);
		template<typename U>
		GLM_FUNC_DECL vec & operator%=(vec<1, U, Q> const& v);
		template<typename U>
		GLM_FUNC_DECL vec & operator&=(U scalar);
		template<typename U>
		GLM_FUNC_DECL vec & operator&=(vec<1, U, Q> const& v);
		template<typename U>
		GLM_FUNC_DECL vec & operator|=(U scalar);
		template<typename U>
		GLM_FUNC_DECL vec & operator|=(vec<1, U, Q> const& v);
		template<typename U>
		GLM_FUNC_DECL vec & operator^=(U scalar);
		template<typename U>
		GLM_FUNC_DECL vec & operator^=(vec<1, U, Q> const& v);
		template<typename U>
		GLM_FUNC_DECL vec & operator<<=(U scalar);
		template<typename U>
		GLM_FUNC_DECL vec & operator<<=(vec<1, U, Q> const& v);
		template<typename U>
		GLM_FUNC_DECL vec & operator>>=(U scalar);
		template<typename U>
		GLM_FUNC_DECL vec & operator>>=(vec<1, U, Q> const& v);
	};

	// -- Unary operators --

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<1, T, Q> operator+(vec<1, T, Q> const& v);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<1, T, Q> operator-(vec<1, T, Q> const& v);

	// -- Binary operators --

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<1, T, Q> operator+(vec<1, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<1, T, Q> operator+(T scalar, vec<1, T, Q> const& v);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<1, T, Q> operator+(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<1, T, Q> operator-(vec<1, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<1, T, Q> operator-(T scalar, vec<1, T, Q> const& v);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<1, T, Q> operator-(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<1, T, Q> operator*(vec<1, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<1, T, Q> operator*(T scalar, vec<1, T, Q> const& v);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<1, T, Q> operator*(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<1, T, Q> operator/(vec<1, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<1, T, Q> operator/(T scalar, vec<1, T, Q> const& v);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<1, T, Q> operator/(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<1, T, Q> operator%(vec<1, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<1, T, Q> operator%(T scalar, vec<1, T, Q> const& v);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<1, T, Q> operator%(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<1, T, Q> operator&(vec<1, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<1, T, Q> operator&(T scalar, vec<1, T, Q> const& v);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<1, T, Q> operator&(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<1, T, Q> operator|(vec<1, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<1, T, Q> operator|(T scalar, vec<1, T, Q> const& v);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<1, T, Q> operator|(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<1, T, Q> operator^(vec<1, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<1, T, Q> operator^(T scalar, vec<1, T, Q> const& v);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<1, T, Q> operator^(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<1, T, Q> operator<<(vec<1, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<1, T, Q> operator<<(T scalar, vec<1, T, Q> const& v);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<1, T, Q> operator<<(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<1, T, Q> operator>>(vec<1, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<1, T, Q> operator>>(T scalar, vec<1, T, Q> const& v);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<1, T, Q> operator>>(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<1, T, Q> operator~(vec<1, T, Q> const& v);

	// -- Boolean operators --

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR_CXX14 bool operator==(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR_CXX14 bool operator!=(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2);

	template<qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR_CXX14 vec<1, bool, Q> operator&&(vec<1, bool, Q> const& v1, vec<1, bool, Q> const& v2);

	template<qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR_CXX14 vec<1, bool, Q> operator||(vec<1, bool, Q> const& v1, vec<1, bool, Q> const& v2);

	/// 1 component vector of single-precision floating-point numbers using high precision arithmetic in term of ULPs.
	///
	/// @see ext_vec1
	typedef vec<1, float, highp>		highp_vec1;

	/// 1 component vector of single-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	///
	/// @see ext_vec1
	typedef vec<1, float, mediump>		mediump_vec1;

	/// 1 component vector of single-precision floating-point numbers using low precision arithmetic in term of ULPs.
	///
	/// @see ext_vec1
	typedef vec<1, float, lowp>			lowp_vec1;

	/// 1 component vector of double-precision floating-point numbers using high precision arithmetic in term of ULPs.
	///
	/// @see ext_vec1
	typedef vec<1, double, highp>		highp_dvec1;

	/// 1 component vector of double-precision floating-point numbers using medium precision arithmetic in term of ULPs.
	///
	/// @see ext_vec1
	typedef vec<1, double, mediump>		mediump_dvec1;

	/// 1 component vector of double-precision floating-point numbers using low precision arithmetic in term of ULPs.
	///
	/// @see ext_vec1
	typedef vec<1, double, lowp>		lowp_dvec1;

	/// 1 component vector of signed integer numbers.
	///
	/// @see ext_vec1
	typedef vec<1, int, highp>			highp_ivec1;

	/// 1 component vector of signed integer numbers.
	///
	/// @see ext_vec1
	typedef vec<1, int, mediump>		mediump_ivec1;

	/// 1 component vector of signed integer numbers.
	///
	/// @see ext_vec1
	typedef vec<1, int, lowp>			lowp_ivec1;

	/// 1 component vector of unsigned integer numbers.
	///
	/// @see ext_vec1
	typedef vec<1, uint, highp>			highp_uvec1;

	/// 1 component vector of unsigned integer numbers.
	///
	/// @see ext_vec1
	typedef vec<1, uint, mediump>		mediump_uvec1;

	/// 1 component vector of unsigned integer numbers.
	///
	/// @see ext_vec1
	typedef vec<1, uint, lowp>			lowp_uvec1;

	/// 1 component vector of bool values.
	///
	/// @see ext_vec1
	typedef vec<1, bool, highp>			highp_bvec1;

	/// 1 component vector of bool values.
	///
	/// @see ext_vec1
	typedef vec<1, bool, mediump>		mediump_bvec1;

	/// 1 component vector of bool values.
	///
	/// @see ext_vec1
	typedef vec<1, bool, lowp>			lowp_bvec1;

#if GLM_HAS_TEMPLATE_ALIASES
	template <typename T, qualifier Q = defaultp> using tvec1 = vec<1, T, Q>;
#endif//GLM_HAS_TEMPLATE_ALIASES

	//////////////////////////
	// vec1 definition

#if(defined(GLM_PRECISION_HIGHP_BOOL))
	typedef highp_bvec1				bvec1;
#elif(defined(GLM_PRECISION_MEDIUMP_BOOL))
	typedef mediump_bvec1			bvec1;
#elif(defined(GLM_PRECISION_LOWP_BOOL))
	typedef lowp_bvec1				bvec1;
#else
	/// 1 component vector of boolean.
	/// @see gtc_vec1 extension.
	typedef highp_bvec1				bvec1;
#endif//GLM_PRECISION

#if(defined(GLM_PRECISION_HIGHP_FLOAT))
	typedef highp_vec1				vec1;
#elif(defined(GLM_PRECISION_MEDIUMP_FLOAT))
	typedef mediump_vec1			vec1;
#elif(defined(GLM_PRECISION_LOWP_FLOAT))
	typedef lowp_vec1				vec1;
#else
	/// 1 component vector of floating-point numbers.
	/// @see gtc_vec1 extension.
	typedef highp_vec1				vec1;
#endif//GLM_PRECISION

#if(defined(GLM_PRECISION_HIGHP_DOUBLE))
	typedef highp_dvec1				dvec1;
#elif(defined(GLM_PRECISION_MEDIUMP_DOUBLE))
	typedef mediump_dvec1			dvec1;
#elif(defined(GLM_PRECISION_LOWP_DOUBLE))
	typedef lowp_dvec1				dvec1;
#else
	/// 1 component vector of floating-point numbers.
	/// @see gtc_vec1 extension.
	typedef highp_dvec1				dvec1;
#endif//GLM_PRECISION

#if(defined(GLM_PRECISION_HIGHP_INT))
	typedef highp_ivec1			ivec1;
#elif(defined(GLM_PRECISION_MEDIUMP_INT))
	typedef mediump_ivec1		ivec1;
#elif(defined(GLM_PRECISION_LOWP_INT))
	typedef lowp_ivec1			ivec1;
#else
	/// 1 component vector of signed integer numbers.
	/// @see gtc_vec1 extension.
	typedef highp_ivec1			ivec1;
#endif//GLM_PRECISION

#if(defined(GLM_PRECISION_HIGHP_UINT))
	typedef highp_uvec1			uvec1;
#elif(defined(GLM_PRECISION_MEDIUMP_UINT))
	typedef mediump_uvec1		uvec1;
#elif(defined(GLM_PRECISION_LOWP_UINT))
	typedef lowp_uvec1			uvec1;
#else
	/// 1 component vector of unsigned integer numbers.
	/// @see gtc_vec1 extension.
	typedef highp_uvec1			uvec1;
#endif//GLM_PRECISION

	/// @}
}//namespace glm

#ifndef GLM_EXTERNAL_TEMPLATE
#include "../detail/type_vec1.inl"
#endif//GLM_EXTERNAL_TEMPLATE
