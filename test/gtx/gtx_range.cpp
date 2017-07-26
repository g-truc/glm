#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/epsilon.hpp>

#if GLM_HAS_RANGE_FOR

#include <glm/gtx/range.hpp>

int testVec()
{
	int Error(0);
	glm::vec3 v(1, 2, 3);

	int count = 0;
	for(float x : v){ count++; }
	Error += count == 3 ? 0 : 1;

	for(float& x : v){ x = 0; }
	Error += glm::all(glm::equal(v, glm::vec3(0, 0, 0))) ? 0 : 1;
	return Error;
}

int testMat()
{
	int Error(0);
	glm::mat4x3 m(1);

	int count = 0;
	for(float x : m){ count++; }
	Error += count == 12 ? 0 : 1;

	for(float& x : m){ x = 0; }
	glm::vec4 v(1, 1, 1, 1);
	Error += glm::all(glm::equal(m*v, glm::vec3(0, 0, 0))) ? 0 : 1;
	return Error;
}

int main()
{
	int Error(0);
	Error += testVec();
	Error += testMat();
	return Error;
}

#else

int main()
{
	return 0;
}

#endif//GLM_HAS_RANGE_FOR
