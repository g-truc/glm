/// @ref core
/// @file glm/detail/type_mat1x4.hpp

#pragma once

#include "type_vec1.hpp"
#include "type_vec4.hpp"
#include <limits>
#include <cstddef>

namespace glm
{
	template<typename T, qualifier Q>
	struct mat<1, 4, T, Q>
	{
		typedef vec<4, T, Q> col_type;
		typedef vec<1, T, Q> row_type;
		typedef mat<1, 4, T, Q> type;
		typedef mat<4, 1, T, Q> transpose_type;
		typedef T value_type;

	private:
		col_type value[1];

	public:
		// -- Accesses --

		typedef length_t length_type;
		GLM_FUNC_DECL static constexpr length_type length() { return 1; }

		GLM_FUNC_DECL GLM_CONSTEXPR col_type & operator[](length_type i) noexcept;
		GLM_FUNC_DECL GLM_CONSTEXPR col_type const& operator[](length_type i) const noexcept;

		// -- Constructors --

		GLM_DEFAULTED_DEFAULT_CTOR_DECL GLM_CONSTEXPR mat() GLM_DEFAULT_CTOR;
		GLM_CTOR_DECL mat(mat<1, 4, T, Q> const& m) = default;
		template<qualifier P>
		GLM_CTOR_DECL mat(mat<1, 4, T, P> const& m);

		GLM_CTOR_DECL GLM_EXPLICIT mat(T scalar);
		GLM_CTOR_DECL mat(
			T const& x1, T const& y1, T const& z1, T const& w1);
		GLM_CTOR_DECL mat(
			col_type const& v1);

		// -- Conversions --

		template<typename X1, typename Y1, typename Z1, typename W1>
		GLM_CTOR_DECL mat(
			X1 const& x1, Y1 const& y1, Z1 const& z1);

		template<typename U>
		GLM_CTOR_DECL mat(
			vec<4, U, Q> const& v1);

		// -- Matrix conversions --

		template<typename U, qualifier P>
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<1, 4, U, P> const& m);

		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<1, 1, T, Q> const& x);
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<2, 2, T, Q> const& x);
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<3, 3, T, Q> const& x);
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<4, 4, T, Q> const& x);
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<1, 2, T, Q> const& x);
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<2, 1, T, Q> const& x);
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<1, 3, T, Q> const& x);
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<3, 1, T, Q> const& x);
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<4, 1, T, Q> const& x);
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<2, 3, T, Q> const& x);
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<3, 2, T, Q> const& x);
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<2, 4, T, Q> const& x);
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<4, 2, T, Q> const& x);
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<3, 4, T, Q> const& x);
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<4, 3, T, Q> const& x);

		// -- Unary arithmetic operators --

		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR mat<1, 4, T, Q>& operator=(mat<1, 4, T, Q> const& m) = default;

		template<typename U>
		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR mat<1, 4, T, Q>& operator=(mat<1, 4, U, Q> const& m);
		template<typename U>
		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR mat<1, 4, T, Q>& operator+=(U s);
		template<typename U>
		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR mat<1, 4, T, Q>& operator+=(mat<1, 4, U, Q> const& m);
		template<typename U>
		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR mat<1, 4, T, Q>& operator-=(U s);
		template<typename U>
		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR mat<1, 4, T, Q>& operator-=(mat<1, 4, U, Q> const& m);
		template<typename U>
		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR mat<1, 4, T, Q>& operator*=(U s);
		template<typename U>
		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR mat<1, 4, T, Q>& operator*=(mat<1, 4, U, Q> const& m);
		template<typename U>
		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR mat<1, 4, T, Q>& operator/=(U s);
		template<typename U>
		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR mat<1, 4, T, Q>& operator/=(mat<1, 4, U, Q> const& m);

		// -- Increment and decrement operators --

		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR mat<1, 4, T, Q> & operator++ ();
		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR mat<1, 4, T, Q> & operator-- ();
		GLM_FUNC_DECL GLM_CONSTEXPR mat<1, 4, T, Q> operator++(int);
		GLM_FUNC_DECL GLM_CONSTEXPR mat<1, 4, T, Q> operator--(int);
	};

	// -- Unary operators --

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<1, 4, T, Q> operator+(mat<1, 4, T, Q> const& m);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<1, 4, T, Q> operator-(mat<1, 4, T, Q> const& m);

	// -- Binary operators --

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<1, 4, T, Q> operator+(mat<1, 4, T, Q> const& m, T scalar);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<1, 4, T, Q> operator+(T scalar, mat<1, 4, T, Q> const& m);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<1, 4, T, Q> operator+(mat<1, 4, T, Q> const& m1, mat<1, 4, T, Q> const& m2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<1, 4, T, Q> operator-(mat<1, 4, T, Q> const& m, T scalar);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<1, 4, T, Q> operator-(T scalar, mat<1, 4, T, Q> const& m);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<1, 4, T, Q> operator-(mat<1, 4, T, Q> const& m1, mat<1, 4, T, Q> const& m2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<1, 4, T, Q> operator*(mat<1, 4, T, Q> const& m, T scalar);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<1, 4, T, Q> operator*(T scalar, mat<1, 4, T, Q> const& m);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR typename mat<1, 4, T, Q>::col_type operator*(mat<1, 4, T, Q> const& m, typename mat<1, 4, T, Q>::row_type const& v);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR typename mat<1, 4, T, Q>::row_type operator*(typename mat<1, 4, T, Q>::col_type const& v, mat<1, 4, T, Q> const& m);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<1, 4, T, Q> operator*(mat<1, 4, T, Q> const& m1, mat<1, 1, T, Q> const& m2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<2, 4, T, Q> operator*(mat<1, 4, T, Q> const& m1, mat<2, 1, T, Q> const& m2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<3, 4, T, Q> operator*(mat<1, 4, T, Q> const& m1, mat<3, 1, T, Q> const& m2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<4, 4, T, Q> operator*(mat<1, 4, T, Q> const& m1, mat<4, 1, T, Q> const& m2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<1, 4, T, Q> operator/(mat<1, 4, T, Q> const& m, T scalar);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<1, 4, T, Q> operator/(T scalar, mat<1, 4, T, Q> const& m);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR typename mat<1, 4, T, Q>::col_type operator/(mat<1, 4, T, Q> const& m, typename mat<1, 4, T, Q>::row_type const& v);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR typename mat<1, 4, T, Q>::row_type operator/(typename mat<1, 4, T, Q>::col_type const& v, mat<1, 4, T, Q> const& m);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<1, 4, T, Q> operator/(mat<1, 4, T, Q> const& m1, mat<1, 4, T, Q> const& m2);

	// -- Boolean operators --

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR bool operator==(mat<1, 4, T, Q> const& m1, mat<1, 4, T, Q> const& m2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR bool operator!=(mat<1, 4, T, Q> const& m1, mat<1, 4, T, Q> const& m2);
} //namespace glm

#ifndef GLM_EXTERNAL_TEMPLATE
#include "type_mat1x4.inl"
#endif
