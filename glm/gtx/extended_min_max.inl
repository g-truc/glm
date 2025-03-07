/// @ref gtx_extended_min_max

namespace glm
{
	
	template<typename T>
	GLM_FUNC_QUALIFIER T min(
		T const& x,
		T const& y,
		T const& z) {
		return glm::min(glm::min(x, y),z);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER T min(
		T const& x,
		T const& y,
		T const& z,
		T const& w) {
		return glm::min(glm::min(x, y),glm::min(z,w));
	}


		template<typename T>
	GLM_FUNC_QUALIFIER T max(
		T const& x,
		T const& y,
		T const& z) {
		return glm::max(glm::max(x, y),z);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER T max(
		T const& x,
		T const& y,
		T const& z,
		T const& w) {
		return glm::max(glm::max(x, y),glm::max(z,w));
	}

}//namespace glm
