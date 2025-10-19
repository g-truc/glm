#include <glm/glm.hpp>
#include <glm/ext.hpp>

#if GLM_HAS_CONSTEXPR

#include <glm/gtc/constants.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/ext/vector_relational.hpp>
#include <glm/ext/vector_int1.hpp>
#include <glm/ext/vector_bool1.hpp>
#include <glm/ext/vector_bool4.hpp>
#include <glm/ext/vector_float1.hpp>
#include <glm/vector_relational.hpp>

static int test_vec1()
{
	int Error = 0;

	{
		constexpr glm::bvec1 B(true);
		constexpr bool A = glm::all(B);
		static_assert(A, "GLM: Failed constexpr");
		
		constexpr glm::bvec1 D(true);
		constexpr bool C = glm::any(D);
		static_assert(C, "GLM: Failed constexpr");
	}
	
	{
		constexpr glm::bvec2 C(true);
		constexpr glm::bvec2 B(true);
		static_assert(glm::any(glm::equal(C, B)), "GLM: Failed constexpr");
	}
	
	{
		constexpr glm::ivec1 O(glm::ivec1(1));
		static_assert(glm::ivec1(1) == O, "GLM: Failed constexpr");

		constexpr glm::ivec1 P(1);
		static_assert(glm::ivec1(1) == P, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec1 L(glm::ivec2(1, 2));
		static_assert(glm::ivec1(1) == L, "GLM: Failed constexpr");

		constexpr glm::ivec1 M(glm::ivec3(1, 2, 3));
		static_assert(glm::ivec1(1) == M, "GLM: Failed constexpr");

		constexpr glm::ivec1 N(glm::ivec4(1, 2, 3, 4));
		static_assert(glm::ivec1(1) == N, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec1 A(1);
		static_assert(A[0] == 1, "GLM: Failed constexpr");
		static_assert(glm::vec1(1.0f).x > 0.0f, "GLM: Failed constexpr");
		static_assert(glm::vec1::length() == 1, "GLM: Failed constexpr");
	}

	{
		constexpr glm::bvec1 A1(true);
		constexpr glm::bvec1 A2(true);
		constexpr glm::bvec1 B1(false);
		constexpr glm::bvec1 B2(false);
		static_assert(A1 == A2 && B1 == B2, "GLM: Failed constexpr");
		static_assert(A1 == A2 || B1 == B2, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec1 A(1);
		constexpr glm::ivec1 B = A + 1;
		constexpr glm::ivec1 C(3);
		static_assert(A + B == C, "GLM: Failed constexpr");

		constexpr glm::ivec1 D = +A;
		static_assert(D == A, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec1 A(3);
		constexpr glm::ivec1 B = A - 1;
		constexpr glm::ivec1 C(1);
		static_assert(A - B == C, "GLM: Failed constexpr");

		constexpr glm::ivec1 D = -A;
		static_assert(-D == A, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec1 A(3);
		constexpr glm::ivec1 B = A * 1;
		static_assert(A == B, "GLM: Failed constexpr");

		constexpr glm::ivec1 C(1);
		static_assert(B * C == A, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec1 A(3);
		constexpr glm::ivec1 B = A / 1;
		static_assert(A == B, "GLM: Failed constexpr");

		constexpr glm::ivec1 C(1);
		static_assert(B / C == A, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec1 A(3);
		constexpr glm::ivec1 B = A % 2;
		constexpr glm::ivec1 C(1);
		static_assert(B == C, "GLM: Failed constexpr");

		constexpr glm::ivec1 D(2);
		static_assert(A % D == C, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec1 A(1);
		constexpr glm::ivec1 B = A & 1;
		static_assert(A == B, "GLM: Failed constexpr");

		constexpr glm::ivec1 C(1);
		static_assert(A == (A & C), "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec1 A(1);
		constexpr glm::ivec1 B = A | 1;
		static_assert(A == B, "GLM: Failed constexpr");

		constexpr glm::ivec1 C(1);
		static_assert(A == (A | C), "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec1 A(1);
		constexpr glm::ivec1 B = A ^ 0;
		static_assert(A == B, "GLM: Failed constexpr");

		constexpr glm::ivec1 C(0);
		static_assert(A == (A ^ C), "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec1 A(1);
		constexpr glm::ivec1 B = A << 1;
		static_assert(B == glm::ivec1(2), "GLM: Failed constexpr");

		constexpr glm::ivec1 C(1);
		static_assert(B == (A << C), "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec1 A(2);
		constexpr glm::ivec1 B = A >> 1;
		static_assert(B == glm::ivec1(1), "GLM: Failed constexpr");

		constexpr glm::ivec1 C(1);
		static_assert(B == A >> C, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec1 A(~0);
		constexpr glm::ivec1 B = ~A;
		static_assert(A == ~B, "GLM: Failed constexpr");
	}

	return Error;
}

static int test_vec2()
{
	int Error = 0;

	{
		constexpr glm::bvec2 B(true);
		constexpr bool A = glm::all(B);
		static_assert(A, "GLM: Failed constexpr");
		
		constexpr glm::bvec2 D(true, false);
		constexpr bool C = glm::any(D);
		static_assert(C, "GLM: Failed constexpr");
	}
	
	{
		constexpr glm::bvec2 C(true);
		constexpr glm::bvec2 B(true, false);
		static_assert(glm::any(glm::equal(C, B)), "GLM: Failed constexpr");
	}
	
	{
		constexpr glm::ivec2 O(glm::ivec1(1));
		static_assert(glm::ivec2(1) == O, "GLM: Failed constexpr");

		constexpr glm::ivec2 A(1);
		static_assert(glm::ivec2(1) == A, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec2 F(glm::ivec1(1), glm::ivec1(2));
		static_assert(glm::ivec2(1, 2) == F, "GLM: Failed constexpr");

		constexpr glm::ivec2 G(1, glm::ivec1(2));
		static_assert(glm::ivec2(1, 2) == G, "GLM: Failed constexpr");

		constexpr glm::ivec2 H(glm::ivec1(1), 2);
		static_assert(glm::ivec2(1, 2) == H, "GLM: Failed constexpr");

		constexpr glm::ivec2 I(1, 2);
		static_assert(glm::ivec2(1, 2) == I, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec2 L(glm::ivec2(1, 2));
		static_assert(glm::ivec2(1, 2) == L, "GLM: Failed constexpr");

		constexpr glm::ivec2 M(glm::ivec3(1, 2, 3));
		static_assert(glm::ivec2(1, 2) == M, "GLM: Failed constexpr");

		constexpr glm::ivec2 N(glm::ivec4(1, 2, 3, 4));
		static_assert(glm::ivec2(1, 2) == N, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec2 A(1);
		static_assert(A[0] == 1, "GLM: Failed constexpr");
		static_assert(glm::vec2(1.0f).x > 0.0f, "GLM: Failed constexpr");
		static_assert(glm::vec2(1.0f, -1.0f).x > 0.0f, "GLM: Failed constexpr");
		static_assert(glm::vec2(1.0f, -1.0f).y < 0.0f, "GLM: Failed constexpr");
		static_assert(glm::vec2::length() == 2, "GLM: Failed constexpr");
	}

	{
		constexpr glm::bvec2 A1(true);
		constexpr glm::bvec2 A2(true);
		constexpr glm::bvec2 B1(false);
		constexpr glm::bvec2 B2(false);
		static_assert(A1 == A2 && B1 == B2, "GLM: Failed constexpr");
		static_assert(A1 == A2 || B1 == B2, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec2 A(1);
		constexpr glm::ivec2 B = A + 1;
		constexpr glm::ivec2 C(3);
		static_assert(A + B == C, "GLM: Failed constexpr");

		constexpr glm::ivec2 D = +A;
		static_assert(D == A, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec2 A(3);
		constexpr glm::ivec2 B = A - 1;
		constexpr glm::ivec2 C(1);
		static_assert(A - B == C, "GLM: Failed constexpr");

		constexpr glm::ivec2 D = -A;
		static_assert(-D == A, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec2 A(3);
		constexpr glm::ivec2 B = A * 1;
		static_assert(A == B, "GLM: Failed constexpr");

		constexpr glm::ivec2 C(1);
		static_assert(B * C == A, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec2 A(3);
		constexpr glm::ivec2 B = A / 1;
		static_assert(A == B, "GLM: Failed constexpr");

		constexpr glm::ivec2 C(1);
		static_assert(B / C == A, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec2 A(3);
		constexpr glm::ivec2 B = A % 2;
		constexpr glm::ivec2 C(1);
		static_assert(B == C, "GLM: Failed constexpr");

		constexpr glm::ivec1 D(2);
		static_assert(A % D == C, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec2 A(1);
		constexpr glm::ivec2 B = A & 1;
		static_assert(A == B, "GLM: Failed constexpr");

		constexpr glm::ivec1 C(1);
		static_assert(A == (A & C), "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec2 A(1);
		constexpr glm::ivec2 B = A | 1;
		static_assert(A == B, "GLM: Failed constexpr");

		constexpr glm::ivec1 C(1);
		static_assert(A == (A | C), "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec2 A(1);
		constexpr glm::ivec2 B = A ^ 0;
		static_assert(A == B, "GLM: Failed constexpr");

		constexpr glm::ivec1 C(0);
		static_assert(A == (A ^ C), "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec2 A(1);
		constexpr glm::ivec2 B = A << 1;
		static_assert(B == glm::ivec2(2), "GLM: Failed constexpr");

		constexpr glm::ivec1 C(1);
		static_assert(B == (A << C), "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec2 A(2);
		constexpr glm::ivec2 B = A >> 1;
		static_assert(B == glm::ivec2(1), "GLM: Failed constexpr");

		constexpr glm::ivec1 C(1);
		static_assert(B == A >> C, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec2 A(~0);
		constexpr glm::ivec2 B = ~A;
		static_assert(A == ~B, "GLM: Failed constexpr");
	}

	return Error;
}

static int test_vec3()
{
	int Error = 0;

	{
		constexpr glm::bvec3 B(true);
		constexpr bool A = glm::all(B);
		static_assert(A, "GLM: Failed constexpr");
		
		constexpr glm::bvec3 D(true, false, true);
		constexpr bool C = glm::any(D);
		static_assert(C, "GLM: Failed constexpr");
	}
	
	{
		constexpr glm::bvec3 C(true);
		constexpr glm::bvec3 B(true, false, true);
		static_assert(glm::any(glm::equal(C, B)), "GLM: Failed constexpr");
	}
	
	{
		constexpr glm::ivec3 O(glm::ivec1(1));
		static_assert(glm::ivec3(1) == O, "GLM: Failed constexpr");

		constexpr glm::ivec3 A(1);
		static_assert(glm::ivec3(1) == A, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec3 B(glm::ivec2(1, 2), 3);
		static_assert(glm::ivec3(1, 2, 3) == B, "GLM: Failed constexpr");

		constexpr glm::ivec3 C(1, glm::ivec2(2, 3));
		static_assert(glm::ivec3(1, 2, 3) == C, "GLM: Failed constexpr");

		constexpr glm::ivec3 D(glm::ivec1(1), glm::ivec2(2, 3));
		static_assert(glm::ivec3(1, 2, 3) == D, "GLM: Failed constexpr");

		constexpr glm::ivec3 E(glm::ivec2(1, 2), glm::ivec1(3));
		static_assert(glm::ivec3(1, 2, 3) == E, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec3 F(glm::ivec1(1), glm::ivec1(2), glm::ivec1(3));
		static_assert(glm::ivec3(1, 2, 3) == F, "GLM: Failed constexpr");

		constexpr glm::ivec3 G(1, glm::ivec1(2), glm::ivec1(3));
		static_assert(glm::ivec3(1, 2, 3) == G, "GLM: Failed constexpr");

		constexpr glm::ivec3 H(glm::ivec1(1), 2, glm::ivec1(3));
		static_assert(glm::ivec3(1, 2, 3) == H, "GLM: Failed constexpr");

		constexpr glm::ivec3 I(1, 2, glm::ivec1(3));
		static_assert(glm::ivec3(1, 2, 3) == I, "GLM: Failed constexpr");

		constexpr glm::ivec3 J(glm::ivec1(1), glm::ivec1(2), 3);
		static_assert(glm::ivec3(1, 2, 3) == J, "GLM: Failed constexpr");

		constexpr glm::ivec3 K(1, glm::ivec1(2), 3);
		static_assert(glm::ivec3(1, 2, 3) == K, "GLM: Failed constexpr");

		constexpr glm::ivec3 L(glm::ivec1(1), 2, 3);
		static_assert(glm::ivec3(1, 2, 3) == L, "GLM: Failed constexpr");

		constexpr glm::ivec3 M(1, 2, 3);
		static_assert(glm::ivec3(1, 2, 3) == M, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec3 N(glm::ivec4(1, 2, 3, 4));
		static_assert(glm::ivec3(1, 2, 3) == N, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec3 const A(1);
		static_assert(A[0] == 1, "GLM: Failed constexpr");
		static_assert(glm::vec3(1.0f).x > 0.0f, "GLM: Failed constexpr");
		static_assert(glm::vec3(1.0f, -1.0f, -1.0f).x > 0.0f, "GLM: Failed constexpr");
		static_assert(glm::vec3(1.0f, -1.0f, -1.0f).y < 0.0f, "GLM: Failed constexpr");
		static_assert(glm::vec3::length() == 3, "GLM: Failed constexpr");
	}

	{
		constexpr glm::bvec3 A1(true);
		constexpr glm::bvec3 A2(true);
		constexpr glm::bvec3 B1(false);
		constexpr glm::bvec3 B2(false);
		static_assert(A1 == A2 && B1 == B2, "GLM: Failed constexpr");
		static_assert(A1 == A2 || B1 == B2, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec3 A(1);
		constexpr glm::ivec3 B = A + 1;
		constexpr glm::ivec3 C(3);
		static_assert(A + B == C, "GLM: Failed constexpr");

		constexpr glm::ivec3 D = +A;
		static_assert(D == A, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec3 A(3);
		constexpr glm::ivec3 B = A - 1;
		constexpr glm::ivec3 C(1);
		static_assert(A - B == C, "GLM: Failed constexpr");

		constexpr glm::ivec3 D = -A;
		static_assert(-D == A, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec3 A(3);
		constexpr glm::ivec3 B = A * 1;
		static_assert(A == B, "GLM: Failed constexpr");

		constexpr glm::ivec3 C(1);
		static_assert(B * C == A, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec3 A(3);
		constexpr glm::ivec3 B = A / 1;
		static_assert(A == B, "GLM: Failed constexpr");

		constexpr glm::ivec3 C(1);
		static_assert(B / C == A, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec3 A(3);
		constexpr glm::ivec3 B = A % 2;
		constexpr glm::ivec3 C(1);
		static_assert(B == C, "GLM: Failed constexpr");

		constexpr glm::ivec1 D(2);
		static_assert(A % D == C, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec3 A(1);
		constexpr glm::ivec3 B = A & 1;
		static_assert(A == B, "GLM: Failed constexpr");

		constexpr glm::ivec1 C(1);
		static_assert(A == (A & C), "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec3 A(1);
		constexpr glm::ivec3 B = A | 1;
		static_assert(A == B, "GLM: Failed constexpr");

		constexpr glm::ivec1 C(1);
		static_assert(A == (A | C), "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec3 A(1);
		constexpr glm::ivec3 B = A ^ 0;
		static_assert(A == B, "GLM: Failed constexpr");

		constexpr glm::ivec1 C(0);
		static_assert(A == (A ^ C), "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec3 A(1);
		constexpr glm::ivec3 B = A << 1;
		static_assert(B == glm::ivec3(2), "GLM: Failed constexpr");

		constexpr glm::ivec1 C(1);
		static_assert(B == (A << C), "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec3 A(2);
		constexpr glm::ivec3 B = A >> 1;
		static_assert(B == glm::ivec3(1), "GLM: Failed constexpr");

		constexpr glm::ivec1 C(1);
		static_assert(B == A >> C, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec3 A(~0);
		constexpr glm::ivec3 B = ~A;
		static_assert(A == ~B, "GLM: Failed constexpr");
	}

	return Error;
}

static int test_vec4()
{
	int Error = 0;
	
	{
		constexpr glm::bvec4 B(true);
		constexpr bool A = glm::all(B);
		static_assert(A, "GLM: Failed constexpr");
		
		constexpr glm::bvec4 D(true, false, true, false);
		constexpr bool C = glm::any(D);
		static_assert(C, "GLM: Failed constexpr");
	}
	
	{
		constexpr glm::bvec4 C(true);
		constexpr glm::bvec4 B(true, false, true, false);
		static_assert(glm::any(glm::equal(C, B)), "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec4 O(glm::ivec4(1));
		static_assert(glm::ivec4(1) == O, "GLM: Failed constexpr");

		constexpr glm::ivec4 A(1);
		static_assert(glm::ivec4(1) == A, "GLM: Failed constexpr");

		constexpr glm::ivec4 N(glm::ivec4(1, 2, 3, 4));
		static_assert(glm::ivec4(1, 2, 3, 4) == N, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec4 A(glm::ivec3(1, 2, 3), 4);
		static_assert(glm::ivec4(1, 2, 3, 4) == A, "GLM: Failed constexpr");

		constexpr glm::ivec4 B(glm::ivec2(1, 2), glm::ivec2(3, 4));
		static_assert(glm::ivec4(1, 2, 3, 4) == B, "GLM: Failed constexpr");

		constexpr glm::ivec4 C(1, glm::ivec3(2, 3, 4));
		static_assert(glm::ivec4(1, 2, 3, 4) == C, "GLM: Failed constexpr");

		constexpr glm::ivec4 D(glm::ivec1(1), glm::ivec2(2, 3), glm::ivec1(4));
		static_assert(glm::ivec4(1, 2, 3, 4) == D, "GLM: Failed constexpr");

		constexpr glm::ivec4 E(glm::ivec2(1, 2), glm::ivec1(3), glm::ivec1(4));
		static_assert(glm::ivec4(1, 2, 3, 4) == E, "GLM: Failed constexpr");

		constexpr glm::ivec4 F(glm::ivec1(1), glm::ivec1(2), glm::ivec2(3, 4));
		static_assert(glm::ivec4(1, 2, 3, 4) == F, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec4 A(1);
		static_assert(A[0] == 1, "GLM: Failed constexpr");
		static_assert(glm::ivec4(1).x > 0, "GLM: Failed constexpr");
		static_assert(glm::ivec4(1.0f, -1.0f, -1.0f, 1.0f).x > 0, "GLM: Failed constexpr");
		static_assert(glm::ivec4(1.0f, -1.0f, -1.0f, 1.0f).y < 0, "GLM: Failed constexpr");
		static_assert(glm::ivec4::length() == 4, "GLM: Failed constexpr");
	}

	{
		constexpr glm::bvec4 A1(true);
		constexpr glm::bvec4 A2(true);
		constexpr glm::bvec4 B1(false);
		constexpr glm::bvec4 B2(false);
		static_assert(A1 == A2 && B1 == B2, "GLM: Failed constexpr");
		static_assert(A1 == A2 || B1 == B2, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec4 A(1);
		constexpr glm::ivec4 B = A + 1;
		constexpr glm::ivec4 C(3);
		static_assert(A + B == C, "GLM: Failed constexpr");

		constexpr glm::ivec4 D = +A;
		static_assert(D == A, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec4 A(3);
		constexpr glm::ivec4 B = A - 1;
		constexpr glm::ivec4 C(1);
		static_assert(A - B == C, "GLM: Failed constexpr");

		constexpr glm::ivec4 D = -A;
		static_assert(-D == A, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec4 A(3);
		constexpr glm::ivec4 B = A * 1;
		static_assert(A == B, "GLM: Failed constexpr");

		constexpr glm::ivec4 C(1);
		static_assert(B * C == A, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec4 A(3);
		constexpr glm::ivec4 B = A / 1;
		static_assert(A == B, "GLM: Failed constexpr");

		constexpr glm::ivec4 C(1);
		static_assert(B / C == A, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec4 A(3);
		constexpr glm::ivec4 B = A % 2;
		constexpr glm::ivec4 C(1);
		static_assert(B == C, "GLM: Failed constexpr");

		constexpr glm::ivec1 D(2);
		static_assert(A % D == C, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec4 A(1);
		constexpr glm::ivec4 B = A & 1;
		static_assert(A == B, "GLM: Failed constexpr");

		constexpr glm::ivec1 C(1);
		static_assert(A == (A & C), "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec4 A(1);
		constexpr glm::ivec4 B = A | 1;
		static_assert(A == B, "GLM: Failed constexpr");

		constexpr glm::ivec1 C(1);
		static_assert(A == (A | C), "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec4 A(1);
		constexpr glm::ivec4 B = A ^ 0;
		static_assert(A == B, "GLM: Failed constexpr");

		constexpr glm::ivec1 C(0);
		static_assert(A == (A ^ C), "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec4 A(1);
		constexpr glm::ivec4 B = A << 1;
		static_assert(B == glm::ivec4(2), "GLM: Failed constexpr");

		constexpr glm::ivec1 C(1);
		static_assert(B == (A << C), "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec4 A(2);
		constexpr glm::ivec4 B = A >> 1;
		static_assert(B == glm::ivec4(1), "GLM: Failed constexpr");

		constexpr glm::ivec1 C(1);
		static_assert(B == A >> C, "GLM: Failed constexpr");
	}

	{
		constexpr glm::ivec4 A(~0);
		constexpr glm::ivec4 B = ~A;
		static_assert(A == ~B, "GLM: Failed constexpr");
	}

	return Error;
}

static int test_quat()
{
	int Error = 0;

	{
		static_assert(glm::quat::length() == 4, "GLM: Failed constexpr");
		static_assert(glm::quat(1.0f, glm::vec3(0.0f)).w > 0.0f, "GLM: Failed constexpr");
		static_assert(glm::quat(1.0f, 0.0f, 0.0f, 0.0f).w > 0.0f, "GLM: Failed constexpr");

		glm::quat constexpr Q = glm::identity<glm::quat>();
		static_assert(Q.x - glm::quat(1.0f, glm::vec3(0.0f)).x <= glm::epsilon<float>(), "GLM: Failed constexpr");
	}

	return Error;
}

static int test_mat2x2()
{
	int Error = 0;

	static_assert(glm::mat2x2::length() == 2, "GLM: Failed constexpr");

	return Error;
}

static int test_mat3x3()
{
	int Error = 0;

	static_assert(glm::mat3x3::length() == 3, "GLM: Failed constexpr");

	constexpr glm::mat3x3 const Z(1.0f);
	Error += glm::all(glm::equal(Z, glm::mat3x3(1.0f), glm::epsilon<float>())) ? 0 : 1;

	return Error;
}

static int test_mat3x4()
{
	int Error = 0;

	static_assert(glm::mat3x4::length() == 3, "GLM: Failed constexpr");

	constexpr glm::mat3x4 const Z(1.0f);
	Error += glm::all(glm::equal(Z, glm::mat3x4(1.0f), glm::epsilon<float>())) ? 0 : 1;

	return Error;
}

static int test_mat4x2()
{
	int Error = 0;

	static_assert(glm::mat4x2::length() == 4, "GLM: Failed constexpr");

	constexpr glm::mat4x2 const Z(1.0f);
	Error += glm::all(glm::equal(Z, glm::mat4x2(1.0f), glm::epsilon<float>())) ? 0 : 1;

	return Error;
}

static int test_mat4x3()
{
	int Error = 0;

	static_assert(glm::mat4x3::length() == 4, "GLM: Failed constexpr");

	constexpr glm::mat4x3 const Z(1.0f);
	Error += glm::all(glm::equal(Z, glm::mat4x3(1.0f), glm::epsilon<float>())) ? 0 : 1;

	return Error;
}

static int test_mat4x4()
{
	int Error = 0;

	static_assert(glm::mat4::length() == 4, "GLM: Failed constexpr");
	constexpr glm::mat4 A(1.f);
	constexpr glm::mat4 B(1.f);
	constexpr glm::bvec4 C = glm::equal(A, B, 0.01f);
	static_assert(glm::all(C), "GLM: Failed constexpr");

	constexpr glm::mat4 const Z(1.0f);
	Error += glm::all(glm::equal(Z, glm::mat4(1.0f), glm::epsilon<float>())) ? 0 : 1;

	return Error;
}

static int test_common()
{
	static_assert(glm::abs(1.0f) > 0.0f, "GLM: Failed constexpr");
	constexpr glm::vec1 const A = glm::abs(glm::vec1(1.0f));
	constexpr glm::vec2 const B = glm::abs(glm::vec2(1.0f));
	constexpr glm::vec3 const C = glm::abs(glm::vec3(1.0f));
	constexpr glm::vec4 const D = glm::abs(glm::vec4(1.0f));

	static_assert(glm::all(glm::equal(A, glm::vec1(1.0f), glm::epsilon<float>())), "GLM: Failed constexpr");
	static_assert(glm::all(glm::equal(B, glm::vec2(1.0f), glm::epsilon<float>())), "GLM: Failed constexpr");
	static_assert(glm::all(glm::equal(C, glm::vec3(1.0f), glm::epsilon<float>())), "GLM: Failed constexpr");
	static_assert(glm::all(glm::equal(D, glm::vec4(1.0f), glm::epsilon<float>())), "GLM: Failed constexpr");

	return 0;
}

int main()
{
	int Error = 0;

	Error += test_vec1();
	Error += test_vec2();
	Error += test_vec3();
	Error += test_vec4();
	Error += test_quat();
	Error += test_mat2x2();
	Error += test_mat3x3();
	Error += test_mat3x4();
	Error += test_mat4x2();
	Error += test_mat4x3();
	Error += test_mat4x4();

	Error += test_common();

	return Error;
}

#else

int main()
{
	return 0;
}

#endif

