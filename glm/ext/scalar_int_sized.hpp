/// @ref ext_scalar_int_sized
/// @file glm/ext/scalar_int_sized.hpp
///
/// @defgroup ext_scalar_int_sized GLM_EXT_scalar_int_sized
/// @ingroup ext
///
/// Exposes sized signed integer scalar types.
///
/// Include <glm/ext/scalar_int_sized.hpp> to use the features of this extension.
///
/// @see ext_scalar_uint_sized

#pragma once

#include "../detail/setup.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_EXT_scalar_int_sized extension included")
#endif

namespace glm{
	/// @addtogroup ext_scalar_int_sized
	/// @{

	/// 8 bit signed integer type.
	typedef detail::int8		int8;

	/// 16 bit signed integer type.
	typedef detail::int16		int16;

	/// 32 bit signed integer type.
	typedef detail::int32		int32;

	/// 64 bit signed integer type.
	typedef detail::int64		int64;

	/// @}
}//namespace glm
