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
/// @file test/gtx/gtx_log_base.cpp
/// @date 2013-10-25 / 2014-11-25
/// @author Christophe Riccio
///////////////////////////////////////////////////////////////////////////////////

#include <glm/gtx/log_base.hpp>
#include <glm/gtc/vec1.hpp>
#include <glm/gtc/epsilon.hpp>
#include <glm/exponential.hpp>

namespace test_log
{
	int run()
	{
		int Error = 0;

		{
			float A = glm::log(10.f, 2.0f);
			float B = glm::log2(10.f);
			Error += glm::epsilonEqual(A, B, 0.00001f) ? 0 : 1;
		}

		{
			glm::vec1 A = glm::log(glm::vec1(10.f), glm::vec1(2.0f));
			glm::vec1 B = glm::log2(glm::vec1(10.f));
			Error += glm::all(glm::epsilonEqual(A, B, glm::vec1(0.00001f))) ? 0 : 1;
		}

		{
			glm::vec2 A = glm::log(glm::vec2(10.f), glm::vec2(2.0f));
			glm::vec2 B = glm::log2(glm::vec2(10.f));
			Error += glm::all(glm::epsilonEqual(A, B, glm::vec2(0.00001f))) ? 0 : 1;
		}

		{
			glm::vec3 A = glm::log(glm::vec3(10.f), glm::vec3(2.0f));
			glm::vec3 B = glm::log2(glm::vec3(10.f));
			Error += glm::all(glm::epsilonEqual(A, B, glm::vec3(0.00001f))) ? 0 : 1;
		}

		{
			glm::vec4 A = glm::log(glm::vec4(10.f), glm::vec4(2.0f));
			glm::vec4 B = glm::log2(glm::vec4(10.f));
			Error += glm::all(glm::epsilonEqual(A, B, glm::vec4(0.00001f))) ? 0 : 1;
		}

		return Error;
	}
}//namespace test_log

int main()
{
	int Error(0);

	Error += test_log::run();

	return Error;
}
