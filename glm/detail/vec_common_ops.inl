#include "qualifier.hpp"

namespace glm {


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator+(vec<L, T, Q> const& v) {
		return v;
	}

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator++(vec<L, T, Q>& v, int) {
		vec<L, T, Q> Result(v);
		++v;
		return Result;
	}

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator--(vec<L, T, Q>& v, int) {
		vec<L, T, Q> Result(v);
		--v;
		return Result;
	}

	template<length_t L, typename T, qualifier Q, typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q>& operator+=(vec<L, T, Q>& v1, U scalar) {
		return v1 += vec<L, T, Q>(static_cast<T>(scalar)); // cast to T to reduce template instatntions
	}
	template<length_t L, typename T, qualifier Q, typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q>& operator-=(vec<L, T, Q>& v1, U scalar) {
		return v1 -= vec<L, T, Q>(static_cast<T>(scalar));
	}
	template<length_t L, typename T, qualifier Q, typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q>& operator*=(vec<L, T, Q>& v1, U scalar) {
		return v1 *= vec<L, T, Q>(static_cast<T>(scalar));
	}
	template<length_t L, typename T, qualifier Q, typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q>& operator/=(vec<L, T, Q>& v1, U scalar) {
		return v1 /= vec<L, T, Q>(static_cast<T>(scalar));
	}
	template<length_t L, typename T, qualifier Q, typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q>& operator%=(vec<L, T, Q>& v1, U scalar) {
		return v1 %= vec<L, T, Q>(static_cast<T>(scalar));
	}
	template<length_t L, typename T, qualifier Q, typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q>& operator&=(vec<L, T, Q>& v1, U scalar) {
		return v1 &= vec<L, T, Q>(static_cast<T>(scalar));
	}
	template<length_t L, typename T, qualifier Q, typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q>& operator|=(vec<L, T, Q>& v1, U scalar) {
		return v1 &= vec<L, T, Q>(static_cast<T>(scalar));
	}
	template<length_t L, typename T, qualifier Q, typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q>& operator^=(vec<L, T, Q>& v1, U scalar) {
		return v1 ^= vec<L, T, Q>(static_cast<T>(scalar));
	}
	template<length_t L, typename T, qualifier Q, typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q>& operator<<=(vec<L, T, Q>& v1, U scalar) {
		return v1 <<= vec<L, T, Q>(static_cast<T>(scalar));
	}
	template<length_t L, typename T, qualifier Q, typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q>& operator>>=(vec<L, T, Q>& v1, U scalar) {
		return v1 >>= vec<L, T, Q>(static_cast<T>(scalar));
	}

	// vec2

	template<length_t L, typename T, qualifier Q, typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q>& operator+=(vec<L, T, Q>& v1, vec<1, U, Q> const& v2) {
		return v1 += v2.x;
	}
	template<length_t L, typename T, qualifier Q, typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q>& operator-=(vec<L, T, Q>& v1, vec<1, U, Q> const& v2) {
		return v1 -= v2.x;
	}
	template<length_t L, typename T, qualifier Q, typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q>& operator*=(vec<L, T, Q>& v1, vec<1, U, Q> const& v2) {
		return v1 *= v2.x;
	}
	template<length_t L, typename T, qualifier Q, typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q>& operator/=(vec<L, T, Q>& v1, vec<1, U, Q> const& v2) {
		return v1 /= v2.x;
	}
	template<length_t L, typename T, qualifier Q, typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q>& operator%=(vec<L, T, Q>& v1, vec<1, U, Q> const& v2) {
		return v1 %= v2.x;
	}
	template<length_t L, typename T, qualifier Q, typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q>& operator&=(vec<L, T, Q>& v1, vec<1, U, Q> const& v2) {
		return v1 &= v2.x;
	}
	template<length_t L, typename T, qualifier Q, typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q>& operator|=(vec<L, T, Q>& v1, vec<1, U, Q> const& v2) {
		return v1 |= v2.x;
	}
	template<length_t L, typename T, qualifier Q, typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q>& operator^=(vec<L, T, Q>& v1, vec<1, U, Q> const& v2) {
		return v1 ^= v2.x;
	}
	template<length_t L, typename T, qualifier Q, typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q>& operator<<=(vec<L, T, Q>& v1, vec<1, U, Q> const& v2) {
		return v1 <<= v2.x;
	}
	template<length_t L, typename T, qualifier Q, typename U>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q>& operator>>=(vec<L, T, Q>& v1, vec<1, U, Q> const& v2) {
		return v1 >>= v2.x;
	}



	// Vectors vs Vectors
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator+(vec<L, T, Q> const& v1, vec<L, T, Q> const& v2) {
		return vec<L, T, Q>(v1) += v2;
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator-(vec<L, T, Q> const& v1, vec<L, T, Q> const& v2) {
		return vec<L, T, Q>(v1) -= v2;
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator*(vec<L, T, Q> const& v1, vec<L, T, Q> const& v2) {
		return vec<L, T, Q>(v1) *= v2;
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator/(vec<L, T, Q> const& v1, vec<L, T, Q> const& v2) {
		return vec<L, T, Q>(v1) /= v2;
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator%(vec<L, T, Q> const& v1, vec<L, T, Q> const& v2) {
		return vec<L, T, Q>(v1) %= v2;
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator&(vec<L, T, Q> const& v1, vec<L, T, Q> const& v2) {
		return vec<L, T, Q>(v1) &= v2;
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator|(vec<L, T, Q> const& v1, vec<L, T, Q> const& v2) {
		return vec<L, T, Q>(v1) |= v2;
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator^(vec<L, T, Q> const& v1, vec<L, T, Q> const& v2) {
		return vec<L, T, Q>(v1) ^= v2;
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator<<(vec<L, T, Q> const& v1, vec<L, T, Q> const& v2) {
		return vec<L, T, Q>(v1) <<= v2;
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator>>(vec<L, T, Q> const& v1, vec<L, T, Q> const& v2) {
		return vec<L, T, Q>(v1) >>= v2;
	}


	// Scalars
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator+(vec<L, T, Q> const& v, T scalar) {
		return vec<L, T, Q>(v) += vec<L, T, Q>(scalar);
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator-(vec<L, T, Q> const& v, T scalar) {
		return vec<L, T, Q>(v) -= vec<L, T, Q>(scalar);
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator*(vec<L, T, Q> const& v, T scalar) {
		return vec<L, T, Q>(v) *= vec<L, T, Q>(scalar);
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator/(vec<L, T, Q> const& v, T scalar) {
		return vec<L, T, Q>(v) /= vec<L, T, Q>(scalar);
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator%(vec<L, T, Q> const& v, T scalar) {
		return vec<L, T, Q>(v) %= vec<L, T, Q>(scalar);
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator&(vec<L, T, Q> const& v, T scalar) {
		return vec<L, T, Q>(v) &= vec<L, T, Q>(scalar);
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator|(vec<L, T, Q> const& v, T scalar) {
		return vec<L, T, Q>(v) |= vec<L, T, Q>(scalar);
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator^(vec<L, T, Q> const& v, T scalar) {
		return vec<L, T, Q>(v) ^= vec<L, T, Q>(scalar);
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator<<(vec<L, T, Q> const& v, T scalar) {
		return vec<L, T, Q>(v) <<= vec<L, T, Q>(scalar);
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator>>(vec<L, T, Q> const& v, T scalar) {
		return vec<L, T, Q>(v) >>= vec<L, T, Q>(scalar);
	}

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator+(T scalar, vec<L, T, Q> const& v) {
		return vec<L, T, Q>(scalar) += v;
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator-(T scalar, vec<L, T, Q> const& v) {
		return vec<L, T, Q>(scalar) -= v;
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator*(T scalar, vec<L, T, Q> const& v) {
		return vec<L, T, Q>(scalar) *= v;
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator/(T scalar, vec<L, T, Q> const& v) {
		return vec<L, T, Q>(scalar) /= v;
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator%(T scalar, vec<L, T, Q> const& v) {
		return vec<L, T, Q>(scalar) %= v;
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator&(T scalar, vec<L, T, Q> const& v) {
		return vec<L, T, Q>(scalar) &= v;
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator|(T scalar, vec<L, T, Q> const& v) {
		return vec<L, T, Q>(scalar) |= v;
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator^(T scalar, vec<L, T, Q> const& v) {
		return vec<L, T, Q>(scalar) ^= v;
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator<<(T scalar, vec<L, T, Q> const& v) {
		return vec<L, T, Q>(scalar) <<= v;
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator>>(T scalar, vec<L, T, Q> const& v) {
		return vec<L, T, Q>(scalar) >>= v;
	}




	/// vec1

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator+(vec<1, T, Q> const& v1, vec<L, T, Q> const& v2) {
		return v1.x + v2;
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator-(vec<1, T, Q> const& v1, vec<L, T, Q> const& v2) {
		return v1.x - v2;
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator*(vec<1, T, Q> const& v1, vec<L, T, Q> const& v2) {
		return v1.x * v2;
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator/(vec<1, T, Q> const& v1, vec<L, T, Q> const& v2) {
		return v1.x / v2;
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator%(vec<1, T, Q> const& v1, vec<L, T, Q> const& v2) {
		return v1.x % v2;
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator&(vec<1, T, Q> const& v1, vec<L, T, Q> const& v2) {
		return v1.x & v2;
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator|(vec<1, T, Q> const& v1, vec<L, T, Q> const& v2) {
		return v1.x | v2;
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator^(vec<1, T, Q> const& v1, vec<L, T, Q> const& v2) {
		return v1.x ^ v2;
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator<<(vec<1, T, Q> const& v1, vec<L, T, Q> const& v2) {
		return v1.x << v2;
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator>>(vec<1, T, Q> const& v1, vec<L, T, Q> const& v2) {
		return v1.x >> v2;
	}

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator+(vec<L, T, Q> const& v1, vec<1, T, Q> const& v2) {
		return v1 + v2.x;
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator-(vec<L, T, Q> const& v1, vec<1, T, Q> const& v2) {
		return v1 - v2.x;
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator*(vec<L, T, Q> const& v1, vec<1, T, Q> const& v2) {
		return v1 * v2.x;
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator/(vec<L, T, Q> const& v1, vec<1, T, Q> const& v2) {
		return v1 / v2.x;
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator%(vec<L, T, Q> const& v1, vec<1, T, Q> const& v2) {
		return v1 / v2.x;
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator&(vec<L, T, Q> const& v1, vec<1, T, Q> const& v2) {
		return v1 & v2.x;
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator|(vec<L, T, Q> const& v1, vec<1, T, Q> const& v2) {
		return v1 | v2.x;
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator^(vec<L, T, Q> const& v1, vec<1, T, Q> const& v2) {
		return v1 ^ v2.x;
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator<<(vec<L, T, Q> const& v1, vec<1, T, Q> const& v2) {
		return v1 << v2.x;
	}
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator>>(vec<L, T, Q> const& v1, vec<1, T, Q> const& v2) {
		return v1 >> v2.x;
	}


	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR bool operator!=(vec<L, T, Q> const& v1, vec<L, T, Q> const& v2) {
		return !(v1 == v2);
	}
}
