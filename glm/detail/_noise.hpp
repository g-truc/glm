#pragma once

#include "../common.hpp"

namespace glm{
namespace detail
{
	template<typename T>
	GLM_FUNC_QUALIFIER T mod289(T const& x)
	{
		return x - floor(x * (static_cast<T>(1.0) / static_cast<T>(289.0))) * static_cast<T>(289.0);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER T permute(T const& x)
	{
		return mod289(((x * static_cast<T>(34)) + static_cast<T>(1)) * x);
	}

	template<length_t L,typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> permute(vec<L, T, Q> const& x)
	{
		return mod289(((x * static_cast<T>(34)) + static_cast<T>(1)) * x);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER T taylorInvSqrt(T const& r)
	{
		return static_cast<T>(1.79284291400159) - static_cast<T>(0.85373472095314) * r;
	}

	template<length_t L,typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> taylorInvSqrt(vec<L, T, Q> const& r)
	{
		return static_cast<T>(1.79284291400159) - static_cast<T>(0.85373472095314) * r;
	}

	template<length_t L,typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> fade(vec<L, T, Q> const& t)
	{
		return (t * t * t) * (t * (t * static_cast<T>(6) - static_cast<T>(15)) + static_cast<T>(10));
	}
}//namespace detail
}//namespace glm

