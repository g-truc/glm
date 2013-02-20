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
/// @ref gtx_dual_quaternion
/// @file glm/gtx/dual_quaternion.hpp
/// @date 2013-02-10 / 2013-02-20
/// @author Maksim Vorobiev (msomeone@gmail.com)
///
/// @see core (dependence)
/// @see gtc_half_float (dependence)
/// @see gtc_constants (dependence)
/// @see gtc_quaternion (dependence)
///
/// @defgroup gtc_dual_quaternion GLM_GTX_dual_quaternion
/// @ingroup gtc
/// 
/// @brief Defines a templated dual-quaternion type and several dual-quaternion operations.
/// 
/// <glm/gtx/dual_quaternion.hpp> need to be included to use these functionalities.
///////////////////////////////////////////////////////////////////////////////////

#ifndef GLM_GTX_dual_quaternion
#define GLM_GTX_dual_quaternion GLM_VERSION

// Dependency:
#include "../glm.hpp"
#include "../gtc/half_float.hpp"
#include "../gtc/constants.hpp"
#include "../gtc/quaternion.hpp"

#if(defined(GLM_MESSAGES) && !defined(glm_ext))
#	pragma message("GLM: GLM_GTX_dual_quaternion extension included")
#endif

namespace glm{
namespace detail
{
    template <typename T> 
    struct tdualquat// : public genType<T, tquat>
    {
        enum ctor{null};

        typedef T value_type;
        typedef glm::detail::tquat<T> part_type;
        typedef std::size_t size_type;

    public:
        glm::detail::tquat<T> real, dual;

        GLM_FUNC_DECL size_type length() const;

        // Constructors
        tdualquat();
        explicit tdualquat(tquat<T> const & real);
        tdualquat(tquat<T> const & real,tquat<T> const & dual);
        tdualquat(tquat<T> const & orientation,tvec3<T> const& translation);

        //////////////////////////////////////////////////////////////
        // tdualquat conversions
        explicit tdualquat(tmat2x4<T> const & holder_mat);
        explicit tdualquat(tmat3x4<T> const & aug_mat);

        // Accesses
        typename part_type & operator[](int i);
        typename part_type const & operator[](int i) const;

        // Operators
        tdualquat<T> & operator*=(value_type const & s);
        tdualquat<T> & operator/=(value_type const & s);
    };

    template <typename T> 
    detail::tquat<T> operator- (
        detail::tquat<T> const & q);
    
    template <typename T> 
    detail::tdualquat<T> operator+ ( 
        detail::tdualquat<T> const & q, 
        detail::tdualquat<T> const & p); 

    template <typename T>
    detail::tdualquat<T> operator* (
        detail::tdualquat<T> const & q, 
        detail::tdualquat<T> const & p); 

    template <typename T> 
    detail::tvec3<T> operator* (
        detail::tquat<T> const & q, 
        detail::tvec3<T> const & v);

    template <typename T> 
    detail::tvec3<T> operator* (
        detail::tvec3<T> const & v,
        detail::tquat<T> const & q);

    template <typename T> 
    detail::tvec4<T> operator* (
        detail::tquat<T> const & q, 
        detail::tvec4<T> const & v);

    template <typename T> 
    detail::tvec4<T> operator* (
        detail::tvec4<T> const & v,
        detail::tquat<T> const & q);

    template <typename T> 
    detail::tdualquat<T> operator* (
        detail::tdualquat<T> const & q, 
        typename detail::tdualquat<T>::value_type const & s);

    template <typename T> 
    detail::tdualquat<T> operator* (
        typename detail::tdualquat<T>::value_type const & s,
        detail::tdualquat<T> const & q);

    template <typename T> 
    detail::tdualquat<T> operator/ (
        detail::tdualquat<T> const & q, 
        typename detail::tdualquat<T>::value_type const & s);
} //namespace detail

    /// @addtogroup gtc_dual_quaternion
    /// @{

    /// Returns the normalized quaternion. 
    /// 
    /// @see gtc_dual_quaternion
    template <typename T> 
    detail::tdualquat<T> normalize(
        detail::tdualquat<T> const & q);

    /// Returns the linear interpolation of two dual quaternion. 
    /// 
    /// @see gtc_dual_quaternion
    template <typename T>
    detail::tdualquat<T> lerp (
        detail::tdualquat<T> const & x, 
        detail::tdualquat<T> const & y,
        typename detail::tdualquat<T>::value_type const & a); 

    /// Returns the q inverse. 
    /// 
    /// @see gtc_dual_quaternion
    template <typename T> 
    detail::tdualquat<T> inverse(
        detail::tdualquat<T> const & q);

    /// Extracts a rotation part from dual-quaternion to a 3 * 3 matrix. 
    /// 
    /// @see gtc_dual_quaternion
    template <typename T> 
    detail::tmat3x3<T> mat3_cast(
        detail::tdualquat<T> const & x);

    /// Converts a quaternion to a 2 * 4 matrix. 
    /// 
    /// @see gtc_dual_quaternion
    template <typename T> 
    detail::tmat2x4<T> mat2x4_cast(
        detail::tdualquat<T> const & x);

    /// Converts a quaternion to a 3 * 4 matrix. 
    /// 
    /// @see gtc_dual_quaternion
    template <typename T> 
    detail::tmat3x4<T> mat3x4_cast(
        detail::tdualquat<T> const & x);

    /// Converts a 2 * 4 matrix (matrix which holds real and dual parts) to a quaternion. 
    /// 
    /// @see gtc_dual_quaternion
    template <typename T> 
    detail::tdualquat<T> dualquat_cast(
        detail::tmat2x4<T> const & x);

    /// Converts a 3 * 4 matrix (augmented matrix rotation + translation) to a quaternion. 
    /// 
    /// @see gtc_dual_quaternion
    template <typename T> 
    detail::tdualquat<T> dualquat_cast(
        detail::tmat3x4<T> const & x);

    /// Dual-quaternion of floating-point numbers. 
    /// 
    /// @see gtc_dual_quaternion
    typedef detail::tdualquat<float> dualquat;

    /// Dual-quaternion of half-precision floating-point numbers.
    /// 
    /// @see gtc_dual_quaternion
    typedef detail::tdualquat<detail::half>	hdualquat;

    /// Dual-quaternion of single-precision floating-point numbers. 
    /// 
    /// @see gtc_dual_quaternion
    typedef detail::tdualquat<float>	fdualquat;

    /// Dual-quaternion of double-precision floating-point numbers. 
    /// 
    /// @see gtc_dual_quaternion
    typedef detail::tdualquat<double>	ddualquat;

    /// Dual-quaternion of low precision floating-point numbers.
    /// 
    /// @see gtc_dual_quaternion
    typedef detail::tdualquat<lowp_float>		lowp_dualquat;

    /// Dual-quaternion of medium precision floating-point numbers. 
    /// 
    /// @see gtc_dual_quaternion
    typedef detail::tdualquat<mediump_float>	mediump_dualquat;

    /// Dual-quaternion of high precision floating-point numbers. 
    /// 
    /// @see gtc_dual_quaternion
    typedef detail::tdualquat<highp_float>		highp_dualquat;

    /// @}
} //namespace glm

#include "dual_quaternion.inl"

#endif//GLM_GTX_dual_quaternion
