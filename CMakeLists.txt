cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
cmake_policy(VERSION 3.2)

set(GLM_VERSION "0.9.9")
project(glm VERSION ${GLM_VERSION} LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

enable_testing()

option(GLM_STATIC_LIBRARY_ENABLE "GLM static library" OFF)
if(GLM_STATIC_LIBRARY_ENABLE)
	message(STATUS "GLM is a header only library, no need to build it. Set the option GLM_STATIC_LIBRARY_ENABLE with ON to build an optional static library")
endif()

option(GLM_DYNAMIC_LIBRARY_ENABLE "GLM dynamic library" OFF)
if(GLM_DYNAMIC_LIBRARY_ENABLE)
	message(STATUS "GLM is a header only library, no need to build it. Set the option GLM_DYNAMIC_LIBRARY_ENABLE with ON to build an optional dynamic library")
endif()

option(GLM_TEST_ENABLE "GLM test" OFF)
if(NOT GLM_TEST_ENABLE)
	message(STATUS "GLM is a header only library, no need to build it. Set the option GLM_TEST_ENABLE with ON to build and run the test bench")
endif()

option(GLM_TEST_ENABLE_CXX_98 "Enable C++ 98" OFF)
option(GLM_TEST_ENABLE_CXX_11 "Enable C++ 11" OFF)
option(GLM_TEST_ENABLE_CXX_14 "Enable C++ 14" OFF)
option(GLM_TEST_ENABLE_CXX_17 "Enable C++ 17" OFF)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(GLM_TEST_ENABLE_CXX_17)
	set(CMAKE_CXX_STANDARD 17)
	message(STATUS "GLM: Build with C++17 features")

elseif(GLM_TEST_ENABLE_CXX_14)
	set(CMAKE_CXX_STANDARD 14)
	message(STATUS "GLM: Build with C++14 features")

elseif(GLM_TEST_ENABLE_CXX_11)
	set(CMAKE_CXX_STANDARD 11)
	message(STATUS "GLM: Build with C++11 features")

elseif(GLM_TEST_ENABLE_CXX_98)
	set(CMAKE_CXX_STANDARD 98)
	message(STATUS "GLM: Build with C++98 features")
endif()

option(GLM_TEST_ENABLE_LANG_EXTENSIONS "Enable language extensions" OFF)

if(GLM_TEST_ENABLE_LANG_EXTENSIONS)
	set(CMAKE_CXX_EXTENSIONS ON)

	message(STATUS "GLM: Build with C++ language extensions")
else()
	set(CMAKE_CXX_EXTENSIONS OFF)
endif()

option(GLM_TEST_ENABLE_FAST_MATH "Enable fast math optimizations" OFF)
if(GLM_TEST_ENABLE_FAST_MATH)
	message(STATUS "GLM: Build with fast math optimizations")

	if((CMAKE_CXX_COMPILER_ID MATCHES "Clang") OR (CMAKE_CXX_COMPILER_ID MATCHES "GNU"))
		add_compile_options(-ffast-math)

	elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
		add_compile_options(/fp:fast)
	endif()
else()
	if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
		add_compile_options(/fp:precise)
	endif()
endif()

option(GLM_TEST_ENABLE_SIMD_SSE2 "Enable SSE2 optimizations" OFF)
option(GLM_TEST_ENABLE_SIMD_SSE3 "Enable SSE3 optimizations" OFF)
option(GLM_TEST_ENABLE_SIMD_AVX "Enable AVX optimizations" OFF)
option(GLM_TEST_ENABLE_SIMD_AVX2 "Enable AVX2 optimizations" OFF)
option(GLM_TEST_FORCE_PURE "Force 'pure' instructions" OFF)

option(GLM_ENABLE_EXPERIMENTAL "Enable experimental GLM_GTX" OFF)
configure_file(glm/experimental.hpp.in experimental.hpp @ONLY)
include_directories(${CMAKE_BINARY_DIR}/glm)
include_directories(${CMAKE_BINARY_DIR})

if(GLM_TEST_FORCE_PURE)
	add_definitions(-DGLM_FORCE_PURE)

	if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
		add_compile_options(-mfpmath=387)
	endif()
	message(STATUS "GLM: No SIMD instruction set")

elseif(GLM_TEST_ENABLE_SIMD_AVX2)
	if((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
		add_compile_options(-mavx2)
	elseif(CMAKE_CXX_COMPILER_ID MATCHES "Intel")
		add_compile_options(/QxAVX2)
	elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
		add_compile_options(/arch:AVX2)
	endif()
	message(STATUS "GLM: AVX2 instruction set")

elseif(GLM_TEST_ENABLE_SIMD_AVX)
	if((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
		add_compile_options(-mavx)
	elseif(CMAKE_CXX_COMPILER_ID MATCHES "Intel")
		add_compile_options(/QxAVX)
	elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
		add_compile_options(/arch:AVX)
	endif()
	message(STATUS "GLM: AVX instruction set")

elseif(GLM_TEST_ENABLE_SIMD_SSE3)
	if((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
		add_compile_options(-msse3)
	elseif(CMAKE_CXX_COMPILER_ID MATCHES "Intel")
		add_compile_options(/QxSSE3)
	elseif((CMAKE_CXX_COMPILER_ID MATCHES "MSVC") AND NOT CMAKE_CL_64)
		add_compile_options(/arch:SSE2) # VC doesn't support /arch:SSE3
	endif()
	message(STATUS "GLM: SSE3 instruction set")

elseif(GLM_TEST_ENABLE_SIMD_SSE2)
	if((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
		add_compile_options(-msse2)
	elseif(CMAKE_CXX_COMPILER_ID MATCHES "Intel")
		add_compile_options(/QxSSE2)
	elseif((CMAKE_CXX_COMPILER_ID MATCHES "MSVC") AND NOT CMAKE_CL_64)
		add_compile_options(/arch:SSE2)
	endif()
	message(STATUS "GLM: SSE2 instruction set")
endif()

# Compiler and default options

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
	message("GLM: Clang - ${CMAKE_CXX_COMPILER_ID} compiler")

	add_compile_options(-Werror -Weverything)
	add_compile_options(-Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-c++11-long-long -Wno-padded -Wno-gnu-anonymous-struct -Wno-nested-anon-types)
	add_compile_options(-Wno-undefined-reinterpret-cast -Wno-sign-conversion -Wno-unused-variable -Wno-missing-prototypes -Wno-unreachable-code -Wno-missing-variable-declarations -Wno-sign-compare -Wno-global-constructors -Wno-unused-macros -Wno-format-nonliteral)

elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
	message("GLM: GCC - ${CMAKE_CXX_COMPILER_ID} compiler")

	add_compile_options(-O2)
	add_compile_options(-Wno-long-long)

elseif(CMAKE_CXX_COMPILER_ID MATCHES "Intel")
	message("GLM: Intel - ${CMAKE_CXX_COMPILER_ID} compiler")

elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
	message("GLM: Visual C++ - ${CMAKE_CXX_COMPILER_ID} compiler")

	add_compile_options(/FAs /W4 /WX)
	add_compile_options(/wd4309 /wd4324 /wd4389 /wd4127 /wd4267 /wd4146 /wd4201 /wd4464 /wd4514 /wd4701 /wd4820 /wd4365)
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

include_directories("${PROJECT_SOURCE_DIR}")

add_subdirectory(glm)
add_subdirectory(test)

option(GLM_INSTALL_ENABLE "GLM install" ON)

set(GLM_INSTALL_CONFIGDIR "${CMAKE_INSTALL_LIBDIR}/cmake/glm")
if (GLM_INSTALL_ENABLE)
	install(DIRECTORY glm DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
	install(FILES "${CMAKE_CURRENT_BINARY_DIR}/experimental.hpp" DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/glm)
endif()

write_basic_package_version_file("${CMAKE_CURRENT_BINARY_DIR}/glmConfigVersion.cmake" VERSION ${GLM_VERSION} COMPATIBILITY AnyNewerVersion)

# build tree package config
configure_file(cmake/glmBuildConfig.cmake.in glmConfig.cmake @ONLY)

# install tree package config
configure_package_config_file(
	cmake/glmConfig.cmake.in
	${GLM_INSTALL_CONFIGDIR}/glmConfig.cmake
	INSTALL_DESTINATION ${GLM_INSTALL_CONFIGDIR}
	PATH_VARS CMAKE_INSTALL_INCLUDEDIR
	NO_CHECK_REQUIRED_COMPONENTS_MACRO)

if(GLM_INSTALL_ENABLE)
	install(FILES
		"${CMAKE_CURRENT_BINARY_DIR}/${GLM_INSTALL_CONFIGDIR}/glmConfig.cmake"
		"${CMAKE_CURRENT_BINARY_DIR}/glmConfigVersion.cmake"
		DESTINATION ${GLM_INSTALL_CONFIGDIR})
endif()

add_library(glm INTERFACE)
target_include_directories(glm INTERFACE
	$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
install(TARGETS glm EXPORT glmTargets)

export(EXPORT glmTargets FILE "${CMAKE_CURRENT_BINARY_DIR}/glmTargets.cmake")

if(GLM_INSTALL_ENABLE)
	install(EXPORT glmTargets FILE glmTargets.cmake DESTINATION ${GLM_INSTALL_CONFIGDIR})
endif()

# build pkg-config file
configure_file("./cmake/glm.pc.in" "glm.pc" @ONLY)

# install pkg-config file
if (GLM_INSTALL_ENABLE)
	install(FILES "${CMAKE_CURRENT_BINARY_DIR}/glm.pc" DESTINATION "${CMAKE_INSTALL_LIBDIR}/pkgconfig")
endif()

export(PACKAGE glm)

if(NOT TARGET uninstall)
	configure_file(
		${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in
		${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake
		IMMEDIATE @ONLY)

	add_custom_target(uninstall
		COMMAND ${CMAKE_COMMAND} -P
		${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
endif()
