///////////////////////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 - 2014 G-Truc Creation (www.g-truc.net)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Created : 2011-05-31
// Updated : 2013-08-27
// Licence : This source is under MIT License
// File    : test/core/setup_message.cpp
///////////////////////////////////////////////////////////////////////////////////////////////////

#define GLM_MESSAGES
#include <glm/vec3.hpp>
#include <cstdio>

int test_compiler()
{
	int Error(0);
	
	if(GLM_COMPILER & GLM_COMPILER_VC)
	{
		switch(GLM_COMPILER)
		{
		case GLM_COMPILER_VC2010:
			std::printf("GLM_COMPILER_VC2010\n");
			break;
		case GLM_COMPILER_VC2012:
			std::printf("GLM_COMPILER_VC2012\n");
			break;
		case GLM_COMPILER_VC2013:
			std::printf("GLM_COMPILER_VC2013\n");
			break;
		case GLM_COMPILER_VC2015:
			std::printf("GLM_COMPILER_VC2015\n");
			break;
		default:
			std::printf("Visual C++ version not detected\n");
			Error += 1;
			break;
		}
	}
	else if(GLM_COMPILER & GLM_COMPILER_GCC)
	{
		switch(GLM_COMPILER)
		{
		case GLM_COMPILER_GCC44:
			std::printf("GLM_COMPILER_GCC44\n");
			break;
		case GLM_COMPILER_GCC45:
			std::printf("GLM_COMPILER_GCC45\n");
			break;
		case GLM_COMPILER_GCC46:
			std::printf("GLM_COMPILER_GCC46\n");
			break;
		case GLM_COMPILER_GCC47:
			std::printf("GLM_COMPILER_GCC47\n");
			break;
		case GLM_COMPILER_GCC48:
			std::printf("GLM_COMPILER_GCC48\n");
			break;
		case GLM_COMPILER_GCC49:
			std::printf("GLM_COMPILER_GCC49\n");
			break;
		case GLM_COMPILER_GCC50:
			std::printf("GLM_COMPILER_GCC50\n");
			break;
		case GLM_COMPILER_GCC51:
			std::printf("GLM_COMPILER_GCC51\n");
			break;
		case GLM_COMPILER_GCC52:
			std::printf("GLM_COMPILER_GCC52\n");
			break;
		case GLM_COMPILER_GCC53:
			std::printf("GLM_COMPILER_GCC53\n");
			break;
		case GLM_COMPILER_GCC60:
			std::printf("GLM_COMPILER_GCC60\n");
			break;
		default:
			std::printf("GCC version not detected\n");
			Error += 1;
			break;
		}
	}
	else if(GLM_COMPILER & GLM_COMPILER_CUDA)
	{
		std::printf("GLM_COMPILER_CUDA\n");
	}
	else if(GLM_COMPILER & GLM_COMPILER_APPLE_CLANG)
	{
		switch(GLM_COMPILER)
		{
		case GLM_COMPILER_APPLE_CLANG40:
			std::printf("GLM_COMPILER_APPLE_CLANG40\n");
			break;
		case GLM_COMPILER_APPLE_CLANG41:
			std::printf("GLM_COMPILER_APPLE_CLANG41\n");
			break;
		case GLM_COMPILER_APPLE_CLANG42:
			std::printf("GLM_COMPILER_APPLE_CLANG42\n");
			break;
		case GLM_COMPILER_APPLE_CLANG50:
			std::printf("GLM_COMPILER_APPLE_CLANG50\n");
			break;
		case GLM_COMPILER_APPLE_CLANG51:
			std::printf("GLM_COMPILER_APPLE_CLANG51\n");
			break;
		case GLM_COMPILER_APPLE_CLANG60:
			std::printf("GLM_COMPILER_APPLE_CLANG60\n");	
			break;
		case GLM_COMPILER_APPLE_CLANG61:
			std::printf("GLM_COMPILER_APPLE_CLANG61\n");	
			break;
		default:
			std::printf("Apple Clang version not detected\n");
			break;
		}
	}
	else if(GLM_COMPILER & GLM_COMPILER_LLVM)
	{
		switch(GLM_COMPILER)
		{
		case GLM_COMPILER_LLVM32:
			std::printf("GLM_COMPILER_LLVM32\n");
			break;
		case GLM_COMPILER_LLVM33:
			std::printf("GLM_COMPILER_LLVM33\n");
			break;
		case GLM_COMPILER_LLVM34:
			std::printf("GLM_COMPILER_LLVM34\n");
			break;
		case GLM_COMPILER_LLVM35:
			std::printf("GLM_COMPILER_LLVM35\n");
			break;
		case GLM_COMPILER_LLVM36:
			std::printf("GLM_COMPILER_LLVM36\n");
			break;
		case GLM_COMPILER_LLVM37:
			std::printf("GLM_COMPILER_LLVM37\n");
			break;
		case GLM_COMPILER_LLVM38:
			std::printf("GLM_COMPILER_LLVM38\n");
			break;
		case GLM_COMPILER_LLVM39:
			std::printf("GLM_COMPILER_LLVM39\n");
			break;
		default:
			std::printf("LLVM version not detected\n");
			break;
		}
	}
	else if(GLM_COMPILER & GLM_COMPILER_INTEL)
	{
		switch(GLM_COMPILER)
		{
		case GLM_COMPILER_INTEL12:
			std::printf("GLM_COMPILER_INTEL12\n");
			break;
		case GLM_COMPILER_INTEL12_1:
			std::printf("GLM_COMPILER_INTEL12_1\n");
			break;
		case GLM_COMPILER_INTEL13:
			std::printf("GLM_COMPILER_INTEL13\n");
			break;
		case GLM_COMPILER_INTEL14:
			std::printf("GLM_COMPILER_INTEL14\n");
			break;
		case GLM_COMPILER_INTEL15:
			std::printf("GLM_COMPILER_INTEL15\n");
			break;
		case GLM_COMPILER_INTEL16:
			std::printf("GLM_COMPILER_INTEL16\n");
			break;
		default:
			std::printf("Intel compiler version not detected\n");
			Error += 1;
			break;
		}
	}
	else
	{
		std::printf("Undetected compiler\n");
		Error += 1;
	}
	
	return Error;
}

int test_model()
{
	int Error = 0;
	
	Error += ((sizeof(void*) == 4) && (GLM_MODEL == GLM_MODEL_32)) || ((sizeof(void*) == 8) && (GLM_MODEL == GLM_MODEL_64)) ? 0 : 1;
	
	if(GLM_MODEL == GLM_MODEL_32)
		std::printf("GLM_MODEL_32\n");
	else if(GLM_MODEL == GLM_MODEL_64)
		std::printf("GLM_MODEL_64\n");
	
	return Error;
}

int test_instruction_set()
{
	int Error = 0;

	std::printf("GLM_ARCH: ");

	if(GLM_ARCH == GLM_ARCH_PURE)
		std::printf("GLM_ARCH_PURE ");
	if(GLM_ARCH & GLM_ARCH_ARM)
		std::printf("GLM_ARCH_ARM ");
	if(GLM_ARCH & GLM_ARCH_AVX2)
		std::printf("GLM_ARCH_AVX2 ");
	if(GLM_ARCH & GLM_ARCH_AVX)
		std::printf("GLM_ARCH_AVX ");
	if(GLM_ARCH & GLM_ARCH_AVX)
		std::printf("GLM_ARCH_SSE4 ");
	if(GLM_ARCH & GLM_ARCH_SSE3)
		std::printf("GLM_ARCH_SSE3 ");
	if(GLM_ARCH & GLM_ARCH_SSE2)
		std::printf("GLM_ARCH_SSE2 ");

	std::printf("\n");

	return Error;
}

int test_cpp_version()
{
	std::printf("__cplusplus: %ld\n", __cplusplus);
	
	return 0;
}

int test_operators()
{
	glm::vec3 A(1.0f);
	glm::vec3 B(1.0f);
	bool R = A != B;
	bool S = A == B;

	return (S && !R) ? 0 : 1;
}

template <typename T>
struct vec
{

};

template <template <typename> class C, typename T>
struct Class
{

};

template <typename T>
struct Class<vec, T>
{

};

int main()
{
	//Class<vec, float> C;

	int Error = 0;

	Error += test_cpp_version();
	Error += test_compiler();
	Error += test_model();
	Error += test_instruction_set();
	Error += test_operators();
	
	return Error;
}
