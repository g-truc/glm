///////////////////////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 - 2013 G-Truc Creation (www.g-truc.net)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Created : 2012-11-19
// Updated : 2012-11-19
// Licence : This source is under MIT licence
// File    : test/gtx/gtx_multiple.cpp
///////////////////////////////////////////////////////////////////////////////////////////////////

#include <glm/glm.hpp>
#include <glm/gtx/multiple.hpp>

int test_higher()
{
	int Error(0);

	Error += glm::higherMultiple(-5, 4) == -4 ? 0 : 1;
	Error += glm::higherMultiple(-4, 4) == -4 ? 0 : 1;
	Error += glm::higherMultiple(-3, 4) == 0 ? 0 : 1;
	Error += glm::higherMultiple(-2, 4) == 0 ? 0 : 1;
	Error += glm::higherMultiple(-1, 4) == 0 ? 0 : 1;

	Error += glm::higherMultiple(0, 4) == 0 ? 0 : 1;
	Error += glm::higherMultiple(1, 4) == 4 ? 0 : 1;
	Error += glm::higherMultiple(2, 4) == 4 ? 0 : 1;
	Error += glm::higherMultiple(3, 4) == 4 ? 0 : 1;
	Error += glm::higherMultiple(4, 4) == 4 ? 0 : 1;
	Error += glm::higherMultiple(5, 4) == 8 ? 0 : 1;
	Error += glm::higherMultiple(6, 4) == 8 ? 0 : 1;
	Error += glm::higherMultiple(7, 4) == 8 ? 0 : 1;
	Error += glm::higherMultiple(8, 4) == 8 ? 0 : 1;
	Error += glm::higherMultiple(9, 4) == 12 ? 0 : 1;

	return Error;
}

int test_Lower()
{
	int Error(0);

	Error += glm::lowerMultiple(-5, 4) == -8 ? 0 : 1;
	Error += glm::lowerMultiple(-4, 4) == -4 ? 0 : 1;
	Error += glm::lowerMultiple(-3, 4) == -4 ? 0 : 1;
	Error += glm::lowerMultiple(-2, 4) == -4 ? 0 : 1;
	Error += glm::lowerMultiple(-1, 4) == -4 ? 0 : 1;
	Error += glm::lowerMultiple(0, 4) == 0 ? 0 : 1;
	Error += glm::lowerMultiple(1, 4) == 0 ? 0 : 1;
	Error += glm::lowerMultiple(2, 4) == 0 ? 0 : 1;
	Error += glm::lowerMultiple(3, 4) == 0 ? 0 : 1;
	Error += glm::lowerMultiple(4, 4) == 4 ? 0 : 1;
	Error += glm::lowerMultiple(5, 4) == 4 ? 0 : 1;
	Error += glm::lowerMultiple(6, 4) == 4 ? 0 : 1;
	Error += glm::lowerMultiple(7, 4) == 4 ? 0 : 1;
	Error += glm::lowerMultiple(8, 4) == 8 ? 0 : 1;
	Error += glm::lowerMultiple(9, 4) == 8 ? 0 : 1;

	return Error;
}

int main()
{
	int Error(0);

	Error += test_higher();
	Error += test_Lower();

	return Error;
}
