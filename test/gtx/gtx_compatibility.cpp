#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/compatibility.hpp>

// This file has divisions by zero to test isnan
#if GLM_COMPILER & GLM_COMPILER_VC
#	pragma warning(push)
#	pragma warning(disable : 4723)
#endif

int main()
{
	int Error(0);

	float Zero_f = 0.0;
	double Zero_d = 0.0;

	Error += glm::isfinite(1.0f) ? 0 : 1;
	Error += glm::isfinite(1.0) ? 0 : 1;
	Error += glm::isfinite(-1.0f) ? 0 : 1;
	Error += glm::isfinite(-1.0) ? 0 : 1;

	Error += glm::all(glm::isfinite(glm::vec4(1.0f))) ? 0 : 1;
	Error += glm::all(glm::isfinite(glm::dvec4(1.0))) ? 0 : 1;
	Error += glm::all(glm::isfinite(glm::vec4(-1.0f))) ? 0 : 1;
	Error += glm::all(glm::isfinite(glm::dvec4(-1.0))) ? 0 : 1;

	Error += glm::all(glm::isfinite(glm::quat(1.0f, 1.0f, 1.0f, 1.0f))) ? 0 : 1;
	Error += glm::all(glm::isfinite(glm::dquat(1.0, 1.0, 1.0, 1.0))) ? 0 : 1;
	Error += glm::all(glm::isfinite(glm::quat(-1.0f, -1.0f, -1.0f, -1.0f))) ? 0 : 1;
	Error += glm::all(glm::isfinite(glm::dquat(-1.0, -1.0, -1.0, -1.0))) ? 0 : 1;

	Error += glm::isfinite(0.0f/Zero_f) ? 1 : 0;
	Error += glm::isfinite(0.0/Zero_d) ? 1 : 0;
	Error += glm::isfinite(1.0f/Zero_f) ? 1 : 0;
	Error += glm::isfinite(1.0/Zero_d) ? 1 : 0;
	Error += glm::isfinite(-1.0f/Zero_f) ? 1 : 0;
	Error += glm::isfinite(-1.0/Zero_d) ? 1 : 0;

	Error += glm::any(glm::isfinite(glm::vec4(0.0f/Zero_f))) ? 1 : 0;
	Error += glm::any(glm::isfinite(glm::dvec4(0.0/Zero_d))) ? 1 : 0;
	Error += glm::any(glm::isfinite(glm::vec4(1.0f/Zero_f))) ? 1 : 0;
	Error += glm::any(glm::isfinite(glm::dvec4(1.0/Zero_d))) ? 1 : 0;
	Error += glm::any(glm::isfinite(glm::vec4(-1.0f/Zero_f))) ? 1 : 0;
	Error += glm::any(glm::isfinite(glm::dvec4(-1.0/Zero_d))) ? 1 : 0;

	Error += glm::any(glm::isfinite(glm::quat(0.0f/Zero_f, 0.0f/Zero_f, 0.0f/Zero_f, 0.0f/Zero_f))) ? 1 : 0;
	Error += glm::any(glm::isfinite(glm::dquat(0.0/Zero_d, 0.0/Zero_d, 0.0/Zero_d, 0.0/Zero_d))) ? 1 : 0;
	Error += glm::any(glm::isfinite(glm::quat(1.0f/Zero_f, 1.0f/Zero_f, 1.0f/Zero_f, 1.0f/Zero_f))) ? 1 : 0;
	Error += glm::any(glm::isfinite(glm::dquat(1.0/Zero_d, 1.0/Zero_d, 1.0/Zero_d, 1.0/Zero_d))) ? 1 : 0;
	Error += glm::any(glm::isfinite(glm::quat(-1.0f/Zero_f, -1.0f/Zero_f, -1.0f/Zero_f, -1.0f/Zero_f))) ? 1 : 0;
	Error += glm::any(glm::isfinite(glm::dquat(-1.0/Zero_d, -1.0/Zero_d, -1.0/Zero_d, -1.0/Zero_d))) ? 1 : 0;

	return Error;
}

#if(GLM_COMPILER & GLM_COMPILER_VC)
#	pragma warning(pop)
#endif
