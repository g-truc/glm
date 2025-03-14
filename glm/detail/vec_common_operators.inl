namespace glm {
template<length_t L,typename T,qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L,T,Q> operator++(vec<L,T,Q>& v,int) {{
    const vec<L,T,Q> Result(v);
    ++v;
    return Result;
}}
template<length_t L,typename T,qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L,T,Q> operator--(vec<L,T,Q>& v,int) {
    const vec<L,T,Q> Result(v);
    --v;
    return Result;
}
template<length_t L,typename T,qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L,T,Q> operator+(vec<L,T,Q> const& v) {
    return v;
}
template<length_t L,typename T,qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR bool operator!=(vec<L,T,Q> const& a,vec<L,T,Q> const& b) {
    return !(a == b);
}

template<length_t L, typename T, qualifier Q,typename U,qualifier P>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q>& operator+=(vec<L, T, Q>& a, vec<1,U,P> const& b) {
    return a += b.x;
}
template<length_t L, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator+(vec<L, T, Q> const& a, vec<1,T,Q> const& b) {
    return a + b.x;
}
template<length_t L, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator+(vec<1, T, Q> const& a, vec<L,T,Q> const& b) {
    return a.x + b;
}

template<length_t L, typename T, qualifier Q,typename U,qualifier P>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q>& operator-=(vec<L, T, Q>& a, vec<1,U,P> const& b) {
    return a -= b.x;
}
template<length_t L, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator-(vec<L, T, Q> const& a, vec<1,T,Q> const& b) {
    return a - b.x;
}
template<length_t L, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator-(vec<1, T, Q> const& a, vec<L,T,Q> const& b) {
    return a.x - b;
}

template<length_t L, typename T, qualifier Q,typename U,qualifier P>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q>& operator*=(vec<L, T, Q>& a, vec<1,U,P> const& b) {
    return a *= b.x;
}
template<length_t L, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator*(vec<L, T, Q> const& a, vec<1,T,Q> const& b) {
    return a * b.x;
}
template<length_t L, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator*(vec<1, T, Q> const& a, vec<L,T,Q> const& b) {
    return a.x * b;
}

template<length_t L, typename T, qualifier Q,typename U,qualifier P>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q>& operator/=(vec<L, T, Q>& a, vec<1,U,P> const& b) {
    return a /= b.x;
}
template<length_t L, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator/(vec<L, T, Q> const& a, vec<1,T,Q> const& b) {
    return a / b.x;
}
template<length_t L, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator/(vec<1, T, Q> const& a, vec<L,T,Q> const& b) {
    return a.x / b;
}

template<length_t L, typename T, qualifier Q,typename U,qualifier P>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q>& operator%=(vec<L, T, Q>& a, vec<1,U,P> const& b) {
    return a %= b.x;
}
template<length_t L, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator%(vec<L, T, Q> const& a, vec<1,T,Q> const& b) {
    return a % b.x;
}
template<length_t L, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator%(vec<1, T, Q> const& a, vec<L,T,Q> const& b) {
    return a.x % b;
}

template<length_t L, typename T, qualifier Q,typename U,qualifier P>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q>& operator&=(vec<L, T, Q>& a, vec<1,U,P> const& b) {
    return a &= b.x;
}
template<length_t L, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator&(vec<L, T, Q> const& a, vec<1,T,Q> const& b) {
    return a & b.x;
}
template<length_t L, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator&(vec<1, T, Q> const& a, vec<L,T,Q> const& b) {
    return a.x & b;
}

template<length_t L, typename T, qualifier Q,typename U,qualifier P>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q>& operator|=(vec<L, T, Q>& a, vec<1,U,P> const& b) {
    return a |= b.x;
}
template<length_t L, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator|(vec<L, T, Q> const& a, vec<1,T,Q> const& b) {
    return a | b.x;
}
template<length_t L, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator|(vec<1, T, Q> const& a, vec<L,T,Q> const& b) {
    return a.x | b;
}

template<length_t L, typename T, qualifier Q,typename U,qualifier P>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q>& operator^=(vec<L, T, Q>& a, vec<1,U,P> const& b) {
    return a ^= b.x;
}
template<length_t L, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator^(vec<L, T, Q> const& a, vec<1,T,Q> const& b) {
    return a ^ b.x;
}
template<length_t L, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator^(vec<1, T, Q> const& a, vec<L,T,Q> const& b) {
    return a.x ^ b;
}

template<length_t L, typename T, qualifier Q,typename U,qualifier P>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q>& operator<<=(vec<L, T, Q>& a, vec<1,U,P> const& b) {
    return a <<= b.x;
}
template<length_t L, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator<<(vec<L, T, Q> const& a, vec<1,T,Q> const& b) {
    return a << b.x;
}
template<length_t L, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator<<(vec<1, T, Q> const& a, vec<L,T,Q> const& b) {
    return a.x << b;
}

template<length_t L, typename T, qualifier Q,typename U,qualifier P>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q>& operator>>=(vec<L, T, Q>& a, vec<1,U,P> const& b) {
    return a >>= b.x;
}
template<length_t L, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator>>(vec<L, T, Q> const& a, vec<1,T,Q> const& b) {
    return a >> b.x;
}
template<length_t L, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator>>(vec<1, T, Q> const& a, vec<L,T,Q> const& b) {
    return a.x >> b;
}

template<length_t L, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator+(T scalar,vec<L, T, Q> const& v) {
    return v + scalar;
}
template<length_t L, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator*(T scalar,vec<L, T, Q> const& v) {
    return v * scalar;
}
template<length_t L, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator&(T scalar,vec<L, T, Q> const& v) {
    return v & scalar;
}
template<length_t L, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator|(T scalar,vec<L, T, Q> const& v) {
    return v | scalar;
}
template<length_t L, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator^(T scalar,vec<L, T, Q> const& v) {
    return v ^ scalar;
}
} // namespace glm
