#pragma once
namespace glm{
namespace detail
{
	template<template<length_t L, typename T, qualifier Q> class vec, length_t L, typename R, typename T, qualifier Q>
	struct functor1
	{
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static vec<L, R, Q> call(R (*Func) (T x), vec<L, T, Q> const& v)
		{
			vec<L, R, Q> ret{v};
			#pragma GCC unroll(4)
			for (int i = 0; i < L; i++) {
				ret[i] = Func(v[i]);
			}
			return ret;
		}
	};

	
	template<template<length_t L, typename T, qualifier Q> class vec, length_t L, typename T, qualifier Q>
	struct functor2
	{
		GLM_FUNC_QUALIFIER static vec<L, T, Q> call(T (*Func) (T x, T y), vec<L, T, Q> a, vec<L, T, Q> const& b)
		{
			vec<L, T, Q> ret{a};
			#pragma GCC unroll(4)
			for (int i = 0; i < L; i++) {
				ret[i] = Func(a[i], b[i]);
			}
			return ret;
		}

		template<typename Fct>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static vec<L, T, Q> call(Fct Func, vec<L, T, Q> a, vec<L, T, Q> const& b)
		{
			vec<L, T, Q> ret{a};
			#pragma GCC unroll(4)
			for (int i = 0; i < L; i++) {
				ret[i] = Func(a[i], b[i]);
			}
			return ret;
		}
	};

	template<template<length_t L, typename T, qualifier Q> class vec, length_t L, typename T, qualifier Q>
	struct functor2_vec_sca{
		GLM_FUNC_QUALIFIER static vec<L, T, Q> call(T (*Func) (T x, T y), vec<L, T, Q> a, T b)
		{
			vec<L, T, Q> ret{a};
			#pragma GCC unroll(4)
			for (int i = 0; i < L; i++) {
				ret[i] = Func(a[i], b);
			}
			return ret;
		}
		template<class Fct>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static vec<L, T, Q> call(Fct Func, vec<L, T, Q> a, T b)
		{
			vec<L, T, Q> ret{a};
			#pragma GCC unroll(4)
			for (int i = 0; i < L; i++) {
				ret[i] = Func(a[i], b);
			}
			return ret;
		}
	};

	template<length_t L, typename T, qualifier Q>
	struct functor2_vec_int {
		GLM_FUNC_QUALIFIER static vec<L, int, Q> call(int (*Func) (T x, int y), vec<L, T, Q> const& a, vec<L, int, Q> b)
		{
			vec<L, int, Q> ret{b};
			#pragma GCC unroll(4)
			for (int i = 0; i < L; i++) {
				ret[i] = Func(a[i], b[i]);
			}
			return ret;
		}

		template<class Fct>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR static vec<L, int, Q> call(Fct Func, vec<L, T, Q> const& a, vec<L, int, Q> b)
		{
			vec<L, int, Q> ret{b};
			#pragma GCC unroll(4)
			for (int i = 0; i < L; i++) {
				ret[i] = Func(a[i], b[i]);
			}
			return ret;
		}
	};
}//namespace detail
}//namespace glm
