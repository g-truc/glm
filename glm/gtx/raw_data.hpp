/// @ref gtx_raw_data
/// @file glm/gtx/raw_data.hpp
///
/// @see core (dependence)
///
/// @defgroup gtx_raw_data GLM_GTX_raw_data
/// @ingroup gtx
///
/// Include <glm/gtx/raw_data.hpp> to use the features of this extension.
///
/// Projection of a vector to other one

#pragma once

// Dependencies
#include "../ext/scalar_uint_sized.hpp"
#include "../detail/setup.hpp"

#ifndef GLM_ENABLE_EXPERIMENTAL
#	error "GLM: GLM_GTX_raw_data is an experimental extension and may change in the future. Use #define GLM_ENABLE_EXPERIMENTAL before including it, if you really want to use it."
#elif GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_GTX_raw_data extension included")
#endif

namespace glm
{
	/// @addtogroup gtx_raw_data
	/// @{

	//! Type for byte numbers.
	//! From GLM_GTX_raw_data extension.
	using		byte = detail::uint8;

	//! Type for word numbers.
	//! From GLM_GTX_raw_data extension.
	using		word = detail::uint16;

	//! Type for dword numbers.
	//! From GLM_GTX_raw_data extension.
	using		dword = detail::uint32;

	//! Type for qword numbers.
	//! From GLM_GTX_raw_data extension.
	using		qword = detail::uint64;

	/// @}
}// namespace glm

#include "raw_data.inl"
