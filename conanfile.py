## run: 
##      $ cd build
##      $ conan install .. --build=missing

from conan import ConanFile
from conan.tools.cmake import cmake_layout

class CompressorRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"

    def requirements(self):
        self.requires("poco/1.13.0")
        self.requires("nng/1.7.1")

    # def build_requirements(self):
        # self.tool_requires("cmake/3.22.6")

    def layout(self):
        cmake_layout(self)
