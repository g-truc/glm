#include <glm/glm.hpp>

#if GLM_CONFIG_ANONYMOUS_STRUCT == GLM_ENABLE
struct vec2;

struct _swizzle
{
	char _buffer[1];
};

struct vec2
{
	GLM_CONSTEXPR vec2() :
		x(0), y(0)
	{}

#if defined(_MSC_VER)
#	pragma warning(push)
#	pragma warning(disable: 4201)  // nonstandard extension used : nameless struct/union
#endif

	union
	{
		struct { float x, y; };
		struct { _swizzle xx; };
	};

#if defined(_MSC_VER)
#	pragma warning(pop)
#endif
};
#endif

// Visual C++ has a bug generating the error: fatal error C1001: An internal error has occurred in the compiler.
// vec2 Bar;

int main()
{
	return 0;
}
