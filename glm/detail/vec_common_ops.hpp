#pragma once

#include "qualifier.hpp"

namespace glm {

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator+(vec<L, T, Q> const& v);

	template<length_t L,typename T,qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator++(vec<L, T, Q>& v, int);

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator--(vec<L, T, Q>& v, int);

	template<length_t L, typename T, qualifier Q, typename U>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q>& operator+=(vec<L, T, Q>& v1, U scalar);
	template<length_t L, typename T, qualifier Q, typename U>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q>& operator-=(vec<L, T, Q>& v1, U scalar);
	template<length_t L, typename T, qualifier Q, typename U>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q>& operator*=(vec<L, T, Q>& v1, U scalar);
	template<length_t L, typename T, qualifier Q, typename U>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q>& operator/=(vec<L, T, Q>& v1, U scalar);
	template<length_t L, typename T, qualifier Q, typename U>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q>& operator%=(vec<L, T, Q>& v1, U scalar);
	template<length_t L, typename T, qualifier Q, typename U>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q>& operator&=(vec<L, T, Q>& v1, U scalar);
	template<length_t L, typename T, qualifier Q, typename U>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q>& operator|=(vec<L, T, Q>& v1, U scalar);
	template<length_t L, typename T, qualifier Q, typename U>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q>& operator^=(vec<L, T, Q>& v1, U scalar);
	template<length_t L, typename T, qualifier Q, typename U>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q>& operator<<=(vec<L, T, Q>& v1, U scalar);
	template<length_t L, typename T, qualifier Q, typename U>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q>& operator>>=(vec<L, T, Q>& v1, U scalar);

	template<length_t L, typename T, qualifier Q, typename U>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q>& operator+=(vec<L, T, Q>& v1, vec<1, U, Q> const& v2);
	template<length_t L, typename T, qualifier Q, typename U>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q>& operator-=(vec<L, T, Q>& v1, vec<1, U, Q> const& v2);
	template<length_t L, typename T, qualifier Q, typename U>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q>& operator*=(vec<L, T, Q>& v1, vec<1, U, Q> const& v2);
	template<length_t L, typename T, qualifier Q, typename U>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q>& operator/=(vec<L, T, Q>& v1, vec<1, U, Q> const& v2);
	template<length_t L, typename T, qualifier Q, typename U>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q>& operator%=(vec<L, T, Q>& v1, vec<1, U, Q> const& v2);
	template<length_t L, typename T, qualifier Q, typename U>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q>& operator&=(vec<L, T, Q>& v1, vec<1, U, Q> const& v2);
	template<length_t L, typename T, qualifier Q, typename U>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q>& operator|=(vec<L, T, Q>& v1, vec<1, U, Q> const& v2);
	template<length_t L, typename T, qualifier Q, typename U>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q>& operator^=(vec<L, T, Q>& v1, vec<1, U, Q> const& v2);
	template<length_t L, typename T, qualifier Q, typename U>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q>& operator<<=(vec<L, T, Q>& v1, vec<1, U, Q> const& v2);
	template<length_t L, typename T, qualifier Q, typename U>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q>& operator>>=(vec<L, T, Q>& v1, vec<1, U, Q> const& v2);

	// vectors

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator+(vec<L, T, Q> const& v1, vec<L, T, Q> const& v2);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator-(vec<L, T, Q> const& v1, vec<L, T, Q> const& v2);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator*(vec<L, T, Q> const& v1, vec<L, T, Q> const& v2);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator/(vec<L, T, Q> const& v1, vec<L, T, Q> const& v2);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator%(vec<L, T, Q> const& v1, vec<L, T, Q> const& v2);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator&(vec<L, T, Q> const& v1, vec<L, T, Q> const& v2);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator|(vec<L, T, Q> const& v1, vec<L, T, Q> const& v2);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator^(vec<L, T, Q> const& v1, vec<L, T, Q> const& v2);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator<<(vec<L, T, Q> const& v1, vec<L, T, Q> const& v2);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator>>(vec<L, T, Q> const& v1, vec<L, T, Q> const& v2);

	
	// Scalars
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator+(vec<L, T, Q> const& v, T scalar);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator-(vec<L, T, Q> const& v, T scalar);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator*(vec<L, T, Q> const& v, T scalar);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator/(vec<L, T, Q> const& v, T scalar);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator%(vec<L, T, Q> const& v, T scalar);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator&(vec<L, T, Q> const& v, T scalar);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator|(vec<L, T, Q> const& v, T scalar);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator^(vec<L, T, Q> const& v, T scalar);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator<<(vec<L, T, Q> const& v, T scalar);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator>>(vec<L, T, Q> const& v, T scalar);

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator+(T scalar, vec<L, T, Q> const& v);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator-(T scalar, vec<L, T, Q> const& v);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator*(T scalar, vec<L, T, Q> const& v);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator/(T scalar, vec<L, T, Q> const& v);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator%(T scalar, vec<L, T, Q> const& v);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator&(T scalar, vec<L, T, Q> const& v);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator|(T scalar, vec<L, T, Q> const& v);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator^(T scalar, vec<L, T, Q> const& v);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator<<(T scalar, vec<L, T, Q> const& v);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator>>(T scalar, vec<L, T, Q> const& v);

	//////// vec1
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator+(vec<L, T, Q> const& v1, vec<1, T, Q> const& v2);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator-(vec<L, T, Q> const& v1, vec<1, T, Q> const& v2);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator*(vec<L, T, Q> const& v1, vec<1, T, Q> const& v2);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator/(vec<L, T, Q> const& v1, vec<1, T, Q> const& v2);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator%(vec<L, T, Q> const& v1, vec<1, T, Q> const& v2);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator&(vec<L, T, Q> const& v1, vec<1, T, Q> const& v2);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator|(vec<L, T, Q> const& v1, vec<1, T, Q> const& v2);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator^(vec<L, T, Q> const& v1, vec<1, T, Q> const& v2);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator<<(vec<L, T, Q> const& v1, vec<1, T, Q> const& v2);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator>>(vec<L, T, Q> const& v1, vec<1, T, Q> const& v2);

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator+(vec<1, T, Q> const& v1, vec<L, T, Q> const& v2);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator-(vec<1, T, Q> const& v1, vec<L, T, Q> const& v2);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator*(vec<1, T, Q> const& v1, vec<L, T, Q> const& v2);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator/(vec<1, T, Q> const& v1, vec<L, T, Q> const& v2);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator%(vec<1, T, Q> const& v1, vec<L, T, Q> const& v2);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator&(vec<1, T, Q> const& v1, vec<L, T, Q> const& v2);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator|(vec<1, T, Q> const& v1, vec<L, T, Q> const& v2);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator^(vec<1, T, Q> const& v1, vec<L, T, Q> const& v2);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator<<(vec<1, T, Q> const& v1, vec<L, T, Q> const& v2);
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator>>(vec<1, T, Q> const& v1, vec<L, T, Q> const& v2);

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR bool operator!=(vec<L, T, Q> const& v1, vec<L, T, Q> const& v2);

}

#ifndef GLM_EXTERNAL_TEMPLATE
#include "vec_common_ops.inl"
#endif//GLM_EXTERNAL_TEMPLATE
