cmake_minimum_required(VERSION 3.10)
project(X11Overlay)

find_package(fmt REQUIRED)
find_package(X11 REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(CAIRO REQUIRED cairo)

set(CMAKE_CXX_STANDARD 11)

include_directories(${X11_INCLUDE_DIR} ${CAIRO_INCLUDE_DIRS})

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(X11Overlay ${SOURCES})

target_include_directories(X11Overlay PRIVATE include)

target_link_libraries(X11Overlay ${X11_LIBRARIES} ${CAIRO_LIBRARIES} fmt::fmt)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

