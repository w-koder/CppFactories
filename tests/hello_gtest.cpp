#include <gtest/gtest.h>
#include <expected>

TEST(MyTestSuite, MyTestCase)
{
    EXPECT_EQ(1, 1);
    std::expected<int, std::string> result = 42;
    EXPECT_TRUE(result.has_value());
}