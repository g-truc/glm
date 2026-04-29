#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/polar_coordinates.hpp>

#include <glm/gtc/constants.hpp>
#include <glm/gtc/epsilon.hpp>
#include <glm/ext/vector_relational.hpp>

static int test_revertConversion()
{
	int Error = 0;

	glm::vec3 const Polar = {glm::quarter_pi<float>(), glm::quarter_pi<float>(), 10.0f};
	glm::vec3 const Euclidean = glm::euclidean(Polar);
	glm::vec3 const PolarAgain = glm::polar(Euclidean);
	glm::vec3 const EuclideanAgain = glm::euclidean(PolarAgain);

	Error += glm::all(glm::equal(Polar, PolarAgain, 0.001f)) ? 0 : 1;
	Error += glm::all(glm::equal(Euclidean, EuclideanAgain, 0.001f)) ? 0 : 1;

	return Error;
}

static int test_originConversion()
{
	int Error = 0;

	glm::vec3 const EuclideanOrigin = {0.0f, 0.0f, 0.0f};
	glm::vec3 const PolarOrigin = glm::polar(EuclideanOrigin);
	glm::vec3 const EuclideanOriginAgain = glm::euclidean(PolarOrigin);

	Error += glm::epsilonEqual(PolarOrigin.z, 0.0f, 0.001f) ? 0 : 1;
	Error += glm::all(glm::equal(EuclideanOrigin, EuclideanOriginAgain, 0.001f)) ? 0 : 1;

	return Error;
}

int main()
{
	int Error = 0;

	Error += test_revertConversion();
	Error += test_originConversion();

	return Error;
}
