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
/// @file test/gtx/gtx_angle.cpp
/// @date 2015-05-10
/// @author Miroslav Knejp
///////////////////////////////////////////////////////////////////////////////////

#include <glm/gtx/angle.hpp>
#include <glm/gtc/epsilon.hpp>
#include <algorithm>
#include <cstdlib>
#include <ctime>

namespace
{
	const float pi = glm::pi<float>();

	int test_factory()
	{
		int Error(0);
		
		{
			glm::fangle a = glm::rad(0.f);
			Error += glm::epsilonEqual(rad(a), 0.f, 0.01f) ? 0 : 1;
			Error += glm::epsilonEqual(deg(a), 0.f, 0.01f) ? 0 : 1;
		}
		{
			glm::fangle a = glm::deg(0.f);
			Error += glm::epsilonEqual(rad(a), 0.f, 0.01f) ? 0 : 1;
			Error += glm::epsilonEqual(deg(a), 0.f, 0.01f) ? 0 : 1;
		}
		{
			glm::fangle a = glm::rad(pi);
			Error += glm::epsilonEqual(rad(a), pi, 0.01f) ? 0 : 1;
			Error += glm::epsilonEqual(deg(a), 180.f, 0.01f) ? 0 : 1;
		}
		{
			glm::fangle a = glm::deg(180.f);
			Error += glm::epsilonEqual(rad(a), pi, 0.01f) ? 0 : 1;
			Error += glm::epsilonEqual(deg(a), 180.f, 0.01f) ? 0 : 1;
		}
		{
			glm::fangle a = glm::rad(-pi / 2);
			Error += glm::epsilonEqual(rad(a), -pi / 2, 0.01f) ? 0 : 1;
			Error += glm::epsilonEqual(deg(a), -90.f, 0.01f) ? 0 : 1;
		}
		{
			glm::fangle a = glm::deg(-90.f);
			Error += glm::epsilonEqual(rad(a), -pi / 2, 0.01f) ? 0 : 1;
			Error += glm::epsilonEqual(deg(a), -90.f, 0.01f) ? 0 : 1;
		}
		return Error;
	}

	int test_arithmetic()
	{
		int Error(0);
		float x = static_cast<float>(std::max(std::rand(), 1)) / RAND_MAX;
		float y = static_cast<float>(std::max(std::rand(), 1)) / RAND_MAX;
		
		{
			glm::fangle a = glm::rad(x);
			glm::fangle b = glm::rad(y);
			Error += glm::epsilonEqual(x + y, rad(a + b), 0.01f) ? 0 : 1;
			Error += glm::epsilonEqual(x - y, rad(a - b), 0.01f) ? 0 : 1;
		}
		{
			glm::fangle a = glm::rad(x);
			Error += glm::epsilonEqual(y * x, rad(y * a), 0.01f) ? 0 : 1;
			Error += glm::epsilonEqual(x * y, rad(a * y), 0.01f) ? 0 : 1;
		}
		{
			glm::fangle a = glm::rad(x);
			Error += glm::epsilonEqual(x / y, rad(a / y), 0.01f) ? 0 : 1;
		}
		{
			glm::fangle a = glm::rad(x);
			glm::fangle b = glm::rad(y);
			Error += glm::epsilonEqual(x / y, a / b, 0.01f) ? 0 : 1;
		}
		{
			glm::fangle a = glm::rad(x);
			Error += glm::epsilonEqual(+x, rad(+a), 0.01f) ? 0 : 1;
		}
		{
			glm::fangle a = glm::rad(x);
			Error += glm::epsilonEqual(-x, rad(-a), 0.01f) ? 0 : 1;
		}
		
		return Error;
	}
	
	int test_comparison()
	{
		int Error(0);
		float x = -static_cast<float>(std::max(std::rand(), 1)) / RAND_MAX;
		float y = static_cast<float>(std::max(std::rand(), 1)) / RAND_MAX;
		
		Error += glm::rad(x) == glm::rad(x) ? 0 : 1;
		Error += glm::rad(x) == glm::rad(y) ? 1 : 0;
		Error += glm::rad(x) != glm::rad(x) ? 1 : 0;
		Error += glm::rad(x) != glm::rad(y) ? 0 : 1;
		
		Error += glm::rad(x) < glm::rad(x) ? 1 : 0;
		Error += glm::rad(x) < glm::rad(y) ? 0 : 1;
		
		Error += glm::rad(x) > glm::rad(x) ? 1 : 0;
		Error += glm::rad(y) > glm::rad(x) ? 0 : 1;
		
		Error += glm::rad(x) <= glm::rad(x) ? 0 : 1;
		Error += glm::rad(x) <= glm::rad(y) ? 0 : 1;
		
		Error += glm::rad(x) >= glm::rad(x) ? 0 : 1;
		Error += glm::rad(y) >= glm::rad(x) ? 0 : 1;
		return Error;
	}

	int test_constexpr()
	{
		int Error(0);
		
#	if GLM_HAS_CONSTEXPR
		static_assert(std::is_literal_type<glm::fangle>::value, "");
		static_assert(std::is_literal_type<glm::angled>::value, "");
		
		constexpr auto a = glm::deg(1.f);
		constexpr auto b = glm::rad(2.f);
		constexpr auto f = 3.f;
		
		// Force compile-time evaluation
		static_assert((rad(a), true), "");
		static_assert((deg(a), true), "");
		
		static_assert((+a, true), "");
		static_assert((-a, true), "");
		
		static_assert((a + b, true), "");
		static_assert((a - b, true), "");
		static_assert((a * f, true), "");
		static_assert((f * b, true), "");
		static_assert((a / f, true), "");
		static_assert((a / b, true), "");
		
		static_assert((a == b) || true, "");
		static_assert((a != b) || true, "");
		static_assert((a <= b) || true, "");
		static_assert((a >= b) || true, "");
		static_assert((a < b) || true, "");
		static_assert((a > b) || true, "");
#	endif
		
		return Error;
	}
	
	int test_common()
	{
		int Error(0);
	
		float x = static_cast<float>(std::max(std::rand(), 1)) / RAND_MAX;
		float y = static_cast<float>(std::max(std::rand(), 1)) / RAND_MAX;
		float f = static_cast<float>(std::max(std::rand(), 1)) / RAND_MAX;
		{
			glm::fangle a = glm::rad(x);
			glm::fangle b = glm::rad(-x);
			Error += glm::epsilonEqual(x, rad(abs(b)), 0.01f) ? 0 : 1;
			Error += glm::epsilonEqual(rad(a), rad(abs(b)), 0.01f) ? 0 : 1;
		}
		{
			glm::fangle a = glm::rad(100.f);
			glm::fangle b = glm::rad(200.f);
			glm::fangle c = a - glm::rad(x);
			glm::fangle d = b + glm::rad(y);
			glm::fangle e = glm::rad(150.f);
			Error += clamp(c, a, b) <= b ? 0 : 1;
			Error += clamp(c, a, b) >= a ? 0 : 1;
			Error += clamp(d, a, b) <= b ? 0 : 1;
			Error += clamp(d, a, b) >= a ? 0 : 1;
			Error += glm::epsilonEqual(rad(clamp(e, a, b)), rad(e), 0.01f) ? 0 : 1;
		}
		{
			glm::fangle a = glm::rad(x);
			glm::fangle b = glm::rad(y);
			Error += glm::epsilonEqual(std::max(x, y), rad(max(a, b)), 0.01f) ? 0 : 1;
			Error += glm::epsilonEqual(std::min(x, y), rad(min(a, b)), 0.01f) ? 0 : 1;
		}
		{
			glm::fangle a = glm::rad(x);
			glm::fangle b = glm::rad(y);
			Error += glm::epsilonEqual(glm::mix(x, y, f), rad(mix(a, b, f)), 0.01f) ? 0 : 1;
			Error += glm::epsilonEqual(x, rad(mix(a, b, false)), 0.01f) ? 0 : 1;
			Error += glm::epsilonEqual(y, rad(mix(a, b, true)), 0.01f) ? 0 : 1;
		}
		{
			glm::fangle a = glm::rad(x);
			glm::fangle b = glm::rad(y);
			Error += glm::epsilonEqual(glm::mod(x, y), rad(mod(a, b)), 0.01f) ? 0 : 1;
			Error += glm::epsilonEqual(glm::mod(y, x), rad(mod(b, a)), 0.01f) ? 0 : 1;
		}
		{
			Error += glm::epsilonEqual(1.f, sign(glm::rad(10.f)), 0.01f) ? 0 : 1;
			Error += glm::epsilonEqual(0.f, sign(glm::rad(0.f)), 0.01f) ? 0 : 1;
			Error += glm::epsilonEqual(-1.f, sign(glm::rad(-10.f)), 0.01f) ? 0 : 1;
			
			Error += glm::epsilonEqual(1.f, sign(glm::deg(10.f)), 0.01f) ? 0 : 1;
			Error += glm::epsilonEqual(0.f, sign(glm::deg(0.f)), 0.01f) ? 0 : 1;
			Error += glm::epsilonEqual(-1.f, sign(glm::deg(-10.f)), 0.01f) ? 0 : 1;
		}
		return Error;
	}
	
	int test_special()
	{
		int Error(0);
		
		{
			glm::fangle a = glm::rad(5 * pi);
			Error += glm::epsilonEqual(pi, rad(normalize(a)), 0.01f) ? 0 : 1;
		}
		{
			glm::fangle a = glm::rad(2 * pi);
			Error += glm::epsilonEqual(0.f, rad(normalize(a)), 0.01f) ? 0 : 1;
		}
		{
			glm::fangle a = glm::rad(-pi / 2);
			Error += glm::epsilonEqual(1.5f * pi, rad(normalize(a)), 0.01f) ? 0 : 1;
		}
		{
			glm::fangle a = glm::rad(-pi * 2);
			Error += glm::epsilonEqual(0.f, rad(normalize(a)), 0.01f) ? 0 : 1;
		}
		{
			glm::fangle a = glm::rad(5 * -pi);
			Error += glm::epsilonEqual(pi, rad(normalize(a)), 0.01f) ? 0 : 1;
		}
	
		{
			glm::fangle a = glm::deg(0.f);
			glm::fangle b = glm::deg(90.f);
			Error += glm::epsilonEqual(90.f, deg(distance(a, b)), 0.01f) ? 0 : 1;
			Error += glm::epsilonEqual(-90.f, deg(distance(b, a)), 0.01f) ? 0 : 1;
		}
		{
			glm::fangle a = glm::deg(0.f);
			glm::fangle b = glm::deg(180.f);
			Error += glm::epsilonEqual(180.f, deg(distance(a, b)), 0.01f) ? 0 : 1;
			Error += glm::epsilonEqual(-180.f, deg(distance(b, a)), 0.01f) ? 0 : 1;
		}
		{
			glm::fangle a = glm::deg(0.f);
			glm::fangle b = glm::deg(270.f);
			Error += glm::epsilonEqual(-90.f, deg(distance(a, b)), 0.01f) ? 0 : 1;
			Error += glm::epsilonEqual(90.f, deg(distance(b, a)), 0.01f) ? 0 : 1;
		}
		{
			glm::fangle a = glm::deg(0.f);
			glm::fangle b = glm::deg(360.f);
			Error += glm::epsilonEqual(0.f, deg(distance(a, b)), 0.01f) ? 0 : 1;
			Error += glm::epsilonEqual(0.f, deg(distance(b, a)), 0.01f) ? 0 : 1;
		}
		{
			glm::fangle a = glm::deg(10.f);
			glm::fangle b = glm::deg(350.f);
			Error += glm::epsilonEqual(-20.f, deg(distance(a, b)), 0.01f) ? 0 : 1;
			Error += glm::epsilonEqual(20.f, deg(distance(b, a)), 0.01f) ? 0 : 1;
		}

		return Error;
	}

	int test_trigonometric()
	{
		int Error(0);
		
		float x = static_cast<float>(std::rand());
		float y = static_cast<float>(std::rand());

		{
			glm::fangle a = glm::rad(x);
			Error += glm::epsilonEqual(std::cos(x), cos(a), 0.0001f) ? 0 : 1;
			Error += glm::epsilonEqual(std::sin(x), sin(a), 0.0001f) ? 0 : 1;
			Error += glm::epsilonEqual(std::tan(x), tan(a), 0.0001f) ? 0 : 1;
		}
		Error += glm::epsilonEqual(std::atan2(y, x), rad(glm::atan2(y, x)), 0.0001f) ? 0 : 1;
		Error += glm::epsilonEqual(std::atan2(y, x), rad(glm::atan2(glm::vec2(x, y))), 0.0001f) ? 0 : 1;
		
		return Error;
	}
}

int main()
{
	int Error(0);
	std::srand(std::time(NULL));
	
	Error += test_factory();
	Error += test_comparison();
	Error += test_arithmetic();
	Error += test_constexpr();
	Error += test_common();
	Error += test_special();
	Error += test_trigonometric();

	return Error;
}
