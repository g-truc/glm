/// @ref gtx_exterior_product
/// @file glm/gtx/exterior_product.hpp
///
/// @see core (dependence)
/// @see gtx_exterior_product (dependence)
///
/// @defgroup gtx_exterior_product GLM_GTX_exterior_product
/// @ingroup gtx
/// 
/// @brief Allow to perform bit operations on integer values
/// 
/// <glm/gtc/bitfield.hpp> need to be included to use these functionalities.

#pragma once

// Dependencies
#include "../detail/setup.hpp"
#include "../detail/precision.hpp"

#if GLM_MESSAGES == GLM_MESSAGES_ENABLED && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_GTX_exterior_product extension included")
#endif

namespace glm
{
	/// @addtogroup gtx_exterior_product
	/// @{

	/// Returns the cross product of x and y.
	///
	/// @tparam valType Floating-point scalar types.
	/// 
	/// @see <a href="https://en.wikipedia.org/wiki/Exterior_algebra#Cross_and_triple_products">Exterior product</a>
	template<typename T, precision P>
	GLM_FUNC_DECL T cross(vec<2, T, P> const& v, vec<2, T, P> const& u);

	/// @}
} //namespace glm

#include "exterior_product.inl"
