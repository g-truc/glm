/// @ref gtx_structured_bindings
/// @file glm/gtx/structured_bindings.hpp
///
/// @defgroup gtx_structured_bindings GLM_GTX_structured_bindings
/// @ingroup gtx
///
/// Include <glm/gtx/structured_bindings.hpp> to use the features of this extension.

#pragma once

// Dependency:
#include "../glm.hpp"
#include "../gtx/quaternion.hpp"

#ifdef __cpp_structured_bindings
#if __cpp_structured_bindings >= 201606L
#include <utility>
#include <cstddef>
namespace std {
	template<glm::length_t L,typename T,glm::qualifier Q>
	struct tuple_size<glm::vec<L, T, Q>> {
		static constexpr size_t value = L;
	};
	template<glm::length_t C,glm::length_t R, typename T, glm::qualifier Q>
	struct tuple_size<glm::mat<C,R, T, Q>> {
		static constexpr size_t value = C;
	};
	template<typename T, glm::qualifier Q>
	struct tuple_size<glm::qua<T, Q>> {
		static constexpr size_t value = 4;
	};
	template<std::size_t I,glm::length_t L,typename T,glm::qualifier Q>
	struct tuple_element<I, glm::vec<L,T,Q>>
	{
		static_assert(I < L,"Index out of bounds");
		typedef T type;
	};
	template<std::size_t I, glm::length_t C, glm::length_t R, typename T, glm::qualifier Q>
	struct tuple_element<I, glm::mat<C,R, T, Q>>
	{
		static_assert(I < C, "Index out of bounds");
		typedef glm::vec<R,T,Q> type;
	};
	template<std::size_t I, typename T, glm::qualifier Q>
	struct tuple_element<I, glm::qua<T, Q>>
	{
		static_assert(I < 4, "Index out of bounds");
		typedef T type;
	};

}
#endif
#endif

#ifndef GLM_ENABLE_EXPERIMENTAL
#	error "GLM: GLM_GTX_iteration is an experimental extension and may change in the future. Use #define GLM_ENABLE_EXPERIMENTAL before including it, if you really want to use it."
#elif GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_GTX_io extension included")
#endif

namespace glm
{
	/// @addtogroup gtx_structured_bindings
	/// @{

	template<length_t I, length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR T& get(vec<L, T, Q>& v);
	template<length_t I, length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR T const& get(vec<L, T, Q> const& v);

	template<length_t I, length_t C, length_t R, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<R, T, Q>& get(mat<C, R, T, Q>& m);
	template<length_t I, length_t C, length_t R, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<R, T, Q> const& get(mat<C, R, T, Q> const& m);

	template<length_t I, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR T& get(qua<T, Q>& q);
	template<length_t I, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR T const& get(qua<T, Q> const& q);

	template<length_t I, length_t L,typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR T get(vec<L,T, Q> const&& v);
	template<length_t I,length_t C,length_t R, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<R,T,Q> get(mat<C,R,T, Q> const&& m);
	template<length_t I, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR T get(qua<T, Q> const&& q);
	/// @}
}//namespace glm

#include "structured_bindings.inl"
