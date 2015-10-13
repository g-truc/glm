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
/// @file test/gtx/gtx_type_aligned.cpp
/// @date 2014-11-23 / 2014-11-25
/// @author Christophe Riccio
///////////////////////////////////////////////////////////////////////////////////

#include <glm/gtx/type_aligned.hpp>
#include <cstdio>

int test_decl()
{
	int Error(0);

	{
		struct S1
		{
			glm::aligned_vec4 B;
		};

		struct S2
		{
			glm::vec4 B;
		};

		printf("vec4 - Aligned: %d, unaligned: %d\n", static_cast<int>(sizeof(S1)), static_cast<int>(sizeof(S2)));

		Error += sizeof(S1) >= sizeof(S2) ? 0 : 1;
	}

	{
		struct S1
		{
			bool A;
			glm::vec3 B;
		};

		struct S2
		{
			bool A;
			glm::aligned_vec3 B;
		};

		printf("vec3 - Aligned: %d, unaligned: %d\n", static_cast<int>(sizeof(S1)), static_cast<int>(sizeof(S2)));

		Error += sizeof(S1) <= sizeof(S2) ? 0 : 1;
	}

	{
		struct S1
		{
			bool A;
			glm::aligned_vec4 B;
		};

		struct S2
		{
			bool A;
			glm::vec4 B;
		};

		printf("vec4 - Aligned: %d, unaligned: %d\n", static_cast<int>(sizeof(S1)), static_cast<int>(sizeof(S2)));

		Error += sizeof(S1) >= sizeof(S2) ? 0 : 1;
	}

	{
		struct S1
		{
			bool A;
			glm::aligned_dvec4 B;
		};

		struct S2
		{
			bool A;
			glm::dvec4 B;
		};

		printf("dvec4 - Aligned: %d, unaligned: %d\n", static_cast<int>(sizeof(S1)), static_cast<int>(sizeof(S2)));

		Error += sizeof(S1) >= sizeof(S2) ? 0 : 1;
	}

	return Error;
}

template <typename genType>
void print(genType const & Mat0)
{
	printf("mat4(\n");
	printf("\tvec4(%2.9f, %2.9f, %2.9f, %2.9f)\n", Mat0[0][0], Mat0[0][1], Mat0[0][2], Mat0[0][3]);
	printf("\tvec4(%2.9f, %2.9f, %2.9f, %2.9f)\n", Mat0[1][0], Mat0[1][1], Mat0[1][2], Mat0[1][3]);
	printf("\tvec4(%2.9f, %2.9f, %2.9f, %2.9f)\n", Mat0[2][0], Mat0[2][1], Mat0[2][2], Mat0[2][3]);
	printf("\tvec4(%2.9f, %2.9f, %2.9f, %2.9f))\n\n", Mat0[3][0], Mat0[3][1], Mat0[3][2], Mat0[3][3]);
}

int perf_mul()
{
	int Error = 0;

	glm::mat4 A(1.0f);
	glm::mat4 B(1.0f);

	glm::mat4 C = A * B;

	print(C);

	return Error;
}

int main()
{
	int Error(0);

	Error += test_decl();
	Error += perf_mul();

	return Error;
}
