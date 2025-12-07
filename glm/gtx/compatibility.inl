#include <limits>

namespace glm
{
	// isfinite
	template<typename genType>
	GLM_FUNC_QUALIFIER bool isfinite(genType const& x)
	{
		return std::isfinite(x) != 0;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<1, bool, Q> isfinite(vec<1, T, Q> const& x)
	{
		return vec<1, bool, Q>(
			isfinite(x.x));
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<2, bool, Q> isfinite(vec<2, T, Q> const& x)
	{
		return vec<2, bool, Q>(
			isfinite(x.x),
			isfinite(x.y));
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, bool, Q> isfinite(vec<3, T, Q> const& x)
	{
		return vec<3, bool, Q>(
			isfinite(x.x),
			isfinite(x.y),
			isfinite(x.z));
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<4, bool, Q> isfinite(vec<4, T, Q> const& x)
	{
		return vec<4, bool, Q>(
			isfinite(x.x),
			isfinite(x.y),
			isfinite(x.z),
			isfinite(x.w));
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<4, bool, Q> isfinite(qua<T, Q> const& x)
	{
		return vec<4, bool, Q>(
			isfinite(x.x),
			isfinite(x.y),
			isfinite(x.z),
			isfinite(x.w));
	}

}//namespace glm
