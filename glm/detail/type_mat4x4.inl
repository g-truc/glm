#include "../matrix.hpp"
#include "../geometric.hpp"

namespace glm
{
	// -- Constructors --

#	if GLM_CONFIG_CTOR_INIT == GLM_ENABLE
		template<typename T, qualifier Q>
		GLM_DEFAULTED_DEFAULT_CTOR_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q>::mat()
			: value{col_type(1, 0, 0, 0), col_type(0, 1, 0, 0), col_type(0, 0, 1, 0), col_type(0, 0, 0, 1)}
		{}
#	endif

	template<typename T, qualifier Q>
	template<qualifier P>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q>::mat(mat<4, 4, T, P> const& m)
		: value{col_type(m[0]), col_type(m[1]), col_type(m[2]), col_type(m[3])}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q>::mat(T s)
		: value{col_type(s, 0, 0, 0), col_type(0, s, 0, 0), col_type(0, 0, s, 0), col_type(0, 0, 0, s)}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q>::mat
	(
		T const& x0, T const& y0, T const& z0, T const& w0,
		T const& x1, T const& y1, T const& z1, T const& w1,
		T const& x2, T const& y2, T const& z2, T const& w2,
		T const& x3, T const& y3, T const& z3, T const& w3
	)
		: value{
			col_type(x0, y0, z0, w0),
			col_type(x1, y1, z1, w1),
			col_type(x2, y2, z2, w2),
			col_type(x3, y3, z3, w3)}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q>::mat(col_type const& v0, col_type const& v1, col_type const& v2, col_type const& v3)
		: value{col_type(v0), col_type(v1), col_type(v2), col_type(v3)}
	{}

	template<typename T, qualifier Q>
	template<typename U, qualifier P>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q>::mat(mat<4, 4, U, P> const& m)
		: value{col_type(m[0]), col_type(m[1]), col_type(m[2]), col_type(m[3])}
	{}

	// -- Conversions --

	template<typename T, qualifier Q>
	template<
		typename X1, typename Y1, typename Z1, typename W1,
		typename X2, typename Y2, typename Z2, typename W2,
		typename X3, typename Y3, typename Z3, typename W3,
		typename X4, typename Y4, typename Z4, typename W4>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q>::mat
	(
		X1 const& x1, Y1 const& y1, Z1 const& z1, W1 const& w1,
		X2 const& x2, Y2 const& y2, Z2 const& z2, W2 const& w2,
		X3 const& x3, Y3 const& y3, Z3 const& z3, W3 const& w3,
		X4 const& x4, Y4 const& y4, Z4 const& z4, W4 const& w4
	)
		: value{col_type(x1, y1, z1, w1), col_type(x2, y2, z2, w2), col_type(x3, y3, z3, w3), col_type(x4, y4, z4, w4)}
	{
		static_assert(std::numeric_limits<X1>::is_iec559 || std::numeric_limits<X1>::is_integer || GLM_CONFIG_UNRESTRICTED_GENTYPE, "*mat4x4 constructor only takes float and integer types, 1st parameter type invalid.");
		static_assert(std::numeric_limits<Y1>::is_iec559 || std::numeric_limits<Y1>::is_integer || GLM_CONFIG_UNRESTRICTED_GENTYPE, "*mat4x4 constructor only takes float and integer types, 2nd parameter type invalid.");
		static_assert(std::numeric_limits<Z1>::is_iec559 || std::numeric_limits<Z1>::is_integer || GLM_CONFIG_UNRESTRICTED_GENTYPE, "*mat4x4 constructor only takes float and integer types, 3rd parameter type invalid.");
		static_assert(std::numeric_limits<W1>::is_iec559 || std::numeric_limits<W1>::is_integer || GLM_CONFIG_UNRESTRICTED_GENTYPE, "*mat4x4 constructor only takes float and integer types, 4th parameter type invalid.");

		static_assert(std::numeric_limits<X2>::is_iec559 || std::numeric_limits<X2>::is_integer || GLM_CONFIG_UNRESTRICTED_GENTYPE, "*mat4x4 constructor only takes float and integer types, 5th parameter type invalid.");
		static_assert(std::numeric_limits<Y2>::is_iec559 || std::numeric_limits<Y2>::is_integer || GLM_CONFIG_UNRESTRICTED_GENTYPE, "*mat4x4 constructor only takes float and integer types, 6th parameter type invalid.");
		static_assert(std::numeric_limits<Z2>::is_iec559 || std::numeric_limits<Z2>::is_integer || GLM_CONFIG_UNRESTRICTED_GENTYPE, "*mat4x4 constructor only takes float and integer types, 7th parameter type invalid.");
		static_assert(std::numeric_limits<W2>::is_iec559 || std::numeric_limits<W2>::is_integer || GLM_CONFIG_UNRESTRICTED_GENTYPE, "*mat4x4 constructor only takes float and integer types, 8th parameter type invalid.");

		static_assert(std::numeric_limits<X3>::is_iec559 || std::numeric_limits<X3>::is_integer || GLM_CONFIG_UNRESTRICTED_GENTYPE, "*mat4x4 constructor only takes float and integer types, 9th parameter type invalid.");
		static_assert(std::numeric_limits<Y3>::is_iec559 || std::numeric_limits<Y3>::is_integer || GLM_CONFIG_UNRESTRICTED_GENTYPE, "*mat4x4 constructor only takes float and integer types, 10th parameter type invalid.");
		static_assert(std::numeric_limits<Z3>::is_iec559 || std::numeric_limits<Z3>::is_integer || GLM_CONFIG_UNRESTRICTED_GENTYPE, "*mat4x4 constructor only takes float and integer types, 11th parameter type invalid.");
		static_assert(std::numeric_limits<W3>::is_iec559 || std::numeric_limits<W3>::is_integer || GLM_CONFIG_UNRESTRICTED_GENTYPE, "*mat4x4 constructor only takes float and integer types, 12th parameter type invalid.");

		static_assert(std::numeric_limits<X4>::is_iec559 || std::numeric_limits<X4>::is_integer || GLM_CONFIG_UNRESTRICTED_GENTYPE, "*mat4x4 constructor only takes float and integer types, 13th parameter type invalid.");
		static_assert(std::numeric_limits<Y4>::is_iec559 || std::numeric_limits<Y4>::is_integer || GLM_CONFIG_UNRESTRICTED_GENTYPE, "*mat4x4 constructor only takes float and integer types, 14th parameter type invalid.");
		static_assert(std::numeric_limits<Z4>::is_iec559 || std::numeric_limits<Z4>::is_integer || GLM_CONFIG_UNRESTRICTED_GENTYPE, "*mat4x4 constructor only takes float and integer types, 15th parameter type invalid.");
		static_assert(std::numeric_limits<W4>::is_iec559 || std::numeric_limits<W4>::is_integer || GLM_CONFIG_UNRESTRICTED_GENTYPE, "*mat4x4 constructor only takes float and integer types, 16th parameter type invalid.");
	}

	template<typename T, qualifier Q>
	template<typename V1, typename V2, typename V3, typename V4>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q>::mat(vec<4, V1, Q> const& v1, vec<4, V2, Q> const& v2, vec<4, V3, Q> const& v3, vec<4, V4, Q> const& v4)
			: value{col_type(v1), col_type(v2), col_type(v3), col_type(v4)}
	{
		static_assert(std::numeric_limits<V1>::is_iec559 || std::numeric_limits<V1>::is_integer || GLM_CONFIG_UNRESTRICTED_GENTYPE, "*mat4x4 constructor only takes float and integer types, 1st parameter type invalid.");
		static_assert(std::numeric_limits<V2>::is_iec559 || std::numeric_limits<V2>::is_integer || GLM_CONFIG_UNRESTRICTED_GENTYPE, "*mat4x4 constructor only takes float and integer types, 2nd parameter type invalid.");
		static_assert(std::numeric_limits<V3>::is_iec559 || std::numeric_limits<V3>::is_integer || GLM_CONFIG_UNRESTRICTED_GENTYPE, "*mat4x4 constructor only takes float and integer types, 3rd parameter type invalid.");
		static_assert(std::numeric_limits<V4>::is_iec559 || std::numeric_limits<V4>::is_integer || GLM_CONFIG_UNRESTRICTED_GENTYPE, "*mat4x4 constructor only takes float and integer types, 4th parameter type invalid.");
	}

	// -- Matrix conversions --

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q>::mat(mat<2, 2, T, Q> const& m)
		: value{col_type(m[0], 0, 0), col_type(m[1], 0, 0), col_type(0, 0, 1, 0), col_type(0, 0, 0, 1)}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q>::mat(mat<3, 3, T, Q> const& m)
		: value{col_type(m[0], 0), col_type(m[1], 0), col_type(m[2], 0), col_type(0, 0, 0, 1)}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q>::mat(mat<2, 3, T, Q> const& m)
		: value{col_type(m[0], 0), col_type(m[1], 0), col_type(0, 0, 1, 0), col_type(0, 0, 0, 1)}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q>::mat(mat<3, 2, T, Q> const& m)
		: value{col_type(m[0], 0, 0), col_type(m[1], 0, 0), col_type(m[2], 1, 0), col_type(0, 0, 0, 1)}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q>::mat(mat<2, 4, T, Q> const& m)
		: value{col_type(m[0]), col_type(m[1]), col_type(0, 0, 1, 0), col_type(0, 0, 0, 1)}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q>::mat(mat<4, 2, T, Q> const& m)
		: value{col_type(m[0], 0, 0), col_type(m[1], 0, 0), col_type(0, 0, 1, 0), col_type(0, 0, 0, 1)}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q>::mat(mat<3, 4, T, Q> const& m)
		: value{col_type(m[0]), col_type(m[1]), col_type(m[2]), col_type(0, 0, 0, 1)}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q>::mat(mat<4, 3, T, Q> const& m)
		: value{col_type(m[0], 0), col_type(m[1], 0), col_type(m[2], 0), col_type(m[3], 1)}
	{}

	// -- Accesses --

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR typename mat<4, 4, T, Q>::col_type & mat<4, 4, T, Q>::operator[](typename mat<4, 4, T, Q>::length_type i) noexcept
	{
		GLM_ASSERT_LENGTH(i, this->length());
		return this->value[i];
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR typename mat<4, 4, T, Q>::col_type const& mat<4, 4, T, Q>::operator[](typename mat<4, 4, T, Q>::length_type i) const noexcept
	{
		GLM_ASSERT_LENGTH(i, this->length());
		return this->value[i];
	}

	// -- Unary arithmetic operators --

	template<typename T, qualifier Q>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q>& mat<4, 4, T, Q>::operator=(mat<4, 4, U, Q> const& m)
	{
		//memcpy could be faster
		//memcpy(&this->value, &m.value, 16 * sizeof(valType));
		this->value[0] = m[0];
		this->value[1] = m[1];
		this->value[2] = m[2];
		this->value[3] = m[3];
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q>& mat<4, 4, T, Q>::operator+=(U s)
	{
		this->value[0] += s;
		this->value[1] += s;
		this->value[2] += s;
		this->value[3] += s;
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q>& mat<4, 4, T, Q>::operator+=(mat<4, 4, U, Q> const& m)
	{
		this->value[0] += m[0];
		this->value[1] += m[1];
		this->value[2] += m[2];
		this->value[3] += m[3];
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q> & mat<4, 4, T, Q>::operator-=(U s)
	{
		this->value[0] -= s;
		this->value[1] -= s;
		this->value[2] -= s;
		this->value[3] -= s;
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q> & mat<4, 4, T, Q>::operator-=(mat<4, 4, U, Q> const& m)
	{
		this->value[0] -= m[0];
		this->value[1] -= m[1];
		this->value[2] -= m[2];
		this->value[3] -= m[3];
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q> & mat<4, 4, T, Q>::operator*=(U s)
	{
		this->value[0] *= s;
		this->value[1] *= s;
		this->value[2] *= s;
		this->value[3] *= s;
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q> & mat<4, 4, T, Q>::operator*=(mat<4, 4, U, Q> const& m)
	{
		return (*this = *this * m);
	}

	template<typename T, qualifier Q>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q> & mat<4, 4, T, Q>::operator/=(U s)
	{
		this->value[0] /= s;
		this->value[1] /= s;
		this->value[2] /= s;
		this->value[3] /= s;
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q> & mat<4, 4, T, Q>::operator/=(mat<4, 4, U, Q> const& m)
	{
		return *this *= inverse(m);
	}

	// -- Increment and decrement operators --

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q> & mat<4, 4, T, Q>::operator++()
	{
		++this->value[0];
		++this->value[1];
		++this->value[2];
		++this->value[3];
		return *this;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q> & mat<4, 4, T, Q>::operator--()
	{
		--this->value[0];
		--this->value[1];
		--this->value[2];
		--this->value[3];
		return *this;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q> mat<4, 4, T, Q>::operator++(int)
	{
		mat<4, 4, T, Q> Result(*this);
		++*this;
		return Result;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q> mat<4, 4, T, Q>::operator--(int)
	{
		mat<4, 4, T, Q> Result(*this);
		--*this;
		return Result;
	}

	// -- Unary constant operators --

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q> operator+(mat<4, 4, T, Q> const& m)
	{
		return m;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q> operator-(mat<4, 4, T, Q> const& m)
	{
		return mat<4, 4, T, Q>(
			-m[0],
			-m[1],
			-m[2],
			-m[3]);
	}

	// -- Binary arithmetic operators --

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q> operator+(mat<4, 4, T, Q> const& m, T scalar)
	{
		return mat<4, 4, T, Q>(
			m[0] + scalar,
			m[1] + scalar,
			m[2] + scalar,
			m[3] + scalar);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q> operator+(T scalar, mat<4, 4, T, Q> const& m)
	{
		return mat<4, 4, T, Q>(
			m[0] + scalar,
			m[1] + scalar,
			m[2] + scalar,
			m[3] + scalar);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q> operator+(mat<4, 4, T, Q> const& m1, mat<4, 4, T, Q> const& m2)
	{
		return mat<4, 4, T, Q>(
			m1[0] + m2[0],
			m1[1] + m2[1],
			m1[2] + m2[2],
			m1[3] + m2[3]);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q> operator-(mat<4, 4, T, Q> const& m, T scalar)
	{
		return mat<4, 4, T, Q>(
			m[0] - scalar,
			m[1] - scalar,
			m[2] - scalar,
			m[3] - scalar);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q> operator-(T scalar, mat<4, 4, T, Q> const& m)
	{
		return mat<4, 4, T, Q>(
			scalar - m[0],
			scalar - m[1],
			scalar - m[2],
			scalar - m[3]);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q> operator-(mat<4, 4, T, Q> const& m1, mat<4, 4, T, Q> const& m2)
	{
		return mat<4, 4, T, Q>(
			m1[0] - m2[0],
			m1[1] - m2[1],
			m1[2] - m2[2],
			m1[3] - m2[3]);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q> operator*(mat<4, 4, T, Q> const& m, T scalar)
	{
		return mat<4, 4, T, Q>(
			m[0] * scalar,
			m[1] * scalar,
			m[2] * scalar,
			m[3] * scalar);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q> operator*(T scalar, mat<4, 4, T, Q> const& m)
	{
		return mat<4, 4, T, Q>(
			m[0] * scalar,
			m[1] * scalar,
			m[2] * scalar,
			m[3] * scalar);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR typename mat<4, 4, T, Q>::col_type operator*
	(
		mat<4, 4, T, Q> const& m,
		typename mat<4, 4, T, Q>::row_type const& v
	)
	{
/*
		__m128 v0 = _mm_shuffle_ps(v.data, v.data, _MM_SHUFFLE(0, 0, 0, 0));
		__m128 v1 = _mm_shuffle_ps(v.data, v.data, _MM_SHUFFLE(1, 1, 1, 1));
		__m128 v2 = _mm_shuffle_ps(v.data, v.data, _MM_SHUFFLE(2, 2, 2, 2));
		__m128 v3 = _mm_shuffle_ps(v.data, v.data, _MM_SHUFFLE(3, 3, 3, 3));

		__m128 m0 = _mm_mul_ps(m[0].data, v0);
		__m128 m1 = _mm_mul_ps(m[1].data, v1);
		__m128 a0 = _mm_add_ps(m0, m1);

		__m128 m2 = _mm_mul_ps(m[2].data, v2);
		__m128 m3 = _mm_mul_ps(m[3].data, v3);
		__m128 a1 = _mm_add_ps(m2, m3);

		__m128 a2 = _mm_add_ps(a0, a1);

		return typename mat<4, 4, T, Q>::col_type(a2);
*/

		typename mat<4, 4, T, Q>::col_type const Mov0(v[0]);
		typename mat<4, 4, T, Q>::col_type const Mov1(v[1]);
		typename mat<4, 4, T, Q>::col_type const Mul0 = m[0] * Mov0;
		typename mat<4, 4, T, Q>::col_type const Mul1 = m[1] * Mov1;
		typename mat<4, 4, T, Q>::col_type const Add0 = Mul0 + Mul1;
		typename mat<4, 4, T, Q>::col_type const Mov2(v[2]);
		typename mat<4, 4, T, Q>::col_type const Mov3(v[3]);
		typename mat<4, 4, T, Q>::col_type const Mul2 = m[2] * Mov2;
		typename mat<4, 4, T, Q>::col_type const Mul3 = m[3] * Mov3;
		typename mat<4, 4, T, Q>::col_type const Add1 = Mul2 + Mul3;
		typename mat<4, 4, T, Q>::col_type const Add2 = Add0 + Add1;
		return Add2;

/*
		return typename mat<4, 4, T, Q>::col_type(
			m[0][0] * v[0] + m[1][0] * v[1] + m[2][0] * v[2] + m[3][0] * v[3],
			m[0][1] * v[0] + m[1][1] * v[1] + m[2][1] * v[2] + m[3][1] * v[3],
			m[0][2] * v[0] + m[1][2] * v[1] + m[2][2] * v[2] + m[3][2] * v[3],
			m[0][3] * v[0] + m[1][3] * v[1] + m[2][3] * v[2] + m[3][3] * v[3]);
*/
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR typename mat<4, 4, T, Q>::row_type operator*
	(
		typename mat<4, 4, T, Q>::col_type const& v,
		mat<4, 4, T, Q> const& m
	)
	{
		return typename mat<4, 4, T, Q>::row_type(
			glm::dot(m[0], v),
			glm::dot(m[1], v),
			glm::dot(m[2], v),
			glm::dot(m[3], v));
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<2, 4, T, Q> operator*(mat<4, 4, T, Q> const& m1, mat<2, 4, T, Q> const& m2)
	{
		return mat<2, 4, T, Q>(
			m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2] + m1[3][0] * m2[0][3],
			m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2] + m1[3][1] * m2[0][3],
			m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1] + m1[2][2] * m2[0][2] + m1[3][2] * m2[0][3],
			m1[0][3] * m2[0][0] + m1[1][3] * m2[0][1] + m1[2][3] * m2[0][2] + m1[3][3] * m2[0][3],
			m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2] + m1[3][0] * m2[1][3],
			m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2] + m1[3][1] * m2[1][3],
			m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1] + m1[2][2] * m2[1][2] + m1[3][2] * m2[1][3],
			m1[0][3] * m2[1][0] + m1[1][3] * m2[1][1] + m1[2][3] * m2[1][2] + m1[3][3] * m2[1][3]);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<3, 4, T, Q> operator*(mat<4, 4, T, Q> const& m1, mat<3, 4, T, Q> const& m2)
	{
		return mat<3, 4, T, Q>(
			m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2] + m1[3][0] * m2[0][3],
			m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2] + m1[3][1] * m2[0][3],
			m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1] + m1[2][2] * m2[0][2] + m1[3][2] * m2[0][3],
			m1[0][3] * m2[0][0] + m1[1][3] * m2[0][1] + m1[2][3] * m2[0][2] + m1[3][3] * m2[0][3],
			m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2] + m1[3][0] * m2[1][3],
			m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2] + m1[3][1] * m2[1][3],
			m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1] + m1[2][2] * m2[1][2] + m1[3][2] * m2[1][3],
			m1[0][3] * m2[1][0] + m1[1][3] * m2[1][1] + m1[2][3] * m2[1][2] + m1[3][3] * m2[1][3],
			m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1] + m1[2][0] * m2[2][2] + m1[3][0] * m2[2][3],
			m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1] + m1[2][1] * m2[2][2] + m1[3][1] * m2[2][3],
			m1[0][2] * m2[2][0] + m1[1][2] * m2[2][1] + m1[2][2] * m2[2][2] + m1[3][2] * m2[2][3],
			m1[0][3] * m2[2][0] + m1[1][3] * m2[2][1] + m1[2][3] * m2[2][2] + m1[3][3] * m2[2][3]);
	}

	namespace detail
	{
		template<typename T, qualifier Q, bool is_aligned>
		struct mul4x4 {};

		template<typename T, qualifier Q>
		struct mul4x4<T, Q, true>
		{
			GLM_FUNC_QUALIFIER GLM_CONSTEXPR static mat<4, 4, T, Q> call(mat<4, 4, T, Q> const& m1, mat<4, 4, T, Q> const& m2)
			{
				typename mat<4, 4, T, Q>::col_type const SrcA0 = m1[0];
				typename mat<4, 4, T, Q>::col_type const SrcA1 = m1[1];
				typename mat<4, 4, T, Q>::col_type const SrcA2 = m1[2];
				typename mat<4, 4, T, Q>::col_type const SrcA3 = m1[3];

				typename mat<4, 4, T, Q>::col_type const SrcB0 = m2[0];
				typename mat<4, 4, T, Q>::col_type const SrcB1 = m2[1];
				typename mat<4, 4, T, Q>::col_type const SrcB2 = m2[2];
				typename mat<4, 4, T, Q>::col_type const SrcB3 = m2[3];

				typename mat<4, 4, T, Q>::col_type const tmp0 = glm::fma(SrcA3, splatW(SrcB0), glm::fma(SrcA2, splatZ(SrcB0), glm::fma(SrcA1, splatY(SrcB0), SrcA0 * splatX(SrcB0))));
				typename mat<4, 4, T, Q>::col_type const tmp1 = glm::fma(SrcA3, splatW(SrcB1), glm::fma(SrcA2, splatZ(SrcB1), glm::fma(SrcA1, splatY(SrcB1), SrcA0 * splatX(SrcB1))));
				typename mat<4, 4, T, Q>::col_type const tmp2 = glm::fma(SrcA3, splatW(SrcB2), glm::fma(SrcA2, splatZ(SrcB2), glm::fma(SrcA1, splatY(SrcB2), SrcA0 * splatX(SrcB2))));
				typename mat<4, 4, T, Q>::col_type const tmp3 = glm::fma(SrcA3, splatW(SrcB3), glm::fma(SrcA2, splatZ(SrcB3), glm::fma(SrcA1, splatY(SrcB3), SrcA0 * splatX(SrcB3))));

				return mat < 4, 4, T, Q > (tmp0, tmp1, tmp2, tmp3);
			}
		};

		template<typename T, qualifier Q>
		struct mul4x4<T, Q, false>
		{
			GLM_FUNC_QUALIFIER GLM_CONSTEXPR static mat<4, 4, T, Q> call(mat<4, 4, T, Q> const& m1, mat<4, 4, T, Q> const& m2)
			{
				typename mat<4, 4, T, Q>::col_type const& SrcA0 = m1[0];
				typename mat<4, 4, T, Q>::col_type const& SrcA1 = m1[1];
				typename mat<4, 4, T, Q>::col_type const& SrcA2 = m1[2];
				typename mat<4, 4, T, Q>::col_type const& SrcA3 = m1[3];

				typename mat<4, 4, T, Q>::col_type const& SrcB0 = m2[0];
				typename mat<4, 4, T, Q>::col_type const& SrcB1 = m2[1];
				typename mat<4, 4, T, Q>::col_type const& SrcB2 = m2[2];
				typename mat<4, 4, T, Q>::col_type const& SrcB3 = m2[3];

				// note: the following lines are decomposed to have consistent results between simd and non simd code (prevent rounding error because of operation order)
				//Result[0] = SrcA3 * SrcB0.w + SrcA2 * SrcB0.z + SrcA1 * SrcB0.y + SrcA0 * SrcB0.x;
				//Result[1] = SrcA3 * SrcB1.w + SrcA2 * SrcB1.z + SrcA1 * SrcB1.y + SrcA0 * SrcB1.x;
				//Result[2] = SrcA3 * SrcB2.w + SrcA2 * SrcB2.z + SrcA1 * SrcB2.y + SrcA0 * SrcB2.x;
				//Result[3] = SrcA3 * SrcB3.w + SrcA2 * SrcB3.z + SrcA1 * SrcB3.y + SrcA0 * SrcB3.x;

				typename mat<4, 4, T, Q>::col_type tmp0 = SrcA0 * SrcB0.x;
				tmp0 += SrcA1 * SrcB0.y;
				tmp0 += SrcA2 * SrcB0.z;
				tmp0 += SrcA3 * SrcB0.w;
				typename mat<4, 4, T, Q>::col_type tmp1 = SrcA0 * SrcB1.x;
				tmp1 += SrcA1 * SrcB1.y;
				tmp1 += SrcA2 * SrcB1.z;
				tmp1 += SrcA3 * SrcB1.w;
				typename mat<4, 4, T, Q>::col_type tmp2 = SrcA0 * SrcB2.x;
				tmp2 += SrcA1 * SrcB2.y;
				tmp2 += SrcA2 * SrcB2.z;
				tmp2 += SrcA3 * SrcB2.w;
				typename mat<4, 4, T, Q>::col_type tmp3 = SrcA0 * SrcB3.x;
				tmp3 += SrcA1 * SrcB3.y;
				tmp3 += SrcA2 * SrcB3.z;
				tmp3 += SrcA3 * SrcB3.w;

				return mat<4, 4, T, Q>(tmp0, tmp1, tmp2, tmp3);
			}
		};
	}


	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q> operator*(mat<4, 4, T, Q> const& m1, mat<4, 4, T, Q> const& m2)
	{
		return detail::mul4x4<T, Q, detail::is_aligned<Q>::value>::call(m1, m2);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q> operator/(mat<4, 4, T, Q> const& m, T scalar)
	{
		return mat<4, 4, T, Q>(
			m[0] / scalar,
			m[1] / scalar,
			m[2] / scalar,
			m[3] / scalar);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q> operator/(T scalar,	mat<4, 4, T, Q> const& m)
	{
		return mat<4, 4, T, Q>(
			scalar / m[0],
			scalar / m[1],
			scalar / m[2],
			scalar / m[3]);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR typename mat<4, 4, T, Q>::col_type operator/(mat<4, 4, T, Q> const& m, typename mat<4, 4, T, Q>::row_type const& v)
	{
		return inverse(m) * v;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR typename mat<4, 4, T, Q>::row_type operator/(typename mat<4, 4, T, Q>::col_type const& v, mat<4, 4, T, Q> const& m)
	{
		return v * inverse(m);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q> operator/(mat<4, 4, T, Q> const& m1, mat<4, 4, T, Q> const& m2)
	{
		mat<4, 4, T, Q> m1_copy(m1);
		return m1_copy /= m2;
	}

	// -- Boolean operators --

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR bool operator==(mat<4, 4, T, Q> const& m1, mat<4, 4, T, Q> const& m2)
	{
		return (m1[0] == m2[0]) && (m1[1] == m2[1]) && (m1[2] == m2[2]) && (m1[3] == m2[3]);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR bool operator!=(mat<4, 4, T, Q> const& m1, mat<4, 4, T, Q> const& m2)
	{
		return (m1[0] != m2[0]) || (m1[1] != m2[1]) || (m1[2] != m2[2]) || (m1[3] != m2[3]);
	}
}//namespace glm

#if GLM_CONFIG_SIMD == GLM_ENABLE
#	include "type_mat4x4_simd.inl"
#endif
