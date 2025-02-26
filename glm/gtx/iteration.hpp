/// @ref gtx_iteration
/// @file glm/gtx/iteration.hpp
/// 
/// @defgroup gtx_iteration GLM_GTX_iteration
/// @ingroup gtx
///
/// Include <glm/gtx/iteration.hpp> to use the features of this extension.
///
/// Defines begin and end for vectors, matrices and quaternions useful for range based for loop construct

#pragma once

// Dependencies
#include "../detail/setup.hpp"
#include "../detail/qualifier.hpp"

#ifndef GLM_ENABLE_EXPERIMENTAL
#	error "GLM: GLM_GTX_iteration is an experimental extension and may change in the future. Use #define GLM_ENABLE_EXPERIMENTAL before including it, if you really want to use it."
#elif GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_GTX_iteration extension included")
#endif

#include <iterator>

namespace glm
{
	/// @addtogroup gtx_iteration
	/// @{
	template<length_t L,typename T,qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR T* begin(vec<L, T, Q>& v);
	template<length_t C,length_t R,typename T,qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR T* begin(mat<C, R, T, Q>& m);
	template<typename T,qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR T* begin(qua<T, Q>& q);
	template<length_t L,typename T,qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR const T* begin(const vec<L, T, Q>& v);
	template<length_t C,length_t R,typename T,qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR const T* begin(const mat<C, R, T, Q>& m);
	template<typename T,qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR const T* begin(const qua<T, Q>& q);

	template<length_t L,typename T,qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR T* end(vec<L, T, Q>& v);
	template<length_t C,length_t R,typename T,qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR T* end(mat<C, R, T, Q>& m);
	template<typename T,qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR T* end(qua<T, Q>& q);
	template<length_t L,typename T,qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR const T* end(const vec<L, T, Q>& v);
	template<length_t C,length_t R,typename T,qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR const T* end(const mat<C, R, T, Q>& m);
	template<typename T,qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR const T* end(const qua<T, Q>& q);

	// Reverse iteration
	// rbegin,rend
	template<length_t L,typename T,qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR std::reverse_iterator<T*> rbegin(vec<L, T, Q>& v);
	template<length_t C,length_t R,typename T,qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR std::reverse_iterator<T*> rbegin(mat<C, R, T, Q>& m);
	template<typename T,qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR std::reverse_iterator<T*> rbegin(qua<T, Q>& q);
	template<length_t L,typename T,qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR std::reverse_iterator<const T*> rbegin(const vec<L, T, Q>& v);
	template<length_t C,length_t R,typename T,qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR std::reverse_iterator<const T*> rbegin(const mat<C, R, T, Q>& m);
	template<typename T,qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR std::reverse_iterator<const T*> rbegin(const qua<T, Q>& q);

	template<length_t L,typename T,qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR std::reverse_iterator<T*> rend(vec<L, T, Q>& v);
	template<length_t C,length_t R,typename T,qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR std::reverse_iterator<T*> rend(mat<C, R, T, Q>& m);
	template<typename T,qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR std::reverse_iterator<T*> rend(qua<T, Q>& q);
	template<length_t L,typename T,qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR std::reverse_iterator<const T*> rend(const vec<L, T, Q>& v);
	template<length_t C,length_t R,typename T,qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR std::reverse_iterator<const T*> rend(const mat<C, R, T, Q>& m);
	template<typename T,qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR std::reverse_iterator<const T*> rend(const qua<T, Q>& q);


	/// @}
}//namespace glm

#include "iteration.inl"
