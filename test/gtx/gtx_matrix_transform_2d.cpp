#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/matrix_transform_2d.hpp>
#include <glm/gtc/constants.hpp>
#include <glm/ext/matrix_relational.hpp>
#include <glm/ext/matrix_float3x3.hpp>
#include <glm/ext/vector_relational.hpp>
#include <glm/ext/vector_float3.hpp>
#include <glm/ext/vector_float2.hpp>

static int test_translate()
{
	int Error = 0;

	glm::mat3 const M(1.0f);
	glm::vec2 const V(1.0f);

	glm::mat3 const T = glm::translate(M, V);
	Error += glm::all(glm::equal(T[2], glm::vec3(1.0f), glm::epsilon<float>())) ? 0 : 1;

	return Error;
}

static int test_rotate()
{
	int Error = 0;

	glm::vec3 const A(1.0f, 0.0f, 1.0f);
	float constexpr a = glm::radians(90.f);

	glm::mat3 const R = glm::rotate(glm::mat3(1.0f), a);
	glm::vec3 const B = R * A;
	Error += glm::all(glm::equal(B, glm::vec3(0.0f, 1.0f, 1.0f), glm::epsilon<float>())) ? 0 : 1;

	return Error;
}

static int test_scale()
{
	int Error = 0;

	glm::mat3 const M(1.0f);
	glm::vec2 const V(2.0f);

	glm::mat3 const S = glm::scale(M, V);
	glm::mat3 const R = glm::mat3(
		glm::vec3(2, 0, 0),
		glm::vec3(0, 2, 0),
		glm::vec3(0, 0, 1));
	Error += glm::all(glm::equal(S, R, glm::epsilon<float>())) ? 0 : 1;

	return Error;
}

static int test_shearX()
{
	int Error = 0;

	glm::mat3 const M(1.0f);
	float constexpr y = 1.0f;

	glm::mat3 const S = glm::shearX(M, y);
	glm::vec3 const V = S * glm::vec3(1.0f);
	Error += glm::all(glm::equal(V, glm::vec3(1.0f, 2.0f, 1.0f), glm::epsilon<float>())) ? 0 : 1;

	return Error;
}

static int test_shearY()
{
	int Error = 0;

	glm::mat3 const M(1.0f);
	float constexpr x = 1.0f;

	glm::mat3 const S = glm::shearY(M, x);
	glm::vec3 const V = S * glm::vec3(1.0f);
	Error += glm::all(glm::equal(V, glm::vec3(2.0f, 1.0f, 1.0f), glm::epsilon<float>())) ? 0 : 1;

	return Error;
}

static int test_shear()
{
	int Error = 0;

	glm::mat3 const M(1.0f);
	glm::vec2 const s(1.0f);

	glm::mat3 const S = glm::shear(M, s);
	glm::vec3 const V = S * glm::vec3(1.0f);
	Error += glm::all(glm::equal(V, glm::vec3(3.0f, 2.0f, 1.0f), glm::epsilon<float>())) ? 0 : 1;

	return Error;
}

int main()
{
	int Error(0);

	Error += test_translate();
	Error += test_rotate();
	Error += test_scale();
	Error += test_shearX();
	Error += test_shearY();
	Error += test_shear();

	return Error;
}
