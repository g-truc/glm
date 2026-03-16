/// @ref core
/// @file glm/detail/type_mat4x1.hpp

#pragma once

#include "type_vec1.hpp"
#include "type_vec4.hpp"
#include <limits>
#include <cstddef>

namespace glm
{
	template<typename T, qualifier Q>
	struct mat<4, 1, T, Q>
	{
		typedef vec<1, T, Q> col_type;
		typedef vec<4, T, Q> row_type;
		typedef mat<4, 1, T, Q> type;
		typedef mat<1, 4, T, Q> transpose_type;
		typedef T value_type;

	private:
		col_type value[4];

	public:
		// -- Accesses --

		typedef length_t length_type;
		GLM_FUNC_DECL static constexpr length_type length() { return 4; }

		GLM_FUNC_DECL GLM_CONSTEXPR col_type & operator[](length_type i) noexcept;
		GLM_FUNC_DECL GLM_CONSTEXPR col_type const& operator[](length_type i) const noexcept;

		// -- Constructors --

		GLM_DEFAULTED_DEFAULT_CTOR_DECL GLM_CONSTEXPR mat() GLM_DEFAULT_CTOR;
		GLM_CTOR_DECL mat(mat<4, 1, T, Q> const& m) = default;
		template<qualifier P>
		GLM_CTOR_DECL mat(mat<4, 1, T, P> const& m);

		GLM_CTOR_DECL GLM_EXPLICIT mat(T scalar);
		GLM_CTOR_DECL mat(
			T const& x1, T const& x2, T const& x3, T const& x4);
		GLM_CTOR_DECL mat(
			col_type const& v1,
			col_type const& v2,
			col_type const& v3,
			col_type const& v4);

		// -- Conversions --

		template<typename X1, typename X2, typename X3, typename X4>
		GLM_CTOR_DECL mat(
			X1 const& x1, X2 const& x2, X3 const& x3, X4 const& x4);

		template<typename V1, typename V2, typename V3, , typename V4>
		GLM_CTOR_DECL mat(
			vec<1, V1, Q> const& v1,
			vec<1, V2, Q> const& v2,
			vec<1, V3, Q> const& v3,
			vec<1, V4, Q> const& v4);

		// -- Matrix conversions --

		template<typename U, qualifier P>
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<4, 1, U, P> const& m);

		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<1, 1, T, Q> const& x);
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<2, 2, T, Q> const& x);
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<3, 3, T, Q> const& x);
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<4, 4, T, Q> const& x);
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<1, 2, T, Q> const& x);
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<2, 1, T, Q> const& x);
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<1, 3, T, Q> const& x);
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<3, 1, T, Q> const& x);
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<1, 4, T, Q> const& x);
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<2, 3, T, Q> const& x);
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<3, 2, T, Q> const& x);
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<2, 4, T, Q> const& x);
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<4, 2, T, Q> const& x);
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<3, 4, T, Q> const& x);
		GLM_CTOR_DECL GLM_EXPLICIT mat(mat<4, 3, T, Q> const& x);

		// -- Unary arithmetic operators --

		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR mat<4, 1, T, Q>& operator=(mat<4, 1, T, Q> const& m) = default;

		template<typename U>
		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR mat<4, 1, T, Q>& operator=(mat<4, 1, U, Q> const& m);
		template<typename U>
		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR mat<4, 1, T, Q>& operator+=(U s);
		template<typename U>
		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR mat<4, 1, T, Q>& operator+=(mat<4, 1, U, Q> const& m);
		template<typename U>
		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR mat<4, 1, T, Q>& operator-=(U s);
		template<typename U>
		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR mat<4, 1, T, Q>& operator-=(mat<4, 1, U, Q> const& m);
		template<typename U>
		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR mat<4, 1, T, Q>& operator*=(U s);
		template<typename U>
		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR mat<4, 1, T, Q>& operator*=(mat<4, 1, U, Q> const& m);
		template<typename U>
		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR mat<4, 1, T, Q>& operator/=(U s);
		template<typename U>
		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR mat<4, 1, T, Q>& operator/=(mat<4, 1, U, Q> const& m);

		// -- Increment and decrement operators --

		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR mat<4, 1, T, Q> & operator++ ();
		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR mat<4, 1, T, Q> & operator-- ();
		GLM_FUNC_DECL GLM_CONSTEXPR mat<4, 1, T, Q> operator++(int);
		GLM_FUNC_DECL GLM_CONSTEXPR mat<4, 1, T, Q> operator--(int);
	};

	// -- Unary operators --

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<4, 1, T, Q> operator+(mat<4, 1, T, Q> const& m);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<4, 1, T, Q> operator-(mat<4, 1, T, Q> const& m);

	// -- Binary operators --

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<4, 1, T, Q> operator+(mat<4, 1, T, Q> const& m, T scalar);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<4, 1, T, Q> operator+(T scalar, mat<4, 1, T, Q> const& m);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<4, 1, T, Q> operator+(mat<4, 1, T, Q> const& m1, mat<4, 1, T, Q> const& m2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<4, 1, T, Q> operator-(mat<4, 1, T, Q> const& m, T scalar);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<4, 1, T, Q> operator-(T scalar, mat<4, 1, T, Q> const& m);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<4, 1, T, Q> operator-(mat<4, 1, T, Q> const& m1, mat<4, 1, T, Q> const& m2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<4, 1, T, Q> operator*(mat<4, 1, T, Q> const& m, T scalar);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<4, 1, T, Q> operator*(T scalar, mat<4, 1, T, Q> const& m);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR typename mat<4, 1, T, Q>::col_type operator*(mat<4, 1, T, Q> const& m, typename mat<4, 1, T, Q>::row_type const& v);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR typename mat<4, 1, T, Q>::row_type operator*(typename mat<4, 1, T, Q>::col_type const& v, mat<4, 1, T, Q> const& m);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<1, 1, T, Q> operator*(mat<4, 1, T, Q> const& m1, mat<1, 4, T, Q> const& m2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<2, 1, T, Q> operator*(mat<4, 1, T, Q> const& m1, mat<2, 4, T, Q> const& m2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<4, 1, T, Q> operator*(mat<4, 1, T, Q> const& m1, mat<3, 4, T, Q> const& m2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<4, 1, T, Q> operator*(mat<4, 1, T, Q> const& m1, mat<4, 4, T, Q> const& m2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<4, 1, T, Q> operator/(mat<4, 1, T, Q> const& m, T scalar);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<4, 1, T, Q> operator/(T scalar, mat<4, 1, T, Q> const& m);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR typename mat<4, 1, T, Q>::col_type operator/(mat<4, 1, T, Q> const& m, typename mat<4, 1, T, Q>::row_type const& v);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR typename mat<4, 1, T, Q>::row_type operator/(typename mat<4, 1, T, Q>::col_type const& v, mat<4, 1, T, Q> const& m);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR mat<4, 1, T, Q> operator/(mat<4, 1, T, Q> const& m1, mat<4, 1, T, Q> const& m2);

	// -- Boolean operators --

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR bool operator==(mat<4, 1, T, Q> const& m1, mat<4, 1, T, Q> const& m2);

	template<typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR bool operator!=(mat<4, 1, T, Q> const& m1, mat<4, 1, T, Q> const& m2);
} //namespace glm

#ifndef GLM_EXTERNAL_TEMPLATE
#include "type_mat4x1.inl"
#endif
