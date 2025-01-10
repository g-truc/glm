/// @ref gtx_fast_exponential

namespace glm
{
	// fastPow:
	template<typename genType>
	GLM_FUNC_QUALIFIER genType fastPow(genType x, genType y)
	{
		return exp(y * log(x));
        /*
         // ieee pow 
	      union __double64_t {
		  double f;
		  uint64_t n;
               };
 
              __double64_t mx = {static_cast<double>(x)};

              genType lnx, px, vx;
              if(x < 1.0)
                lnx = -(-mx.f * (mx.f*mx.f * 0.5) - (mx.f*mx.f*mx.f * 0.3333333));
              else {
                 px = (mx.n & 0xFFFFFFFFFFFFF) * 0.0000000000000002;
                 vx = (-px * (px*px * 0.5) - (px*px*px * 0.333333));
                 lnx = static_cast<genType>( (((mx.n >> 52) & 0x7FF)-1023) * 0.69314718055994) + vx;
               }
 
               for(int i = 0; i < 4; i++) {
 	         const genType inx = lnx * 0.5 * 0.5 * 0.5;
                 const genType x2 = inx * inx;
	         const genType x3 = x2 * inx;
	         const genType x4 = x3 * inx;
	         const genType x5 = x4 * inx;
	         genType expo = genType(1) + inx + (x2 * genType(0.5)) + (x3 * genType(0.1666666667)) + (x4 * genType(0.041666667)) + (x5 * genType(0.008333333333));
                 expo *= expo;
                 expo *= expo;
                 expo *= expo;
                 lnx = lnx-((expo-x)/expo);
                }
 
                genType in_expo_half = y * lnx * 1.4426950408889634 * 0.5;
                genType my, final_exponent;
                uint32_t whole = static_cast<uint32_t>(in_expo_half);
	        const uint64_t integer_exponent = ((1023L+whole) << 52);
	         my =(in_expo_half-whole)*0.69314718055994;
	
	        if(my)
	          final_exponent = static_cast<genType>(*reinterpret_cast<const double*>(&integer_exponent) * (1.0 + my + (my*my * 0.5)));
                else
                  final_exponent = static_cast<genType>(*reinterpret_cast<const double*>(&integer_exponent));
                final_exponent *= final_exponent;
             return (y < genType(0.0)) ? (1.0/final_exponent) : final_exponent;
        */
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
         ieee exponential, it handles large and negative values
         e^x = (x_exponent / ln(2)) * taylor_series(x-floor(x))
        */
#define __epsilon 0.0001
              x /= ln_two<T>();
              bool sign = x < 0; //handling negative values exp(-x) = 1.0 / exp(abs(x))
              if(sign)
                 x = -x;
 
	       const uint16_t exponent = static_cast<uint16_t>(x);
	       T fractional = x-exponent;
	       double out = 1.0;
	       uint64_t* bits = reinterpret_cast<uint64_t*>(&out);
	       (*bits) += ((uint64_t)exponent) << 52; //the base of ieee float is 2, so just add whole number of x to exponent

               if(fractional >= __epsilon) {
                   //subdivide into half, take advantage this formula exp(x) = exp(x/2)^2 for better accuracy
	           fractional = ((fractional * ln_two<T>()) * 0.5);
	 
	           //the code above is used here since the fractional is always lower than 1.0
                   const T x2 = fractional * fractional;
		   const T x3 = x2 * fractional;
	 	   const T x4 = x3 * fractional;
		   const T x5 = x4 * fractional;
		   x = T(1) + fractional + (x2 * T(0.5)) + (x3 * T(0.1666666667)) + (x4 * T(0.041666667)) + (x5 * T(0.008333333333));
	 	   return static_cast<T>((sign) ? 1.0 / (out * (x*x)) : (out * (x*x)));
	         }
               return static_cast<T>((sign) ? 1.0/ out : out);
#undef __epsilon
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
        /*
         // fast ieee log
	      union __double64_t {
	        double f;
	        uint64_t n;
	      } val = {static_cast<double>(x)};
	      if(x < 1.0)
		 return -x;
              x = (val.n & 0xFFFFFFFFFFFFF) * 0.0000000000000002;
	      return static_cast<genType>((((val.n >> 52) & 0x7FF)-1023) * 0.69314718055994 + x);
        */
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
	    /*
	    // ieee log2 function, bit slower than std::log
#define __epsilon 0.0001
#define __inv_ln2 1.4426950409 // 1.0 / ln(2)
           union __double64_t {
  	    double f;
  	    uint64_t n;
           } val = {x};

           //handle the value lower than 1.0
           //const bool bb = ((val.n >> 52) & 0x7FF) < 1023;
           const bool bb = val.f < 1.0;
           x = 1.0 + (val.n & 0xFFFFFFFFFFFFF) / static_cast<double>((1LU << 52));

           if(bb)
             x = 1.0 / x;

           if(x >= __epsilon) {
             //fast log function
             const genType y1 = (x - 1.0f) / (x + 1.0f);
	     const genType y2 = y1 * y1;
	     genType mx = 2.0 * y1 * (1.0f + y2 * (0.3333333333 + y2 * (0.2f + y2 * 0.1428571429)));
             // newton raphson iteration, for accuracy and slow computation
             //genType xp_tmp;
             //xp_tmp = fastExp<genType>(mx);
             //mx = mx - ((xp_tmp-x) / xp_tmp);
             //xp_tmp = fastExp<genType>(mx);
             //mx = mx - ((xp_tmp-x) / xp_tmp);
             //xp_tmp = fastExp<genType>(mx);
             //mx = mx - ((xp_tmp-x) / xp_tmp);
             //xp_tmp = fastExp<genType>(mx);
             //mx = mx - ((xp_tmp-x) / xp_tmp);
             
             return (bb) ? (-mx) : (mx * __inv_ln2 + genType(((val.n >> 52) & 0x7FF)-1023));
           }
          return genType(((val.n >> 52) & 0x7FF)-1023);
#undef __epsilon
#undef __inv_ln2
        */
        }

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> fastLog2(vec<L, T, Q> const& x)
	{
		return detail::functor1<vec, L, T, T, Q>::call(fastLog2, x);
	}
}//namespace glm
