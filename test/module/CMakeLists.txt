set(SAMPLE_NAME test-module)
add_executable(test-module module.cpp)

add_test(
	NAME test-module
	COMMAND $<TARGET_FILE:test-module>)
target_link_libraries(test-module PRIVATE glm::glm-module)
set_target_properties(test-module PROPERTIES CXX_SCAN_FOR_MODULES ON)
