
namespace glm {


template<length_t R, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4,R,T,Q> operator-(mat<4,R,T,Q> const& m) {
    return mat<4,R,T,Q>(-m[0],-m[1],-m[2],-m[3]);
}

template<length_t R, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4,R,T,Q>& operator++(mat<4,R,T,Q>& m) {
    ++m[0];
    ++m[1];
    ++m[2];
    ++m[3];
    return m;
}

template<length_t R, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4,R,T,Q>& operator--(mat<4,R,T,Q>& m) {
    --m[0];
    --m[1];
    --m[2];
    --m[3];
    return m;
}

template<length_t R, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR bool operator==(mat<4,R,T,Q> const& m1, mat<4,R,T,Q> const& m2) {
    return (m1[0] == m2[0]) && (m1[1] == m2[1]) && (m1[2] == m2[2]) && (m1[3] == m2[3]);
}

template<length_t R, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4,R,T,Q> operator+(mat<4,R,T,Q> const& m1, mat<4,R,T,Q> const& m2) {
    return mat<4,R,T,Q>(m1[0] + m2[0],m1[1] + m2[1],m1[2] + m2[2],m1[3] + m2[3]);
}
template<length_t R, typename T, qualifier Q,typename U>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4,R,T,Q>& operator+=(mat<4,R,T,Q>& m1, mat<4,R,U,Q> const& m2) {
    m1[0] += m2[0];
    m1[1] += m2[1];
    m1[2] += m2[2];
    m1[3] += m2[3];
    return m1;
}

template<length_t R, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4,R,T,Q> operator-(mat<4,R,T,Q> const& m1, mat<4,R,T,Q> const& m2) {
    return mat<4,R,T,Q>(m1[0] - m2[0],m1[1] - m2[1],m1[2] - m2[2],m1[3] - m2[3]);
}
template<length_t R, typename T, qualifier Q,typename U>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4,R,T,Q>& operator-=(mat<4,R,T,Q>& m1, mat<4,R,U,Q> const& m2) {
    m1[0] -= m2[0];
    m1[1] -= m2[1];
    m1[2] -= m2[2];
    m1[3] -= m2[3];
    return m1;
}

template<length_t R, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4,R, T, Q> operator+(mat<4,R, T, Q> const& m, T scalar) {
    return mat<4,R,T,Q>(m[0] + scalar,m[1] + scalar,m[2] + scalar,m[3] + scalar);
}
template<length_t R, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4,R, T, Q> operator+(T scalar,mat<4,R, T, Q> const& m) {
    return mat<4,R,T,Q>(scalar + m[0],scalar + m[1],scalar + m[2],scalar + m[3]);
}
template<length_t R, typename T, qualifier Q,typename U>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4,R,T,Q>& operator+=(mat<4,R,T,Q>& m, U scalar) {
    m[0] += scalar;
    m[1] += scalar;
    m[2] += scalar;
    m[3] += scalar;
    return m;
}

template<length_t R, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4,R, T, Q> operator-(mat<4,R, T, Q> const& m, T scalar) {
    return mat<4,R,T,Q>(m[0] - scalar,m[1] - scalar,m[2] - scalar,m[3] - scalar);
}
template<length_t R, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4,R, T, Q> operator-(T scalar,mat<4,R, T, Q> const& m) {
    return mat<4,R,T,Q>(scalar - m[0],scalar - m[1],scalar - m[2],scalar - m[3]);
}
template<length_t R, typename T, qualifier Q,typename U>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4,R,T,Q>& operator-=(mat<4,R,T,Q>& m, U scalar) {
    m[0] -= scalar;
    m[1] -= scalar;
    m[2] -= scalar;
    m[3] -= scalar;
    return m;
}

template<length_t R, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4,R, T, Q> operator*(mat<4,R, T, Q> const& m, T scalar) {
    return mat<4,R,T,Q>(m[0] * scalar,m[1] * scalar,m[2] * scalar,m[3] * scalar);
}
template<length_t R, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4,R, T, Q> operator*(T scalar,mat<4,R, T, Q> const& m) {
    return mat<4,R,T,Q>(scalar * m[0],scalar * m[1],scalar * m[2],scalar * m[3]);
}
template<length_t R, typename T, qualifier Q,typename U>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4,R,T,Q>& operator*=(mat<4,R,T,Q>& m, U scalar) {
    m[0] *= scalar;
    m[1] *= scalar;
    m[2] *= scalar;
    m[3] *= scalar;
    return m;
}

template<length_t R, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4,R, T, Q> operator/(mat<4,R, T, Q> const& m, T scalar) {
    return mat<4,R,T,Q>(m[0] / scalar,m[1] / scalar,m[2] / scalar,m[3] / scalar);
}
template<length_t R, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4,R, T, Q> operator/(T scalar,mat<4,R, T, Q> const& m) {
    return mat<4,R,T,Q>(scalar / m[0],scalar / m[1],scalar / m[2],scalar / m[3]);
}
template<length_t R, typename T, qualifier Q,typename U>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<4,R,T,Q>& operator/=(mat<4,R,T,Q>& m, U scalar) {
    m[0] /= scalar;
    m[1] /= scalar;
    m[2] /= scalar;
    m[3] /= scalar;
    return m;
}

}

