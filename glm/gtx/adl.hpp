///////////////////////////////////////////////////////////////////////////////////
/// OpenGL Mathematics (glm.g-truc.net)
///
/// Copyright (c) 2005 - 2014 G-Truc Creation (www.g-truc.net)
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
/// @ref gtx_adl
/// @file gtx/adl.hpp
/// @date 2014-09-19 / 2014-09-19
/// @author Joshua Moerman
///
/// @brief Allows to call glm functions without the need of fully qualifying
/// the name
///
///////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "../trigonometric.hpp"
#include "../exponential.hpp"
#include "../common.hpp"
#include "../geometric.hpp"
#include "../matrix.hpp"
#include "../vector_relational.hpp"

namespace glm {
	namespace detail {
		using glm::radians;
		using glm::degrees;
		using glm::sin;
		using glm::cos;
		using glm::tan;
		using glm::asin;
		using glm::acos;
		using glm::atan;
		using glm::sinh;
		using glm::cosh;
		using glm::tanh;
		using glm::asinh;
		using glm::acosh;
		using glm::atanh;

		using glm::pow;
		using glm::exp;
		using glm::log;
		using glm::exp2;
		using glm::log2;
		using glm::sqrt;
		using glm::inversesqrt;

		using glm::abs;
		using glm::sign;
		using glm::floor;
		using glm::trunc;
		using glm::round;
		using glm::roundEven;
		using glm::ceil;
		using glm::fract;
		using glm::mod;
		using glm::modf;
		using glm::min;
		using glm::max;
		using glm::clamp;
		using glm::step;
		using glm::smoothstep;
		using glm::isnan;
		using glm::isinf;
		using glm::floatBitsToInt;
		using glm::floatBitsToUint;
		using glm::intBitsToFloat;
		using glm::uintBitsToFloat;
		using glm::fma;
		using glm::frexp;
		using glm::ldexp;

		using glm::length;
		using glm::distance;
		using glm::dot;
		using glm::cross;
		using glm::normalize;
		using glm::faceforward;
		using glm::reflect;
		using glm::refract;

		using glm::matrixCompMult;
		using glm::outerProduct;
		using glm::transpose;
		using glm::determinant;
		using glm::inverse;

		using glm::lessThan;
		using glm::lessThanEqual;
		using glm::greaterThan;
		using glm::greaterThanEqual;
		using glm::equal;
		using glm::notEqual;
		using glm::any;
		using glm::all;
		using glm::not_;
	}
}
