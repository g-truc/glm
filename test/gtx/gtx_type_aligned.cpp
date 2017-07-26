#define GLM_ENABLE_EXPERIMENTAL
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

template<typename genType>
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
