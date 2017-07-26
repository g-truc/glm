#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/epsilon.hpp>
#include <glm/gtx/intersect.hpp>

int test_intersectRayTriangle()
{
	int Error = 0;

	glm::vec3 const Orig(0, 0, 2);
	glm::vec3 const Dir(0, 0, -1);
	glm::vec3 const Vert0(0, 0, 0);
	glm::vec3 const Vert1(-1, -1, 0);
	glm::vec3 const Vert2(1, -1, 0);
	glm::vec2 BaryPosition(0);
	float Distance = 0;

	bool const Result = glm::intersectRayTriangle(Orig, Dir, Vert0, Vert1, Vert2, BaryPosition, Distance);

	Error += glm::all(glm::epsilonEqual(BaryPosition, glm::vec2(0), std::numeric_limits<float>::epsilon())) ? 0 : 1;
	Error += glm::abs(Distance - 2.f) <= std::numeric_limits<float>::epsilon() ? 0 : 1;
	Error += Result ? 0 : 1;

	return Error;
}

int main()
{
	int Error = 0;

	Error += test_intersectRayTriangle();

	return Error;
}
