/// @ref gtx_extend

namespace glm
{
	template<typename genType>
	GLM_FUNC_QUALIFIER genType extend
	(
		genType const& Origin,
		genType const& Source,
		genType const& Distance
	)
	{
		return Origin + (Source - Origin) * Distance;
	}

	template<length_t L,typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> extend
	(
		vec<L, T, Q> const& Origin,
		vec<L, T, Q> const& Source,
		T const& Distance
	)
	{
		return Origin + (Source - Origin) * Distance;
	}

}//namespace glm
