/// @ref gtx_fast_exponential

namespace glm
{
	// fastPow
	template<typename genType>
	GLM_FUNC_QUALIFIER genType fastPow(genType x, genType y)
	{
		return exp(y * log(x));
	}
	
	template<>
	GLM_FUNC_QUALIFIER float fastPow(float x, float y)
	{
		//negative y always reciprocal, pow(x, -y) = 1 / pow(x, abs(-y))
		//when x is lower than 1.0, you can use this formula. pow(x, y) = 1 / glm::fastPow(1 / x, y)
		// ex: when x is '0.3'... pow(0.3, y) = 1 / glm::fastPow(1 / 0.3, y)
		uint32_t mantissa = 1065353216U | ((*(uint32_t*)&x) & 0x007FFFFF);
		float mx = *(float*)&mantissa;
		float lnx = y * float(1.44269504088896338700) * ((((*(uint32_t*)&x) >> 23)-127) * float(0.69314718055994528623) + ((((float(-0.056571767549593956) * mx + float(0.4471786103806078)) * mx - float(1.4699399880154467)) * mx + float(2.8211719569953488)) * mx - float(1.7417780977156199)));
		uint32_t out = ((127U + uint32_t(lnx)) << 23U);
		lnx -= uint32_t(lnx);
		return (*(float*)(&out)) * ((float(0.34400110689651969) * lnx + float(0.65104678030290897)) * lnx + float(1.0024760564002857));
	}
	
	template<>
	GLM_FUNC_QUALIFIER double fastPow(double x, double y)
	{
		//negative y always reciprocal, pow(x, -y) = 1 / pow(x, abs(-y))
		uint64_t mantissa = 4607182418800017408U | ((*(uint64_t*)&x) & 0x000FFFFFFFFFFFFF);
		double mx = *(double*)&mantissa;
		double lnx = y * double(1.44269504088896338700) * ((((*(uint64_t*)&x) >> 52)-1023) * double(0.69314718055994528623) + ((((double(-0.056571767549593956) * mx + double(0.4471786103806078)) * mx - double(1.4699399880154467)) * mx + double(2.8211719569953488)) * mx - double(1.7417780977156199)));
		uint64_t out = ((uint64_t)(1023U + uint64_t(lnx)) << 52U);
		lnx -= uint64_t(lnx);
		return (*(double*)(&out)) * ((double(0.34400110689651969) * lnx + double(0.65104678030290897)) * lnx + double(1.0024760564002857));
	}

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> fastPow(vec<L, T, Q> const& x, vec<L, T, Q> const& y)
	{
		return exp(y * log(x));
	}

	template<typename T>
	GLM_FUNC_QUALIFIER T fastPow(T x, int y)
	{
		T f = static_cast<T>(1);
		for(int i = 0; i < y; ++i)
			f *= x;
		return f;
	}

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> fastPow(vec<L, T, Q> const& x, vec<L, int, Q> const& y)
	{
		vec<L, T, Q> Result;
		for(length_t i = 0, n = x.length(); i < n; ++i)
			Result[i] = fastPow(x[i], y[i]);
		return Result;
	}

	// fastExp
	template<>
	GLM_FUNC_QUALIFIER float fastExp(float x)
	{
		//negative x always reciprocal, exp(-x) = 1 / exp(abs(-x))
		uint32_t out = ((127U + uint32_t(x *= 1.44269504088896338700f)) << 23U);
		float mx = x - uint32_t(x);
		/*
		//(accurate) 2 degree polynomial exp2(), interval [0, 1]
		return (*(float*)(&out)) * ((float(0.34400110689651969) * mx + float(0.65104678030290897)) * mx + float(1.0024760564002857));
		*/
		return (*(float*)(&out)) * (mx + 0.95696433397203284f);
	}
	
	template<>
	GLM_FUNC_QUALIFIER double fastExp(double x)
	{
		//negative x always reciprocal, exp(-x) = 1 / exp(abs(-x))
		uint64_t out = ((uint64_t)(1023U + uint64_t(x *= 1.44269504088896338700)) << 52U);
		double mx = x - uint64_t(x);
		/*
		//(accurate) 2 degree polynomial exp2(), interval [0, 1]
		return (*(double*)(&out)) * ((double(0.34400110689651969) * mx + double(0.65104678030290897)) * mx + double(1.0024760564002857));
		*/
		return (*(double*)(&out)) * (mx + 0.95696433397203284);
	}
	/*  // Try to handle all values of float... but often shower than std::exp, glm::floor and the loop kill the performance
	GLM_FUNC_QUALIFIER float fastExp(float x)
	{
		const float e = 2.718281828f;
		const float IntegerPart = floor(x);
		const float FloatPart = x - IntegerPart;
		float z = 1.f;

		for(int i = 0; i < int(IntegerPart); ++i)
			z *= e;

		const float x2 = FloatPart * FloatPart;
		const float x3 = x2 * FloatPart;
		const float x4 = x3 * FloatPart;
		const float x5 = x4 * FloatPart;
		return z * (1.0f + FloatPart + (x2 * 0.5f) + (x3 * 0.1666666667f) + (x4 * 0.041666667f) + (x5 * 0.008333333333f));
	}

	// Increase accuracy on number bigger that 1 and smaller than -1 but it's not enough for high and negative numbers
	GLM_FUNC_QUALIFIER float fastExp(float x)
	{
		// This has a better looking and same performance in release mode than the following code. However, in debug mode it's slower.
		// return 1.0f + x * (1.0f + x * 0.5f * (1.0f + x * 0.3333333333f * (1.0f + x * 0.25 * (1.0f + x * 0.2f))));
		float x2 = x * x;
		float x3 = x2 * x;
		float x4 = x3 * x;
		float x5 = x4 * x;
		float x6 = x5 * x;
		float x7 = x6 * x;
		float x8 = x7 * x;
		return 1.0f + x + (x2 * 0.5f) + (x3 * 0.1666666667f) + (x4 * 0.041666667f) + (x5 * 0.008333333333f)+ (x6 * 0.00138888888888f) + (x7 * 0.000198412698f) + (x8 * 0.0000248015873f);;
	}
	*/

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> fastExp(vec<L, T, Q> const& x)
	{
		return detail::functor1<vec, L, T, T, Q>::call(fastExp, x);
	}

	// fastLog
	template<typename genType>
	GLM_FUNC_QUALIFIER genType fastLog(genType x)
	{
		return std::log(x);
	}

	// Slower than the VC7.1 function...
	template<>
	GLM_FUNC_QUALIFIER float fastLog(float x)
	{
		//x less than 1 always negative log(0.2) = -log(1 / 0.2)
		uint32_t mantissa = 1065353216U | ((*(uint32_t*)&x) & 0x007FFFFF);
		return (((*(uint32_t*)&x) >> 23)-127) * float(0.69314718055994528623) + ((float(-0.2390307190544787) * (*(float*)&mantissa) + float(1.4033913763229589)) * (*(float*)&mantissa) - float(1.1609366765682689));
	}
	
	template<>
	GLM_FUNC_QUALIFIER double fastLog(double x)
	{
		//x less than 1 always negative log(0.2) = -log(1 / 0.2)
		uint64_t mantissa = 4607182418800017408U | ((*(uint64_t*)&x) & 0x000FFFFFFFFFFFFF);
		return (((*(uint64_t*)&x) >> 52)-1023) * double(0.69314718055994528623) + ((double(-0.2390307190544787) * (*(double*)&mantissa) + double(1.4033913763229589)) * (*(double*)&mantissa) - double(1.1609366765682689));
	}

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> fastLog(vec<L, T, Q> const& x)
	{
		return detail::functor1<vec, L, T, T, Q>::call(fastLog, x);
	}

	//fastExp2, ln2 = 0.69314718055994530941723212145818f
	template<typename genType>
	GLM_FUNC_QUALIFIER genType fastExp2(genType x)
	{
		return fastExp(static_cast<genType>(0.69314718055994530941723212145818) * x);
	}

	template<>
	GLM_FUNC_QUALIFIER float fastExp2(float x)
	{
		//negative x always reciprocal, exp2(-x) = 1 / exp2(abs(-x))		
		uint32_t out = ((127U + uint32_t(x)) << 23U);
		x -= uint32_t(x);
		return (*(float*)(&out)) * ((float(0.34400110689651969) * x + float(0.65104678030290897)) * x + float(1.0024760564002857));
	}
	
	template<>
	GLM_FUNC_QUALIFIER double fastExp2(double x)
	{
		//negative x always reciprocal, exp2(-x) = 1 / exp2(abs(-x))		
		uint64_t out = ((uint64_t)(1023U + uint64_t(x)) << 52U);
		x -= uint64_t(x);
		return (*(double*)(&out)) * ((double(0.34400110689651969) * x + double(0.65104678030290897)) * x + double(1.0024760564002857));
	}

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> fastExp2(vec<L, T, Q> const& x)
	{
		return detail::functor1<vec, L, T, T, Q>::call(fastExp2, x);
	}

	// fastLog2, ln2 = 0.69314718055994530941723212145818f
	template<typename genType>
	GLM_FUNC_QUALIFIER genType fastLog2(genType x)
	{
		return fastLog(x) / static_cast<genType>(0.69314718055994530941723212145818);
	}
	
	template<>
	GLM_FUNC_QUALIFIER float fastLog2(float x)
	{
		uint32_t mantissa = 1065353216U | ((*(uint32_t*)&x) & 0x007FFFFF);
		return (((*(uint32_t*)&x) >> 23)-127) + ((float(-0.34484843300001944) * (*(float*)&mantissa) + float(2.0246657790474698)) * (*(float*)&mantissa) - float(1.674877586071156));
	}

	template<>
	GLM_FUNC_QUALIFIER double fastLog2(double x)
	{
		uint64_t mantissa = 4607182418800017408U | ((*(uint64_t*)&x) & 0x000FFFFFFFFFFFFF);
		return (((*(uint64_t*)&x) >> 52)-1023) + ((double(-0.34484843300001944) * (*(double*)&mantissa) + double(2.0246657790474698)) * (*(double*)&mantissa) - double(1.674877586071156));
	}

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> fastLog2(vec<L, T, Q> const& x)
	{
		return detail::functor1<vec, L, T, T, Q>::call(fastLog2, x);
	}
}//namespace glm
