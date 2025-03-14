import itertools
import sys

def make_unary_minus(column_count,filename):
    mat_def = f"mat<{column_count},R,T,Q>"
    sys.stdout =  open(f"{filename}.hpp", 'a')
    print(f"""
template<length_t R, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR {mat_def} operator-({mat_def} const& m);
"""    ,end="")
    sys.stdout.close()

    sys.stdout =  open(f"{filename}.inl", 'a')
    print(f"""
template<length_t R, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR {mat_def} operator-({mat_def} const& m) {{
    return {mat_def}({",".join([f"-m[{i}]" for i in range(0,column_count)])});
}}
"""    ,end="")
    sys.stdout.close()






def make_prefix_incr_decr_funcs(column_count,filename):
    op_symbols = ["++","--"]
    sys.stdout =  open(f"{filename}.hpp", 'a')
    mat_def = f"mat<{column_count},R,T,Q>"
    for op_symbol in op_symbols:
        print(f"""
template<length_t R, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR {mat_def}& operator{op_symbol}({mat_def}& m);
"""    ,end="")
    sys.stdout.close()

    sys.stdout =  open(f"{filename}.inl", 'a')
    for op_symbol in op_symbols:
        print(f"""
template<length_t R, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR {mat_def}& operator{op_symbol}({mat_def}& m) {{
    {"    ".join([f"{op_symbol}m[{i}];" + ("\n" if i != column_count-1 else "") for i in range(0,column_count)])}
    return m;
}}
"""    ,end="")
    sys.stdout.close()




def make_equality_funcs(column_count,filename):
    sys.stdout =  open(f"{filename}.hpp", 'a')
    mat_def = f"mat<{column_count},R,T,Q>"
    print(f"""
template<length_t R, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR bool operator==({mat_def} const& m1, {mat_def} const& m2);
"""    ,end="")
    sys.stdout.close()

    sys.stdout =  open(f"{filename}.inl", 'a')
    print(f"""
template<length_t R, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR bool operator==({mat_def} const& m1, {mat_def} const& m2) {{
    return {" && ".join([f"(m1[{i}] == m2[{i}])" for i in range(0,column_count)])};
}}
"""    ,end="")
    sys.stdout.close()

def make_binary_scalar_funcs(op_symbols,column_count,filename):
    mat_def = f"mat<{column_count},R,T,Q>"
    col_range = range(0,column_count)
    template = """
template<length_t R, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR mat<{column_count},R, T, Q> operator{op_symbol}(mat<{column_count},R, T, Q> const& m, T scalar);
template<length_t R, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR mat<{column_count},R, T, Q> operator{op_symbol}(T scalar,mat<{column_count},R, T, Q> const& m);
"""
    sys.stdout =  open(f"{filename}.hpp", 'a')
    for op_symbol in op_symbols:
        print(template.format(
            op_symbol= op_symbol,
            column_count= column_count
        ),end="")
    sys.stdout.close()


    sys.stdout =  open(f"{filename}.inl", 'a')
    for op_symbol in op_symbols:
        print(f"""
template<length_t R, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<{column_count},R, T, Q> operator{op_symbol}(mat<{column_count},R, T, Q> const& m, T scalar) {{
    return mat<{column_count},R,T,Q>({",".join([f"m[{i}] {op_symbol} scalar" for i in range(0,column_count)])});
}}
template<length_t R, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR mat<{column_count},R, T, Q> operator{op_symbol}(T scalar,mat<{column_count},R, T, Q> const& m) {{
    return mat<{column_count},R,T,Q>({",".join([f"scalar {op_symbol} m[{i}]" for i in range(0,column_count)])});
}}
template<length_t R, typename T, qualifier Q,typename U>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR {mat_def}& operator{op_symbol}=({mat_def}& m, U scalar) {{
    {"    ".join([f"m[{i}] {op_symbol}= scalar;" + ("\n" if i != col_range.stop-1 else "") for i in col_range])}
    return m;
}}
""",end="")
    sys.stdout.close()


def make_binary_mat_funcs(op_symbols,column_count,filename):
    col_range = range(0,column_count)
    mat_def = f"mat<{column_count},R,T,Q>"
    mat_def_U = f"mat<{column_count},R,U,Q>"

    sys.stdout =  open(f"{filename}.hpp", 'a')
    for op_symbol in op_symbols:
       
        print(f"""
template<length_t R, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR {mat_def} operator{op_symbol}({mat_def} const& m1, {mat_def} const& m2);
template<length_t R, typename T, qualifier Q,typename U>
GLM_FUNC_DECL GLM_CONSTEXPR {mat_def}& operator{op_symbol}=({mat_def}& m1, {mat_def_U} const& m2);
""",end="")
    sys.stdout.close()

    
    sys.stdout =  open(f"{filename}.inl", 'a')
    for op_symbol in op_symbols:
        print(f"""
template<length_t R, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR {mat_def} operator{op_symbol}({mat_def} const& m1, {mat_def} const& m2) {{
    return {mat_def}({",".join([f"m1[{i}] {op_symbol} m2[{i}]" for i in col_range])});
}}
template<length_t R, typename T, qualifier Q,typename U>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR {mat_def}& operator{op_symbol}=({mat_def}& m1, {mat_def_U} const& m2) {{
    {"    ".join([f"m1[{i}] {op_symbol}= m2[{i}];" + ("\n" if i != col_range.stop-1 else "") for i in col_range])}
    return m1;
}}
""",end="")
    sys.stdout.close()


def make_scalar_commutative_operators(op_symbols,filename):
    template = """
template<length_t L, typename T, qualifier Q>
GLM_FUNC_DECL GLM_CONSTEXPR vec<L, T, Q> operator{op_symbol}(T scalar,vec<L, T, Q> const& v);
"""
    sys.stdout =  open(f"{filename}.hpp", 'a')
    for op_symbol in op_symbols:
        print(template.format(
            op_symbol= op_symbol
        ),end="")
    sys.stdout.close()

    template = """
template<length_t L, typename T, qualifier Q>
GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<L, T, Q> operator{op_symbol}(T scalar,vec<L, T, Q> const& v) {{
    return v {op_symbol} scalar;
}}
"""
    sys.stdout =  open(f"{filename}.inl", 'a')
    for op_symbol in op_symbols:
        print(template.format(
            op_symbol= op_symbol
        ),end="")
    sys.stdout.close()




if __name__ == "__main__":
      for C in range(2,5):
         filename = f"mat{C}xR_common_operators"
         sys.stdout = open(f"{filename}.hpp",'w')
         print("""
#pragma once
#include "qualifier.hpp"
#include "mat_common_operators.hpp"
namespace glm {
""")
         sys.stdout.close()

         sys.stdout = open(f"{filename}.inl",'w')
         print("""
namespace glm {
""")
         sys.stdout.close()

         make_unary_minus(C,filename)
         make_prefix_incr_decr_funcs(C,filename)
         make_equality_funcs(C,filename)
         make_binary_mat_funcs(['+', '-'],C,filename)
         make_binary_scalar_funcs(['+', '-', '*','/'],C,filename)

         sys.stdout = open(f"{filename}.hpp",'a')
         print(f"""
}}
#ifndef GLM_EXTERNAL_TEMPLATE
#include "{filename}.inl"
#endif
""")
         sys.stdout.close()


         sys.stdout = open(f"{filename}.inl",'a')
         print("""
}
""")
         sys.stdout.close()

     #make_scalar_commutative_operators(['+', '*'],"mat")