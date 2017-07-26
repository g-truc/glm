#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/matrix_factorisation.hpp>

float const epsilon = 1e-10f;

template <glm::length_t C, glm::length_t R, typename T, glm::precision P, template<glm::length_t, glm::length_t, typename, glm::precision> class matType>
int test_qr(matType<C, R, T, P> m)
{
	int Error = 0;

	matType<(C < R ? C : R), R, T, P> q(-999);
	matType<C, (C < R ? C : R), T, P> r(-999);

	glm::qr_decompose(m, q, r);

	//Test if q*r really equals the input matrix
	matType<C, R, T, P> tm = q*r;
	matType<C, R, T, P> err = tm - m;

	for (glm::length_t i = 0; i < C; i++)
	for (glm::length_t j = 0; j < R; j++)
		Error += std::abs(err[i][j]) > epsilon ? 1 : 0;

	//Test if the columns of q are orthonormal
	for (glm::length_t i = 0; i < (C < R ? C : R); i++)
	{
		Error += (length(q[i]) - 1) > epsilon ? 1 : 0;

		for (glm::length_t j = 0; j<i; j++)
			Error += std::abs(dot(q[i], q[j])) > epsilon ? 1 : 0;
	}

	//Test if the matrix r is upper triangular
	for (glm::length_t i = 0; i < C; i++)
	for (glm::length_t j = i + 1; j < (C < R ? C : R); j++)
			Error += r[i][j] != 0 ? 1 : 0;

	return Error;
}

template <glm::length_t C, glm::length_t R, typename T, glm::precision P, template<glm::length_t, glm::length_t, typename, glm::precision> class matType>
int test_rq(matType<C, R, T, P> m)
{
	int Error = 0;

	matType<C, (C < R ? C : R), T, P> q(-999);
	matType<(C < R ? C : R), R, T, P> r(-999);

	glm::rq_decompose(m, r, q);

	//Test if q*r really equals the input matrix
	matType<C, R, T, P> tm = r*q;
	matType<C, R, T, P> err = tm - m;

	for (glm::length_t i = 0; i < C; i++)
	for (glm::length_t j = 0; j < R; j++)
		Error += std::abs(err[i][j]) > epsilon ? 1 : 0;

	//Test if the rows of q are orthonormal
	matType<(C < R ? C : R), C, T, P> tq = transpose(q);

	for (glm::length_t i = 0; i < (C < R ? C : R); i++)
	{
		Error += (length(tq[i]) - 1) > epsilon ? 1 : 0;

		for (glm::length_t j = 0; j<i; j++)
			Error += std::abs(dot(tq[i], tq[j])) > epsilon ? 1 : 0;
	}

	//Test if the matrix r is upper triangular
	for (glm::length_t i = 0; i < (C < R ? C : R); i++)
	for (glm::length_t j = R - (C < R ? C : R) + i + 1; j < R; j++)
		Error += r[i][j] != 0 ? 1 : 0;

	return Error;
}

int main()
{
	int Error = 0;

	//Test QR square
	Error += test_qr(glm::dmat3(12, 6, -4, -51, 167, 24, 4, -68, -41)) ? 1 : 0;

	//Test RQ square
	Error += test_rq(glm::dmat3(12, 6, -4, -51, 167, 24, 4, -68, -41)) ? 1 : 0;

	//Test QR triangular 1
	Error += test_qr(glm::dmat3x4(12, 6, -4, -51, 167, 24, 4, -68, -41, 7, 2, 15)) ? 1 : 0;

	//Test QR triangular 2
	Error += test_qr(glm::dmat4x3(12, 6, -4, -51, 167, 24, 4, -68, -41, 7, 2, 15)) ? 1 : 0;

	//Test RQ triangular 1 : Fails at the triangular test
	Error += test_rq(glm::dmat3x4(12, 6, -4, -51, 167, 24, 4, -68, -41, 7, 2, 15)) ? 1 : 0;

	//Test QR triangular 2
	Error += test_rq(glm::dmat4x3(12, 6, -4, -51, 167, 24, 4, -68, -41, 7, 2, 15)) ? 1 : 0;

	return Error;
}
