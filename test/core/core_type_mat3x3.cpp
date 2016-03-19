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
/// @file test/core/core_type_mat3x3.cpp
/// @date 2008-08-31 / 2014-11-25
/// @author Christophe Riccio
///////////////////////////////////////////////////////////////////////////////////

#include <glm/gtc/epsilon.hpp>
#include <glm/matrix.hpp>
#include <glm/vector_relational.hpp>
#include <glm/mat2x2.hpp>
#include <glm/mat2x3.hpp>
#include <glm/mat2x4.hpp>
#include <glm/mat3x2.hpp>
#include <glm/mat3x3.hpp>
#include <glm/mat3x4.hpp>
#include <glm/mat4x2.hpp>
#include <glm/mat4x3.hpp>
#include <glm/mat4x4.hpp>
#include <cstdio>
#include <vector>

void print(glm::dmat3 const & Mat0)
{
	printf("mat3(\n");
	printf("\tvec3(%2.3f, %2.3f, %2.3f)\n", Mat0[0][0], Mat0[0][1], Mat0[0][2]);
	printf("\tvec3(%2.3f, %2.3f, %2.3f)\n", Mat0[1][0], Mat0[1][1], Mat0[1][2]);
	printf("\tvec3(%2.3f, %2.3f, %2.3f))\n\n", Mat0[2][0], Mat0[2][1], Mat0[2][2]);
}

int test_mat3x3()
{
	glm::dmat3 Mat0(
		glm::dvec3(0.6f, 0.2f, 0.3f), 
		glm::dvec3(0.2f, 0.7f, 0.5f), 
		glm::dvec3(0.3f, 0.5f, 0.7f));
	glm::dmat3 Inv0 = glm::inverse(Mat0);
	glm::dmat3 Res0 = Mat0 * Inv0;

	print(Mat0);
	print(Inv0);
	print(Res0);

	return 0;
}

static int test_operators()
{
	glm::mat3x3 l(1.0f);
	glm::mat3x3 m(1.0f);
	glm::vec3 u(1.0f);
	glm::vec3 v(1.0f);
	float x = 1.0f;
	glm::vec3 a = m * u;
	glm::vec3 b = v * m;
	glm::mat3x3 n = x / m;
	glm::mat3x3 o = m / x;
	glm::mat3x3 p = x * m;
	glm::mat3x3 q = m * x;
	bool R = m != q;
	bool S = m == l;

	return (S && !R) ? 0 : 1;
}

int test_inverse()
{
	int Error(0);

	{
		glm::mat3 const Matrix(
			glm::vec3(0.6f, 0.2f, 0.3f), 
			glm::vec3(0.2f, 0.7f, 0.5f), 
			glm::vec3(0.3f, 0.5f, 0.7f));
		glm::mat3 const Inverse = glm::inverse(Matrix);
		glm::mat3 const Identity = Matrix * Inverse;

		Error += glm::all(glm::epsilonEqual(Identity[0], glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.01f))) ? 0 : 1;
		Error += glm::all(glm::epsilonEqual(Identity[1], glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.01f))) ? 0 : 1;
		Error += glm::all(glm::epsilonEqual(Identity[2], glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.01f))) ? 0 : 1;
	}

	{
		glm::mat3 const Matrix(
			glm::vec3(0.6f, 0.2f, 0.3f), 
			glm::vec3(0.2f, 0.7f, 0.5f), 
			glm::vec3(0.3f, 0.5f, 0.7f));
		glm::mat3 const Identity = Matrix / Matrix;

		Error += glm::all(glm::epsilonEqual(Identity[0], glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.01f))) ? 0 : 1;
		Error += glm::all(glm::epsilonEqual(Identity[1], glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.01f))) ? 0 : 1;
		Error += glm::all(glm::epsilonEqual(Identity[2], glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.01f))) ? 0 : 1;
	}

	return Error;
}

int test_ctr()
{
	int Error(0);

#if(GLM_HAS_INITIALIZER_LISTS)
	glm::mat3x3 m0(
		glm::vec3(0, 1, 2),
		glm::vec3(3, 4, 5),
		glm::vec3(6, 7, 8));
	
	glm::mat3x3 m1{0, 1, 2, 3, 4, 5, 6, 7, 8};
	
	glm::mat3x3 m2{
		{0, 1, 2},
		{3, 4, 5},
		{6, 7, 8}};
	
	for(glm::length_t i = 0; i < m0.length(); ++i)
		Error += glm::all(glm::equal(m0[i], m2[i])) ? 0 : 1;
	
	for(glm::length_t i = 0; i < m1.length(); ++i)
		Error += glm::all(glm::equal(m1[i], m2[i])) ? 0 : 1;
	
	std::vector<glm::mat3x3> v1{
		{0, 1, 2, 3, 4, 5, 6, 7, 8},
		{0, 1, 2, 3, 4, 5, 6, 7, 8}
	};
	
	std::vector<glm::mat3x3> v2{
		{
			{ 0, 1, 2},
			{ 3, 4, 5},
			{ 6, 7, 8}
		},
		{
			{ 0, 1, 2},
			{ 3, 4, 5},
			{ 6, 7, 8}
		}
	};
	
#endif//GLM_HAS_INITIALIZER_LISTS
	
	return Error;
}

namespace cast
{
	template <typename genType>
	int entry()
	{
		int Error = 0;

		genType A(1.0f);
		glm::mat3x3 B(A);
		glm::mat3x3 Identity(1.0f);

		for(glm::length_t i = 0, length = B.length(); i < length; ++i)
			Error += glm::all(glm::equal(B[i], Identity[i])) ? 0 : 1;

		return Error;
	}

	int test()
	{
		int Error = 0;
		
		Error += entry<glm::mat2x2>();
		Error += entry<glm::mat2x3>();
		Error += entry<glm::mat2x4>();
		Error += entry<glm::mat3x2>();
		Error += entry<glm::mat3x3>();
		Error += entry<glm::mat3x4>();
		Error += entry<glm::mat4x2>();
		Error += entry<glm::mat4x3>();
		Error += entry<glm::mat4x4>();

		return Error;
	}
}//namespace cast

int main()
{
	int Error = 0;

	Error += cast::test();
	Error += test_ctr();
	Error += test_mat3x3();
	Error += test_operators();
	Error += test_inverse();

	return Error;
}

