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
				if constexpr (L != 3 && (L < 3 || detail::is_aligned<Q>::value)) {
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
			gcc_vec_t v = gcc_vec_t{} + ( (T)scalar );
			using Tx = decltype(scalar);
			scalar.Tx::~Tx();
			return gcc_vec_to_data(v);
		}
		
		template <length_t Lx, typename Tx, qualifier Qx> requires (Lx == L)
		static inline auto __attribute__((always_inline)) simd_ctor(::glm::vec<Lx, Tx, Qx> v)
		{
			using OtherVec = GccVec<Lx, Tx, Qx>;
			if constexpr (!std::is_same_v<::glm::vec<Lx, Tx, Qx>, ::glm::vec<L,T,Q>>) {
				if constexpr (	((Lx == 3 || L == 3) && (!BIsAlignedQ<Q>() || !BIsAlignedQ<Qx>())) || sizeof(v.data) != sizeof(OtherVec)  ) { 
					OtherVec o;
					static constexpr auto size = std::min(sizeof(v.data), sizeof(o));
					std::memcpy(&o, &(v.data), size);
					using o_vec_t = decltype(v);
					v.o_vec_t::~o_vec_t();
					gcc_vec_t converted = __builtin_convertvector(o, gcc_vec_t);
					return gcc_vec_to_data(converted);
				} else if constexpr ( L == Lx && sizeof(v) == sizeof(data_t) ) {
					OtherVec o = reinterpret_cast<OtherVec>(v.data);
					gcc_vec_t converted = __builtin_convertvector(o, gcc_vec_t);
					return gcc_vec_to_data(converted);
				} else {
					OtherVec o = std::bit_cast<OtherVec>(v.data);
					gcc_vec_t converted = __builtin_convertvector(o, gcc_vec_t);
					return gcc_vec_to_data(converted);
				}
			} else {
				return v.data;
			}
		}
		
		template <length_t Lx, typename Tx, qualifier Qx> requires (Lx != L)
		static inline auto __attribute__((always_inline)) simd_ctor(::glm::vec<Lx, Tx, Qx> v)
		{
			using OurSizeTheirType = GccVec<L, Tx, Qx>;
			static constexpr auto size = std::min(sizeof(OurSizeTheirType), sizeof(v.data));
			OurSizeTheirType oExpanded;
			std::memcpy(&oExpanded, &(v.data), size);
			using o_vec_t = decltype(v);
			v.o_vec_t::~o_vec_t();
			
			gcc_vec_t converted = __builtin_convertvector(oExpanded, gcc_vec_t);
			return gcc_vec_to_data(converted);
		}

		template<arithmetic... A>
		static consteval bool isLengthOfVector() {
			return sizeof...(A) == L;
		}
		
		template <arithmetic... A>
		static inline auto __attribute__((always_inline)) simd_ctor_multi_scalars(A... scalars) requires ( isLengthOfVector<A...>() && SameArithmeticTypes<A...>())
		{
			//assuming that number of scalars is always the same as the length of the to-be-constructed vector
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