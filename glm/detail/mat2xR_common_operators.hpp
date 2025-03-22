
#pragma once
#include "qualifier.hpp"
#include "mat_common_operators.hpp"
namespace glm {


template<length_t R, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR mat<2,R,T,Q> operator-(mat<2,R,T,Q> const& m);

template<length_t R, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR mat<2,R,T,Q>& operator++(mat<2,R,T,Q>& m);

template<length_t R, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR mat<2,R,T,Q>& operator--(mat<2,R,T,Q>& m);

template<length_t R, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR bool operator==(mat<2,R,T,Q> const& m1, mat<2,R,T,Q> const& m2);

template<length_t R, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR mat<2,R,T,Q> operator+(mat<2,R,T,Q> const& m1, mat<2,R,T,Q> const& m2);
template<length_t R, typename T, qualifier Q,typename U>
GLM_FUNC_DECL GLM_CONSTEXPR mat<2,R,T,Q>& operator+=(mat<2,R,T,Q>& m1, mat<2,R,U,Q> const& m2);

template<length_t R, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR mat<2,R,T,Q> operator-(mat<2,R,T,Q> const& m1, mat<2,R,T,Q> const& m2);
template<length_t R, typename T, qualifier Q,typename U>
GLM_FUNC_DECL GLM_CONSTEXPR mat<2,R,T,Q>& operator-=(mat<2,R,T,Q>& m1, mat<2,R,U,Q> const& m2);

template<length_t R, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR mat<2,R, T, Q> operator+(mat<2,R, T, Q> const& m, T scalar);
template<length_t R, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR mat<2,R, T, Q> operator+(T scalar,mat<2,R, T, Q> const& m);

template<length_t R, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR mat<2,R, T, Q> operator-(mat<2,R, T, Q> const& m, T scalar);
template<length_t R, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR mat<2,R, T, Q> operator-(T scalar,mat<2,R, T, Q> const& m);

template<length_t R, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR mat<2,R, T, Q> operator*(mat<2,R, T, Q> const& m, T scalar);
template<length_t R, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR mat<2,R, T, Q> operator*(T scalar,mat<2,R, T, Q> const& m);

template<length_t R, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR mat<2,R, T, Q> operator/(mat<2,R, T, Q> const& m, T scalar);
template<length_t R, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR mat<2,R, T, Q> operator/(T scalar,mat<2,R, T, Q> const& m);

}
#ifndef GLM_EXTERNAL_TEMPLATE
#include "mat2xR_common_operators.inl"
#endif

