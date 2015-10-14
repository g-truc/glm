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
/// @file test/gtx/gtx_intersect.cpp
/// @date 2013-10-25 / 2014-11-25
/// @author Christophe Riccio
///////////////////////////////////////////////////////////////////////////////////

#include <glm/gtx/intersect.hpp>
#include <cstdio>

int test_conformity()
{
	int Error = 0;
	srand(time(NULL));

	const int vertexCount = 100000;

	glm::vec3 vertices[vertexCount][6];

	for (int i = 0; i < vertexCount; ++i)
	{
		vertices[i][0] = glm::vec3((float)(rand() % 1000)/100, (float)(rand() % 1000)/100,(float)(rand() % 1000)/100);
		vertices[i][1] = glm::vec3((float)(rand() % 1000)/100, (float)(rand() % 1000)/100,(float)(rand() % 1000)/100);
		vertices[i][2] = glm::vec3((float)(rand() % 1000)/100, (float)(rand() % 1000)/100,(float)(rand() % 1000)/100);
		vertices[i][3] = glm::vec3((float)(rand() % 1000)/100, (float)(rand() % 1000)/100,(float)(rand() % 1000)/100);
		vertices[i][4] = glm::vec3(5 - rand() % 10,  5 - rand() % 10, 5 - rand() % 10);
 		vertices[i][5] = glm::vec3(5 - rand() % 10,  5 - rand() % 10, 5 - rand() % 10);	
	}

	for (int i = 0; i < vertexCount; ++i)
	{
		glm::vec3 a = vertices[i][0];
		glm::vec3 b = vertices[i][1];
		glm::vec3 c = vertices[i][2];
		glm::vec3 d = vertices[i][3];

		glm::vec3 orig = vertices[i][4];
		glm::vec3 dir = vertices[i][5];

		glm::vec3 bilinearCoordinates;
		glm::vec3 barycentricCoordinates;

		bool intersects 		= glm::intersectRayDegenerateQuad(orig, dir, a, b, c, d, bilinearCoordinates);
		bool intersects_fast 	= glm::fastIntersectRayDegenerateQuad(orig, dir, a, b, c, d);
		bool intersects_tri 	= glm::intersectRayTriangle(orig, dir, a, b, d, barycentricCoordinates);
		
		bool intersects_line      	= glm::intersectLineDegenerateQuad(orig, dir, a, b, c, d, bilinearCoordinates);
		bool intersects_line_fast 	= glm::fastIntersectLineDegenerateQuad(orig, dir, a, b, c, d);
		bool intersects_line_tri 	= glm::intersectLineTriangle(orig, dir, a, b, d, barycentricCoordinates);

		if(!intersects_tri){
			intersects_tri = glm::intersectRayTriangle(orig, dir, c, d, b, barycentricCoordinates);
		}

		if(!intersects_line_tri){
			intersects_line_tri = glm::intersectLineTriangle(orig, dir, c, d, b, barycentricCoordinates);
		}

		Error += intersects != intersects_fast;
		Error += intersects != intersects_tri;

		Error += intersects_line != intersects_line_fast;
		Error += intersects_line != intersects_line_tri;

		assert(intersects == intersects_fast);
		assert(intersects == intersects_tri);
		assert(intersects_line == intersects_line_fast);
		assert(intersects_line == intersects_line_tri);
	}	

	return Error;
}

int main()
{
	int Error(0);
	Error += test_conformity();
	return Error;
}
