SET(CONAN_CONFIG ${CMAKE_CURRENT_SOURCE_DIR}/1.0.0/conanfile.py)
ADD_CUSTOM_TARGET(mili_1.0.0 ALL
    conan export-pkg ${CMAKE_CURRENT_SOURCE_DIR}/1.0.0 Mili/stable -f -s arch=${CONAN_ARCH}
    COMMAND
    SOURCES ${CONAN_CONFIG}
)
SOURCE_GROUP("Config" FILES ${CONAN_CONFIG})