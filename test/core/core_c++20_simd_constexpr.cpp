#define GLM_SIMD_CONSTEXPR 1
#include <glm/glm.hpp>
#include <glm/vec4.hpp>
#include <cstdio>
#include <ctime>
#include <vector>
#include <cstdlib>
#define GLM_FORCE_ALIGNED_GENTYPES 1
#include <glm/detail/qualifier.hpp>
#if GLM_COMPILER & GLM_COMPILER_CLANG
#       pragma clang diagnostic push
#       pragma clang diagnostic ignored "-Wglobal-constructors"
#       pragma clang diagnostic ignored "-Wunused-variable"
#endif

int main()
{
        static_assert(GLM_ARCH & GLM_ARCH_SIMD_BIT);
        static_assert(GLM_CONFIG_SIMD);
        static_assert(GLM_ARCH_SIMD_BIT);
       
        
        using avec4 = glm::vec<4, float, glm::aligned_highp>;
        static constexpr avec4 v{1.0f};//, 1.1f, 1.2f, 1.0f};
        avec4 v1{static_cast<float>(rand() % 2)};
        avec4 v2{static_cast<float>(rand() % 2)};//, static_cast<float>(rand() % 255), static_cast<float>(rand() % 255), static_cast<float>(rand() % 255)};
	static constexpr avec4 v3 = avec4{1.5f,2.0f,3.0f,4.0f};
				static constexpr avec4 v4 = v3;
				printf("v1 = %f %f %f %f\n", v1[0], v1[1], v1[2], v1[3]);
				printf("v2 = %f %f %f %f\n", v2[0], v2[1], v2[2], v2[3]);
				v1.x;
        avec4 vfin = glm::max(v1, v2) + v3;
	static_assert(sizeof(vfin)>0);
        printf("vfin = %f %f %f %f\n", vfin[0], vfin[1], vfin[2], vfin[3]);
				printf("v3 = %f %f %f %f\n", v3[0], v3[1], v3[2], v3[3]);
	return 0;
}
