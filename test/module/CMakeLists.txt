add_executable(test-module module.cpp)
add_test(
	NAME test-module
	COMMAND $<TARGET_FILE:test-module>)

# Consumer should do this globally via add_compile_definitions
target_compile_definitions(glm::glm-module PUBLIC GLM_ENABLE_EXPERIMENTAL)
target_link_libraries(test-module PRIVATE glm::glm-module)
set_target_properties(test-module PROPERTIES CXX_SCAN_FOR_MODULES ON)
