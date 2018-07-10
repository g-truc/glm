/// @ref core
/// @file glm/detail/type_vec3.hpp

#pragma once

#include "type_vec.hpp"
#if GLM_SWIZZLE == GLM_SWIZZLE_ENABLED
#	if GLM_HAS_UNRESTRICTED_UNIONS
#		include "_swizzle.hpp"
#	else
#		include "_swizzle_func.hpp"
#	endif
#endif //GLM_SWIZZLE == GLM_SWIZZLE_ENABLED
#include <cstddef>

namespace glm
{
	template<typename T, qualifier Q>
	struct vec<3, T, Q>
	{
		// -- Implementation detail --

		typedef T value_type;
		typedef vec type;
		typedef vec<3, bool, Q> bool_type;

		// -- Data --

#		if GLM_HAS_ONLY_XYZW
			T x, y, z;

#		elif GLM_HAS_ALIGNED_TYPE
#			if GLM_COMPILER & GLM_COMPILER_GCC
#				pragma GCC diagnostic push
#				pragma GCC diagnostic ignored "-Wpedantic"
#			endif
#			if GLM_COMPILER & GLM_COMPILER_CLANG
#				pragma clang diagnostic push
#				pragma clang diagnostic ignored "-Wgnu-anonymous-struct"
#				pragma clang diagnostic ignored "-Wnested-anon-types"
#			endif
#			if GLM_COMPILER & GLM_COMPILER_VC
#				pragma warning(push)
#				pragma warning(disable: 4201)  // nonstandard extension used : nameless struct/union
#			endif

			union
			{
				struct{ T x, y, z; };
				struct{ T r, g, b; };
				struct{ T s, t, p; };

#				if GLM_SWIZZLE == GLM_SWIZZLE_ENABLED
					GLM_SWIZZLE3_2_MEMBERS(T, Q, x, y, z)
					GLM_SWIZZLE3_2_MEMBERS(T, Q, r, g, b)
					GLM_SWIZZLE3_2_MEMBERS(T, Q, s, t, p)
					GLM_SWIZZLE3_3_MEMBERS(T, Q, x, y, z)
					GLM_SWIZZLE3_3_MEMBERS(T, Q, r, g, b)
					GLM_SWIZZLE3_3_MEMBERS(T, Q, s, t, p)
					GLM_SWIZZLE3_4_MEMBERS(T, Q, x, y, z)
					GLM_SWIZZLE3_4_MEMBERS(T, Q, r, g, b)
					GLM_SWIZZLE3_4_MEMBERS(T, Q, s, t, p)
#				endif//GLM_SWIZZLE
			};

#			if GLM_COMPILER & GLM_COMPILER_VC
#				pragma warning(pop)
#			endif
#			if GLM_COMPILER & GLM_COMPILER_CLANG
#				pragma clang diagnostic pop
#			endif
#			if GLM_COMPILER & GLM_COMPILER_GCC
#				pragma GCC diagnostic pop
#			endif
#		else
			union { T x, r, s; };
			union { T y, g, t; };
			union { T z, b, p; };

#			if GLM_SWIZZLE == GLM_SWIZZLE_ENABLED
				GLM_SWIZZLE_GEN_VEC_FROM_VEC3(T, P)
#			endif//GLM_SWIZZLE
#		endif//GLM_LANG

		// -- Component accesses --

		/// Return the count of components of the vector
		typedef length_t length_type;
		GLM_FUNC_DECL static GLM_CONSTEXPR_CXX11 length_type length(){return 3;}

		GLM_FUNC_DECL T & operator[](length_type i);
		GLM_FUNC_DECL T const& operator[](length_type i) const;

		// -- Implicit basic constructors --

		GLM_FUNC_DECL GLM_CONSTEXPR_CXX11 vec() GLM_DEFAULT_CTOR;
		GLM_FUNC_DECL GLM_CONSTEXPR_CXX11 vec(vec const& v) GLM_DEFAULT;
		template<qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR_CXX11 vec(vec<3, T, P> const& v);

		// -- Explicit basic constructors --

		GLM_FUNC_DECL GLM_CONSTEXPR_CXX11 explicit vec(T scalar);
		GLM_FUNC_DECL GLM_CONSTEXPR_CXX11 vec(T a, T b, T c);

		// -- Conversion scalar constructors --

		template<typename U, qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR_CXX11 explicit vec(vec<1, U, P> const& v);

		/// Explicit converions (From section 5.4.1 Conversion and scalar constructors of GLSL 1.30.08 specification)
		template<typename X, typename Y, typename Z>
		GLM_FUNC_DECL GLM_CONSTEXPR_CXX11 vec(X x, Y y, Z z);
		template<typename X, typename Y, typename Z>
		GLM_FUNC_DECL GLM_CONSTEXPR_CXX11 vec(vec<1, X, Q> const& _x, Y _y, Z _z);
		template<typename X, typename Y, typename Z>
		GLM_FUNC_DECL GLM_CONSTEXPR_CXX11 vec(X _x, vec<1, Y, Q> const& _y, Z _z);
		template<typename X, typename Y, typename Z>
		GLM_FUNC_DECL GLM_CONSTEXPR_CXX11 vec(vec<1, X, Q> const& _x, vec<1, Y, Q> const& _y, Z _z);
		template<typename X, typename Y, typename Z>
		GLM_FUNC_DECL GLM_CONSTEXPR_CXX11 vec(X _x, Y _y, vec<1, Z, Q> const& _z);
		template<typename X, typename Y, typename Z>
		GLM_FUNC_DECL GLM_CONSTEXPR_CXX11 vec(vec<1, X, Q> const& _x, Y _y, vec<1, Z, Q> const& _z);
		template<typename X, typename Y, typename Z>
		GLM_FUNC_DECL GLM_CONSTEXPR_CXX11 vec(X _x, vec<1, Y, Q> const& _y, vec<1, Z, Q> const& _z);
		template<typename X, typename Y, typename Z>
		GLM_FUNC_DECL GLM_CONSTEXPR_CXX11 vec(vec<1, X, Q> const& _x, vec<1, Y, Q> const& _y, vec<1, Z, Q> const& _z);

		// -- Conversion vector constructors --

		/// Explicit conversions (From section 5.4.1 Conversion and scalar constructors of GLSL 1.30.08 specification)
		template<typename A, typename B, qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR_CXX11 vec(vec<2, A, P> const& _xy, B _z);
		/// Explicit conversions (From section 5.4.1 Conversion and scalar constructors of GLSL 1.30.08 specification)
		template<typename A, typename B, qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR_CXX11 vec(vec<2, A, P> const& _xy, vec<1, B, P> const& _z);
		/// Explicit conversions (From section 5.4.1 Conversion and scalar constructors of GLSL 1.30.08 specification)
		template<typename A, typename B, qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR_CXX11 vec(A _x, vec<2, B, P> const& _yz);
		/// Explicit conversions (From section 5.4.1 Conversion and scalar constructors of GLSL 1.30.08 specification)
		template<typename A, typename B, qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR_CXX11 vec(vec<1, A, P> const& _x, vec<2, B, P> const& _yz);
		/// Explicit conversions (From section 5.4.1 Conversion and scalar constructors of GLSL 1.30.08 specification)
		template<typename U, qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR_CXX11 GLM_EXPLICIT vec(vec<4, U, P> const& v);

		/// Explicit conversions (From section 5.4.1 Conversion and scalar constructors of GLSL 1.30.08 specification)
		template<typename U, qualifier P>
		GLM_FUNC_DECL GLM_CONSTEXPR_CXX11 GLM_EXPLICIT vec(vec<3, U, P> const& v);

		// -- Swizzle constructors --
#		if GLM_HAS_UNRESTRICTED_UNIONS && (GLM_SWIZZLE == GLM_SWIZZLE_ENABLED)
			template<int E0, int E1, int E2>
			GLM_FUNC_DECL vec(detail::_swizzle<3, T, Q, E0, E1, E2, -1> const& that)
			{
				*this = that();
			}

			template<int E0, int E1>
			GLM_FUNC_DECL vec(detail::_swizzle<2, T, Q, E0, E1, -1, -2> const& v, T const& scalar)
			{
				*this = vec(v(), scalar);
			}

			template<int E0, int E1>
			GLM_FUNC_DECL vec(T const& scalar, detail::_swizzle<2, T, Q, E0, E1, -1, -2> const& v)
			{
				*this = vec(scalar, v());
			}
#		endif// GLM_HAS_UNRESTRICTED_UNIONS && (GLM_SWIZZLE == GLM_SWIZZLE_ENABLED)

		// -- Unary arithmetic operators --

		GLM_FUNC_DECL vec & operator=(vec const& v);

		template<typename U>
		GLM_FUNC_DECL vec & operator=(vec<3, U, Q> const& v);
		template<typename U>
		GLM_FUNC_DECL vec & operator+=(U scalar);
		template<typename U>
		GLM_FUNC_DECL vec & operator+=(vec<1, U, Q> const& v);
		template<typename U>
		GLM_FUNC_DECL vec & operator+=(vec<3, U, Q> const& v);
		template<typename U>
		GLM_FUNC_DECL vec & operator-=(U scalar);
		template<typename U>
		GLM_FUNC_DECL vec & operator-=(vec<1, U, Q> const& v);
		template<typename U>
		GLM_FUNC_DECL vec & operator-=(vec<3, U, Q> const& v);
		template<typename U>
		GLM_FUNC_DECL vec & operator*=(U scalar);
		template<typename U>
		GLM_FUNC_DECL vec & operator*=(vec<1, U, Q> const& v);
		template<typename U>
		GLM_FUNC_DECL vec & operator*=(vec<3, U, Q> const& v);
		template<typename U>
		GLM_FUNC_DECL vec & operator/=(U scalar);
		template<typename U>
		GLM_FUNC_DECL vec & operator/=(vec<1, U, Q> const& v);
		template<typename U>
		GLM_FUNC_DECL vec & operator/=(vec<3, U, Q> const& v);

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
		GLM_FUNC_DECL vec & operator%=(vec<3, U, Q> const& v);
		template<typename U>
		GLM_FUNC_DECL vec & operator&=(U scalar);
		template<typename U>
		GLM_FUNC_DECL vec & operator&=(vec<1, U, Q> const& v);
		template<typename U>
		GLM_FUNC_DECL vec & operator&=(vec<3, U, Q> const& v);
		template<typename U>
		GLM_FUNC_DECL vec & operator|=(U scalar);
		template<typename U>
		GLM_FUNC_DECL vec & operator|=(vec<1, U, Q> const& v);
		template<typename U>
		GLM_FUNC_DECL vec & operator|=(vec<3, U, Q> const& v);
		template<typename U>
		GLM_FUNC_DECL vec & operator^=(U scalar);
		template<typename U>
		GLM_FUNC_DECL vec & operator^=(vec<1, U, Q> const& v);
		template<typename U>
		GLM_FUNC_DECL vec & operator^=(vec<3, U, Q> const& v);
		template<typename U>
		GLM_FUNC_DECL vec & operator<<=(U scalar);
		template<typename U>
		GLM_FUNC_DECL vec & operator<<=(vec<1, U, Q> const& v);
		template<typename U>
		GLM_FUNC_DECL vec & operator<<=(vec<3, U, Q> const& v);
		template<typename U>
		GLM_FUNC_DECL vec & operator>>=(U scalar);
		template<typename U>
		GLM_FUNC_DECL vec & operator>>=(vec<1, U, Q> const& v);
		template<typename U>
		GLM_FUNC_DECL vec & operator>>=(vec<3, U, Q> const& v);
	};

	// -- Unary operators --

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator+(vec<3, T, Q> const& v);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator-(vec<3, T, Q> const& v);

	// -- Binary operators --

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator+(vec<3, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator+(vec<3, T, Q> const& v, vec<1, T, Q> const& scalar);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator+(T scalar, vec<3, T, Q> const& v);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator+(vec<1, T, Q> const& v1, vec<3, T, Q> const& v2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator+(vec<3, T, Q> const& v1, vec<3, T, Q> const& v2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator-(vec<3, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator-(vec<3, T, Q> const& v1, vec<1, T, Q> const& v2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator-(T scalar, vec<3, T, Q> const& v);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator-(vec<1, T, Q> const& v1, vec<3, T, Q> const& v2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator-(vec<3, T, Q> const& v1, vec<3, T, Q> const& v2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator*(vec<3, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator*(vec<3, T, Q> const& v1, vec<1, T, Q> const& v2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator*(T scalar, vec<3, T, Q> const& v);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator*(vec<1, T, Q> const& v1, vec<3, T, Q> const& v2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator*(vec<3, T, Q> const& v1, vec<3, T, Q> const& v2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator/(vec<3, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator/(vec<3, T, Q> const& v1, vec<1, T, Q> const& v2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator/(T scalar, vec<3, T, Q> const& v);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator/(vec<1, T, Q> const& v1, vec<3, T, Q> const& v2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator/(vec<3, T, Q> const& v1, vec<3, T, Q> const& v2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator%(vec<3, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator%(vec<3, T, Q> const& v1, vec<1, T, Q> const& v2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator%(T const& scalar, vec<3, T, Q> const& v);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator%(vec<1, T, Q> const& v1, vec<3, T, Q> const& v2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator%(vec<3, T, Q> const& v1, vec<3, T, Q> const& v2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator&(vec<3, T, Q> const& v1, T scalar);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator&(vec<3, T, Q> const& v1, vec<1, T, Q> const& v2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator&(T scalar, vec<3, T, Q> const& v);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator&(vec<1, T, Q> const& v1, vec<3, T, Q> const& v2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator&(vec<3, T, Q> const& v1, vec<3, T, Q> const& v2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator|(vec<3, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator|(vec<3, T, Q> const& v1, vec<1, T, Q> const& v2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator|(T scalar, vec<3, T, Q> const& v);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator|(vec<1, T, Q> const& v1, vec<3, T, Q> const& v2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator|(vec<3, T, Q> const& v1, vec<3, T, Q> const& v2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator^(vec<3, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator^(vec<3, T, Q> const& v1, vec<1, T, Q> const& v2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator^(T scalar, vec<3, T, Q> const& v);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator^(vec<1, T, Q> const& v1, vec<3, T, Q> const& v2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator^(vec<3, T, Q> const& v1, vec<3, T, Q> const& v2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator<<(vec<3, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator<<(vec<3, T, Q> const& v1, vec<1, T, Q> const& v2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator<<(T scalar, vec<3, T, Q> const& v);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator<<(vec<1, T, Q> const& v1, vec<3, T, Q> const& v2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator<<(vec<3, T, Q> const& v1, vec<3, T, Q> const& v2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator>>(vec<3, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator>>(vec<3, T, Q> const& v1, vec<1, T, Q> const& v2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator>>(T scalar, vec<3, T, Q> const& v);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator>>(vec<1, T, Q> const& v1, vec<3, T, Q> const& v2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator>>(vec<3, T, Q> const& v1, vec<3, T, Q> const& v2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> operator~(vec<3, T, Q> const& v);

	// -- Boolean operators --

	template<typename T, qualifier Q>
	GLM_FUNC_DECL bool operator==(vec<3, T, Q> const& v1, vec<3, T, Q> const& v2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL bool operator!=(vec<3, T, Q> const& v1, vec<3, T, Q> const& v2);

	template<qualifier Q>
	GLM_FUNC_DECL vec<3, bool, Q> operator&&(vec<3, bool, Q> const& v1, vec<3, bool, Q> const& v2);

	template<qualifier Q>
	GLM_FUNC_DECL vec<3, bool, Q> operator||(vec<3, bool, Q> const& v1, vec<3, bool, Q> const& v2);
}//namespace glm

#ifndef GLM_EXTERNAL_TEMPLATE
#include "type_vec3.inl"
#endif//GLM_EXTERNAL_TEMPLATE
