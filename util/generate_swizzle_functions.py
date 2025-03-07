import itertools

def make_swizzlers(letters, vector_length):
    
    permutations = itertools.product(letters, repeat=vector_length)
    
    template = """
template<length_t L, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR glm::vec<{vector_length}, T, Q> {function_name}(glm::vec<L, T, Q> const& v) {{
    return glm::vec<{vector_length}, T, Q>({swizzle});
}}
"""
    for perm in permutations:
        print(template.format(
            vector_length=vector_length,
            function_name=''.join(perm),
            swizzle=', '.join([f'v.{i}' for i in perm])
        ))
        
        
if __name__ == "__main__":
    for i in range(2,5):
        make_swizzlers(['x', 'y', 'z', 'w'], i)
