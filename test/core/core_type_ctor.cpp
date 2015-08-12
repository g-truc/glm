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
/// @file test/core/core_type_ctor.cpp
/// @date 2015-07-25 / 2015-07-25
/// @author Christophe Riccio
///////////////////////////////////////////////////////////////////////////////////

#define GLM_FORCE_NO_CTOR_INIT
#include <glm/glm.hpp>
#include <glm/gtc/vec1.hpp>
#include <glm/gtc/quaternion.hpp>

int test_vec1_ctor()
{
	int Error = 0;

#	if GLM_HAS_DEFAULTED_FUNCTIONS
	{
		union pack
		{
			glm::vec1 f;
			glm::ivec1 i;
		} A, B;

		A.f = glm::vec1(0);
		Error += glm::all(glm::equal(A.i, glm::ivec1(0))) ? 0 : 1;

		B.f = glm::vec1(1);
		Error += glm::all(glm::equal(B.i, glm::ivec1(1065353216))) ? 0 : 1;
	}
#	endif//GLM_HAS_DEFAULTED_FUNCTIONS

	return Error;
}

int test_vec2_ctor()
{
	int Error = 0;

#	if GLM_HAS_DEFAULTED_FUNCTIONS
	{
		union pack
		{
			glm::vec2 f;
			glm::ivec2 i;
		} A, B;

		A.f = glm::vec2(0);
		Error += glm::all(glm::equal(A.i, glm::ivec2(0))) ? 0 : 1;

		B.f = glm::vec2(1);
		Error += glm::all(glm::equal(B.i, glm::ivec2(1065353216))) ? 0 : 1;
	}
#	endif//GLM_HAS_DEFAULTED_FUNCTIONS

	return Error;
}

int test_vec3_ctor()
{
	int Error = 0;

#	if GLM_HAS_DEFAULTED_FUNCTIONS
	{
		union pack
		{
			glm::vec3 f;
			glm::ivec3 i;
		} A, B;

		A.f = glm::vec3(0);
		Error += glm::all(glm::equal(A.i, glm::ivec3(0))) ? 0 : 1;

		B.f = glm::vec3(1);
		Error += glm::all(glm::equal(B.i, glm::ivec3(1065353216))) ? 0 : 1;
	}
#	endif//GLM_HAS_DEFAULTED_FUNCTIONS

	return Error;
}

int test_vec4_ctor()
{
	int Error = 0;

#	ifndef GLM_FORCE_NO_CTOR_INIT
	{
		glm::vec4 A;
		glm::vec4 B(0);
		Error += glm::all(glm::equal(A, B)) ? 0 : 1;
	}
#	endif//GLM_FORCE_NO_CTOR_INIT

#	if GLM_HAS_DEFAULTED_FUNCTIONS
	{
		union pack
		{
			glm::vec4 f;
			glm::ivec4 i;
		} A, B;

		A.f = glm::vec4(0);
		Error += glm::all(glm::equal(A.i, glm::ivec4(0))) ? 0 : 1;

		B.f = glm::vec4(1);
		Error += glm::all(glm::equal(B.i, glm::ivec4(1065353216))) ? 0 : 1;
	}
#	endif//GLM_HAS_DEFAULTED_FUNCTIONS

	return Error;
}

int test_mat2x2_ctor()
{
	int Error = 0;

#	if GLM_HAS_DEFAULTED_FUNCTIONS
	{
		union pack
		{
			glm::mat2x2 f;
			glm::mat2x2 i;
		} A, B;

		A.f = glm::mat2x2(0);
		Error += glm::all(glm::equal(A.i[0], glm::vec2(0))) ? 0 : 1;

		B.f = glm::mat2x2(1);
		Error += glm::all(glm::equal(B.i[0], glm::vec2(1, 0))) ? 0 : 1;
	}
#	endif//GLM_HAS_DEFAULTED_FUNCTIONS

	return Error;
}

int test_mat2x3_ctor()
{
	int Error = 0;

#	if GLM_HAS_DEFAULTED_FUNCTIONS
	{
		union pack
		{
			glm::mat2x3 f;
			glm::mat2x3 i;
		} A, B;

		A.f = glm::mat2x3(0);
		Error += glm::all(glm::equal(A.i[0], glm::vec3(0))) ? 0 : 1;

		B.f = glm::mat2x3(1);
		Error += glm::all(glm::equal(B.i[0], glm::vec3(1, 0, 0))) ? 0 : 1;
	}
#	endif//GLM_HAS_DEFAULTED_FUNCTIONS

	return Error;
}

int test_mat2x4_ctor()
{
	int Error = 0;

#	if GLM_HAS_DEFAULTED_FUNCTIONS
	{
		union pack
		{
			glm::mat2x4 f;
			glm::mat2x4 i;
		} A, B;

		A.f = glm::mat2x4(0);
		Error += glm::all(glm::equal(A.i[0], glm::vec4(0))) ? 0 : 1;

		B.f = glm::mat2x4(1);
		Error += glm::all(glm::equal(B.i[0], glm::vec4(1, 0, 0, 0))) ? 0 : 1;
	}
#	endif//GLM_HAS_DEFAULTED_FUNCTIONS

	return Error;
}

int test_mat3x2_ctor()
{
	int Error = 0;

#	if GLM_HAS_DEFAULTED_FUNCTIONS
	{
		union pack
		{
			glm::mat3x2 f;
			glm::mat3x2 i;
		} A, B;

		A.f = glm::mat3x2(0);
		Error += glm::all(glm::equal(A.i[0], glm::vec2(0))) ? 0 : 1;

		B.f = glm::mat3x2(1);
		Error += glm::all(glm::equal(B.i[0], glm::vec2(1, 0))) ? 0 : 1;
	}
#	endif//GLM_HAS_DEFAULTED_FUNCTIONS

	return Error;
}

int test_mat3x3_ctor()
{
	int Error = 0;

#	if GLM_HAS_DEFAULTED_FUNCTIONS
	{
		union pack
		{
			glm::mat3x3 f;
			glm::mat3x3 i;
		} A, B;

		A.f = glm::mat3x3(0);
		Error += glm::all(glm::equal(A.i[0], glm::vec3(0))) ? 0 : 1;

		B.f = glm::mat3x3(1);
		Error += glm::all(glm::equal(B.i[0], glm::vec3(1, 0, 0))) ? 0 : 1;
	}
#	endif//GLM_HAS_DEFAULTED_FUNCTIONS

	return Error;
}

int test_mat3x4_ctor()
{
	int Error = 0;

#	if GLM_HAS_DEFAULTED_FUNCTIONS
	{
		union pack
		{
			glm::mat3x4 f;
			glm::mat3x4 i;
		} A, B;

		A.f = glm::mat3x4(0);
		Error += glm::all(glm::equal(A.i[0], glm::vec4(0))) ? 0 : 1;

		B.f = glm::mat3x4(1);
		Error += glm::all(glm::equal(B.i[0], glm::vec4(1, 0, 0, 0))) ? 0 : 1;
	}
#	endif//GLM_HAS_DEFAULTED_FUNCTIONS

	return Error;
}

int test_mat4x2_ctor()
{
	int Error = 0;

#	if GLM_HAS_DEFAULTED_FUNCTIONS
	{
		union pack
		{
			glm::mat4x2 f;
			glm::mat4x2 i;
		} A, B;

		A.f = glm::mat4x2(0);
		Error += glm::all(glm::equal(A.i[0], glm::vec2(0))) ? 0 : 1;

		B.f = glm::mat4x2(1);
		Error += glm::all(glm::equal(B.i[0], glm::vec2(1, 0))) ? 0 : 1;
	}
#	endif//GLM_HAS_DEFAULTED_FUNCTIONS

	return Error;
}

int test_mat4x3_ctor()
{
	int Error = 0;

#	if GLM_HAS_DEFAULTED_FUNCTIONS
	{
		union pack
		{
			glm::mat4x3 f;
			glm::mat4x3 i;
		} A, B;

		A.f = glm::mat4x3(0);
		Error += glm::all(glm::equal(A.i[0], glm::vec3(0))) ? 0 : 1;

		B.f = glm::mat4x3(1);
		Error += glm::all(glm::equal(B.i[0], glm::vec3(1, 0, 0))) ? 0 : 1;
	}
#	endif//GLM_HAS_DEFAULTED_FUNCTIONS

	return Error;
}

int test_mat4x4_ctor()
{
	int Error = 0;

#	if GLM_HAS_DEFAULTED_FUNCTIONS
	{
		union pack
		{
			glm::mat4 f;
			glm::mat4 i;
		} A, B;

		A.f = glm::mat4(0);
		Error += glm::all(glm::equal(A.i[0], glm::vec4(0))) ? 0 : 1;

		B.f = glm::mat4(1);
		Error += glm::all(glm::equal(B.i[0], glm::vec4(1, 0, 0, 0))) ? 0 : 1;
	}
#	endif//GLM_HAS_DEFAULTED_FUNCTIONS

	return Error;
}

int test_quat_ctor()
{
	int Error = 0;

#	if GLM_HAS_DEFAULTED_FUNCTIONS && defined(GLM_FORCE_NO_CTOR_INIT)
	{
		union pack
		{
			glm::quat f;
			glm::quat i;
		} A, B;

		A.f = glm::quat(0, 0, 0, 0);
		Error += glm::all(glm::equal(A.i, glm::quat(0, 0, 0, 0))) ? 0 : 1;

		B.f = glm::quat(1, 1, 1, 1);
		Error += glm::all(glm::equal(B.i, glm::quat(1, 1, 1, 1))) ? 0 : 1;
	}
#	endif//GLM_HAS_DEFAULTED_FUNCTIONS

	return Error;
}

int main()
{
	int Error = 0;

	Error += test_vec1_ctor();
	Error += test_vec2_ctor();
	Error += test_vec3_ctor();
	Error += test_vec4_ctor();
	Error += test_mat2x2_ctor();
	Error += test_mat2x3_ctor();
	Error += test_mat2x4_ctor();
	Error += test_mat3x2_ctor();
	Error += test_mat3x3_ctor();
	Error += test_mat3x4_ctor();
	Error += test_mat4x2_ctor();
	Error += test_mat4x3_ctor();
	Error += test_mat4x4_ctor();
	Error += test_quat_ctor();

	return Error;
}
