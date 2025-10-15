#include <iostream>
#include <glm/gtc/constants.hpp>
#include <glm/ext/scalar_relational.hpp>
#include <glm/ext/vector_relational.hpp>
#include <glm/glm.hpp>

#if GLM_HAS_RANGE_FOR

#include <algorithm>
#include <numeric>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/range.hpp>
#include <glm/gtx/type_trait.hpp>

static int test_vec2()
{
	int Error = 0;

	{
		glm::ivec2 const v(1, 2);

		int count = 0;
		glm::ivec2 Result(0);
		for(int x : v)
		{
			Result[count] = x;
			count++;
		}
		Error += count == 2 ? 0 : 1;
		Error += v == Result ? 0 : 1;
	}

	{
		glm::ivec2 v(1, 2);
		for(int& x : v)
			x = 0;
		Error += glm::all(glm::equal(v, glm::ivec2(0))) ? 0 : 1;
	}

	{
		glm::ivec2 const v(1, 2);
		if(std::accumulate(begin(v), end(v), 0) != 3) // Sum all elements
			Error += 1;
		if(std::distance(begin(v), end(v)) != 2) // Count number of elements
			Error += 1;
	}
#if GLM_LANG & GLM_LANG_CXX20_FLAG
	{
		glm::ivec2 const v(1, 2);
#	ifdef __cpp_lib_ranges_fold
		if(std::ranges::fold_left(v, 0, std::plus<>()) != 3) // Sum all elements
			Error += 1;
#	endif
		if(std::ranges::distance(begin(v), end(v)) != 2) // Count number of elements
			Error += 1;
	}
#endif

	return Error;
}

static int test_vec3()
{
	int Error = 0;

	{
		glm::ivec3 const v(1, 2, 3);

		int count = 0;
		glm::ivec3 Result(0);
		for(int x : v)
		{
			Result[count] = x;
			count++;
		}
		Error += count == 3 ? 0 : 1;
		Error += v == Result ? 0 : 1;
	}

	{
		glm::ivec3 v(1, 2, 3);
		for(int& x : v)
			x = 0;
		Error += glm::all(glm::equal(v, glm::ivec3(0))) ? 0 : 1;
	}

	{
		glm::ivec3 const v(1, 2, 3);
		if(std::accumulate(begin(v), end(v), 0) != 6) // Sum all elements
			Error += 1;
		if(std::distance(begin(v), end(v)) != 3) // Count number of elements
			Error += 1;
	}
#if GLM_LANG & GLM_LANG_CXX20_FLAG
	{
		glm::ivec3 const v(1, 2, 3);
#	ifdef __cpp_lib_ranges_fold
		if(std::ranges::fold_left(v, 0, std::plus<>()) != 6) // Sum all elements
			Error += 1;
#	endif
		if(std::ranges::distance(begin(v), end(v)) != 3) // Count number of elements
			Error += 1;
	}
#endif

	return Error;
}

static int test_vec4()
{
	int Error = 0;

	{
		glm::ivec4 const v(1, 2, 3, 4);

		int count = 0;
		glm::ivec4 Result(0);
		for(int x : v)
		{
			Result[count] = x;
			count++;
		}
		Error += count == 4 ? 0 : 1;
		Error += v == Result ? 0 : 1;
	}

	{
		glm::ivec4 v(1, 2, 3, 4);
		for(int& x : v)
			x = 0;
		Error += glm::all(glm::equal(v, glm::ivec4(0))) ? 0 : 1;
	}

	{
		glm::ivec4 const v(1, 2, 3, 4);
		if(std::accumulate(begin(v), end(v), 0) != 10) // Sum all elements
			Error += 1;
		if(std::distance(begin(v), end(v)) != 4) // Count number of elements
			Error += 1;
	}
#if GLM_LANG & GLM_LANG_CXX20_FLAG
	{
		glm::ivec4 const v(1, 2, 3, 4);
#	ifdef __cpp_lib_ranges_fold
		if(std::ranges::fold_left(v, 0, std::plus<>()) != 10) // Sum all elements
			Error += 1;
#	endif
		if(std::ranges::distance(begin(v), end(v)) != 4) // Count number of elements
			Error += 1;
	}
#endif

	return Error;
}

static int test_quat()
{
	int Error = 0;

	{
		glm::quat const q(1, 2, 3, 4);

		int count = 0;
		glm::quat Result(0, 0, 0, 0);
		for(float x : q)
		{
			Result[count] = x;
			count++;
		}
		Error += count == 4 ? 0 : 1;
		Error += q == Result ? 0 : 1;
	}

	{
		glm::quat q(1, 2, 3, 4);
		for(float& x : q)
			x = 0;
		Error += glm::all(glm::equal(q, glm::quat(0, 0, 0, 0))) ? 0 : 1;
	}

	{
		glm::quat const q(1, 2, 3, 4);
		if(std::accumulate(begin(q), end(q), 0.0f) != 10.0f) // Sum all elements
			Error += 1;
		if(std::distance(begin(q), end(q)) != 4) // Count number of elements
			Error += 1;
	}
#if GLM_LANG & GLM_LANG_CXX20_FLAG
	{
		glm::quat const q(1, 2, 3, 4);
#	ifdef __cpp_lib_ranges_fold
		if(std::ranges::fold_left(q, 0.0f, std::plus<>()) != 10.0f) // Sum all elements
			Error += 1;
#	endif
		if(std::ranges::distance(begin(q), end(q)) != 4) // Count number of elements
			Error += 1;
	}
#endif

	return Error;
}

static int test_mat4x3()
{
	int Error = 0;

	{
		glm::mat4x3 m(1.0f);

		int count = 0;
		float Sum = 0.0f;
		for(float x : m)
		{
			count++;
			Sum += x;
		}
		Error += count == 12 ? 0 : 1;
		Error += glm::equal(Sum, 3.0f, 0.001f) ? 0 : 1;
	}

	{
		glm::mat4x3 m(1.0f);

		for(float& x : m)
		{
			x = 0;
		}
		glm::vec4 v(1, 1, 1, 1);
		Error += glm::all(glm::equal(m*v, glm::vec3(0, 0, 0), glm::epsilon<float>())) ? 0 : 1;
	}

	// Sum all using std::accumulate
	{
		glm::mat4x3 const m(1.0f);
		if(std::accumulate(begin(m), end(m), 0.0f) != 3.0f) // Sum all elements
			Error += 1;
		if(std::distance(begin(m), end(m)) != 12) // Count number of elements
			Error += 1;
	}
#if GLM_LANG & GLM_LANG_CXX20_FLAG
	// Sum all using ranges
	{
		glm::mat4x3 const m(1.0f);
#	ifdef __cpp_lib_ranges_fold
		if(std::ranges::fold_left(m, 0.0f, std::plus<>()) != 3.0f) // Sum all elements
			Error += 1;
#	endif
		if(std::ranges::distance(begin(m), end(m)) != 12) // Count number of elements
			Error += 1;
	}
#endif

	return Error;
}

static int test_mat4()
{
	int Error = 0;

	{
		glm::mat4 m(1.0f);

		int count = 0;
		float Sum = 0.0f;
		for(float x : m)
		{
			count++;
			Sum += x;
		}
		Error += count == 16 ? 0 : 1;
		Error += glm::equal(Sum, 4.0f, 0.001f) ? 0 : 1;
	}

	{
		glm::mat4 m(1.0f);

		for(float& x : m)
		{
			x = 0;
		}
		glm::vec4 v(1, 1, 1, 1);
		Error += glm::all(glm::equal(m*v, glm::vec4(0, 0, 0, 0), glm::epsilon<float>())) ? 0 : 1;
	}

	{
		glm::mat4 const m(1.0f);
		if(std::accumulate(begin(m), end(m), 0.0f) != 4.0f) // Sum all elements
			Error += 1;
		if(std::distance(begin(m), end(m)) != 16) // Count number of elements
			Error += 1;
	}
#if GLM_LANG & GLM_LANG_CXX20_FLAG
	{
		glm::mat4 const m(1.0f);
#	ifdef __cpp_lib_ranges_fold
		if(std::ranges::fold_left(m, 0, std::plus<>()) != 4.0f) // Sum all elements
			Error += 1;
#	endif
		if(std::ranges::distance(begin(m), end(m)) != 16) // Count number of elements
			Error += 1;
	}
#endif

	return Error;
}

int main()
{
	int Error = 0;
	Error += test_vec2();
	Error += test_vec3();
	Error += test_vec4();
	Error += test_quat();
	Error += test_mat4x3();
	Error += test_mat4();
	return Error;
}

#else

int main()
{
	return 0;
}

#endif//GLM_HAS_RANGE_FOR
