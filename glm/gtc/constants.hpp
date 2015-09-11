///////////////////////////////////////////////////////////////////////////////////
/// OpenGL Mathematics (glm.g-truc.net)
///
/// Copyright (c) 2005 - 2015 G-Truc Creation (www.g-truc.net)
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
/// @ref gtc_constants
/// @file glm/gtc/constants.hpp
/// @date 2011-09-30 / 2012-01-25
/// @author Christophe Riccio
///
/// @see core (dependence)
/// @see gtc_half_float (dependence)
///
/// @defgroup gtc_constants GLM_GTC_constants
/// @ingroup gtc
/// 
/// @brief Provide a list of constants and precomputed useful values.
/// 
/// <glm/gtc/constants.hpp> need to be included to use these features.
///////////////////////////////////////////////////////////////////////////////////

#pragma once

// Dependencies
#include "../detail/setup.hpp"

#if(defined(GLM_MESSAGES) && !defined(GLM_EXT_INCLUDED))
#	pragma message("GLM: GLM_GTC_constants extension included")
#endif

namespace glm
{
	/// @addtogroup gtc_constants
	/// @{

	/// Return the epsilon constant for floating point types.
	/// @see gtc_constants
	template <typename genType>
	GLM_FUNC_DECL GLM_CONSTEXPR genType epsilon() GLM_NOEXCEPT;

	/// Return 0.
	/// @see gtc_constants
	template <typename genType>
	GLM_FUNC_DECL GLM_CONSTEXPR genType zero() GLM_NOEXCEPT;

	/// Return 1.
	/// @see gtc_constants
	template <typename genType>
	GLM_FUNC_DECL GLM_CONSTEXPR genType one() GLM_NOEXCEPT;

	/// Return the pi constant.
	/// @see gtc_constants
	template <typename genType>
	GLM_FUNC_DECL GLM_CONSTEXPR genType pi() GLM_NOEXCEPT;

	/// Return pi * 2.
	/// @see gtc_constants
	template <typename genType>
	GLM_FUNC_DECL GLM_CONSTEXPR genType two_pi() GLM_NOEXCEPT;

	/// Return square root of pi.
	/// @see gtc_constants
	template <typename genType>
	GLM_FUNC_DECL GLM_CONSTEXPR genType root_pi() GLM_NOEXCEPT;

	/// Return pi / 2.
	/// @see gtc_constants
	template <typename genType>
	GLM_FUNC_DECL GLM_CONSTEXPR genType half_pi() GLM_NOEXCEPT;

	/// Return pi / 2 * 3.
	/// @see gtc_constants
	template <typename genType>
	GLM_FUNC_DECL GLM_CONSTEXPR genType three_over_two_pi() GLM_NOEXCEPT;

	/// Return pi / 4.
	/// @see gtc_constants
	template <typename genType>
	GLM_FUNC_DECL GLM_CONSTEXPR genType quarter_pi() GLM_NOEXCEPT;

	/// Return 1 / pi.
	/// @see gtc_constants
	template <typename genType>
	GLM_FUNC_DECL GLM_CONSTEXPR genType one_over_pi() GLM_NOEXCEPT;

	/// Return 1 / (pi * 2).
	/// @see gtc_constants
	template <typename genType>
	GLM_FUNC_DECL GLM_CONSTEXPR genType one_over_two_pi() GLM_NOEXCEPT;

	/// Return 2 / pi.
	/// @see gtc_constants
	template <typename genType>
	GLM_FUNC_DECL GLM_CONSTEXPR genType two_over_pi() GLM_NOEXCEPT;

	/// Return 4 / pi.
	/// @see gtc_constants
	template <typename genType>
	GLM_FUNC_DECL GLM_CONSTEXPR genType four_over_pi() GLM_NOEXCEPT;

	/// Return 2 / sqrt(pi).
	/// @see gtc_constants
	template <typename genType>
	GLM_FUNC_DECL GLM_CONSTEXPR genType two_over_root_pi() GLM_NOEXCEPT;

	/// Return 1 / sqrt(2).
	/// @see gtc_constants
	template <typename genType>
	GLM_FUNC_DECL GLM_CONSTEXPR genType one_over_root_two() GLM_NOEXCEPT;

	/// Return sqrt(pi / 2).
	/// @see gtc_constants
	template <typename genType>
	GLM_FUNC_DECL GLM_CONSTEXPR genType root_half_pi() GLM_NOEXCEPT;

	/// Return sqrt(2 * pi).
	/// @see gtc_constants
	template <typename genType>
	GLM_FUNC_DECL GLM_CONSTEXPR genType root_two_pi() GLM_NOEXCEPT;

	/// Return sqrt(ln(4)).
	/// @see gtc_constants
	template <typename genType>
	GLM_FUNC_DECL GLM_CONSTEXPR genType root_ln_four() GLM_NOEXCEPT;

	/// Return e constant.
	/// @see gtc_constants
	template <typename genType>
	GLM_FUNC_DECL GLM_CONSTEXPR genType e() GLM_NOEXCEPT;

	/// Return Euler's constant.
	/// @see gtc_constants
	template <typename genType>
	GLM_FUNC_DECL GLM_CONSTEXPR genType euler() GLM_NOEXCEPT;

	/// Return sqrt(2).
	/// @see gtc_constants
	template <typename genType>
	GLM_FUNC_DECL GLM_CONSTEXPR genType root_two() GLM_NOEXCEPT;

	/// Return sqrt(3).
	/// @see gtc_constants
	template <typename genType>
	GLM_FUNC_DECL GLM_CONSTEXPR genType root_three() GLM_NOEXCEPT;

	/// Return sqrt(5).
	/// @see gtc_constants
	template <typename genType>
	GLM_FUNC_DECL GLM_CONSTEXPR genType root_five() GLM_NOEXCEPT;

	/// Return ln(2).
	/// @see gtc_constants
	template <typename genType>
	GLM_FUNC_DECL GLM_CONSTEXPR genType ln_two() GLM_NOEXCEPT;

	/// Return ln(10).
	/// @see gtc_constants
	template <typename genType>
	GLM_FUNC_DECL GLM_CONSTEXPR genType ln_ten() GLM_NOEXCEPT;

	/// Return ln(ln(2)).
	/// @see gtc_constants
	template <typename genType>
	GLM_FUNC_DECL GLM_CONSTEXPR genType ln_ln_two() GLM_NOEXCEPT;

	/// Return 1 / 3.
	/// @see gtc_constants
	template <typename genType>
	GLM_FUNC_DECL GLM_CONSTEXPR genType third() GLM_NOEXCEPT;

	/// Return 2 / 3.
	/// @see gtc_constants
	template <typename genType>
	GLM_FUNC_DECL GLM_CONSTEXPR genType two_thirds() GLM_NOEXCEPT;

	/// Return the golden ratio constant.
	/// @see gtc_constants
	template <typename genType>
	GLM_FUNC_DECL GLM_CONSTEXPR genType golden_ratio() GLM_NOEXCEPT;

	/// @}
} //namespace glm

#include "constants.inl"
