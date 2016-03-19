#include <glm/vec4.hpp>
#include <glm/gtx/type_trait.hpp>

template <typename genType>
struct type_gni
{
	static bool const is_vec = true;
	static bool const is_mat = false;
	static bool const is_quat = false;
};
/*
template <template <class, glm::precision> class vecType, typename T, glm::precision P>
struct type_gni<vecType, T, P>
{
	static bool const is_vec = true;
	static bool const is_mat = false;
	static bool const is_quat = false;
};
*/

namespace detail
{
	template <template <typename, glm::precision> class vec_type>
	struct compute_vec_type
	{
		static bool const is_vec = false;
		static GLM_RELAXED_CONSTEXPR glm::length_t components = 0;
	};

	template <>
	struct compute_vec_type<glm::tvec1>
	{
		static bool const is_vec = false;
		//static GLM_RELAXED_CONSTEXPR glm::length_t components = 1;
	};

	template <>
	struct compute_vec_type<glm::tvec2>
	{
		static bool const is_vec = false;
		//static GLM_RELAXED_CONSTEXPR glm::length_t components = 2;
	};

	template <>
	struct compute_vec_type<glm::tvec3>
	{
		static bool const is_vec = false;
		//static GLM_RELAXED_CONSTEXPR glm::length_t components = 3;
	};

	template <>
	struct compute_vec_type<glm::tvec4>
	{
		static bool const is_vec = false;
		//static GLM_RELAXED_CONSTEXPR glm::length_t components = 4;
	};
}//namespace detail
/*
template <class gen_type>
struct vec_type
{
	static bool const is_vec = detail::compute_vec_type<typename gen_type::vec_type>::is_vec;
	//static GLM_RELAXED_CONSTEXPR glm::length_t const components = detail::compute_vec_type<typename gen_type::vec_type>::components;
};
*/

int main()
{
	int Error = 0;

	//typedef  vec_type;
	//bool const is_vec = detail::compute_vec_type<>::is_vec;

	//Error += vec_type<glm::vec4>::is_vec ? 0 : 1;
	//Error += vec_type<glm::vec4>::components == 4 ? 0 : 1;

	return Error;
}

