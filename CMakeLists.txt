cmake_minimum_required(VERSION 2.8.3)

project(qore-dummy-module)


FIND_PACKAGE (Qore REQUIRED)

# Check for C++11.
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
else()
    message(FATAL_ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

set(CPP_SRC src/dummy-module.cpp)

set(module_name "dummy")

add_library(${module_name} SHARED ${CPP_SRC} ${QPP_SOURCES})

qore_binary_module(${module_name} "0.0.1")

qore_dist("${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

qore_config_info()

