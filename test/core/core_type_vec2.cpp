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
/// @file test/core/core_type_vec2.cpp
/// @date 2008-08-31 / 2014-11-25
/// @author Christophe Riccio
///////////////////////////////////////////////////////////////////////////////////

#if !(GLM_COMPILER & GLM_COMPILER_GCC)
#	define GLM_META_PROG_HELPERS
#endif
#define GLM_SWIZZLE
#include <glm/vector_relational.hpp>
#include <glm/vec2.hpp>
#include <vector>
#if GLM_HAS_TRIVIAL_QUERIES
#	include <type_traits>
#endif

int test_vec2_operators()
{
	int Error = 0;

	{
		glm::vec2 A(1.0f);
		glm::vec2 B(1.0f);
		Error += A != B ? 1 : 0;
		Error += A == B ? 0 : 1;
	}

	{
		glm::vec2 A(1.0f);
		glm::vec2 C = A + 1.0f;
		A += 1.0f;
		Error += A.x == 2.0f && A.y == 2.0f ? 0 : 1;
		Error += A.x == C.x && A.y == C.y ? 0 : 1;
	}

	{
		glm::vec2 A(1.0f);
		glm::vec2 B(2.0f,-1.0f);
		glm::vec2 C = A + B;
		A += B;
		Error += A.x == 3.0f && A.y == 0.0f ? 0 : 1;
		Error += A.x == C.x && A.y == C.y ? 0 : 1;
	}

	{
		glm::vec2 A(1.0f);
		glm::vec2 C = A - 1.0f;
		A -= 1.0f;
		Error += A.x == 0.0f && A.y == 0.0f ? 0 : 1;
		Error += A.x == C.x && A.y == C.y ? 0 : 1;
	}

	{
		glm::vec2 A(1.0f);
		glm::vec2 B(2.0f,-1.0f);
		glm::vec2 C = A - B;
		A -= B;
		Error += A.x == -1.0f && A.y == 2.0f ? 0 : 1;
		Error += A.x == C.x && A.y == C.y ? 0 : 1;
	}

	{
		glm::vec2 A(1.0f);
		glm::vec2 C = A * 2.0f;
		A *= 2.0f;
		Error += A.x == 2.0f && A.y == 2.0f ? 0 : 1;
		Error += A.x == C.x && A.y == C.y ? 0 : 1;
	}

	{
		glm::vec2 A(2.0f);
		glm::vec2 B(2.0f);
		glm::vec2 C = A / B;
		A /= B;
		Error += A.x == 1.0f && A.y == 1.0f ? 0 : 1;
		Error += A.x == C.x && A.y == C.y ? 0 : 1;
	}

	{
		glm::vec2 A(1.0f, 2.0f);
		glm::vec2 B(4.0f, 5.0f);

		glm::vec2 C = A + B;
		Error += C == glm::vec2(5, 7) ? 0 : 1;

		glm::vec2 D = B - A;
		Error += D == glm::vec2(3, 3) ? 0 : 1;

		glm::vec2 E = A * B;
		Error += E == glm::vec2(4, 10) ? 0 : 1;

		glm::vec2 F = B / A;
		Error += F == glm::vec2(4, 2.5) ? 0 : 1;

		glm::vec2 G = A + 1.0f;
		Error += G == glm::vec2(2, 3) ? 0 : 1;

		glm::vec2 H = B - 1.0f;
		Error += H == glm::vec2(3, 4) ? 0 : 1;

		glm::vec2 I = A * 2.0f;
		Error += I == glm::vec2(2, 4) ? 0 : 1;

		glm::vec2 J = B / 2.0f;
		Error += J == glm::vec2(2, 2.5) ? 0 : 1;

		glm::vec2 K = 1.0f + A;
		Error += K == glm::vec2(2, 3) ? 0 : 1;

		glm::vec2 L = 1.0f - B;
		Error += L == glm::vec2(-3, -4) ? 0 : 1;

		glm::vec2 M = 2.0f * A;
		Error += M == glm::vec2(2, 4) ? 0 : 1;

		glm::vec2 N = 2.0f / B;
		Error += N == glm::vec2(0.5, 2.0 / 5.0) ? 0 : 1;
	}

	{
		glm::vec2 A(1.0f, 2.0f);
		glm::vec2 B(4.0f, 5.0f);

		A += B;
		Error += A == glm::vec2(5, 7) ? 0 : 1;

		A += 1.0f;
		Error += A == glm::vec2(6, 8) ? 0 : 1;
	}
	{
		glm::vec2 A(1.0f, 2.0f);
		glm::vec2 B(4.0f, 5.0f);

		B -= A;
		Error += B == glm::vec2(3, 3) ? 0 : 1;

		B -= 1.0f;
		Error += B == glm::vec2(2, 2) ? 0 : 1;
	}
	{
		glm::vec2 A(1.0f, 2.0f);
		glm::vec2 B(4.0f, 5.0f);

		A *= B;
		Error += A == glm::vec2(4, 10) ? 0 : 1;

		A *= 2.0f;
		Error += A == glm::vec2(8, 20) ? 0 : 1;
	}
	{
		glm::vec2 A(1.0f, 2.0f);
		glm::vec2 B(4.0f, 5.0f);

		B /= A;
		Error += B == glm::vec2(4, 2.5) ? 0 : 1;

		B /= 2.0f;
		Error += B == glm::vec2(2, 1.25) ? 0 : 1;
	}
	{
		glm::vec2 B(2.0f);

		B /= B.y;
		Error += B == glm::vec2(1.0f) ? 0 : 1;
	}

	{
		glm::vec2 A(1.0f, 2.0f);
		glm::vec2 B = -A;
		Error += B == glm::vec2(-1.0f, -2.0f) ? 0 : 1;
	}

	{
		glm::vec2 A(1.0f, 2.0f);
		glm::vec2 B = --A;
		Error += B == glm::vec2(0.0f, 1.0f) ? 0 : 1;
	}

	{
		glm::vec2 A(1.0f, 2.0f);
		glm::vec2 B = A--;
		Error += B == glm::vec2(1.0f, 2.0f) ? 0 : 1;
		Error += A == glm::vec2(0.0f, 1.0f) ? 0 : 1;
	}

	{
		glm::vec2 A(1.0f, 2.0f);
		glm::vec2 B = ++A;
		Error += B == glm::vec2(2.0f, 3.0f) ? 0 : 1;
	}

	{
		glm::vec2 A(1.0f, 2.0f);
		glm::vec2 B = A++;
		Error += B == glm::vec2(1.0f, 2.0f) ? 0 : 1;
		Error += A == glm::vec2(2.0f, 3.0f) ? 0 : 1;
	}

	return Error;
}

int test_vec2_ctor()
{
	int Error = 0;

#	if GLM_HAS_TRIVIAL_QUERIES
	//	Error += std::is_trivially_default_constructible<glm::vec2>::value ? 0 : 1;
	//	Error += std::is_trivially_copy_assignable<glm::vec2>::value ? 0 : 1;
		Error += std::is_trivially_copyable<glm::vec2>::value ? 0 : 1;
		Error += std::is_trivially_copyable<glm::dvec2>::value ? 0 : 1;
		Error += std::is_trivially_copyable<glm::ivec2>::value ? 0 : 1;
		Error += std::is_trivially_copyable<glm::uvec2>::value ? 0 : 1;

		Error += std::is_copy_constructible<glm::vec2>::value ? 0 : 1;
#	endif

#if GLM_HAS_INITIALIZER_LISTS
	{
		glm::vec2 a{ 0, 1 };
		std::vector<glm::vec2> v = {
			{0, 1},
			{4, 5},
			{8, 9}};
	}

	{
		glm::dvec2 a{ 0, 1 };
		std::vector<glm::dvec2> v = {
			{0, 1},
			{4, 5},
			{8, 9}};
	}
#endif

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

int test_vec2_size()
{
	int Error = 0;

	Error += sizeof(glm::vec2) == sizeof(glm::mediump_vec2) ? 0 : 1;
	Error += 8 == sizeof(glm::mediump_vec2) ? 0 : 1;
	Error += sizeof(glm::dvec2) == sizeof(glm::highp_dvec2) ? 0 : 1;
	Error += 16 == sizeof(glm::highp_dvec2) ? 0 : 1;
	Error += glm::vec2().length() == 2 ? 0 : 1;
	Error += glm::dvec2().length() == 2 ? 0 : 1;
	Error += glm::vec2::components == 2 ? 0 : 1;

	return Error;
}

int test_operator_increment()
{
	int Error(0);

	glm::ivec2 v0(1);
	glm::ivec2 v1(v0);
	glm::ivec2 v2(v0);
	glm::ivec2 v3 = ++v1;
	glm::ivec2 v4 = v2++;

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

int main()
{
	int Error = 0;

	glm::vec2 v;
	assert(v.length() == 2);

#	ifdef GLM_META_PROG_HELPERS
		assert(glm::vec2::components == glm::vec2().length());
		assert(glm::vec2::components == 2);
#	endif

	Error += test_vec2_size();
	Error += test_vec2_ctor();
	Error += test_vec2_operators();
	Error += test_operator_increment();

	return Error;
}
