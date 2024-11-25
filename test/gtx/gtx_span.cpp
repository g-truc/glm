#include <glm/gtc/constants.hpp>
#include <glm/ext/scalar_relational.hpp>
#include <glm/ext/vector_relational.hpp>
#include <glm/glm.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/span.hpp>

#if (GLM_LANG & GLM_LANG_CXX20_FLAG) && defined(__cpp_lib_span) && __cpp_lib_span >= 202002L
static int test_span_vec2()
{
	int Error = 0;

	{
		glm::ivec2 const v(1, 2);

		int count = 0;
		glm::ivec2 Result(0);
		for(int x : glm::span(v))
		{
			Result[count] = x;
			count++;
		}
		Error += count == 2 ? 0 : 1;
		Error += v == Result ? 0 : 1;
	}

	{
		glm::ivec2 v(1, 2);
		for(int& x : glm::span(v))
			x = 0;
		Error += glm::all(glm::equal(v, glm::ivec2(0))) ? 0 : 1;
	}

	return Error;
}

static int test_span_vec3()
{
	int Error = 0;

	{
		glm::ivec3 const v(1, 2, 3);

		int count = 0;
		glm::ivec3 Result(0);
		for(int x : glm::span(v))
		{
			Result[count] = x;
			count++;
		}
		Error += count == 3 ? 0 : 1;
		Error += v == Result ? 0 : 1;
	}

	{
		glm::ivec3 v(1, 2, 3);
		for(int& x : glm::span(v))
			x = 0;
		Error += glm::all(glm::equal(v, glm::ivec3(0))) ? 0 : 1;
	}

	return Error;
}

static int test_span_vec4()
{
	int Error = 0;

	{
		glm::ivec4 const v(1, 2, 3, 4);

		int count = 0;
		glm::ivec4 Result(0);
		for(int x : glm::span(v))
		{
			Result[count] = x;
			count++;
		}
		Error += count == 4 ? 0 : 1;
		Error += v == Result ? 0 : 1;
	}

	{
		glm::ivec4 v(1, 2, 3, 4);
		for(int& x : glm::span(v))
			x = 0;
		Error += glm::all(glm::equal(v, glm::ivec4(0))) ? 0 : 1;
	}

	return Error;
}

static int test_span_quat()
{
	int Error = 0;

	{
		glm::quat const q(1, 2, 3, 4);

		int count = 0;
		glm::quat Result(0, 0, 0, 0);
		for(float x : glm::span(q))
		{
			Result[count] = x;
			count++;
		}
		Error += count == 4 ? 0 : 1;
		Error += q == Result ? 0 : 1;
	}

	{
		glm::quat q(1, 2, 3, 4);
		for(float& x : glm::span(q))
			x = 0;
		Error += glm::all(glm::equal(q, glm::quat(0, 0, 0, 0))) ? 0 : 1;
	}

	return Error;
}

static int test_span_mat()
{
	int Error = 0;

	{
		glm::mat4x3 m(1.0f);

		int count = 0;
		float Sum = 0.0f;
		for(float x : glm::span(m))
		{
			count++;
			Sum += x;
		}
		Error += count == 12 ? 0 : 1;
		Error += glm::equal(Sum, 3.0f, 0.001f) ? 0 : 1;
	}

	{
		glm::mat4x3 m(1.0f);

		for(float& x : glm::span(m))
			x = 0;
		glm::vec4 v(1, 1, 1, 1);
		Error += glm::all(glm::equal(m*v, glm::vec3(0, 0, 0), glm::epsilon<float>())) ? 0 : 1;
	}

	return Error;
}
#endif

int main()
{
	int Error = 0;
	//TODO std::valarray
#if (GLM_LANG & GLM_LANG_CXX20_FLAG) && defined(__cpp_lib_span) && __cpp_lib_span >= 202002L
	Error += test_span_vec2();
	Error += test_span_vec3();
	Error += test_span_vec4();
	Error += test_span_quat();
	Error += test_span_mat();
#endif
	//TODO std::mdspan
	return Error;
}
