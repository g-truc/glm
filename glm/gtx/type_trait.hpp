/// @ref gtx_type_trait
/// @file glm/gtx/type_trait.hpp
///
/// @see core (dependence)
///
/// @defgroup gtx_type_trait GLM_GTX_type_trait
/// @ingroup gtx
///
/// Include <glm/gtx/type_trait.hpp> to use the features of this extension.
///
/// Defines traits for each type.

#pragma once

#ifndef GLM_ENABLE_EXPERIMENTAL
#	error "GLM: GLM_GTX_type_trait is an experimental extension and may change in the future. Use #define GLM_ENABLE_EXPERIMENTAL before including it, if you really want to use it."
#elif GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_GTX_type_trait extension included")
#endif

// Dependency:
#include "../detail/qualifier.hpp"
#include "../gtc/quaternion.hpp"
#include "../gtx/dual_quaternion.hpp"

namespace glm
{
	/// @addtogroup gtx_type_trait
	/// @{

	template<typename T>
	struct type
	{
		enum {
			is_vec = false,
			is_mat = false,
			is_quat = false,
			components = 0,
			cols = 0,
			rows = 0
		};
	};

	template<length_t L, typename T, qualifier Q>
	struct type<vec<L, T, Q> >
	{
		enum {
			is_vec = true,
			is_mat = false,
			is_quat = false,
			components = L
		};
	};

	template<length_t C, length_t R, typename T, qualifier Q>
	struct type<mat<C, R, T, Q> >
	{
		enum {
			is_vec = false,
			is_mat = true,
			is_quat = false,
			components = C,
			cols = C,
			rows = R
		};
	};

	template<typename T, qualifier Q>
	struct type<qua<T, Q> >
	{
		enum {
			is_vec = false,
			is_mat = false,
			is_quat = true,
			components = 4
		};
	};

	template<typename T, qualifier Q>
	struct type<tdualquat<T, Q> >
	{
		enum {
			is_vec = false,
			is_mat = false,
			is_quat = true,
			components = 8
		};
	};

	/// @}
}//namespace glm

