from conans import ConanFile, CMake
import os

class TestGlm(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake"

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def test(self):
        self.run(os.sep.join([".", "bin", "testGlm"]))
