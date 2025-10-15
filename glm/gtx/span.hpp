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

// `std::enable_if` support (and few more)
// Required for all functions below
#if !(GLM_LANG & GLM_LANG_CXX11_FLAG)
#	error "GLM_GTX_span requiers at least C++11, using C++20 or C++23 is recommended for full functionality"
#endif

// GLM_MESSAGES info
#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	if (GLM_LANG & GLM_LANG_CXX20_FLAG) && defined(__cpp_lib_span) && __cpp_lib_span >= 202002L
#		pragma message("GLM: GLM_GTX_span extension will include std::span")
#	endif
#	if (GLM_LANG & GLM_LANG_CXX23_FLAG) && defined(__cpp_lib_mdspan) && __cpp_lib_mdspan >= 202207L
#		pragma message("GLM: GLM_GTX_span extension will include std::mdspan")
#	endif
#endif

#include "../gtc/type_ptr.hpp"
#include "type_trait.hpp"

#include <valarray>

// Version-specific includes
#if GLM_LANG & GLM_LANG_CXX20_FLAG
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

#	if (GLM_LANG & GLM_LANG_CXX20_FLAG)
	template<typename T>
		requires (type<std::remove_cvref_t<T>>::elements > 0)
#	else
	template<typename T, typename = typename std::enable_if<
		(
			type<
				typename std::remove_reference<
					typename std::remove_cv<T>::type
				>::type
			>::elements > 0
		)>::type>
#	endif
	GLM_NODISCARD GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::valarray<typename T::value_type> valarray(T const& v)
	{
		return std::valarray<typename T::value_type>(value_ptr(v), type<T>::elements);
	}

#if (GLM_LANG & GLM_LANG_CXX20_FLAG) && defined(__cpp_lib_span) && __cpp_lib_span >= 202002L

	template<typename T>
		requires (type<std::remove_cvref_t<T>>::elements > 0)
	GLM_NODISCARD GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::span<typename T::value_type> span(T & v)
	{
		using TN = std::remove_cvref_t<T>;
		return std::span<typename T::value_type>(value_ptr(v), type<TN>::elements);
	}

	template<typename T>
		requires (type<std::remove_cvref_t<T>>::elements > 0)
	GLM_NODISCARD GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::span<const typename T::value_type> span(T const& v)
	{
		using TN = std::remove_cvref_t<T>;
		return std::span<const typename T::value_type>(value_ptr(v), type<TN>::elements);
	}

#endif

#if (GLM_LANG & GLM_LANG_CXX23_FLAG) && defined(__cpp_lib_mdspan) && __cpp_lib_mdspan >= 202207L

	template<typename T>
		requires (type<std::remove_cvref_t<T>>::rows == 1)
	GLM_NODISCARD GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::mdspan<typename T::value_type> span(T & v)
	{
		using TN = std::remove_cvref_t<T>;
		static_assert(type<TN>::cols >= 1);
		return std::mdspan<typename T::value_type>(value_ptr(v), type<TN>::cols);
	}

	template<typename T>
		requires (type<std::remove_cvref_t<T>>::rows == 1)
	GLM_NODISCARD GLM_FUNC_QUALIFIER GLM_CONSTEXPR std::mdspan<const typename T::value_type> span(T const& v)
	{
		using TN = std::remove_cvref_t<T>;
		static_assert(type<TN>::cols >= 1);
		return std::mdspan<const typename T::value_type>(value_ptr(v), type<TN>::cols);
	}

	template<typename T>
		requires (type<std::remove_cvref_t<T>>::rows > 1)
	GLM_NODISCARD GLM_FUNC_QUALIFIER GLM_CONSTEXPR auto mdspan(T & m)
	{
		using TN = std::remove_cvref_t<T>;
		static_assert(type<TN>::cols >= 1);
		return std::mdspan<typename T::value_type>(value_ptr(m), type<TN>::cols, type<TN>::rows);
	}

	template<typename T>
		requires (type<std::remove_cvref_t<T>>::rows > 1)
	GLM_NODISCARD GLM_FUNC_QUALIFIER GLM_CONSTEXPR auto mdspan(T const& m)
	{
		using TN = std::remove_cvref_t<T>;
		static_assert(type<TN>::cols >= 1);
		return std::mdspan<const typename T::value_type>(value_ptr(m), type<TN>::cols, type<TN>::rows);
	}

#endif

	/// @}
}//namespace glm
