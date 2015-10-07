///////////////////////////////////////////////////////////////////////////////////
/// OpenGL Mathematics (glm.g-truc.net)
///
/// Copyright (c) 2005 - 2012 G-Truc Creation (www.g-truc.net)
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
/// @file test/gtx/gtx_vector_query.cpp
/// @date 2011-11-23 / 2014-11-25
/// @author Christophe Riccio
///////////////////////////////////////////////////////////////////////////////////

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/gtx/vector_query.hpp>

using namespace glm;

int test_areCollinear()
{
	int Error(0);

	{
		bool TestA = glm::areCollinear(glm::vec2(-1), glm::vec2(1), 0.00001f);
		Error += TestA ? 0 : 1;
	}

	{
		bool TestA = glm::areCollinear(glm::vec3(-1), glm::vec3(1), 0.00001f);
		Error += TestA ? 0 : 1;
	}

	{
		bool TestA = glm::areCollinear(glm::vec4(-1), glm::vec4(1), 0.00001f);
		Error += TestA ? 0 : 1;
	}

	{
		bool TestA = glm::areCollinear(glm::vec2(0, 0), glm::vec2(1, 1), glm::vec2(2, 2));
		Error += TestA ? 0 : 1;
	}

	{
		bool TestA = glm::areCollinear(glm::vec2(0, 0), glm::vec2(1, 1), glm::vec2(4, 2));
		Error += !TestA ? 0 : 1;
	}

	return Error;
}

int test_areOrthogonal()
{
	int Error(0);
	
	bool TestA = glm::areOrthogonal(glm::vec2(1, 0), glm::vec2(0, 1), 0.00001f);
	Error += TestA ? 0 : 1;

	return Error;
}

int test_isNormalized()
{
	int Error(0);
	
	bool TestA = glm::isNormalized(glm::vec4(1, 0, 0, 0), 0.00001f);
	Error += TestA ? 0 : 1;

	return Error;
}

int test_isNull()
{
	int Error(0);
	
	bool TestA = glm::isNull(glm::vec4(0), 0.00001f);
	Error += TestA ? 0 : 1;

	return Error;
}

int test_areOrthonormal()
{
	int Error(0);

	bool TestA = glm::areOrthonormal(glm::vec2(1, 0), glm::vec2(0, 1), 0.00001f);
	Error += TestA ? 0 : 1;

	return Error;
}

int test_isLeft()
{
	int Error(0);

	Error += isLeft(vec2(1, 1), vec2(2.5, 2), vec2(1.305, 3.062)) ? 0 : 1;
	Error += isLeft(vec2(1.278, 1.176), vec2(0.734, 2.257), vec2(0.5, 1.5)) ? 0 : 1;
	Error += isLeft(vec2(1.183, 1.326), vec2(0.923, 0.695), vec2(2, 0)) ? 0 : 1;
	Error += !isLeft(vec2(0.923, 0.695), vec2(1.183, 1.326), vec2(2, 0)) ? 0 : 1;
	Error += isLeft(vec2(0, 0), vec2(1, 0), vec2(-1, 1)) ? 0 : 1;
	return Error;
}

int test_isLeftOrOn()
{
	int Error(0);

	Error += isLeftOrOn(vec2(0, 2), vec2(2, 0), vec2(1, 1)) ? 0 : 1;
	Error += isLeftOrOn(vec2(0, 2), vec2(2, 0), vec2(2, 2)) ? 0 : 1;
	Error += isLeftOrOn(ivec2(0, 2), ivec2(2, 0), ivec2(0, 5)) ? 0 : 1;
	Error += isLeftOrOn(dvec2(0, 2), dvec2(2, 0), dvec2(-1, 5)) ? 0 : 1;
	Error += !isLeftOrOn(vec2(0, 2), vec2(2, 0), vec2(0, 0)) ? 0 : 1;

	return Error;
}

int main()
{
	int Error(0);

	Error += test_areCollinear();
	Error += test_areOrthogonal();
	Error += test_isNormalized();
	Error += test_isNull();
	Error += test_areOrthonormal();
	Error += test_isLeft();
	Error += test_isLeftOrOn();

	return Error;
}


