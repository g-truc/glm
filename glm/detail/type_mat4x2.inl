namespace glm
{
	// -- Constructors --

#	if GLM_CONFIG_CTOR_INIT == GLM_ENABLE
		template<typename T, qualifier Q>
		GLM_DEFAULTED_DEFAULT_CTOR_QUALIFIER GLM_CONSTEXPR mat<4, 2, T, Q>::mat()
			: value{col_type(1, 0), col_type(0, 1), col_type(0, 0), col_type(0, 0)}
		{}
#	endif

	template<typename T, qualifier Q>
	template<qualifier P>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 2, T, Q>::mat(mat<4, 2, T, P> const& m)
		: value{col_type(m[0]), col_type(m[1]), col_type(m[2]), col_type(m[3])}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 2, T, Q>::mat(T s)
		: value{col_type(s, 0), col_type(0, s), col_type(0, 0), col_type(0, 0)}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 2, T, Q>::mat
	(
		T x0, T y0,
		T x1, T y1,
		T x2, T y2,
		T x3, T y3
	)
		: value{col_type(x0, y0), col_type(x1, y1), col_type(x2, y2), col_type(x3, y3)}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 2, T, Q>::mat(col_type const& v0, col_type const& v1, col_type const& v2, col_type const& v3)
		: value{col_type(v0), col_type(v1), col_type(v2), col_type(v3)}
	{}

	// -- Conversion constructors --

	template<typename T, qualifier Q>
	template<
		typename X0, typename Y0,
		typename X1, typename Y1,
		typename X2, typename Y2,
		typename X3, typename Y3>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 2, T, Q>::mat
	(
		X0 x0, Y0 y0,
		X1 x1, Y1 y1,
		X2 x2, Y2 y2,
		X3 x3, Y3 y3
	)
		: value{col_type(x0, y0), col_type(x1, y1), col_type(x2, y2), col_type(x3, y3)}
	{}

	template<typename T, qualifier Q>
	template<typename V0, typename V1, typename V2, typename V3>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 2, T, Q>::mat(vec<2, V0, Q> const& v0, vec<2, V1, Q> const& v1, vec<2, V2, Q> const& v2, vec<2, V3, Q> const& v3)
		: value{col_type(v0), col_type(v1), col_type(v2), col_type(v3)}
	{}

	// -- Conversion --

	template<typename T, qualifier Q>
	template<typename U, qualifier P>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 2, T, Q>::mat(mat<4, 2, U, P> const& m)
		: value{col_type(m[0]), col_type(m[1]), col_type(m[2]), col_type(m[3])}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 2, T, Q>::mat(mat<2, 2, T, Q> const& m)
		: value{col_type(m[0]), col_type(m[1]), col_type(0), col_type(0)}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 2, T, Q>::mat(mat<3, 3, T, Q> const& m)
		: value{col_type(m[0]), col_type(m[1]), col_type(m[2]), col_type(0)}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 2, T, Q>::mat(mat<4, 4, T, Q> const& m)
		: value{col_type(m[0]), col_type(m[1]), col_type(m[2]), col_type(m[3])}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 2, T, Q>::mat(mat<2, 3, T, Q> const& m)
		: value{col_type(m[0]), col_type(m[1]), col_type(0), col_type(0)}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 2, T, Q>::mat(mat<3, 2, T, Q> const& m)
		: value{col_type(m[0]), col_type(m[1]), col_type(m[2]), col_type(0)}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 2, T, Q>::mat(mat<2, 4, T, Q> const& m)
		: value{col_type(m[0]), col_type(m[1]), col_type(0), col_type(0)}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 2, T, Q>::mat(mat<4, 3, T, Q> const& m)
		: value{col_type(m[0]), col_type(m[1]), col_type(m[2]), col_type(m[3])}
	{}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 2, T, Q>::mat(mat<3, 4, T, Q> const& m)
		: value{col_type(m[0]), col_type(m[1]), col_type(m[2]), col_type(0)}
	{}

	// -- Accesses --

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR typename mat<4, 2, T, Q>::col_type & mat<4, 2, T, Q>::operator[](typename mat<4, 2, T, Q>::length_type i) noexcept
	{
		GLM_ASSERT_LENGTH(i, this->length());
		return this->value[i];
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR typename mat<4, 2, T, Q>::col_type const& mat<4, 2, T, Q>::operator[](typename mat<4, 2, T, Q>::length_type i) const noexcept
	{
		GLM_ASSERT_LENGTH(i, this->length());
		return this->value[i];
	}

	// -- Unary updatable operators --

	template<typename T, qualifier Q>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 2, T, Q>& mat<4, 2, T, Q>::operator=(mat<4, 2, U, Q> const& m)
	{
		this->value[0] = m[0];
		this->value[1] = m[1];
		this->value[2] = m[2];
		this->value[3] = m[3];
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 2, T, Q> & mat<4, 2, T, Q>::operator+=(U s)
	{
		this->value[0] += s;
		this->value[1] += s;
		this->value[2] += s;
		this->value[3] += s;
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 2, T, Q> & mat<4, 2, T, Q>::operator+=(mat<4, 2, U, Q> const& m)
	{
		this->value[0] += m[0];
		this->value[1] += m[1];
		this->value[2] += m[2];
		this->value[3] += m[3];
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 2, T, Q> & mat<4, 2, T, Q>::operator-=(U s)
	{
		this->value[0] -= s;
		this->value[1] -= s;
		this->value[2] -= s;
		this->value[3] -= s;
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 2, T, Q> & mat<4, 2, T, Q>::operator-=(mat<4, 2, U, Q> const& m)
	{
		this->value[0] -= m[0];
		this->value[1] -= m[1];
		this->value[2] -= m[2];
		this->value[3] -= m[3];
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 2, T, Q> & mat<4, 2, T, Q>::operator*=(U s)
	{
		this->value[0] *= s;
		this->value[1] *= s;
		this->value[2] *= s;
		this->value[3] *= s;
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 2, T, Q> & mat<4, 2, T, Q>::operator/=(U s)
	{
		this->value[0] /= s;
		this->value[1] /= s;
		this->value[2] /= s;
		this->value[3] /= s;
		return *this;
	}

	// -- Increment and decrement operators --

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 2, T, Q> & mat<4, 2, T, Q>::operator++()
	{
		++this->value[0];
		++this->value[1];
		++this->value[2];
		++this->value[3];
		return *this;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 2, T, Q> & mat<4, 2, T, Q>::operator--()
	{
		--this->value[0];
		--this->value[1];
		--this->value[2];
		--this->value[3];
		return *this;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 2, T, Q> mat<4, 2, T, Q>::operator++(int)
	{
		mat<4, 2, T, Q> Result(*this);
		++*this;
		return Result;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 2, T, Q> mat<4, 2, T, Q>::operator--(int)
	{
		mat<4, 2, T, Q> Result(*this);
		--*this;
		return Result;
	}

	// -- Unary arithmetic operators --

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 2, T, Q> operator+(mat<4, 2, T, Q> const& m)
	{
		return m;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 2, T, Q> operator-(mat<4, 2, T, Q> const& m)
	{
		return mat<4, 2, T, Q>(
			-m[0],
			-m[1],
			-m[2],
			-m[3]);
	}

	// -- Binary arithmetic operators --

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 2, T, Q> operator+(mat<4, 2, T, Q> const& m, T scalar)
	{
		return mat<4, 2, T, Q>(
			m[0] + scalar,
			m[1] + scalar,
			m[2] + scalar,
			m[3] + scalar);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 2, T, Q> operator+(mat<4, 2, T, Q> const& m1, mat<4, 2, T, Q> const& m2)
	{
		return mat<4, 2, T, Q>(
			m1[0] + m2[0],
			m1[1] + m2[1],
			m1[2] + m2[2],
			m1[3] + m2[3]);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 2, T, Q> operator-(mat<4, 2, T, Q> const& m, T scalar)
	{
		return mat<4, 2, T, Q>(
			m[0] - scalar,
			m[1] - scalar,
			m[2] - scalar,
			m[3] - scalar);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 2, T, Q> operator-(mat<4, 2, T, Q> const& m1, mat<4, 2, T, Q> const& m2)
	{
		return mat<4, 2, T, Q>(
			m1[0] - m2[0],
			m1[1] - m2[1],
			m1[2] - m2[2],
			m1[3] - m2[3]);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 2, T, Q> operator*(mat<4, 2, T, Q> const& m, T scalar)
	{
		return mat<4, 2, T, Q>(
			m[0] * scalar,
			m[1] * scalar,
			m[2] * scalar,
			m[3] * scalar);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 2, T, Q> operator*(T scalar, mat<4, 2, T, Q> const& m)
	{
		return mat<4, 2, T, Q>(
			m[0] * scalar,
			m[1] * scalar,
			m[2] * scalar,
			m[3] * scalar);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR typename mat<4, 2, T, Q>::col_type operator*(mat<4, 2, T, Q> const& m, typename mat<4, 2, T, Q>::row_type const& v)
	{
		return typename mat<4, 2, T, Q>::col_type(
			m[0][0] * v.x + m[1][0] * v.y + m[2][0] * v.z + m[3][0] * v.w,
			m[0][1] * v.x + m[1][1] * v.y + m[2][1] * v.z + m[3][1] * v.w);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR typename mat<4, 2, T, Q>::row_type operator*(typename mat<4, 2, T, Q>::col_type const& v, mat<4, 2, T, Q> const& m)
	{
		return typename mat<4, 2, T, Q>::row_type(
			v.x * m[0][0] + v.y * m[0][1],
			v.x * m[1][0] + v.y * m[1][1],
			v.x * m[2][0] + v.y * m[2][1],
			v.x * m[3][0] + v.y * m[3][1]);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<2, 2, T, Q> operator*(mat<4, 2, T, Q> const& m1, mat<2, 4, T, Q> const& m2)
	{
		return mat<2, 2, T, Q>(
			m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2] + m1[3][0] * m2[0][3],
			m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2] + m1[3][1] * m2[0][3],
			m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2] + m1[3][0] * m2[1][3],
			m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2] + m1[3][1] * m2[1][3]);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<3, 2, T, Q> operator*(mat<4, 2, T, Q> const& m1, mat<3, 4, T, Q> const& m2)
	{
		return mat<3, 2, T, Q>(
			m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2] + m1[3][0] * m2[0][3],
			m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2] + m1[3][1] * m2[0][3],
			m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2] + m1[3][0] * m2[1][3],
			m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2] + m1[3][1] * m2[1][3],
			m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1] + m1[2][0] * m2[2][2] + m1[3][0] * m2[2][3],
			m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1] + m1[2][1] * m2[2][2] + m1[3][1] * m2[2][3]);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 2, T, Q> operator*(mat<4, 2, T, Q> const& m1, mat<4, 4, T, Q> const& m2)
	{
		return mat<4, 2, T, Q>(
			m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2] + m1[3][0] * m2[0][3],
			m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2] + m1[3][1] * m2[0][3],
			m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2] + m1[3][0] * m2[1][3],
			m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2] + m1[3][1] * m2[1][3],
			m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1] + m1[2][0] * m2[2][2] + m1[3][0] * m2[2][3],
			m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1] + m1[2][1] * m2[2][2] + m1[3][1] * m2[2][3],
			m1[0][0] * m2[3][0] + m1[1][0] * m2[3][1] + m1[2][0] * m2[3][2] + m1[3][0] * m2[3][3],
			m1[0][1] * m2[3][0] + m1[1][1] * m2[3][1] + m1[2][1] * m2[3][2] + m1[3][1] * m2[3][3]);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 2, T, Q> operator/(mat<4, 2, T, Q> const& m, T scalar)
	{
		return mat<4, 2, T, Q>(
			m[0] / scalar,
			m[1] / scalar,
			m[2] / scalar,
			m[3] / scalar);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4, 2, T, Q> operator/(T scalar, mat<4, 2, T, Q> const& m)
	{
		return mat<4, 2, T, Q>(
			scalar / m[0],
			scalar / m[1],
			scalar / m[2],
			scalar / m[3]);
	}

	// -- Boolean operators --

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR bool operator==(mat<4, 2, T, Q> const& m1, mat<4, 2, T, Q> const& m2)
	{
		return (m1[0] == m2[0]) && (m1[1] == m2[1]) && (m1[2] == m2[2]) && (m1[3] == m2[3]);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR bool operator!=(mat<4, 2, T, Q> const& m1, mat<4, 2, T, Q> const& m2)
	{
		return (m1[0] != m2[0]) || (m1[1] != m2[1]) || (m1[2] != m2[2]) || (m1[3] != m2[3]);
	}
} //namespace glm
