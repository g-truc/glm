/// @ref core
/// @file glm/detail/type_vec1.hpp

#pragma once

#include "../fwd.hpp"
#include "type_vec.hpp"
#ifdef GLM_SWIZZLE
#	if GLM_HAS_UNRESTRICTED_UNIONS
#		include "_swizzle.hpp"
#	else
#		include "_swizzle_func.hpp"
#	endif
#endif //GLM_SWIZZLE
#include <cstddef>

namespace glm
{
	template <typename T, precision P = defaultp>
	struct tvec1
	{
		// -- Implementation detail --

		typedef tvec1<T, P> type;
		typedef tvec1<bool, P> bool_type;
		typedef T value_type;

		// -- Data --

#		if GLM_HAS_UNRESTRICTED_UNIONS
			union
			{
				T x;
				T r;
				T s;
/*
#				ifdef GLM_SWIZZLE
					_GLM_SWIZZLE1_2_MEMBERS(T, P, tvec2, x)
					_GLM_SWIZZLE1_2_MEMBERS(T, P, tvec2, r)
					_GLM_SWIZZLE1_2_MEMBERS(T, P, tvec2, s)
					_GLM_SWIZZLE1_3_MEMBERS(T, P, tvec3, x)
					_GLM_SWIZZLE1_3_MEMBERS(T, P, tvec3, r)
					_GLM_SWIZZLE1_3_MEMBERS(T, P, tvec3, s)
					_GLM_SWIZZLE1_4_MEMBERS(T, P, tvec4, x)
					_GLM_SWIZZLE1_4_MEMBERS(T, P, tvec4, r)
					_GLM_SWIZZLE1_4_MEMBERS(T, P, tvec4, s)
#				endif//GLM_SWIZZLE*/
			};
#		else
			union {T x, r, s;};
/*
#			ifdef GLM_SWIZZLE
				GLM_SWIZZLE_GEN_VEC_FROM_VEC1(T, P, tvec2, tvec2, tvec3, tvec4)
#			endif//GLM_SWIZZLE*/
#		endif

		// -- Component accesses --

		/// Return the count of components of the vector
		typedef length_t length_type;
		GLM_FUNC_DECL GLM_CONSTEXPR length_type length() const;

		GLM_FUNC_DECL T & operator[](length_type i);
		GLM_FUNC_DECL T const & operator[](length_type i) const;

		// -- Implicit basic constructors --

		GLM_FUNC_DECL GLM_CONSTEXPR tvec1() GLM_DEFAULT_CTOR;
		GLM_FUNC_DECL GLM_CONSTEXPR tvec1(tvec1<T, P> const & v) GLM_DEFAULT;
		template <precision Q>
		GLM_FUNC_DECL GLM_CONSTEXPR tvec1(tvec1<T, Q> const & v);

		// -- Explicit basic constructors --

		GLM_FUNC_DECL GLM_CONSTEXPR_CTOR explicit tvec1(ctor);
		GLM_FUNC_DECL GLM_CONSTEXPR explicit tvec1(T scalar);

		// -- Conversion vector constructors --

		/// Explicit conversions (From section 5.4.1 Conversion and scalar constructors of GLSL 1.30.08 specification)
		template <typename U, precision Q>
		GLM_FUNC_DECL GLM_CONSTEXPR GLM_EXPLICIT tvec1(tvec2<U, Q> const & v);
		/// Explicit conversions (From section 5.4.1 Conversion and scalar constructors of GLSL 1.30.08 specification)
		template <typename U, precision Q>
		GLM_FUNC_DECL GLM_CONSTEXPR GLM_EXPLICIT tvec1(tvec3<U, Q> const & v);
		/// Explicit conversions (From section 5.4.1 Conversion and scalar constructors of GLSL 1.30.08 specification)
		template <typename U, precision Q>
		GLM_FUNC_DECL GLM_CONSTEXPR GLM_EXPLICIT tvec1(tvec4<U, Q> const & v);

		/// Explicit conversions (From section 5.4.1 Conversion and scalar constructors of GLSL 1.30.08 specification)
		template <typename U, precision Q>
		GLM_FUNC_DECL GLM_CONSTEXPR GLM_EXPLICIT tvec1(tvec1<U, Q> const & v);

		// -- Swizzle constructors --
/*
#		if(GLM_HAS_UNRESTRICTED_UNIONS && defined(GLM_SWIZZLE))
			template <int E0>
			GLM_FUNC_DECL tvec1(detail::_swizzle<1, T, P, tvec1, E0, -1,-2,-3> const & that)
			{
				*this = that();
			}
#		endif//(GLM_HAS_UNRESTRICTED_UNIONS && defined(GLM_SWIZZLE))
*/
		// -- Unary arithmetic operators --

		GLM_FUNC_DECL tvec1<T, P> & operator=(tvec1<T, P> const & v) GLM_DEFAULT;

		template <typename U>
		GLM_FUNC_DECL tvec1<T, P> & operator=(tvec1<U, P> const & v);
		template <typename U>
		GLM_FUNC_DECL tvec1<T, P> & operator+=(U scalar);
		template <typename U>
		GLM_FUNC_DECL tvec1<T, P> & operator+=(tvec1<U, P> const & v);
		template <typename U>
		GLM_FUNC_DECL tvec1<T, P> & operator-=(U scalar);
		template <typename U>
		GLM_FUNC_DECL tvec1<T, P> & operator-=(tvec1<U, P> const & v);
		template <typename U>
		GLM_FUNC_DECL tvec1<T, P> & operator*=(U scalar);
		template <typename U>
		GLM_FUNC_DECL tvec1<T, P> & operator*=(tvec1<U, P> const & v);
		template <typename U>
		GLM_FUNC_DECL tvec1<T, P> & operator/=(U scalar);
		template <typename U>
		GLM_FUNC_DECL tvec1<T, P> & operator/=(tvec1<U, P> const & v);

		// -- Increment and decrement operators --

		GLM_FUNC_DECL tvec1<T, P> & operator++();
		GLM_FUNC_DECL tvec1<T, P> & operator--();
		GLM_FUNC_DECL tvec1<T, P> operator++(int);
		GLM_FUNC_DECL tvec1<T, P> operator--(int);

		// -- Unary bit operators --

		template <typename U>
		GLM_FUNC_DECL tvec1<T, P> & operator%=(U scalar);
		template <typename U>
		GLM_FUNC_DECL tvec1<T, P> & operator%=(tvec1<U, P> const & v);
		template <typename U>
		GLM_FUNC_DECL tvec1<T, P> & operator&=(U scalar);
		template <typename U>
		GLM_FUNC_DECL tvec1<T, P> & operator&=(tvec1<U, P> const & v);
		template <typename U>
		GLM_FUNC_DECL tvec1<T, P> & operator|=(U scalar);
		template <typename U>
		GLM_FUNC_DECL tvec1<T, P> & operator|=(tvec1<U, P> const & v);
		template <typename U>
		GLM_FUNC_DECL tvec1<T, P> & operator^=(U scalar);
		template <typename U>
		GLM_FUNC_DECL tvec1<T, P> & operator^=(tvec1<U, P> const & v);
		template <typename U>
		GLM_FUNC_DECL tvec1<T, P> & operator<<=(U scalar);
		template <typename U>
		GLM_FUNC_DECL tvec1<T, P> & operator<<=(tvec1<U, P> const & v);
		template <typename U>
		GLM_FUNC_DECL tvec1<T, P> & operator>>=(U scalar);
		template <typename U>
		GLM_FUNC_DECL tvec1<T, P> & operator>>=(tvec1<U, P> const & v);
	};

	// -- Unary operators --

	template <typename T, precision P>
	GLM_FUNC_DECL tvec1<T, P> operator+(tvec1<T, P> const & v);

	template <typename T, precision P>
	GLM_FUNC_DECL tvec1<T, P> operator-(tvec1<T, P> const & v);

	// -- Binary operators --

	template <typename T, precision P>
	GLM_FUNC_DECL tvec1<T, P> operator+(tvec1<T, P> const & v, T scalar);

	template <typename T, precision P>
	GLM_FUNC_DECL tvec1<T, P> operator+(T scalar, tvec1<T, P> const & v);

	template <typename T, precision P>
	GLM_FUNC_DECL tvec1<T, P> operator+(tvec1<T, P> const & v1, tvec1<T, P> const & v2);

	template <typename T, precision P>
	GLM_FUNC_DECL tvec1<T, P> operator-(tvec1<T, P> const & v, T scalar);

	template <typename T, precision P>
	GLM_FUNC_DECL tvec1<T, P> operator-(T scalar, tvec1<T, P> const & v);

	template <typename T, precision P>
	GLM_FUNC_DECL tvec1<T, P> operator-	(tvec1<T, P> const & v1, tvec1<T, P> const & v2);

	template <typename T, precision P>
	GLM_FUNC_DECL tvec1<T, P> operator*(tvec1<T, P> const & v, T scalar);

	template <typename T, precision P>
	GLM_FUNC_DECL tvec1<T, P> operator*(T scalar, tvec1<T, P> const & v);

	template <typename T, precision P>
	GLM_FUNC_DECL tvec1<T, P> operator*(tvec1<T, P> const & v1, tvec1<T, P> const & v2);

	template <typename T, precision P>
	GLM_FUNC_DECL tvec1<T, P> operator/(tvec1<T, P> const & v, T scalar);

	template <typename T, precision P>
	GLM_FUNC_DECL tvec1<T, P> operator/(T scalar, tvec1<T, P> const & v);

	template <typename T, precision P>
	GLM_FUNC_DECL tvec1<T, P> operator/(tvec1<T, P> const & v1, tvec1<T, P> const & v2);

	template <typename T, precision P>
	GLM_FUNC_DECL tvec1<T, P> operator%(tvec1<T, P> const & v, T scalar);

	template <typename T, precision P>
	GLM_FUNC_DECL tvec1<T, P> operator%(T scalar, tvec1<T, P> const & v);

	template <typename T, precision P>
	GLM_FUNC_DECL tvec1<T, P> operator%(tvec1<T, P> const & v1, tvec1<T, P> const & v2);

	template <typename T, precision P>
	GLM_FUNC_DECL tvec1<T, P> operator&(tvec1<T, P> const & v, T scalar);

	template <typename T, precision P>
	GLM_FUNC_DECL tvec1<T, P> operator&(T scalar, tvec1<T, P> const & v);

	template <typename T, precision P>
	GLM_FUNC_DECL tvec1<T, P> operator&(tvec1<T, P> const & v1, tvec1<T, P> const & v2);

	template <typename T, precision P>
	GLM_FUNC_DECL tvec1<T, P> operator|(tvec1<T, P> const & v, T scalar);

	template <typename T, precision P>
	GLM_FUNC_DECL tvec1<T, P> operator|(T scalar, tvec1<T, P> const & v);

	template <typename T, precision P>
	GLM_FUNC_DECL tvec1<T, P> operator|(tvec1<T, P> const & v1, tvec1<T, P> const & v2);

	template <typename T, precision P>
	GLM_FUNC_DECL tvec1<T, P> operator^(tvec1<T, P> const & v, T scalar);

	template <typename T, precision P>
	GLM_FUNC_DECL tvec1<T, P> operator^(T scalar, tvec1<T, P> const & v);

	template <typename T, precision P>
	GLM_FUNC_DECL tvec1<T, P> operator^(tvec1<T, P> const & v1, tvec1<T, P> const & v2);

	template <typename T, precision P>
	GLM_FUNC_DECL tvec1<T, P> operator<<(tvec1<T, P> const & v, T scalar);

	template <typename T, precision P>
	GLM_FUNC_DECL tvec1<T, P> operator<<(T scalar, tvec1<T, P> const & v);

	template <typename T, precision P>
	GLM_FUNC_DECL tvec1<T, P> operator<<(tvec1<T, P> const & v1, tvec1<T, P> const & v2);

	template <typename T, precision P>
	GLM_FUNC_DECL tvec1<T, P> operator>>(tvec1<T, P> const & v, T scalar);

	template <typename T, precision P>
	GLM_FUNC_DECL tvec1<T, P> operator>>(T scalar, tvec1<T, P> const & v);

	template <typename T, precision P>
	GLM_FUNC_DECL tvec1<T, P> operator>>(tvec1<T, P> const & v1, tvec1<T, P> const & v2);

	template <typename T, precision P>
	GLM_FUNC_DECL tvec1<T, P> operator~(tvec1<T, P> const & v);

	// -- Boolean operators --

	template <typename T, precision P>
	GLM_FUNC_DECL bool operator==(tvec1<T, P> const & v1, tvec1<T, P> const & v2);

	template <typename T, precision P>
	GLM_FUNC_DECL bool operator!=(tvec1<T, P> const & v1, tvec1<T, P> const & v2);

	template <precision P>
	GLM_FUNC_DECL tvec1<bool, P> operator&&(tvec1<bool, P> const & v1, tvec1<bool, P> const & v2);

	template <precision P>
	GLM_FUNC_DECL tvec1<bool, P> operator||(tvec1<bool, P> const & v1, tvec1<bool, P> const & v2);
}//namespace glm

#ifndef GLM_EXTERNAL_TEMPLATE
#include "type_vec1.inl"
#endif//GLM_EXTERNAL_TEMPLATE
