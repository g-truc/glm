/// @ref gtx_fast_trigonometry

namespace glm{
namespace detail
{
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> taylorCos(vec<L, T, Q> const& x)
	{
		return static_cast<T>(1)
			- (x * x) * (1.f / 2.f)
			+ ((x * x) * (x * x)) * (1.f / 24.f)
			- (((x * x) * (x * x)) * (x * x)) * (1.f / 720.f)
			+ (((x * x) * (x * x)) * ((x * x) * (x * x))) * (1.f / 40320.f);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER T cos_52s(T x)
	{
		T const xx(x * x);
		return (T(0.9999932946) + xx * (T(-0.4999124376) + xx * (T(0.0414877472) + xx * T(-0.0012712095))));
	}

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> cos_52s(vec<L, T, Q> const& x)
	{
		return detail::functor1<vec, L, T, T, Q>::call(cos_52s, x);
	}
}//namespace detail

	// wrapAngle
	template<typename T>
	GLM_FUNC_QUALIFIER T wrapAngle(T angle)
	{
		return abs<T>(mod<T>(angle, two_pi<T>()));
	}

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> wrapAngle(vec<L, T, Q> const& x)
	{
		return detail::functor1<vec, L, T, T, Q>::call(wrapAngle, x);
	}

	// cos
	template<typename T>
	GLM_FUNC_QUALIFIER T fastCos(T x)
	{
		T const angle(wrapAngle<T>(x));

		if(angle < half_pi<T>())
			return detail::cos_52s(angle);
		if(angle < pi<T>())
			return -detail::cos_52s(pi<T>() - angle);
		if(angle < (T(3) * half_pi<T>()))
			return -detail::cos_52s(angle - pi<T>());

		return detail::cos_52s(two_pi<T>() - angle);
	}

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> fastCos(vec<L, T, Q> const& x)
	{
		return detail::functor1<vec, L, T, T, Q>::call(fastCos, x);
	}

	// sin
	template<typename T>
	GLM_FUNC_QUALIFIER T fastSin(T x)
	{
		return fastCos<T>(half_pi<T>() - x);
	}

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> fastSin(vec<L, T, Q> const& x)
	{
		return detail::functor1<vec, L, T, T, Q>::call(fastSin, x);
	}

	// tan
	template<typename T>
	GLM_FUNC_QUALIFIER T fastTan(T x)
	{
                //correction between tan(51°) - tan(89°)
		if(x >= 1.2348971565)
		 return fastSin<T>(x)/fastCos<T>(x);
		return x + (x * x * x * T(0.3333333333)) + (x * x * x * x * x * T(0.1333333333333)) + (x * x * x * x * x * x * x * T(0.0539682539));
	}

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> fastTan(vec<L, T, Q> const& x)
	{
		return detail::functor1<vec, L, T, T, Q>::call(fastTan, x);
	}

	// asin
	template<typename T>
	GLM_FUNC_QUALIFIER T fastAsin(T x)
	{
		return x + (x * x * x * T(0.166666667)) + (x * x * x * x * x * T(0.075)) + (x * x * x * x * x * x * x * T(0.0446428571)) + (x * x * x * x * x * x * x * x * x * T(0.0303819444));// + (x * x * x * x * x * x * x * x * x * x * x * T(0.022372159));
	}

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> fastAsin(vec<L, T, Q> const& x)
	{
		return detail::functor1<vec, L, T, T, Q>::call(fastAsin, x);
	}

	// acos
	template<typename T>
	GLM_FUNC_QUALIFIER T fastAcos(T x)
	{
		return T(1.5707963267948966192313216916398) - fastAsin(x); //(PI / 2)
	}

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> fastAcos(vec<L, T, Q> const& x)
	{
		return detail::functor1<vec, L, T, T, Q>::call(fastAcos, x);
	}

	// atan
	template<typename T>
	GLM_FUNC_QUALIFIER T fastAtan(T y, T x)
	{
		/*
	        // correct vec2 mapping between 91° and 269°
	           T sgn = sign(y) * sign(x);
	           return abs(fastAtan(y/x)) * sgn;
	         */
                 if(x > 0)
                    return fastAtan(y / x);
                 else if(x < 0) {
                    if(y >= 0)
                         return fastAtan(y / x) + 3.1415926535897; //pi 
                    else
                         return fastAtan(y / x) - 3.1415926535897; //pi
                 } else {
                   if(y > 0)
                         return 1.5707963267948; //pi half
                   else if(y < 0)
                         return -1.5707963267948; //pi half
                   else
                         return 0.0;
                }
        }

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> fastAtan(vec<L, T, Q> const& y, vec<L, T, Q> const& x)
	{
	         return detail::functor2<vec, L, T, Q>::call(fastAtan, y, x);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER T fastAtan(T x)
	{
		//as the x gradually increasing until it becomes close to infinity,
                //the output becomes farther to pi half
                //so it needs a little bit of adjustment between tan(45°) - tan(89°)
                if(x > 1.0)
                    return fastAcos(fastInverseSqrt(x * x + 1));
                 else if(x < -1.0)
                    return -fastAcos(fastInverseSqrt(x * x + 1));
 
                 bool negative = x < 0.0;
                 if(negative) x = -x;
                 return (negative) ?  -(x - (x * x * x * T(0.333333333333)) + (x * x * x * x * x * T(0.2)) - (x * x * x * x * x * x * x * T(0.1428571429)) + (x * x * x * x * x * x * x * x * x * T(0.111111111111)) - (x * x * x * x * x * x * x * x * x * x * x * T(0.0909090909)))
                         : x - (x * x * x * T(0.333333333333)) + (x * x * x * x * x * T(0.2)) - (x * x * x * x * x * x * x * T(0.1428571429)) + (x * x * x * x * x * x * x * x * x * T(0.111111111111)) - (x * x * x * x * x * x * x * x * x * x * x * T(0.0909090909));
        }

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> fastAtan(vec<L, T, Q> const& x)
	{
		return detail::functor1<vec, L, T, T, Q>::call(fastAtan, x);
	}
}//namespace glm
