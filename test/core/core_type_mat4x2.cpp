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
#include <vector>

static int test_operators()
{
	glm::mat4x2 l(1.0f);
	glm::mat4x2 m(1.0f);
	glm::vec4 u(1.0f);
	glm::vec2 v(1.0f);
	float x = 1.0f;
	glm::vec2 a = m * u;
	glm::vec4 b = v * m;
	glm::mat4x2 n = x / m;
	glm::mat4x2 o = m / x;
	glm::mat4x2 p = x * m;
	glm::mat4x2 q = m * x;
	bool R = m != q;
	bool S = m == l;

	return (S && !R) ? 0 : 1;
}

int test_ctr()
{
	int Error(0);

#if(GLM_HAS_INITIALIZER_LISTS)
	glm::mat4x2 m0(
		glm::vec2(0, 1), 
		glm::vec2(2, 3),
		glm::vec2(4, 5),
		glm::vec2(6, 7));

	glm::mat4x2 m1{0, 1, 2, 3, 4, 5, 6, 7};

	glm::mat4x2 m2{
		{0, 1},
		{2, 3},
		{4, 5},
		{6, 7}};

	for(glm::length_t i = 0; i < m0.length(); ++i)
		Error += glm::all(glm::equal(m0[i], m2[i])) ? 0 : 1;

	for(glm::length_t i = 0; i < m1.length(); ++i)
		Error += glm::all(glm::equal(m1[i], m2[i])) ? 0 : 1;

	std::vector<glm::mat4x2> v1{
		{0, 1, 2, 3, 4, 5, 6, 7},
		{0, 1, 2, 3, 4, 5, 6, 7}
	};

	std::vector<glm::mat4x2> v2{
		{
			{ 0, 1},
			{ 4, 5},
			{ 8, 9},
			{ 12, 13}
		},
		{
			{ 0, 1},
			{ 4, 5},
			{ 8, 9},
			{ 12, 13}
		}
	};

#endif//GLM_HAS_INITIALIZER_LISTS

	return Error;
}

namespace cast
{
	template<typename genType>
	int entry()
	{
		int Error = 0;

		genType A(1.0f);
		glm::mat4x2 B(A);
		glm::mat4x2 Identity(1.0f);

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

int test_size()
{
	int Error = 0;

	Error += 32 == sizeof(glm::mat4x2) ? 0 : 1;
	Error += 64 == sizeof(glm::dmat4x2) ? 0 : 1;
	Error += glm::mat4x2().length() == 4 ? 0 : 1;
	Error += glm::dmat4x2().length() == 4 ? 0 : 1;
	Error += glm::mat4x2::length() == 4 ? 0 : 1;
	Error += glm::dmat4x2::length() == 4 ? 0 : 1;

	return Error;
}

int main()
{
	int Error = 0;

	Error += cast::test();
	Error += test_ctr();
	Error += test_operators();
	Error += test_size();

	return Error;
}

