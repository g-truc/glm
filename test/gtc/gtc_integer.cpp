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
/// @file test/gtc/gtc_integer.cpp
/// @date 2014-11-17 / 2014-11-25
/// @author Christophe Riccio
///////////////////////////////////////////////////////////////////////////////////

#define GLM_FORCE_INLINE
#include <glm/gtc/epsilon.hpp>
#include <glm/gtc/integer.hpp>
#include <glm/gtc/type_precision.hpp>
#include <glm/gtc/vec1.hpp>
#include <glm/gtx/type_aligned.hpp>
#include <glm/vector_relational.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <ctime>
#include <cstdio>
#include <vector>
#include <cmath>

namespace log2_
{
	int test()
	{
		int Error = 0;

		int A0 = static_cast<int>(glm::log2(16.f));
		glm::ivec1 B0(glm::log2(glm::vec1(16.f)));
		glm::ivec2 C0(glm::log2(glm::vec2(16.f)));
		glm::ivec3 D0(glm::log2(glm::vec3(16.f)));
		glm::ivec4 E0(glm::log2(glm::vec4(16.f)));

		int A1 = glm::log2(int(16));
		glm::ivec1 B1 = glm::log2(glm::ivec1(16));
		glm::ivec2 C1 = glm::log2(glm::ivec2(16));
		glm::ivec3 D1 = glm::log2(glm::ivec3(16));
		glm::ivec4 E1 = glm::log2(glm::ivec4(16));

		Error += A0 == A1 ? 0 : 1;
		Error += glm::all(glm::equal(B0, B1)) ? 0 : 1;
		Error += glm::all(glm::equal(C0, C1)) ? 0 : 1;
		Error += glm::all(glm::equal(D0, D1)) ? 0 : 1;
		Error += glm::all(glm::equal(E0, E1)) ? 0 : 1;

		glm::uint64 A2 = glm::log2(glm::uint64(16));
		glm::u64vec1 B2 = glm::log2(glm::u64vec1(16));
		glm::u64vec2 C2 = glm::log2(glm::u64vec2(16));
		glm::u64vec3 D2 = glm::log2(glm::u64vec3(16));
		glm::u64vec4 E2 = glm::log2(glm::u64vec4(16));

		Error += A2 == glm::uint64(4) ? 0 : 1;
		Error += glm::all(glm::equal(B2, glm::u64vec1(4))) ? 0 : 1;
		Error += glm::all(glm::equal(C2, glm::u64vec2(4))) ? 0 : 1;
		Error += glm::all(glm::equal(D2, glm::u64vec3(4))) ? 0 : 1;
		Error += glm::all(glm::equal(E2, glm::u64vec4(4))) ? 0 : 1;

		return Error;
	}

	int perf(std::size_t Count)
	{
		int Error = 0;

		{
			std::vector<int> Result;
			Result.resize(Count);

			std::clock_t Begin = clock();

			for(int i = 0; i < static_cast<int>(Count); ++i)
				Result[i] = glm::log2(static_cast<int>(i));

			std::clock_t End = clock();

			printf("glm::log2<int>: %ld clocks\n", End - Begin);
		}

		{
			std::vector<glm::ivec4> Result;
			Result.resize(Count);

			std::clock_t Begin = clock();

			for(int i = 0; i < static_cast<int>(Count); ++i)
				Result[i] = glm::log2(glm::ivec4(i));

			std::clock_t End = clock();

			printf("glm::log2<ivec4>: %ld clocks\n", End - Begin);
		}

#		if GLM_HAS_BITSCAN_WINDOWS
		{
			std::vector<glm::ivec4> Result;
			Result.resize(Count);

			std::clock_t Begin = clock();

			for(std::size_t i = 0; i < Count; ++i)
			{
				glm::tvec4<unsigned long, glm::defaultp> Tmp(glm::uninitialize);
				_BitScanReverse(&Tmp.x, i);
				_BitScanReverse(&Tmp.y, i);
				_BitScanReverse(&Tmp.z, i);
				_BitScanReverse(&Tmp.w, i);
				Result[i] = glm::ivec4(Tmp);
			}

			std::clock_t End = clock();

			printf("glm::log2<ivec4> inlined: %ld clocks\n", End - Begin);
		}


		{
			std::vector<glm::tvec4<unsigned long, glm::defaultp> > Result;
			Result.resize(Count);

			std::clock_t Begin = clock();

			for(std::size_t i = 0; i < Count; ++i)
			{
				_BitScanReverse(&Result[i].x, i);
				_BitScanReverse(&Result[i].y, i);
				_BitScanReverse(&Result[i].z, i);
				_BitScanReverse(&Result[i].w, i);
			}

			std::clock_t End = clock();

			printf("glm::log2<ivec4> inlined no cast: %ld clocks\n", End - Begin);
		}


		{
			std::vector<glm::ivec4> Result;
			Result.resize(Count);

			std::clock_t Begin = clock();

			for(std::size_t i = 0; i < Count; ++i)
			{
				_BitScanReverse(reinterpret_cast<unsigned long*>(&Result[i].x), i);
				_BitScanReverse(reinterpret_cast<unsigned long*>(&Result[i].y), i);
				_BitScanReverse(reinterpret_cast<unsigned long*>(&Result[i].z), i);
				_BitScanReverse(reinterpret_cast<unsigned long*>(&Result[i].w), i);
			}

			std::clock_t End = clock();

			printf("glm::log2<ivec4> reinterpret: %ld clocks\n", End - Begin);
		}
#		endif//GLM_HAS_BITSCAN_WINDOWS

		{
			std::vector<float> Result;
			Result.resize(Count);

			std::clock_t Begin = clock();

			for(std::size_t i = 0; i < Count; ++i)
				Result[i] = glm::log2(static_cast<float>(i));

			std::clock_t End = clock();

			printf("glm::log2<float>: %ld clocks\n", End - Begin);
		}

		{
			std::vector<glm::vec4> Result;
			Result.resize(Count);

			std::clock_t Begin = clock();

			for(int i = 0; i < static_cast<int>(Count); ++i)
				Result[i] = glm::log2(glm::vec4(i));

			std::clock_t End = clock();

			printf("glm::log2<vec4>: %ld clocks\n", End - Begin);
		}

		return Error;
	}
}//namespace log2_

int main()
{
	int Error(0);

	Error += ::log2_::test();

#	ifdef NDEBUG
		std::size_t const Samples(1000);
		Error += ::log2_::perf(Samples);
#	endif//NDEBUG

	return Error;
}
