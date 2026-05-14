# Define the test executable
add_executable(g_tests 
    ${TEST_SOURCES}
)

# Link against GTest and the project library
target_link_libraries(g_tests 
    PRIVATE 
        GTest::gtest_main 
        dummy_app_lib
)

# Enable CTest discovery
include(GoogleTest)
gtest_discover_tests(g_tests)
