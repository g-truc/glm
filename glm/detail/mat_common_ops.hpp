#pragma once

#include "qualifier.hpp"

namespace glm {

	template<length_t C, length_t R, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<C, R, T, Q> operator+(mat<C, R, T, Q> const& m);

	template<length_t C, length_t R, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<C, R, T, Q> operator++(mat<C, R, T, Q>& m, int);

	template<length_t C, length_t R, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<C, R, T, Q> operator--(mat<C, R, T, Q>& m, int);

	template<length_t C, length_t R, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<C, R, T, Q> operator+(mat<C, R, T, Q> const& m, T scalar);
	template<length_t C, length_t R, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<C, R, T, Q> operator-(mat<C, R, T, Q> const& m, T scalar);
	template<length_t C, length_t R, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<C, R, T, Q> operator*(mat<C, R, T, Q> const& m, T scalar);
	template<length_t C, length_t R, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<C, R, T, Q> operator/(mat<C, R, T, Q> const& m, T scalar);

	template<length_t C, length_t R, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<C, R, T, Q> operator+(T scalar, mat<C, R, T, Q> const& m);
	template<length_t C, length_t R, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<C, R, T, Q> operator*(T scalar, mat<C, R, T, Q> const& m);

	template<length_t C, length_t R, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR bool operator!=(mat<C, R, T, Q> const& m1, mat<C, R, T, Q> const& m2);
}


#ifndef GLM_EXTERNAL_TEMPLATE
#include "mat_common_ops.inl"
#endif//!GLM_EXTERNAL_TEMPLATE
