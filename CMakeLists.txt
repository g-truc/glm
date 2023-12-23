cmake_minimum_required(VERSION 3.6 FATAL_ERROR)
cmake_policy(VERSION 3.6)


file(READ "glm/detail/setup.hpp" GLM_SETUP_FILE)
string(REGEX MATCH "#define[ ]+GLM_VERSION_MAJOR[ ]+([0-9]+)" _ ${GLM_SETUP_FILE})
set(GLM_VERSION_MAJOR "${CMAKE_MATCH_1}")
string(REGEX MATCH "#define[ ]+GLM_VERSION_MINOR[ ]+([0-9]+)" _ ${GLM_SETUP_FILE})
set(GLM_VERSION_MINOR "${CMAKE_MATCH_1}")
string(REGEX MATCH "#define[ ]+GLM_VERSION_PATCH[ ]+([0-9]+)" _ ${GLM_SETUP_FILE})
set(GLM_VERSION_PATCH "${CMAKE_MATCH_1}")
string(REGEX MATCH "#define[ ]+GLM_VERSION_REVISION[ ]+([0-9]+)" _ ${GLM_SETUP_FILE})
set(GLM_VERSION_REVISION "${CMAKE_MATCH_1}")

set(GLM_VERSION ${GLM_VERSION_MAJOR}.${GLM_VERSION_MINOR}.${GLM_VERSION_PATCH}.${GLM_VERSION_REVISION})
project(glm VERSION ${GLM_VERSION} LANGUAGES CXX)
message(STATUS "GLM: Version " ${GLM_VERSION})

set(GLM_IS_MASTER_PROJECT OFF)
if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
	set(GLM_IS_MASTER_PROJECT ON)
endif()

option(GLM_BUILD_LIBRARY "Build dynamic/static library" ON)
option(GLM_BUILD_TESTS "Build the test programs" ${GLM_IS_MASTER_PROJECT})
option(GLM_BUILD_INSTALL "Generate the install target" ${GLM_IS_MASTER_PROJECT})

include(GNUInstallDirs)

add_subdirectory(glm)

if (GLM_BUILD_TESTS)
	include(CTest)
	add_subdirectory(test)
endif()

if (GLM_BUILD_INSTALL)
	include(CPack)

	install(TARGETS glm-header-only glm EXPORT glm)
	install(
		DIRECTORY glm
		DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
		PATTERN "CMakeLists.txt" EXCLUDE
	)
	install(
		EXPORT glm
		NAMESPACE glm::
		DESTINATION "${CMAKE_INSTALL_DATAROOTDIR}/glm"
		FILE glmConfig.cmake
	)
	include(CMakePackageConfigHelpers)
	write_basic_package_version_file(
		"${CMAKE_CURRENT_BINARY_DIR}/glmConfigVersion.cmake"
		COMPATIBILITY AnyNewerVersion
	)
	install(
		FILES "${CMAKE_CURRENT_BINARY_DIR}/glmConfigVersion.cmake"
		DESTINATION "${CMAKE_INSTALL_DATAROOTDIR}/glm"
	)

	configure_file(
		"${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmake_uninstall.cmake.in"
		"${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
		IMMEDIATE @ONLY
	)

	add_custom_target(
		uninstall
		"${CMAKE_COMMAND}" -P
		"${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
	)
endif()
