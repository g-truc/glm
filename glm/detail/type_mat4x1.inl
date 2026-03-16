#include "../matrix.hpp"

namespace glm
{
	// -- Constructors --

#	if GLM_CONFIG_CTOR_INIT == GLM_ENABLE
		template<typename T, qualifier Q>
		GLM_DEFAULTED_DEFAULT_CTOR_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q>::mat()
			: value{col_type(1), col_type(0), col_type(0), col_type(0)}
		{}
#	endif

	template<typename T, qualifier Q>
	template<qualifier P>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q>::mat(mat<4, 1, T, P> const& m)
		: value{col_type(m[0]), col_type(m[1]), col_type(m[2]), col_type(m[3])}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q>::mat(T scalar)
		: value{col_type(scalar), col_type(0), col_type(0), col_type(0)}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q>::mat
	(
		T const& x0, T const& x1, T const& x2, T const& x3
	)
		: value{col_type(x0), col_type(x1), col_type(x2), col_type(x3)}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q>::mat(col_type const& v0, col_type const& v1, col_type const& v2, col_type const& v3)
		: value{v0, v1, v2, v3}
	{}

	// -- Conversion constructors --

	template<typename T, qualifier Q>
	template<typename X1, typename X2, typename X3, typename X4>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q>::mat
	(
		X1 const& x1, X2 const& x2, X3 const& x3, X4 const& x4
	)
		: value{col_type(static_cast<T>(x1)), col_type(static_cast<T>(x2)), col_type(static_cast<T>(x3)), col_type(static_cast<T>(x4)) }
	{}

	template<typename T, qualifier Q>
	template<typename V1, typename V2, typename V3, typename V4>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q>::mat(vec<1, V1, Q> const& v1, vec<1, V2, Q> const& v2, vec<1, V3, Q> const& v3, vec<1, V4, Q> const& v4)
		: value{col_type(v1), col_type(v2), col_type(v3), col_type(v4)}
	{}

	// -- mat4x1 matrix conversions --

	template<typename T, qualifier Q>
	template<typename U, qualifier P>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q>::mat(mat<4, 1, U, P> const& m)
		: value{col_type(m[0]), col_type(m[1]), col_type(m[2]), col_type(m[3])}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q>::mat(mat<1, 1, T, Q> const& m)
		: value{col_type(m[0]), col_type(0), col_type(0), col_type(0)}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q>::mat(mat<2, 2, T, Q> const& m)
		: value{col_type(m[0]), col_type(m[1]), col_type(0), col_type(0)}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q>::mat(mat<3, 3, T, Q> const& m)
		: value{col_type(m[0]), col_type(m[1]), col_type(m[2]), col_type(0)}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q>::mat(mat<4, 4, T, Q> const& m)
		: value{col_type(m[0]), col_type(m[1]), col_type(m[2]), col_type(m[3])}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q>::mat(mat<1, 2, T, Q> const& m)
		: value{col_type(m[0]), col_type(0), col_type(0), col_type(0)}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q>::mat(mat<2, 1, T, Q> const& m)
		: value{col_type(m[0]), col_type(m[1]), col_type(0), col_type(0)}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q>::mat(mat<1, 3, T, Q> const& m)
		: value{col_type(m[0]), col_type(0), col_type(0), col_type(0)}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q>::mat(mat<3, 1, T, Q> const& m)
		: value{col_type(m[0]), col_type(m[1]), col_type(m[2]), col_type(0)}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q>::mat(mat<1, 4, T, Q> const& m)
		: value{col_type(m[0]), col_type(0), col_type(0), col_type(0)}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q>::mat(mat<2, 3, T, Q> const& m)
		: value{col_type(m[0]), col_type(m[1]), col_type(0), col_type(0)}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q>::mat(mat<3, 2, T, Q> const& m)
		: value{col_type(m[0]), col_type(m[1]), col_type(m[2]), col_type(0)}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q>::mat(mat<2, 4, T, Q> const& m)
		: value{col_type(m[0]), col_type(m[1]), col_type(0), col_type(0)}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q>::mat(mat<4, 2, T, Q> const& m)
		: value{col_type(m[0]), col_type(m[1]), col_type(m[2]), col_type(m[3])}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q>::mat(mat<3, 4, T, Q> const& m)
		: value{col_type(m[0]), col_type(m[1]), col_type(m[2]), col_type(0)}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q>::mat(mat<4, 3, T, Q> const& m)
		: value{col_type(m[0]), col_type(m[1]), col_type(m[2]), col_type(m[3])}
	{}

	// -- Accesses --

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR typename mat<4, 1, T, Q>::col_type& mat<4, 1, T, Q>::operator[](typename mat<4, 1, T, Q>::length_type i) noexcept
	{
		GLM_ASSERT_LENGTH(i, this->length());
		return this->value[i];
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR typename mat<4, 1, T, Q>::col_type const& mat<4, 1, T, Q>::operator[](typename mat<4, 1, T, Q>::length_type i) const noexcept
	{
		GLM_ASSERT_LENGTH(i, this->length());
		return this->value[i];
	}

	// -- Unary updatable operators --

	template<typename T, qualifier Q>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q>& mat<4, 1, T, Q>::operator=(mat<4, 1, U, Q> const& m)
	{
		this->value[0] = m[0];
		this->value[1] = m[1];
		this->value[2] = m[2];
		this->value[3] = m[3];
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q>& mat<4, 1, T, Q>::operator+=(U scalar)
	{
		this->value[0] += scalar;
		this->value[1] += scalar;
		this->value[2] += scalar;
		this->value[3] += scalar;
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q>& mat<4, 1, T, Q>::operator+=(mat<4, 1, U, Q> const& m)
	{
		this->value[0] += m[0];
		this->value[1] += m[1];
		this->value[2] += m[2];
		this->value[3] += m[3];
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q>& mat<4, 1, T, Q>::operator-=(U scalar)
	{
		this->value[0] -= scalar;
		this->value[1] -= scalar;
		this->value[2] -= scalar;
		this->value[3] -= scalar;
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q>& mat<4, 1, T, Q>::operator-=(mat<4, 1, U, Q> const& m)
	{
		this->value[0] -= m[0];
		this->value[1] -= m[1];
		this->value[2] -= m[2];
		this->value[3] -= m[3];
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q>& mat<4, 1, T, Q>::operator*=(U scalar)
	{
		this->value[0] *= scalar;
		this->value[1] *= scalar;
		this->value[2] *= scalar;
		this->value[3] *= scalar;
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q>& mat<4, 1, T, Q>::operator*=(mat<4, 1, U, Q> const& m)
	{
		return (*this = *this * m);
	}

	template<typename T, qualifier Q>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q>& mat<4, 1, T, Q>::operator/=(U scalar)
	{
		this->value[0] /= scalar;
		this->value[1] /= scalar;
		this->value[2] /= scalar;
		this->value[3] /= scalar;
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q>& mat<4, 1, T, Q>::operator/=(mat<4, 1, U, Q> const& m)
	{
		return *this *= inverse(m);
	}

	// -- Increment and decrement operators --

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q>& mat<4, 1, T, Q>::operator++()
	{
		++this->value[0];
		++this->value[1];
		++this->value[2];
		++this->value[3];
		return *this;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q>& mat<4, 1, T, Q>::operator--()
	{
		--this->value[0];
		--this->value[1];
		--this->value[2];
		--this->value[3];
		return *this;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q> mat<4, 1, T, Q>::operator++(int)
	{
		mat<4, 1, T, Q> Result(*this);
		++*this;
		return Result;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q> mat<4, 1, T, Q>::operator--(int)
	{
		mat<4, 1, T, Q> Result(*this);
		--*this;
		return Result;
	}

	// -- Unary arithmetic operators --

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q> operator+(mat<4, 1, T, Q> const& m)
	{
		return m;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q> operator-(mat<4, 1, T, Q> const& m)
	{
		return mat<4, 1, T, Q>(
			-m[0],
			-m[1],
			-m[2],
			-m[3]);
	}

	// -- Binary arithmetic operators --

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q> operator+(mat<4, 1, T, Q> const& m, T scalar)
	{
		return mat<4, 1, T, Q>(
			m[0] + scalar,
			m[1] + scalar,
			m[2] + scalar,
			m[3] + scalar);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q> operator+(T scalar, mat<4, 1, T, Q> const& m)
	{
		return mat<4, 1, T, Q>(
			m[0] + scalar,
			m[1] + scalar,
			m[2] + scalar,
			m[3] + scalar);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q> operator+(mat<4, 1, T, Q> const& m1, mat<4, 1, T, Q> const& m2)
	{
		return mat<4, 1, T, Q>(
			m1[0] + m2[0],
			m1[1] + m2[1],
			m1[2] + m2[2],
			m1[3] + m2[3]);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q> operator-(mat<4, 1, T, Q> const& m, T scalar)
	{
		return mat<4, 1, T, Q>(
			m[0] - scalar,
			m[1] - scalar,
			m[2] - scalar,
			m[3] - scalar);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q> operator-(T scalar, mat<4, 1, T, Q> const& m)
	{
		return mat<4, 1, T, Q>(
			scalar - m[0],
			scalar - m[1],
			scalar - m[2],
			scalar - m[3]);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q> operator-(mat<4, 1, T, Q> const& m1, mat<4, 1, T, Q> const& m2)
	{
		return mat<4, 1, T, Q>(
			m1[0] - m2[0],
			m1[1] - m2[1],
			m1[2] - m2[2],
			m1[3] - m2[3]);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q> operator*(mat<4, 1, T, Q> const& m, T scalar)
	{
		return mat<4, 1, T, Q>(
			m[0] * scalar,
			m[1] * scalar,
			m[2] * scalar,
			m[3] * scalar);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q> operator*(T scalar, mat<4, 1, T, Q> const& m)
	{
		return mat<4, 1, T, Q>(
			m[0] * scalar,
			m[1] * scalar,
			m[2] * scalar,
			m[3] * scalar);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR typename mat<4, 1, T, Q>::col_type operator*
	(
		mat<4, 1, T, Q> const& m,
		typename mat<4, 1, T, Q>::row_type const& v
	)
	{
		return vec<1, T, Q>(
			m[0][0] * v.x + m[1][0] * v.y + m[2][0] * v.z + m[3][0] * v.w);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR typename mat<4, 1, T, Q>::row_type operator*
	(
		typename mat<4, 1, T, Q>::col_type const& v,
		mat<4, 1, T, Q> const& m
	)
	{
		return vec<4, T, Q>(
			v.x * m[0][0],
			v.x * m[1][0],
			v.x * m[2][0],
			v.x * m[3][0]);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 1, T, Q> operator*(mat<4, 1, T, Q> const& m1, mat<1, 4, T, Q> const& m2)
	{
		return mat<1, 1, T, Q>(
			m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2] + m1[3][0] * m2[0][3]);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<2, 1, T, Q> operator*(mat<4, 1, T, Q> const& m1, mat<2, 4, T, Q> const& m2)
	{
		return mat<2, 1, T, Q>(
			m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2] + m1[3][0] * m2[0][3],
			m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2] + m1[3][0] * m2[1][3]);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q> operator*(mat<4, 1, T, Q> const& m1, mat<3, 4, T, Q> const& m2)
	{
		return mat<3, 1, T, Q>(
			m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2] + m1[3][0] * m2[0][3],
			m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2] + m1[3][0] * m2[1][3],
			m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1] + m1[2][0] * m2[2][2] + m1[3][0] * m2[2][3]);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q> operator*(mat<4, 1, T, Q> const& m1, mat<4, 4, T, Q> const& m2)
	{
		return mat<4, 1, T, Q>(
			m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2] + m1[3][0] * m2[0][3],
			m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2] + m1[3][0] * m2[1][3],
			m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1] + m1[2][0] * m2[2][2] + m1[3][0] * m2[2][3],
			m1[0][0] * m2[3][0] + m1[1][0] * m2[3][1] + m1[2][0] * m2[3][2] + m1[3][0] * m2[3][3]);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q> operator/(mat<4, 1, T, Q> const& m, T scalar)
	{
		return mat<4, 1, T, Q>(
			m[0] / scalar,
			m[1] / scalar,
			m[2] / scalar,
			m[3] / scalar);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q> operator/(T scalar, mat<4, 1, T, Q> const& m)
	{
		return mat<4, 1, T, Q>(
			scalar / m[0],
			scalar / m[1],
			scalar / m[2],
			scalar / m[3]);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR typename mat<4, 1, T, Q>::col_type operator/(mat<4, 1, T, Q> const& m, typename mat<4, 1, T, Q>::row_type const& v)
	{
		return inverse(m) * v;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR typename mat<4, 1, T, Q>::row_type operator/(typename mat<4, 1, T, Q>::col_type const& v, mat<4, 1, T, Q> const& m)
	{
		return v *  inverse(m);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 1, T, Q> operator/(mat<4, 1, T, Q> const& m1, mat<4, 1, T, Q> const& m2)
	{
		mat<4, 1, T, Q> m1_copy(m1);
		return m1_copy /= m2;
	}

	// -- Boolean operators --

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR bool operator==(mat<4, 1, T, Q> const& m1, mat<4, 1, T, Q> const& m2)
	{
		return (m1[0] == m2[0]) && (m1[1] == m2[1]) && (m1[2] == m2[2]) && (m1[3] == m2[3]);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR bool operator!=(mat<4, 1, T, Q> const& m1, mat<4, 1, T, Q> const& m2)
	{
		return (m1[0] != m2[0]) || (m1[1] != m2[1]) || (m1[2] != m2[2]) || (m1[3] != m2[3]);
	}
} //namespace glm
