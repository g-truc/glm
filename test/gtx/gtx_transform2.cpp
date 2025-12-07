#include <glm/glm.hpp>
#include <glm/gtc/epsilon.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/transform2.hpp>

static int test_reflect2D()
{
	int Error = 0;

	{
		const glm::mat3 m3(
			1, 0, 0,
			0, 1, 0,
			1, 2, 1
		);

		const glm::mat3 eam3(
			1, 0, 0,
			0, -1, 0,
			1, 2, 1
		);

		const glm::mat3 am3 = glm::reflect2D(
			m3,
			glm::vec2(0, 1),
			static_cast<glm::mat3::row_type::value_type>(0)
		);

		Error += glm::all(glm::bvec3(
			glm::all(glm::epsilonEqual(eam3[0], am3[0], glm::epsilon<float>())),
			glm::all(glm::epsilonEqual(eam3[1], am3[1], glm::epsilon<float>())),
			glm::all(glm::epsilonEqual(eam3[2], am3[2], glm::epsilon<float>())))) ? 0 : 1;
	}

	{
		const glm::mat3 m3(
			1, 0, 0,
			0, 1, 0,
			1, 2, 1
		);

		const glm::mat3 eam3(
			0, 1, 0,
			1, 0, 0,
			1, 2, 1
		);

		const glm::mat3 am3 = glm::reflect2D(
			m3,
			glm::vec2(-0.70710678, 0.70710678),
			static_cast<glm::mat3::row_type::value_type>(0)
		);

		Error += glm::all(glm::bvec3(
			glm::all(glm::epsilonEqual(eam3[0], am3[0], glm::epsilon<float>())),
			glm::all(glm::epsilonEqual(eam3[1], am3[1], glm::epsilon<float>())),
			glm::all(glm::epsilonEqual(eam3[2], am3[2], glm::epsilon<float>())))) ? 0 : 1;
	}
		
	return Error;
}

static int test_reflect3D()
{
	int Error = 0;

	{
		const glm::mat4 m4(
			1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		);

		const glm::mat4 eam4(
			1, 0, 0, 0,
			0, -1, 0, 0,
			0, 0, 1, 0,
			0, -2, 0, 1
		);

		const glm::mat4 am4 = glm::reflect3D(
			m4,
			glm::vec3(0, 1, 0),
			static_cast<glm::mat4::row_type::value_type>(1)
		);

		Error += glm::all(glm::bvec4(
			glm::all(glm::epsilonEqual(eam4[0], am4[0], glm::epsilon<float>())),
			glm::all(glm::epsilonEqual(eam4[1], am4[1], glm::epsilon<float>())),
			glm::all(glm::epsilonEqual(eam4[2], am4[2], glm::epsilon<float>())),
			glm::all(glm::epsilonEqual(eam4[3], am4[3], glm::epsilon<float>())))) ? 0 : 1;
	}

	{
		const glm::mat4 m4(
			1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		);

		const glm::mat4 eam4(
			0, 1, 0, 0,
			1, 0, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		);

		const glm::mat4 am4 = glm::reflect3D(
			m4,
			glm::vec3(-0.70710678, 0.70710678, 0.0),
			static_cast<glm::mat4::row_type::value_type>(0)
		);

		Error += glm::all(glm::bvec4(
			glm::all(glm::epsilonEqual(eam4[0], am4[0], glm::epsilon<float>())),
			glm::all(glm::epsilonEqual(eam4[1], am4[1], glm::epsilon<float>())),
			glm::all(glm::epsilonEqual(eam4[2], am4[2], glm::epsilon<float>())),
			glm::all(glm::epsilonEqual(eam4[3], am4[3], glm::epsilon<float>())))) ? 0 : 1;
	}

	return Error;
}

int main()
{
	int Error = 0;

	Error += test_reflect2D();
	Error += test_reflect3D();

	return Error;
}
