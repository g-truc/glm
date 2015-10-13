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
/// @file test/core/func_matrix.cpp
/// @date 2007-01-25 / 2011-06-07
/// @author Christophe Riccio
///////////////////////////////////////////////////////////////////////////////////

#include <glm/matrix.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/ulp.hpp>
#include <vector>
#include <ctime>
#include <cstdio>

using namespace glm;

int test_matrixCompMult()
{
	int Error(0);

	{
		mat2 m(0, 1, 2, 3);
		mat2 n = matrixCompMult(m, m);
		Error += n == mat2(0, 1, 4, 9) ? 0 : 1;
	}

	{
		mat2x3 m(0, 1, 2, 3, 4, 5);
		mat2x3 n = matrixCompMult(m, m);
		Error += n == mat2x3(0, 1, 4, 9, 16, 25) ? 0 : 1;
	}

	{
		mat2x4 m(0, 1, 2, 3, 4, 5, 6, 7);
		mat2x4 n = matrixCompMult(m, m);
		Error += n == mat2x4(0, 1, 4, 9, 16, 25, 36, 49) ? 0 : 1;
	}

	{
		mat3 m(0, 1, 2, 3, 4, 5, 6, 7, 8);
		mat3 n = matrixCompMult(m, m);
		Error += n == mat3(0, 1, 4, 9, 16, 25, 36, 49, 64) ? 0 : 1;
	}

	{
		mat3x2 m(0, 1, 2, 3, 4, 5);
		mat3x2 n = matrixCompMult(m, m);
		Error += n == mat3x2(0, 1, 4, 9, 16, 25) ? 0 : 1;
	}

	{
		mat3x4 m(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
		mat3x4 n = matrixCompMult(m, m);
		Error += n == mat3x4(0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121) ? 0 : 1;
	}

	{
		mat4 m(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
		mat4 n = matrixCompMult(m, m);
		Error += n == mat4(0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196, 225) ? 0 : 1;
	}

	{
		mat4x2 m(0, 1, 2, 3, 4, 5, 6, 7);
		mat4x2 n = matrixCompMult(m, m);
		Error += n == mat4x2(0, 1, 4, 9, 16, 25, 36, 49) ? 0 : 1;
	}

	{
		mat4x3 m(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
		mat4x3 n = matrixCompMult(m, m);
		Error += n == mat4x3(0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121) ? 0 : 1;
	}

	return Error;
}

int test_outerProduct()
{
	glm::mat4 m = glm::outerProduct(glm::vec4(1.0f), glm::vec4(1.0f));

	return 0;
}

int test_transpose()
{
	int Error(0);

	{
		mat2 m(0, 1, 2, 3);
		mat2 t = transpose(m);
		Error += t == mat2(0, 2, 1, 3) ? 0 : 1;
	}

	{
		mat2x3 m(0, 1, 2, 3, 4, 5);
		mat3x2 t = transpose(m);
		Error += t == mat3x2(0, 3, 1, 4, 2, 5) ? 0 : 1;
	}

	{
		mat2x4 m(0, 1, 2, 3, 4, 5, 6, 7);
		mat4x2 t = transpose(m);
		Error += t == mat4x2(0, 4, 1, 5, 2, 6, 3, 7) ? 0 : 1;
	}

	{
		mat3 m(0, 1, 2, 3, 4, 5, 6, 7, 8);
		mat3 t = transpose(m);
		Error += t == mat3(0, 3, 6, 1, 4, 7, 2, 5, 8) ? 0 : 1;
	}

	{
		mat3x2 m(0, 1, 2, 3, 4, 5);
		mat2x3 t = transpose(m);
		Error += t == mat2x3(0, 2, 4, 1, 3, 5) ? 0 : 1;
	}

	{
		mat3x4 m(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
		mat4x3 t = transpose(m);
		Error += t == mat4x3(0, 4, 8, 1, 5, 9, 2, 6, 10, 3, 7, 11) ? 0 : 1;
	}

	{
		mat4 m(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
		mat4 t = transpose(m);
		Error += t == mat4(0, 4, 8, 12, 1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15) ? 0 : 1;
	}

	{
		mat4x2 m(0, 1, 2, 3, 4, 5, 6, 7);
		mat2x4 t = transpose(m);
		Error += t == mat2x4(0, 2, 4, 6, 1, 3, 5, 7) ? 0 : 1;
	}

	{
		mat4x3 m(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
		mat3x4 t = transpose(m);
		Error += t == mat3x4(0, 3, 6, 9, 1, 4, 7, 10, 2, 5, 8, 11) ? 0 : 1;
	}

	return Error;
}

int test_determinant()
{


	return 0;
}

int test_inverse()
{
	int Failed(0);

	glm::mat4x4 A4x4(
		glm::vec4(1, 0, 1, 0), 
		glm::vec4(0, 1, 0, 0), 
		glm::vec4(0, 0, 1, 0), 
		glm::vec4(0, 0, 0, 1));
	glm::mat4x4 B4x4 = inverse(A4x4);
	glm::mat4x4 I4x4 = A4x4 * B4x4;
	Failed += I4x4 == glm::mat4x4(1) ? 0 : 1;

	glm::mat3x3 A3x3(
		glm::vec3(1, 0, 1), 
		glm::vec3(0, 1, 0), 
		glm::vec3(0, 0, 1));
	glm::mat3x3 B3x3 = glm::inverse(A3x3);
	glm::mat3x3 I3x3 = A3x3 * B3x3;
	Failed += I3x3 == glm::mat3x3(1) ? 0 : 1;

	glm::mat2x2 A2x2(
		glm::vec2(1, 1), 
		glm::vec2(0, 1));
	glm::mat2x2 B2x2 = glm::inverse(A2x2);
	glm::mat2x2 I2x2 = A2x2 * B2x2;
	Failed += I2x2 == glm::mat2x2(1) ? 0 : 1;



	return Failed;
}

template <typename VEC3, typename MAT4>
int test_inverse_perf(std::size_t Count, std::size_t Instance, char const * Message)
{
	std::vector<MAT4> TestInputs;
	TestInputs.resize(Count);
	std::vector<MAT4> TestOutputs;
	TestOutputs.resize(TestInputs.size());

	VEC3 Axis(glm::normalize(VEC3(1.0f, 2.0f, 3.0f)));

	for(std::size_t i = 0; i < TestInputs.size(); ++i)
	{
		typename MAT4::value_type f = static_cast<typename MAT4::value_type>(i + Instance) * typename MAT4::value_type(0.1) + typename MAT4::value_type(0.1);
		TestInputs[i] = glm::rotate(glm::translate(MAT4(1), Axis * f), f, Axis);
		//TestInputs[i] = glm::translate(MAT4(1), Axis * f);
	}

	std::clock_t StartTime = std::clock();

	for(std::size_t i = 0; i < TestInputs.size(); ++i)
		TestOutputs[i] = glm::inverse(TestInputs[i]);

	std::clock_t EndTime = std::clock();

	for(std::size_t i = 0; i < TestInputs.size(); ++i)
		TestOutputs[i] = TestOutputs[i] * TestInputs[i];

	typename MAT4::value_type Diff(0);
	for(std::size_t Entry = 0; Entry < TestOutputs.size(); ++Entry)
	{
		MAT4 i(1.0);
		MAT4 m(TestOutputs[Entry]);
		for(glm::length_t y = 0; y < m.length(); ++y)
		for(glm::length_t x = 0; x < m[y].length(); ++x)
			Diff = glm::max(m[y][x], i[y][x]);
	}

	//glm::uint Ulp = 0;
	//Ulp = glm::max(glm::float_distance(*Dst, *Src), Ulp);

	printf("inverse<%s>(%f): %lu\n", Message, Diff, EndTime - StartTime);

	return 0;
}

int main()
{
	int Error(0);
	Error += test_matrixCompMult();
	Error += test_outerProduct();
	Error += test_transpose();
	Error += test_determinant();
	Error += test_inverse();

#	ifdef NDEBUG
	std::size_t const Samples(1000);
	for(std::size_t i = 0; i < 1; ++i)
	{
		Error += test_inverse_perf<glm::vec3, glm::mat4>(Samples, i, "mat4");
		Error += test_inverse_perf<glm::dvec3, glm::dmat4>(Samples, i, "dmat4");
	}
#	endif//NDEBUG

	return Error;
}

