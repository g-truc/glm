/// @ref core
/// @file glm/detail/type_quat.hpp

#pragma once

// Dependency:
#include "../detail/type_mat3x3.hpp"
#include "../detail/type_mat4x4.hpp"
#include "../detail/type_vec3.hpp"
#include "../detail/type_vec4.hpp"
#include "../ext/vector_relational.hpp"
#include "../ext/quaternion_relational.hpp"
#include "../gtc/constants.hpp"
#include "../gtc/matrix_transform.hpp"

namespace glm
{
#		if GLM_SILENT_WARNINGS == GLM_ENABLE
#			if GLM_COMPILER & GLM_COMPILER_GCC
#				pragma GCC diagnostic push
#				pragma GCC diagnostic ignored "-Wpedantic"
#				pragma GCC diagnostic ignored "-Wattributes" // for alignas(1), packed types
#			elif GLM_COMPILER & GLM_COMPILER_CLANG
#				pragma clang diagnostic push
#				pragma clang diagnostic ignored "-Wgnu-anonymous-struct"
#				pragma clang diagnostic ignored "-Wnested-anon-types"
#				pragma clang diagnostic ignored "-Wpadded"
#			elif GLM_COMPILER & GLM_COMPILER_VC
#				pragma warning(push)
#				pragma warning(disable: 4201)  // nonstandard extension used : nameless struct/union
#				pragma warning(disable: 4324)  // nonstandard extension used : nameless struct/union
#			endif
#		endif

	template<typename T, qualifier Q, std::size_t N>
	struct alignas(N) qua
	{
		// -- Implementation detail --

		typedef qua<T, Q> type;
		typedef T value_type;

		// -- Data --

#		if GLM_LANG & GLM_LANG_CXXMS_FLAG
			union
			{
#				ifdef GLM_FORCE_QUAT_DATA_WXYZ
					struct { T w, x, y, z; };
#				else
					struct { T x, y, z, w; };
#				endif

				typename detail::storage<4, T, detail::is_aligned<Q>::value>::type data;
			};
#		else
#			ifdef GLM_FORCE_QUAT_DATA_WXYZ
				T w, x, y, z;
#			else
				T x, y, z, w;
#			endif
#		endif

		// -- Component accesses --

		typedef length_t length_type;

		/// Return the count of components of a quaternion
		GLM_FUNC_DECL static constexpr length_type length(){return 4;}

		GLM_FUNC_DECL GLM_CONSTEXPR T & operator[](length_type i);
		GLM_FUNC_DECL GLM_CONSTEXPR T const& operator[](length_type i) const;

		// -- Implicit basic constructors --

		GLM_DEFAULTED_DEFAULT_CTOR_DECL GLM_CONSTEXPR qua() GLM_DEFAULT_CTOR;
		GLM_CTOR_DECL qua(qua<T, Q, N> const& q) = default;
		template<qualifier P>
		GLM_CTOR_DECL qua(qua<T, P, N> const& q);

		// -- Explicit basic constructors --

		GLM_CTOR_DECL qua(T s, vec<3, T, Q> const& v);

#		ifdef GLM_FORCE_QUAT_DATA_XYZW
		GLM_CTOR_DECL qua(T x, T y, T z, T w);
#		else
		GLM_CTOR_DECL qua(T w, T x, T y, T z);
#		endif

		GLM_FUNC_DECL static GLM_CONSTEXPR qua<T, Q, N> wxyz(T w, T x, T y, T z);

		// -- Conversion constructors --

		template<typename U, qualifier P, std::size_t M>
		GLM_CTOR_DECL GLM_EXPLICIT qua(qua<U, P, M> const& q);

		GLM_FUNC_DECL explicit operator mat<3, 3, T, Q>() const;
		GLM_FUNC_DECL explicit operator mat<4, 4, T, Q>() const;

		/// Create a quaternion from two normalized axis
		///
		/// @param u A first normalized axis
		/// @param v A second normalized axis
		/// @see gtc_quaternion
		/// @see http://lolengine.net/blog/2013/09/18/beautiful-maths-quaternion-from-vectors
		GLM_FUNC_DISCARD_DECL qua(vec<3, T, Q> const& u, vec<3, T, Q> const& v);

		/// Build a quaternion from euler angles (pitch, yaw, roll), in radians.
		GLM_CTOR_DECL GLM_EXPLICIT qua(vec<3, T, Q> const& eulerAngles);
		GLM_CTOR_DECL GLM_EXPLICIT qua(mat<3, 3, T, Q> const& q);
		GLM_CTOR_DECL GLM_EXPLICIT qua(mat<4, 4, T, Q> const& q);

		// -- Unary arithmetic operators --

		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR qua<T, Q, N>& operator=(qua<T, Q, N> const& q) = default;

		template<typename U>
		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR qua<T, Q, N>& operator=(qua<U, Q, N> const& q);
		template<typename U>
		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR qua<T, Q, N>& operator+=(qua<U, Q, N> const& q);
		template<typename U>
		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR qua<T, Q, N>& operator-=(qua<U, Q, N> const& q);
		template<typename U>
		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR qua<T, Q, N>& operator*=(qua<U, Q, N> const& q);
		template<typename U>
		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR qua<T, Q, N>& operator*=(U s);
		template<typename U>
		GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR qua<T, Q, N>& operator/=(U s);
	};

#		if GLM_SILENT_WARNINGS == GLM_ENABLE
#			if GLM_COMPILER & GLM_COMPILER_CLANG
#				pragma clang diagnostic pop
#			elif GLM_COMPILER & GLM_COMPILER_GCC
#				pragma GCC diagnostic pop
#			elif GLM_COMPILER & GLM_COMPILER_VC
#				pragma warning(pop)
#			endif
#		endif

	// -- Unary bit operators --

	template<typename T, qualifier Q, std::size_t N>
	GLM_FUNC_DECL GLM_CONSTEXPR qua<T, Q, N> operator+(qua<T, Q, N> const& q);

	template<typename T, qualifier Q, std::size_t N>
	GLM_FUNC_DECL GLM_CONSTEXPR qua<T, Q, N> operator-(qua<T, Q, N> const& q);

	// -- Binary operators --

	template<typename T, qualifier Q, std::size_t N>
	GLM_FUNC_DECL GLM_CONSTEXPR qua<T, Q, N> operator+(qua<T, Q, N> const& q, qua<T, Q, N> const& p);

	template<typename T, qualifier Q, std::size_t N>
	GLM_FUNC_DECL GLM_CONSTEXPR qua<T, Q, N> operator-(qua<T, Q, N> const& q, qua<T, Q, N> const& p);

	template<typename T, qualifier Q, std::size_t N>
	GLM_FUNC_DECL GLM_CONSTEXPR qua<T, Q, N> operator*(qua<T, Q, N> const& q, qua<T, Q, N> const& p);

	template<typename T, qualifier Q, std::size_t N>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<3, T, Q> operator*(qua<T, Q, N> const& q, vec<3, T, Q> const& v);

	template<typename T, qualifier Q, std::size_t N>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<3, T, Q> operator*(vec<3, T, Q> const& v, qua<T, Q, N> const& q);

	template<typename T, qualifier Q, std::size_t N>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<4, T, Q> operator*(qua<T, Q, N> const& q, vec<4, T, Q> const& v);

	template<typename T, qualifier Q, std::size_t N>
	GLM_FUNC_DECL GLM_CONSTEXPR vec<4, T, Q> operator*(vec<4, T, Q> const& v, qua<T, Q, N> const& q);

	template<typename T, qualifier Q, std::size_t N>
	GLM_FUNC_DECL GLM_CONSTEXPR qua<T, Q, N> operator*(qua<T, Q, N> const& q, T const& s);

	template<typename T, qualifier Q, std::size_t N>
	GLM_FUNC_DECL GLM_CONSTEXPR qua<T, Q, N> operator*(T const& s, qua<T, Q, N> const& q);

	template<typename T, qualifier Q, std::size_t N>
	GLM_FUNC_DECL GLM_CONSTEXPR qua<T, Q, N> operator/(qua<T, Q, N> const& q, T const& s);

	// -- Boolean operators --

	template<typename T, qualifier Q, std::size_t N>
	GLM_FUNC_DECL GLM_CONSTEXPR bool operator==(qua<T, Q, N> const& q1, qua<T, Q, N> const& q2);

	template<typename T, qualifier Q, std::size_t N>
	GLM_FUNC_DECL GLM_CONSTEXPR bool operator!=(qua<T, Q, N> const& q1, qua<T, Q, N> const& q2);
} //namespace glm

#ifndef GLM_EXTERNAL_TEMPLATE
#include "type_quat.inl"
#endif//GLM_EXTERNAL_TEMPLATE
