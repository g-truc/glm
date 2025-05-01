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



 //polynomials
	template<typename T>
	GLM_FUNC_QUALIFIER T tanPoly(T x, T sign)
	{
		return sign * ((((((T(-9.580235e-4) * x + T(1.025743e-2)) * x - T(1.964406e-3)) * x - T(1.656241e-1)) * x - T(2.652585e-4)) * x + T(1.000025e-0)) * x - T(3.973469e-7))
		/ ((((((T(-9.580235e-4) * x - T(1.228280e-3)) * x + T(4.313990e-2)) * x - T(8.634596e-4)) * x - T(4.997638e-1)) * x - T(2.400507e-5)) * x + T(1.000000e-0));
	}

	template<typename T>
	GLM_FUNC_QUALIFIER T asinPoly(T x)
	{
		return ((((((T(1.550104e-1) * x - T(6.284173e-2)) * x + T(5.446719e-2)) * x + T(1.561094e-1)) * x + T(9.531123e-4)) * x + T(9.999680e-1)) * x + T(1.740546e-7));
	}

	template<typename T>
	GLM_FUNC_QUALIFIER T acosPoly(T x)
	{
		return ((((((T(-1.550104e-1) * x + T(6.284173e-2)) * x - 5.446719e-2) * x - T(1.561094e-1)) * x - T(9.531123e-4)) * x - T(9.999680e-1)) * x + T(1.570796e-0));
	}
}//namespace detail

	// wrapAngle
	template<typename T>
	GLM_FUNC_QUALIFIER T wrapAngle(T angle)
	{
		//glm::trunc() is much faster than glm::mod but i got an error when i try to use it
		//return abs<T>(angle - trunc<T>(angle * T(0.15915494309189534561)) * two_pi<T>());
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
		T ms = (x < T(0.0)) ? T(-1.0) : T(1.0);
		T mx = x * ms;
 
		if(mx > two_pi<T>())
			mx = wrapAngle<T>(mx);

		switch((int)(mx * T(0.6366197))) //(1.0 / half_pi<T>())
		{
			case 0:
				return detail::tanPoly<T>(mx, ms);
			break;
			case 1:
				return -detail::tanPoly<T>(pi<T>() - mx, ms);
			break;
			case 2:
				return detail::tanPoly<T>(mx - pi<T>(), ms);
			break;
			case 3:
				return -detail::tanPoly<T>(two_pi<T>() - mx, ms);
			break;
		}
		return T(NAN);
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
		T ms = (x < T(0.0)) ? T(-1.0) : T(1.0);
		T mx = x * ms;
		if(mx > T(0.5))
			return ms * (half_pi<T>() - T(2.0) * detail::asinPoly<T>(fastSqrt<T>((T(1.0) - mx) * T(0.5))) );
		return ms * detail::asinPoly<T>(mx);
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
		bool is_negative = (x < T(0.0));
		T mx = is_negative ? -x : x;
 
		if(is_negative)
		{
			if(mx > T(0.5))
				return T(2.0) * detail::acosPoly<T>(fastSqrt<T>((T(1.0) - mx) * T(0.5)));
			return pi<T>() - detail::acosPoly<T>(mx);
		}
		if(mx > T(0.5))
			return (pi<T>() - T(2.0) * detail::acosPoly<T>(fastSqrt<T>((T(1.0) - mx) * T(0.5))) );
		return detail::acosPoly<T>(mx);
	}

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> fastAcos(vec<L, T, Q> const& x)
	{
		return detail::functor1<vec, L, T, T, Q>::call(fastAcos, x);
	}

	// atan2
	template<typename T>
	GLM_FUNC_QUALIFIER T fastAtan(T y, T x)
	{
		if (y < T(0.0) && x < T(0.0))
			return fastAtan<T>(y / x) - pi<T>();
		else if(y > T(0.0) && x < T(0.0))
			return fastAtan<T>(y / x) + pi<T>();
		return fastAtan<T>(y / x);
	}

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> fastAtan(vec<L, T, Q> const& y, vec<L, T, Q> const& x)
	{
		return detail::functor2<vec, L, T, Q>::call(fastAtan, y, x);
	}
	// atan
	template<typename T>
	GLM_FUNC_QUALIFIER T fastAtan(T x)
	{
		T ms = (x < T(0.0)) ? T(-1.0) : T(1.0);
		T mx = x * ms;
		mx = (mx * fastInverseSqrt<T>(T(1.0) + mx * mx));
		if(mx > T(0.5))
			return ms * (half_pi<T>() - T(2.0) * detail::asinPoly<T>(fastSqrt<T>((T(1.0) - mx) * T(0.5))));
		return ms * detail::asinPoly<T>(mx);
	}

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> fastAtan(vec<L, T, Q> const& x)
	{
		return detail::functor1<vec, L, T, T, Q>::call(fastAtan, x);
	}
}//namespace glm
