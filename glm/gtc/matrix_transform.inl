/// @ref gtc_matrix_transform
/// @file glm/gtc/matrix_transform.inl

#include "../geometric.hpp"
#include "../trigonometric.hpp"
#include "../matrix.hpp"

namespace glm
{
	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q> translate(mat<4, 4, T, Q> const& m, vec<3, T, Q> const& v)
	{
		mat<4, 4, T, Q> Result(m);
		Result[3] = m[0] * v[0] + m[1] * v[1] + m[2] * v[2] + m[3];
		return Result;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q> rotate(mat<4, 4, T, Q> const& m, T angle, vec<3, T, Q> const& v)
	{
		T const a = angle;
		T const c = cos(a);
		T const s = sin(a);

		vec<3, T, Q> axis(normalize(v));
		vec<3, T, Q> temp((T(1) - c) * axis);

		mat<4, 4, T, Q> Rotate;
		Rotate[0][0] = c + temp[0] * axis[0];
		Rotate[0][1] = temp[0] * axis[1] + s * axis[2];
		Rotate[0][2] = temp[0] * axis[2] - s * axis[1];

		Rotate[1][0] = temp[1] * axis[0] - s * axis[2];
		Rotate[1][1] = c + temp[1] * axis[1];
		Rotate[1][2] = temp[1] * axis[2] + s * axis[0];

		Rotate[2][0] = temp[2] * axis[0] + s * axis[1];
		Rotate[2][1] = temp[2] * axis[1] - s * axis[0];
		Rotate[2][2] = c + temp[2] * axis[2];

		mat<4, 4, T, Q> Result;
		Result[0] = m[0] * Rotate[0][0] + m[1] * Rotate[0][1] + m[2] * Rotate[0][2];
		Result[1] = m[0] * Rotate[1][0] + m[1] * Rotate[1][1] + m[2] * Rotate[1][2];
		Result[2] = m[0] * Rotate[2][0] + m[1] * Rotate[2][1] + m[2] * Rotate[2][2];
		Result[3] = m[3];
		return Result;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q> rotate_slow(mat<4, 4, T, Q> const& m, T angle, vec<3, T, Q> const& v)
	{
		T const a = angle;
		T const c = cos(a);
		T const s = sin(a);
		mat<4, 4, T, Q> Result;

		vec<3, T, Q> axis = normalize(v);

		Result[0][0] = c + (static_cast<T>(1) - c)      * axis.x     * axis.x;
		Result[0][1] = (static_cast<T>(1) - c) * axis.x * axis.y + s * axis.z;
		Result[0][2] = (static_cast<T>(1) - c) * axis.x * axis.z - s * axis.y;
		Result[0][3] = static_cast<T>(0);

		Result[1][0] = (static_cast<T>(1) - c) * axis.y * axis.x - s * axis.z;
		Result[1][1] = c + (static_cast<T>(1) - c) * axis.y * axis.y;
		Result[1][2] = (static_cast<T>(1) - c) * axis.y * axis.z + s * axis.x;
		Result[1][3] = static_cast<T>(0);

		Result[2][0] = (static_cast<T>(1) - c) * axis.z * axis.x + s * axis.y;
		Result[2][1] = (static_cast<T>(1) - c) * axis.z * axis.y - s * axis.x;
		Result[2][2] = c + (static_cast<T>(1) - c) * axis.z * axis.z;
		Result[2][3] = static_cast<T>(0);

		Result[3] = vec<4, T, Q>(0, 0, 0, 1);
		return m * Result;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q> scale(mat<4, 4, T, Q> const& m, vec<3, T, Q> const& v)
	{
		mat<4, 4, T, Q> Result;
		Result[0] = m[0] * v[0];
		Result[1] = m[1] * v[1];
		Result[2] = m[2] * v[2];
		Result[3] = m[3];
		return Result;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q> scale_slow(mat<4, 4, T, Q> const& m, vec<3, T, Q> const& v)
	{
		mat<4, 4, T, Q> Result(T(1));
		Result[0][0] = v.x;
		Result[1][1] = v.y;
		Result[2][2] = v.z;
		return m * Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T, defaultp> ortho(T left, T right, T bottom, T top)
	{
		mat<4, 4, T, defaultp> Result(static_cast<T>(1));
		Result[0][0] = static_cast<T>(2) / (right - left);
		Result[1][1] = static_cast<T>(2) / (top - bottom);
		Result[3][0] = - (right + left) / (right - left);
		Result[3][1] = - (top + bottom) / (top - bottom);
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T, defaultp> orthoLH_ZO(T left, T right, T bottom, T top, T zNear, T zFar)
	{
		mat<4, 4, T, defaultp> Result(1);
		Result[0][0] = static_cast<T>(2) / (right - left);
		Result[1][1] = static_cast<T>(2) / (top - bottom);
		Result[2][2] = static_cast<T>(1) / (zFar - zNear);
		Result[3][0] = - (right + left) / (right - left);
		Result[3][1] = - (top + bottom) / (top - bottom);
		Result[3][2] = - zNear / (zFar - zNear);
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T, defaultp> orthoLH_NO(T left, T right, T bottom, T top, T zNear, T zFar)
	{
		mat<4, 4, T, defaultp> Result(1);
		Result[0][0] = static_cast<T>(2) / (right - left);
		Result[1][1] = static_cast<T>(2) / (top - bottom);
		Result[2][2] = static_cast<T>(2) / (zFar - zNear);
		Result[3][0] = - (right + left) / (right - left);
		Result[3][1] = - (top + bottom) / (top - bottom);
		Result[3][2] = - (zFar + zNear) / (zFar - zNear);
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T, defaultp> orthoRH_ZO(T left, T right, T bottom, T top, T zNear, T zFar)
	{
		mat<4, 4, T, defaultp> Result(1);
		Result[0][0] = static_cast<T>(2) / (right - left);
		Result[1][1] = static_cast<T>(2) / (top - bottom);
		Result[2][2] = - static_cast<T>(1) / (zFar - zNear);
		Result[3][0] = - (right + left) / (right - left);
		Result[3][1] = - (top + bottom) / (top - bottom);
		Result[3][2] = - zNear / (zFar - zNear);
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T, defaultp> orthoRH_NO(T left, T right, T bottom, T top, T zNear, T zFar)
	{
		mat<4, 4, T, defaultp> Result(1);
		Result[0][0] = static_cast<T>(2) / (right - left);
		Result[1][1] = static_cast<T>(2) / (top - bottom);
		Result[2][2] = - static_cast<T>(2) / (zFar - zNear);
		Result[3][0] = - (right + left) / (right - left);
		Result[3][1] = - (top + bottom) / (top - bottom);
		Result[3][2] = - (zFar + zNear) / (zFar - zNear);
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T, defaultp> orthoZO(T left, T right, T bottom, T top, T zNear, T zFar)
	{
#		if GLM_COORDINATE_SYSTEM == GLM_LEFT_HANDED
			return orthoLH_ZO(left, right, bottom, top, zNear, zFar);
#		else
			return orthoRH_ZO(left, right, bottom, top, zNear, zFar);
#		endif
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T, defaultp> orthoNO(T left, T right, T bottom, T top, T zNear, T zFar)
	{
#		if GLM_COORDINATE_SYSTEM == GLM_LEFT_HANDED
			return orthoLH_NO(left, right, bottom, top, zNear, zFar);
#		else
			return orthoRH_NO(left, right, bottom, top, zNear, zFar);
#		endif
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T, defaultp> orthoLH(T left, T right, T bottom, T top, T zNear, T zFar)
	{
#		if GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_ZERO_TO_ONE
			return orthoLH_ZO(left, right, bottom, top, zNear, zFar);
#		else
			return orthoLH_NO(left, right, bottom, top, zNear, zFar);
#		endif
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T, defaultp> orthoRH(T left, T right, T bottom, T top, T zNear, T zFar)
	{
#		if GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_ZERO_TO_ONE
			return orthoRH_ZO(left, right, bottom, top, zNear, zFar);
#		else
			return orthoRH_NO(left, right, bottom, top, zNear, zFar);
#		endif
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T, defaultp> ortho(T left, T right, T bottom, T top, T zNear, T zFar)
	{
#		if GLM_COORDINATE_SYSTEM == GLM_LEFT_HANDED && GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_ZERO_TO_ONE
			return orthoLH_ZO(left, right, bottom, top, zNear, zFar);
#		elif GLM_COORDINATE_SYSTEM == GLM_LEFT_HANDED && GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_NEGATIVE_ONE_TO_ONE
			return orthoLH_NO(left, right, bottom, top, zNear, zFar);
#		elif GLM_COORDINATE_SYSTEM == GLM_RIGHT_HANDED && GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_ZERO_TO_ONE
			return orthoRH_ZO(left, right, bottom, top, zNear, zFar);
#		elif GLM_COORDINATE_SYSTEM == GLM_RIGHT_HANDED && GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_NEGATIVE_ONE_TO_ONE
			return orthoRH_NO(left, right, bottom, top, zNear, zFar);
#		endif
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T, defaultp> frustumLH_ZO(T left, T right, T bottom, T top, T nearVal, T farVal)
	{
		mat<4, 4, T, defaultp> Result(0);
		Result[0][0] = (static_cast<T>(2) * nearVal) / (right - left);
		Result[1][1] = (static_cast<T>(2) * nearVal) / (top - bottom);
		Result[2][0] = (right + left) / (right - left);
		Result[2][1] = (top + bottom) / (top - bottom);
		Result[2][2] = farVal / (farVal - nearVal);
		Result[2][3] = static_cast<T>(1);
		Result[3][2] = -(farVal * nearVal) / (farVal - nearVal);
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T, defaultp> frustumLH_NO(T left, T right, T bottom, T top, T nearVal, T farVal)
	{
		mat<4, 4, T, defaultp> Result(0);
		Result[0][0] = (static_cast<T>(2) * nearVal) / (right - left);
		Result[1][1] = (static_cast<T>(2) * nearVal) / (top - bottom);
		Result[2][0] = (right + left) / (right - left);
		Result[2][1] = (top + bottom) / (top - bottom);
		Result[2][2] = (farVal + nearVal) / (farVal - nearVal);
		Result[2][3] = static_cast<T>(1);
		Result[3][2] = - (static_cast<T>(2) * farVal * nearVal) / (farVal - nearVal);
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T, defaultp> frustumRH_ZO(T left, T right, T bottom, T top, T nearVal, T farVal)
	{
		mat<4, 4, T, defaultp> Result(0);
		Result[0][0] = (static_cast<T>(2) * nearVal) / (right - left);
		Result[1][1] = (static_cast<T>(2) * nearVal) / (top - bottom);
		Result[2][0] = (right + left) / (right - left);
		Result[2][1] = (top + bottom) / (top - bottom);
		Result[2][2] = farVal / (nearVal - farVal);
		Result[2][3] = static_cast<T>(-1);
		Result[3][2] = -(farVal * nearVal) / (farVal - nearVal);
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T, defaultp> frustumRH_NO(T left, T right, T bottom, T top, T nearVal, T farVal)
	{
		mat<4, 4, T, defaultp> Result(0);
		Result[0][0] = (static_cast<T>(2) * nearVal) / (right - left);
		Result[1][1] = (static_cast<T>(2) * nearVal) / (top - bottom);
		Result[2][0] = (right + left) / (right - left);
		Result[2][1] = (top + bottom) / (top - bottom);
		Result[2][2] = - (farVal + nearVal) / (farVal - nearVal);
		Result[2][3] = static_cast<T>(-1);
		Result[3][2] = - (static_cast<T>(2) * farVal * nearVal) / (farVal - nearVal);
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T, defaultp> frustumZO(T left, T right, T bottom, T top, T nearVal, T farVal)
	{
#		if GLM_COORDINATE_SYSTEM == GLM_LEFT_HANDED
			return frustumLH_ZO(left, right, bottom, top, nearVal, farVal);
#		else
			return frustumRH_ZO(left, right, bottom, top, nearVal, farVal);
#		endif
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T, defaultp> frustumNO(T left, T right, T bottom, T top, T nearVal, T farVal)
	{
#		if GLM_COORDINATE_SYSTEM == GLM_LEFT_HANDED
			return frustumLH_NO(left, right, bottom, top, nearVal, farVal);
#		else
			return frustumRH_NO(left, right, bottom, top, nearVal, farVal);
#		endif
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T, defaultp> frustumLH(T left, T right, T bottom, T top, T nearVal, T farVal)
	{
#		if GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_ZERO_TO_ONE
			return frustumLH_ZO(left, right, bottom, top, nearVal, farVal);
#		else
			return frustumLH_NO(left, right, bottom, top, nearVal, farVal);
#		endif
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T, defaultp> frustumRH(T left, T right, T bottom, T top, T nearVal, T farVal)
	{
#		if GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_ZERO_TO_ONE
			return frustumRH_ZO(left, right, bottom, top, nearVal, farVal);
#		else
			return frustumRH_NO(left, right, bottom, top, nearVal, farVal);
#		endif
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T, defaultp> frustum(T left, T right, T bottom, T top, T nearVal, T farVal)
	{
#		if GLM_COORDINATE_SYSTEM == GLM_LEFT_HANDED && GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_ZERO_TO_ONE
			return frustumLH_ZO(left, right, bottom, top, nearVal, farVal);
#		elif GLM_COORDINATE_SYSTEM == GLM_LEFT_HANDED && GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_NEGATIVE_ONE_TO_ONE
			return frustumLH_NO(left, right, bottom, top, nearVal, farVal);
#		elif GLM_COORDINATE_SYSTEM == GLM_RIGHT_HANDED && GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_ZERO_TO_ONE
			return frustumRH_ZO(left, right, bottom, top, nearVal, farVal);
#		elif GLM_COORDINATE_SYSTEM == GLM_RIGHT_HANDED && GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_NEGATIVE_ONE_TO_ONE
			return frustumRH_NO(left, right, bottom, top, nearVal, farVal);
#		endif
	}
	//projection matrix code from Vulkan-CookBook
	// Author:   Pawel Lapinski
	// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T, defaultp> perspectiveRH_ZO(T fovy, T aspect, T zNear, T zFar)
	{
		assert(abs(aspect - std::numeric_limits<T>::epsilon()) > static_cast<T>(0));

		T const f = static_cast<T>(1) / tan(static_cast<T>(0.5) * fovy);

		mat<4, 4, T, defaultp> Result(static_cast<T>(0));
		Result[0][0] = f / aspect;
		Result[1][1] = -f;
		Result[2][2] = zFar / (zNear - zFar);
		Result[2][3] = - static_cast<T>(1);
		Result[3][2] = (zNear * zFar) / (zNear - zFar);

		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T, defaultp> perspectiveRH_NO(T fovy, T aspect, T zNear, T zFar)
	{
		assert(abs(aspect - std::numeric_limits<T>::epsilon()) > static_cast<T>(0));

		T const tanHalfFovy = tan(fovy / static_cast<T>(2));

		mat<4, 4, T, defaultp> Result(static_cast<T>(0));
		Result[0][0] = static_cast<T>(1) / (aspect * tanHalfFovy);
		Result[1][1] = static_cast<T>(1) / (tanHalfFovy);
		Result[2][2] = - (zFar + zNear) / (zFar - zNear);
		Result[2][3] = - static_cast<T>(1);
		Result[3][2] = - (static_cast<T>(2) * zFar * zNear) / (zFar - zNear);
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T, defaultp> perspectiveLH_ZO(T fovy, T aspect, T zNear, T zFar)
	{
		assert(abs(aspect - std::numeric_limits<T>::epsilon()) > static_cast<T>(0));

		T const tanHalfFovy = tan(fovy / static_cast<T>(2));

		mat<4, 4, T, defaultp> Result(static_cast<T>(0));
		Result[0][0] = static_cast<T>(1) / (aspect * tanHalfFovy);
		Result[1][1] = static_cast<T>(1) / (tanHalfFovy);
		Result[2][2] = zFar / (zFar - zNear);
		Result[2][3] = static_cast<T>(1);
		Result[3][2] = -(zFar * zNear) / (zFar - zNear);
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T, defaultp> perspectiveLH_NO(T fovy, T aspect, T zNear, T zFar)
	{
		assert(abs(aspect - std::numeric_limits<T>::epsilon()) > static_cast<T>(0));

		T const tanHalfFovy = tan(fovy / static_cast<T>(2));

		mat<4, 4, T, defaultp> Result(static_cast<T>(0));
		Result[0][0] = static_cast<T>(1) / (aspect * tanHalfFovy);
		Result[1][1] = static_cast<T>(1) / (tanHalfFovy);
		Result[2][2] = (zFar + zNear) / (zFar - zNear);
		Result[2][3] = static_cast<T>(1);
		Result[3][2] = - (static_cast<T>(2) * zFar * zNear) / (zFar - zNear);
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T, defaultp> perspectiveZO(T fovy, T aspect, T zNear, T zFar)
	{
#		if GLM_COORDINATE_SYSTEM == GLM_LEFT_HANDED
			return perspectiveLH_ZO(fovy, aspect, zNear, zFar);
#		else
			return perspectiveRH_ZO(fovy, aspect, zNear, zFar);
#		endif
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T, defaultp> perspectiveNO(T fovy, T aspect, T zNear, T zFar)
	{
#		if GLM_COORDINATE_SYSTEM == GLM_LEFT_HANDED
			return perspectiveLH_NO(fovy, aspect, zNear, zFar);
#		else
			return perspectiveRH_NO(fovy, aspect, zNear, zFar);
#		endif
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T, defaultp> perspectiveLH(T fovy, T aspect, T zNear, T zFar)
	{
#		if GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_ZERO_TO_ONE
			return perspectiveLH_ZO(fovy, aspect, zNear, zFar);
#		else
			return perspectiveLH_NO(fovy, aspect, zNear, zFar);
#		endif
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T, defaultp> perspectiveRH(T fovy, T aspect, T zNear, T zFar)
	{
#		if GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_ZERO_TO_ONE
			return perspectiveRH_ZO(fovy, aspect, zNear, zFar);
#		else
			return perspectiveRH_NO(fovy, aspect, zNear, zFar);
#		endif
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T, defaultp> perspective(T fovy, T aspect, T zNear, T zFar)
	{
#		if GLM_COORDINATE_SYSTEM == GLM_LEFT_HANDED && GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_ZERO_TO_ONE
			return perspectiveLH_ZO(fovy, aspect, zNear, zFar);
#		elif GLM_COORDINATE_SYSTEM == GLM_LEFT_HANDED && GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_NEGATIVE_ONE_TO_ONE
			return perspectiveLH_NO(fovy, aspect, zNear, zFar);
#		elif GLM_COORDINATE_SYSTEM == GLM_RIGHT_HANDED && GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_ZERO_TO_ONE
			return perspectiveRH_ZO(fovy, aspect, zNear, zFar);
#		elif GLM_COORDINATE_SYSTEM == GLM_RIGHT_HANDED && GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_NEGATIVE_ONE_TO_ONE
			return perspectiveRH_NO(fovy, aspect, zNear, zFar);
#		endif
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T, defaultp> perspectiveFovRH_ZO(T fov, T width, T height, T zNear, T zFar)
	{
		assert(width > static_cast<T>(0));
		assert(height > static_cast<T>(0));
		assert(fov > static_cast<T>(0));

		T const rad = fov;
		T const h = glm::cos(static_cast<T>(0.5) * rad) / glm::sin(static_cast<T>(0.5) * rad);
		T const w = h * height / width; ///todo max(width , Height) / min(width , Height)?

		mat<4, 4, T, defaultp> Result(static_cast<T>(0));
		Result[0][0] = w;
		Result[1][1] = h;
		Result[2][2] = zFar / (zNear - zFar);
		Result[2][3] = - static_cast<T>(1);
		Result[3][2] = -(zFar * zNear) / (zFar - zNear);
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T, defaultp> perspectiveFovRH_NO(T fov, T width, T height, T zNear, T zFar)
	{
		assert(width > static_cast<T>(0));
		assert(height > static_cast<T>(0));
		assert(fov > static_cast<T>(0));

		T const rad = fov;
		T const h = glm::cos(static_cast<T>(0.5) * rad) / glm::sin(static_cast<T>(0.5) * rad);
		T const w = h * height / width; ///todo max(width , Height) / min(width , Height)?

		mat<4, 4, T, defaultp> Result(static_cast<T>(0));
		Result[0][0] = w;
		Result[1][1] = h;
		Result[2][2] = - (zFar + zNear) / (zFar - zNear);
		Result[2][3] = - static_cast<T>(1);
		Result[3][2] = - (static_cast<T>(2) * zFar * zNear) / (zFar - zNear);
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T, defaultp> perspectiveFovLH_ZO(T fov, T width, T height, T zNear, T zFar)
	{
		assert(width > static_cast<T>(0));
		assert(height > static_cast<T>(0));
		assert(fov > static_cast<T>(0));

		T const rad = fov;
		T const h = glm::cos(static_cast<T>(0.5) * rad) / glm::sin(static_cast<T>(0.5) * rad);
		T const w = h * height / width; ///todo max(width , Height) / min(width , Height)?

		mat<4, 4, T, defaultp> Result(static_cast<T>(0));
		Result[0][0] = w;
		Result[1][1] = h;
		Result[2][2] = zFar / (zFar - zNear);
		Result[2][3] = static_cast<T>(1);
		Result[3][2] = -(zFar * zNear) / (zFar - zNear);
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T, defaultp> perspectiveFovLH_NO(T fov, T width, T height, T zNear, T zFar)
	{
		assert(width > static_cast<T>(0));
		assert(height > static_cast<T>(0));
		assert(fov > static_cast<T>(0));

		T const rad = fov;
		T const h = glm::cos(static_cast<T>(0.5) * rad) / glm::sin(static_cast<T>(0.5) * rad);
		T const w = h * height / width; ///todo max(width , Height) / min(width , Height)?

		mat<4, 4, T, defaultp> Result(static_cast<T>(0));
		Result[0][0] = w;
		Result[1][1] = h;
		Result[2][2] = (zFar + zNear) / (zFar - zNear);
		Result[2][3] = static_cast<T>(1);
		Result[3][2] = - (static_cast<T>(2) * zFar * zNear) / (zFar - zNear);
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T, defaultp> perspectiveFovZO(T fov, T width, T height, T zNear, T zFar)
	{
#		if GLM_COORDINATE_SYSTEM == GLM_LEFT_HANDED
			return perspectiveFovLH_ZO(fov, width, height, zNear, zFar);
#		else
			return perspectiveFovRH_ZO(fov, width, height, zNear, zFar);
#		endif
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T, defaultp> perspectiveFovNO(T fov, T width, T height, T zNear, T zFar)
	{
#		if GLM_COORDINATE_SYSTEM == GLM_LEFT_HANDED
			return perspectiveFovLH_NO(fov, width, height, zNear, zFar);
#		else
			return perspectiveFovRH_NO(fov, width, height, zNear, zFar);
#		endif
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T, defaultp> perspectiveFovLH(T fov, T width, T height, T zNear, T zFar)
	{
#		if GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_ZERO_TO_ONE
			return perspectiveFovLH_ZO(fov, width, height, zNear, zFar);
#		else
			return perspectiveFovLH_NO(fov, width, height, zNear, zFar);
#		endif
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T, defaultp> perspectiveFovRH(T fov, T width, T height, T zNear, T zFar)
	{
#		if GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_ZERO_TO_ONE
			return perspectiveFovRH_ZO(fov, width, height, zNear, zFar);
#		else
			return perspectiveFovRH_NO(fov, width, height, zNear, zFar);
#		endif
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T, defaultp> perspectiveFov(T fov, T width, T height, T zNear, T zFar)
	{
#		if GLM_COORDINATE_SYSTEM == GLM_LEFT_HANDED && GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_ZERO_TO_ONE
			return perspectiveFovLH_ZO(fov, width, height, zNear, zFar);
#		elif GLM_COORDINATE_SYSTEM == GLM_LEFT_HANDED && GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_NEGATIVE_ONE_TO_ONE
			return perspectiveFovLH_NO(fov, width, height, zNear, zFar);
#		elif GLM_COORDINATE_SYSTEM == GLM_RIGHT_HANDED && GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_ZERO_TO_ONE
			return perspectiveFovRH_ZO(fov, width, height, zNear, zFar);
#		elif GLM_COORDINATE_SYSTEM == GLM_RIGHT_HANDED && GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_NEGATIVE_ONE_TO_ONE
			return perspectiveFovRH_NO(fov, width, height, zNear, zFar);
#		endif
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T, defaultp> infinitePerspectiveRH(T fovy, T aspect, T zNear)
	{
		T const range = tan(fovy / static_cast<T>(2)) * zNear;
		T const left = -range * aspect;
		T const right = range * aspect;
		T const bottom = -range;
		T const top = range;

		mat<4, 4, T, defaultp> Result(static_cast<T>(0));
		Result[0][0] = (static_cast<T>(2) * zNear) / (right - left);
		Result[1][1] = (static_cast<T>(2) * zNear) / (top - bottom);
		Result[2][2] = - static_cast<T>(1);
		Result[2][3] = - static_cast<T>(1);
		Result[3][2] = - static_cast<T>(2) * zNear;
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T, defaultp> infinitePerspectiveLH(T fovy, T aspect, T zNear)
	{
		T const range = tan(fovy / static_cast<T>(2)) * zNear;
		T const left = -range * aspect;
		T const right = range * aspect;
		T const bottom = -range;
		T const top = range;

		mat<4, 4, T, defaultp> Result(T(0));
		Result[0][0] = (static_cast<T>(2) * zNear) / (right - left);
		Result[1][1] = (static_cast<T>(2) * zNear) / (top - bottom);
		Result[2][2] = static_cast<T>(1);
		Result[2][3] = static_cast<T>(1);
		Result[3][2] = - static_cast<T>(2) * zNear;
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T, defaultp> infinitePerspective(T fovy, T aspect, T zNear)
	{
#		if GLM_COORDINATE_SYSTEM == GLM_LEFT_HANDED
			return infinitePerspectiveLH(fovy, aspect, zNear);
#		else
			return infinitePerspectiveRH(fovy, aspect, zNear);
#		endif
	}

	// Infinite projection matrix: http://www.terathon.com/gdc07_lengyel.pdf
	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T, defaultp> tweakedInfinitePerspective(T fovy, T aspect, T zNear, T ep)
	{
		T const range = tan(fovy / static_cast<T>(2)) * zNear;
		T const left = -range * aspect;
		T const right = range * aspect;
		T const bottom = -range;
		T const top = range;

		mat<4, 4, T, defaultp> Result(static_cast<T>(0));
		Result[0][0] = (static_cast<T>(2) * zNear) / (right - left);
		Result[1][1] = (static_cast<T>(2) * zNear) / (top - bottom);
		Result[2][2] = ep - static_cast<T>(1);
		Result[2][3] = static_cast<T>(-1);
		Result[3][2] = (ep - static_cast<T>(2)) * zNear;
		return Result;
	}

	template<typename T>
	GLM_FUNC_QUALIFIER mat<4, 4, T, defaultp> tweakedInfinitePerspective(T fovy, T aspect, T zNear)
	{
		return tweakedInfinitePerspective(fovy, aspect, zNear, epsilon<T>());
	}

	template<typename T, typename U, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, T, Q> projectZO(vec<3, T, Q> const& obj, mat<4, 4, T, Q> const& model, mat<4, 4, T, Q> const& proj, vec<4, U, Q> const& viewport)
	{
		vec<4, T, Q> tmp = vec<4, T, Q>(obj, static_cast<T>(1));
		tmp = model * tmp;
		tmp = proj * tmp;

		tmp /= tmp.w;
		tmp.x = tmp.x * static_cast<T>(0.5) + static_cast<T>(0.5);
		tmp.y = tmp.y * static_cast<T>(0.5) + static_cast<T>(0.5);

		tmp[0] = tmp[0] * T(viewport[2]) + T(viewport[0]);
		tmp[1] = tmp[1] * T(viewport[3]) + T(viewport[1]);

		return vec<3, T, Q>(tmp);
	}

	template<typename T, typename U, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, T, Q> projectNO(vec<3, T, Q> const& obj, mat<4, 4, T, Q> const& model, mat<4, 4, T, Q> const& proj, vec<4, U, Q> const& viewport)
	{
		vec<4, T, Q> tmp = vec<4, T, Q>(obj, static_cast<T>(1));
		tmp = model * tmp;
		tmp = proj * tmp;

		tmp /= tmp.w;
		tmp = tmp * static_cast<T>(0.5) + static_cast<T>(0.5);
		tmp[0] = tmp[0] * T(viewport[2]) + T(viewport[0]);
		tmp[1] = tmp[1] * T(viewport[3]) + T(viewport[1]);

		return vec<3, T, Q>(tmp);
	}

	template<typename T, typename U, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, T, Q> project(vec<3, T, Q> const& obj, mat<4, 4, T, Q> const& model, mat<4, 4, T, Q> const& proj, vec<4, U, Q> const& viewport)
	{
#		if GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_ZERO_TO_ONE
			return projectZO(obj, model, proj, viewport);
#		else
			return projectNO(obj, model, proj, viewport);
#		endif
	}

	template<typename T, typename U, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, T, Q> unProjectZO(vec<3, T, Q> const& win, mat<4, 4, T, Q> const& model, mat<4, 4, T, Q> const& proj, vec<4, U, Q> const& viewport)
	{
		mat<4, 4, T, Q> Inverse = inverse(proj * model);

		vec<4, T, Q> tmp = vec<4, T, Q>(win, T(1));
		tmp.x = (tmp.x - T(viewport[0])) / T(viewport[2]);
		tmp.y = (tmp.y - T(viewport[1])) / T(viewport[3]);
		tmp.x = tmp.x * static_cast<T>(2) - static_cast<T>(1);
		tmp.y = tmp.y * static_cast<T>(2) - static_cast<T>(1);

		vec<4, T, Q> obj = Inverse * tmp;
		obj /= obj.w;

		return vec<3, T, Q>(obj);
	}

	template<typename T, typename U, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, T, Q> unProjectNO(vec<3, T, Q> const& win, mat<4, 4, T, Q> const& model, mat<4, 4, T, Q> const& proj, vec<4, U, Q> const& viewport)
	{
		mat<4, 4, T, Q> Inverse = inverse(proj * model);

		vec<4, T, Q> tmp = vec<4, T, Q>(win, T(1));
		tmp.x = (tmp.x - T(viewport[0])) / T(viewport[2]);
		tmp.y = (tmp.y - T(viewport[1])) / T(viewport[3]);
		tmp = tmp * static_cast<T>(2) - static_cast<T>(1);

		vec<4, T, Q> obj = Inverse * tmp;
		obj /= obj.w;

		return vec<3, T, Q>(obj);
	}

	template<typename T, typename U, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, T, Q> unProject(vec<3, T, Q> const& win, mat<4, 4, T, Q> const& model, mat<4, 4, T, Q> const& proj, vec<4, U, Q> const& viewport)
	{
#		if GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_ZERO_TO_ONE
			return unProjectZO(win, model, proj, viewport);
#		else
			return unProjectNO(win, model, proj, viewport);
#		endif
	}

	template<typename T, qualifier Q, typename U>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q> pickMatrix(vec<2, T, Q> const& center, vec<2, T, Q> const& delta, vec<4, U, Q> const& viewport)
	{
		assert(delta.x > static_cast<T>(0) && delta.y > static_cast<T>(0));
		mat<4, 4, T, Q> Result(static_cast<T>(1));

		if(!(delta.x > static_cast<T>(0) && delta.y > static_cast<T>(0)))
			return Result; // Error

		vec<3, T, Q> Temp(
			(static_cast<T>(viewport[2]) - static_cast<T>(2) * (center.x - static_cast<T>(viewport[0]))) / delta.x,
			(static_cast<T>(viewport[3]) - static_cast<T>(2) * (center.y - static_cast<T>(viewport[1]))) / delta.y,
			static_cast<T>(0));

		// Translate and scale the picked region to the entire window
		Result = translate(Result, Temp);
		return scale(Result, vec<3, T, Q>(static_cast<T>(viewport[2]) / delta.x, static_cast<T>(viewport[3]) / delta.y, static_cast<T>(1)));
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q> lookAtRH(vec<3, T, Q> const& eye, vec<3, T, Q> const& center, vec<3, T, Q> const& up)
	{
		vec<3, T, Q> const f(normalize(center - eye));
		vec<3, T, Q> const s(normalize(cross(f, up)));
		vec<3, T, Q> const u(cross(s, f));

		mat<4, 4, T, Q> Result(1);
		Result[0][0] = s.x;
		Result[1][0] = s.y;
		Result[2][0] = s.z;
		Result[0][1] = u.x;
		Result[1][1] = u.y;
		Result[2][1] = u.z;
		Result[0][2] =-f.x;
		Result[1][2] =-f.y;
		Result[2][2] =-f.z;
		Result[3][0] =-dot(s, eye);
		Result[3][1] =-dot(u, eye);
		Result[3][2] = dot(f, eye);
		return Result;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q> lookAtLH(vec<3, T, Q> const& eye, vec<3, T, Q> const& center, vec<3, T, Q> const& up)
	{
		vec<3, T, Q> const f(normalize(center - eye));
		vec<3, T, Q> const s(normalize(cross(up, f)));
		vec<3, T, Q> const u(cross(f, s));

		mat<4, 4, T, Q> Result(1);
		Result[0][0] = s.x;
		Result[1][0] = s.y;
		Result[2][0] = s.z;
		Result[0][1] = u.x;
		Result[1][1] = u.y;
		Result[2][1] = u.z;
		Result[0][2] = f.x;
		Result[1][2] = f.y;
		Result[2][2] = f.z;
		Result[3][0] = -dot(s, eye);
		Result[3][1] = -dot(u, eye);
		Result[3][2] = -dot(f, eye);
		return Result;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q> lookAt(vec<3, T, Q> const& eye, vec<3, T, Q> const& center, vec<3, T, Q> const& up)
	{
#		if GLM_COORDINATE_SYSTEM == GLM_LEFT_HANDED
			return lookAtLH(eye, center, up);
#		else
			return lookAtRH(eye, center, up);
#		endif
	}
}//namespace glm
