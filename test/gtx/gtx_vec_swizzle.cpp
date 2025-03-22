#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/vec_swizzle.hpp>

int main()
{
	int Error = 0;





	{
		glm::ivec2 const v(1, 2);
		Error += xx(v).x != xx(v).y;
		Error += yy(v).x != yy(v).y;
	}

	{
		glm::ivec3 const v(1, 2, 3);
		Error += zyx(v) != glm::ivec3(3, 2, 1);
	}

	{
		glm::ivec4 const v(1, 2, 3, 4);
		Error += wwww(v) != glm::ivec4(4);
		Error += wzyx(v) != glm::ivec4(4,3,2,1);

	}

	return Error;
}

