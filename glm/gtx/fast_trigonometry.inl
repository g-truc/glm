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
		return abs<T>(angle - ::trunc(angle * T(0.15915494309189534561)) * two_pi<T>());
		//return abs<T>(mod<T>(angle, two_pi<T>()));
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
		/*
		T const angle(wrapAngle<T>(x));

		if(angle < half_pi<T>())
			return detail::cos_52s(angle);
		if(angle < pi<T>())
			return -detail::cos_52s(pi<T>() - angle);
		if(angle < (T(3) * half_pi<T>()))
			return -detail::cos_52s(angle - pi<T>());

		return detail::cos_52s(two_pi<T>() - angle);
		*/
		/*
		approximated using "cos(sqrt(x))" 
		interval [0, pi/2]
		*/ 
		T mx, x2, out, C0, C1, C2, C3, C4, C5, C6;
		bool sign, flip;
		int q;
		/* coefficients */
		C0 = T( 2.0254959785478004e-09);
		C1 = T(-2.7543954056392956e-07);
		C2 = T( 2.4801444520278038e-05);
		C3 = T(-1.3888888105171723e-03);
		C4 = T( 0.4166666664617346e-01);
		C5 = T(-4.9999999999799011e-01);
		C6 = T( 0.9999999999999678e-00);
		/* sign handle */
		mx = x < T(0.0) ? -x : x;
		/* remainder */
		mx = mx - ::trunc(mx * T(0.1591549)) * T(6.283185307);
		/* range reduction*/
		q = ((int)(mx * T(0.6366197))+1);
		flip = (q == 2 || q == 4);
		sign = (q == 2 || q == 3);
		mx = mx - (T(1.57079632) * T(q-1));
		mx = flip ? (mx - T(1.57079632)) : mx;
		/*range reduction*/
		x2 = mx * mx;
		out = ((((((C0 * x2 + C1) * x2 + C2) * x2 + C3) * x2 + C4) * x2 + C5) * x2 + C6);
		out = sign ? -out : out;
		return out;
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
		//return fastCos<T>(half_pi<T>() - x);
		/*
		this function is approximated using this formula : (sin(sqrt(x))-sqrt(x)) / (x * sqrt(x))
		interval [0, pi/2]
		sin(x) ≈ x * x3 * sin_poly(x2)
		where : sin_poly(x) = (((C0 * x + C1) * x + C2) * x + C3)
		for -x = -sin(abs(x))
		*/
		T mx, x2, out, C0, C1, C2, C3;
		bool sign, flip;
		int q;
		/* coefficients */
		C0 = T( 2.678156924342569e-06);
		C1 = T(-1.983369323468157e-04);
		C2 = T( 8.333309602749911e-03);
		C3 = T(-1.666666655047327e-01);
		mx = x;
		sign = mx < T(0.0);
		mx = sign ? -mx : mx;
		/* remainder */
		mx = mx - ::trunc(mx * T(0.1591549)) * T(6.283185307);
		/* range reduction */
		q = ((int)(mx * T(0.6366197))+1);
		flip = (q == 2 || q == 4);
		sign ^= q > 2;
		mx = mx - (T(1.57079632) * T(q-1));
		mx = flip ? (T(1.57079632) - mx) : mx;
		/* polynomial */
		x2 = mx * mx;
		out = mx + (x2 * mx) * (((C0 * x2 + C1) * x2 + C2) * x2 + C3);
		out = sign ? -out : out;
		return out;
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
		/*
		calculated using "sin(x)/cos(x)"
		this is much more efficient because it only perform single
		range reduction and remainder operation, unlike separate sin and cos
		*/
		T mx, sx, cx, out, x2, S0, S1, S2, S3, C0, C1, C2, C3, C4, C5, C6;
		bool sign, flip;
		int q;

		S0 = T( 2.6781569243425690e-06);
		S1 = T(-1.9833693234681570e-04);
		S2 = T( 8.3333096027499110e-03);
		S3 = T(-1.6666666550473270e-01);
		C0 = T( 2.0254959785478004e-09);
		C1 = T(-2.7543954056392956e-07);
		C2 = T( 2.4801444520278038e-05);
		C3 = T(-1.3888888105171723e-03);
		C4 = T( 0.4166666664617346e-01);
		C5 = T(-4.9999999999799011e-01);
		C6 = T( 0.9999999999999678e-00);
 
		mx = x;
		sign = mx < T(0.0);
		mx = sign ? -mx : mx;
		/* remainder */
		mx = mx - ::trunc(mx * T(0.1591549)) * T(6.283185307);
		/* range reduction */
		q = ((int)(mx * T(0.6366197))+1);
		flip = (q == 2 || q == 4);
		sign ^= flip;
		mx = mx - (T(1.57079632) * T(q-1));
		mx = flip ? (T(1.57079632) - mx) : mx;
		/* polynomial */
		x2 = mx * mx;
		sx = mx + (x2 * mx) * (((S0 * x2 + S1) * x2 + S2) * x2 + S3);
		cx = ((((((C0 * x2 + C1) * x2 + C2) * x2 + C3) * x2 + C4) * x2 + C5) * x2 + C6);
		out = sx / cx;
		out = sign ? -out : out;
		return out;
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
		/*
		approximated using this formula "(atan(sqrt(x))-sqrt(x)) / (x * sqrt(x))"
		for x <= 0.5   asin(x) = x + x^3 + asin_poly(x^2)
		for x > 0.5    asin(x) = asin(sqrt((1 - x) / 2))
		*/
		// TODO : fix glm::fastSqrt, it kills accuracy
		T mx, x2, out, C0, C1, C2, C3, C4;
		bool sign, more_x;
		/* coefficients interval [0, 0.5] */
		C0 = T(0.038328305e-00);
		C1 = T(0.026433362e-00);
		C2 = T(0.045020215e-00);
		C3 = T(0.074987613e-00);
		C4 = T(0.166666730e-00);
		mx = x;
		sign = mx < T(0.0);
		mx = sign ? -mx : mx;
		more_x = mx >= T(0.5);
		mx = more_x ? (fastSqrt<T>((T(1.0) - mx) * T(0.5))) : mx;
		x2 = mx * mx;
		out = mx + (x2 * mx) * ((((C0 * x2 + C1) * x2 + C2) * x2 + C3) * x2 + C4);
		out = more_x ? (T(1.57079632) - T(2.0) * out) : out;
		out = sign ? -out : out;
		return out;
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
		return T(1.57079632) - fastAsin<T>(x);
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
		T ratio, mx;
		bool both_negative, y_positive;
		both_negative = x < T(0.0) && y < T(0.0f);
		y_positive = y > T(0.0) && x < T(0.0);
		ratio = y / x;
		mx = fastAtan<T>(ratio);
		mx = both_negative ? (mx - T(3.14159265)) : mx;
		mx = y_positive ? (mx + T(3.14159265)) : mx;
		return mx;
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
		/*
		approximated using this formula "(atan(sqrt(x))-sqrt(x)) / (x * sqrt(x))"
		interval [0, 0.5]
		for x <= 0.5            atan(x) = x*C0 + x2*C1 + x3*C2...
		for x > 0.5 && x < 1.0  atan(x) = atan((x - 1) / (1 + x)) + pi/4
 
		for x > 1.0 -> inf      atan(x) = asin(x / sqrt(1 + x*x))
		better accuracy:
		for x > 1.0 -> inf      atan(x) = pi_half - atan(1.0 / x)
		*/
		T mx, x2, out, C0, C1, C2, C3, C4;
		bool low, high, sign;
		C0 = T(-0.037163095549048668);
		C1 = T( 0.092448081545483562);
		C2 = T(-0.139917441027514330);
		C3 = T( 0.199831512979624430);
		C4 = T(-0.333331771776715250);
		mx = x;
		sign = mx < T(0.0);
		mx = sign ? -mx : mx;
		high = mx > T(1.0);
		mx = high ? (T(1.0) / mx) : mx;
		low = mx > 0.5f;
		mx = low ? ((mx - T(1.0)) / (T(1.0) + mx)) : mx;
		x2 = mx*mx;
		out = mx + (x2 * mx) * ((((C0 * x2 + C1) * x2 + C2) * x2 + C3) * x2 + C4);
		out = low ? (out + T(0.78539816)) : out;
		out = high ? (T(1.57079632) - out) : out;
		out = sign ? -out : out;
		return out;
	}

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> fastAtan(vec<L, T, Q> const& x)
	{
		return detail::functor1<vec, L, T, T, Q>::call(fastAtan, x);
	}
	
}//namespace glm
