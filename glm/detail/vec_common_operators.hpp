#pragma once
#include "qualifier.hpp"
namespace glm {

template<length_t L,typename T,qualifier Q>
GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR vec<L,T,Q> operator++(vec<L,T,Q>& v,int);
template<length_t L,typename T,qualifier Q>
GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR vec<L,T,Q> operator--(vec<L,T,Q>& v,int);
template<length_t L,typename T,qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR vec<L,T,Q> operator+(vec<L,T,Q> const& v);
template<length_t L,typename T,qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR bool operator!=(vec<L,T,Q> const& a,vec<L,T,Q> const& b);

template<length_t L, typename T, qualifier Q,typename U,qualifier P>
GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR vec<L, T, Q>& operator+=(vec<L, T, Q>& a, vec<1,U,P> const& b);
template<length_t L, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator+(vec<L, T, Q> const& a, vec<1,T,Q> const& b);
template<length_t L, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator+(vec<1, T, Q> const& a, vec<L,T,Q> const& b);

template<length_t L, typename T, qualifier Q,typename U,qualifier P>
GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR vec<L, T, Q>& operator-=(vec<L, T, Q>& a, vec<1,U,P> const& b);
template<length_t L, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator-(vec<L, T, Q> const& a, vec<1,T,Q> const& b);
template<length_t L, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator-(vec<1, T, Q> const& a, vec<L,T,Q> const& b);

template<length_t L, typename T, qualifier Q,typename U,qualifier P>
GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR vec<L, T, Q>& operator*=(vec<L, T, Q>& a, vec<1,U,P> const& b);
template<length_t L, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator*(vec<L, T, Q> const& a, vec<1,T,Q> const& b);
template<length_t L, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator*(vec<1, T, Q> const& a, vec<L,T,Q> const& b);

template<length_t L, typename T, qualifier Q,typename U,qualifier P>
GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR vec<L, T, Q>& operator/=(vec<L, T, Q>& a, vec<1,U,P> const& b);
template<length_t L, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator/(vec<L, T, Q> const& a, vec<1,T,Q> const& b);
template<length_t L, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator/(vec<1, T, Q> const& a, vec<L,T,Q> const& b);

template<length_t L, typename T, qualifier Q,typename U,qualifier P>
GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR vec<L, T, Q>& operator%=(vec<L, T, Q>& a, vec<1,U,P> const& b);
template<length_t L, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator%(vec<L, T, Q> const& a, vec<1,T,Q> const& b);
template<length_t L, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator%(vec<1, T, Q> const& a, vec<L,T,Q> const& b);

template<length_t L, typename T, qualifier Q,typename U,qualifier P>
GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR vec<L, T, Q>& operator&=(vec<L, T, Q>& a, vec<1,U,P> const& b);
template<length_t L, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator&(vec<L, T, Q> const& a, vec<1,T,Q> const& b);
template<length_t L, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator&(vec<1, T, Q> const& a, vec<L,T,Q> const& b);

template<length_t L, typename T, qualifier Q,typename U,qualifier P>
GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR vec<L, T, Q>& operator|=(vec<L, T, Q>& a, vec<1,U,P> const& b);
template<length_t L, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator|(vec<L, T, Q> const& a, vec<1,T,Q> const& b);
template<length_t L, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator|(vec<1, T, Q> const& a, vec<L,T,Q> const& b);

template<length_t L, typename T, qualifier Q,typename U,qualifier P>
GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR vec<L, T, Q>& operator^=(vec<L, T, Q>& a, vec<1,U,P> const& b);
template<length_t L, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator^(vec<L, T, Q> const& a, vec<1,T,Q> const& b);
template<length_t L, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator^(vec<1, T, Q> const& a, vec<L,T,Q> const& b);

template<length_t L, typename T, qualifier Q,typename U,qualifier P>
GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR vec<L, T, Q>& operator<<=(vec<L, T, Q>& a, vec<1,U,P> const& b);
template<length_t L, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator<<(vec<L, T, Q> const& a, vec<1,T,Q> const& b);
template<length_t L, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator<<(vec<1, T, Q> const& a, vec<L,T,Q> const& b);

template<length_t L, typename T, qualifier Q,typename U,qualifier P>
GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR vec<L, T, Q>& operator>>=(vec<L, T, Q>& a, vec<1,U,P> const& b);
template<length_t L, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator>>(vec<L, T, Q> const& a, vec<1,T,Q> const& b);
template<length_t L, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator>>(vec<1, T, Q> const& a, vec<L,T,Q> const& b);

template<length_t L, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator+(T scalar,vec<L, T, Q> const& v);

template<length_t L, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator*(T scalar,vec<L, T, Q> const& v);

template<length_t L, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator&(T scalar,vec<L, T, Q> const& v);

template<length_t L, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator|(T scalar,vec<L, T, Q> const& v);

template<length_t L, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator^(T scalar,vec<L, T, Q> const& v);
} // namespace glm

#ifndef GLM_EXTERNAL_TEMPLATE
#include "vec_common_operators.inl"
#endif
