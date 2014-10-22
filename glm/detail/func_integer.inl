///////////////////////////////////////////////////////////////////////////////////
/// OpenGL Mathematics (glm.g-truc.net)
///
/// Copyright (c) 2005 - 2014 G-Truc Creation (www.g-truc.net)
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
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
/// THE SOFTWARE.
///
/// @ref core
/// @file glm/core/func_integer.inl
/// @date 2010-03-17 / 2011-06-15
/// @author Christophe Riccio
///////////////////////////////////////////////////////////////////////////////////

#include "type_vec2.hpp"
#include "type_vec3.hpp"
#include "type_vec4.hpp"
#include "type_int.hpp"
#include "_vectorize.hpp"
#if(GLM_ARCH != GLM_ARCH_PURE)
#if(GLM_COMPILER & GLM_COMPILER_VC)
#	include <intrin.h>
#	pragma intrinsic(_BitScanReverse)
#endif//(GLM_COMPILER & GLM_COMPILER_VC)
#endif//(GLM_ARCH != GLM_ARCH_PURE)
#include <limits>

namespace glm
{
	// uaddCarry
	GLM_FUNC_QUALIFIER uint uaddCarry(uint const & x, uint const & y, uint & Carry)
	{
		uint64 Value64 = static_cast<uint64>(x) + static_cast<uint64>(y);
		uint32 Result = static_cast<uint32>(Value64 % (static_cast<uint64>(1) << static_cast<uint64>(32)));
		Carry = (Value64 % (static_cast<uint64>(1) << static_cast<uint64>(32))) > 1 ? static_cast<uint32>(1) : static_cast<uint32>(0);
		return Result;
	}

	template <precision P, template <typename, precision> class vecType>
	GLM_FUNC_QUALIFIER vecType<uint, P> uaddCarry(vecType<uint, P> const & x, vecType<uint, P> const & y, vecType<uint, P> & Carry)
	{
		vecType<uint64, P> Value64(vecType<uint64, P>(x) + vecType<uint64, P>(y));
		vecType<uint32, P> Result(Value64 % (static_cast<uint64>(1) << static_cast<uint64>(32)));

		vecType<bool, P> DoCarry(greaterThan(Value64 % (static_cast<uint64>(1) << static_cast<uint64>(32)), vecType<uint64, P>(1)));
		Carry = mix(vecType<uint32, P>(0), vecType<uint32, P>(1), DoCarry);

		return Result;
	}

	// usubBorrow
	GLM_FUNC_QUALIFIER uint usubBorrow(uint const & x, uint const & y, uint & Borrow)
	{
		GLM_STATIC_ASSERT(sizeof(uint) == sizeof(uint32), "uint and uint32 size mismatch");

		Borrow = x >= y ? static_cast<uint32>(0) : static_cast<uint32>(1);
		if(y >= x)
			return y - x;
		else
			return static_cast<uint32>((static_cast<int64>(1) << static_cast<int64>(32)) + (static_cast<int64>(y) - static_cast<int64>(x)));
	}

	template <precision P, template <typename, precision> class vecType>
	GLM_FUNC_QUALIFIER vecType<uint, P> usubBorrow(vecType<uint, P> const & x, vecType<uint, P> const & y, vecType<uint, P> & Borrow)
	{
		Borrow = mix(vecType<uint, P>(1), vecType<uint, P>(0), greaterThanEqual(x, y));
		vecType<uint, P> const YgeX(y - x);
		vecType<uint, P> const XgeY(vecType<uint32, P>((static_cast<int64>(1) << static_cast<int64>(32)) + (vecType<int64, P>(y) - vecType<int64, P>(x))));
		return mix(XgeY, YgeX, greaterThanEqual(y, x));
	}

	// umulExtended
	GLM_FUNC_QUALIFIER void umulExtended(uint const & x, uint const & y, uint & msb, uint & lsb)
	{
		GLM_STATIC_ASSERT(sizeof(uint) == sizeof(uint32), "uint and uint32 size mismatch");

		uint64 Value64 = static_cast<uint64>(x) * static_cast<uint64>(y);
		uint32* PointerMSB = (reinterpret_cast<uint32*>(&Value64) + 1);
		msb = *PointerMSB;
		uint32* PointerLSB = (reinterpret_cast<uint32*>(&Value64) + 0);
		lsb = *PointerLSB;
	}

	template <precision P, template <typename, precision> class vecType>
	GLM_FUNC_QUALIFIER void umulExtended(vecType<uint, P> const & x, vecType<uint, P> const & y, vecType<uint, P> & msb, vecType<uint, P> & lsb)
	{
		GLM_STATIC_ASSERT(sizeof(uint) == sizeof(uint32), "uint and uint32 size mismatch");

		vecType<uint64, P> Value64(vecType<uint64, P>(x) * vecType<uint64, P>(y));
		msb = vecType<uint32, P>(Value64 >> static_cast<uint64>(32));
		lsb = vecType<uint32, P>(Value64);
	}

	// imulExtended
	GLM_FUNC_QUALIFIER void imulExtended(int x, int y, int & msb, int & lsb)
	{
		GLM_STATIC_ASSERT(sizeof(int) == sizeof(int32), "int and int32 size mismatch");

		int64 Value64 = static_cast<int64>(x) * static_cast<int64>(y);
		int32* PointerMSB = (reinterpret_cast<int32*>(&Value64) + 1);
		msb = *PointerMSB;
		int32* PointerLSB = (reinterpret_cast<int32*>(&Value64));
		lsb = *PointerLSB;
	}

	template <precision P, template <typename, precision> class vecType>
	GLM_FUNC_QUALIFIER void imulExtended(vecType<int, P> const & x, vecType<int, P> const & y, vecType<int, P> & msb, vecType<int, P> & lsb)
	{
		GLM_STATIC_ASSERT(sizeof(int) == sizeof(int32), "int and int32 size mismatch");

		vecType<int64, P> Value64(vecType<int64, P>(x) * vecType<int64, P>(y));
		lsb = vecType<int32, P>(Value64 & static_cast<int64>(0xFFFFFFFF));
		msb = vecType<int32, P>((Value64 >> static_cast<int64>(32)) & static_cast<int64>(0xFFFFFFFF));
	}

	// bitfieldExtract
	template <typename genIUType>
	GLM_FUNC_QUALIFIER genIUType bitfieldExtract(genIUType Value, int Offset, int Bits)
	{
		return bitfieldExtract(tvec1<genIUType>(Value), Offset, Bits).x;
	}

	template <typename T, precision P, template <typename, precision> class vecType>
	GLM_FUNC_QUALIFIER vecType<T, P> bitfieldExtract(vecType<T, P> const & Value, int const & Offset, int const & Bits)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_integer, "'bitfieldExtract' only accept integer inputs");

		int GenSize = int(sizeof(T)) << int(3);

		assert(Offset + Bits <= GenSize);

		vecType<T, P> ShiftLeft(0);
		if(Bits)
			ShiftLeft = Value << static_cast<T>(GenSize - (Bits + Offset));
		vecType<T, P> const ShiftBack = ShiftLeft >> static_cast<T>(GenSize - Bits);

		return ShiftBack;
	}

	// bitfieldInsert
	template <typename genIUType>
	GLM_FUNC_QUALIFIER genIUType bitfieldInsert
	(
		genIUType const & Base,
		genIUType const & Insert,
		int const & Offset,
		int const & Bits
	)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genIUType>::is_integer, "'bitfieldInsert' only accept integer values");
		assert(Offset + Bits <= sizeof(genIUType));

		if(Bits == 0)
			return Base;

		genIUType Mask = 0;
		for(int Bit = Offset; Bit < Offset + Bits; ++Bit)
			Mask |= (1 << Bit);

		return (Base & ~Mask) | (Insert & Mask);
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tvec2<T, P> bitfieldInsert
	(
		tvec2<T, P> const & Base,
		tvec2<T, P> const & Insert,
		int const & Offset,
		int const & Bits
	)
	{
		return tvec2<T, P>(
			bitfieldInsert(Base[0], Insert[0], Offset, Bits),
			bitfieldInsert(Base[1], Insert[1], Offset, Bits));
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tvec3<T, P> bitfieldInsert
	(
		tvec3<T, P> const & Base,
		tvec3<T, P> const & Insert,
		int const & Offset,
		int const & Bits
	)
	{
		return tvec3<T, P>(
			bitfieldInsert(Base[0], Insert[0], Offset, Bits),
			bitfieldInsert(Base[1], Insert[1], Offset, Bits),
			bitfieldInsert(Base[2], Insert[2], Offset, Bits));
	}

	template <typename T, precision P>
	GLM_FUNC_QUALIFIER tvec4<T, P> bitfieldInsert
	(
		tvec4<T, P> const & Base,
		tvec4<T, P> const & Insert,
		int const & Offset,
		int const & Bits
	)
	{
		return tvec4<T, P>(
			bitfieldInsert(Base[0], Insert[0], Offset, Bits),
			bitfieldInsert(Base[1], Insert[1], Offset, Bits),
			bitfieldInsert(Base[2], Insert[2], Offset, Bits),
			bitfieldInsert(Base[3], Insert[3], Offset, Bits));
	}

	// bitfieldReverse
	template <typename T>
	GLM_FUNC_QUALIFIER T bitfieldReverse(T v)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_integer, "'bitfieldReverse' only accept integer values");

		return bitfieldReverse(tvec1<T>(v)).x;
	}

	template <typename T, precision P, template <typename, precision> class vecType>
	GLM_FUNC_QUALIFIER vecType<T, P> bitfieldReverse(vecType<T, P> const & v)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_integer, "'bitfieldReverse' only accept integer values");

		vecType<T, P> Result(0);
		vecType<T, P> const Null(0);
		T const BitSize = static_cast<T>(sizeof(T) * 8);
		for(T i = 0; i < BitSize; ++i)
		{
			vecType<T, P> const BitSet(v & (static_cast<T>(1) << i));
			vecType<T, P> const BitFirst(BitSet >> i);
			Result |= BitFirst << (BitSize - 1 - i);
		}
		return Result;
	}

	// bitCount
	template <typename genIUType>
	GLM_FUNC_QUALIFIER int bitCount(genIUType x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genIUType>::is_integer, "'bitCount' only accept integer values");

		return bitCount(tvec1<genIUType>(x)).x;
	}

	template <typename T, precision P, template <typename, precision> class vecType>
	GLM_FUNC_QUALIFIER vecType<int, P> bitCount(vecType<T, P> const & v)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_integer, "'bitCount' only accept integer values");

		vecType<int, P> Count(0);
		for(std::size_t i = 0; i < sizeof(T) * std::size_t(8); ++i)
		{
			if(v & (static_cast<T>(1) << i))
				++Count;
		}
		return Count;
	}

	// findLSB
	template <typename genIUType>
	GLM_FUNC_QUALIFIER int findLSB(genIUType Value)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genIUType>::is_integer, "'findLSB' only accept integer values");
		if(Value == 0)
			return -1;

		genIUType Bit;
		for(Bit = genIUType(0); !(Value & (1 << Bit)); ++Bit){}
		return Bit;
	}

	template <typename T, precision P, template <typename, precision> class vecType>
	GLM_FUNC_QUALIFIER vecType<int, P> findLSB(vecType<T, P> const & x)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<T>::is_integer, "'findLSB' only accept integer values");

		return detail::functor1<int, T, P, vecType>::call(findLSB, x);
	}

	// findMSB
#if (GLM_ARCH != GLM_ARCH_PURE) && (GLM_COMPILER & GLM_COMPILER_VC)

	template <typename genIUType>
	GLM_FUNC_QUALIFIER int findMSB(genIUType Value)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genIUType>::is_integer, "'findMSB' only accept integer values");
		if(Value == 0)
			return -1;

		unsigned long Result(0);
		_BitScanReverse(&Result, Value);
		return int(Result);
	}
/*
// __builtin_clz seems to be buggy as it crasks for some values, from 0x00200000 to 80000000
#elif((GLM_ARCH != GLM_ARCH_PURE) && (GLM_COMPILER & GLM_COMPILER_GCC) && (GLM_COMPILER >= GLM_COMPILER_GCC40))

	template <typename genIUType>
	GLM_FUNC_QUALIFIER int findMSB
	(
		genIUType const & Value
	)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genIUType>::is_integer, "'findMSB' only accept integer values");
		if(Value == 0)
			return -1;

		// clz returns the number or trailing 0-bits; see
		// http://gcc.gnu.org/onlinedocs/gcc-4.7.1/gcc/Other-Builtins.html
		//
		// NoteBecause __builtin_clz only works for unsigned ints, this
		// implementation will not work for 64-bit integers.
		//
		return 31 - __builtin_clzl(Value);
	}
*/
#else

/* SSE implementation idea

		__m128i const Zero = _mm_set_epi32( 0,  0,  0,  0);
		__m128i const One = _mm_set_epi32( 1,  1,  1,  1);
		__m128i Bit = _mm_set_epi32(-1, -1, -1, -1);
		__m128i Tmp = _mm_set_epi32(Value, Value, Value, Value);
		__m128i Mmi = Zero;
		for(int i = 0; i < 32; ++i)
		{
			__m128i Shilt = _mm_and_si128(_mm_cmpgt_epi32(Tmp, One), One);
			Tmp = _mm_srai_epi32(Tmp, One);
			Bit = _mm_add_epi32(Bit, _mm_and_si128(Shilt, i));
			Mmi = _mm_and_si128(Mmi, One);
		}
		return Bit;
*/

	template <typename genIUType>
	GLM_FUNC_QUALIFIER int findMSB(genIUType Value)
	{
		GLM_STATIC_ASSERT(std::numeric_limits<genIUType>::is_integer, "'findMSB' only accept integer values");
		
		if(Value == genIUType(0) || Value == genIUType(-1))
			return -1;
		else if(Value > 0)
		{
			genIUType Bit = genIUType(-1);
			for(genIUType tmp = Value; tmp > 0; tmp >>= 1, ++Bit){}
			return Bit;
		}
		else //if(Value < 0)
		{
			int const BitCount(sizeof(genIUType) * 8);
			int MostSignificantBit(-1);
			for(int BitIndex(0); BitIndex < BitCount; ++BitIndex)
				MostSignificantBit = (Value & (1 << BitIndex)) ? MostSignificantBit : BitIndex;
			assert(MostSignificantBit >= 0);
			return MostSignificantBit;
		}
	}
#endif//(GLM_COMPILER)

	template <typename T, precision P, template <typename, precision> class vecType>
	GLM_FUNC_QUALIFIER vecType<int, P> findMSB(vecType<T, P> const & x)
	{
		return detail::functor1<int, T, P, vecType>::call(findMSB, x);
	}
}//namespace glm
