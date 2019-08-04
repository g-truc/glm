function(glmCreateTestGTC NAME)
	set(SAMPLE_NAME test-${NAME})
	add_executable(${SAMPLE_NAME} ${NAME}.cpp)
	target_link_libraries(${SAMPLE_NAME} PUBLIC glm::glm)

	add_test(
		NAME ${SAMPLE_NAME}
		COMMAND $<TARGET_FILE:${SAMPLE_NAME}> )
endfunction()

if(GLM_TEST_ENABLE)
	add_subdirectory(bug)
	add_subdirectory(core)
	add_subdirectory(ext)
	add_subdirectory(gtc)
	add_subdirectory(gtx)
	add_subdirectory(perf)
endif()


