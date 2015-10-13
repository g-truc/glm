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
/// @file test/core/core_type_vec1.cpp
/// @date 2014-10-11 / 2014-11-25
/// @author Christophe Riccio
///////////////////////////////////////////////////////////////////////////////////

#if !(GLM_COMPILER & GLM_COMPILER_GCC)
#	define GLM_META_PROG_HELPERS
#endif
#define GLM_STATIC_CONST_MEMBERS
#define GLM_SWIZZLE
#include <glm/vector_relational.hpp>
#include <glm/gtc/vec1.hpp>
#include <vector>

int test_vec1_operators()
{
	int Error(0);

	glm::vec1 A(1.0f);
	glm::vec1 B(1.0f);
	{
		bool R = A != B;
		bool S = A == B;

		Error += (S && !R) ? 0 : 1;
	}

	{
		A *= 1.0f;
		B *= 1.0;
		A += 1.0f;
		B += 1.0;

		bool R = A != B;
		bool S = A == B;

		Error += (S && !R) ? 0 : 1;
	}

	return Error;
}

int test_vec1_ctor()
{
	int Error = 0;

#	if GLM_HAS_TRIVIAL_QUERIES
	//	Error += std::is_trivially_default_constructible<glm::vec1>::value ? 0 : 1;
	//	Error += std::is_trivially_copy_assignable<glm::vec1>::value ? 0 : 1;
		Error += std::is_trivially_copyable<glm::vec1>::value ? 0 : 1;
		Error += std::is_trivially_copyable<glm::dvec1>::value ? 0 : 1;
		Error += std::is_trivially_copyable<glm::ivec1>::value ? 0 : 1;
		Error += std::is_trivially_copyable<glm::uvec1>::value ? 0 : 1;

		Error += std::is_copy_constructible<glm::vec1>::value ? 0 : 1;
#	endif

/*
#if GLM_HAS_INITIALIZER_LISTS
	{
		glm::vec1 a{ 0 };
		std::vector<glm::vec1> v = {
			{0.f},
			{4.f},
			{8.f}};
	}

	{
		glm::dvec2 a{ 0 };
		std::vector<glm::dvec1> v = {
			{0.0},
			{4.0},
			{8.0}};
	}
#endif
*/
#if GLM_HAS_ANONYMOUS_UNION && defined(GLM_SWIZZLE)
	{
		glm::vec2 A = glm::vec2(1.0f, 2.0f);
		glm::vec2 B = A.xy;
		glm::vec2 C(A.xy);
		glm::vec2 D(A.xy());

		Error += glm::all(glm::equal(A, B)) ? 0 : 1;
		Error += glm::all(glm::equal(A, C)) ? 0 : 1;
		Error += glm::all(glm::equal(A, D)) ? 0 : 1;
	}
#endif// GLM_HAS_ANONYMOUS_UNION && defined(GLM_SWIZZLE)

	{
		glm::vec2 A = glm::vec2(2.0f);
		glm::vec2 B = glm::vec2(2.0f, 3.0f);
		glm::vec2 C = glm::vec2(2.0f, 3.0);
		//glm::vec2 D = glm::dvec2(2.0); // Build error TODO: What does the specification says?
		glm::vec2 E(glm::dvec2(2.0));
		glm::vec2 F(glm::ivec2(2));
	}

	return Error;
}

int test_vec1_size()
{
	int Error = 0;
	
	Error += sizeof(glm::vec1) == sizeof(glm::mediump_vec1) ? 0 : 1;
	Error += 4 == sizeof(glm::mediump_vec1) ? 0 : 1;
	Error += sizeof(glm::dvec1) == sizeof(glm::highp_dvec1) ? 0 : 1;
	Error += 8 == sizeof(glm::highp_dvec1) ? 0 : 1;
	Error += glm::vec1().length() == 1 ? 0 : 1;
	Error += glm::dvec1().length() == 1 ? 0 : 1;
	Error += glm::vec1::components == 1 ? 0 : 1;
	
	return Error;
}

int test_vec1_operator_increment()
{
	int Error(0);

	glm::ivec1 v0(1);
	glm::ivec1 v1(v0);
	glm::ivec1 v2(v0);
	glm::ivec1 v3 = ++v1;
	glm::ivec1 v4 = v2++;

	Error += glm::all(glm::equal(v0, v4)) ? 0 : 1;
	Error += glm::all(glm::equal(v1, v2)) ? 0 : 1;
	Error += glm::all(glm::equal(v1, v3)) ? 0 : 1;

	int i0(1);
	int i1(i0);
	int i2(i0);
	int i3 = ++i1;
	int i4 = i2++;

	Error += i0 == i4 ? 0 : 1;
	Error += i1 == i2 ? 0 : 1;
	Error += i1 == i3 ? 0 : 1;

	return Error;
}

int test_vec1_static_const() {
	int Error = 0;

	Error += (glm::vec1(1.0f) == glm::vec1::X) ? 0 : 1;
	Error += (glm::ivec1(1) == glm::ivec1::X) ? 0 : 1;
	Error += (glm::dvec1(1.0) == glm::dvec1::X) ? 0 : 1;
	Error += (glm::bvec1(false) == glm::bvec1::ZERO) ? 0 : 1;
	Error += (glm::uvec1(0) == glm::uvec1::ZERO) ? 0 : 1;

	return Error;
}

int main()
{
	int Error = 0;

	glm::vec1 v;
	assert(v.length() == 1);

#	ifdef GLM_META_PROG_HELPERS
		assert(glm::vec1::components == glm::vec1().length());
		assert(glm::vec1::components == 1);
#	endif

	Error += test_vec1_static_const();
	Error += test_vec1_size();
	Error += test_vec1_ctor();
	Error += test_vec1_operators();
	Error += test_vec1_operator_increment();
	
	return Error;
}
