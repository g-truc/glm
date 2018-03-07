cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
cmake_policy(VERSION 2.6)
if (NOT CMAKE_VERSION VERSION_LESS "3.1")
	cmake_policy(SET CMP0054 NEW)
endif()

project(glm)
set(GLM_VERSION "0.9.8")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

enable_testing()

add_definitions(-D_CRT_SECURE_NO_WARNINGS)

option(GLM_STATIC_LIBRARY_ENABLE "GLM static library" OFF)
if(GLM_STATIC_LIBRARY_ENABLE)
	message(STATUS "GLM is a header only library, no need to build it. Set the option GLM_STATIC_LIBRARY_ENABLE with ON to build an optional static library")
endif()

option(GLM_DYNAMIC_LIBRARY_ENABLE "GLM static library" OFF)
if(GLM_DYNAMIC_LIBRARY_ENABLE)
	message(STATUS "GLM is a header only library, no need to build it. Set the option GLM_DYNAMIC_LIBRARY_ENABLE with ON to build an optional dynamic library")
endif()

option(GLM_TEST_ENABLE "GLM test" OFF)
if(NOT GLM_TEST_ENABLE)
	message(STATUS "GLM is a header only library, no need to build it. Set the option GLM_TEST_ENABLE with ON to build and run the test bench")
endif()

option(GLM_TEST_ENABLE_FAST_MATH "Enable fast math optimizations" OFF)

if(("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang") OR ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU") OR (("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel") AND UNIX))
	option(GLM_TEST_ENABLE_CXX_98 "Enable C++ 98" OFF)
	option(GLM_TEST_ENABLE_CXX_0X "Enable C++ 0x" OFF)
	option(GLM_TEST_ENABLE_CXX_11 "Enable C++ 11" OFF)
	option(GLM_TEST_ENABLE_CXX_1Y "Enable C++ 1y" OFF)
	option(GLM_TEST_ENABLE_CXX_14 "Enable C++ 14" OFF)
	option(GLM_TEST_ENABLE_CXX_1Z "Enable C++ 1z" OFF)

	if(GLM_TEST_ENABLE_CXX_1Z)
		set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "c++1z")
		set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
		set(CMAKE_CXX_FLAGS "-std=c++1Z")
	elseif(GLM_TEST_ENABLE_CXX_14)
		set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "c++14")
		set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
		set(CMAKE_CXX_FLAGS "-std=c++14")
	elseif(GLM_TEST_ENABLE_CXX_1Y)
		set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "c++1y")
		set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
		set(CMAKE_CXX_FLAGS "-std=c++1y")
	elseif(GLM_TEST_ENABLE_CXX_11)
		set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "c++11")
		set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
		set(CMAKE_CXX_FLAGS "-std=c++11")
	elseif(GLM_TEST_ENABLE_CXX_0X)
		set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "c++0x")
		set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
		set(CMAKE_CXX_FLAGS "-std=c++0x")
	elseif(GLM_TEST_ENABLE_CXX_98)
		set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "c++98")
		set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
		set(CMAKE_CXX_FLAGS "-std=c++98")
		if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
			add_definitions(-Wno-long-long)
		endif()
	endif()
endif()

option(GLM_TEST_ENABLE_LANG_EXTENSIONS "Enable language extensions" OFF)

if(GLM_TEST_ENABLE_LANG_EXTENSIONS)
	if(GLM_TEST_ENABLE_FAST_MATH)
		if(CMAKE_COMPILER_IS_GNUCXX)
			add_definitions(-ffast-math)
		endif()

		if(MSVC)
			add_definitions(/fp:fast)
		endif()
	elseif(NOT GLM_TEST_ENABLE_FAST_MATH)
		if(MSVC)
			add_definitions(/fp:precise)
		endif()
	endif()
else()
	if(("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC") OR (("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel") AND WIN32))
		add_definitions(/Za)
	elseif(("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang") OR ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU"))
		add_definitions(-pedantic)
	endif()
endif()

option(GLM_TEST_ENABLE_SIMD_SSE2 "Enable SSE2 optimizations" OFF)
option(GLM_TEST_ENABLE_SIMD_SSE3 "Enable SSE3 optimizations" OFF)
option(GLM_TEST_ENABLE_SIMD_AVX "Enable AVX optimizations" OFF)
option(GLM_TEST_ENABLE_SIMD_AVX2 "Enable AVX2 optimizations" OFF)
option(GLM_TEST_FORCE_PURE "Force 'pure' instructions" OFF)

if(GLM_TEST_FORCE_PURE)
	add_definitions(-DGLM_FORCE_PURE)

	if(CMAKE_COMPILER_IS_GNUCXX)
		add_definitions(-mfpmath=387)
	endif()
	message(STATUS "GLM: No SIMD instruction set")
elseif(GLM_TEST_ENABLE_SIMD_AVX2)
	if(CMAKE_COMPILER_IS_GNUCXX OR ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang"))
		add_definitions(-mavx2)
	elseif(GLM_USE_INTEL)
		add_definitions(/QxAVX2)
	elseif(MSVC)
		add_definitions(/arch:AVX2)
	endif()
	message(STATUS "GLM: AVX2 instruction set")
elseif(GLM_TEST_ENABLE_SIMD_AVX)
	if(CMAKE_COMPILER_IS_GNUCXX OR ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang"))
		add_definitions(-mavx)
	elseif(GLM_USE_INTEL)
		add_definitions(/QxAVX)
	elseif(MSVC)
		add_definitions(/arch:AVX)
	endif()
	message(STATUS "GLM: AVX instruction set")
elseif(GLM_TEST_ENABLE_SIMD_SSE3)
	if(CMAKE_COMPILER_IS_GNUCXX OR ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang"))
		add_definitions(-msse3)
	elseif(GLM_USE_INTEL)
		add_definitions(/QxSSE3)
	elseif(MSVC AND NOT CMAKE_CL_64)
		add_definitions(/arch:SSE2) # VC doesn't support /arch:SSE3
	endif()
	message(STATUS "GLM: SSE3 instruction set")
elseif(GLM_TEST_ENABLE_SIMD_SSE2)
	if(CMAKE_COMPILER_IS_GNUCXX OR ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang"))
		add_definitions(-msse2)
	elseif(GLM_USE_INTEL)
		add_definitions(/QxSSE2)
	elseif(MSVC AND NOT CMAKE_CL_64)
		add_definitions(/arch:SSE2)
	endif()
	message(STATUS "GLM: SSE2 instruction set")
endif()

if(CMAKE_COMPILER_IS_GNUCXX)
	#add_definitions(-S)
	#add_definitions(-s)
	add_definitions(-O2)

	#add_definitions(-fprofile-arcs -ftest-coverage) gcov
	#ctest_enable_coverage()
endif()

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	add_definitions(/FAs)
endif()

include_directories("${PROJECT_SOURCE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/test/external")

add_subdirectory(glm)
add_subdirectory(test)

set(GLM_INSTALL_CONFIGDIR "${CMAKE_INSTALL_LIBDIR}/cmake/glm")
install(DIRECTORY glm DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/glmConfigVersion.cmake"
    VERSION ${GLM_VERSION}
    COMPATIBILITY AnyNewerVersion
)

# build tree package config
configure_file(
    cmake/glmBuildConfig.cmake.in
    glmConfig.cmake
    @ONLY
)

# install tree package config
configure_package_config_file(
    cmake/glmConfig.cmake.in
    ${GLM_INSTALL_CONFIGDIR}/glmConfig.cmake
    INSTALL_DESTINATION ${GLM_INSTALL_CONFIGDIR}
    PATH_VARS CMAKE_INSTALL_INCLUDEDIR
    NO_CHECK_REQUIRED_COMPONENTS_MACRO
)

install(
    FILES 
        "${CMAKE_CURRENT_BINARY_DIR}/${GLM_INSTALL_CONFIGDIR}/glmConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/glmConfigVersion.cmake"
    DESTINATION ${GLM_INSTALL_CONFIGDIR}
)

if (NOT CMAKE_VERSION VERSION_LESS "3.0")
    add_library(glm INTERFACE)
    target_include_directories(glm INTERFACE
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    )
    install(TARGETS glm EXPORT glmTargets)

    export(
        EXPORT glmTargets
        FILE "${CMAKE_CURRENT_BINARY_DIR}/glmTargets.cmake"
    )
    
    install(
        EXPORT glmTargets FILE glmTargets.cmake
        DESTINATION ${GLM_INSTALL_CONFIGDIR}
    )
endif()

# build pkg-config file
configure_file(
    "./cmake/glm.pc.in"
    "glm.pc"
    @ONLY
)

# install pkg-config file
install(
    FILES "${CMAKE_CURRENT_BINARY_DIR}/glm.pc"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/pkgconfig"
)

export(PACKAGE glm)
