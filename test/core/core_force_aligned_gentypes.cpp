#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <cstdio>

#		if GLM_SILENT_WARNINGS == GLM_ENABLE
#			if GLM_COMPILER & GLM_COMPILER_GCC
#				pragma GCC diagnostic push
#				pragma GCC diagnostic ignored "-Wpedantic"
#				pragma GCC diagnostic ignored "-Wattributes" // for alignas(1), packed types
#			elif GLM_COMPILER & GLM_COMPILER_CLANG
#				pragma clang diagnostic push
#				pragma clang diagnostic ignored "-Wgnu-anonymous-struct"
#				pragma clang diagnostic ignored "-Wnested-anon-types"
#				pragma clang diagnostic ignored "-Wpadded"
#			elif GLM_COMPILER & GLM_COMPILER_VC
#				pragma warning(push)
#				pragma warning(disable: 4201)  // nonstandard extension used : nameless struct/union
#				pragma warning(disable: 4324)
#			endif
#		endif

struct test_packed4 {
	float x;
	float y;
	float z;
	float w;
};

struct alignas(sizeof(float) * 4) test_aligned4 {
	float x;
	float y;
	float z;
};

struct test_packed3 {
	float x;
	float y;
	float z;
};

struct alignas(sizeof(float) * 4) test_aligned3 {
	float x;
	float y;
	float z;
};

int main()
{
	int Error = 0;

	printf("alignof(test_packed4): %d\n", static_cast<int>(alignof(test_packed4)));
	printf("alignof(test_aligned4): %d\n", static_cast<int>(alignof(test_aligned4)));
	printf("alignof(test_packed3): %d\n", static_cast<int>(alignof(test_packed3)));
	printf("alignof(test_aligned3): %d\n", static_cast<int>(alignof(test_aligned3)));

	printf("alignof(packed_quat): %d\n", static_cast<int>(alignof(glm::packed_quat)));
	printf("alignof(glm::aligned_quat): %d\n", static_cast<int>(alignof(glm::aligned_quat)));
	printf("alignof(glm::quat): %d\n", static_cast<int>(alignof(glm::quat)));

	return Error;
}

#		if GLM_SILENT_WARNINGS == GLM_ENABLE
#			if GLM_COMPILER & GLM_COMPILER_CLANG
#				pragma clang diagnostic pop
#			elif GLM_COMPILER & GLM_COMPILER_GCC
#				pragma GCC diagnostic pop
#			elif GLM_COMPILER & GLM_COMPILER_VC
#				pragma warning(pop)
#			endif
#		endif


