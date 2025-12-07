#ifdef GLM_FORCE_CXX_UNKNOWN
#undef GLM_FORCE_CXX_UNKNOWN
#endif
#ifdef GLM_FORCE_CXX20
#undef GLM_FORCE_CXX20
#endif
#ifdef GLM_FORCE_CXX17
#undef GLM_FORCE_CXX17
#endif

#define GLM_FORCE_CXX20

#include <glm/glm.hpp>
#include <glm/ext.hpp>

int main()
{
	int Error = 0;

	return Error;
}
