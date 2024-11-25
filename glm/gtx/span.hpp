/// @ref gtx_span
/// @file glm/gtx/span.hpp
/// @author Abit Gray
///
/// @defgroup gtx_span GLM_GTX_span
/// @ingroup gtx
///
/// Include <glm/gtx/span.hpp> to use the features of this extension.
///
/// Defines functions to convert glm types to std::valarray or view them using C++20 std::span and C++23 std::mdspan.

#pragma once

// Dependencies
#include "../detail/setup.hpp"

#ifndef GLM_ENABLE_EXPERIMENTAL
#	error "GLM: GLM_GTX_span is an experimental extension and may change in the future. Use #define GLM_ENABLE_EXPERIMENTAL before including it, if you really want to use it."
#elif GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_GTX_span extension included")
#endif

#if !(GLM_LANG & GLM_LANG_CXX11)
// This requirement is due to `std::enable_if`
#	error "GLM_GTX_span requiers at least C++11, using C++20 or C++23 is recommended for full functionality"
#endif

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	if (GLM_LANG & GLM_LANG_CXX20) && defined(__cpp_lib_span) && __cpp_lib_span >= 202002L
#		pragma message("GLM: GLM_GTX_span extension will include std::span")
#	endif
#	if (GLM_LANG & GLM_LANG_CXX23) && defined(__cpp_lib_mdspan) && __cpp_lib_mdspan >= 202207L
#		pragma message("GLM: GLM_GTX_span extension will include std::mdspan")
#	endif
#endif

#include "../gtc/type_precision.hpp"
#include "../gtc/type_ptr.hpp"

#include <valarray>
#include <type_traits>

#if GLM_LANG & GLM_LANG_CXX20
// Feature testing
#	include <version>

// C++20 std::span
#	if defined(__cpp_lib_span) && __cpp_lib_span >= 202002L
#		include <span>
#	endif

// C++23 std::mdspan
#	if (GLM_LANG & GLM_LANG_CXX23) && defined(__cpp_lib_mdspan) && __cpp_lib_mdspan >= 202207L
#		include <mdspan>
#	endif
#endif

namespace glm
{
	/// @addtogroup gtx_span
	/// @{

	template<typename T>
	struct is_vec : std::false_type {};
	template<length_t L, typename T, qualifier Q>
	struct is_vec<vec<L, T, Q>> : std::true_type {};

	template<typename T>
	struct is_quat : std::false_type {};
	template<typename T, qualifier Q>
	struct is_quat<qua<T, Q>> : std::true_type {};

	template<typename T>
	struct is_mat : std::false_type {};
	template<length_t L1, length_t L2, typename T, qualifier Q>
	struct is_mat<mat<L1, L2, T, Q>> : std::true_type {};

#if (GLM_LANG & GLM_LANG_CXX17)
	template<typename T>
	inline constexpr bool is_vec_v = is_vec<T>::value;
	template<typename T>
	inline constexpr bool is_quat_v = is_quat<T>::value;
	template<typename T>
	inline constexpr bool is_mat_v = is_mat<T>::value;
#endif

#if (GLM_LANG & GLM_LANG_CXX20)
	template<typename T>
		requires is_vec<T>::value || is_quat<T>::value
#else
	template<typename T, typename = typename std::enable_if<is_vec<T>::value || is_quat<T>::value>::type>
#endif
	GLM_NODISCARD GLM_FUNC_QUALIFIER GLM_CONSTEXPR length_t components()
	{
		return T::length();
	}
#if (GLM_LANG & GLM_LANG_CXX20)
	template<typename T>
		requires is_mat<T>::value
#else
	template<typename T, typename = typename std::enable_if<is_mat<T>::value>::type>
#endif
	GLM_NODISCARD GLM_FUNC_QUALIFIER GLM_CONSTEXPR length_t components()
	{
		return T::length() * T::col_type::length();
	}
#	if GLM_COMPILER & GLM_COMPILER_VC
#		pragma warning(push)
#		pragma warning(disable : 4100) // unreferenced formal parameter
#	endif

	/// Utility function if you don't have the type and dont use `decltype` (it is from C++11 so this function won't exist for earlier anyway)
#if (GLM_LANG & GLM_LANG_CXX20)
	template<typename T>
		requires is_vec<T>::value || is_quat<T>::value
#else
	template<typename T, typename = typename std::enable_if<is_vec<T>::value || is_quat<T>::value>::type>
#endif
	GLM_NODISCARD GLM_FUNC_QUALIFIER GLM_CONSTEXPR length_t components(T const&)
	{
		return components<T>();
	}
#	if GLM_COMPILER & GLM_COMPILER_VC
#		pragma warning(pop)
#	endif

#if (GLM_LANG & GLM_LANG_CXX20)
	template<typename T>
		requires is_vec<T>::value || is_quat<T>::value || is_mat<T>::value
#else
	template<typename T, typename = typename std::enable_if<is_vec<T>::value || is_quat<T>::value || is_mat<T>::value>::type>
#endif
	GLM_NODISCARD GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::valarray<typename T::value_type> valarray(T const& v)
	{
		return std::valarray<typename T::value_type>(value_ptr(v), components<T>());
	}

#if (GLM_LANG & GLM_LANG_CXX20) && defined(__cpp_lib_span) && __cpp_lib_span >= 202002L

#if (GLM_LANG & GLM_LANG_CXX20)
	template<typename T>
		requires is_vec<T>::value || is_quat<T>::value || is_mat<T>::value
#else
	template<typename T, typename = typename std::enable_if<is_vec<T>::value || is_quat<T>::value || is_mat<T>::value>::type>
#endif
	GLM_NODISCARD GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::span<typename T::value_type> span(T & v)
	{
		return std::span<typename T::value_type>(value_ptr(v), components<T>());
	}

#if (GLM_LANG & GLM_LANG_CXX20)
	template<typename T>
		requires is_vec<T>::value || is_quat<T>::value || is_mat<T>::value
#else
	template<typename T, typename = typename std::enable_if<is_vec<T>::value || is_quat<T>::value || is_mat<T>::value>::type>
#endif
	GLM_NODISCARD GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::span<const typename T::value_type> span(T const& v)
	{
		return std::span<const typename T::value_type>(value_ptr(v), components<T>());
	}

#endif

#if (GLM_LANG & GLM_LANG_CXX23) && defined(__cpp_lib_mdspan) && __cpp_lib_mdspan >= 202207L

#if (GLM_LANG & GLM_LANG_CXX20)
	template<typename T>
		requires is_vec<T>::value || is_quat<T>::value
#else
	template<typename T, typename = typename std::enable_if<is_vec<T>::value || is_quat<T>::value>::type>
#endif
	GLM_NODISCARD GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::mdspan<typename T::value_type> span(T & v)
	{
		return std::mdspan<typename T::value_type>(value_ptr(v), components<T>());
	}

#if (GLM_LANG & GLM_LANG_CXX20)
	template<typename T>
		requires is_vec<T>::value || is_quat<T>::value
#else
	template<typename T, typename = typename std::enable_if<is_vec<T>::value || is_quat<T>::value>::type>
#endif
	GLM_NODISCARD GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::mdspan<const typename T::value_type> span(T const& v)
	{
		return std::mdspan<const typename T::value_type>(value_ptr(v), components<T>());
	}

	template<length_t L1, length_t L2, typename T, qualifier Q>
	GLM_NODISCARD GLM_FUNC_QUALIFIER GLM_CONSTEXPR auto mdspan(mat<L1, L2, T, Q> & m)
	{
		return std::mdspan<T>(value_ptr(m), L1, L2);
	}

	template<length_t L1, length_t L2, typename T, qualifier Q>
	GLM_NODISCARD GLM_FUNC_QUALIFIER GLM_CONSTEXPR auto mdspan(mat<L1, L2, T, Q> const& m)
	{
		return std::mdspan<const T>(value_ptr(m), L1, L2);
	}

#endif

	/// @}
}//namespace glm
