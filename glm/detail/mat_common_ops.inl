#include "qualifier.hpp"

namespace glm {
	template<length_t C,length_t R,typename T,qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<C, R, T, Q> operator+(mat<C,R,T,Q> const& m) {
		return m;
	}
	template<length_t C,length_t R,typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<C,R, T, Q> operator++(mat<C,R,T,Q>& m,int)
	{
		mat<C,R, T, Q> Result(m);
		++m;
		return Result;
	}

	template<length_t C, length_t R, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<C, R, T, Q> operator--(mat<C, R, T, Q>& m, int)
	{
		mat<C, R, T, Q> Result(m);
		--m;
		return Result;
	}


	template<length_t C,length_t R,typename T,qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR bool operator!=(mat<C, R, T, Q> const& m1, mat<C, R, T, Q> const& m2) {
		return !(m1 == m2);
	}


	template<length_t C, length_t R, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<C, R, T, Q> operator+(mat<C, R, T, Q> const& m, T scalar) {
		mat<C, R, T, Q> Result(m);
		Result += scalar;
		return Result;
	}

	template<length_t C, length_t R, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<C, R, T, Q> operator-(mat<C, R, T, Q> const& m, T scalar) {
		mat<C, R, T, Q> Result(m);
		Result -= scalar;
		return Result;
	}

	template<length_t C, length_t R, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<C, R, T, Q> operator*(mat<C, R, T, Q> const& m, T scalar) {
		mat<C, R, T, Q> Result(m);
		Result *= scalar;
		return Result;
	}

	template<length_t C, length_t R, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<C, R, T, Q> operator/(mat<C, R, T, Q> const& m, T scalar) {
		mat<C, R, T, Q> Result(m);
		Result /= scalar;
		return Result;
	}
	
	template<length_t C, length_t R, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<C, R, T, Q> operator+(T scalar, mat<C, R, T, Q> const& m) {
		return m + scalar;
	}
	template<length_t C, length_t R, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<C, R, T, Q> operator*(T scalar, mat<C, R, T, Q> const& m) {
		return m * scalar;
	}
}
