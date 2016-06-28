/// @ref gtx_wrap
/// @file glm/gtx/wrap.inl

namespace glm
{
	template <typename genType> 
	GLM_FUNC_QUALIFIER genType clamp(genType const & Texcoord)
	{
		return glm::clamp(Texcoord, genType(0), genType(1));
	}

	template <typename T, precision P> 
	GLM_FUNC_QUALIFIER tvec2<T, P> clamp(tvec2<T, P> const & Texcoord)
	{
		tvec2<T, P> Result;
		for(typename tvec2<T, P>::size_type i = 0; i < tvec2<T, P>::value_size(); ++i)
			Result[i] = clamp_to_edge(Texcoord[i]);
		return Result;
	}

	template <typename T, precision P> 
	GLM_FUNC_QUALIFIER tvec3<T, P> clamp(tvec3<T, P> const & Texcoord)
	{
		tvec3<T, P> Result;
		for(typename tvec3<T, P>::size_type i = 0; i < tvec3<T, P>::value_size(); ++i)
			Result[i] = clamp_to_edge(Texcoord[i]);
		return Result;
	}

	template <typename T, precision P> 
	GLM_FUNC_QUALIFIER tvec4<T, P> clamp(tvec4<T, P> const & Texcoord)
	{
		tvec4<T, P> Result;
		for(typename tvec4<T, P>::size_type i = 0; i < tvec4<T, P>::value_size(); ++i)
			Result[i] = clamp_to_edge(Texcoord[i]);
		return Result;
	}

	template <typename genType>
	GLM_FUNC_QUALIFIER genType repeat(genType const & Texcoord)
	{
		return glm::fract(Texcoord);
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tvec2<T, P> repeat(tvec2<T, P> const & Texcoord)
	{
		tvec2<T, P> Result;
		for(typename tvec2<T, P>::size_type i = 0; i < tvec2<T, P>::value_size(); ++i)
			Result[i] = repeat(Texcoord[i]);
		return Result;
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tvec3<T, P> repeat(tvec3<T, P> const & Texcoord)
	{
		tvec3<T, P> Result;
		for(typename tvec3<T, P>::size_type i = 0; i < tvec3<T, P>::value_size(); ++i)
			Result[i] = repeat(Texcoord[i]);
		return Result;
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tvec4<T, P> repeat(tvec4<T, P> const & Texcoord)
	{
		tvec4<T, P> Result;
		for(typename tvec4<T, P>::size_type i = 0; i < tvec4<T, P>::value_size(); ++i)
			Result[i] = repeat(Texcoord[i]);
		return Result;
	}

	template <typename genType>
	GLM_FUNC_QUALIFIER genType mirrorClamp(genType const & Texcoord)
	{
		return glm::fract(glm::abs(Texcoord));
		//return glm::mod(glm::abs(Texcoord), 1.0f);
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tvec2<T, P> mirrorClamp(tvec2<T, P> const & Texcoord)
	{
		tvec2<T, P> Result;
		for(typename tvec2<T, P>::size_type i = 0; i < tvec2<T, P>::value_size(); ++i)
			Result[i] = mirrorClamp(Texcoord[i]);
		return Result;
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tvec3<T, P> mirrorClamp(tvec3<T, P> const & Texcoord)
	{
		tvec3<T, P> Result;
		for(typename tvec3<T, P>::size_type i = 0; i < tvec3<T, P>::value_size(); ++i)
			Result[i] = mirrorClamp(Texcoord[i]);
		return Result;
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tvec4<T, P> mirrorClamp(tvec4<T, P> const & Texcoord)
	{
		tvec4<T, P> Result;
		for(typename tvec4<T, P>::size_type i = 0; i < tvec4<T, P>::value_size(); ++i)
			Result[i] = mirrorClamp(Texcoord[i]);
		return Result;
	}

	template <typename genType>
	GLM_FUNC_QUALIFIER genType mirrorRepeat(genType const & Texcoord)
	{
		genType const Abs = glm::abs(Texcoord);
		genType const Clamp = genType(int(glm::floor(Abs)) % 2);
		genType const Floor = glm::floor(Abs);
		genType const Rest = Abs - Floor;
		genType const Mirror = Clamp + Rest;

		genType Out;
		if(Mirror >= genType(1))
			Out = genType(1) - Rest;
		else
			Out = Rest;
		return Out;
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tvec2<T, P> mirrorRepeat(tvec2<T, P> const & Texcoord)
	{
		tvec2<T, P> Result;
		for(typename tvec2<T, P>::size_type i = 0; i < tvec2<T, P>::value_size(); ++i)
			Result[i] = mirrorRepeat(Texcoord[i]);
		return Result;
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tvec3<T, P> mirrorRepeat(tvec3<T, P> const & Texcoord)
	{
		tvec3<T, P> Result;
		for(typename tvec3<T, P>::size_type i = 0; i < tvec3<T, P>::value_size(); ++i)
			Result[i] = mirrorRepeat(Texcoord[i]);
		return Result;
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tvec4<T, P> mirrorRepeat(tvec4<T, P> const & Texcoord)
	{
		tvec4<T, P> Result;
		for(typename tvec4<T, P>::size_type i = 0; i < tvec4<T, P>::value_size(); ++i)
			Result[i] = mirrorRepeat(Texcoord[i]);
		return Result;
	}
}//namespace glm
