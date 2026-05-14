#include <gtest/gtest.h>
#include <expected>

#include "dummy_app/MathQuiz.h"

TEST(MyTestSuite, MyTestCase)
{
    EXPECT_EQ(1, 1);
    std::expected<int, std::string> result = 42;
    EXPECT_TRUE(result.has_value());
}


TEST(MyTestSuite, MathQuizTest)
{
    MathQuiz q;
    EXPECT_EQ(1, 1);
}