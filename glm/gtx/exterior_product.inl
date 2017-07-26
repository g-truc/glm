/// @ref core
/// @file glm/detail/func_geometric.inl

#include <limits>

namespace glm {
namespace detail
{
	template<typename T, precision P, bool Aligned>
	struct compute_cross_vec2
	{
		GLM_FUNC_QUALIFIER static T call(vec<2, T, P> const& v, vec<2, T, P> const& u)
		{
			GLM_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "'cross' accepts only floating-point inputs");

			return v.x * u.y - u.x * v.y;
		}
	};
}//namespace detail

	template<typename T, precision P>
	GLM_FUNC_QUALIFIER T cross(vec<2, T, P> const & x, vec<2, T, P> const & y)
	{
		return detail::compute_cross_vec2<T, P, detail::is_aligned<P>::value>::call(x, y);
	}
}//namespace glm

