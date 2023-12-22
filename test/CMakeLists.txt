option(GLM_QUIET "No CMake Message" OFF)

option(GLM_TEST_ENABLE "Build unit tests" ON)
option(GLM_PERF_TEST_ENABLE "Build perf tests" OFF)
<<<<<<< HEAD
=======
option(GLM_TEST_ENABLE_SIMD_SSE2 "Enable SSE2 optimizations" OFF)
option(GLM_TEST_ENABLE_SIMD_SSE3 "Enable SSE3 optimizations" OFF)
option(GLM_TEST_ENABLE_SIMD_SSSE3 "Enable SSSE3 optimizations" OFF)
option(GLM_TEST_ENABLE_SIMD_SSE4_1 "Enable SSE 4.1 optimizations" OFF)
option(GLM_TEST_ENABLE_SIMD_SSE4_2 "Enable SSE 4.2 optimizations" OFF)
option(GLM_TEST_ENABLE_SIMD_AVX "Enable AVX optimizations" OFF)
option(GLM_TEST_ENABLE_SIMD_AVX2 "Enable AVX2 optimizations" OFF)
option(GLM_TEST_ENABLE_SIMD_NEON "Enable ARM NEON optimizations" OFF)
option(GLM_TEST_ENABLE_SIMD_FMA "Enable FMA optimizations" OFF)
option(GLM_TEST_FORCE_PURE "Force 'pure' instructions" OFF)

if(GLM_TEST_FORCE_PURE)
	add_definitions(-DGLM_FORCE_PURE)

	if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
		add_compile_options(-mfpmath=387)
	endif()
	message(STATUS "GLM: No SIMD instruction set")

elseif(GLM_TEST_ENABLE_SIMD_AVX2)
	add_definitions(-DGLM_FORCE_INTRINSICS)

	if((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
		add_compile_options(-mavx2)
	elseif(CMAKE_CXX_COMPILER_ID MATCHES "Intel")
		add_compile_options(/QxAVX2)
	elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
		add_compile_options(/arch:AVX2)
	endif()
	message(STATUS "GLM: AVX2 instruction set")

elseif(GLM_TEST_ENABLE_SIMD_AVX)
	add_definitions(-DGLM_FORCE_INTRINSICS)

	if((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
		add_compile_options(-mavx)
	elseif(CMAKE_CXX_COMPILER_ID MATCHES "Intel")
		add_compile_options(/QxAVX)
	elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
		add_compile_options(/arch:AVX)
	endif()
	message(STATUS "GLM: AVX instruction set")

elseif(GLM_TEST_ENABLE_SIMD_SSE4_2)
	add_definitions(-DGLM_FORCE_INTRINSICS)

	if((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
		add_compile_options(-msse4.2)
	elseif(CMAKE_CXX_COMPILER_ID MATCHES "Intel")
		add_compile_options(/QxSSE4.2)
	elseif((CMAKE_CXX_COMPILER_ID MATCHES "MSVC") AND NOT CMAKE_CL_64)
		add_compile_options(/arch:SSE2) # VC doesn't support SSE4.2
	endif()
	message(STATUS "GLM: SSE4.2 instruction set")

elseif(GLM_TEST_ENABLE_SIMD_SSE4_1)
	add_definitions(-DGLM_FORCE_INTRINSICS)

	if((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
		add_compile_options(-msse4.1)
	elseif(CMAKE_CXX_COMPILER_ID MATCHES "Intel")
		add_compile_options(/QxSSE4.1)
	elseif((CMAKE_CXX_COMPILER_ID MATCHES "MSVC") AND NOT CMAKE_CL_64)
		add_compile_options(/arch:SSE2) # VC doesn't support SSE4.1
	endif()
	message(STATUS "GLM: SSE4.1 instruction set")

elseif(GLM_TEST_ENABLE_SIMD_SSSE3)
	add_definitions(-DGLM_FORCE_INTRINSICS)

	if((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
		add_compile_options(-mssse3)
	elseif(CMAKE_CXX_COMPILER_ID MATCHES "Intel")
		add_compile_options(/QxSSSE3)
	elseif((CMAKE_CXX_COMPILER_ID MATCHES "MSVC") AND NOT CMAKE_CL_64)
		add_compile_options(/arch:SSE2) # VC doesn't support SSSE3
	endif()
	message(STATUS "GLM: SSSE3 instruction set")

elseif(GLM_TEST_ENABLE_SIMD_SSE3)
	add_definitions(-DGLM_FORCE_INTRINSICS)

	if((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
		add_compile_options(-msse3)
	elseif(CMAKE_CXX_COMPILER_ID MATCHES "Intel")
		add_compile_options(/QxSSE3)
	elseif((CMAKE_CXX_COMPILER_ID MATCHES "MSVC") AND NOT CMAKE_CL_64)
		add_compile_options(/arch:SSE2) # VC doesn't support SSE3
	endif()
	message(STATUS "GLM: SSE3 instruction set")

elseif(GLM_TEST_ENABLE_SIMD_SSE2)
	add_definitions(-DGLM_FORCE_INTRINSICS)

	if((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
		add_compile_options(-msse2)
	elseif(CMAKE_CXX_COMPILER_ID MATCHES "Intel")
		add_compile_options(/QxSSE2)
	elseif((CMAKE_CXX_COMPILER_ID MATCHES "MSVC") AND NOT CMAKE_CL_64)
		add_compile_options(/arch:SSE2)
	endif()
	message(STATUS "GLM: SSE2 instruction set")
elseif(GLM_TEST_ENABLE_SIMD_NEON)
	add_definitions(-DGLM_FORCE_NEON)
	message(STATUS "GLM: ARM NEON instruction set")
endif()

if (GLM_TEST_ENABLE_SIMD_FMA)
	add_definitions(-DGLM_FORCE_FMA)
	if((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
		add_compile_options(-mfma)
	endif()
endif()
>>>>>>> 5c1da05b (Simd improvement)

# Compiler and default options

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
	if(NOT GLM_QUIET)
		message("GLM: Clang - ${CMAKE_CXX_COMPILER_ID} compiler")
	endif()

	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
	if(NOT GLM_DISABLE_AUTO_DETECTION)
		add_compile_options(-Werror -Weverything)
	endif()
<<<<<<< HEAD
=======
	if (NOT APPLE)
		add_compile_options(-Wno-unsafe-buffer-usage) #this option makes MacOS compilation fail but prevent error on windows
	endif()
	
	add_compile_options(-Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-c++11-long-long -Wno-padded -Wno-gnu-anonymous-struct -Wno-nested-anon-types)
    add_compile_options(-Wno-undefined-reinterpret-cast -Wno-sign-conversion -Wno-unused-variable -Wno-missing-prototypes -Wno-unreachable-code -Wno-missing-variable-declarations -Wno-sign-compare -Wno-global-constructors -Wno-unused-macros -Wno-format-nonliteral -Wno-float-equal)
>>>>>>> 5c1da05b (Simd improvement)

elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
	if(NOT GLM_QUIET)
		message("GLM: GCC - ${CMAKE_CXX_COMPILER_ID} compiler")
	endif()

	if(NOT GLM_DISABLE_AUTO_DETECTION)
		add_compile_options(-Werror)
#		add_compile_options(-Wpedantic)
#		add_compile_options(-Wall)
#		add_compile_options(-Wextra)
	endif()
	add_compile_options(-O2)
	#add_compile_options(-Wno-long-long)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "Intel")
	if(NOT GLM_QUIET)
		message("GLM: Intel - ${CMAKE_CXX_COMPILER_ID} compiler")
	endif()

elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
	if(NOT GLM_QUIET)
		message("GLM: Visual C++ - ${CMAKE_CXX_COMPILER_ID} compiler")
	endif()

	if(NOT GLM_DISABLE_AUTO_DETECTION)
		add_compile_options(/Wall /WX)
		add_compile_options(/wd4464) # warning C4464: relative include path contains '..'
		add_compile_options(/wd4514) # warning C4514: unreferenced inline function has been removed 
		add_compile_options(/wd4365) # warning C4365: signed/unsigned mismatch 
		add_compile_options(/wd5045) # warning C5045: Compiler will insert Spectre mitigation for memory load if /Qspectre switch specified
		add_compile_options(/wd5029) # warning C5029: nonstandard extension used: alignment attributes in C++ apply to variables, data members and tag types only
		add_compile_options(/wd4820) # warning C4820: 'test_decl::S1': '3' bytes padding added after data member 'test_decl::S1::A' 
		add_compile_options(/wd4710) # warning C4710: 'std::string glm::detail::format(const char *,...)': function not inlined
		add_compile_options(/wd4626) # warning C4626: 'glm::io::format_punct<CTy>': assignment operator was implicitly defined as deleted
		add_compile_options(/wd4711) # warning C4711: function 'int __cdecl test_vec1(void)' selected for automatic inline expansion 
		add_compile_options(/wd4571) # warning C4571: Informational: catch(...) semantics changed since Visual C++ 7.1; structured exceptions (SEH) are no longer caught
		add_compile_options(/wd4625) # warning C4625: 'std::codecvt_base': copy constructor was implicitly defined as deleted
		add_compile_options(/wd5026) # warning C5026: 'std::_Generic_error_category': move constructor was implicitly defined as deleted
		add_compile_options(/wd5027) # warning C5027: 'std::_Generic_error_category': move assignment operator was implicitly defined as deleted
		add_compile_options(/wd4774) # warning C4774: 'sprintf_s' : format string expected in argument 3 is not a string literal
	endif()
#	add_compile_options(/wd4309 /wd4324 /wd4389 /wd4127 /wd4267 /wd4146 /wd4201 /wd4464 /wd4514 /wd4701 /wd4820 /wd4365)
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

function(glmCreateTestGTC NAME)
	set(SAMPLE_NAME test-${NAME})
	add_executable(${SAMPLE_NAME} ${NAME}.cpp)

	add_test(
		NAME ${SAMPLE_NAME}
		COMMAND $<TARGET_FILE:${SAMPLE_NAME}> )
	target_link_libraries(${SAMPLE_NAME} PRIVATE glm::glm)
endfunction()

if(GLM_TEST_ENABLE)
	add_subdirectory(bug)
	add_subdirectory(core)
	add_subdirectory(ext)
	add_subdirectory(gtc)
	add_subdirectory(gtx)
endif()
if(GLM_PERF_TEST_ENABLE)
	add_subdirectory(perf)
endif()

