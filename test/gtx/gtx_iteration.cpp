#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/iteration.hpp>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

// Testing if adl works if it doesn't a compiler error is generated
// Note all usages of glm::begin,glm::end,glm::rbegin,glm::rend 
// in this file is via adl
template<typename T>
void begin(T) {}
template<typename T>
void rbegin(T) {}
template<typename T>
void end(T) {}
template<typename T>
void rend(T) {}


template<typename T>
std::ptrdiff_t get_iter_distance() {
	T t = T(); // needed for const initializing
	return std::distance(begin(t), end(t));
}

template<typename T>
std::ptrdiff_t get_rev_iter_distance() {
	T t = T(); // needed for const initializing
	return std::distance(rbegin(t), rend(t));
}


template<typename GenTypc>
int rangedSumComp(GenTypc& genType, int compsum) {
	int Error = 0;

#if defined(__cpp_range_based_for)
#if __cpp_range_based_for >= 200907L
	{
		int sum = 0;
		for (const int& elem : genType)
			sum += elem;
		Error += sum != compsum;
	}
#endif
#endif
	{
		int sum = 0;
		for (const int* it = begin(genType); it != end(genType); ++it)
			sum += *it;
		Error += sum != compsum;
	}

	{
		int sum = 0;
		for (std::reverse_iterator<const int*> it = rbegin(genType); it != rend(genType); ++it)
			sum += *it;
		Error += sum != compsum;
	}
	return Error;
}

template<glm::length_t L>
int sumVec() {
	glm::vec<L, int> v;
	int sumManual = 0;
	for (int i = 0; i < L; ++i) {
		v[i] = i;
		sumManual += i;
	}
	glm::vec<L, int> const cv = v;

	return (sumManual != std::accumulate(begin(v), end(v), 0))
		+ (sumManual != std::accumulate(begin(cv), end(cv), 0))
		+ (sumManual != std::accumulate(rbegin(v), rend(v), 0))
		+ (sumManual != std::accumulate(rbegin(cv), rend(cv), 0))
		+ rangedSumComp(v, sumManual)
		+ rangedSumComp(cv, sumManual);
}

template<glm::length_t C, glm::length_t R>
int sumMat() {
	glm::mat<C, R, int> m;
	int sumManual = 0;
	for (int i = 0; i < C; ++i) {
		for (int j = 0; j < R; ++j) {
			m[i][j] = i * j;
			sumManual += i * j;
		}
	}
	glm::mat<C, R, int> const cm = m;
	return (sumManual != std::accumulate(begin(m), end(m), 0))
		+ (sumManual != std::accumulate(begin(cm), end(cm), 0))
		+ (sumManual != std::accumulate(rbegin(m), rend(m), 0))
		+ (sumManual != std::accumulate(rbegin(cm), rend(cm), 0))
		+ rangedSumComp(m, sumManual)
		+ rangedSumComp(cm, sumManual);
}

static int sumQuat() {
	glm::qua<int> q(0, 1, 2, 3);
	glm::qua<int> const cq(0, 1, 2, 3);
	const int sumManual = (0 + 1 + 2 + 3);
	return (sumManual != std::accumulate(begin(q), end(q), 0))
		+ (sumManual != std::accumulate(begin(cq), end(cq), 0))
		+ (sumManual != std::accumulate(rbegin(q), rend(q), 0))
		+ (sumManual != std::accumulate(rbegin(cq), rend(cq), 0))
		+ rangedSumComp(q, sumManual)
		+ rangedSumComp(cq, sumManual);
}


int main()
{
	int Error = 0;

	Error += (1 != get_iter_distance<glm::vec1>());
	Error += (2 != get_iter_distance<glm::vec2>());
	Error += (3 != get_iter_distance<glm::vec3>());
	Error += (4 != get_iter_distance<glm::vec4>());

	Error += (1 != get_iter_distance<const glm::vec1>());
	Error += (2 != get_iter_distance<const glm::vec2>());
	Error += (3 != get_iter_distance<const glm::vec3>());
	Error += (4 != get_iter_distance<const glm::vec4>());

	Error += (4 != get_iter_distance<glm::quat>());
	Error += (4 != get_iter_distance<const glm::quat>());

	Error += (2 * 2 != get_iter_distance<glm::mat2x2>());
	Error += (2 * 3 != get_iter_distance<glm::mat2x3>());
	Error += (2 * 4 != get_iter_distance<glm::mat2x4>());

	Error += (2 * 2 != get_iter_distance<const glm::mat2x2>());
	Error += (2 * 3 != get_iter_distance<const glm::mat2x3>());
	Error += (2 * 4 != get_iter_distance<const glm::mat2x4>());

	Error += (3 * 2 != get_iter_distance<glm::mat3x2>());
	Error += (3 * 3 != get_iter_distance<glm::mat3x3>());
	Error += (3 * 4 != get_iter_distance<glm::mat3x4>());

	Error += (3 * 2 != get_iter_distance<const glm::mat3x2>());
	Error += (3 * 3 != get_iter_distance<const glm::mat3x3>());
	Error += (3 * 4 != get_iter_distance<const glm::mat3x4>());

	Error += (4 * 2 != get_iter_distance<glm::mat4x2>());
	Error += (4 * 3 != get_iter_distance<glm::mat4x3>());
	Error += (4 * 4 != get_iter_distance<glm::mat4x4>());

	Error += (4 * 2 != get_iter_distance<const glm::mat4x2>());
	Error += (4 * 3 != get_iter_distance<const glm::mat4x3>());
	Error += (4 * 4 != get_iter_distance<const glm::mat4x4>());


	Error += (1 != get_rev_iter_distance<glm::vec1>());
	Error += (2 != get_rev_iter_distance<glm::vec2>());
	Error += (3 != get_rev_iter_distance<glm::vec3>());
	Error += (4 != get_rev_iter_distance<glm::vec4>());

	Error += (1 != get_rev_iter_distance<const glm::vec1>());
	Error += (2 != get_rev_iter_distance<const glm::vec2>());
	Error += (3 != get_rev_iter_distance<const glm::vec3>());
	Error += (4 != get_rev_iter_distance<const glm::vec4>());

	Error += (4 != get_rev_iter_distance<glm::quat>());
	Error += (4 != get_rev_iter_distance<const glm::quat>());

	Error += (2 * 2 != get_rev_iter_distance<glm::mat2x2>());
	Error += (2 * 3 != get_rev_iter_distance<glm::mat2x3>());
	Error += (2 * 4 != get_rev_iter_distance<glm::mat2x4>());

	Error += (2 * 2 != get_rev_iter_distance<const glm::mat2x2>());
	Error += (2 * 3 != get_rev_iter_distance<const glm::mat2x3>());
	Error += (2 * 4 != get_rev_iter_distance<const glm::mat2x4>());


	Error += (3 * 2 != get_rev_iter_distance<glm::mat3x2>());
	Error += (3 * 3 != get_rev_iter_distance<glm::mat3x3>());
	Error += (3 * 4 != get_rev_iter_distance<glm::mat3x4>());

	Error += (3 * 2 != get_rev_iter_distance<const glm::mat3x2>());
	Error += (3 * 3 != get_rev_iter_distance<const glm::mat3x3>());
	Error += (3 * 4 != get_rev_iter_distance<const glm::mat3x4>());

	Error += (4 * 2 != get_rev_iter_distance<glm::mat4x2>());
	Error += (4 * 3 != get_rev_iter_distance<glm::mat4x3>());
	Error += (4 * 4 != get_rev_iter_distance<glm::mat4x4>());

	Error += (4 * 2 != get_rev_iter_distance<const glm::mat4x2>());
	Error += (4 * 3 != get_rev_iter_distance<const glm::mat4x3>());
	Error += (4 * 4 != get_rev_iter_distance<const glm::mat4x4>());

	Error += sumVec<1>();
	Error += sumVec<2>();
	Error += sumVec<3>();
	Error += sumVec<4>();

	Error += sumMat<2, 2>();
	Error += sumMat<2, 3>();
	Error += sumMat<2, 4>();

	Error += sumMat<3, 2>();
	Error += sumMat<3, 3>();
	Error += sumMat<3, 4>();

	Error += sumMat<4, 2>();
	Error += sumMat<4, 3>();
	Error += sumMat<4, 4>();

	Error += sumQuat();

	return Error;
}
