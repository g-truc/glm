project "glm"

  kind "StaticLib"
  language "C++"

  targetdir ("../../bin/" .. outputdir .. "/%{prj.name}")
  objdir ("../../obj/" .. outputdir .. "/%{prj.name}")

  files
  {
	 "glm/detail/glm.cpp"
  }

  defines
  {
	 "GLM_ENABLE_EXPERIMENTAL"
  }
  
  includedirs
  {
  	"./",
  }
  
  buildoptions
  {
  }

