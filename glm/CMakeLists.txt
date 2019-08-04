file(GLOB ROOT_SOURCE src/*.cpp)
file(GLOB ROOT_INLINE include/glm/*.inl)
file(GLOB ROOT_HEADER include/glm/*.hpp)

file(GLOB_RECURSE CORE_SOURCE src/detail/*.cpp)
file(GLOB_RECURSE CORE_INLINE include/glm/detail/*.inl)
file(GLOB_RECURSE CORE_HEADER include/glm/detail/*.hpp)

file(GLOB_RECURSE EXT_SOURCE src/ext/*.cpp)
file(GLOB_RECURSE EXT_INLINE include/glm/ext/*.inl)
file(GLOB_RECURSE EXT_HEADER include/glm/ext/*.hpp)

file(GLOB_RECURSE GTC_SOURCE src/gtc/*.cpp)
file(GLOB_RECURSE GTC_INLINE include/glm/gtc/*.inl)
file(GLOB_RECURSE GTC_HEADER include/glm/gtc/*.hpp)

file(GLOB_RECURSE GTX_SOURCE src/gtx/*.cpp)
file(GLOB_RECURSE GTX_INLINE include/glm/gtx/*.inl)
file(GLOB_RECURSE GTX_HEADER include/glm/gtx/*.hpp)

file(GLOB_RECURSE SIMD_SOURCE src/simd/*.cpp)
file(GLOB_RECURSE SIMD_INLINE include/glm/simd/*.inl)
file(GLOB_RECURSE SIMD_HEADER include/glm/simd/*.h)

set(SOURCE ${ROOT_SOURCE}
		${CORE_SOURCE}
		${EXT_SOURCE}
		${GTC_SOURCE}
		${GTX_SOURCE}
		${SIMD_SOURCE}
		)

set(INCLUDE ${ROOT_SOURCE}
		${CORE_SOURCE}
		${EXT_SOURCE}
		${GTC_SOURCE}
		${GTX_SOURCE}
		${SIMD_SOURCE}
		)

source_group("Core Files" FILES ${ROOT_SOURCE} ${CORE_SOURCE})
source_group("Core Files" FILES ${ROOT_INLINE} ${CORE_INLINE})
source_group("Core Files" FILES ${ROOT_HEADER} ${CORE_HEADER})
source_group("EXT Files" FILES ${EXT_SOURCE})
source_group("EXT Files" FILES ${EXT_INLINE})
source_group("EXT Files" FILES ${EXT_HEADER})
source_group("GTC Files" FILES ${GTC_SOURCE})
source_group("GTC Files" FILES ${GTC_INLINE})
source_group("GTC Files" FILES ${GTC_HEADER})
source_group("GTX Files" FILES ${GTX_SOURCE})
source_group("GTX Files" FILES ${GTX_INLINE})
source_group("GTX Files" FILES ${GTX_HEADER})
source_group("SIMD Files" FILES ${SIMD_SOURCE})
source_group("SIMD Files" FILES ${SIMD_INLINE})
source_group("SIMD Files" FILES ${SIMD_HEADER})

add_library(glm INTERFACE)
add_library(glm::glm ALIAS glm)
target_include_directories(glm
		INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		          $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
		)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(TARGETS glm
		EXPORT glm-targets
		RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
		LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
		ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
		)
install(EXPORT glm-targets
		NAMESPACE glm::
		FILE glmConfig.cmake
		DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/glm
		EXPORT_LINK_INTERFACE_LIBRARIES
		)

# CMake automatically adds an architecture compatibility check to make sure
# 32 and 64 bit code is not accidentally mixed. For a header-only library this
# is not required. The check can be disabled by temporarily unsetting
# CMAKE_SIZEOF_VOID_P. In CMake 3.14 and later this can be achieved more cleanly
# with write_basic_package_version_file(ARCH_INDEPENDENT).
# TODO: Use this once a newer CMake can be required.
set(GLM_SIZEOF_VOID_P ${CMAKE_SIZEOF_VOID_P})
unset(CMAKE_SIZEOF_VOID_P)
write_basic_package_version_file("${CMAKE_CURRENT_BINARY_DIR}/glmConfigVersion.cmake" VERSION ${GLM_VERSION} COMPATIBILITY AnyNewerVersion)
set(CMAKE_SIZEOF_VOID_P ${GLM_SIZEOF_VOID_P})

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/glmConfigVersion.cmake"
		DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/glm
		)

if(BUILD_STATIC_LIBS)
	add_library(glm_static STATIC ${SOURCE})
	target_link_libraries(glm_static PUBLIC glm::glm)
endif()

if(BUILD_SHARED_LIBS)
	add_library(glm_shared SHARED ${SOURCE})
	target_link_libraries(glm_shared PUBLIC glm::glm)
endif()

