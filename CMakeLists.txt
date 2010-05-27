cmake_minimum_required(VERSION 2.6)

project(Qore-dummy)

# where to look first for cmake modules, before ${CMAKE_ROOT}/Modules/ is checked
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules )

set(CMAKE_BUILD_TYPE Debug)

SET(QORE_MIN_VERSION "0.8.0")
FIND_PACKAGE (Qore REQUIRED)

add_subdirectory(src)

