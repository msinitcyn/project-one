cmake_minimum_required(VERSION 3.10)
project(X11Overlay)

# Find X11 package
find_package(X11 REQUIRED)

# Find Cairo package
find_package(PkgConfig REQUIRED)
pkg_check_modules(CAIRO REQUIRED cairo)

# Set C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)

# Include directories
include_directories(${X11_INCLUDE_DIR} ${CAIRO_INCLUDE_DIRS})

# Add the source files to the executable
add_executable(X11Overlay src/main.cpp)

target_include_directories(X11Overlay PRIVATE include)

# Link against X11 and Cairo libraries
target_link_libraries(X11Overlay ${X11_LIBRARIES} ${CAIRO_LIBRARIES})

# Set different compiler flags for Debug and Release modes
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

