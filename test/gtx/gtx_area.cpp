///////////////////////////////////////////////////////////////////////////////////
/// OpenGL Mathematics (glm.g-truc.net)
///
/// Copyright (c) 2015 G-Truc Creation (www.g-truc.net)
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
///   By making use of the Software for military purposes, you choose to make
///   a Bunny unhappy.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
/// THE SOFTWARE.
///
/// @file test/gtx/gtx_area.cpp
/// @date 2015-09-27
/// @author Jesse Talavera-Greenberg
///////////////////////////////////////////////////////////////////////////////////

#include <glm/gtx/area.hpp>
#include <glm/vec2.hpp>
#include <glm/gtc/epsilon.hpp>

using namespace glm;

const float EPSILON = epsilon<float>();

int test_triangle_area_zero() {
	int Error(0);

	vec2 a(0, 0), b(0, 0), c(0, 0);

	Error += epsilonEqual(area(a, b, c), 0.0f, EPSILON) ? 0 : 1;

	return Error;
}

int test_triangle_area_clockwise_negative() {
	int Error(0);

	vec2 a(0, 1), b(-1, 0), c(1, 0);
	// Upward-facing triangle at the origin

	Error += epsilonEqual(area(a, c, b), -1.0f, EPSILON) ? 0 : 1;
	Error += epsilonEqual(area(b, a, c), -1.0f, EPSILON) ? 0 : 1;
	Error += epsilonEqual(area(c, b, a), -1.0f, EPSILON) ? 0 : 1;

	return Error;
}

int test_triangle_area_anticlockwise_positive() {
	int Error(0);

	vec2 a(0, 1), b(-1, 0), c(1, 0);

	Error += epsilonEqual(area(a, b, c), 1.0f, EPSILON) ? 0 : 1;
	Error += epsilonEqual(area(b, c, a), 1.0f, EPSILON) ? 0 : 1;
	Error += epsilonEqual(area(c, a, b), 1.0f, EPSILON) ? 0 : 1;

	return Error;
}

int test_triangle_area_collinear() {
	int Error(0);

	vec2 a(-1, 0), b(0, 0), c(1, 0);

	Error += epsilonEqual(area(a, b, c), 0.0f, EPSILON) ? 0 : 1;

	vec2 d(0, -1), e(0, 0), f(0, 1);

	Error += epsilonEqual(area(d, e, f), 0.0f, EPSILON) ? 0 : 1;

	return Error;
}

int test_polygon_area() {
	int Error(0);

	return Error;
}

int main()
{
	int Error(0);

	Error += test_triangle_area_zero();
	Error += test_triangle_area_clockwise_negative();
	Error += test_triangle_area_anticlockwise_positive();
	Error += test_triangle_area_collinear();
	Error += test_polygon_area();

	return Error;
}
