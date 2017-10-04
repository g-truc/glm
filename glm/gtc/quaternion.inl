/// @ref gtc_quaternion
/// @file glm/gtc/quaternion.inl

#include "../trigonometric.hpp"
#include "../geometric.hpp"
#include "../exponential.hpp"
#include "../detail/compute_vector_relational.hpp"
#include "epsilon.hpp"
#include <limits>

namespace glm{
namespace detail
{
	template<typename T, qualifier Q, bool Aligned>
	struct compute_dot<tquat<T, Q>, T, Aligned>
	{
		static GLM_FUNC_QUALIFIER T call(tquat<T, Q> const& a, tquat<T, Q> const& b)
		{
			vec<4, T, Q> tmp(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w);
			return (tmp.x + tmp.y) + (tmp.z + tmp.w);
		}
	};

	template<typename T, qualifier Q, bool Aligned>
	struct compute_quat_add
	{
		static tquat<T, Q> call(tquat<T, Q> const& q, tquat<T, Q> const& p)
		{
			return tquat<T, Q>(q.w + p.w, q.x + p.x, q.y + p.y, q.z + p.z);
		}
	};

	template<typename T, qualifier Q, bool Aligned>
	struct compute_quat_sub
	{
		static tquat<T, Q> call(tquat<T, Q> const& q, tquat<T, Q> const& p)
		{
			return tquat<T, Q>(q.w - p.w, q.x - p.x, q.y - p.y, q.z - p.z);
		}
	};

	template<typename T, qualifier Q, bool Aligned>
	struct compute_quat_mul_scalar
	{
		static tquat<T, Q> call(tquat<T, Q> const& q, T s)
		{
			return tquat<T, Q>(q.w * s, q.x * s, q.y * s, q.z * s);
		}
	};

	template<typename T, qualifier Q, bool Aligned>
	struct compute_quat_div_scalar
	{
		static tquat<T, Q> call(tquat<T, Q> const& q, T s)
		{
			return tquat<T, Q>(q.w / s, q.x / s, q.y / s, q.z / s);
		}
	};

	template<typename T, qualifier Q, bool Aligned>
	struct compute_quat_mul_vec4
	{
		static vec<4, T, Q> call(tquat<T, Q> const& q, vec<4, T, Q> const& v)
		{
			return vec<4, T, Q>(q * vec<3, T, Q>(v), v.w);
		}
	};
}//namespace detail

	// -- Component accesses --

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER T & tquat<T, Q>::operator[](typename tquat<T, Q>::length_type i)
	{
		assert(i >= 0 && i < this->length());
		return (&x)[i];
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER T const& tquat<T, Q>::operator[](typename tquat<T, Q>::length_type i) const
	{
		assert(i >= 0 && i < this->length());
		return (&x)[i];
	}

	// -- Implicit basic constructors --

#	if !GLM_HAS_DEFAULTED_FUNCTIONS
		template<typename T, qualifier Q>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR tquat<T, Q>::tquat()
		{}
#	endif

#	if !GLM_HAS_DEFAULTED_FUNCTIONS
		template<typename T, qualifier Q>
		GLM_FUNC_QUALIFIER GLM_CONSTEXPR tquat<T, Q>::tquat(tquat<T, Q> const& q)
			: x(q.x), y(q.y), z(q.z), w(q.w)
		{}
#	endif//!GLM_HAS_DEFAULTED_FUNCTIONS

	template<typename T, qualifier Q>
	template<qualifier P>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR tquat<T, Q>::tquat(tquat<T, P> const& q)
		: x(q.x), y(q.y), z(q.z), w(q.w)
	{}

	// -- Explicit basic constructors --

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR tquat<T, Q>::tquat(T s, vec<3, T, Q> const& v)
		: x(v.x), y(v.y), z(v.z), w(s)
	{}

	template <typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR tquat<T, Q>::tquat(T _w, T _x, T _y, T _z)
		: x(_x), y(_y), z(_z), w(_w)
	{}

	// -- Conversion constructors --

	template<typename T, qualifier Q>
	template<typename U, qualifier P>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR tquat<T, Q>::tquat(tquat<U, P> const& q)
		: x(static_cast<T>(q.x))
		, y(static_cast<T>(q.y))
		, z(static_cast<T>(q.z))
		, w(static_cast<T>(q.w))
	{}

	//template<typename valType> 
	//GLM_FUNC_QUALIFIER tquat<valType>::tquat
	//(
	//	valType const& pitch,
	//	valType const& yaw,
	//	valType const& roll
	//)
	//{
	//	vec<3, valType> eulerAngle(pitch * valType(0.5), yaw * valType(0.5), roll * valType(0.5));
	//	vec<3, valType> c = glm::cos(eulerAngle * valType(0.5));
	//	vec<3, valType> s = glm::sin(eulerAngle * valType(0.5));
	//	
	//	this->w = c.x * c.y * c.z + s.x * s.y * s.z;
	//	this->x = s.x * c.y * c.z - c.x * s.y * s.z;
	//	this->y = c.x * s.y * c.z + s.x * c.y * s.z;
	//	this->z = c.x * c.y * s.z - s.x * s.y * c.z;
	//}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER tquat<T, Q>::tquat(vec<3, T, Q> const& u, vec<3, T, Q> const& v)
	{
		T norm_u_norm_v = sqrt(dot(u, u) * dot(v, v));
		T real_part = norm_u_norm_v + dot(u, v);
		vec<3, T, Q> t;

		if(real_part < static_cast<T>(1.e-6f) * norm_u_norm_v)
		{
			// If u and v are exactly opposite, rotate 180 degrees
			// around an arbitrary orthogonal axis. Axis normalisation
			// can happen later, when we normalise the quaternion.
			real_part = static_cast<T>(0);
			t = abs(u.x) > abs(u.z) ? vec<3, T, Q>(-u.y, u.x, static_cast<T>(0)) : vec<3, T, Q>(static_cast<T>(0), -u.z, u.y);
		}
		else
		{
			// Otherwise, build quaternion the standard way.
			t = cross(u, v);
		}

	    *this = normalize(tquat<T, Q>(real_part, t.x, t.y, t.z));
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER tquat<T, Q>::tquat(vec<3, T, Q> const& eulerAngle)
	{
		vec<3, T, Q> c = glm::cos(eulerAngle * T(0.5));
		vec<3, T, Q> s = glm::sin(eulerAngle * T(0.5));
		
		this->w = c.x * c.y * c.z + s.x * s.y * s.z;
		this->x = s.x * c.y * c.z - c.x * s.y * s.z;
		this->y = c.x * s.y * c.z + s.x * c.y * s.z;
		this->z = c.x * c.y * s.z - s.x * s.y * c.z;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER tquat<T, Q>::tquat(mat<3, 3, T, Q> const& m)
	{
		*this = quat_cast(m);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER tquat<T, Q>::tquat(mat<4, 4, T, Q> const& m)
	{
		*this = quat_cast(m);
	}

#	if GLM_HAS_EXPLICIT_CONVERSION_OPERATORS
	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER tquat<T, Q>::operator mat<3, 3, T, Q>()
	{
		return mat3_cast(*this);
	}
	
	template<typename T, qualifier Q>	
	GLM_FUNC_QUALIFIER tquat<T, Q>::operator mat<4, 4, T, Q>()
	{
		return mat4_cast(*this);
	}
#	endif//GLM_HAS_EXPLICIT_CONVERSION_OPERATORS

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER tquat<T, Q> conjugate(tquat<T, Q> const& q)
	{
		return tquat<T, Q>(q.w, -q.x, -q.y, -q.z);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER tquat<T, Q> inverse(tquat<T, Q> const& q)
	{
		return conjugate(q) / dot(q, q);
	}

	// -- Unary arithmetic operators --

#	if !GLM_HAS_DEFAULTED_FUNCTIONS
		template<typename T, qualifier Q>
		GLM_FUNC_QUALIFIER tquat<T, Q> & tquat<T, Q>::operator=(tquat<T, Q> const& q)
		{
			this->w = q.w;
			this->x = q.x;
			this->y = q.y;
			this->z = q.z;
			return *this;
		}
#	endif//!GLM_HAS_DEFAULTED_FUNCTIONS

	template<typename T, qualifier Q>
	template<typename U>
	GLM_FUNC_QUALIFIER tquat<T, Q> & tquat<T, Q>::operator=(tquat<U, Q> const& q)
	{
		this->w = static_cast<T>(q.w);
		this->x = static_cast<T>(q.x);
		this->y = static_cast<T>(q.y);
		this->z = static_cast<T>(q.z);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	GLM_FUNC_QUALIFIER tquat<T, Q> & tquat<T, Q>::operator+=(tquat<U, Q> const& q)
	{
		return (*this = detail::compute_quat_add<T, Q, detail::is_aligned<Q>::value>::call(*this, tquat<T, Q>(q)));
	}

	template<typename T, qualifier Q>
	template<typename U>
	GLM_FUNC_QUALIFIER tquat<T, Q> & tquat<T, Q>::operator-=(tquat<U, Q> const& q)
	{
		return (*this = detail::compute_quat_sub<T, Q, detail::is_aligned<Q>::value>::call(*this, tquat<T, Q>(q)));
	}

	template<typename T, qualifier Q>
	template<typename U>
	GLM_FUNC_QUALIFIER tquat<T, Q> & tquat<T, Q>::operator*=(tquat<U, Q> const& r)
	{
		tquat<T, Q> const p(*this);
		tquat<T, Q> const q(r);

		this->w = p.w * q.w - p.x * q.x - p.y * q.y - p.z * q.z;
		this->x = p.w * q.x + p.x * q.w + p.y * q.z - p.z * q.y;
		this->y = p.w * q.y + p.y * q.w + p.z * q.x - p.x * q.z;
		this->z = p.w * q.z + p.z * q.w + p.x * q.y - p.y * q.x;
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	GLM_FUNC_QUALIFIER tquat<T, Q> & tquat<T, Q>::operator*=(U s)
	{
		return (*this = detail::compute_quat_mul_scalar<T, Q, detail::is_aligned<Q>::value>::call(*this, static_cast<U>(s)));
	}

	template<typename T, qualifier Q>
	template<typename U>
	GLM_FUNC_QUALIFIER tquat<T, Q> & tquat<T, Q>::operator/=(U s)
	{
		return (*this = detail::compute_quat_div_scalar<T, Q, detail::is_aligned<Q>::value>::call(*this, static_cast<U>(s)));
	}

	// -- Unary bit operators --

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER tquat<T, Q> operator+(tquat<T, Q> const& q)
	{
		return q;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER tquat<T, Q> operator-(tquat<T, Q> const& q)
	{
		return tquat<T, Q>(-q.w, -q.x, -q.y, -q.z);
	}

	// -- Binary operators --

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER tquat<T, Q> operator+(tquat<T, Q> const& q, tquat<T, Q> const& p)
	{
		return tquat<T, Q>(q) += p;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER tquat<T, Q> operator*(tquat<T, Q> const& q, tquat<T, Q> const& p)
	{
		return tquat<T, Q>(q) *= p;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, T, Q> operator*(tquat<T, Q> const& q, vec<3, T, Q> const& v)
	{
		vec<3, T, Q> const QuatVector(q.x, q.y, q.z);
		vec<3, T, Q> const uv(glm::cross(QuatVector, v));
		vec<3, T, Q> const uuv(glm::cross(QuatVector, uv));

		return v + ((uv * q.w) + uuv) * static_cast<T>(2);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, T, Q> operator*(vec<3, T, Q> const& v, tquat<T, Q> const& q)
	{
		return glm::inverse(q) * v;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<4, T, Q> operator*(tquat<T, Q> const& q, vec<4, T, Q> const& v)
	{
		return detail::compute_quat_mul_vec4<T, Q, detail::is_aligned<Q>::value>::call(q, v);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<4, T, Q> operator*(vec<4, T, Q> const& v, tquat<T, Q> const& q)
	{
		return glm::inverse(q) * v;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER tquat<T, Q> operator*(tquat<T, Q> const& q, T const& s)
	{
		return tquat<T, Q>(
			q.w * s, q.x * s, q.y * s, q.z * s);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER tquat<T, Q> operator*(T const& s, tquat<T, Q> const& q)
	{
		return q * s;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER tquat<T, Q> operator/(tquat<T, Q> const& q, T const& s)
	{
		return tquat<T, Q>(
			q.w / s, q.x / s, q.y / s, q.z / s);
	}

	// -- Boolean operators --

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER bool operator==(tquat<T, Q> const& q1, tquat<T, Q> const& q2)
	{
		return all(epsilonEqual(q1, q2, epsilon<T>()));
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER bool operator!=(tquat<T, Q> const& q1, tquat<T, Q> const& q2)
	{
		return any(epsilonNotEqual(q1, q2, epsilon<T>()));
	}

	// -- Operations --

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER T dot(tquat<T, Q> const& x, tquat<T, Q> const& y)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'dot' accepts only floating-point inputs");
		return detail::compute_dot<tquat<T, Q>, T, detail::is_aligned<Q>::value>::call(x, y);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER T length(tquat<T, Q> const& q)
	{
		return glm::sqrt(dot(q, q));
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER tquat<T, Q> normalize(tquat<T, Q> const& q)
	{
		T len = length(q);
		if(len <= T(0)) // Problem
			return tquat<T, Q>(static_cast<T>(1), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0));
		T oneOverLen = T(1) / len;
		return tquat<T, Q>(q.w * oneOverLen, q.x * oneOverLen, q.y * oneOverLen, q.z * oneOverLen);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER tquat<T, Q> cross(tquat<T, Q> const& q1, tquat<T, Q> const& q2)
	{
		return tquat<T, Q>(
			q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z,
			q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y,
			q1.w * q2.y + q1.y * q2.w + q1.z * q2.x - q1.x * q2.z,
			q1.w * q2.z + q1.z * q2.w + q1.x * q2.y - q1.y * q2.x);
	}
/*
	// (x * sin(1 - a) * angle / sin(angle)) + (y * sin(a) * angle / sin(angle))
	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER tquat<T, Q> mix(tquat<T, Q> const& x, tquat<T, Q> const& y, T const& a)
	{
		if(a <= T(0)) return x;
		if(a >= T(1)) return y;

		float fCos = dot(x, y);
		tquat<T, Q> y2(y); //BUG!!! tquat<T, Q> y2;
		if(fCos < T(0))
		{
			y2 = -y;
			fCos = -fCos;
		}

		//if(fCos > 1.0f) // problem
		float k0, k1;
		if(fCos > T(0.9999))
		{
			k0 = T(1) - a;
			k1 = T(0) + a; //BUG!!! 1.0f + a;
		}
		else
		{
			T fSin = sqrt(T(1) - fCos * fCos);
			T fAngle = atan(fSin, fCos);
			T fOneOverSin = static_cast<T>(1) / fSin;
			k0 = sin((T(1) - a) * fAngle) * fOneOverSin;
			k1 = sin((T(0) + a) * fAngle) * fOneOverSin;
		}

		return tquat<T, Q>(
			k0 * x.w + k1 * y2.w,
			k0 * x.x + k1 * y2.x,
			k0 * x.y + k1 * y2.y,
			k0 * x.z + k1 * y2.z);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER tquat<T, Q> mix2
	(
		tquat<T, Q> const& x, 
		tquat<T, Q> const& y, 
		T const& a
	)
	{
		bool flip = false;
		if(a <= static_cast<T>(0)) return x;
		if(a >= static_cast<T>(1)) return y;

		T cos_t = dot(x, y);
		if(cos_t < T(0))
		{
			cos_t = -cos_t;
			flip = true;
		}

		T alpha(0), beta(0);

		if(T(1) - cos_t < 1e-7)
			beta = static_cast<T>(1) - alpha;
		else
		{
			T theta = acos(cos_t);
			T sin_t = sin(theta);
			beta = sin(theta * (T(1) - alpha)) / sin_t;
			alpha = sin(alpha * theta) / sin_t;
		}

		if(flip)
			alpha = -alpha;
		
		return normalize(beta * x + alpha * y);
	}
*/

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER tquat<T, Q> mix(tquat<T, Q> const& x, tquat<T, Q> const& y, T a)
	{
		T cosTheta = dot(x, y);

		// Perform a linear interpolation when cosTheta is close to 1 to avoid side effect of sin(angle) becoming a zero denominator
		if(cosTheta > T(1) - epsilon<T>())
		{
			// Linear interpolation
			return tquat<T, Q>(
				mix(x.w, y.w, a),
				mix(x.x, y.x, a),
				mix(x.y, y.y, a),
				mix(x.z, y.z, a));
		}
		else
		{
			// Essential Mathematics, page 467
			T angle = acos(cosTheta);
			return (sin((T(1) - a) * angle) * x + sin(a * angle) * y) / sin(angle);
		}
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER tquat<T, Q> lerp(tquat<T, Q> const& x, tquat<T, Q> const& y, T a)
	{
		// Lerp is only defined in [0, 1]
		assert(a >= static_cast<T>(0));
		assert(a <= static_cast<T>(1));

		return x * (T(1) - a) + (y * a);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER tquat<T, Q> slerp(tquat<T, Q> const& x,	tquat<T, Q> const& y, T a)
	{
		tquat<T, Q> z = y;

		T cosTheta = dot(x, y);

		// If cosTheta < 0, the interpolation will take the long way around the sphere. 
		// To fix this, one quat must be negated.
		if (cosTheta < T(0))
		{
			z        = -y;
			cosTheta = -cosTheta;
		}

		// Perform a linear interpolation when cosTheta is close to 1 to avoid side effect of sin(angle) becoming a zero denominator
		if(cosTheta > T(1) - epsilon<T>())
		{
			// Linear interpolation
			return tquat<T, Q>(
				mix(x.w, z.w, a),
				mix(x.x, z.x, a),
				mix(x.y, z.y, a),
				mix(x.z, z.z, a));
		}
		else
		{
			// Essential Mathematics, page 467
			T angle = acos(cosTheta);
			return (sin((T(1) - a) * angle) * x + sin(a * angle) * z) / sin(angle);
		}
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER tquat<T, Q> rotate(tquat<T, Q> const& q, T const& angle, vec<3, T, Q> const& v)
	{
		vec<3, T, Q> Tmp = v;

		// Axis of rotation must be normalised
		T len = glm::length(Tmp);
		if(abs(len - T(1)) > T(0.001))
		{
			T oneOverLen = static_cast<T>(1) / len;
			Tmp.x *= oneOverLen;
			Tmp.y *= oneOverLen;
			Tmp.z *= oneOverLen;
		}

		T const AngleRad(angle);
		T const Sin = sin(AngleRad * T(0.5));

		return q * tquat<T, Q>(cos(AngleRad * T(0.5)), Tmp.x * Sin, Tmp.y * Sin, Tmp.z * Sin);
		//return gtc::quaternion::cross(q, tquat<T, Q>(cos(AngleRad * T(0.5)), Tmp.x * fSin, Tmp.y * fSin, Tmp.z * fSin));
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, T, Q> eulerAngles(tquat<T, Q> const& x)
	{
		return vec<3, T, Q>(pitch(x), yaw(x), roll(x));
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER T roll(tquat<T, Q> const& q)
	{
		return static_cast<T>(atan(static_cast<T>(2) * (q.x * q.y + q.w * q.z), q.w * q.w + q.x * q.x - q.y * q.y - q.z * q.z));
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER T pitch(tquat<T, Q> const& q)
	{
		//return T(atan(T(2) * (q.y * q.z + q.w * q.x), q.w * q.w - q.x * q.x - q.y * q.y + q.z * q.z));
		const T y = static_cast<T>(2) * (q.y * q.z + q.w * q.x);
		const T x = q.w * q.w - q.x * q.x - q.y * q.y + q.z * q.z;

		if(detail::compute_equal<T>::call(y, static_cast<T>(0)) && detail::compute_equal<T>::call(x, static_cast<T>(0))) //avoid atan2(0,0) - handle singularity - Matiis
			return static_cast<T>(static_cast<T>(2) * atan(q.x,q.w));

		return static_cast<T>(atan(y,x));
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER T yaw(tquat<T, Q> const& q)
	{
		return asin(clamp(static_cast<T>(-2) * (q.x * q.z - q.w * q.y), static_cast<T>(-1), static_cast<T>(1)));
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<3, 3, T, Q> mat3_cast(tquat<T, Q> const& q)
	{
		mat<3, 3, T, Q> Result(T(1));
		T qxx(q.x * q.x);
		T qyy(q.y * q.y);
		T qzz(q.z * q.z);
		T qxz(q.x * q.z);
		T qxy(q.x * q.y);
		T qyz(q.y * q.z);
		T qwx(q.w * q.x);
		T qwy(q.w * q.y);
		T qwz(q.w * q.z);

		Result[0][0] = T(1) - T(2) * (qyy +  qzz);
		Result[0][1] = T(2) * (qxy + qwz);
		Result[0][2] = T(2) * (qxz - qwy);

		Result[1][0] = T(2) * (qxy - qwz);
		Result[1][1] = T(1) - T(2) * (qxx +  qzz);
		Result[1][2] = T(2) * (qyz + qwx);

		Result[2][0] = T(2) * (qxz + qwy);
		Result[2][1] = T(2) * (qyz - qwx);
		Result[2][2] = T(1) - T(2) * (qxx +  qyy);
		return Result;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q> mat4_cast(tquat<T, Q> const& q)
	{
		return mat<4, 4, T, Q>(mat3_cast(q));
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER tquat<T, Q> quat_cast(mat<3, 3, T, Q> const& m)
	{
		T fourXSquaredMinus1 = m[0][0] - m[1][1] - m[2][2];
		T fourYSquaredMinus1 = m[1][1] - m[0][0] - m[2][2];
		T fourZSquaredMinus1 = m[2][2] - m[0][0] - m[1][1];
		T fourWSquaredMinus1 = m[0][0] + m[1][1] + m[2][2];

		int biggestIndex = 0;
		T fourBiggestSquaredMinus1 = fourWSquaredMinus1;
		if(fourXSquaredMinus1 > fourBiggestSquaredMinus1)
		{
			fourBiggestSquaredMinus1 = fourXSquaredMinus1;
			biggestIndex = 1;
		}
		if(fourYSquaredMinus1 > fourBiggestSquaredMinus1)
		{
			fourBiggestSquaredMinus1 = fourYSquaredMinus1;
			biggestIndex = 2;
		}
		if(fourZSquaredMinus1 > fourBiggestSquaredMinus1)
		{
			fourBiggestSquaredMinus1 = fourZSquaredMinus1;
			biggestIndex = 3;
		}

		T biggestVal = sqrt(fourBiggestSquaredMinus1 + static_cast<T>(1)) * static_cast<T>(0.5);
		T mult = static_cast<T>(0.25) / biggestVal;

		tquat<T, Q> Result = {};
		switch(biggestIndex)
		{
		case 0:
			Result.w = biggestVal;
			Result.x = (m[1][2] - m[2][1]) * mult;
			Result.y = (m[2][0] - m[0][2]) * mult;
			Result.z = (m[0][1] - m[1][0]) * mult;
			break;
		case 1:
			Result.w = (m[1][2] - m[2][1]) * mult;
			Result.x = biggestVal;
			Result.y = (m[0][1] + m[1][0]) * mult;
			Result.z = (m[2][0] + m[0][2]) * mult;
			break;
		case 2:
			Result.w = (m[2][0] - m[0][2]) * mult;
			Result.x = (m[0][1] + m[1][0]) * mult;
			Result.y = biggestVal;
			Result.z = (m[1][2] + m[2][1]) * mult;
			break;
		case 3:
			Result.w = (m[0][1] - m[1][0]) * mult;
			Result.x = (m[2][0] + m[0][2]) * mult;
			Result.y = (m[1][2] + m[2][1]) * mult;
			Result.z = biggestVal;
			break;
			
		default:					// Silence a -Wswitch-default warning in GCC. Should never actually get here. Assert is just for sanity.
			assert(false);
			break;
		}
		return Result;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER tquat<T, Q> quat_cast(mat<4, 4, T, Q> const& m4)
	{
		return quat_cast(mat<3, 3, T, Q>(m4));
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER T angle(tquat<T, Q> const& x)
	{
		return acos(x.w) * static_cast<T>(2);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, T, Q> axis(tquat<T, Q> const& x)
	{
		T tmp1 = static_cast<T>(1) - x.w * x.w;
		if(tmp1 <= static_cast<T>(0))
			return vec<3, T, Q>(0, 0, 1);
		T tmp2 = static_cast<T>(1) / sqrt(tmp1);
		return vec<3, T, Q>(x.x * tmp2, x.y * tmp2, x.z * tmp2);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER tquat<T, Q> angleAxis(T const& angle, vec<3, T, Q> const& v)
	{
		tquat<T, Q> Result;

		T const a(angle);
		T const s = glm::sin(a * static_cast<T>(0.5));

		Result.w = glm::cos(a * static_cast<T>(0.5));
		Result.x = v.x * s;
		Result.y = v.y * s;
		Result.z = v.z * s;
		return Result;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<4, bool, Q> lessThan(tquat<T, Q> const& x, tquat<T, Q> const& y)
	{
		vec<4, bool, Q> Result;
		for(length_t i = 0; i < x.length(); ++i)
			Result[i] = x[i] < y[i];
		return Result;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<4, bool, Q> lessThanEqual(tquat<T, Q> const& x, tquat<T, Q> const& y)
	{
		vec<4, bool, Q> Result;
		for(length_t i = 0; i < x.length(); ++i)
			Result[i] = x[i] <= y[i];
		return Result;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<4, bool, Q> greaterThan(tquat<T, Q> const& x, tquat<T, Q> const& y)
	{
		vec<4, bool, Q> Result;
		for(length_t i = 0; i < x.length(); ++i)
			Result[i] = x[i] > y[i];
		return Result;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<4, bool, Q> greaterThanEqual(tquat<T, Q> const& x, tquat<T, Q> const& y)
	{
		vec<4, bool, Q> Result;
		for(length_t i = 0; i < x.length(); ++i)
			Result[i] = x[i] >= y[i];
		return Result;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<4, bool, Q> equal(tquat<T, Q> const& x, tquat<T, Q> const& y)
	{
		vec<4, bool, Q> Result;
		for(length_t i = 0; i < x.length(); ++i)
			Result[i] = detail::compute_equal<T>::call(x[i], y[i]);
		return Result;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<4, bool, Q> notEqual(tquat<T, Q> const& x, tquat<T, Q> const& y)
	{
		vec<4, bool, Q> Result;
		for(length_t i = 0; i < x.length(); ++i)
			Result[i] = !detail::compute_equal<T>::call(x[i], y[i]);
		return Result;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<4, bool, Q> isnan(tquat<T, Q> const& q)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'isnan' only accept floating-point inputs");

		return vec<4, bool, Q>(isnan(q.x), isnan(q.y), isnan(q.z), isnan(q.w));
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<4, bool, Q> isinf(tquat<T, Q> const& q)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'isinf' only accept floating-point inputs");

		return vec<4, bool, Q>(isinf(q.x), isinf(q.y), isinf(q.z), isinf(q.w));
	}
}//namespace glm

#if GLM_ARCH != GLM_ARCH_PURE && GLM_HAS_ALIGNED_TYPE
#	include "quaternion_simd.inl"
#endif

