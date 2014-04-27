///////////////////////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 - 2014 G-Truc Creation (www.g-truc.net)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Created : 2013-10-25
// Updated : 2013-10-25
// Licence : This source is under MIT licence
// File    : test/gtx/intersect.cpp
///////////////////////////////////////////////////////////////////////////////////////////////////

#define GLM_FORCE_RADIANS
#include <glm/gtc/type_precision.hpp>
#include <glm/gtx/intersect.hpp>
#include <cstdio>

int test_conformity()
{
	int Error = 0;
	srand(time(NULL));

	const int vertexCount = 100000;

	glm::vec3** vertices = new glm::vec3*[vertexCount];

	for (int i = 0; i < vertexCount; ++i)
	{
		vertices[i] = new glm::vec3[6];
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

	delete vertices;
	return Error;
}

int main()
{
	int Error(0);
	Error += test_conformity();
	return Error;
}
