namespace glm {

	template<length_t C, length_t R, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<C, R, T, Q> operator++(mat<C, R, T, Q>& m, int) {
		mat<C, R, T, Q> Result(m);
		++m;
		return Result;
	}

	template<length_t C, length_t R, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<C, R, T, Q> operator--(mat<C, R, T, Q>& m, int) {
		mat<C, R, T, Q> Result(m);
		--m;
		return Result;
	}

	template<length_t C, length_t R, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<C, R, T, Q> operator+(mat<C, R, T, Q> const& m) {
		return m;
	}

	template<length_t C, length_t R, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR bool operator!=(mat<C, R, T, Q> const& m1, mat<C, R, T, Q> const& m2) {
		return !(m1 == m2);
	}

	template<length_t D,typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR typename mat<D, D, T, Q>::col_type operator/(mat<D, D, T, Q> const& m, typename mat<D, D, T, Q>::row_type const& v)
	{
		return inverse(m) * v;
	}

	template<length_t D,typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR typename mat<D, D, T, Q>::row_type operator/(typename mat<D, D, T, Q>::col_type const& v, mat<D, D, T, Q> const& m)
	{
		return v * inverse(m);
	}

}
