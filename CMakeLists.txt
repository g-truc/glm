#glm

add_library(glm INTERFACE)

target_include_directories(glm INTERFACE .)

target_compile_definitions(glm INTERFACE GLM_FORCE_SIZE_FUNC)

if(NTOP_GLM_GCC_OVERRIDES)
  target_compile_definitions(glm INTERFACE -DGLM_GCC_OVERRIDE)
endif()
