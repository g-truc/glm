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
/// @file test/gtx/gtx_intersect.cpp
/// @date 2013-10-25 / 2014-11-25
/// @author Christophe Riccio
///////////////////////////////////////////////////////////////////////////////////

#include <glm/gtx/intersect.hpp>

using namespace glm;

int test_LineLine() {
	int Error(0);

	Error += intersectLineLine(vec2(0, 2), vec2(2, 0), vec2(1, 1), vec2(1, 3)) ? 0 : 1;
	Error += intersectLineLine(vec2(-1, -1), vec2(1, 1), vec2(1, -1), vec2(-1, 1)) ? 0 : 1;
	Error += intersectLineLine(vec2(-1, -1), vec2(1, 1), vec2(-1, 1), vec2(1, -1)) ? 0 : 1;
	Error += !intersectLineLine(vec2(-1, 1), vec2(1, 1), vec2(-1, -1), vec2(1, -1)) ? 0 : 1;
	Error += !intersectLineLine(vec2(-1, 1), vec2(1, 1), vec2(0, 0), vec2(0, -1)) ? 0 : 1;

	return Error;
}

int test_LineLineProper() {
	int Error(0);

	Error += !intersectLineLineProper(vec2(0, 2), vec2(2, 0), vec2(1, 1), vec2(1, 3)) ? 0 : 1;
	Error += intersectLineLineProper(vec2(-1, -1), vec2(1, 1), vec2(1, -1), vec2(-1, 1)) ? 0 : 1;
	Error += intersectLineLineProper(vec2(-1, -1), vec2(1, 1), vec2(-1, 1), vec2(1, -1)) ? 0 : 1;
	Error += !intersectLineLineProper(vec2(-1, 1), vec2(1, 1), vec2(-1, -1), vec2(1, -1)) ? 0 : 1;
	Error += !intersectLineLineProper(vec2(-1, 1), vec2(1, 1), vec2(0, 0), vec2(0, -1)) ? 0 : 1;

	return Error;
}

int test_overlapSegment() {
	int Error(0);

	Error += !overlapSegment(vec2(0, 1), vec2(2, 1), vec2(1, 1), vec2(1, 2)) ? 0 : 1;
	Error += !overlapSegment(vec2(0, 1), vec2(2, 1), vec2(1, 2), vec2(1, 1)) ? 0 : 1;
	Error += !overlapSegment(vec2(0, 0), vec2(0, 1), vec2(0, 1), vec2(0, 2)) ? 0 : 1;
	Error += overlapSegment(vec2(0, 0), vec2(0, 1), vec2(0, 0.5), vec2(0, 2)) ? 0 : 1;
	Error += overlapSegment(vec2(0.5, 1), vec2(2, 2.5), vec2(1, 1.5), vec2(1.5, 2)) ? 0 : 1;
	Error += !overlapSegment(vec2(0.5, 1), vec2(2, 2.5), vec2(1, 1.51), vec2(1.5, 2)) ? 0 : 1;

	return Error;
}

int main()
{
	int Error(0);

	Error += test_LineLine();
	Error += test_LineLineProper();
	Error += test_overlapSegment();

	return Error;
}
