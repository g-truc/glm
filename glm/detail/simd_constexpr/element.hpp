#include <iostream>
#include <type_traits>
namespace glm::detail
{
	consteval bool NotEmpty(length_t I, length_t L) { return I <= L; }
	struct Empty {};
	struct  GLM_TRIVIAL RowTwo {
		[[no_unique_address]] Empty y; [[no_unique_address]] Empty g; [[no_unique_address]] Empty t;
	};
	struct GLM_TRIVIAL RowThree {
		[[no_unique_address]] Empty z; [[no_unique_address]] Empty b; [[no_unique_address]] Empty p;
	};
	struct GLM_TRIVIAL RowFour {
		[[no_unique_address]] Empty w; [[no_unique_address]] Empty a; [[no_unique_address]] Empty q;
	};
	template <length_t L, typename T, qualifier Q>
	struct ElementCollection;
	
#ifdef __clang
	template<typename T> struct declval_helper { static T value; };

template<typename T, typename Z, Z T::*MPtr>
struct offset_helper {
    using TV = declval_helper<T>;
    char for_sizeof[
        (char *)&(TV::value.*MPtr) -
        (char *)&TV::value
    ];
};


template<typename T, typename Z>
constexpr int memberOffset(Z T::*MPtr, auto MPtrGetter) {
    return sizeof(glm::detail::offset_helper<T, Z, MPtrGetter()>::for_sizeof);
}
			template <length_t L, typename T, qualifier Q>
			static constexpr auto k_X = &ElementCollection<L, T, Q>::X;
	template <qualifier Q, typename T>
	struct  GLM_TRIVIAL ElementCollection<4, T, Q> {
		using data_t = typename detail::storage<4, T, detail::is_aligned<Q>::value>::type;
		static constexpr T X = -1ll;
		union
		{
				VDataArray<4, T, Q> elementArr;
				struct {
					union { T x, r, s; }; 
					union { T y, g, t; };
					union { T z, b, p; };
					union { T w, a, q; };
				};
				data_t data;
		};
		

			template <auto member, auto* baseObj>
			static consteval int64_t getOffset()  {
		//if constexpr (requires { constexpr vec<L,T,Q> v{0}; v.*member; }) {

//#    ifdef __clang__
			
			using E = ElementCollection<4, T, Q>;

			if constexpr (member == &baseObj->X) {
				return -1ll;
			}
			else if constexpr (member == &baseObj->x || member == &baseObj->r || member == &baseObj->s) {
				return (int64_t)(offsetof(E, x)/sizeof(T));
			} else if constexpr (member == &baseObj->y || member == &baseObj->g || member == &baseObj->t) {
				return (int64_t)(offsetof(E, y)/sizeof(T));
			} else if constexpr (member == &baseObj->z || member == &baseObj->b || member == &baseObj->p) {
				return (int64_t)(offsetof(E, z)/sizeof(T));
			} else if constexpr (member == &baseObj->w || member == &baseObj->a || member == &baseObj->q) {
				return (int64_t)(offsetof(E, w)/sizeof(T));
			} else {
				static_assert(false);
			}
	}
					GLM_SWIZZLE_GEN_VEC_FROM_VEC4(T, Q)
	};
	

	template <qualifier Q, typename T>
	struct GLM_TRIVIAL ElementCollection<3, T, Q> : RowFour {
		using data_t = typename detail::storage<3, T, detail::is_aligned<Q>::value>::type;
		using RowFour::w;
		using RowFour::a;
		using RowFour::q;
		static constexpr length_t data_len = (Q == aligned) ? 4 : 3;
		static constexpr int64_t X = -1ll;
		union
		{
				VDataArray<data_len, T, Q> elementArr;
				struct {
					union { T x, r, s; }; 
					union { T y, g, t; };
					union { T z, b, p; };
				};
				data_t data;
		};
			template <auto member, auto* baseObj>
			consteval int64_t getOffset() {
		//if constexpr (requires { constexpr vec<L,T,Q> v{0}; v.*member; }) {

//#    ifdef __clang__
			auto callable = []() { return member; };
			using E = ElementCollection<3, T, Q>;

			if constexpr (member == &baseObj->X) {
				return -1ll;
			}
			else if constexpr (member == &baseObj->x || member == &baseObj->r || member == &baseObj->s) {
				return (int64_t)(offsetof(E, x)/sizeof(T));
			} else if constexpr (member == &baseObj->y || member == &baseObj->g || member == &baseObj->t) {
				return (int64_t)(offsetof(E, y)/sizeof(T));
			} else if constexpr (member == &baseObj->z || member == &baseObj->b || member == &baseObj->p) {
				return (int64_t)(offsetof(E, z)/sizeof(T));
			} else if constexpr (member == &baseObj->w || member == &baseObj->a || member == &baseObj->q) {
				return (int64_t)(offsetof(E, w)/sizeof(T));
			} else {
				static_assert(false);
			}
	}
					GLM_SWIZZLE_GEN_VEC_FROM_VEC3(T, Q)
	};
	template <qualifier Q, typename T>
	struct GLM_TRIVIAL ElementCollection<2, T, Q> : RowThree, RowFour {
		using data_t = typename detail::storage<2, T, detail::is_aligned<Q>::value>::type;
		using RowThree::z;
		using RowThree::b;
		using RowThree::p;
		using RowFour::w;
		using RowFour::a;
		using RowFour::q;
		static constexpr int64_t X = -1ll;
		union
		{
				VDataArray<2, T, Q> elementArr;
				struct {
					union { T x, r, s; }; 
					union { T y, g, t; };
				};
				data_t data;
		};
		template <auto member, auto* baseObj>
			static consteval int64_t getOffset() {
		//if constexpr (requires { constexpr vec<L,T,Q> v{0}; v.*member; }) {

//#    ifdef __clang__
			auto callable = []() { return member; };
			using E = ElementCollection<2, T, Q>;

			if constexpr (member == &baseObj->X) {
				return -1ll;
			}
			else if constexpr (member == &baseObj->x || member == &baseObj->r || member == &baseObj->s) {
				return (int64_t)(offsetof(E, x)/sizeof(T));
			} else if constexpr (member == &baseObj->y || member == &baseObj->g || member == &baseObj->t) {
				return (int64_t)(offsetof(E, y)/sizeof(T));
			} else if constexpr (member == &baseObj->z || member == &baseObj->b || member == &baseObj->p) {
				return (int64_t)(offsetof(E, z)/sizeof(T));
			} else if constexpr (member == &baseObj->w || member == &baseObj->a || member == &baseObj->q) {
				return (int64_t)(offsetof(E, w)/sizeof(T));
			} else {
				static_assert(false);
			}
	}
				GLM_SWIZZLE_GEN_VEC_FROM_VEC2(T, Q)
	};
	template <qualifier Q, typename T>
	struct GLM_TRIVIAL ElementCollection<1, T, Q> : RowTwo, RowThree, RowFour {
		using data_t = typename detail::storage<1, T, detail::is_aligned<Q>::value>::type;
		using RowTwo::y;
		using RowTwo::g;
		using RowTwo::t;
		using RowThree::z;
		using RowThree::b;
		using RowThree::p;
		using RowFour::w;
		using RowFour::a;
		using RowFour::q;
		static constexpr int64_t X = -1ll;
		union
		{
				VDataArray<1, T, Q> elementArr;
				struct {
					union { T x, r, s; }; 
				};
				data_t data;
		};
		#undef G
	};

#else
	template <length_t L, typename T, qualifier Q>
	struct ElementCollection;
	template <qualifier Q, typename T>
	struct  GLM_TRIVIAL ElementCollection<4, T, Q> {
		using data_t = typename detail::storage<4, T, detail::is_aligned<Q>::value>::type;
		union
		{
				VDataArray<4, T, Q> elementArr;
				struct {
					union { T x, r, s; }; 
					union { T y, g, t; };
					union { T z, b, p; };
					union { T w, a, q; };
				};
				data_t data;
		};
					GLM_SWIZZLE_GEN_VEC_FROM_VEC4(T, Q)
	};
	

	template <qualifier Q, typename T>
	struct GLM_TRIVIAL ElementCollection<3, T, Q> : RowFour {
		using data_t = typename detail::storage<3, T, detail::is_aligned<Q>::value>::type;
		using RowFour::w;
		using RowFour::a;
		using RowFour::q;
		static constexpr length_t data_len = (Q == aligned) ? 4 : 3;
		union
		{
				VDataArray<data_len, T, Q> elementArr;
				struct {
					union { T x, r, s; }; 
					union { T y, g, t; };
					union { T z, b, p; };
				};
				data_t data;
		};
					GLM_SWIZZLE_GEN_VEC_FROM_VEC3(T, Q)
	};
	template <qualifier Q, typename T>
	struct GLM_TRIVIAL ElementCollection<2, T, Q> : RowThree, RowFour {
		using data_t = typename detail::storage<2, T, detail::is_aligned<Q>::value>::type;
		using RowThree::z;
		using RowThree::b;
		using RowThree::p;
		using RowFour::w;
		using RowFour::a;
		using RowFour::q;
		union
		{
				VDataArray<2, T, Q> elementArr;
				struct {
					union { T x, r, s; }; 
					union { T y, g, t; };
				};
				data_t data;
		};				
				GLM_SWIZZLE_GEN_VEC_FROM_VEC2(T, Q)
	};
	template <qualifier Q, typename T>
	struct GLM_TRIVIAL ElementCollection<1, T, Q> : RowTwo, RowThree, RowFour {
		using data_t = typename detail::storage<1, T, detail::is_aligned<Q>::value>::type;
		using RowTwo::y;
		using RowTwo::g;
		using RowTwo::t;
		using RowThree::z;
		using RowThree::b;
		using RowThree::p;
		using RowFour::w;
		using RowFour::a;
		using RowFour::q;
		union
		{
				VDataArray<1, T, Q> elementArr;
				struct {
					union { T x, r, s; }; 
				};
				data_t data;
		};
		#undef G
	};
	#endif
}

