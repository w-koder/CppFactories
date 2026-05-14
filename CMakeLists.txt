cmake_minimum_required(VERSION 3.15)
project(CppFactories CXX)

# Set C++ standard to C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

file(GLOB_RECURSE APP_SOURCES src/dummy_app/*.cpp)
file(GLOB_RECURSE TEST_SOURCES tests/*.cpp)

# Add subdirectories
add_subdirectory(src)
add_subdirectory(tests)
