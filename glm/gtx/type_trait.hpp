///////////////////////////////////////////////////////////////////////////////////
/// OpenGL Mathematics (glm.g-truc.net)
///
/// Copyright (c) 2005 - 2016 G-Truc Creation (www.g-truc.net)
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
/// Restrictions:
///		By making use of the Software for military purposes, you choose to make
///		a Bunny unhappy.
/// 
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
/// THE SOFTWARE.
/// 
/// @ref gtx_type_info
/// @file glm/gtx/type_info.hpp
/// @date 2016-03-12 / 2016-03-12
/// @author Christophe Riccio
/// 
/// @see core (dependence)
/// 
/// @defgroup gtx_type_info GLM_GTX_type_info
/// @ingroup gtx
/// 
/// @brief Defines aligned types.
/// 
/// <glm/gtx/type_aligned.hpp> need to be included to use these functionalities.
///////////////////////////////////////////////////////////////////////////////////

#pragma once

// Dependency:
#include "../detail/precision.hpp"
#include "../detail/setup.hpp"

#if(defined(GLM_MESSAGES) && !defined(GLM_EXT_INCLUDED))
#	pragma message("GLM: GLM_GTX_type_info extension included")
#endif

namespace glm
{
	/// @addtogroup gtx_type_info
	/// @{

	template <typename T, precision P> struct tvec1;
	template <typename T, precision P> struct tvec2;
	template <typename T, precision P> struct tvec3;
	template <typename T, precision P> struct tvec4;

	template <typename T, precision P> struct tmat2x2;
	template <typename T, precision P> struct tmat2x3;
	template <typename T, precision P> struct tmat2x4;
	template <typename T, precision P> struct tmat3x2;
	template <typename T, precision P> struct tmat3x3;
	template <typename T, precision P> struct tmat3x4;
	template <typename T, precision P> struct tmat4x2;
	template <typename T, precision P> struct tmat4x3;
	template <typename T, precision P> struct tmat4x4;

	template <typename T, precision P> struct tquat;
	template <typename T, precision P> struct tdualquat;

	template <template <typename, precision> class genType>
	struct type
	{
		static bool const is_vec = false;
		static bool const is_mat = false;
		static bool const is_quat = false;
		static GLM_RELAXED_CONSTEXPR length_t components = 0;
	};

	template <>
	struct type<tvec1>
	{
		static bool const is_vec = true;
		static bool const is_mat = false;
		static bool const is_quat = false;
		static GLM_RELAXED_CONSTEXPR length_t components = 1;
	};

	template <>
	struct type<tvec2>
	{
		static bool const is_vec = true;
		static bool const is_mat = false;
		static bool const is_quat = false;
		static GLM_RELAXED_CONSTEXPR length_t components = 2;
	};

	template <>
	struct type<tvec3>
	{
		static bool const is_vec = true;
		static bool const is_mat = false;
		static bool const is_quat = false;
		static GLM_RELAXED_CONSTEXPR length_t components = 3;
	};

	template <>
	struct type<tvec4>
	{
		static bool const is_vec = true;
		static bool const is_mat = false;
		static bool const is_quat = false;
		static GLM_RELAXED_CONSTEXPR length_t components = 4;
	};

	template <>
	struct type<tmat2x2>
	{
		static bool const is_vec = false;
		static bool const is_mat = true;
		static bool const is_quat = false;
		static GLM_RELAXED_CONSTEXPR length_t components = 2;
	};

	template <>
	struct type<tmat2x3>
	{
		static bool const is_vec = false;
		static bool const is_mat = true;
		static bool const is_quat = false;
		static GLM_RELAXED_CONSTEXPR length_t components = 2;
	};

	template <>
	struct type<tmat2x4>
	{
		static bool const is_vec = false;
		static bool const is_mat = true;
		static bool const is_quat = false;
		static GLM_RELAXED_CONSTEXPR length_t components = 2;
	};

	template <>
	struct type<tmat3x2>
	{
		static bool const is_vec = false;
		static bool const is_mat = true;
		static bool const is_quat = false;
		static GLM_RELAXED_CONSTEXPR length_t components = 3;
		static GLM_RELAXED_CONSTEXPR length_t cols = 3;
		static GLM_RELAXED_CONSTEXPR length_t rows = 2;
	};

	template <>
	struct type<tmat3x3>
	{
		static bool const is_vec = false;
		static bool const is_mat = true;
		static bool const is_quat = false;
		static GLM_RELAXED_CONSTEXPR length_t components = 3;
	};

	template <>
	struct type<tmat3x4>
	{
		static bool const is_vec = false;
		static bool const is_mat = true;
		static bool const is_quat = false;
		static GLM_RELAXED_CONSTEXPR length_t components = 3;
	};

	template <>
	struct type<tmat4x2>
	{
		static bool const is_vec = false;
		static bool const is_mat = true;
		static bool const is_quat = false;
		static GLM_RELAXED_CONSTEXPR length_t components = 4;
	};

	template <>
	struct type<tmat4x3>
	{
		static bool const is_vec = false;
		static bool const is_mat = true;
		static bool const is_quat = false;
		static GLM_RELAXED_CONSTEXPR length_t components = 4;
	};

	template <>
	struct type<tmat4x4>
	{
		static bool const is_vec = false;
		static bool const is_mat = true;
		static bool const is_quat = false;
		static GLM_RELAXED_CONSTEXPR length_t components = 4;
	};

	template <>
	struct type<tquat>
	{
		static bool const is_vec = false;
		static bool const is_mat = false;
		static bool const is_quat = true;
		static GLM_RELAXED_CONSTEXPR length_t components = 4;
	};

	template <>
	struct type<tdualquat>
	{
		static bool const is_vec = false;
		static bool const is_mat = false;
		static bool const is_quat = true;
		static GLM_RELAXED_CONSTEXPR length_t components = 8;
	};

	/// @}
}//namespace glm

#include "type_trait.inl"
