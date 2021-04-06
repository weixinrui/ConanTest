from conans import ConanFile, tools


class MiliConan(ConanFile):
    name = "mili"
    version = "1.0.0"
    settings = "os", "compiler", "build_type", "arch"
    description = "<Description of Mili here>"
    url = "None"
    license = "None"
    author = "None"
    topics = None

    def package(self):
        self.copy("mili/*")

    def package_info(self):
        self.cpp_info.libs = tools.collect_libs(self)
