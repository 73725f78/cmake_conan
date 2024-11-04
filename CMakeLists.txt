cmake_minimum_required(VERSION 3.28)

project(Main VERSION 0.1.0)

set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_BUILD_TYPE Release)

include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#Project version, etc.
configure_file(main/include/config.h.in config.hpp)

find_package(Poco REQUIRED COMPONENTS Foundation Util)
find_package(nng REQUIRED)

add_subdirectory(main)
add_subdirectory(testing_lib)

#Pack configurations
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR amd64)
set(CPACK_SET_DESTDIR true)
set(CPACK_INSTALL_PREFIX /usr/local)
set(CPACK_PACKAGE_VENDOR "Luis")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "lrodriguez") #required
set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE ${CMAKE_SYSTEM_PROCESSOR})
set(CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)
set(CPACK_GENERATOR DEB)
include(CPack)
