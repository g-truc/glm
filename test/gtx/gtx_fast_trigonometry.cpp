///////////////////////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 - 2014 G-Truc Creation (www.g-truc.net)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Created : 2013-10-25
// Updated : 2013-10-25
// Licence : This source is under MIT licence
// File    : test/gtx/fast_trigonometry.cpp
///////////////////////////////////////////////////////////////////////////////////////////////////

#include <glm/gtc/type_precision.hpp>
#include <glm/gtx/fast_trigonometry.hpp>
#include <ctime>
#include <cstdio>

namespace fastCos{
	int perf()
	{
		const float begin = -glm::pi<float>();
		const float end = glm::pi<float>();
		float result = 0.f;
		const std::clock_t timestamp1 = std::clock();
		for(float i=begin; i<end; i = nextafterf(i, end))
			result = glm::fastCos(i);
		const std::clock_t timestamp2 = std::clock();
		for(float i=begin; i<end; i = nextafterf(i, end))
			result = glm::cos(i);
		const std::clock_t timestamp3 = std::clock();
		const std::clock_t time_fast = timestamp2 - timestamp1;
		const std::clock_t time_default = timestamp3 - timestamp2;
		std::printf("fastCos Time %d clocks\n", static_cast<unsigned int>(time_fast));
		std::printf("cos Time %d clocks\n", static_cast<unsigned int>(time_default));
		return time_fast < time_default ? 0 : 1;
	}
}

namespace fastSin{
	int perf()
	{
		const float begin = -glm::pi<float>();
		const float end = glm::pi<float>();
		float result = 0.f;
		const std::clock_t timestamp1 = std::clock();
		for (float i = begin; i<end; i = nextafterf(i, end))
			result = glm::fastSin(i);
		const std::clock_t timestamp2 = std::clock();
		for (float i = begin; i<end; i = nextafterf(i, end))
			result = glm::sin(i);
		const std::clock_t timestamp3 = std::clock();
		const std::clock_t time_fast = timestamp2 - timestamp1;
		const std::clock_t time_default = timestamp3 - timestamp2;
		std::printf("fastSin Time %d clocks\n", static_cast<unsigned int>(time_fast));
		std::printf("sin Time %d clocks\n", static_cast<unsigned int>(time_default));
		return time_fast < time_default ? 0 : 1;
	}
}

namespace fastTan{
	int perf()
	{
		const float begin = -glm::pi<float>();
		const float end = glm::pi<float>();
		float result = 0.f;
		const std::clock_t timestamp1 = std::clock();
		for (float i = begin; i<end; i = nextafterf(i, end))
			result = glm::fastTan(i);
		const std::clock_t timestamp2 = std::clock();
		for (float i = begin; i<end; i = nextafterf(i, end))
			result = glm::tan(i);
		const std::clock_t timestamp3 = std::clock();
		const std::clock_t time_fast = timestamp2 - timestamp1;
		const std::clock_t time_default = timestamp3 - timestamp2;
		std::printf("fastTan Time %d clocks\n", static_cast<unsigned int>(time_fast));
		std::printf("tan Time %d clocks\n", static_cast<unsigned int>(time_default));
		return time_fast < time_default ? 0 : 1;
	}
}

namespace fastAcos{
	int perf()
	{
		const float begin = -glm::pi<float>();
		const float end = glm::pi<float>();
		float result = 0.f;
		const std::clock_t timestamp1 = std::clock();
		for (float i = begin; i<end; i = nextafterf(i, end))
			result = glm::fastAcos(i);
		const std::clock_t timestamp2 = std::clock();
		for (float i = begin; i<end; i = nextafterf(i, end))
			result = glm::acos(i);
		const std::clock_t timestamp3 = std::clock();
		const std::clock_t time_fast = timestamp2 - timestamp1;
		const std::clock_t time_default = timestamp3 - timestamp2;
		std::printf("fastAcos Time %d clocks\n", static_cast<unsigned int>(time_fast));
		std::printf("acos Time %d clocks\n", static_cast<unsigned int>(time_default));
		return time_fast < time_default ? 0 : 1;
	}
}

namespace fastAsin{
	int perf()
	{
		const float begin = -glm::pi<float>();
		const float end = glm::pi<float>();
		float result = 0.f;
		const std::clock_t timestamp1 = std::clock();
		for (float i = begin; i<end; i = nextafterf(i, end))
			result = glm::fastAsin(i);
		const std::clock_t timestamp2 = std::clock();
		for (float i = begin; i<end; i = nextafterf(i, end))
			result = glm::asin(i);
		const std::clock_t timestamp3 = std::clock();
		const std::clock_t time_fast = timestamp2 - timestamp1;
		const std::clock_t time_default = timestamp3 - timestamp2;
		std::printf("fastAsin Time %d clocks\n", static_cast<unsigned int>(time_fast));
		std::printf("asin Time %d clocks\n", static_cast<unsigned int>(time_default));
		return time_fast < time_default ? 0 : 1;
	}
}

namespace fastAtan{
	int perf()
	{
		const float begin = -glm::pi<float>();
		const float end = glm::pi<float>();
		float result = 0.f;
		const std::clock_t timestamp1 = std::clock();
		for (float i = begin; i<end; i = nextafterf(i, end))
			result = glm::fastAtan(i);
		const std::clock_t timestamp2 = std::clock();
		for (float i = begin; i<end; i = nextafterf(i, end))
			result = glm::atan(i);
		const std::clock_t timestamp3 = std::clock();
		const std::clock_t time_fast = timestamp2 - timestamp1;
		const std::clock_t time_default = timestamp3 - timestamp2;
		std::printf("fastAtan Time %d clocks\n", static_cast<unsigned int>(time_fast));
		std::printf("atan Time %d clocks\n", static_cast<unsigned int>(time_default));
		return time_fast < time_default ? 0 : 1;
	}
}


int main()
{
	int Error(0);

	Error += ::fastCos::perf();
	Error += ::fastSin::perf();
	Error += ::fastTan::perf();
	Error += ::fastAcos::perf();
	Error += ::fastAsin::perf();
	Error += ::fastAtan::perf();

	return Error;
}
