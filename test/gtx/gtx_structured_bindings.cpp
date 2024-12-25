#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/structured_bindings.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/vec1.hpp>

static int test_vec1() {
	glm::vec1 v(0);
	float& x = glm::get<0>(v);
	return (&x != &v.x);
}

static int test_vec2() {
	glm::vec2 v(0);
	float& x = glm::get<0>(v);
	float& y = glm::get<1>(v);
	return (&x != &v.x) + (&y != &v.y);
}

static int test_vec3() {
	glm::vec3 v(0);
	float& x = glm::get<0>(v);
	float& y = glm::get<1>(v);
	float& z = glm::get<2>(v);
	return (&x != &v.x) + (&y != &v.y) + (&z != &v.z);
}

static int test_vec4() {
	glm::vec4 v(0);
	float& x = glm::get<0>(v);
	float& y = glm::get<1>(v);
	float& z = glm::get<2>(v);
	float& w = glm::get<3>(v);

	return (&x != &v.x) + (&y != &v.y) + (&z != &v.z) + (&w != &v.w);
}

static int test_const_vec1() {
	glm::vec1 const v(0);
	float const& x = glm::get<0>(v);
	return (&x != &v.x);
}

static int test_const_vec2() {
	glm::vec2 const v(0);
	float const& x = glm::get<0>(v);
	float const& y = glm::get<1>(v);
	return (&x != &v.x) + (&y != &v.y);
}

static int test_const_vec3() {
	glm::vec3 const v(0);
	float const& x = glm::get<0>(v);
	float const& y = glm::get<1>(v);
	float const& z = glm::get<2>(v);
	return (&x != &v.x) + (&y != &v.y) + (&z != &v.z);
}

static int test_const_vec4() {
	glm::vec4 const v(0);
	float const& x = glm::get<0>(v);
	float const& y = glm::get<1>(v);
	float const& z = glm::get<2>(v);
	float const& w = glm::get<3>(v);

	return (&x != &v.x) + (&y != &v.y) + (&z != &v.z) + (&w != &v.w);
}


static int test_quat() {
	glm::quat q(0.0f, 0.0f, 0.0f, 0.0f);
#ifdef GLM_FORCE_QUAT_DATA_WXYZ
	float& w = glm::get<0>(q);
	float& x = glm::get<1>(q);
	float& y = glm::get<2>(q);
	float& z = glm::get<3>(q);
#else
	float& x = glm::get<0>(q);
	float& y = glm::get<1>(q);
	float& z = glm::get<2>(q);
	float& w = glm::get<3>(q);
#endif
	return (&x != &q.x) + (&y != &q.y) + (&z != &q.z) + (&w != &q.w);
}

static int test_const_quat() {
	glm::quat const q(0.0f, 0.0f, 0.0f, 0.0f);
#ifdef GLM_FORCE_QUAT_DATA_WXYZ
	float const& w = glm::get<0>(q);
	float const& x = glm::get<1>(q);
	float const& y = glm::get<2>(q);
	float const& z = glm::get<3>(q);
#else
	float const& x = glm::get<0>(q);
	float const& y = glm::get<1>(q);
	float const& z = glm::get<2>(q);
	float const& w = glm::get<3>(q);
#endif
	return (&x != &q.x) + (&y != &q.y) + (&z != &q.z) + (&w != &q.w);
}


template<glm::length_t R>
static int test_mat2xR() {
	typedef glm::mat<2, R, float> Mat;
	Mat m(0);
	typename Mat::col_type& c1 = glm::get<0>(m);
	typename Mat::col_type& c2 = glm::get<1>(m);
	return (&c1 != &m[0]) + (&c2 != &m[1]);
}
template<glm::length_t R>
static int test_const_mat2xR() {
	typedef glm::mat<2,R,float> Mat;
	Mat const m(0);
	typename Mat::col_type const& c1 = glm::get<0>(m);
	typename Mat::col_type const& c2 = glm::get<1>(m);
	return (&c1 != &m[0]) + (&c2 != &m[1]);
}

template<glm::length_t R>
static int test_mat3xR() {
	typedef glm::mat<3, R, float> Mat;
	Mat m(0);
	typename Mat::col_type& c1 = glm::get<0>(m);
	typename Mat::col_type& c2 = glm::get<1>(m);
	typename Mat::col_type& c3 = glm::get<2>(m);
	return (&c1 != &m[0]) + (&c2 != &m[1]) + (&c3 != &m[2]);
}

template<glm::length_t R>
static int test_const_mat3xR() {
	typedef glm::mat< 3, R, float> Mat;
	Mat const m(0);
    typename Mat::col_type const& c1 = glm::get<0>(m);
    typename Mat::col_type const& c2 = glm::get<1>(m);
    typename Mat::col_type const& c3 = glm::get<2>(m);
	return (&c1 != &m[0]) + (&c2 != &m[1]) + (&c3 != &m[2]);
}

template<glm::length_t R>
static int test_mat4xR() {
	typedef glm::mat<4,R,float> Mat;
	Mat m(0);
	typename Mat::col_type& c1 = glm::get<0>(m);
	typename Mat::col_type& c2 = glm::get<1>(m);
	typename Mat::col_type& c3 = glm::get<2>(m);
	typename Mat::col_type& c4 = glm::get<3>(m);

	return (&c1 != &m[0]) + (&c2 != &m[1]) + (&c3 != &m[2]) + (&c4 != &m[3]);
}

template<glm::length_t R>
static int test_const_mat4xR() {
	typedef glm::mat<4,R,float> Mat; 
	Mat const m(0);
	typename Mat::col_type const& c1 = glm::get<0>(m);
	typename Mat::col_type const& c2 = glm::get<1>(m);
	typename Mat::col_type const& c3 = glm::get<2>(m);
	typename Mat::col_type const& c4 = glm::get<3>(m);

	return (&c1 != &m[0]) + (&c2 != &m[1]) + (&c3 != &m[2]) + (&c4 != &m[3]);
}
#if defined(__cpp_structured_bindings)
#if __cpp_structured_bindings >= 201606L
static int test_structured_vec1() {
	glm::vec1 v(0);
	auto& [x] = v;
	return (&x != &v.x);
}

static int test_structured_vec2() {
	glm::vec2 v(0);
	auto& [x, y] = v;
	return (&x != &v.x) + (&y != &v.y);
}

static int test_structured_vec3() {
	glm::vec3 v(0);
	auto& [x, y, z] = v;
	return (&x != &v.x) + (&y != &v.y) + (&z != &v.z);
}

static int test_structured_vec4() {
	glm::vec4 v(0);
	auto& [x, y, z, w] = v;
	return (&x != &v.x) + (&y != &v.y) + (&z != &v.z) + (&w != &v.w);
}

static int test_const_structured_vec1() {
	glm::vec1 const v(0);
	auto const& [x] = v;
	return (&x != &v.x);
}

static int test_const_structured_vec2() {
	glm::vec2 const v(0);
	auto const& [x, y] = v;
	return (&x != &v.x) + (&y != &v.y);
}

static int test_const_structured_vec3() {
	glm::vec3 const v(0);
	auto const& [x, y, z] = v;
	return (&x != &v.x) + (&y != &v.y) + (&z != &v.z);
}

static int test_const_structured_vec4() {
	glm::vec4 const v(0);
	auto const& [x, y, z, w] = v;
	return (&x != &v.x) + (&y != &v.y) + (&z != &v.z) + (&w != &v.w);
}

template<glm::length_t R>
static int test_structured_mat2xR() {
	glm::mat<2,R,float,glm::defaultp> m(0);
	auto& [c1, c2] = m;
	return (&c1 != &m[0]) + (&c2 != &m[1]);
}

template<glm::length_t R>
static int test_const_structured_mat2xR() {
	glm::mat<2, R, float, glm::defaultp> const m(0);
	auto const& [c1, c2] = m;
	return (&c1 != &m[0]) + (&c2 != &m[1]);
}

template<glm::length_t R>
static int test_structured_mat3xR() {
	glm::mat<3, R, float, glm::defaultp> m(0);
	auto& [c1, c2,c3] = m;
	return (&c1 != &m[0]) + (&c2 != &m[1]) + (&c3 != &m[2]);
}

template<glm::length_t R>
static int test_const_structured_mat3xR() {
	glm::mat<3, R, float, glm::defaultp> const m(0);
	auto const& [c1, c2, c3] = m;
	return (&c1 != &m[0]) + (&c2 != &m[1]) + (&c3 != &m[2]);
}

template<glm::length_t R>
static int test_structured_mat4xR() {
	glm::mat<4, R, float, glm::defaultp> m(0);
	auto& [c1, c2, c3,c4] = m;
	return (&c1 != &m[0]) + (&c2 != &m[1]) + (&c3 != &m[2]) + (&c4 != &m[3]);
}

template<glm::length_t R>
static int test_const_structured_mat4xR() {
	glm::mat<4, R, float, glm::defaultp> const m(0);
	auto const& [c1, c2, c3, c4] = m;
	return (&c1 != &m[0]) + (&c2 != &m[1]) + (&c3 != &m[2]) + (&c4 != &m[3]);
}

static int test_structured_quat() {
	glm::quat q(0.0f, 0.0f, 0.0f, 0.0f);
#ifdef GLM_FORCE_QUAT_DATA_WXYZ
	auto& [w, x, y, z] = q;
#else
	auto& [x, y, z, w] = q;
#endif
	return (&x != &q.x) + (&y != &q.y) + (&z != &q.z) + (&w != &q.w);
}

static int test_const_structured_quat() {
	glm::quat const q(0.0f, 0.0f, 0.0f, 0.0f);
#ifdef GLM_FORCE_QUAT_DATA_WXYZ
	auto const& [w, x, y, z] = q;
#else
	auto const& [x, y, z, w] = q;
#endif
	return (&x != &q.x) + (&y != &q.y) + (&z != &q.z) + (&w != &q.w);
}

#endif
#endif
int main()
{
	int Error = 0;
	Error += test_vec1();
	Error += test_vec2();
	Error += test_vec3();
	Error += test_vec4();

	Error += test_const_vec1();
	Error += test_const_vec2();
	Error += test_const_vec3();
	Error += test_const_vec4();


	Error += test_quat();
	Error += test_const_quat();


	Error += test_mat2xR<2>();
	Error += test_const_mat2xR<2>();

	Error += test_mat2xR<3>();
	Error += test_const_mat2xR<3>();

	Error += test_mat2xR<4>();
	Error += test_const_mat2xR<4>();

	Error += test_mat3xR<2>();
	Error += test_const_mat3xR<2>();

	Error += test_mat3xR<3>();
	Error += test_const_mat3xR<3>();

	Error += test_mat3xR<4>();
	Error += test_const_mat3xR<4>();

	Error += test_mat4xR<2>();
	Error += test_const_mat4xR<2>();

	Error += test_mat4xR<3>();
	Error += test_const_mat4xR<3>();

	Error += test_mat4xR<4>();
	Error += test_const_mat4xR<4>();
	
#ifdef __cpp_structured_bindings
#if __cpp_structured_bindings >= 201606L
	Error += test_structured_vec1();
	Error += test_structured_vec2();
	Error += test_structured_vec3();
	Error += test_structured_vec4();

	Error += test_const_structured_vec1();
	Error += test_const_structured_vec2();
	Error += test_const_structured_vec3();
	Error += test_const_structured_vec4();

	Error += test_structured_quat();
	Error += test_const_structured_quat();

	Error += test_structured_mat2xR<2>();
	Error += test_const_structured_mat2xR<2>();

	Error += test_structured_mat2xR<3>();
	Error += test_const_structured_mat2xR<3>();

	Error += test_structured_mat2xR<4>();
	Error += test_const_structured_mat2xR<4>();

	Error += test_structured_mat3xR<2>();
	Error += test_const_structured_mat3xR<2>();

	Error += test_structured_mat3xR<3>();
	Error += test_const_structured_mat3xR<3>();

	Error += test_structured_mat3xR<4>();
	Error += test_const_structured_mat3xR<4>();

	Error += test_structured_mat4xR<2>();
	Error += test_const_structured_mat4xR<2>();

	Error += test_structured_mat4xR<3>();
	Error += test_const_structured_mat4xR<3>();

	Error += test_structured_mat4xR<4>();
	Error += test_const_structured_mat4xR<4>();

#endif
#endif
	return Error;
}
