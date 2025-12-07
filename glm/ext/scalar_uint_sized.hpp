/// @ref ext_scalar_uint_sized
/// @file glm/ext/scalar_uint_sized.hpp
///
/// @defgroup ext_scalar_uint_sized GLM_EXT_scalar_uint_sized
/// @ingroup ext
///
/// Exposes sized unsigned integer scalar types.
///
/// Include <glm/ext/scalar_uint_sized.hpp> to use the features of this extension.
///
/// @see ext_scalar_int_sized

#pragma once

#include "../detail/setup.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_EXT_scalar_uint_sized extension included")
#endif

namespace glm{
	/// @addtogroup ext_scalar_uint_sized
	/// @{

	/// 8 bit unsigned integer type.
	typedef detail::uint8		uint8;

	/// 16 bit unsigned integer type.
	typedef detail::uint16		uint16;

	/// 32 bit unsigned integer type.
	typedef detail::uint32		uint32;

	/// 64 bit unsigned integer type.
	typedef detail::uint64		uint64;

	/// @}
}//namespace glm
