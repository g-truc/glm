import itertools
import sys

def write_to_file(text,filename,mode='a'):
    with open(filename,mode) as file:
        file.write(text)

def make_binary_funcs(filename,op_symbols):
    for op_symbol in op_symbols:
        write_to_file(f"""
template<length_t L, typename T, qualifier Q,typename U,qualifier P>
GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR vec<L, T, Q>& operator{op_symbol}=(vec<L, T, Q>& a, vec<1,U,P> const& b);
template<length_t L, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator{op_symbol}(vec<L, T, Q> const& a, vec<1,T,Q> const& b);
template<length_t L, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator{op_symbol}(vec<1, T, Q> const& a, vec<L,T,Q> const& b);
""",f"{filename}.hpp")
        write_to_file(f"""
template<length_t L, typename T, qualifier Q,typename U,qualifier P>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q>& operator{op_symbol}=(vec<L, T, Q>& a, vec<1,U,P> const& b) {{
    return a {op_symbol}= b.x;
}}
template<length_t L, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator{op_symbol}(vec<L, T, Q> const& a, vec<1,T,Q> const& b) {{
    return a {op_symbol} b.x;
}}
template<length_t L, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator{op_symbol}(vec<1, T, Q> const& a, vec<L,T,Q> const& b) {{
    return a.x {op_symbol} b;
}}
""",f"{filename}.inl")


def make_scalar_commutative_operators(filename,op_symbols):
    for op_symbol in op_symbols:
        write_to_file(f"""
template<length_t L, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator{op_symbol}(T scalar,vec<L, T, Q> const& v);
""",f"{filename}.hpp")
        write_to_file(f"""
template<length_t L, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator{op_symbol}(T scalar,vec<L, T, Q> const& v) {{
    return v {op_symbol} scalar;
}}""",f"{filename}.inl")




if __name__ == "__main__":
    filename = "vec_common_operators"    
    write_to_file("""#pragma once
#include "qualifier.hpp"
namespace glm {

template<length_t L,typename T,qualifier Q>
GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR vec<L,T,Q> operator++(vec<L,T,Q>& v,int);
template<length_t L,typename T,qualifier Q>
GLM_FUNC_DISCARD_DECL GLM_CONSTEXPR vec<L,T,Q> operator--(vec<L,T,Q>& v,int);
template<length_t L,typename T,qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR vec<L,T,Q> operator+(vec<L,T,Q> const& v);
template<length_t L,typename T,qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR bool operator!=(vec<L,T,Q> const& a,vec<L,T,Q> const& b);
""",f"{filename}.hpp",'w')

    write_to_file("""namespace glm {
template<length_t L,typename T,qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L,T,Q> operator++(vec<L,T,Q>& v,int) {{
    const vec<L,T,Q> Result(v);
    ++v;
    return Result;
}}
template<length_t L,typename T,qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L,T,Q> operator--(vec<L,T,Q>& v,int) {
    const vec<L,T,Q> Result(v);
    --v;
    return Result;
}
template<length_t L,typename T,qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L,T,Q> operator+(vec<L,T,Q> const& v) {
    return v;
}
template<length_t L,typename T,qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR bool operator!=(vec<L,T,Q> const& a,vec<L,T,Q> const& b) {
    return !(a == b);
}
""",f"{filename}.inl",'w')
    make_binary_funcs(filename,['+', '-', '*', '/', '%', '&', '|', '^', '<<', '>>'])
    make_scalar_commutative_operators(filename,['+', '*', '&', '|', '^'])

    write_to_file("""
} // namespace glm
""",f"{filename}.inl")

    write_to_file(f"""}} // namespace glm

#ifndef GLM_EXTERNAL_TEMPLATE
#include "{filename}.inl"
#endif
""",f"{filename}.hpp")