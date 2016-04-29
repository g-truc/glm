///////////////////////////////////////////////////////////////////////////////////
/// OpenGL Mathematics (glm.g-truc.net)
///
/// Copyright (c) 2005 - 2016 G-Truc Creation (www.g-truc.net)
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
/// @file test/gtx/gtx_io.cpp
/// @date 2013-11-22 / 2016-03-14
/// @author Jan P Springer (regnirpsj@gmail.com)
///////////////////////////////////////////////////////////////////////////////////

#include <glm/gtc/type_precision.hpp>
#include <glm/gtx/io.hpp>
#include <iostream>
#include <sstream>
#include <typeinfo>

namespace
{
	template <typename CTy, typename CTr>
	std::basic_ostream<CTy,CTr>& operator<<(std::basic_ostream<CTy,CTr>& os, glm::precision const& a)
	{
		typename std::basic_ostream<CTy,CTr>::sentry const cerberus(os);

		if (cerberus)
		{
			switch (a) {
			case glm::highp:   os << "hi"; break;
			case glm::mediump: os << "md"; break;
			case glm::lowp:    os << "lo"; break;
			}
		}

		return os;
	}

	template <typename U, glm::precision P, typename T, typename CTy, typename CTr>
	std::basic_string<CTy> type_name(std::basic_ostream<CTy,CTr>& os, T const&)
	{
		std::basic_ostringstream<CTy,CTr> ostr;

		if      (typeid(T) == typeid(glm::tquat<U,P>))   { ostr << "quat"; }
		else if (typeid(T) == typeid(glm::tvec2<U,P>))   { ostr << "vec2"; }
		else if (typeid(T) == typeid(glm::tvec3<U,P>))   { ostr << "vec3"; }
		else if (typeid(T) == typeid(glm::tvec4<U,P>))   { ostr << "vec4"; }
		else if (typeid(T) == typeid(glm::tmat2x2<U,P>)) { ostr << "mat2x2"; }
		else if (typeid(T) == typeid(glm::tmat2x3<U,P>)) { ostr << "mat2x3"; }
		else if (typeid(T) == typeid(glm::tmat2x4<U,P>)) { ostr << "mat2x4"; }
		else if (typeid(T) == typeid(glm::tmat3x2<U,P>)) { ostr << "mat3x2"; }
		else if (typeid(T) == typeid(glm::tmat3x3<U,P>)) { ostr << "mat3x3"; }
		else if (typeid(T) == typeid(glm::tmat3x4<U,P>)) { ostr << "mat3x4"; }
		else if (typeid(T) == typeid(glm::tmat4x2<U,P>)) { ostr << "mat4x2"; }
		else if (typeid(T) == typeid(glm::tmat4x3<U,P>)) { ostr << "mat4x3"; }
		else if (typeid(T) == typeid(glm::tmat4x4<U,P>)) { ostr << "mat4x4"; }
		else                                             { ostr << "unknown"; }

		ostr << '<' << typeid(U).name() << ',' << P << '>';

		return ostr.str();
	}
} // namespace {

template <typename T, glm::precision P, typename OS>
int test_io_quat(OS& os)
{
	os << '\n' << typeid(OS).name() << '\n';

	glm::tquat<T,P> const q(1, 0, 0, 0);

	{
		glm::io::basic_format_saver<typename OS::char_type> const iofs(os);

		os << glm::io::precision(2) << glm::io::width(1 + 2 + 1 + 2)
			<< type_name<T,P>(os, q) << ": " << q << '\n';
	}

	{
		glm::io::basic_format_saver<typename OS::char_type> const iofs(os);

		os << glm::io::unformatted
			<< type_name<T,P>(os, q) << ": " << q << '\n';
	}

	return 0;
}

template <typename T, glm::precision P, typename OS>
int test_io_vec(OS& os)
{
	os << '\n' << typeid(OS).name() << '\n';

	glm::tvec2<T,P> const v2(0, 1);
	glm::tvec3<T,P> const v3(2, 3, 4);
	glm::tvec4<T,P> const v4(5, 6, 7, 8);

	os << type_name<T,P>(os, v2) << ": " << v2 << '\n'
		<< type_name<T,P>(os, v3) << ": " << v3 << '\n'
		<< type_name<T,P>(os, v4) << ": " << v4 << '\n';

	glm::io::basic_format_saver<typename OS::char_type> const iofs(os);

	os << glm::io::precision(2) << glm::io::width(1 + 2 + 1 + 2)
		<< type_name<T,P>(os, v2) << ": " << v2 << '\n'
		<< type_name<T,P>(os, v3) << ": " << v3 << '\n'
		<< type_name<T,P>(os, v4) << ": " << v4 << '\n';

	return 0;
}

template <typename T, glm::precision P, typename OS>
int test_io_mat(OS& os, glm::io::order_type otype)
{
	os << '\n' << typeid(OS).name() << '\n';

	glm::tvec2<T,P> const v2_1( 0,  1);
	glm::tvec2<T,P> const v2_2( 2,  3);
	glm::tvec2<T,P> const v2_3( 4,  5);
	glm::tvec2<T,P> const v2_4( 6,  7);
	glm::tvec3<T,P> const v3_1( 8,  9, 10);
	glm::tvec3<T,P> const v3_2(11, 12, 13);
	glm::tvec3<T,P> const v3_3(14, 15, 16);
	glm::tvec3<T,P> const v3_4(17, 18, 19);
	glm::tvec4<T,P> const v4_1(20, 21, 22, 23);
	glm::tvec4<T,P> const v4_2(24, 25, 26, 27);
	glm::tvec4<T,P> const v4_3(28, 29, 30, 31);
	glm::tvec4<T,P> const v4_4(32, 33, 34, 35);

	glm::io::basic_format_saver<typename OS::char_type> const iofs(os);

	os << glm::io::precision(2) << glm::io::width(1 + 2 + 1 + 2)
		<< glm::io::order(otype)
		<< "mat2x2<" << typeid(T).name() << ',' << P << ">: " << glm::tmat2x2<T,P>(v2_1, v2_2) << '\n'
		<< "mat2x3<" << typeid(T).name() << ',' << P << ">: " << glm::tmat2x3<T,P>(v3_1, v3_2) << '\n'
		<< "mat2x4<" << typeid(T).name() << ',' << P << ">: " << glm::tmat2x4<T,P>(v4_1, v4_2) << '\n'
		<< "mat3x2<" << typeid(T).name() << ',' << P << ">: " << glm::tmat3x2<T,P>(v2_1, v2_2, v2_3) << '\n'
		<< "mat3x3<" << typeid(T).name() << ',' << P << ">: " << glm::tmat3x3<T,P>(v3_1, v3_2, v3_3) << '\n'
		<< "mat3x4<" << typeid(T).name() << ',' << P << ">: " << glm::tmat3x4<T,P>(v4_1, v4_2, v4_3) << '\n'
		<< "mat4x2<" << typeid(T).name() << ',' << P << ">: " << glm::tmat4x2<T,P>(v2_1, v2_2, v2_3, v2_4) << '\n'
		<< "mat4x3<" << typeid(T).name() << ',' << P << ">: " << glm::tmat4x3<T,P>(v3_1, v3_2, v3_3, v3_4) << '\n'
		<< "mat4x4<" << typeid(T).name() << ',' << P << ">: " << glm::tmat4x4<T,P>(v4_1, v4_2, v4_3, v4_4) << '\n';

	os << glm::io::unformatted
		<< glm::io::order(otype)
		<< "mat2x2<" << typeid(T).name() << ',' << P << ">: " << glm::tmat2x2<T,P>(v2_1, v2_2) << '\n'
		<< "mat2x3<" << typeid(T).name() << ',' << P << ">: " << glm::tmat2x3<T,P>(v3_1, v3_2) << '\n'
		<< "mat2x4<" << typeid(T).name() << ',' << P << ">: " << glm::tmat2x4<T,P>(v4_1, v4_2) << '\n'
		<< "mat3x2<" << typeid(T).name() << ',' << P << ">: " << glm::tmat3x2<T,P>(v2_1, v2_2, v2_3) << '\n'
		<< "mat3x3<" << typeid(T).name() << ',' << P << ">: " << glm::tmat3x3<T,P>(v3_1, v3_2, v3_3) << '\n'
		<< "mat3x4<" << typeid(T).name() << ',' << P << ">: " << glm::tmat3x4<T,P>(v4_1, v4_2, v4_3) << '\n'
		<< "mat4x2<" << typeid(T).name() << ',' << P << ">: " << glm::tmat4x2<T,P>(v2_1, v2_2, v2_3, v2_4) << '\n'
		<< "mat4x3<" << typeid(T).name() << ',' << P << ">: " << glm::tmat4x3<T,P>(v3_1, v3_2, v3_3, v3_4) << '\n'
		<< "mat4x4<" << typeid(T).name() << ',' << P << ">: " << glm::tmat4x4<T,P>(v4_1, v4_2, v4_3, v4_4) << '\n';
  
	return 0;
}

int main()
{
	int Error(0);

	Error += test_io_quat<float, glm::highp>(std::cout);
	Error += test_io_quat<float, glm::highp>(std::wcout);
	Error += test_io_quat<int, glm::mediump>(std::cout);
	Error += test_io_quat<int, glm::mediump>(std::wcout);
	Error += test_io_quat<glm::uint, glm::lowp>(std::cout);
	Error += test_io_quat<glm::uint, glm::lowp>(std::wcout);

	Error += test_io_vec<float, glm::highp>(std::cout);
	Error += test_io_vec<float, glm::highp>(std::wcout);
	Error += test_io_vec<int, glm::mediump>(std::cout);
	Error += test_io_vec<int, glm::mediump>(std::wcout);
	Error += test_io_vec<glm::uint, glm::lowp>(std::cout);
	Error += test_io_vec<glm::uint, glm::lowp>(std::wcout);

	Error += test_io_mat<float, glm::highp>(std::cout, glm::io::column_major);
	Error += test_io_mat<float, glm::lowp>(std::wcout, glm::io::column_major);
	Error += test_io_mat<float, glm::highp>(std::cout, glm::io::row_major);
        Error += test_io_mat<float, glm::lowp>(std::wcout, glm::io::row_major);

	return Error;
}
