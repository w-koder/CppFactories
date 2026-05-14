# Exclude main.cpp from the library so it doesn't conflict with gtest_main
add_library(dummy_app_lib 
    ${APP_SOURCES}
)

# Define public include paths
target_include_directories(dummy_app_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# 2. Define the actual application
add_executable(dummy_app main.cpp)
target_link_libraries(dummy_app PRIVATE dummy_app_lib)
