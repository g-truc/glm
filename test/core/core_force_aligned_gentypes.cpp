#include <glm/glm.hpp>
#include <glm/ext.hpp>

#if GLM_COMPILER & GLM_COMPILER_CLANG
#	pragma clang diagnostic push
#	pragma clang diagnostic ignored "-Wpadded"
#elif defined(_MSC_VER)
#	pragma warning(push)
#	pragma warning(disable: 4324)  // structure was padded due to alignment specifier
#endif

#ifdef GLM_FORCE_XYZW_ONLY
#error Aligned types are not supported
#endif

// Every object of type struct_float will be aligned
// to alignof(float) boundary (usually 4):
struct alignas(float) struct_float
{
    // your definition here
};

struct alignas(16) struct_sse3_t
{
    float sse_data[3];
};
 
struct alignas(16) struct_sse4_t
{
    float sse_data[4];
};

struct struct_sse4_packed
{
    float sse_data[4];
};

struct alignas(16) storage_type {
	float sse_data[3];
};

struct struct_sse4_data
{
	storage_type data;
};

template<glm::qualifier P>
struct is_aligned
{
	static const bool value = false;
};

template<>
struct is_aligned<glm::aligned_lowp>
{
	static const bool value = true;
};

template<>
struct is_aligned<glm::aligned_mediump>
{
	static const bool value = true;
};

template<>
struct is_aligned<glm::aligned_highp>
{
	static const bool value = true;
};

template<glm::length_t L, typename T, bool is_aligned>
struct storage
{
	T data[L];
};

template<glm::length_t L, typename T>
struct alignas(L * sizeof(T)) storage<L, T, true>
{
	T data[L];
};

template<typename T>
struct alignas(4 * sizeof(T)) storage<3, T, true>
{
	T data[3];
};

int main()
{
	int Error = 0;

	static_assert(sizeof(storage<4, float, true>) == 16);
	static_assert(alignof(storage<4, float, true>) == 16);

	static_assert(sizeof(storage<3, float, true>) == 16);
	static_assert(alignof(storage<3, float, true>) == 16);

	static_assert(sizeof(storage<4, float, false>) == 16);
	static_assert(alignof(storage<4, float, false>) == 4);

	static_assert(sizeof(storage<3, float, false>) == 12);
	static_assert(alignof(storage<3, float, false>) == 4);

	static_assert(sizeof(struct_sse3_t) == 16);
	static_assert(alignof(struct_sse3_t) == 16);

	static_assert(sizeof(struct_sse4_t) == 16);
	static_assert(alignof(struct_sse4_t) == 16);

	static_assert(sizeof(struct_sse4_packed) == 16);
	static_assert(alignof(struct_sse4_packed) == 4);

	static_assert(sizeof(struct_sse4_data) == 16);
	static_assert(alignof(struct_sse4_data) == 16);

	static_assert(alignof(struct_float) == 4);

	static_assert(sizeof(glm::vec3) == 12);
	static_assert(sizeof(glm::vec4) == 16);

#if defined(GLM_FORCE_DEFAULT_ALIGNED_GENTYPES)
	static_assert(alignof(glm::vec3) == 16);
	static_assert(alignof(glm::vec4) == 16);
#else
	static_assert(alignof(glm::vec3) == 4);
	static_assert(alignof(glm::vec4) == 4);
#endif

#if (GLM_ARCH & GLM_ARCH_SIMD_BIT) // FIXME, should work without SIMD
	static_assert(sizeof(glm::aligned_vec3) == 16);
	static_assert(alignof(glm::aligned_vec3) == 16);
#endif

	static_assert(sizeof(glm::packed_vec3) == 12);
	static_assert(alignof(glm::packed_vec3) == 4);

	static_assert(sizeof(glm::aligned_vec4) == 16);
#if (GLM_ARCH & GLM_ARCH_SIMD_BIT) // FIXME, should work without SIMD
	static_assert(alignof(glm::aligned_vec4) == 16);
#endif
	static_assert(sizeof(glm::packed_vec4) == 16);
	static_assert(alignof(glm::packed_vec4) == 4);

	//static_assert(alignof(glm::detail::storage<3, float, true>) == 16);

	return Error;
}

#if GLM_COMPILER & GLM_COMPILER_CLANG
#	pragma clang diagnostic pop
#elif defined(_MSC_VER)
#	pragma warning(pop)
#endif

