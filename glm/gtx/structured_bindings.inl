namespace glm
{
	template<length_t I, length_t L, typename T, qualifier Q>
	GLM_CONSTEXPR T& get(vec<L, T, Q>& v) {
		static_assert(I < L, "Index out of bounds");
		return v[I];
	}
	template<length_t I, length_t L, typename T, qualifier Q>
	GLM_CONSTEXPR T const& get(vec<L, T, Q> const& v) {
		static_assert(I < L, "Index out of bounds");
		return v[I];
	}

	template<length_t I, length_t C, length_t R, typename T, qualifier Q>
	GLM_CONSTEXPR vec<R, T, Q>& get(mat<C, R, T, Q>& m) {
		static_assert(I < C, "Index out of bounds");
		return m[I];
	}
	template<length_t I, length_t C, length_t R, typename T, qualifier Q>
	GLM_CONSTEXPR vec<R, T, Q> const& get(mat<C, R, T, Q> const& m) {
		static_assert(I < C, "Index out of bounds");
		return m[I];
	}

	template<length_t I, typename T, qualifier Q>
	GLM_CONSTEXPR T& get(qua<T, Q>& q) {
		static_assert(I < 4, "Index out of bounds");
		return q[I];
	}
	template<length_t I, typename T, qualifier Q>
	GLM_CONSTEXPR T const& get(qua<T, Q> const& q) {
		static_assert(I < 4, "Index out of bounds");
		return q[I];
	}

	template<length_t I, length_t L, typename T, qualifier Q>
	GLM_CONSTEXPR T get(vec<L, T, Q> const&& v)
	{
		static_assert(I < L, "Index out of bounds");
		return v[I];
	}
	template<length_t I, length_t C, length_t R, typename T, qualifier Q>
	GLM_CONSTEXPR vec<R, T, Q> get(mat<C, R, T, Q> const&& m) {
		static_assert(I < C, "Index out of bounds");
		return m[I];
	}
	template<length_t I, typename T, qualifier Q>
	GLM_CONSTEXPR T get(qua<T, Q> const&& q) {
		static_assert(I < 4, "Index out of bounds");
		return q[I];
	}
}//namespace glm

