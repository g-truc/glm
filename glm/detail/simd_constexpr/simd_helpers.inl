namespace glm::detail
{
	template<length_t L, typename T, qualifier Q>
	struct SimdHelpers
	{
		template <typename Tx0, typename... Tx>
		struct GetFirstType
		{
			using FirstTx = Tx0;
		};
		template <length_t Lx, typename Tx, qualifier Qx>
		using GccVec = typename detail::GccVExt<Lx, Tx, Qx>::GccV;
		using gcc_vec_t = GccVec<L, T, Q>;
		using data_t = typename detail::storage<L, T, detail::is_aligned<Q>::value>::type;
		
		static inline auto __attribute__((always_inline)) gcc_vec_to_data(auto v) {
			static constexpr auto size = std::min(sizeof(v), sizeof(data_t));
			static constexpr auto biggerSize = std::max(sizeof(v), sizeof(data_t));
			if constexpr (size == biggerSize) {
				if constexpr (L != 3 || (detail::is_aligned<Q>::value)) {
					return reinterpret_cast<data_t>(v);
				} else {
					data_t d;
					std::memcpy(&d, &v, size);
					return d;
				}
			} else {
				data_t d;
				std::memcpy(&d, &v, size);
				return d;
			}
		}
		
		static inline auto __attribute__((always_inline)) simd_ctor_scalar(arithmetic auto scalar) {
			gcc_vec_t v = ( (T)scalar ) - gcc_vec_t{};
			using Tx = decltype(scalar);
			scalar.Tx::~Tx();
			return gcc_vec_to_data(v);
		}
		template <typename Tx, qualifier Qx>
		static inline auto __attribute__((always_inline)) fetch_vec3_as_vec4(::glm::vec<3, Tx, Qx> const& v) {
			using OtherVec = GccVec<3, Tx, Qx>;
#ifdef __clang__
			//On clang, simply doing memcpy results in better overall codegen
			//Also, this allows clang to avoid spilling registers to the stack, when this function is run on local lvalues
			//The local lvalues thing only matters for clang, because gcc seems to always emit memory load/stores when going from packed vec3 -> vec4/aligned_vec3 :(  
			OtherVec o{};
			std::memcpy(&o, &v, sizeof(v));
			return o;
#else
			typedef Tx v2_packed __attribute__((aligned(alignof(Tx)),vector_size(2*sizeof(Tx)))); 
			struct __attribute__((packed,aligned(alignof(Tx)))) padded {
        Tx data0;
        v2_packed v2;
    	};
    	auto const& reinterpreted = reinterpret_cast<padded const&>(v);
    	OtherVec initialPart{};
    	initialPart[0] = v[0];
    	OtherVec fetched = __builtin_shufflevector(reinterpreted.v2, reinterpreted.v2, -1, -1, 0, 1);
    	initialPart = __builtin_shufflevector(initialPart, fetched, 0, 5, 6, -1 );
    	return initialPart;
#endif
		}
		template <typename Tx, qualifier Qx>
		static inline auto __attribute__((always_inline)) fetch_vec3_as_vec4(::glm::vec<3, Tx, Qx>&& v) {
			union M {
		      gcc_vec_t ourType;
		      ::glm::vec<3, Tx, Qx> other;
		  };
		  M m {.ourType{}};
		  m.other = v;
		 	return m.ourType;
		}
		template <length_t Lx, typename Tx, qualifier Qx> requires (Lx == L)
		static inline auto __attribute__((always_inline)) simd_ctor_same_size_conversions(auto&& v) {
			using OtherVec = GccVec<Lx, Tx, Qx>;
			static_assert(sizeof(v) == sizeof(data_t));
			if constexpr (std::is_same_v<::glm::vec<Lx, Tx, Qx>, ::glm::vec<L,T,Q>>) {
				return v.data;
			} else if constexpr (L == 3 && !BIsAlignedQ<Q>()) {
				 if constexpr (std::is_same_v<T, Tx>) {
						return v.data;
				 } else {
				 		using Vec4 = GccVec<4, T, Qx>;
						gcc_vec_t converted = __builtin_convertvector(fetch_vec3_as_vec4(v), Vec4);
						return gcc_vec_to_data(converted);
				 }
			} else { 
				gcc_vec_t converted = __builtin_convertvector(v.data, gcc_vec_t);
			}
		}
		
		template <length_t Lx, typename Tx, qualifier Qx> requires (Lx == L)
		static inline auto __attribute__((always_inline)) simd_ctor(::glm::vec<Lx, Tx, Qx>&& v)
		{
			using OtherVec = GccVec<Lx, Tx, Qx>;
			if constexpr (sizeof(v) == sizeof(data_t)) {
				return simd_ctor_same_size_conversions<Lx, Tx, Qx>(v);
			} else if constexpr (BIsAlignedQ<Q>() && !BIsAlignedQ<Qx>() && Lx == 3) {
				auto o = fetch_vec3_as_vec4<Tx,Qx>(v);
				if constexpr (std::is_same_v<T, Tx>) {
					return gcc_vec_to_data(o);
				} else {
					gcc_vec_t converted = __builtin_convertvector(o, gcc_vec_t);
					return gcc_vec_to_data(converted);
				}
			} else {
				OtherVec o;
				static constexpr auto size = std::min(sizeof(v.data), sizeof(o));
				std::memcpy(&o, &(v.data), size);
				//using o_vec_t = decltype(v);
				//v.o_vec_t::~o_vec_t();
				gcc_vec_t converted = __builtin_convertvector(o, gcc_vec_t);
				return gcc_vec_to_data(converted);
			}
		}
		template <length_t Lx, typename Tx, qualifier Qx> requires (Lx == L)
		static inline auto __attribute__((always_inline)) simd_ctor(::glm::vec<Lx, Tx, Qx> const& v)
		{
			using OtherVec = GccVec<Lx, Tx, Qx>;
			if constexpr (sizeof(v) == sizeof(data_t)) {
				return simd_ctor_same_size_conversions<Lx, Tx, Qx>(v);
			} else if constexpr (BIsAlignedQ<Q>() && !BIsAlignedQ<Qx>() && Lx == 3) {
				auto o = fetch_vec3_as_vec4<Tx,Qx>(v);
				if constexpr (std::is_same_v<T, Tx>) {
					return gcc_vec_to_data(o);
				} else {
					gcc_vec_t converted = __builtin_convertvector(o, gcc_vec_t);
					return gcc_vec_to_data(converted);
				}
			} else {
				OtherVec o;
				static constexpr auto size = std::min(sizeof(v.data), sizeof(o));
				std::memcpy(&o, &(v.data), size);
				//using o_vec_t = decltype(v);
				//v.o_vec_t::~o_vec_t();
				gcc_vec_t converted = __builtin_convertvector(o, gcc_vec_t);
				return gcc_vec_to_data(converted);
			}
		}
		
		template <length_t Lx, typename Tx, qualifier Qx> requires (Lx != L)
		static inline auto __attribute__((always_inline)) simd_ctor(::glm::vec<Lx, Tx, Qx> v)
		{
			using OtherVec = GccVec<Lx, Tx, Qx>;
			if constexpr (	((Lx != 3 || L == 3) && (!BIsAlignedQ<Q>() || !BIsAlignedQ<Qx>()))
											&& L != 3 && L > 0 && L <= 4 ) { 
						static constexpr int64_t posOne = 0;
						static constexpr int64_t posTwo = Lx > 1 ? 1 : -1;
						static constexpr int64_t posThree = Lx > 2 ? 2 : -1;
						static constexpr int64_t posFour = Lx > 3 ? 3 : -1;
						if constexpr (L == 4) {
								OtherVec o = v.data;
								auto oExt = __builtin_shufflevector(o, o, posOne, posTwo, posThree, posFour);
								if constexpr (std::is_same_v<T, Tx>) {
									return gcc_vec_to_data(oExt);
								} else {
									return gcc_vec_to_data(__builtin_convertvector(oExt, gcc_vec_t));
								}
						} else if constexpr (L == 2) {
								OtherVec o = v.data;
								auto oExt = __builtin_shufflevector(o, o, posOne, posTwo);
								if constexpr (std::is_same_v<T, Tx>) {
									return gcc_vec_to_data(oExt);
								} else {
									return gcc_vec_to_data(__builtin_convertvector(oExt, gcc_vec_t));
								}
						} else if constexpr (L == 1) {
								OtherVec o = v.data;
								auto oExt = __builtin_shufflevector(o, o, posOne);
								if constexpr (std::is_same_v<T, Tx>) {
									return gcc_vec_to_data(oExt);
								} else {
									return gcc_vec_to_data(__builtin_convertvector(oExt, gcc_vec_t));
								}
						} else {
							static_assert(false, "unreachable");
						}
			} else {
				using OurSizeTheirType = GccVec<L, Tx, Qx>;
				static constexpr auto size = std::min(sizeof(OurSizeTheirType), sizeof(v.data));
				OurSizeTheirType oExpanded;
				std::memcpy(&oExpanded, &(v.data), size);
				using o_vec_t = decltype(v);
				v.o_vec_t::~o_vec_t();
	
				gcc_vec_t converted = __builtin_convertvector(oExpanded, gcc_vec_t);
				return gcc_vec_to_data(converted);
			}	
		}

		template<arithmetic... A>
		static consteval bool isLengthOfVector() {
			return sizeof...(A) == L;
		}
		
		template <arithmetic... A>
		static inline auto __attribute__((always_inline)) simd_ctor_multi_scalars(A... scalars) requires ( isLengthOfVector<A...>() && SameTypes<A...>())
		{
			using OtherType = GetFirstType<A...>::FirstTx;
			using other_vec_t = GccVec<L, OtherType, Q>;
			other_vec_t o {scalars...};
			if constexpr (std::is_same_v<T, OtherType>) {
					return gcc_vec_to_data(o);
			} else {
					return gcc_vec_to_data(__builtin_convertvector(o, gcc_vec_t));
			}
		}
		template <arithmetic... A>
		static inline auto __attribute__((always_inline)) simd_ctor_multi_scalars(A... scalars) requires ( isLengthOfVector<A...>() && std::is_floating_point_v<T> && AllIntegralTypes<A...>() && !SameTypes<A...>())
		{
			using OtherType = GetCommonType<A...>::Type;
			using other_vec_t = GccVec<L, OtherType, Q>;
			other_vec_t o {scalars...};
			
			if constexpr (std::is_same_v<T, OtherType>) {
					return gcc_vec_to_data(o);
			} else {
					return gcc_vec_to_data(__builtin_convertvector(o, gcc_vec_t));
			}
		}
		
		template <arithmetic... A>
		static inline auto __attribute__((always_inline)) simd_ctor_multi_scalars(A... scalars) requires ( isLengthOfVector<A...>() && std::is_integral_v<T> && AllFloatTypes<A...>() && !SameTypes<A...>())
		{
			using OtherType = GetCommonType<A...>::Type;
			using other_vec_t = GccVec<L, OtherType, Q>;
			other_vec_t o {scalars...};
			
			if constexpr (std::is_same_v<T, OtherType>) {
					return gcc_vec_to_data(o);
			} else {
					return gcc_vec_to_data(__builtin_convertvector(o, gcc_vec_t));
			}
		}
		
		template <arithmetic... A>
		static inline auto __attribute__((always_inline)) simd_ctor_multi_scalars(A... scalars) requires ( isLengthOfVector<A...>() && !SameTypes<A...>() && SameArithmeticTypes<A...>())
		{
			gcc_vec_t v;
			std::array<T, sizeof...(scalars)> pack{static_cast<T>(scalars)...};
			for (int i = 0; i != sizeof...(scalars); i++ ) {
				v[i] = pack[i];
				pack[i].T::~T();
			}
			return gcc_vec_to_data(v);
		}
		
		
	};
}