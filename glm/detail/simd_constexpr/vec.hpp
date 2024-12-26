/// @ref core
/// @file glm/detail/simd_constexpr/vec.hpp

#pragma once

#include "../qualifier.hpp"
#ifdef GLM_CONFIG_SWIZZLE
# undef GLM_CONFIG_SWIZZLE
#endif

#define GLM_CONFIG_SWIZZLE GLM_SWIZZLE_FUNCTION

//sharkautarch: IMO, the GLM swizzle 'operators' are too hacky to me, plus they actually *increase the size of the vec's*, and lastly, I wasn't confident that they'd work well here.
//Instead, we'll just always provide swizzle *functions*, which don't bloat the binary/stack space, and also utilizes simd __builtin_shufflevector intrinsics (for *both* aligned and packed vec's). This'll make them actually be *more performant* compared to separately accessing more than one x/y/z/w(etc) member.
//So no real reason not to simply enable swizzle functions by default!

// NOTE: swizzle functions only return by value. 
//	also all swizzles require you to select at least two members (ex: v.xy(); v2.yzw(); )
#include "../_swizzle_func_gcc_vec.hpp"

#include <cstddef>
#include <array>
#include <variant>
#include <cstring>
#include <ranges>
#include <algorithm>
namespace glm
{
#ifdef __clang__
#define GLM_TRIVIAL __attribute__((trivial_abi))
#else
#define GLM_TRIVIAL
#endif
	
			//improve vectorization by widening length-three vectors that are floating point
			//since the compiler will have a harder time vectorizing glm::vec3's
	template <length_t L>
	concept NotVec1 = !std::is_same_v<std::integral_constant<length_t, L>, std::integral_constant<length_t, 1>>;
	template <qualifier Q>
	consteval bool BIsAlignedQ() {
		return Q == aligned_highp || Q == aligned_mediump || Q == aligned_lowp;
	}
	template <length_t L>
	consteval bool BIsLenThree() {
		return L == 3;
	}
	template <length_t L, typename T, qualifier Q>
	consteval bool BShouldWidenVec() { 
		return BIsLenThree<L>() && BIsAlignedQ<Q>() && std::is_floating_point_v<T>;
	}
	template <typename T>
	concept arithmetic = std::integral<T> || std::floating_point<T>;
	template <typename T0, typename... T>
	consteval bool SameArithmeticTypes() {
		return (std::is_same_v<std::common_type_t<T0,T>, std::common_type_t<T0,T>> && ...);
	}
	template <typename T0, typename... T>
	consteval bool SameTypes() {
		return (std::is_same_v<T0, T> && ...);
	}
	template <typename... T>
	consteval bool NotSameArithmeticTypes() {
		return ( (!(std::is_integral_v<T> || std::is_floating_point_v<T>) || ...) || !(SameArithmeticTypes<T...>()) );
	}
	
	namespace detail
	{
		template <length_t L, typename T, qualifier Q>
		using _ArrT = std::array<T,L>;

		template <length_t L, typename T, qualifier Q>
		using _data_t = typename detail::storage<L, T, detail::is_aligned<Q>::value>::type;
		
		template <length_t L, typename T, qualifier Q>
		struct GccVExt {
			static constexpr length_t v_length = (L == 3) ? 4 : L;
			using VType = std::conditional_t< std::is_same_v<T, bool>, uint8_t, T>;
			typedef VType GccV __attribute__(( vector_size(sizeof(VType)*v_length), aligned(alignof(_data_t<L, T, Q>)) ));
		};
		template <length_t L, typename T, qualifier Q>
		consteval bool BDataNeedsPadding() {
			return sizeof(_data_t<L,T,Q>) > sizeof(_ArrT<L,T,Q>);
		}
		template <length_t L, typename T, qualifier Q>
		consteval bool BVecNeedsPadding() {
			return sizeof(_data_t<L,T,Q>) > sizeof(typename GccVExt<L,T,Q>::GccV);
		}
		template <length_t L, typename T, qualifier Q, bool NeedsPadding>
		struct VecDataArray;
			
		template <length_t L, typename T, qualifier Q>
		struct VecDataArray<L, T, Q, true> {
			using ArrT = _ArrT<L, T, Q>;
			using data_t = _data_t<L,T,Q>;
			ArrT p;
			constexpr auto cbegin() const {
				return p.cbegin();
			}
			std::byte padding[sizeof(data_t) - sizeof(ArrT)];
		};
		template <length_t L, typename T, qualifier Q>
		struct VecDataArray<L, T, Q, false> {
			using ArrT = _ArrT<L, T, Q>;
			ArrT p;
			constexpr auto cbegin() const {
				return p.cbegin();
			}
		};
		
		template <length_t L, typename T, qualifier Q, bool NeedsPadding>
		struct PaddedGccVec;
		
		template <length_t L, typename T, qualifier Q>
		struct PaddedGccVec<L, T, Q, true> {
			using GccV = typename GccVExt<L, T,Q>::GccV;
			using data_t = _data_t<L, T, Q>;
			GccV gcc_vec;
			std::byte padding[sizeof(data_t) - sizeof(GccV)];
		};
	
		template <length_t L, typename T, qualifier Q>
		struct PaddedGccVec<L, T, Q, false> {
			using GccV = typename GccVExt<L, T,Q>::GccV;
			GccV gcc_vec;
		};
	}
	
	/*template <length_t L, typename T, qualifier Q>
	using PaddedGccVec = detail::PaddedGccVec<L, T, Q, detail::BVecNeedsPadding<L, T, Q>()>;*/
	template <length_t L, typename T, qualifier Q>
	using GccVec = typename detail::GccVExt<L, T, Q>::GccV;
	template <length_t L, typename T, qualifier Q>
	using VDataArray = detail::VecDataArray<L, T, Q, detail::BDataNeedsPadding<L, T, Q>()>;
	static_assert(!detail::BDataNeedsPadding<3, float, (glm::qualifier)0>());
}
#include "element.hpp"
#include "simd_helpers.inl"
#include "../compute_vector_relational.hpp"
#include "../compute_vector_decl.hpp"
#if GLM_CONFIG_SIMD == GLM_ENABLE
#	include "../type_vec_simd.inl"
#endif
namespace glm
{
	template<length_t L, typename T, qualifier Q>
	struct GLM_TRIVIAL vec : detail::ElementCollection<L, T, Q>
	{
		// -- Data --
		using EC = detail::ElementCollection<L, T, Q>;
		using EC::x;
		using EC::y;
		using EC::z;
		using EC::w;
		using EC::r;
		using EC::g;
		using EC::b;
		using EC::a;
		using EC::s;
		using EC::t;
		using EC::p;
		using EC::q;
		using EC::data;
		using EC::elementArr;

		using SimdHlp = detail::SimdHelpers<L, T, Q>;
		static constexpr length_t data_len = (Q == aligned && L == 3) ? 4 : L;
		using DataArray = VDataArray<data_len, T, Q>;
		using data_t = typename detail::storage<L, T, detail::is_aligned<Q>::value>::type;
		using GccVec_t = GccVec<L, T, Q>;

		// -- Implementation detail --
		typedef T value_type;
		typedef vec<L, T, Q> type;
		typedef vec<L, bool, Q> bool_type;
		static constexpr qualifier k_qual = Q;
		static constexpr length_t k_len = L;
		
		enum is_aligned
		{
			value = detail::is_aligned<Q>::value
		};

		// -- Component Access --
		static constexpr length_t length(){	return L;	}
		
		inline constexpr T& __attribute__((always_inline,flatten)) operator[](length_t i)
		{
			if (!std::is_constant_evaluated() && !__builtin_constant_p(i) ) {
				GLM_ASSERT_LENGTH(i, L);
			}
			return elementArr.p[i];
		}
		
		inline constexpr T __attribute__((always_inline,flatten)) operator[](length_t i) const
		{
			if (!std::is_constant_evaluated() && !__builtin_constant_p(i) ) {
				GLM_ASSERT_LENGTH(i, L);
			}
			
			return elementArr.p[i];
		}
		
		template <typename Tx, qualifier Qx> requires(std::is_same_v<T, bool>)
		inline vec<L, Tx, Qx> compWiseTernary(vec<L, Tx, Qx> v1, vec<L, Tx, Qx> v2) {
			if constexpr ( sizeof(Tx) == sizeof(int32_t) ) {
				using GVec_t = typename detail::GccVExt<L, int32_t, Q>::GccV;
				GVec_t condMask = __builtin_convertvector(std::bit_cast<GccVec_t>(elementArr), GVec_t);
				auto gv1 = std::bit_cast<GccVec<L, Tx, Qx>>(v1.elementArr);
				auto gv2 = std::bit_cast<GccVec<L, Tx, Qx>>(v2.elementArr);
				return vec<L, Tx, Qx>((condMask ? gv1 : gv2));
			} else if constexpr ( sizeof(Tx) == sizeof(int64_t) ) {
				using GVec_t = typename detail::GccVExt<L, int64_t, Q>::GccV;
				GVec_t condMask = __builtin_convertvector(std::bit_cast<GccVec_t>(elementArr), GVec_t);
				auto gv1 = std::bit_cast<GccVec<L, Tx, Qx>>(v1.elementArr);
				auto gv2 = std::bit_cast<GccVec<L, Tx, Qx>>(v2.elementArr);
				return vec<L, Tx, Qx>((condMask ? gv1 : gv2));
			} else if constexpr ( sizeof(Tx) == sizeof(int16_t) ) {
				using GVec_t = typename detail::GccVExt<L, int16_t, Q>::GccV;
				GVec_t condMask = __builtin_convertvector(std::bit_cast<GccVec_t>(elementArr), GVec_t);
				auto gv1 = std::bit_cast<GccVec<L, Tx, Qx>>(v1.elementArr);
				auto gv2 = std::bit_cast<GccVec<L, Tx, Qx>>(v2.elementArr);
				return vec<L, Tx, Qx>((condMask ? gv1 : gv2));
			} else {
				using GVec_t = typename detail::GccVExt<L, int8_t, Q>::GccV;
				GVec_t condMask = __builtin_convertvector(std::bit_cast<GccVec_t>(elementArr), GVec_t);
				auto gv1 = std::bit_cast<GccVec<L, Tx, Qx>>(v1.elementArr);
				auto gv2 = std::bit_cast<GccVec<L, Tx, Qx>>(v2.elementArr);
				return vec<L, Tx, Qx>((condMask ? gv1 : gv2));
			}
		} 
		
		static constexpr auto __attribute__((always_inline,flatten)) ctor_scalar(arithmetic auto scalar) {
			if (std::is_constant_evaluated()) {
				DataArray a{};
		    for (length_t i = 0; i < L; i++) {
		    	a.p[i]=scalar;
		    }
		    return EC{.elementArr=a};
			} else {
				return EC{.data=SimdHlp::simd_ctor_scalar(scalar)};
			}
		}
		
		template <length_t Lx, typename Tx, qualifier Qx>
		static constexpr auto __attribute__((always_inline,flatten)) ctor(vec<Lx, Tx, Qx> vec) {
			if (std::is_constant_evaluated()) {
				DataArray a;
				using ArrX = VDataArray<Lx, Tx, Qx>;
				ArrX ax = std::bit_cast<ArrX>(vec.data);
				for (length_t i = 0; i < std::min(Lx, L); i++) {
					a.p[i] = (T)ax.p[i];
				}
				
				return EC{.elementArr=a};
			} else {
				return EC{.data=SimdHlp::simd_ctor(vec)};
			}
		}
		template <length_t len>
		using RetArr = std::array<T, len>;
		
		template <typename Vs0>
		static constexpr length_t __attribute__((always_inline)) ctor_mixed_constexpr_single_get_length()
		{
			if constexpr ( std::is_integral_v<Vs0> || std::is_floating_point_v<Vs0> ) {
				return 1;
			} else if constexpr ( ( requires { Vs0::k_len; }) ) {
				return Vs0::k_len;
			} else {
				return 1;
			} 
		}
		static constexpr decltype(auto) __attribute__((always_inline)) ctor_mixed_constexpr_single(auto vs0)
		{
			using VTX = decltype(vs0);
			if constexpr ( std::is_integral_v<VTX> || std::is_floating_point_v<VTX> ) {
				return RetArr<1>{(T)vs0};
			} else if constexpr ( ( requires { VTX::k_len; }) ) {
				using Tx = VTX::value_type;
				using ArrX = VDataArray<VTX::k_len, Tx, VTX::k_qual>;
				
				ArrX ax = std::bit_cast<ArrX>(vs0.data);
				return ax;
			} else {
				using Tx = VTX::value_type;
				return RetArr<1>{(Tx)vs0};
			} 
		}
		
		constexpr __attribute__((always_inline)) vec() = default;
		constexpr __attribute__((always_inline)) vec(arithmetic auto scalar) : EC{ ctor_scalar(scalar)} {}

		template <length_t Lx, typename Tx, qualifier Qx> requires (Lx == 1 && NotVec1<L>)
	  constexpr __attribute__((always_inline)) vec(vec<Lx, Tx, Qx> v) : EC{ [d=std::bit_cast<VDataArray<Lx, Tx, Qx>>(v.elementArr)](){ auto s = [scalar=d.p[0]](){ return scalar; }; return ctor_scalar(s); }() } {}
		
		template <length_t Lx, typename Tx, qualifier Qx> requires (Lx != 1)
		constexpr __attribute__((always_inline)) vec(vec<Lx, Tx, Qx> v) : EC{ ctor(v) } {}

		constexpr __attribute__((always_inline)) vec(GccVec_t d) : EC{.data=reinterpret_cast<data_t>(d)} {}
		
		//template <length_t Lx, typename Tx, qualifier Qx> requires (Lx != 1)
		//constexpr vec(__m128 d) : EC{ .data = std::bit_cast<detail::_data_t<L, T, Q>>(d) } {}
		template <arithmetic... Scalar> requires (sizeof...(Scalar) == L)
		constexpr auto __attribute__((always_inline)) ctor_multi_scalar_func(Scalar... scalar) {
			if (std::is_constant_evaluated() || (L == 3)) {
				DataArray a = {.p={ static_cast<T>(scalar)... }};
				return EC{.elementArr=a};
			} else {
				return EC{.data=SimdHlp::simd_ctor_multi_scalars(scalar...)};
			}
		}
		
		template <arithmetic... Scalar> requires (sizeof...(Scalar) == L)
		constexpr __attribute__((always_inline)) vec(Scalar... scalar)
		: EC
			{ ctor_multi_scalar_func(scalar...)
			} {}
		
		template <typename VecOrScalar0, typename... VecOrScalar> requires (sizeof...(VecOrScalar) >= 1 && NotSameArithmeticTypes<VecOrScalar0, VecOrScalar...>())
		constexpr EC __attribute__((always_inline)) ctor_multi_mixed_func(VecOrScalar0 const&__restrict__ vecOrScalar0, VecOrScalar... vecOrScalar)
		{
					//type_vecx.inl never had any simd versions for ctor from mixes of scalars & vectors,
					//so I don't really need to figure out how I'd make a generic simd version for this ctor 
					
					constexpr auto i = ctor_mixed_constexpr_single_get_length<VecOrScalar0>();

					struct PaddedA {
						VDataArray<i, T, Q> a;
						unsigned char padding[sizeof(VDataArray<L, T, Q>) - sizeof(VDataArray<i, T, Q>)];
					};
					auto destArr = std::bit_cast<VDataArray<L, T, Q>>(PaddedA{.a=ctor_mixed_constexpr_single(vecOrScalar0)});
					constexpr std::array<length_t, sizeof...(VecOrScalar)> lengths = { ctor_mixed_constexpr_single_get_length<VecOrScalar>()...};
					const auto params = std::tuple{vecOrScalar...};
					
					const auto arr = ctor_mixed_constexpr_single(std::get<0>(params));
					std::ranges::copy_n(arr.cbegin(), lengths[0], destArr.p.begin()+i);
					constexpr auto i2 = i + lengths[0];
					
					if constexpr (sizeof...(VecOrScalar) > 1) {
						const auto arr2 = ctor_mixed_constexpr_single(std::get<1>(params));
						std::ranges::copy_n(arr2.cbegin(), lengths[1], destArr.p.begin()+i2);
						constexpr auto i3 = i2 + lengths[1];
						if constexpr (sizeof...(VecOrScalar) > 2) {
							const auto arr3 = ctor_mixed_constexpr_single(std::get<2>(params));
							std::ranges::copy_n(arr3.cbegin(), lengths[2], destArr.p.begin()+i3);
						}
					}
					
					return std::bit_cast<EC>(destArr);
		}
		template <typename VecOrScalar0, typename... VecOrScalar> requires (sizeof...(VecOrScalar) >= 1 && NotSameArithmeticTypes<VecOrScalar0, VecOrScalar...>())
		constexpr __attribute__((always_inline)) vec(VecOrScalar0 const&__restrict__ vecOrScalar0, VecOrScalar... vecOrScalar)
		: EC
			{ctor_multi_mixed_func(vecOrScalar0, vecOrScalar...)} {}


			
		inline GLM_CONSTEXPR vec<L, T, Q>& __attribute__((always_inline)) operator+=(arithmetic auto scalar)
		{
			if constexpr (BShouldWidenVec<L,T,Q>()) {
				vec<4,T,Q> widened(*this);
				
				widened.data += scalar;
				return (*this = vec<3,T,Q>(widened));
			} else if constexpr (L != 3) {
				this->data += scalar;
				return *this;
			} else {
				return (*this = detail::compute_vec_add<L, T, Q, detail::is_aligned<Q>::value>::call(*this, vec<L, T, Q>(scalar)));
			}
		}

		template<typename Tx>
		inline GLM_CONSTEXPR vec<L, T, Q> & __attribute__((always_inline)) operator+=(vec<1, Tx, Q> v) requires (NotVec1<L>)
		{
			if constexpr (BShouldWidenVec<L,T,Q>()) {
				vec<4,T,Q> widened(*this);
				
				widened.data += v.x;
				return (*this = vec<3,T,Q>(widened));
			} else if constexpr (L != 3) {
				this->data += v.x;
				return *this;
			} else
				return (*this = detail::compute_vec_add<L, T, Q, detail::is_aligned<Q>::value>::call(*this, vec<L, T, Q>(v.x)));
		}

		template<typename Tx>
		inline GLM_CONSTEXPR vec<L, T, Q> & __attribute__((always_inline)) operator+=(vec<L, Tx, Q> const& __restrict__ v)
		{
			if constexpr (BShouldWidenVec<L,T,Q>()) {
				vec<4,T,Q> widened(*this);
				
				widened.data += vec<4,T,Q>(v).data;
				return (*this = vec<3,T,Q>(widened));
			} else if constexpr (L != 3) {
				this->data += v.data;
				return *this;
			} else
				return (*this = detail::compute_vec_add<L, T, Q, detail::is_aligned<Q>::value>::call(*this, vec<L, T, Q>(v)));
		}

		inline GLM_CONSTEXPR vec<L, T, Q> & __attribute__((always_inline)) operator-=(arithmetic auto scalar)
		{
			if constexpr (BShouldWidenVec<L,T,Q>()) {
				vec<4,T,Q> widened(*this);
				
				widened.data -= vec<4,T,Q>(scalar).data;
				return (*this = vec<3,T,Q>(widened));
			} else if constexpr (L != 3) {
				this->data -= scalar;
				return *this;
			} else
				return (*this = detail::compute_vec_sub<L, T, Q, detail::is_aligned<Q>::value>::call(*this, vec<L, T, Q>(scalar)));
		}

		template<typename Tx>
		inline GLM_CONSTEXPR vec<L, T, Q> & __attribute__((always_inline)) operator-=(vec<1, Tx, Q> v) requires (NotVec1<L>)
		{
			if constexpr (BShouldWidenVec<L,T,Q>()) {
				vec<4,T,Q> widened(*this);
				
				widened.data -= vec<4,T,Q>(v.x).data;
				return (*this = vec<3,T,Q>(widened));
			} else if constexpr (L != 3) {
				this->data -= v.x;
				return *this;
			} else
				return (*this = detail::compute_vec_sub<L, T, Q, detail::is_aligned<Q>::value>::call(*this, vec<L, T, Q>(v.x)));
		}

		template<typename Tx>
		inline GLM_CONSTEXPR vec<L, T, Q> & __attribute__((always_inline)) operator-=(vec<L, Tx, Q> const& __restrict__ v)
		{
			if constexpr (BShouldWidenVec<L,T,Q>()) {
				vec<4,T,Q> widened(*this);
				
				widened.data -= vec<4,T,Q>(v).data;
				return (*this = vec<3,T,Q>(widened));
			} else if constexpr (L != 3) {
				this->data -= v.data;
				return *this;
			} else
				return (*this = detail::compute_vec_sub<L, T, Q, detail::is_aligned<Q>::value>::call(*this, vec<L, T, Q>(v)));
		}

		inline GLM_CONSTEXPR vec<L, T, Q> & __attribute__((always_inline)) operator*=(arithmetic auto scalar)
		{
			if constexpr (BShouldWidenVec<L,T,Q>()) {
				vec<4,T,Q> widened(*this);
				
				widened.data *= vec<4,T,Q>(scalar).data;
				return (*this = vec<3,T,Q>(widened));
			} else if constexpr (L != 3) {
				this->data *= scalar;
				return *this;
			} else
				return (*this = detail::compute_vec_mul<L, T, Q, detail::is_aligned<Q>::value>::call(*this, vec<L, T, Q>(scalar)));
		}

		template<typename Tx>
		inline GLM_CONSTEXPR vec<L, T, Q> & __attribute__((always_inline)) operator*=(vec<1, Tx, Q> v) requires (NotVec1<L>)
		{
			if constexpr (BShouldWidenVec<L,T,Q>()) {
				vec<4,T,Q> widened(*this);
				
				widened.data *= vec<4,T,Q>(v.x).data;
				return (*this = vec<3,T,Q>(widened));
			} else if constexpr (L != 3) {
				this->data *= v.x;
				return *this;
			} else
				return (*this = detail::compute_vec_mul<L, T, Q, detail::is_aligned<Q>::value>::call(*this, vec<L, T, Q>(v.x)));
		}

		template<typename Tx>
		inline GLM_CONSTEXPR vec<L, T, Q> & __attribute__((always_inline)) operator*=(vec<L, Tx, Q> const& __restrict__ v)
		{
			if constexpr (BShouldWidenVec<L,T,Q>()) {
				vec<4,T,Q> widened(*this);
				
				widened.data *= vec<4,T,Q>(v).data;
				return (*this = vec<3,T,Q>(widened));
			} else if constexpr (L != 3) {
				this->data *= v.data;
				return *this;
			} else
				return (*this = detail::compute_vec_mul<L, T, Q, detail::is_aligned<Q>::value>::call(*this, vec<L, T, Q>(v)));
		}

		inline GLM_CONSTEXPR vec<L, T, Q> & __attribute__((always_inline)) operator/=(arithmetic auto scalar)
		{
			if constexpr (BShouldWidenVec<L,T,Q>()) {
				vec<4,T,Q> widened(*this);
				
				widened.data /= vec<4,T,Q>(scalar).data;
				return (*this = vec<3,T,Q>(widened));
			} else if constexpr (L != 3) {
				this->data /= scalar;
				return *this;
			} else
				return (*this = detail::compute_vec_div<L, T, Q, detail::is_aligned<Q>::value>::call(*this, vec<L, T, Q>(scalar)));
		}

		template<typename Tx>
		inline GLM_CONSTEXPR vec<L, T, Q> & __attribute__((always_inline)) operator/=(vec<1, Tx, Q> v) requires (NotVec1<L>)
		{
			if constexpr (BShouldWidenVec<L,T,Q>()) {
				vec<4,T,Q> widened(*this);
				
				widened.data /= vec<4,T,Q>(v.x).data;
				return (*this = vec<3,T,Q>(widened));
			} else if constexpr (L != 3) {
				this->data /= v.x;
				return *this;
			} else
				return (*this = detail::compute_vec_div<L, T, Q, detail::is_aligned<Q>::value>::call(*this, vec<L, T, Q>(v.x)));
		}

		template<typename Tx>
		inline GLM_CONSTEXPR vec<L, T, Q> & __attribute__((always_inline)) operator/=(vec<L, Tx, Q> const& __restrict__ v)
		{
			if constexpr (BShouldWidenVec<L,T,Q>()) {
				vec<4,T,Q> widened(*this);
				
				widened.data /= vec<4,T,Q>(v).data;
				return (*this = vec<3,T,Q>(widened));
			} else if constexpr (L != 3) {
				this->data /= v.data;
				return *this;
			} else
				return (*this = detail::compute_vec_div<L, T, Q, detail::is_aligned<Q>::value>::call(*this, vec<L, T, Q>(v)));
		}
		
		// -- Increment and decrement operators --

		inline GLM_CONSTEXPR vec<L, T, Q> & __attribute__((always_inline)) operator++()
		{
			constexpr T one = T(1);
			if constexpr (L != 3) {
				this->data += one;
				return *this;
			} else {
				*this += one;
				return *this;
			}
		}

		inline GLM_CONSTEXPR vec<L, T, Q> & __attribute__((always_inline)) operator--()
		{
			constexpr T one = T(1);
			if constexpr (L != 3) {
				this->data -= one;
				return *this;
			} else {
				*this -= one;
				return *this;
			}
		}

		inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator++(int)
		{
			vec<L, T, Q> Result(*this);
			constexpr T one = T(1);
			if constexpr (L != 3) {
				++*this;
				return Result;
			} else {
				++*this;
				return Result;
			}
		}

		inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator--(int)
		{
			vec<L, T, Q> Result(*this);
			constexpr T one = T(1);
			if constexpr (L != 3) {
				--*this;
				return Result;
			} else {
				--*this;
				return Result;
			}
		}

		// -- Unary bit operators --

		inline GLM_CONSTEXPR vec<L, T, Q> & __attribute__((always_inline)) operator%=(arithmetic auto scalar)
		{
			if constexpr (BShouldWidenVec<L,T,Q>()) {
				vec<4,T,Q> widened(*this);
				
				widened.data %= vec<4,T,Q>(scalar).data;
				return (*this = vec<3,T,Q>(widened));
			} else if constexpr (L != 3) {
				this->data %= scalar;
				return *this;
			} else
				return (*this = detail::compute_vec_mod<L, T, Q, detail::is_aligned<Q>::value>::call(*this, vec<L, T, Q>(scalar)));
		}

		template<typename Tx>
		inline GLM_CONSTEXPR vec<L, T, Q> & __attribute__((always_inline)) operator%=(vec<1, Tx, Q> v) requires (NotVec1<L>)
		{
			if constexpr (BShouldWidenVec<L,T,Q>()) {
				vec<4,T,Q> widened(*this);
				
				widened.data %= vec<4,T,Q>(v.x).data;
				return (*this = vec<3,T,Q>(widened));
			} else if constexpr (L != 3) {
				this->data %= v.x;
				return *this;
			} else
				return (*this = detail::compute_vec_mod<L, T, Q, detail::is_aligned<Q>::value>::call(*this, vec<L, T, Q>(v)));
		}

		template<typename Tx>
		inline GLM_CONSTEXPR vec<L, T, Q> & __attribute__((always_inline)) operator%=(vec<L, Tx, Q> v)
		{
			if constexpr (BShouldWidenVec<L,T,Q>()) {
				vec<4,T,Q> widened(*this);
				
				widened.data %= vec<4,T,Q>(v).data;
				return (*this = vec<3,T,Q>(widened));
			} else if constexpr (L != 3) {
				this->data %= v.data;
				return *this;
			} else
				return (*this = detail::compute_vec_mod<L, T, Q, detail::is_aligned<Q>::value>::call(*this, vec<L, T, Q>(v)));
		}

		inline GLM_CONSTEXPR vec<L, T, Q> & __attribute__((always_inline)) operator&=(arithmetic auto scalar)
		{
			if constexpr (BShouldWidenVec<L,T,Q>()) {
				vec<4,T,Q> widened(*this);
				
				widened.data &= vec<4,T,Q>(scalar).data;
				return (*this = vec<3,T,Q>(widened));
			} else if constexpr (L != 3) {
				this->data &= scalar;
				return *this;
			} else
				return (*this = detail::compute_vec_and<L, T, Q, detail::is_int<T>::value, sizeof(T) * 8, detail::is_aligned<Q>::value>::call(*this, vec<L, T, Q>(scalar)));
		}

		template<typename Tx>
		inline GLM_CONSTEXPR vec<L, T, Q> & __attribute__((always_inline)) operator&=(vec<1, Tx, Q> v) requires (NotVec1<L>)
		{
			if constexpr (BShouldWidenVec<L,T,Q>()) {
				vec<4,T,Q> widened(*this);
				
				widened.data &= vec<4,T,Q>(v.x).data;
				return (*this = vec<3,T,Q>(widened));
			} else if constexpr (L != 3) {
				this->data &= v.x;
				return *this;
			} else
				return (*this = detail::compute_vec_and<L, T, Q, detail::is_int<T>::value, sizeof(T) * 8, detail::is_aligned<Q>::value>::call(*this, vec<L, T, Q>(v)));
		}

		template<typename Tx>
		inline GLM_CONSTEXPR vec<L, T, Q> & __attribute__((always_inline)) operator&=(vec<L, Tx, Q> v)
		{
			if constexpr (BShouldWidenVec<L,T,Q>()) {
				vec<4,T,Q> widened(*this);
				
				widened.data &= vec<4,T,Q>(v).data;
				return (*this = vec<3,T,Q>(widened));
			} else if constexpr (L != 3) {
				this->data &= v.data;
				return *this;
			} else
				return (*this = detail::compute_vec_and<L, T, Q, detail::is_int<T>::value, sizeof(T) * 8, detail::is_aligned<Q>::value>::call(*this, vec<L, T, Q>(v)));
		}

		inline GLM_CONSTEXPR vec<L, T, Q> & __attribute__((always_inline)) operator|=(arithmetic auto scalar)
		{
			if constexpr (BShouldWidenVec<L,T,Q>()) {
				vec<4,T,Q> widened(*this);
				
				widened.data |= vec<4,T,Q>(scalar).data;
				return (*this = vec<3,T,Q>(widened));
			} else if constexpr (L != 3) {
				this->data |= scalar;
				return *this;
			} else
				return (*this = detail::compute_vec_or<L, T, Q, detail::is_int<T>::value, sizeof(T) * 8, detail::is_aligned<Q>::value>::call(*this, vec<L, T, Q>(scalar)));
		}

		template<typename Tx>
		inline GLM_CONSTEXPR vec<L, T, Q> & __attribute__((always_inline)) operator|=(vec<1, Tx, Q>  v) requires (NotVec1<L>)
		{
			if constexpr (BShouldWidenVec<L,T,Q>()) {
				vec<4,T,Q> widened(*this);
				
				widened.data |= vec<4,T,Q>(v.x).data;
				return (*this = vec<3,T,Q>(widened));
			} else if constexpr (L != 3) {
				this->data |= v.x;
				return *this;
			} else
				return (*this = detail::compute_vec_or<L, T, Q, detail::is_int<T>::value, sizeof(T) * 8, detail::is_aligned<Q>::value>::call(*this, vec<L, T, Q>(v.x)));
		}

		template<typename Tx>
		inline GLM_CONSTEXPR vec<L, T, Q> & __attribute__((always_inline)) operator|=(vec<L, Tx, Q>  v)
		{
			if constexpr (BShouldWidenVec<L,T,Q>()) {
				vec<4,T,Q> widened(*this);
				
				widened.data |= vec<4,T,Q>(v).data;
				return (*this = vec<3,T,Q>(widened));
			} else if constexpr (L != 3) {
				this->data |= v.data;
				return *this;
			} else
				return (*this = detail::compute_vec_or<L, T, Q, detail::is_int<T>::value, sizeof(T) * 8, detail::is_aligned<Q>::value>::call(*this, vec<L, T, Q>(v)));
		}

		inline GLM_CONSTEXPR vec<L, T, Q> & __attribute__((always_inline)) operator^=(arithmetic auto scalar)
		{
			if constexpr (BShouldWidenVec<L,T,Q>()) {
				vec<4,T,Q> widened(*this);
				
				widened.data ^= vec<4,T,Q>(scalar).data;
				return (*this = vec<3,T,Q>(widened));
			} else if constexpr (L != 3) {
				this->data ^= scalar;
				return *this;
			} else
				return (*this = detail::compute_vec_xor<L, T, Q, detail::is_int<T>::value, sizeof(T) * 8, detail::is_aligned<Q>::value>::call(*this, vec<L, T, Q>(scalar)));
		}

		template<typename Tx>
		inline GLM_CONSTEXPR vec<L, T, Q> & __attribute__((always_inline)) operator^=(vec<1, Tx, Q>  v) requires (NotVec1<L>)
		{
			if constexpr (BShouldWidenVec<L,T,Q>()) {
				vec<4,T,Q> widened(*this);
				
				widened.data ^= vec<4,T,Q>(v.x).data;
				return (*this = vec<3,T,Q>(widened));
			} else if constexpr (L != 3) {
				this->data ^= v.x;
				return *this;
			} else
				return (*this = detail::compute_vec_xor<L, T, Q, detail::is_int<T>::value, sizeof(T) * 8, detail::is_aligned<Q>::value>::call(*this, vec<L, T, Q>(v.x)));
		}

		template<typename Tx>
		inline GLM_CONSTEXPR vec<L, T, Q> & __attribute__((always_inline)) operator^=(vec<L, Tx, Q>  v)
		{
			return (*this = detail::compute_vec_xor<L, T, Q, detail::is_int<T>::value, sizeof(T) * 8, detail::is_aligned<Q>::value>::call(*this, vec<L, T, Q>(v)));
		}

		inline GLM_CONSTEXPR vec<L, T, Q> & __attribute__((always_inline)) operator<<=(arithmetic auto scalar)
		{
			if constexpr (BShouldWidenVec<L,T,Q>()) {
				vec<4,T,Q> widened(*this);
				
				widened.data <<= vec<4,T,Q>(scalar).data;
				return (*this = vec<3,T,Q>(widened));
			} else if constexpr (L != 3) {
				this->data <<= scalar;
				return *this;
			} else
				return (*this = detail::compute_vec_shift_left<L, T, Q, detail::is_int<T>::value, sizeof(T) * 8, detail::is_aligned<Q>::value>::call(*this, vec<L, T, Q>(scalar)));
		}

		template<typename Tx>
		inline GLM_CONSTEXPR vec<L, T, Q> & __attribute__((always_inline)) operator<<=(vec<1, Tx, Q>  v) requires (NotVec1<L>)
		{
			if constexpr (BShouldWidenVec<L,T,Q>()) {
				vec<4,T,Q> widened(*this);
				
				widened.data <<= vec<4,T,Q>(v.x).data;
				return (*this = vec<3,T,Q>(widened));
			} else if constexpr (L != 3) {
				this->data <<= v.x;
				return *this;
			} else
				return (*this = detail::compute_vec_shift_left<L, T, Q, detail::is_int<T>::value, sizeof(T) * 8, detail::is_aligned<Q>::value>::call(*this, vec<L, T, Q>(v.x)));
		}

		template<typename Tx>
		inline GLM_CONSTEXPR vec<L, T, Q> & __attribute__((always_inline)) operator<<=(vec<L, Tx, Q>  v)
		{
			if constexpr (BShouldWidenVec<L,T,Q>()) {
				vec<4,T,Q> widened(*this);
				
				widened.data <<= vec<4,T,Q>(v).data;
				return (*this = vec<3,T,Q>(widened));
			} else if constexpr (L != 3) {
				this->data <<= v.data;
				return *this;
			} else
				return (*this = detail::compute_vec_shift_left<L, T, Q, detail::is_int<T>::value, sizeof(T) * 8, detail::is_aligned<Q>::value>::call(*this, vec<L, T, Q>(v)));
		}

		inline GLM_CONSTEXPR vec<L, T, Q> & __attribute__((always_inline)) operator>>=(arithmetic auto scalar)
		{
			if constexpr (BShouldWidenVec<L,T,Q>()) {
				vec<4,T,Q> widened(*this);
				
				widened.data >>= vec<4,T,Q>(scalar).data;
				return (*this = vec<3,T,Q>(widened));
			} else if constexpr (L != 3) {
				this->data >>= scalar;
				return *this;
			} else
				return (*this = detail::compute_vec_shift_right<L, T, Q, detail::is_int<T>::value, sizeof(T) * 8, detail::is_aligned<Q>::value>::call(*this, vec<L, T, Q>(scalar)));
		}

		template<typename Tx>
		inline GLM_CONSTEXPR vec<L, T, Q> & __attribute__((always_inline)) operator>>=(vec<1, Tx, Q>  v) requires (NotVec1<L>)
		{
			if constexpr (BShouldWidenVec<L,T,Q>()) {
				vec<4,T,Q> widened(*this);
				
				widened.data >>= vec<4,T,Q>(v.x).data;
				return (*this = vec<3,T,Q>(widened));
			} else if constexpr (L != 3) {
				this->data >>= v.x;
				return *this;
			} else
				return (*this = detail::compute_vec_shift_right<L, T, Q, detail::is_int<T>::value, sizeof(T) * 8, detail::is_aligned<Q>::value>::call(*this, vec<L, T, Q>(v.x)));
		}

		template<typename Tx>
		inline GLM_CONSTEXPR vec<L, T, Q> & __attribute__((always_inline)) operator>>=(vec<L, Tx, Q>  v)
		{
			if constexpr (BShouldWidenVec<L,T,Q>()) {
				vec<4,T,Q> widened(*this);
				
				widened.data >>= vec<4,T,Q>(v).data;
				return (*this = vec<3,T,Q>(widened));
			} else if constexpr (L != 3) {
				this->data >>= v.data;
				return *this;
			} else
				return (*this = detail::compute_vec_shift_right<L, T, Q, detail::is_int<T>::value, sizeof(T) * 8, detail::is_aligned<Q>::value>::call(*this, vec<L, T, Q>(v)));
		}

		// -- Unary constant operators --

		inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator+()
		{
			return *this;
		}

		inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator-()
		{
			return vec<L, T, Q>(0) -= *this;
		}

		// -- Binary arithmetic operators --

		inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator+(T scalar)
		{
			return vec<L, T, Q>(*this) += scalar;
		}

		template <length_t Lx>
		inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator+(vec<Lx, T, Q> v2) requires (!NotVec1<Lx> && NotVec1<L>)
		{
			return vec<L, T, Q>(*this) += v2;
		}

		friend inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator+(T scalar, vec<L, T, Q> v)
		{
			return vec<L, T, Q>(v) += scalar;
		}

		friend inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator+(vec<1, T, Q> v1, vec<L, T, Q>  v2)
		{
			return vec<L, T, Q>(v2) += v1;
		}

		inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator+(vec<L, T, Q> v2)
		{
			return vec<L, T, Q>(*this) += v2;
		}

		inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator-(T scalar)
		{
			return vec<L, T, Q>(*this) -= scalar;
		}

		template <length_t Lx>
		inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator-(vec<Lx, T, Q> v2) requires (!NotVec1<Lx> && NotVec1<L>)
		{
			return vec<L, T, Q>(*this) -= v2;
		}

		friend inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator-(T scalar, vec<L, T, Q> v)
		{
			return vec<L, T, Q>(scalar) -= v;
		}

		friend inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator-(vec<1, T, Q> v1, vec<L, T, Q> v2) requires (NotVec1<L>)
		{
			return vec<L, T, Q>(v1.x) -= v2;
		}

		friend inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator-(vec<L, T, Q> v1, vec<L, T, Q> v2)
		{
			return vec<L, T, Q>(v1) -= v2;
		}

		inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator*(T scalar)
		{
			return vec<L, T, Q>(*this) *= scalar;
		}

		template <length_t Lx>
		inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator*(vec<Lx, T, Q> v2) requires (!NotVec1<Lx> && NotVec1<L>)
		{
			return vec<L, T, Q>(*this) *= v2;
		}

		
		friend inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator*(T scalar, vec<L, T, Q> v)
		{
			return vec<L, T, Q>(v) *= scalar;
		}

		
		friend inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator*(vec<1, T, Q> v1, vec<L, T, Q> v2) requires (NotVec1<L>)
		{
			return vec<L, T, Q>(v2) *= v1;
		}

		
		friend inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator*(vec<L, T, Q> v1, vec<L, T, Q> const& __restrict__ v2)
		{
			return vec<L, T, Q>(v2) *= v1;
		}

		
		inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator/(T scalar)
		{
			return vec<L, T, Q>(*this) /= scalar;
		}


		template <length_t Lx>
		inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator/(vec<Lx, T, Q>  v2) requires (!NotVec1<Lx> && NotVec1<L>)
		{
			return vec<L, T, Q>(*this) /= v2;
		}

		
		friend inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator/(T scalar, vec<L, T, Q>  v)
		{
			return vec<L, T, Q>(scalar) /= v;
		}

		template <length_t Lx>
		friend inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator/(vec<Lx, T, Q>  v1, vec<L, T, Q> && __restrict__ v2) requires (!NotVec1<Lx> && NotVec1<L>)
		{
				return vec<L, T, Q>(v1.x) /= v2;
		}

		
		friend inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator/(vec<L, T, Q>  v1, vec<L, T, Q>  v2)
		{
			return vec<L, T, Q>(v1) /= v2;
		}

		// -- Binary bit operators --

		
		friend inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator%(vec<L, T, Q>  v, T scalar)
		{
			return vec<L, T, Q>(v) %= scalar;
		}

		template <length_t Lx>
		inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator%(vec<Lx, T, Q>  v2) requires (!NotVec1<Lx> && NotVec1<L>)
		{
			return vec<L, T, Q>(*this) %= v2.x;
		}

		
		friend inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator%(T scalar, vec<L, T, Q>  v)
		{
			return vec<L, T, Q>(scalar) %= v;
		}

		
		friend inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator%(vec<1, T, Q>  scalar, vec<L, T, Q>  v) requires (NotVec1<L>)
		{
			return vec<L, T, Q>(scalar.x) %= v;
		}

		
		friend inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator%(vec<L, T, Q>  v1, vec<L, T, Q>  v2)
		{
			return vec<L, T, Q>(v1) %= v2;
		}

		
		friend inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator&(vec<L, T, Q>  v, T scalar)
		{
			return vec<L, T, Q>(v) &= scalar;
		}

		
		inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator&(vec<1, T, Q>  scalar) requires (NotVec1<L>)
		{
			return vec<L, T, Q>(*this) &= scalar;
		}

		
		friend inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator&(T scalar, vec<L, T, Q>  v)
		{
			return vec<L, T, Q>(scalar) &= v;
		}

		
		friend inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator&(vec<1, T, Q>  v1, vec<L, T, Q>  v2) requires (NotVec1<L>)
		{
			return vec<L, T, Q>(v1.x) &= v2;
		}

		
		friend inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator&(vec<L, T, Q>  v1, vec<L, T, Q>  v2)
		{
			return vec<L, T, Q>(v1) &= v2;
		}

		
		friend inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator|(vec<L, T, Q>  v, T scalar)
		{
			return vec<L, T, Q>(v) |= scalar;
		}

		template <length_t Lx>
		inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator|(vec<Lx, T, Q>  v2) requires (!NotVec1<Lx> && NotVec1<L>)
		{
			return vec<L, T, Q>(*this) |= v2.x;
		}

		
		friend inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator|(T scalar, vec<L, T, Q>  v)
		{
			return vec<L, T, Q>(scalar) |= v;
		}

		
		friend inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator|(vec<1, T, Q>  v1, vec<L, T, Q>  v2) requires (NotVec1<L>)
		{
			return vec<L, T, Q>(v1.x) |= v2;
		}

		
		friend inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator|(vec<L, T, Q>  v1, vec<L, T, Q>  v2)
		{
			return vec<L, T, Q>(v1) |= v2;
		}

		
		friend inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator^(vec<L, T, Q>  v, T scalar)
		{
			return vec<L, T, Q>(v) ^= scalar;
		}

		template <length_t Lx>
		inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator^(vec<Lx, T, Q>  v2) requires (!NotVec1<Lx> && NotVec1<L>)
		{
			return vec<L, T, Q>(*this) ^= v2.x;
		}

		
		friend inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator^(T scalar, vec<L, T, Q>  v)
		{
			return vec<L, T, Q>(scalar) ^= v;
		}

		
		friend inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator^(vec<1, T, Q>  v1, vec<L, T, Q>  v2) requires (NotVec1<L>)
		{
			return vec<L, T, Q>(v1.x) ^= v2;
		}

		
		friend inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator^(vec<L, T, Q>  v1, vec<L, T, Q>  v2)
		{
			return vec<L, T, Q>(v1) ^= v2;
		}

		
		friend inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator<<(vec<L, T, Q>  v, T scalar)
		{
			return vec<L, T, Q>(v) <<= scalar;
		}

		template <length_t Lx>
		inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator<<(vec<Lx, T, Q>  v2) requires (!NotVec1<Lx> && NotVec1<L>)
		{
			return vec<L, T, Q>(*this) <<= v2.x;
		}

		
		friend inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator<<(T scalar, vec<L, T, Q>  v)
		{
			return vec<L, T, Q>(scalar) <<= v;
		}

		
		friend inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator<<(vec<1, T, Q>  v1, vec<L, T, Q>  v2) requires (NotVec1<L>)
		{
			return vec<L, T, Q>(v1.x) <<= v2;
		}

		
		friend inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator<<(vec<L, T, Q>  v1, vec<L, T, Q>  v2)
		{
			return vec<L, T, Q>(v1) <<= v2;
		}

		
		friend inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator>>(vec<L, T, Q>  v, T scalar)
		{
			return vec<L, T, Q>(v) >>= scalar;
		}

		template <length_t Lx>
		inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator>>(vec<Lx, T, Q>  v2) requires (!NotVec1<Lx> && NotVec1<L>)
		{
			return vec<L, T, Q>(*this) >>= v2.x;
		}

		
		friend inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator>>(T scalar, vec<L, T, Q>  v)
		{
			return vec<L, T, Q>(scalar) >>= v;
		}

		
		friend inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator>>(vec<1, T, Q>  v1, vec<L, T, Q>  v2) requires (NotVec1<L>)
		{
			return vec<L, T, Q>(v1.x) >>= v2;
		}

		
		friend inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator>>(vec<L, T, Q>  v1, vec<L, T, Q>  v2)
		{
			return vec<L, T, Q>(v1) >>= v2;
		}

		
		friend inline GLM_CONSTEXPR vec<L, T, Q> __attribute__((always_inline)) operator~(vec<L, T, Q>  v)
		{
			return detail::compute_vec_bitwise_not<L, T, Q, detail::is_int<T>::value, sizeof(T) * 8, detail::is_aligned<Q>::value>::call(v);
		}

		// -- Boolean operators --
		
		friend inline GLM_CONSTEXPR bool __attribute__((always_inline)) operator==(vec<L, T, Q>  v1, vec<L, T, Q>  v2)
		{
			return detail::compute_vec_equal<L, T, Q, detail::is_int<T>::value, sizeof(T) * 8, detail::is_aligned<Q>::value>::call(v1, v2);
		}

		
		friend inline GLM_CONSTEXPR bool __attribute__((always_inline)) operator!=(vec<L, T, Q>  v1, vec<L, T, Q>  v2)
		{
			return detail::compute_vec_nequal<L, T, Q, detail::is_int<T>::value, sizeof(T) * 8, detail::is_aligned<Q>::value>::call(v1, v2);
		}
	};
	
	template <length_t Lx, typename Tx, qualifier Qx> requires (std::is_same_v<Tx, bool>)
	inline vec<Lx, bool, Qx> __attribute__((always_inline)) operator&&(vec<Lx, Tx, Qx>  v1, vec<Lx, Tx, Qx>  v2)
	{
		using GVec_t = typename detail::GccVExt<Lx, Tx, Qx>::GccV;
		using VT = typename vec<Lx, Tx, Qx>::type;
		GVec_t gv1, gv2;
		std::memcpy(&v1, &gv1, std::min(sizeof(v1), sizeof(gv1)));
		std::memcpy(&v2, &gv2, std::min(sizeof(v2), sizeof(gv2)));
		v1.VT::~VT();
		v2.VT::~VT();
		return vec<Lx, bool, Qx>(gv1 && gv2);
	}
	template <length_t Lx, typename Tx, qualifier Qx> requires (std::is_same_v<Tx, bool>)
	inline vec<Lx, bool, Qx> __attribute__((always_inline)) operator||(vec<Lx, bool, Qx>  v1, vec<Lx, bool, Qx>  v2)
	{
		using GVec_t = typename detail::GccVExt<Lx, Tx, Qx>::GccV;
		using VT = typename vec<Lx, Tx, Qx>::type;
		GVec_t gv1, gv2;
		std::memcpy(&v1, &gv1, std::min(sizeof(v1), sizeof(gv1)));
		std::memcpy(&v2, &gv2, std::min(sizeof(v2), sizeof(gv2)));
		v1.VT::~VT();
		v2.VT::~VT();
		return vec<Lx, bool, Qx>(gv1 || gv2);
	}
}
static_assert( glm::detail::is_aligned<(glm::qualifier)0>::value == false);
static_assert(sizeof(glm::vec<3, float, (glm::qualifier)0>) == 12);