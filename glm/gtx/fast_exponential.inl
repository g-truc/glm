/// @ref gtx_fast_exponential

namespace glm
{
	// fastPow:
	template<typename genType>
	GLM_FUNC_QUALIFIER genType fastPow(genType x, genType y)
	{
		return exp(y * log(x));
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
	// Note: This function provides accurate results only for value between -1 and 1, else avoid it.
	template<typename T>
	GLM_FUNC_QUALIFIER T fastExp(T x)
	{
	 /*
		// This has a better looking and same performance in release mode than the following code. However, in debug mode it's slower.
		// return 1.0f + x * (1.0f + x * 0.5f * (1.0f + x * 0.3333333333f * (1.0f + x * 0.25 * (1.0f + x * 0.2f))));
		T x2 = x * x;
		T x3 = x2 * x;
		T x4 = x3 * x;
		T x5 = x4 * x;
		return T(1) + x + (x2 * T(0.5)) + (x3 * T(0.1666666667)) + (x4 * T(0.041666667)) + (x5 * T(0.008333333333));
	*/

        /*
           ieee754 exponential with average error 1e-10, bit faster than std::exp
           e^x = (x_exponent / ln(2)) * taylor_series(x-floor(x))
        */
                const double __ln2 = 0.693147180559945309417232121; //log(2)

 
                 x /= __ln2; //convert to 2^x
                 bool sign = x < 0; // handling negative values using reciprocal exp(x) = 1.0 / exp(-x)
                 if(sign)
                   x = -x;
 
                 const uint16_t exponent = static_cast<uint16_t>(x);
                 double fractional = x-exponent;

                 double out = 1.0;
                 uint64_t* bits = reinterpret_cast<uint64_t*>(&out);
                 (*bits) += ((uint64_t)exponent) << 52; //the base of ieee float is 2 so just add into its exponent

                 if(fractional >= 1e-4) {
                      //you can replace your code above here since the value of "fractional" is lower than zero
                      double exponential = 1.0;
                      double iteration = 1.0;
                      //subdivide it into half 5x, take advantage this formula "exp(x/2) = exp(x/2)^2" for accuracy
                      fractional = ((((fractional * __ln2) * 0.5) * 0.5) * 0.5);

                      //just remove this comment if you want more accurate 
                      //fractional = (((((fractional * Math_LN2) * 0.5) * 0.5) * 0.5) * 0.5) * 0.5;

                      //                  (pre computed reciprocals)
                      iteration *= fractional * 1.0000000000000000; //1 / 1
                      exponential += iteration;
                      iteration *= fractional * 0.5000000000000000; //1 / 2
                      exponential += iteration;
                     /*
                     //just remove this comment if you want more accurate 
                     iteration *= fractional * 0.3333333333333333; //1 / 3
                     exponential += iteration;
                     iteration *= fractional * 0.2500000000000000; //1 / 4
                     exponential += iteration;
                     iteration *= fractional * 0.2000000000000000; //1 / 5
                     exponential += iteration;
                     iteration *= fractional * 0.1666666666666666; //1 / 6
                     exponential += iteration;
                     */
                     //squared it 5x
                     exponential *= exponential;
                     exponential *= exponential;
                     exponential *= exponential;
                    /*
                    //just remove this comment if you want more accurate 
                    exponential *= exponential;
                    exponential *= exponential;
                    exponential *= exponential;
                    */
                    return static_cast<T>((sign) ? (1.0 / (out * exponential)) : (out * exponential));
               }
          return static_cast<T>((sign) ? (1.0/ out) : out);
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

	/* Slower than the VC7.1 function...
	GLM_FUNC_QUALIFIER float fastLog(float x)
	{
		float y1 = (x - 1.0f) / (x + 1.0f);
		float y2 = y1 * y1;
		return 2.0f * y1 * (1.0f + y2 * (0.3333333333f + y2 * (0.2f + y2 * 0.1428571429f)));
	}
	*/

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
}//namespace glm
