#include "../matrix.hpp"

namespace glm
{
	// -- Constructors --

#	if GLM_CONFIG_CTOR_INIT == GLM_ENABLE
		template<typename T, qualifier Q>
		GLM_DEFAULTED_DEFAULT_CTOR_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q>::mat()
			: value{col_type(1, 0), col_type(0, 1)}
		{}
#	endif

	template<typename T, qualifier Q>
	template<qualifier P>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q>::mat(mat<1, 4, T, P> const& m)
		: value{col_type(m[0])}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q>::mat(T scalar)
		: value{col_type(scalar, 0, 0)}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q>::mat
	(
		T const& x0, T const& y0, T const& z0, T const& w0
	)
		: value{col_type(x0, y0, z0, w0)}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q>::mat(col_type const& v0)
		: value{v0}
	{}

	// -- Conversion constructors --

	template<typename T, qualifier Q>
	template<typename X1, typename Y1, typename Z1, typename W1>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q>::mat
	(
		X1 const& x1, Y1 const& y1, Z1 const& z1, W1 const& w1
	)
		: value{col_type(static_cast<T>(x1), value_type(y1), value_type(z1), value_type(w1)) }
	{}

	template<typename T, qualifier Q>
	template<typename V1>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q>::mat(vec<4, V1, Q> const& v1)
		: value{col_type(v1)}
	{}

	// -- mat1x4 matrix conversions --

	template<typename T, qualifier Q>
	template<typename U, qualifier P>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q>::mat(mat<1, 4, U, P> const& m)
		: value{col_type(m[0]), col_type(m[1])}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q>::mat(mat<1, 1, T, Q> const& m)
		: value{col_type(m[0], 0, 0, 0)}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q>::mat(mat<2, 2, T, Q> const& m)
		: value{col_type(m[0], 0, 0, 0)}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q>::mat(mat<3, 3, T, Q> const& m)
		: value{col_type(m[0])}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q>::mat(mat<4, 4, T, Q> const& m)
		: value{col_type(m[0])}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q>::mat(mat<1, 2, T, Q> const& m)
		: value{col_type(m[0], 0, 0)}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q>::mat(mat<2, 1, T, Q> const& m)
		: value{col_type(m[0], 0, 0, 0)}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q>::mat(mat<1, 3, T, Q> const& m)
		: value{col_type(m[0], 0)}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q>::mat(mat<3, 1, T, Q> const& m)
		: value{col_type(m[0], 0, 0, 0)}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q>::mat(mat<4, 1, T, Q> const& m)
		: value{col_type(m[0], 0, 0, 0)}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q>::mat(mat<2, 3, T, Q> const& m)
		: value{col_type(m[0], 0)}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q>::mat(mat<3, 2, T, Q> const& m)
		: value{col_type(m[0], 0, 0)}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q>::mat(mat<2, 4, T, Q> const& m)
		: value{col_type(m[0])}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q>::mat(mat<4, 2, T, Q> const& m)
		: value{col_type(m[0], 0, 0)}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q>::mat(mat<3, 4, T, Q> const& m)
		: value{col_type(m[0])}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q>::mat(mat<4, 3, T, Q> const& m)
		: value{col_type(m[0], 0)}
	{}

	// -- Accesses --

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR typename mat<1, 4, T, Q>::col_type& mat<1, 4, T, Q>::operator[](typename mat<1, 4, T, Q>::length_type i) noexcept
	{
		GLM_ASSERT_LENGTH(i, this->length());
		return this->value[i];
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR typename mat<1, 4, T, Q>::col_type const& mat<1, 4, T, Q>::operator[](typename mat<1, 4, T, Q>::length_type i) const noexcept
	{
		GLM_ASSERT_LENGTH(i, this->length());
		return this->value[i];
	}

	// -- Unary updatable operators --

	template<typename T, qualifier Q>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q>& mat<1, 4, T, Q>::operator=(mat<1, 4, U, Q> const& m)
	{
		this->value[0] = m[0];
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q>& mat<1, 4, T, Q>::operator+=(U scalar)
	{
		this->value[0] += scalar;
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q>& mat<1, 4, T, Q>::operator+=(mat<1, 4, U, Q> const& m)
	{
		this->value[0] += m[0];
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q>& mat<1, 4, T, Q>::operator-=(U scalar)
	{
		this->value[0] -= scalar;
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q>& mat<1, 4, T, Q>::operator-=(mat<1, 4, U, Q> const& m)
	{
		this->value[0] -= m[0];
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q>& mat<1, 4, T, Q>::operator*=(U scalar)
	{
		this->value[0] *= scalar;
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q>& mat<1, 4, T, Q>::operator*=(mat<1, 4, U, Q> const& m)
	{
		return (*this = *this * m);
	}

	template<typename T, qualifier Q>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q>& mat<1, 4, T, Q>::operator/=(U scalar)
	{
		this->value[0] /= scalar;
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q>& mat<1, 4, T, Q>::operator/=(mat<1, 4, U, Q> const& m)
	{
		return *this *= inverse(m);
	}

	// -- Increment and decrement operators --

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q>& mat<1, 4, T, Q>::operator++()
	{
		++this->value[0];
		return *this;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q>& mat<1, 4, T, Q>::operator--()
	{
		--this->value[0];
		return *this;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q> mat<1, 4, T, Q>::operator++(int)
	{
		mat<1, 4, T, Q> Result(*this);
		++*this;
		return Result;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q> mat<1, 4, T, Q>::operator--(int)
	{
		mat<1, 4, T, Q> Result(*this);
		--*this;
		return Result;
	}

	// -- Unary arithmetic operators --

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q> operator+(mat<1, 4, T, Q> const& m)
	{
		return m;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q> operator-(mat<1, 4, T, Q> const& m)
	{
		return mat<1, 4, T, Q>(
			-m[0]);
	}

	// -- Binary arithmetic operators --

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q> operator+(mat<1, 4, T, Q> const& m, T scalar)
	{
		return mat<1, 4, T, Q>(
			m[0] + scalar);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q> operator+(T scalar, mat<1, 4, T, Q> const& m)
	{
		return mat<1, 4, T, Q>(
			m[0] + scalar);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q> operator+(mat<1, 4, T, Q> const& m1, mat<1, 4, T, Q> const& m2)
	{
		return mat<1, 4, T, Q>(
			m1[0] + m2[0]);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q> operator-(mat<1, 4, T, Q> const& m, T scalar)
	{
		return mat<1, 4, T, Q>(
			m[0] - scalar);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q> operator-(T scalar, mat<1, 4, T, Q> const& m)
	{
		return mat<1, 4, T, Q>(
			scalar - m[0]);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q> operator-(mat<1, 4, T, Q> const& m1, mat<1, 4, T, Q> const& m2)
	{
		return mat<1, 4, T, Q>(
			m1[0] - m2[0]);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q> operator*(mat<1, 4, T, Q> const& m, T scalar)
	{
		return mat<1, 4, T, Q>(
			m[0] * scalar);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q> operator*(T scalar, mat<1, 4, T, Q> const& m)
	{
		return mat<1, 4, T, Q>(
			m[0] * scalar);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR typename mat<1, 4, T, Q>::col_type operator*
	(
		mat<1, 4, T, Q> const& m,
		typename mat<1, 4, T, Q>::row_type const& v
	)
	{
		return vec<4, T, Q>(
			m[0][0] * v.x,
			m[0][1] * v.x,
			m[0][2] * v.x,
			m[0][3] * v.x);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR typename mat<1, 4, T, Q>::row_type operator*
	(
		typename mat<1, 4, T, Q>::col_type const& v,
		mat<1, 4, T, Q> const& m
	)
	{
		return vec<1, T, Q>(
			v.x * m[0][0] + v.y * m[0][1] + v.z * m[0][2] + v.w * m[0][3]);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q> operator*(mat<1, 4, T, Q> const& m1, mat<1, 1, T, Q> const& m2)
	{
		return mat<1, 4, T, Q>(
			m1[0][0] * m2[0][0],
			m1[0][1] * m2[0][0],
			m1[0][2] * m2[0][0],
			m1[0][3] * m2[0][0]);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<2, 4, T, Q> operator*(mat<1, 4, T, Q> const& m1, mat<2, 1, T, Q> const& m2)
	{
		return mat<2, 4, T, Q>(
			m1[0][0] * m2[0][0],
			m1[0][1] * m2[0][0],
			m1[0][2] * m2[0][0],
			m1[0][3] * m2[0][0],
			m1[0][0] * m2[1][0],
			m1[0][1] * m2[1][0],
			m1[0][2] * m2[1][0],
			m1[0][3] * m2[1][0],);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<3, 4, T, Q> operator*(mat<1, 4, T, Q> const& m1, mat<3, 1, T, Q> const& m2)
	{
		return mat<3, 4, T, Q>(
			m1[0][0] * m2[0][0],
			m1[0][1] * m2[0][0],
			m1[0][2] * m2[0][0],
			m1[0][3] * m2[0][0],
			m1[0][0] * m2[1][0],
			m1[0][1] * m2[1][0],
			m1[0][2] * m2[1][0],
			m1[0][3] * m2[1][0],
			m1[0][0] * m2[2][0],
			m1[0][1] * m2[2][0],
			m1[0][2] * m2[2][0],
			m1[0][3] * m2[2][0]);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 4, T, Q> operator*(mat<1, 4, T, Q> const& m1, mat<4, 1, T, Q> const& m2)
	{
		return mat<4, 4, T, Q>(
			m1[0][0] * m2[0][0],
			m1[0][1] * m2[0][0],
			m1[0][2] * m2[0][0],
			m1[0][3] * m2[0][0],
			m1[0][0] * m2[1][0],
			m1[0][1] * m2[1][0],
			m1[0][2] * m2[1][0],
			m1[0][3] * m2[1][0],
			m1[0][0] * m2[2][0],
			m1[0][1] * m2[2][0],
			m1[0][2] * m2[2][0],
			m1[0][3] * m2[2][0],
			m1[0][0] * m2[3][0],
			m1[0][1] * m2[3][0],
			m1[0][2] * m2[3][0],
			m1[0][3] * m2[3][0]);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q> operator/(mat<1, 4, T, Q> const& m, T scalar)
	{
		return mat<1, 4, T, Q>(
			m[0] / scalar);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q> operator/(T scalar, mat<1, 4, T, Q> const& m)
	{
		return mat<1, 4, T, Q>(
			scalar / m[0]);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR typename mat<1, 4, T, Q>::col_type operator/(mat<1, 4, T, Q> const& m, typename mat<1, 4, T, Q>::row_type const& v)
	{
		return inverse(m) * v;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR typename mat<1, 4, T, Q>::row_type operator/(typename mat<1, 4, T, Q>::col_type const& v, mat<1, 4, T, Q> const& m)
	{
		return v *  inverse(m);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<1, 4, T, Q> operator/(mat<1, 4, T, Q> const& m1, mat<1, 4, T, Q> const& m2)
	{
		mat<1, 4, T, Q> m1_copy(m1);
		return m1_copy /= m2;
	}

	// -- Boolean operators --

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR bool operator==(mat<1, 4, T, Q> const& m1, mat<1, 4, T, Q> const& m2)
	{
		return (m1[0] == m2[0]);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR bool operator!=(mat<1, 4, T, Q> const& m1, mat<1, 4, T, Q> const& m2)
	{
		return (m1[0] != m2[0]);
	}
} //namespace glm
