///////////////////////////////////////////////////////////////////////////////////
/// OpenGL Mathematics (glm.g-truc.net)
///
/// Copyright (c) 2005 - 2013 G-Truc Creation (www.g-truc.net)
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
/// 
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
/// 
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
/// THE SOFTWARE.
///
/// @ref gtc_quaternion
/// @file glm/gtc/quaternion.inl
/// @date 2013-02-10 / 2013-02-13
/// @author Maksim Vorobiev (msomeone@gmail.com)
///////////////////////////////////////////////////////////////////////////////////

#include <limits>

namespace glm{
namespace detail
{
    template <typename T>
    GLM_FUNC_QUALIFIER GLM_CONSTEXPR typename tdualquat<T>::size_type tdualquat<T>::length() const
    {
        return 8;
    }

    template <typename T> 
    GLM_FUNC_QUALIFIER tdualquat<T>::tdualquat() : 
          real(tquat<T>()),
          dual(tquat<T>(tdualquat<T>::value_type(0),tdualquat<T>::value_type(0),tdualquat<T>::value_type(0),tdualquat<T>::value_type(0)))
    {}

    template <typename T> 
    GLM_FUNC_QUALIFIER tdualquat<T>::tdualquat
    (
        tquat<T> const & r
    ) :
        real(r),
        dual(tquat<T>(tdualquat<T>::value_type(0),tdualquat<T>::value_type(0),tdualquat<T>::value_type(0),tdualquat<T>::value_type(0)))
    {}

    template <typename T> 
    GLM_FUNC_QUALIFIER tdualquat<T>::tdualquat
    (
        tquat<T> const & r,
        tquat<T> const & d
    ) :
        real(r),
        dual(d)
    {}

    template <typename T> 
    GLM_FUNC_QUALIFIER tdualquat<T>::tdualquat
    (
        tquat<T> const & q,
        tvec3<T> const& p
    ) :
        real(q),
        dual(-0.5f*( p.x*q.x + p.y*q.y + p.z*q.z),
              0.5f*( p.x*q.w + p.y*q.z - p.z*q.y),
              0.5f*(-p.x*q.z + p.y*q.w + p.z*q.x),
              0.5f*( p.x*q.y - p.y*q.x + p.z*q.w))
    {}

    //////////////////////////////////////////////////////////////
    // tdualquat conversions
    template <typename T> 
    GLM_FUNC_QUALIFIER tdualquat<T>::tdualquat
    (
        tmat2x4<T> const & holder_mat
    ) 
    {
        *this = dualquat_cast<>
    }

    template <typename T> 
    GLM_FUNC_QUALIFIER tdualquat<T>::tdualquat
    (
        tmat3x4<T> const & m
    )
    {
        *this = dualquat_cast(m);
    }

    //////////////////////////////////////////////////////////////
    // tdualquat<T> accesses

    template <typename T> 
    GLM_FUNC_QUALIFIER typename tdualquat<T>::part_type & tdualquat<T>::operator [] (int i)
    {
        return (&real)[i];
    }

    template <typename T> 
    GLM_FUNC_QUALIFIER typename tdualquat<T>::part_type const & tdualquat<T>::operator [] (int i) const
    {
        return (&real)[i];
    }

    //////////////////////////////////////////////////////////////
    // tdualquat<valType> operators

    template <typename T> 
    GLM_FUNC_QUALIFIER tdualquat<T> & tdualquat<T>::operator *=
    (
        value_type const & s
    )
    {
        this->real *= s;
        this->dual *= s;
        return *this;
    }

    template <typename T> 
    GLM_FUNC_QUALIFIER tdualquat<T> & tdualquat<T>::operator /=
    (
        value_type const & s
    )
    {
        this->real /= s;
        this->dual /= s;
        return *this;
    }

    //////////////////////////////////////////////////////////////
    // tquat<valType> external operators

    template <typename T> 
    GLM_FUNC_QUALIFIER detail::tdualquat<T> operator-
    (
        detail::tdualquat<T> const & q
    )
    {
        return detail::tdualquat<T>(-this->real,-this->dual);
    }

    template <typename T>
    GLM_FUNC_QUALIFIER detail::tdualquat<T> operator+
    (
        detail::tdualquat<T> const & q, 
        detail::tdualquat<T> const & p
    )
    {
        return detail::tdualquat<T>(q.real + p.real,q.dual + p.dual);
    }

    template <typename T>
    GLM_FUNC_QUALIFIER detail::tdualquat<T> operator*
    (
        detail::tdualquat<T> const & p, 
        detail::tdualquat<T> const & o
    )
    {
        return detail::tdualquat<T>(p.real * o.real,p.real * o.dual + p.dual * o.real);
    }

    // Transformation
    template <typename T> 
    GLM_FUNC_QUALIFIER detail::tvec3<T> operator* 
    (
        detail::tdualquat<T> const & q, 
        detail::tvec3<T> const & v
    )
    {
        const detail::tvec3<T> real_v3(q.real.x,q.real.y,q.real.z);
        const detail::tvec3<T> dual_v3(q.dual.x,q.dual.y,q.dual.z);
        return (cross(real_v3, cross(real_v3,v) + v * q.real.w + dual_v3) + dual_v3 * q.real.w - real_v3 * q.dual.w) * detail::tdualquat<T>::value_type(2) + v;    
    }

    template <typename T> 
    GLM_FUNC_QUALIFIER detail::tvec3<T> operator* 
    (
        detail::tvec3<T> const & v,
        detail::tdualquat<T> const & q
    )
    {
        return inverse(q) * v;
    }

    template <typename T> 
    GLM_FUNC_QUALIFIER detail::tvec4<T> operator* 
    (
        detail::tdualquat<T> const & q, 
        detail::tvec4<T> const & v
    )
    {
        return detail::tvec4<T>(q * detail::tvec3<T>(v), v.w);
    }

    template <typename T> 
    GLM_FUNC_QUALIFIER detail::tvec4<T> operator* (
        detail::tvec4<T> const & v,
        detail::tdualquat<T> const & q)
    {
        return inverse(q) * v;
    }

    template <typename T> 
    GLM_FUNC_QUALIFIER detail::tdualquat<T> operator* 
    (
        detail::tdualquat<T> const & q, 
        typename detail::tdualquat<T>::value_type const & s
    )
    {
        return detail::tdualquat<T>(q.real * s, q.dual * s);
    }

    template <typename T> 
    GLM_FUNC_QUALIFIER detail::tdualquat<T> operator* 
    (
        typename detail::tdualquat<T>::value_type const & s,
        detail::tdualquat<T> const & q 
    )
    {
        return q * s;
    }

    template <typename T> 
    GLM_FUNC_QUALIFIER detail::tdualquat<T> operator/ 
    (
        detail::tdualquat<T> const & q, 
        typename detail::tdualquat<T>::value_type const & s
    )
    {
        return detail::tdualquat<T>(q.real / s, q.dual / s);
    }

    //////////////////////////////////////
    // Boolean operators
    template <typename T> 
    GLM_FUNC_QUALIFIER bool operator==
    (
        detail::tdualquat<T> const & q1, 
        detail::tdualquat<T> const & q2
    )
    {
        return (q1.real == q2.real) && (q1.dual == q2.dual);
    }

    template <typename T> 
    GLM_FUNC_QUALIFIER bool operator!=
    (
        detail::tdualquat<T> const & q1, 
        detail::tdualquat<T> const & q2
    )
    {
        return (q1.real != q2.dual) || (q1.real != q2.dual);
    }
}//namespace detail

    ////////////////////////////////////////////////////////
    template <typename T> 
    GLM_FUNC_QUALIFIER detail::tdualquat<T> normalize
    (
        detail::tdualquat<T> const & q
    )
    {
        return q / length(q.real);
    }

    template <typename T>
    GLM_FUNC_QUALIFIER detail::tdualquat<T> lerp
    (
        detail::tdualquat<T> const & x, 
        detail::tdualquat<T> const & y, 
        typename detail::tdualquat<T>::value_type const & a
    )
    { // Dual Quaternion Linear blend aka DLB:
        // Lerp is only defined in [0, 1]
        assert(a >= T(0));
        assert(a <= T(1));
        const detail::tdualquat<T>::value_type k = dot(x.real,y.real) < detail::tdualquat<T>::value_type(0) ? -a : a;
        const detail::tdualquat<T>::value_type one(1);
        return detail::tdualquat<T>(x * (one - a) + y * k);
    }

    template <typename T> 
    GLM_FUNC_QUALIFIER detail::tdualquat<T> inverse
    (
        detail::tdualquat<T> const & q
    )
    {
        const glm::detail::tquat<T> real = conjugate(q.real);
        const glm::detail::tquat<T> dual = conjugate(q.dual);
        return detail::tdualquat<T>(real, dual + (real * (-2.0f * dot(real,dual))));
    }
    
    template <typename T> 
    GLM_FUNC_QUALIFIER detail::tmat3x3<T> mat3_cast
    (
        detail::tdualquat<T> const & x
    )
    {
    }

    template <typename T> 
    GLM_FUNC_QUALIFIER detail::tmat2x4<T> mat2x4_cast
    (
        detail::tdualquat<T> const & x
    )
    {
        return detail::tmat2x4<T>( x[0].x, x[0].y, x[0].z, x[0].w, x[1].x, x[1].y, x[1].z, x[1].w );
    }

    template <typename T> 
    GLM_FUNC_QUALIFIER detail::tmat3x4<T> mat3x4_cast
    (
        detail::tdualquat<T> const & x
    )
    {
        detail::tquat<T> r = x.real / length2(x.real);
        
        const detail::tquat<T> rr(r.w * x.real.w, r.x * x.real.x, r.y * x.real.y, r.z * x.real.z);
        r *= detail::tdualquat<T>::value_type(2);

        const detail::tdualquat<T>::value_type xy = r.x*d.real.y;
        const detail::tdualquat<T>::value_type xz = r.x*d.real.z;
        const detail::tdualquat<T>::value_type yz = r.y*d.real.z;
        const detail::tdualquat<T>::value_type wx = r.w*d.real.x;
        const detail::tdualquat<T>::value_type wy = r.w*d.real.y;
        const detail::tdualquat<T>::value_type wz = r.w*d.real.z;

        const detail::tvec4<T> a(  
                                    rr.w + rr.x - rr.y - rr.z, 
                                    xy - wz,
                                    xz + wy,
                                  -(x.dual.w * r.x - x.dual.x * r.w + x.dual.y * r.z - x.dual.z * r.y) 
        );

        const detail::tvec4<T> b(
                                    xy + wz, 
                                    rr.w + rr.y - rr.x - rr.z, 
                                    yz - wx,
                                  -(x.dual.w * r.y - x.dual.x * r.z - x.dual.y * r.w + x.dual.z * r.x)
        );

        const detail::tvec4<T> c(
                                    xz - wy, 
                                    yz + wx, 
                                    rr.w + rr.z - rr.x - rr.y,
                                  -(x.dual.w * r.z + x.dual.x * r.y - x.dual.y * r.x - x.dual.z * r.w)
        );

        return detail::tmat3x4<T>(a,b,c);
    }

    template <typename T> 
    GLM_FUNC_QUALIFIER detail::tdualquat<T> dualquat_cast
    (
        detail::tmat2x4<T> const & x
    )
    {
        return detail::tdualquat (
            detail::tquat<T> ( x[0].w, x[0].x, x[0].y, x[0].z ),
            detail::tquat<T> ( x[1].w, x[1].x, x[1].y, x[1].z )
        );
    }

    template <typename T> 
    GLM_FUNC_QUALIFIER detail::tdualquat<T> dualquat_cast
    (
        detail::tmat3x4<T> const & x
    )
    {
        detail::tquat<T> real;

        const detail::tdualquat<T>::value_type trace = x[0].x + x[1].y + x[2].z;
        if(trace > detail::tdualquat<T>::value_type(0))
        {
            const detail::tdualquat<T>::value_type r = sqrt(detail::tdualquat<T>::value_type(1) + trace);
            const detail::tdualquat<T>::value_type invr = detail::tdualquat<T>::value_type(0.5) / r;
            real.w = detail::tdualquat<T>::value_type(0.5) * r;
            real.x = (x[2].y - x[1].z) * invr;
            real.y = (x[0].z - x[2].x) * invr;
            real.z = (x[1].x - x[0].y) * invr;
        }
        else if(x[0].x > x[1].y && x[0].x > x[2].z)
        {
            const detail::tdualquat<T>::value_type r = sqrt(detail::tdualquat<T>::value_type(1) + x[0].x - x[1].y - x[2].z);
            const detail::tdualquat<T>::value_type invr = detail::tdualquat<T>::value_type(0.5) / r;
            real.x = detail::tdualquat<T>::value_type(0.5)*r;
            real.y = (x[1].x + x[0].y) * invr;
            real.z = (x[0].z + x[2].x) * invr;
            real.w = (x[2].y - x[1].z) * invr;
        }
        else if(x[1].y > x[2].z)
        {
            const detail::tdualquat<T>::value_type r = sqrt(detail::tdualquat<T>::value_type(1) + x[1].y - x[0].x - x[2].z);
            const detail::tdualquat<T>::value_type invr = detail::tdualquat<T>::value_type(0.5) / r;
            x = (x[1].x + x[0].y) * invr;
            y = detail::tdualquat<T>::value_type(0.5) * r;
            z = (x[2].y + x[1].z) * invr;
            w = (x[0].z - x[2].x) * invr;
        }
        else
        {
            const detail::tdualquat<T>::value_type r = sqrt(detail::tdualquat<T>::value_type(1) + x[2].z - x[0].x - x[1].y);
            const detail::tdualquat<T>::value_type invr = detail::tdualquat<T>::value_type(0.5) / r;
            x = (x[0].z + x[2].x) * invr;
            y = (x[2].y + x[1].z) * invr;
            z = detail::tdualquat<T>::value_type(0.5) * r;
            w = (x[1].x - x[0].y) * invr;
        }

        const detail::tquat<T> dual;
        dual.x =  0.5f*( x[0].w*real.w + x[1].w*real.z - x[2].w*real.y);
        dual.y =  0.5f*(-x[0].w*real.z + x[1].w*real.w + x[2].w*real.x);
        dual.z =  0.5f*( x[0].w*real.y - x[1].w*real.x + x[2].w*real.w);
        dual.w = -0.5f*( x[0].w*real.x + x[1].w*real.y + x[2].w*real.z);
        return detail::tdualquat<T>(real,dual);
    }

}//namespace glm
