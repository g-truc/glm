#include <glm/common.hpp>
#include <glm/exponential.hpp>
#include <glm/gtc/ulp.hpp>
#include <glm/gtc/vec1.hpp>

int test_pow()
{
	int Error(0);

	float A = glm::pow(10.f, 10.f);
	glm::vec1 B = glm::pow(glm::vec1(10.f), glm::vec1(10.f));
	glm::vec2 C = glm::pow(glm::vec2(10.f), glm::vec2(10.f));
	glm::vec3 D = glm::pow(glm::vec3(10.f), glm::vec3(10.f));
	glm::vec4 E = glm::pow(glm::vec4(10.f), glm::vec4(10.f));

	return Error;
}

int test_exp()
{
	int Error(0);

	float A = glm::exp(10.f);
	glm::vec1 B = glm::exp(glm::vec1(10.f));
	glm::vec2 C = glm::exp(glm::vec2(10.f));
	glm::vec3 D = glm::exp(glm::vec3(10.f));
	glm::vec4 E = glm::exp(glm::vec4(10.f));

	return Error;
}

int test_log()
{
	int Error(0);

	float A = glm::log(10.f);
	glm::vec1 B = glm::log(glm::vec1(10.f));
	glm::vec2 C = glm::log(glm::vec2(10.f));
	glm::vec3 D = glm::log(glm::vec3(10.f));
	glm::vec4 E = glm::log(glm::vec4(10.f));

	return Error;
}

int test_exp2()
{
	int Error(0);

	float A = glm::exp2(10.f);
	glm::vec1 B = glm::exp2(glm::vec1(10.f));
	glm::vec2 C = glm::exp2(glm::vec2(10.f));
	glm::vec3 D = glm::exp2(glm::vec3(10.f));
	glm::vec4 E = glm::exp2(glm::vec4(10.f));

	return Error;
}

int test_log2()
{
	int Error(0);

	float A = glm::log2(10.f);
	glm::vec1 B = glm::log2(glm::vec1(10.f));
	glm::vec2 C = glm::log2(glm::vec2(10.f));
	glm::vec3 D = glm::log2(glm::vec3(10.f));
	glm::vec4 E = glm::log2(glm::vec4(10.f));

	return Error;
}

int test_sqrt()
{
	int Error(0);

#	if GLM_ARCH & GLM_ARCH_SSE2_BIT
	for(float f = 0.1f; f < 30.0f; f += 0.1f)
	{
		float r = _mm_cvtss_f32(_mm_sqrt_ps(_mm_set1_ps(f)));
		float s = std::sqrt(f);
		Error += glm::abs(r - s) < 0.01f ? 0 : 1;
		assert(!Error);
	}
#	endif//GLM_ARCH & GLM_ARCH_SSE2_BIT

	float A = glm::sqrt(10.f);
	glm::vec1 B = glm::sqrt(glm::vec1(10.f));
	glm::vec2 C = glm::sqrt(glm::vec2(10.f));
	glm::vec3 D = glm::sqrt(glm::vec3(10.f));
	glm::vec4 E = glm::sqrt(glm::vec4(10.f));

	return Error;
}

int test_inversesqrt()
{
	int Error(0);

	glm::uint ulp(0);
	float diff(0.0f);

	for(float f = 0.001f; f < 10.f; f *= 1.01f)
	{
		glm::lowp_fvec1 u(f);
		glm::lowp_fvec1 lowp_v = glm::inversesqrt(u);
		float defaultp_v = glm::inversesqrt(f);

		ulp = glm::max(glm::float_distance(lowp_v.x, defaultp_v), ulp);
		diff = glm::abs(lowp_v.x - defaultp_v);
		Error += diff > 0.1f ? 1 : 0;
	}

	return Error;
}

int main()
{
	int Error(0);

#if !(GLM_COMPILER & GLM_COMPILER_GCC)

	Error += test_pow();
	Error += test_exp();
	Error += test_log();
	Error += test_exp2();
	Error += test_log2();
	Error += test_sqrt();
	Error += test_inversesqrt();

#endif//GLM_COMPILER & GLM_COMPILER_GCC

	return Error;
}

