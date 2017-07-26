#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtc/noise.hpp>

#if GLM_LANG & GLM_LANG_CXX11_FLAG
#include <gli/gli.hpp>

std::size_t const Size = 64;

int test_simplex()
{
	{
		gli::texture2d Texture(gli::FORMAT_RGBA8_UNORM_PACK8, gli::texture2d::extent_type(Size), 1);
		
		for(std::size_t y = 0; y < Size; ++y)
		for(std::size_t x = 0; x < Size; ++x)
		{
			glm::u8vec4 Pixel(glm::byte(glm::abs(glm::simplex(glm::vec2(x / 64.f, y / 64.f))) * 255.f));

			Texture.store(gli::extent2d(x, y), 0, Pixel);
		}

		gli::save(Texture, "texture_simplex2d_256.dds");
	}

	{
		gli::texture2d Texture(gli::FORMAT_RGBA8_UNORM_PACK8, gli::texture2d::extent_type(Size), 1);

		for(std::size_t y = 0; y < Size; ++y)
		for(std::size_t x = 0; x < Size; ++x)
		{
			glm::u8vec4 Pixel(glm::byte(glm::abs(glm::simplex(glm::vec3(x / 64.f, y / 64.f, 0.5f))) * 255.f));

			Texture.store(gli::extent2d(x, y), 0, Pixel);
		}

		gli::save(Texture, "texture_simplex3d_256.dds");
	}

	{
		gli::texture2d Texture(gli::FORMAT_RGBA8_UNORM_PACK8, gli::texture2d::extent_type(Size), 1);

		for(std::size_t y = 0; y < Size; ++y)
		for(std::size_t x = 0; x < Size; ++x)
		{
			glm::u8vec4 Pixel(glm::byte(glm::abs(glm::simplex(glm::vec4(x / 64.f, y / 64.f, 0.5f, 0.5f))) * 255.f));

			Texture.store(gli::extent2d(x, y), 0, Pixel);
		}

		gli::save(Texture, "texture_simplex4d_256.dds");
	}

	return 0;
}

int test_perlin()
{
	{
		gli::texture2d Texture(gli::FORMAT_RGBA8_UNORM_PACK8, gli::texture2d::extent_type(Size), 1);

		for(std::size_t y = 0; y < Size; ++y)
		for(std::size_t x = 0; x < Size; ++x)
		{
			glm::u8vec4 Pixel(glm::byte(glm::abs(glm::perlin(glm::vec2(x / 64.f, y / 64.f))) * 255.f));

			Texture.store(gli::extent2d(x, y), 0, Pixel);
		}

		gli::save(Texture, "texture_perlin2d_256.dds");
	}

	{
		gli::texture2d Texture(gli::FORMAT_RGBA8_UNORM_PACK8, gli::texture2d::extent_type(Size), 1);

		for(std::size_t y = 0; y < Size; ++y)
		for(std::size_t x = 0; x < Size; ++x)
		{
			glm::u8vec4 Pixel(glm::byte(glm::abs(glm::perlin(glm::vec3(x / 64.f, y / 64.f, 0.5f))) * 255.f));

			Texture.store(gli::extent2d(x, y), 0, Pixel);
		}

		gli::save(Texture, "texture_perlin3d_256.dds");
	}

	{
		gli::texture2d Texture(gli::FORMAT_RGBA8_UNORM_PACK8, gli::texture2d::extent_type(Size), 1);

		for(std::size_t y = 0; y < Size; ++y)
		for(std::size_t x = 0; x < Size; ++x)
		{
			glm::u8vec4 Pixel(glm::byte(glm::abs(glm::perlin(glm::vec4(x / 64.f, y / 64.f, 0.5f, 0.5f))) * 255.f));

			Texture.store(gli::extent2d(x, y), 0, Pixel);
		}

		gli::save(Texture, "texture_perlin4d_256.dds");
	}

	return 0;
}

int test_perlin_pedioric()
{
	{
		gli::texture2d Texture(gli::FORMAT_RGBA8_UNORM_PACK8, gli::texture2d::extent_type(Size), 1);

		for(std::size_t y = 0; y < Size; ++y)
		for(std::size_t x = 0; x < Size; ++x)
		{
			glm::u8vec4 Pixel(glm::byte(glm::abs(glm::perlin(glm::vec2(x / 64.f, y / 64.f), glm::vec2(2.0f))) * 255.f));

			Texture.store(gli::extent2d(x, y), 0, Pixel);
		}

		gli::save(Texture, "texture_perlin_pedioric_2d_256.dds");
	}

	{
		gli::texture2d Texture(gli::FORMAT_RGBA8_UNORM_PACK8, gli::texture2d::extent_type(Size), 1);

		for(std::size_t y = 0; y < Size; ++y)
		for(std::size_t x = 0; x < Size; ++x)
		{
			glm::u8vec4 Pixel(glm::byte(glm::abs(glm::perlin(glm::vec3(x / 64.f, y / 64.f, 0.5f), glm::vec3(2.0f))) * 255.f));

			Texture.store(gli::extent2d(x, y), 0, Pixel);
		}

		gli::save(Texture, "texture_perlin_pedioric_3d_256.dds");
	}

	{
		gli::texture2d Texture(gli::FORMAT_RGBA8_UNORM_PACK8, gli::texture2d::extent_type(Size), 1);

		for(std::size_t y = 0; y < Size; ++y)
		for(std::size_t x = 0; x < Size; ++x)
		{
			glm::u8vec4 Pixel(glm::byte(glm::abs(glm::perlin(glm::vec4(x / 64.f, y / 64.f, 0.5f, 0.5f), glm::vec4(2.0f))) * 255.f));

			Texture.store(gli::extent2d(x, y), 0, Pixel);
		}

		gli::save(Texture, "texture_perlin_pedioric_4d_256.dds");
	}

	return 0;
}

#endif//GLM_LANG & GLM_LANG_CXX11_FLAG

int main()
{
	int Error = 0;

#	if GLM_LANG & GLM_LANG_CXX11_FLAG
		Error += test_simplex();
		Error += test_perlin();
		Error += test_perlin_pedioric();
#	endif

	return Error;
}
