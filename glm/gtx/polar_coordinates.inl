/// @ref gtx_polar_coordinates

namespace glm
{
	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, T, Q> polar
	(
		vec<3, T, Q> const& euclidean
	)
	{
		T const Length(length(euclidean));
		vec<3, T, Q> const tmp(euclidean / Length);

		return vec<3, T, Q>(
			asin(tmp.y),	// latitude
			atan(tmp.x, tmp.z),		// longitude
			Length); // radial distance
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, T, Q> euclidean
	(
		vec<2, T, Q> const& polar
	)
	{
		T const latitude(polar.x);
		T const longitude(polar.y);

		return vec<3, T, Q>(
			cos(latitude) * sin(longitude),
			sin(latitude),
			cos(latitude) * cos(longitude));
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, T, Q> euclidean
	(
		vec<3, T, Q> const& polar
	)
	{
		T const RadialDistance(polar.z);

		if(isinf(static_cast<T>(1) / RadialDistance))
			return vec<3, T, Q>(static_cast<T>(0));

		return RadialDistance * euclidean(vec<2, T, Q>(polar.x, polar.y));
	}

}//namespace glm
