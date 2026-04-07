/// @ref core
/// @file glm/detail/type_mat3x1.hpp

#pragma once

#include "type_vec1.hpp"
#include "type_vec3.hpp"
#include <limits>
#include <cstddef>

namespace glm
{
	template<typename T, qualifier Q>
	struct mat<3, 1, T, Q>
	{
		typedef vec<1, T, Q> col_type;
		typedef vec<3, T, Q> row_type;
		typedef mat<3, 1, T, Q> type;
		typedef mat<1, 3, T, Q> transpose_type;
		typedef T value_type;

	private:
		col_type value[3];

	public:
		// -- Accesses --

		typedef length_t length_type;
		GLM_FUNC_DECL static constexpr length_type length() { return 3; }

		GLM_FUNC_DECL GLM_CONSTEXPR col_type & operator[](length_type i) noexcept;
		GLM_FUNC_DECL GLM_CONSTEXPR col_type const& operator[](length_type i) const noexcept;

		// -- Constructors --

		GLM_DEFAULTED_DEFAULT_CTOR_DECL GLM_CONSTEXPR mat() GLM_DEFAULT_CTOR;
		GLM_CTOR_DECL mat(mat<3, 1, T, Q> const& m) = default;
		template<qualifier P>
		GLM_CTOR_DECL mat(mat<3, 1, T, P> const& m);

		GLM_CTOR_DECL GLM_EXPLICIT mat(T scalar);
		GLM_CTOR_DECL mat(
			T const& x1, T const& x2, T const& x3);
		GLM_CTOR_DECL mat(
			col_type const& v1,
			col_type const& v2,
			col_type const& v3);

		// -- Conversions --

		template<typename X1, typename X2, typename X3>
		GLM_CTOR_DECL mat(
			X1 const& x1, X2 const& x2, X3 const& x3);

		template<typename U, typename V, typename W>
		GLM_CTOR_DECL mat(
			vec<1, U, Q> const& v1,
			vec<1, V, Q> const& v2,
			vec<1, W, Q> const& v3);

		// -- Matrix conversions --

		template<typename U, qualifier P>
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<3, 1, U, P> const& m);

		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<1, 1, T, Q> const& x);
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<2, 2, T, Q> const& x);
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<3, 3, T, Q> const& x);
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<4, 4, T, Q> const& x);
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<1, 2, T, Q> const& x);
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<2, 1, T, Q> const& x);
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<1, 3, T, Q> const& x);
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<1, 4, T, Q> const& x);
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<4, 1, T, Q> const& x);
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<2, 3, T, Q> const& x);
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<3, 2, T, Q> const& x);
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<2, 4, T, Q> const& x);
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<4, 2, T, Q> const& x);
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<3, 4, T, Q> const& x);
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<4, 3, T, Q> const& x);

		// -- Unary arithmetic operators --

		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR mat<3, 1, T, Q>& operator=(mat<3, 1, T, Q> const& m) = default;

		template<typename U>
		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR mat<3, 1, T, Q>& operator=(mat<3, 1, U, Q> const& m);
		template<typename U>
		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR mat<3, 1, T, Q>& operator+=(U s);
		template<typename U>
		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR mat<3, 1, T, Q>& operator+=(mat<3, 1, U, Q> const& m);
		template<typename U>
		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR mat<3, 1, T, Q>& operator-=(U s);
		template<typename U>
		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR mat<3, 1, T, Q>& operator-=(mat<3, 1, U, Q> const& m);
		template<typename U>
		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR mat<3, 1, T, Q>& operator*=(U s);
		template<typename U>
		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR mat<3, 1, T, Q>& operator*=(mat<3, 1, U, Q> const& m);
		template<typename U>
		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR mat<3, 1, T, Q>& operator/=(U s);
		template<typename U>
		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR mat<3, 1, T, Q>& operator/=(mat<3, 1, U, Q> const& m);

		// -- Increment and decrement operators --

		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR mat<3, 1, T, Q> & operator++ ();
		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR mat<3, 1, T, Q> & operator-- ();
		GLM_FUNC_DECL GLM_CONSTEXPR mat<3, 1, T, Q> operator++(int);
		GLM_FUNC_DECL GLM_CONSTEXPR mat<3, 1, T, Q> operator--(int);
	};

	// -- Unary operators --

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<3, 1, T, Q> operator+(mat<3, 1, T, Q> const& m);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<3, 1, T, Q> operator-(mat<3, 1, T, Q> const& m);

	// -- Binary operators --

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<3, 1, T, Q> operator+(mat<3, 1, T, Q> const& m, T scalar);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<3, 1, T, Q> operator+(T scalar, mat<3, 1, T, Q> const& m);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<3, 1, T, Q> operator+(mat<3, 1, T, Q> const& m1, mat<3, 1, T, Q> const& m2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<3, 1, T, Q> operator-(mat<3, 1, T, Q> const& m, T scalar);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<3, 1, T, Q> operator-(T scalar, mat<3, 1, T, Q> const& m);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<3, 1, T, Q> operator-(mat<3, 1, T, Q> const& m1, mat<3, 1, T, Q> const& m2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<3, 1, T, Q> operator*(mat<3, 1, T, Q> const& m, T scalar);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<3, 1, T, Q> operator*(T scalar, mat<3, 1, T, Q> const& m);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR typename mat<3, 1, T, Q>::col_type operator*(mat<3, 1, T, Q> const& m, typename mat<3, 1, T, Q>::row_type const& v);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR typename mat<3, 1, T, Q>::row_type operator*(typename mat<3, 1, T, Q>::col_type const& v, mat<3, 1, T, Q> const& m);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<1, 1, T, Q> operator*(mat<3, 1, T, Q> const& m1, mat<1, 3, T, Q> const& m2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<2, 1, T, Q> operator*(mat<3, 1, T, Q> const& m1, mat<2, 3, T, Q> const& m2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<3, 1, T, Q> operator*(mat<3, 1, T, Q> const& m1, mat<3, 3, T, Q> const& m2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<4, 1, T, Q> operator*(mat<3, 1, T, Q> const& m1, mat<4, 3, T, Q> const& m2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<3, 1, T, Q> operator/(mat<3, 1, T, Q> const& m, T scalar);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<3, 1, T, Q> operator/(T scalar, mat<3, 1, T, Q> const& m);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR typename mat<3, 1, T, Q>::col_type operator/(mat<3, 1, T, Q> const& m, typename mat<3, 1, T, Q>::row_type const& v);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR typename mat<3, 1, T, Q>::row_type operator/(typename mat<3, 1, T, Q>::col_type const& v, mat<3, 1, T, Q> const& m);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<3, 1, T, Q> operator/(mat<3, 1, T, Q> const& m1, mat<3, 1, T, Q> const& m2);

	// -- Boolean operators --

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR bool operator==(mat<3, 1, T, Q> const& m1, mat<3, 1, T, Q> const& m2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR bool operator!=(mat<3, 1, T, Q> const& m1, mat<3, 1, T, Q> const& m2);
} //namespace glm

#ifndef GLM_EXTERNAL_TEMPLATE
#include "type_mat3x1.inl"
#endif
