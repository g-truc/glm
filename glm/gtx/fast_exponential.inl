/// @ref gtx_fast_exponential

namespace glm
{
	template<>
	GLM_FUNC_QUALIFIER float fastExp2(float x)
	{
		//approximated using "exp2(x)" formula
		//for +x = exp2(x)
		//for -x = 1/exp2(abs(x))
		float out, C0, C1, C2, C3, C4, C5;
		bool reciprocal;
		int exponent;
		detail::float_t<float> mx, tmpx;
		// coefficients interval [0, 1] 
		C0 = 0.001896461e-00f;
		C1 = 0.008942828e-00f;
		C2 = 0.055866246e-00f;
		C3 = 0.240139711e-00f;
		C4 = 0.693154752e-00f;
		C5 = 0.999999893e-00f;
		mx.f = x;
		reciprocal = (mx.i & int(0x80000000)) != 0;
		mx.i = mx.i & 0x7FFFFFFF;
		exponent = static_cast<int>(mx.f);
		mx.f = mx.f - static_cast<float>(exponent);
		out = (((((C0 * mx.f + C1) * mx.f + C2) * mx.f + C3) * mx.f + C4) * mx.f + C5);
		tmpx.i = (exponent + 127) << 23;
		out = tmpx.f * out;
		out = reciprocal ? (1.0f / out) : out;
		return out;
	}
	
	template<>
	GLM_FUNC_QUALIFIER double fastExp2(double x)
	{
		//approximated using "exp2(x)" formula
		//for +x = exp2(x)
		//for -x = 1/exp2(abs(x))
		double out, C0, C1, C2, C3, C4, C5;
		bool reciprocal;
		detail::int64 exponent;
		detail::float_t<double> mx, tmpx;
		//coefficients interval [0, 1] 
		C0 = 0.00189646114543331e-00;
		C1 = 0.00894282898410912e-00;
		C2 = 0.05586624630452070e-00;
		C3 = 0.24013971109076948e-00;
		C4 = 0.69315475247516734e-00;
		C5 = 0.99999989311082671e-00;
		mx.f = x;
		reciprocal = (mx.i & detail::int64(0x8000000000000000)) != 0;
		mx.i = mx.i & 0x7FFFFFFFFFFFFFFF;
		exponent = static_cast<detail::int64>(mx.f);
		mx.f = mx.f - static_cast<double>(exponent);
		out = (((((C0 * mx.f + C1) * mx.f + C2) * mx.f + C3) * mx.f + C4) * mx.f + C5);
		tmpx.i = (exponent + 1023) << 52;
		out = tmpx.f * out;
		out = reciprocal ? (1.0 / out) : out;
		return out;
	}

	template<>
	GLM_FUNC_QUALIFIER float fastLog2(float x)
	{
		//approximated using this formula "log2(x)"
		//interval [1, 1.5]
		//for x mantissa <= 1.5 log2(x) ≈ C0 * x + C1 * x2...
		//for x mantissa >= 1.5 log2(x) ≈ log2(x / 1.5) + log2(1.5)
		//for x <= 1.0 = -log2(1/x)
		float l2, inv_three_half, lx, out, poly, C0, C1, C2, C3, C4, C5, C6;
		bool low, low_mantissa;
		detail::float_t<float> tmpx, mx;
		// coefficients 
		C0 = -0.06750856e-00f;
		C1 =  0.60578664e-00f;
		C2 = -2.35146111e-00f;
		C3 =  5.17500641e-00f;
		C4 = -7.18252469e-00f;
		C5 =  7.06467854e-00f;
		C6 = -3.24397719e-00f;
		// constants 
		l2 = 0.5849625f; //log2(1.5) 
		inv_three_half = 0.6666667f; // 1.0 / 1.5 
		mx.f = x;
		low = mx.f < 1.0f;
		mx.f = low ? (1.0f / mx.f) : mx.f;
		tmpx.i = 1065353216 | (mx.i & int(0x007FFFFF));
		lx = tmpx.f;
		low_mantissa = lx <= 1.5f;
		lx = low_mantissa ? lx : (lx * inv_three_half);
		poly = ((((((C0 * lx + C1) * lx + C2) * lx + C3) * lx + C4) * lx + C5) * lx + C6);
		poly = low_mantissa ? poly : (poly + l2);
		out = static_cast<float>((mx.i >> 23) - 127) + poly;
		out = low ? -out : out;
		return out;
	}

	template<>
	GLM_FUNC_QUALIFIER double fastLog2(double x)
	{
		//approximated using this formula "log2(x)"
		//interval [1, 1.5]
		//for x mantissa <= 1.5 log2(x) ≈ C0 * x + C1 * x2...
		//for x mantissa >= 1.5 log2(x) ≈ log2(x / 1.5) + log2(1.5)
		//for x <= 1.0 = -log2(1/x)
		double l2, inv_three_half, lx, out, poly, C0, C1, C2, C3, C4, C5, C6;
		bool low, low_mantissa;
		detail::float_t<double> tmpx, mx;
		// coefficients 
		C0 = -0.067508561412635e-00;
		C1 =  0.605786644896372e-00;
		C2 = -2.351461115180550e-00;
		C3 =  5.175006419193522e-00;
		C4 = -7.182524695365589e-00;
		C5 =  7.064678543395325e-00;
		C6 = -3.243977190921664e-00;
		// constants 
		l2 = 0.5849625; // log2(1.5) 
		inv_three_half = 0.6666667; // 1.0 / 1.5 
		mx.f = x;
		low = mx.f < 1.0;
		mx.f = low ? (1.0 / mx.f) : mx.f;
		tmpx.i = 4607182418800017408U | (mx.i & detail::int64(0x000FFFFFFFFFFFFF));
		lx = tmpx.f;
		low_mantissa = lx <= 1.5;
		lx = low_mantissa ? lx : (lx * inv_three_half);
		poly = ((((((C0 * lx + C1) * lx + C2) * lx + C3) * lx + C4) * lx + C5) * lx + C6);
		poly = low_mantissa ? poly : (poly + l2);
		out = static_cast<double>((mx.i >> 52) - 1023) + poly;
		out = low ? -out : out;
		return out;
	}

	// fastPow
	template<typename genType>
	GLM_FUNC_QUALIFIER genType fastPow(genType x, genType y)
	{
		return exp(y * log(x));
	}
	
	template<>
	GLM_FUNC_QUALIFIER float fastPow(float x, float y)
	{
		return fastExp2<float>(y * fastLog2<float>(x));
	}
	
	template<>
	GLM_FUNC_QUALIFIER double fastPow(double x, double y)
	{
		return fastExp2<double>(y * fastLog2<double>(x));
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
		return fastExp2<float>(1.4426950409f * x);
	}
	
	template<>
	GLM_FUNC_QUALIFIER double fastExp(double x)
	{
		return fastExp2<double>(1.4426950409 * x);
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

	//fastExp2, ln2 = 0.69314718055994530941723212145818f
	template<typename genType>
	GLM_FUNC_QUALIFIER genType fastExp2(genType x)
	{
		return fastExp(static_cast<genType>(0.69314718055994530941723212145818) * x);
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
	
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> fastLog2(vec<L, T, Q> const& x)
	{
		return detail::functor1<vec, L, T, T, Q>::call(fastLog2, x);
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
		return fastLog2<float>(x) * 0.69314718055994530941723212145818f;
	}
	
	template<>
	GLM_FUNC_QUALIFIER double fastLog(double x)
	{
		return fastLog2<double>(x) * 0.69314718055994530941723212145818;
	}

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> fastLog(vec<L, T, Q> const& x)
	{
		return detail::functor1<vec, L, T, T, Q>::call(fastLog, x);
	}
}//namespace glm
