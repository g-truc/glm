import itertools

def make_swizzlers(letters, vector_length):
    if vector_length == 4:
        template = "template<typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<{vector_length},T,Q> {function_name}(vec<4,T,Q> const& v) {{ return vec<4,T,Q>({swizzle}); }}"
    else:
        template = "template<length_t L, typename T, qualifier Q> GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<{vector_length},T,Q> {function_name}(vec<L,T,Q> const& v) {{ return vec<{vector_length},T,Q>({swizzle}); }}"
    for perm in itertools.product(letters, repeat=vector_length):
        print(template.format(
            vector_length=vector_length,
            function_name=''.join(perm),
            swizzle=', '.join([f'v.{i}' for i in perm])
        ))
        
        
if __name__ == "__main__":
    for i in range(2,5):
        make_swizzlers(['x', 'y', 'z', 'w'], i)
