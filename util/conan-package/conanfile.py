import os
from conans import ConanFile

class GlmConan(ConanFile):
    name = "glm"
    version = "0.9.8.5"
    generators = "txt"
    url = "https://github.com/g-truc/glm"
    description = "OpenGL Mathematics (GLM)"
    license = "The Happy Bunny License (Modified MIT License)"
    exports_sources = ["FindGLM.cmake", os.sep.join(["..", "..", "glm*"])]
    exports = "lib_licenses/*"

    def package(self):
        self.copy("FindGLM.cmake", ".", ".")
        self.copy("*", src="glm", dst=os.sep.join([".", "include", "glm"]))
        self.copy("lib_licenses/license*", dst="licenses", ignore_case=True, keep_path=False)
