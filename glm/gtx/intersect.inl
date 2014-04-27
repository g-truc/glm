///////////////////////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 - 2014 G-Truc Creation (www.g-truc.net)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Created : 2007-04-03
// Updated : 2009-01-20
// Licence : This source is under MIT licence
// File    : glm/gtx/intersect.inl
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "../geometric.hpp"
#include <cfloat>
#include <limits>

namespace glm
{
	template <typename genType>
	GLM_FUNC_QUALIFIER bool intersectRayPlane
	(
		genType const & orig, genType const & dir,
		genType const & planeOrig, genType const & planeNormal,
		typename genType::value_type & intersectionDistance
	)
	{
		typename genType::value_type d = glm::dot(dir, planeNormal);
		typename genType::value_type Epsilon = std::numeric_limits<typename genType::value_type>::epsilon();

		if(d < Epsilon)
		{
			intersectionDistance = glm::dot(planeOrig - orig, planeNormal) / d;
			return true;
		}

		return false;
	}

	template <typename genType>
	GLM_FUNC_QUALIFIER bool intersectRayTriangle
	(
		genType const & orig, genType const & dir,
		genType const & v0, genType const & v1, genType const & v2,
		genType & baryPosition
	)
	{
		genType e1 = v1 - v0;
		genType e2 = v2 - v0;

		genType p = glm::cross(dir, e2);

		typename genType::value_type a = glm::dot(e1, p);

		typename genType::value_type Epsilon = std::numeric_limits<typename genType::value_type>::epsilon();
		if(a < Epsilon)
			return false;

		typename genType::value_type f = typename genType::value_type(1.0f) / a;

		genType s = orig - v0;
		baryPosition.x = f * glm::dot(s, p);
		if(baryPosition.x < typename genType::value_type(0.0f))
			return false;
		if(baryPosition.x > typename genType::value_type(1.0f))
			return false;

		genType q = glm::cross(s, e1);
		baryPosition.y = f * glm::dot(dir, q);
		if(baryPosition.y < typename genType::value_type(0.0f))
			return false;
		if(baryPosition.y + baryPosition.x > typename genType::value_type(1.0f))
			return false;

		baryPosition.z = f * glm::dot(e2, q);

		return baryPosition.z >= typename genType::value_type(0.0f);
	}

	//template <typename genType>
	//GLM_FUNC_QUALIFIER bool intersectRayTriangle
	//(
	//	genType const & orig, genType const & dir,
	//	genType const & vert0, genType const & vert1, genType const & vert2,
	//	genType & position
	//)
	//{
	//	typename genType::value_type Epsilon = std::numeric_limits<typename genType::value_type>::epsilon();
	//
	//	genType edge1 = vert1 - vert0;
	//	genType edge2 = vert2 - vert0;
	//
	//	genType pvec = cross(dir, edge2);
	//
	//	float det = dot(edge1, pvec);
	//	if(det < Epsilon)
	//		return false;
	//
	//	genType tvec = orig - vert0;
	//
	//	position.y = dot(tvec, pvec);
	//	if (position.y < typename genType::value_type(0) || position.y > det)
	//		return typename genType::value_type(0);
	//
	//	genType qvec = cross(tvec, edge1);
	//
	//	position.z = dot(dir, qvec);
	//	if (position.z < typename genType::value_type(0) || position.y + position.z > det)
	//		return typename genType::value_type(0);
	//
	//	position.x = dot(edge2, qvec);
	//	position *= typename genType::value_type(1) / det;
	//
	//	return typename genType::value_type(1);
	//}

	template <typename genType>
	GLM_FUNC_QUALIFIER bool intersectLineTriangle
	(
		genType const & orig, genType const & dir,
		genType const & vert0, genType const & vert1, genType const & vert2,
		genType & position
	)
	{
		typename genType::value_type Epsilon = std::numeric_limits<typename genType::value_type>::epsilon();

		genType edge1 = vert1 - vert0;
		genType edge2 = vert2 - vert0;

		genType pvec = cross(dir, edge2);

		float det = dot(edge1, pvec);

		if (det > -Epsilon && det < Epsilon)
			return false;
		float inv_det = typename genType::value_type(1) / det;

		genType tvec = orig - vert0;

		position.y = dot(tvec, pvec) * inv_det;
		if (position.y < typename genType::value_type(0) || position.y > typename genType::value_type(1))
			return false;

		genType qvec = cross(tvec, edge1);

		position.z = dot(dir, qvec) * inv_det;
		if (position.z < typename genType::value_type(0) || position.y + position.z > typename genType::value_type(1))
			return false;

		position.x = dot(edge2, qvec) * inv_det;

		return true;
	}

	template <typename genType>
	GLM_FUNC_QUALIFIER bool intersectRaySphere
	(
		genType const & rayStarting, genType const & rayNormalizedDirection,
		genType const & sphereCenter, const typename genType::value_type sphereRadiusSquered,
		typename genType::value_type & intersectionDistance
	)
	{
		typename genType::value_type Epsilon = std::numeric_limits<typename genType::value_type>::epsilon();
		genType diff = sphereCenter - rayStarting;
		typename genType::value_type t0 = dot(diff, rayNormalizedDirection);
		typename genType::value_type dSquared = dot(diff, diff) - t0 * t0;
		if( dSquared > sphereRadiusSquered )
		{
			return false;
		}
		typename genType::value_type t1 = sqrt( sphereRadiusSquered - dSquared );
		intersectionDistance = t0 > t1 + Epsilon ? t0 - t1 : t0 + t1;
		return intersectionDistance > Epsilon;
	}

	template <typename genType>
	GLM_FUNC_QUALIFIER bool intersectRaySphere
	(
		genType const & rayStarting, genType const & rayNormalizedDirection,
		genType const & sphereCenter, const typename genType::value_type sphereRadius,
		genType & intersectionPosition, genType & intersectionNormal
	)
	{
		typename genType::value_type distance;
		if( intersectRaySphere( rayStarting, rayNormalizedDirection, sphereCenter, sphereRadius * sphereRadius, distance ) )
		{
			intersectionPosition = rayStarting + rayNormalizedDirection * distance;
			intersectionNormal = (intersectionPosition - sphereCenter) / sphereRadius;
			return true;
		}
		return false;
	}

	template <typename genType>
	GLM_FUNC_QUALIFIER bool intersectLineSphere
	(
		genType const & point0, genType const & point1,
		genType const & sphereCenter, typename genType::value_type sphereRadius,
		genType & intersectionPoint1, genType & intersectionNormal1, 
		genType & intersectionPoint2, genType & intersectionNormal2
	)
	{
		typename genType::value_type Epsilon = std::numeric_limits<typename genType::value_type>::epsilon();
		genType dir = normalize(point1 - point0);
		genType diff = sphereCenter - point0;
		typename genType::value_type t0 = dot(diff, dir);
		typename genType::value_type dSquared = dot(diff, diff) - t0 * t0;
		if( dSquared > sphereRadius * sphereRadius )
		{
			return false;
		}
		typename genType::value_type t1 = sqrt( sphereRadius * sphereRadius - dSquared );
		if( t0 < t1 + Epsilon )
			t1 = -t1;
		intersectionPoint1 = point0 + dir * (t0 - t1);
		intersectionNormal1 = (intersectionPoint1 - sphereCenter) / sphereRadius;
		intersectionPoint2 = point0 + dir * (t0 + t1);
		intersectionNormal2 = (intersectionPoint2 - sphereCenter) / sphereRadius;
		return true;
	}

	template <typename genType>
	GLM_FUNC_QUALIFIER bool intersectRayQuad
	(
		genType const & orig, genType const & dir, 
		genType const & v00, genType const & v10, genType const & v11, genType const & v01,
		genType & bilinearCoordinates
	)
	{
		// Epsilon to reject parallell lines
		typename genType::value_type epsilon = std::numeric_limits<typename genType::value_type>::epsilon();

		// Calculate edges and normal of first triangle
		genType e01 = v10 - v00;
		genType e03 = v01 - v00;

		genType p = glm::cross(dir, e03);

		typename genType::value_type det = glm::dot(e01, p);

		// Reject rays orthagonal to the normal vector. I.e. rays parallell to the plane.
		if(det < epsilon)
			return false;

		typename genType::value_type inv_det = typename genType::value_type(1.0f)/det;

		genType s = orig - v00;

		// Calculate the barycentric alpha coordinate of the first triangle
		typename genType::value_type alpha = inv_det * glm::dot(s, p);

		// It lies outside the triangle
		if(alpha > typename genType::value_type(1.0f))
			return false;

		if(alpha < typename genType::value_type(0.0f))
			return false;

		// Vector perpendicular to T and e01 
		genType q = glm::cross(s, e01);

		// Calculate barycentric beta coordinate of the first triangle
		typename genType::value_type beta = inv_det * glm::dot(dir, q);

		if(beta > typename genType::value_type(1.0f))
			return false;

		if(beta < typename genType::value_type(0.0f))
			return false;

		bilinearCoordinates.z = inv_det * glm::dot(e03, q);

		if(alpha + beta > typename genType::value_type(1.0f)){
		// Do exactly the same for the second triangle

			genType e23 = v01 - v11;
			genType e21 = v10 - v11;

			p = glm::cross(dir, e21);
			
			det = glm::dot(e23, p);

			if(det < epsilon && det > -epsilon)
				return false;

			inv_det = typename genType::value_type(1.0f)/det;
			s = orig - v11;

			alpha = inv_det * glm::dot(s, p);

			if(alpha < typename genType::value_type(0.0f))
				return false;

			q = glm::cross(s, e23);
			beta = inv_det * glm::dot(dir, q);

			if(beta < typename genType::value_type(0.0f))
				return false;

			// This to support degenerate squares
			if(beta + alpha > typename genType::value_type(1.0f))
				return false;

			bilinearCoordinates.z = inv_det * glm::dot(e21, q);	
		}

		
		if(bilinearCoordinates.z < typename genType::value_type(0.0f))
			return false;

		// Compute barycentric coordinates of v11
		genType e02 = v11 - v00;
		genType N = glm::cross(e01, e03);
		
		typename genType::value_type alpha_11, beta_11;

		if(abs(N.x) >= abs(N.y) && abs(N.x) >= abs(N.z)) {
			alpha_11 = (e02.y * e03.z - e02.z * e03.y) / N.x;
			beta_11  = (e01.y * e02.z - e01.z * e02.y) / N.x;
		} else if(abs(N.y) >= abs(N.x) && abs(N.y) >= abs(N.z)) {		
			alpha_11 = (e02.z * e03.x - e02.x * e03.z) / N.x;
			beta_11  = (e01.z * e02.x - e01.x * e02.z) / N.x;
		} else {
			alpha_11 = (e02.x * e03.y - e02.y * e03.x) / N.z;
			beta_11  = (e01.x * e02.y - e01.y * e02.x) / N.z;
		}

		// Compute bilinear coordinates of the intersection point
		if(abs(alpha_11 - typename genType::value_type(1.0f)) < epsilon) { 
			bilinearCoordinates.x = alpha;
			
			if(abs(beta_11 - typename genType::value_type(1.0f)) < epsilon){
				bilinearCoordinates.y = beta;
			} else {
				bilinearCoordinates.y = beta/(bilinearCoordinates.x * (beta_11 - typename genType::value_type(1.0f)) + typename genType::value_type(1.0f));
			}

		} else if(abs(beta_11 - typename genType::value_type(1.0f)) < epsilon) {
			bilinearCoordinates.y = alpha;
			bilinearCoordinates.x = alpha/(bilinearCoordinates.y*(alpha_11 - typename genType::value_type(1.0f)) + typename genType::value_type(1.0f));
		} else {
			typename genType::value_type a, b, c, discr, q;

			a = -(beta_11 - typename genType::value_type(1.0f));
			b = alpha*(beta_11 - 1) - beta*(alpha_11 - typename genType::value_type(1.0f)) - typename genType::value_type(1.0f);
			c = alpha;

			discr = b*b - typename genType::value_type(4.0f)*a*c;

			// Get sign of b
			typename genType::value_type sign = (typename genType::value_type(0) < b) - (b < typename genType::value_type(0));
			
			q = -(typename genType::value_type(0.5f)) * (b + sign*glm::fastSqrt(discr));

			bilinearCoordinates.x = q/a;

			if(bilinearCoordinates.x < 0 || bilinearCoordinates.y > 1){
				bilinearCoordinates.x = c/q;
			} 

			bilinearCoordinates.y = beta/(bilinearCoordinates.x*(beta_11 - 1) + 1);
		}

		return true;
	}

	template<typename genType>
	GLM_FUNC_QUALIFIER bool fastIntersectRayQuad
	(
		genType const & orig, genType const & dir,
		genType const & v00, genType const & v10, genType const & v11, genType const & v01
	)
	{
		// Epsilon to reject parallell lines
		typename genType::value_type epsilon = std::numeric_limits<typename genType::value_type>::epsilon();

		// Calculate edges and normal of first triangle
		genType e01 = v10 - v00;
		genType e03 = v01 - v00;

		genType p = glm::cross(dir, e03);

		typename genType::value_type det = glm::dot(e01, p);

		// Reject rays orthagonal to the normal vector. I.e. rays parallell to the plane.
		if(det < epsilon)
			return false;

		typename genType::value_type inv_det = typename genType::value_type(1.0f)/det;


		genType s = orig - v00;

		// Calculate the barycentric alpha coordinate of the first triangle
		typename genType::value_type alpha = inv_det * glm::dot(s, p);

		// It lies outside the triangle
		if(alpha > typename genType::value_type(1.0f))
			return false;

		if(alpha < typename genType::value_type(0.0f))
			return false;

		// Vector perpendicular to T and e01 
		genType q = glm::cross(s, e01);

		// Calculate barycentric beta coordinate of the first triangle
		typename genType::value_type beta = inv_det * glm::dot(dir, q);

		if(beta > typename genType::value_type(1.0f))
			return false;
		if(beta < typename genType::value_type(0.0f))
			return false;

		typename genType::value_type t = inv_det * glm::dot(e03, q);

		if(alpha + beta > typename genType::value_type(1.0f)){
		// Do exactly the same for the second triangle

			genType e23 = v01 - v11;
			genType e21 = v10 - v11;

			p = glm::cross(dir, e21);
			
			det = glm::dot(e23, p);

			if(det < epsilon)
				return false;

			inv_det = typename genType::value_type(1.0f)/det;
			s = orig - v11;

			alpha = inv_det * glm::dot(s, p);

			if(alpha < typename genType::value_type(0.0f))
				return false;

			q = glm::cross(s, e23);
			beta = inv_det * glm::dot(dir, q);

			if(beta < typename genType::value_type(0.0f))
				return false;

			// This to support degenerate squares
			if(beta + alpha > typename genType::value_type(1.0f))
				return false;
		
			 t = inv_det * glm::dot(e21, q);	
		}
		
		if(t < typename genType::value_type(0.0f))
			return false;

		return true;
	}


}//namespace glm
