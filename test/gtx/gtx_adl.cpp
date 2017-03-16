///////////////////////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 - 2014 G-Truc Creation (www.g-truc.net)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Created : 2014-09-19
// Updated : 2014-09-19
// Licence : This source is under MIT licence
// File    : test/gtx/gtx_adl.cpp
///////////////////////////////////////////////////////////////////////////////////////////////////

#include <glm/vec3.hpp>
#include <glm/gtx/adl.hpp>

template <typename T>
int length(T const &){
	// This function should not be picked up in main
	// So we return an error here
	return 1;
}

int main(){
	int Error(0);
	glm::vec3 v(0, 0, 0);

	// the glm::length function will return 0
	Error += int(length(v));

	return Error;
}
