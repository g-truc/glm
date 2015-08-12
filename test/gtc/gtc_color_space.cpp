///////////////////////////////////////////////////////////////////////////////////
/// OpenGL Mathematics (glm.g-truc.net)
///
/// Copyright (c) 2005 - 2015 G-Truc Creation (www.g-truc.net)
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
/// 
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
/// 
/// Restrictions:
///		By making use of the Software for military purposes, you choose to make
///		a Bunny unhappy.
/// 
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
/// THE SOFTWARE.
///
/// @file test/gtc/gtc_color.cpp
/// @date 2015-02-10 / 2015-02-10
/// @author Christophe Riccio
///////////////////////////////////////////////////////////////////////////////////

#include <glm/gtc/color_space.hpp>
#include <glm/gtc/epsilon.hpp>
#include <glm/gtc/constants.hpp>

namespace srgb
{
	int test()
	{
		int Error(0);

		glm::vec3 const ColorSourceRGB(1.0, 0.5, 0.0);

		{
			glm::vec3 const ColorSRGB = glm::convertLinearToSRGB(ColorSourceRGB);
			glm::vec3 const ColorRGB = glm::convertSRGBToLinear(ColorSRGB);
			Error += glm::all(glm::epsilonEqual(ColorSourceRGB, ColorRGB, 0.00001f)) ? 0 : 1;
		}

		{
			glm::vec3 const ColorSRGB = glm::convertLinearToSRGB(ColorSourceRGB, 2.8f);
			glm::vec3 const ColorRGB = glm::convertSRGBToLinear(ColorSRGB, 2.8f);
			Error += glm::all(glm::epsilonEqual(ColorSourceRGB, ColorRGB, 0.00001f)) ? 0 : 1;
		}

		glm::vec4 const ColorSourceRGBA(1.0, 0.5, 0.0, 1.0);

		{
			glm::vec4 const ColorSRGB = glm::convertLinearToSRGB(ColorSourceRGBA);
			glm::vec4 const ColorRGB = glm::convertSRGBToLinear(ColorSRGB);
			Error += glm::all(glm::epsilonEqual(ColorSourceRGBA, ColorRGB, 0.00001f)) ? 0 : 1;
		}

		{
			glm::vec4 const ColorSRGB = glm::convertLinearToSRGB(ColorSourceRGBA, 2.8f);
			glm::vec4 const ColorRGB = glm::convertSRGBToLinear(ColorSRGB, 2.8f);
			Error += glm::all(glm::epsilonEqual(ColorSourceRGBA, ColorRGB, 0.00001f)) ? 0 : 1;
		}

		return Error;
	}
}//namespace srgb

int main()
{
	int Error(0);

	Error += srgb::test();

	return Error;
}
