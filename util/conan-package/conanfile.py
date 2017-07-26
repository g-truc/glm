import os
from conans import ConanFile

class GlmConan(ConanFile):
    name = "glm"
    version = "master"
    generators = "txt"
    url="https://github.com/g-truc/glm"
    description="OpenGL Mathematics (GLM)"
    license = "https://github.com/g-truc/glm/blob/manual/copying.txt"
    exports = ["FindGLM.cmake", "lib_licenses/*", os.sep.join([".", "..", "..", "*"])]

    def build(self):
        self.output.warn("No compilation necessary for GLM")
        self.output.warn(os.sep.join([".", "..", "..", "*"]))

    def package(self):
        self.copy("FindGLM.cmake", ".", ".")
        self.copy("*", src="glm", dst=os.sep.join([".", "include", "glm"]))
        self.copy("lib_licenses/license*", dst="licenses",  ignore_case=True, keep_path=False)
