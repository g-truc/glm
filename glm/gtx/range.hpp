/// @ref gtx_range
/// @file glm/gtx/range.hpp
/// @author Joshua Moerman
///
/// @defgroup gtx_range GLM_GTX_range
/// @ingroup gtx
///
/// Include <glm/gtx/range.hpp> to use the features of this extension.
///
/// Defines begin and end for vectors and matrices. Useful for range-based for loop.
/// The range is defined over the elements, not over columns or rows (e.g. mat4 has 16 elements).

#pragma once

// Dependencies
#include "../detail/setup.hpp"

#ifndef GLM_ENABLE_EXPERIMENTAL
#	error "GLM: GLM_GTX_range is an experimental extension and may change in the future. Use #define GLM_ENABLE_EXPERIMENTAL before including it, if you really want to use it."
#elif GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_GTX_range extension included")
#endif

#include "../gtc/type_ptr.hpp"
#include "type_trait.hpp"

namespace glm
{
	/// @addtogroup gtx_range
	/// @{

#if GLM_COMPILER & GLM_COMPILER_VC
#	pragma warning(push)
#	pragma warning(disable : 4100) // unreferenced formal parameter
#endif

	/// @warning This is not same as `type<genType>::components`, calling this returns total elements (for mat4 returns 16 instead of 4).
	template<typename genType>
	/*GLM_DEPRECATED*/ GLM_NODISCARD GLM_FUNC_QUALIFIER GLM_CONSTEXPR length_t components(genType const& v)
	{
		return type<std::remove_cv<genType>::type>::elements;
	}

#if GLM_COMPILER & GLM_COMPILER_VC
#	pragma warning(pop)
#endif

	template<typename genType>
	GLM_NODISCARD GLM_FUNC_QUALIFIER GLM_CONSTEXPR typename genType::value_type const * begin(genType const& v)
	{
		return value_ptr(v);
	}

	template<typename genType>
	GLM_NODISCARD GLM_FUNC_QUALIFIER GLM_CONSTEXPR typename genType::value_type const * end(genType const& v)
	{
		return begin(v) + type<std::remove_cv<genType>::type>::elements;
	}

	template<typename genType>
	GLM_NODISCARD GLM_FUNC_QUALIFIER GLM_CONSTEXPR typename genType::value_type * begin(genType& v)
	{
		return value_ptr(v);
	}

	template<typename genType>
	GLM_NODISCARD GLM_FUNC_QUALIFIER GLM_CONSTEXPR typename genType::value_type * end(genType& v)
	{
		return begin(v) + type<std::remove_cv<genType>::type>::elements;
	}

	/// @}
}//namespace glm
