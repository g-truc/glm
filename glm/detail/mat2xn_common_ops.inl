#include "qualifier.hpp"

namespace glm {

	template<length_t R, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<2, R, T, Q>& operator++(mat<2, R, T, Q>& m) {
		++m[0];
		++m[1];
		return m;
	}

	template<length_t R, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<2, R, T, Q>& operator--(mat<2, R, T, Q>& m) {
		--m[0];
		--m[1];
		return m;
	}

	template<length_t R, typename T, qualifier Q, typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<2, R, T, Q>& operator+=(mat<2, R, T, Q>& m, U scalar) {
		m[0] += scalar;
		m[1] += scalar;
		return m;
	}
	template<length_t R, typename T, qualifier Q, typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<2, R, T, Q>& operator-=(mat<2, R, T, Q>& m, U scalar) {
		m[0] -= scalar;
		m[1] -= scalar;
		return m;
	}
	template<length_t R, typename T, qualifier Q, typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<2, R, T, Q>& operator*=(mat<2, R, T, Q>& m, U scalar) {
		m[0] *= scalar;
		m[1] *= scalar;
		return m;
	}
	template<length_t R, typename T, qualifier Q, typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<2, R, T, Q>& operator/=(mat<2, R, T, Q>& m, U scalar) {
		m[0] /= scalar;
		m[1] /= scalar;
		return m;
	}

	// Matrices
	template<length_t R, typename T, qualifier Q, typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<2, R, T, Q>& operator+=(mat<2, R, T, Q>& m1, mat<2, R, U, Q> const& m2) {
		m1[0] += m2[0];
		m1[1] += m2[1];
		return m1;
	}

	template<length_t R, typename T, qualifier Q, typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<2, R, T, Q>& operator-=(mat<2, R, T, Q>& m1, mat<2, R, U, Q> const& m2) {
		m1[0] -= m2[0];
		m1[1] -= m2[1];
		return m1;
	}


	// Matrices

	template<length_t R, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<2, R, T, Q> operator+(mat<2, R, T, Q> const& m1, mat<2, R, T, Q> const& m2) {
		return mat<2, R, T, Q>(
			m1[0] + m2[0],
			m1[1] + m2[1]);
	}
	template<length_t R, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<2, R, T, Q> operator-(mat<2, R, T, Q> const& m1, mat<2, R, T, Q> const& m2) {
		return mat<2, R, T, Q>(
			m1[0] - m2[0],
			m1[1] - m2[1]);
	}

	// Scalars

	template<length_t R, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<2, R, T, Q> operator-(T scalar, mat<2, R, T, Q> const& m) {
		return mat<2, R, T, Q>(
			scalar - m[0],
			scalar - m[1]);
	}
	template<length_t R, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<2, R, T, Q> operator/(T scalar, mat<2, R, T, Q> const& m) {
		return mat<2, R, T, Q>(
			scalar / m[0],
			scalar / m[1]);
	}



	template<length_t R,typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<2, R, T, Q> operator-(mat<2, R, T, Q> const& m)
	{
		return mat<2, R, T, Q>(
			-m[0],
			-m[1]);
	}

	// -- Boolean operators --
	template<length_t R, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR bool operator==(mat<2, R, T, Q> const& m1, mat<2, R, T, Q> const& m2) {
		return m1[0] == m2[0] 
			&& m1[1] == m2[1];
	}
}
