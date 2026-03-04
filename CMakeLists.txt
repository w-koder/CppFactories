cmake_minimum_required(VERSION 3.15)
project(CppFactories CXX)

find_package(GTest REQUIRED gtest_main)

add_executable(${PROJECT_NAME} src/main.cpp)
target_sources(${PROJECT_NAME} PRIVATE src/main.cpp)
add_executable(${PROJECT_NAME}_test tests/gtest_main.cpp)
target_sources(${PROJECT_NAME}_test PRIVATE tests/gtest_main.cpp)
target_sources(${PROJECT_NAME}_test PRIVATE tests/hello_gtest.cpp)
target_link_libraries(${PROJECT_NAME}_test ${GTest_LIBRARIES})
target_include_directories(${PROJECT_NAME}_test PRIVATE ${GTest_INCLUDE_DIRS})