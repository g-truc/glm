///////////////////////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 - 2013 G-Truc Creation (www.g-truc.net)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Created : 2009-10-26
// Updated : 2011-06-07
// Licence : This source is under MIT License
// File    : glm/gtx/multiple.inl
///////////////////////////////////////////////////////////////////////////////////////////////////
// Dependency:
// - GLM core
///////////////////////////////////////////////////////////////////////////////////////////////////

namespace glm
{
	//////////////////////
	// higherMultiple

	template <typename genType>
	GLM_FUNC_QUALIFIER genType higherMultiple
	(
		genType const & Source,
		genType const & Multiple
	)
	{
		if (Source > genType(0))
		{
			genType Tmp = Source - genType(1);
			return Tmp + (Multiple - (Tmp % Multiple));
		}
		else
			return Source + (-1*Source % Multiple);
	}

	template <>
	GLM_FUNC_QUALIFIER detail::half higherMultiple
	(
		detail::half const & SourceH,
		detail::half const & MultipleH
	)
	{
		float Source = SourceH.toFloat();
		float Multiple = MultipleH.toFloat();

		if (Source > float(0))
		{
			float Tmp = Source - float(1);
			return detail::half(Tmp + (Multiple - std::fmod(Tmp, Multiple)));
		}
		else
			return detail::half(Source + std::fmod(-Source, Multiple));
	}

	template <>
	GLM_FUNC_QUALIFIER float higherMultiple
	(	
		float const & Source,
		float const & Multiple
	)
	{
		if (Source > float(0))
		{
			float Tmp = Source - float(1);
			return Tmp + (Multiple - std::fmod(Tmp, Multiple));
		}
		else
			return Source + std::fmod(-Source, Multiple);
	}

	template <>
	GLM_FUNC_QUALIFIER double higherMultiple
	(
		double const & Source,
		double const & Multiple
	)
	{
		if (Source > double(0))
		{
			double Tmp = Source - double(1);
			return Tmp + (Multiple - std::fmod(Tmp, Multiple));
		}
		else
			return Source + std::fmod(-Source, Multiple);
	}

	VECTORIZE_VEC_VEC(higherMultiple)

	//////////////////////
	// lowerMultiple

	template <typename genType>
	GLM_FUNC_QUALIFIER genType lowerMultiple
	(
		genType const & Source,
		genType const & Multiple
	)
	{
		if (Source >= genType(0))
			return Source - Source % Multiple;
		else
		{
			genType Tmp = Source + genType(1);
			return Tmp - Tmp % Multiple - Multiple;
		}
	}

	template <>
	GLM_FUNC_QUALIFIER detail::half lowerMultiple
	(
		detail::half const & SourceH,
		detail::half const & MultipleH
	)
	{
		float Source = SourceH.toFloat();
		float Multiple = MultipleH.toFloat();

		if (Source >= float(0))
			return detail::half(Source - std::fmod(Source, Multiple));
		else
		{
			float Tmp = Source + float(1);
			return detail::half(Tmp - std::fmod(Tmp, Multiple) - Multiple);
		}
	}

	template <>
	GLM_FUNC_QUALIFIER float lowerMultiple
	(
		float const & Source,
		float const & Multiple
	)
	{
		if (Source >= float(0))
			return Source - std::fmod(Source, Multiple);
		else
		{
			float Tmp = Source + float(1);
			return Tmp - std::fmod(Tmp, Multiple) - Multiple;
		}
	}

	template <>
	GLM_FUNC_QUALIFIER double lowerMultiple
	(
		double const & Source,
		double const & Multiple
	)
	{
		if (Source >= double(0))
			return Source - std::fmod(Source, Multiple);
		else
		{
			double Tmp = Source + double(1);
			return Tmp - std::fmod(Tmp, Multiple) - Multiple;
		}
	}

	VECTORIZE_VEC_VEC(lowerMultiple)
}//namespace glm
