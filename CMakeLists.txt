cmake_minimum_required(VERSION 3.15)
project(CppFactories CXX)

# Define binaries names
set(BINARY_NAME dummy_app)
set(TEST_BINARY_NAME g_test)

# Collect all source files
file(GLOB_RECURSE APP_SOURCES src/*.cpp)
file(GLOB_RECURSE TEST_SOURCES tests/*.cpp)

# Add the main application executable
add_executable(${BINARY_NAME} ${APP_SOURCES})

# Add the test executable
add_executable(${TEST_BINARY_NAME} ${TEST_SOURCES})

# Link the test executable with GTest
find_package(GTest REQUIRED gtest_main)

target_link_libraries(${TEST_BINARY_NAME} ${GTest_LIBRARIES})
target_include_directories(${TEST_BINARY_NAME} PRIVATE ${GTest_INCLUDE_DIRS})
