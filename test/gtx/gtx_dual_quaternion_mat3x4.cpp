#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/dual_quaternion.hpp>

template<typename T>
static int test_mat3x4_cast()
{
	int Error = 0;
	glm::qua<T> const Rotation(static_cast<T>(1), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0));
	glm::vec<3, T> const Translation(static_cast<T>(2), static_cast<T>(-3), static_cast<T>(4));
	glm::tdualquat<T> const Transform(Rotation, Translation);
	glm::mat<3, 4, T> const Matrix = glm::mat3x4_cast(Transform);
	glm::mat<3, 4, T> const Expected(
		glm::vec<4, T>(1, 0, 0, 2),
		glm::vec<4, T>(0, 1, 0, -3),
		glm::vec<4, T>(0, 0, 1, 4));
	Error += Matrix == Expected ? 0 : 1;
	Error += glm::mat3x4_cast(Transform * static_cast<T>(2)) == Expected ? 0 : 1;
	return Error;
}

int main()
{
	return test_mat3x4_cast<float>() + test_mat3x4_cast<double>();
}
