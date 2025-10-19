/// @ref gtc_ulp

#include "../ext/scalar_ulp.hpp"

namespace glm
{
	template<>
	GLM_FUNC_QUALIFIER float next_float(float x)
	{
		return std::nextafter(x, std::numeric_limits<float>::max());
	}

	template<>
	GLM_FUNC_QUALIFIER double next_float(double x)
	{
		return std::nextafter(x, std::numeric_limits<double>::max());
	}

	template<typename T>
	GLM_FUNC_QUALIFIER T next_float(T x, int ULPs)
	{
		static_assert(std::numeric_limits<T>::is_iec559 || GLM_CONFIG_UNRESTRICTED_FLOAT, "'next_float' only accept floating-point input");
		assert(ULPs >= 0);

		T temp = x;
		for (int i = 0; i < ULPs; ++i)
			temp = next_float(temp);
		return temp;
	}

	GLM_FUNC_QUALIFIER float prev_float(float x)
	{
		return std::nextafter(x, std::numeric_limits<float>::min());
	}

	GLM_FUNC_QUALIFIER double prev_float(double x)
	{
		return std::nextafter(x, std::numeric_limits<double>::min());
	}

	template<typename T>
	GLM_FUNC_QUALIFIER T prev_float(T x, int ULPs)
	{
		static_assert(std::numeric_limits<T>::is_iec559 || GLM_CONFIG_UNRESTRICTED_FLOAT, "'prev_float' only accept floating-point input");
		assert(ULPs >= 0);

		T temp = x;
		for (int i = 0; i < ULPs; ++i)
			temp = prev_float(temp);
		return temp;
	}

	GLM_FUNC_QUALIFIER int float_distance(float x, float y)
	{
		detail::float_t<float> const a(x);
		detail::float_t<float> const b(y);

		return abs(a.i - b.i);
	}

	GLM_FUNC_QUALIFIER int64 float_distance(double x, double y)
	{
		detail::float_t<double> const a(x);
		detail::float_t<double> const b(y);

		return abs(a.i - b.i);
	}

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> next_float(vec<L, T, Q> const& x)
	{
		vec<L, T, Q> Result;
		for (length_t i = 0, n = Result.length(); i < n; ++i)
			Result[i] = next_float(x[i]);
		return Result;
	}

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> next_float(vec<L, T, Q> const& x, int ULPs)
	{
		vec<L, T, Q> Result;
		for (length_t i = 0, n = Result.length(); i < n; ++i)
			Result[i] = next_float(x[i], ULPs);
		return Result;
	}

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> next_float(vec<L, T, Q> const& x, vec<L, int, Q> const& ULPs)
	{
		vec<L, T, Q> Result;
		for (length_t i = 0, n = Result.length(); i < n; ++i)
			Result[i] = next_float(x[i], ULPs[i]);
		return Result;
	}

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> prev_float(vec<L, T, Q> const& x)
	{
		vec<L, T, Q> Result;
		for (length_t i = 0, n = Result.length(); i < n; ++i)
			Result[i] = prev_float(x[i]);
		return Result;
	}

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> prev_float(vec<L, T, Q> const& x, int ULPs)
	{
		vec<L, T, Q> Result;
		for (length_t i = 0, n = Result.length(); i < n; ++i)
			Result[i] = prev_float(x[i], ULPs);
		return Result;
	}

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, T, Q> prev_float(vec<L, T, Q> const& x, vec<L, int, Q> const& ULPs)
	{
		vec<L, T, Q> Result;
		for (length_t i = 0, n = Result.length(); i < n; ++i)
			Result[i] = prev_float(x[i], ULPs[i]);
		return Result;
	}

	template<length_t L, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, int, Q> float_distance(vec<L, float, Q> const& x, vec<L, float, Q> const& y)
	{
		vec<L, int, Q> Result;
		for (length_t i = 0, n = Result.length(); i < n; ++i)
			Result[i] = float_distance(x[i], y[i]);
		return Result;
	}

	template<length_t L, qualifier Q>
	GLM_FUNC_QUALIFIER vec<L, int64, Q> float_distance(vec<L, double, Q> const& x, vec<L, double, Q> const& y)
	{
		vec<L, int64, Q> Result;
		for (length_t i = 0, n = Result.length(); i < n; ++i)
			Result[i] = float_distance(x[i], y[i]);
		return Result;
	}
}//namespace glm

