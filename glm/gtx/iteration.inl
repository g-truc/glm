namespace glm
{
	/*
	namespace details {
		template<typename T, glm::length_t L>
		struct known_length_iterator;
	}
	*/

	/// @addtogroup gtx_iteration
	/// @{
	template<length_t L,typename T,qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR T* begin(vec<L,T,Q>& v) {
		return &v.x;
	}
	template<length_t C,length_t R,typename T,qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR T* begin(mat<C,R,T,Q>& m) {
		return &m[0].x;
	}
	template<typename T,qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR T* begin(qua<T,Q>& q) {
		return &q[0];
	}
	template<length_t L,typename T,qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR const T* begin(const vec<L,T,Q>& v) {
		return &v.x;
	}
	template<length_t C,length_t R,typename T,qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR const T* begin(const mat<C,R,T,Q>& m) {
		return &m[0].x;
	}
	template<typename T,qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR const T* begin(const qua<T,Q>& q) {
		return &q[0];
	}

	template<length_t L,typename T,qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR T* end(vec<L,T,Q>& v) {
		return (&v.x) + L;
	}
	template<length_t C,length_t R,typename T,qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR T* end(mat<C,R,T,Q>& m) {
		return (&m[0].x) + C*R;
	}
	template<typename T,qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR T* end(qua<T,Q>& q) {
		return (&q[0]) + 4;
	}
	template<length_t L,typename T,qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR const T* end(const vec<L,T,Q>& v) {
		return (&v.x) + L;
	}
	template<length_t C,length_t R,typename T,qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR const T* end(const mat<C,R,T,Q>& m) {
		return (&m[0].x) + C*R;
	}
	template<typename T,qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR const T* end(const qua<T,Q>& q) {
		return (&q[0]) + 4;
	}

	// Reverse iteration
	// rbegin,rend
	template<length_t L,typename T,qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::reverse_iterator<T*> rbegin(vec<L,T,Q>& v) {
		return std::reverse_iterator<T*>(end(v));
	}
	template<length_t C,length_t R,typename T,qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::reverse_iterator<T*> rbegin(mat<C,R,T,Q>& m) {
		return std::reverse_iterator<T*>(end(m));
	}
	template<typename T,qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::reverse_iterator<T*> rbegin(qua<T,Q>& q) {
		return std::reverse_iterator<T*>(end(q));
	}
	template<length_t L,typename T,qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::reverse_iterator<const T*> rbegin(const vec<L,T,Q>& v) {
		return std::reverse_iterator<const T*>(end(v));
	}
	template<length_t C,length_t R,typename T,qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::reverse_iterator<const T*> rbegin(const mat<C,R,T,Q>& m) {
		return std::reverse_iterator<const T*>(end(m));
	}
	template<typename T,qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::reverse_iterator<const T*> rbegin(const qua<T,Q>& q) {
		return std::reverse_iterator<const T*>(end(q));
	}

	template<length_t L,typename T,qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::reverse_iterator<T*> rend(vec<L,T,Q>& v) {
		return std::reverse_iterator<T*>(begin(v));
	}
	template<length_t C,length_t R,typename T,qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::reverse_iterator<T*> rend(mat<C,R,T,Q>& m) {
		return std::reverse_iterator<T*>(begin(m));
	}
	template<typename T,qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::reverse_iterator<T*> rend(qua<T,Q>& q) {
		return std::reverse_iterator<T*>(begin(q));
	}
	template<length_t L,typename T,qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::reverse_iterator<const T*> rend(const vec<L,T,Q>& v) {
		return std::reverse_iterator<const T*>(begin(v));
	}
	template<length_t C,length_t R,typename T,qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::reverse_iterator<const T*> rend(const mat<C,R,T,Q>& m) {
		return std::reverse_iterator<const T*>(begin(m));
	}
	template<typename T,qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::reverse_iterator<const T*> rend(const qua<T,Q>& q) {
		return std::reverse_iterator<const T*>(begin(q));
	}


	/// @}
}//namespace glm
