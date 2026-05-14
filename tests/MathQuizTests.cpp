#include <gtest/gtest.h>

#include "dummy_app/MathQuiz.h"
#include "dummy_app/RandomGenerator.h"
#include "dummy_app/UserInteraction.h"
#include "factories/Factory.h"
#include "mocks/RandomGeneratorMock.h"
#include "mocks/UserInteractionMock.h"


class MathQuizFixture : public testing::Test {
protected:
    testing::NiceMock<RandomGeneratorMock>* mockRandomGeneratorPtr{nullptr};
    testing::NiceMock<UserInteractionMock>* mockUserInteractionPtr{nullptr};

    void SetUp() override {
        Factory<IRandomGenerator, RandomGenerator>::getInstance().setCreator([this]() -> std::unique_ptr<IRandomGenerator> {
            auto mock = std::make_unique<testing::NiceMock<RandomGeneratorMock>>();
            mockRandomGeneratorPtr = mock.get();
            return mock;
        });
        Factory<IUserInteraction, UserInteraction>::getInstance().setCreator([this]() -> std::unique_ptr<IUserInteraction> {
            auto mock = std::make_unique<testing::NiceMock<UserInteractionMock>>();
            mockUserInteractionPtr = mock.get();
            return mock;
        });
    }

    void TearDown() override {
        Factory<IRandomGenerator, RandomGenerator>::getInstance().setCreator(nullptr);
        Factory<IUserInteraction, UserInteraction>::getInstance().setCreator(nullptr);
    }
};

TEST_F(MathQuizFixture, ConstructorTest)
{
    EXPECT_EQ(mockRandomGeneratorPtr, nullptr);
    EXPECT_EQ(mockUserInteractionPtr, nullptr);
    MathQuiz q;
    EXPECT_NE(mockRandomGeneratorPtr, nullptr);
    EXPECT_NE(mockUserInteractionPtr, nullptr);
}

TEST_F(MathQuizFixture, RunTestTrivial)
{
    MathQuiz q;
    q.run();
}

TEST_F(MathQuizFixture, RunTest)
{
    // Question 1: 5 + 3 = 8
    // Question 2: 4 * 2 = 8
    MathQuiz q;
    
    EXPECT_CALL(*mockRandomGeneratorPtr, generateNumber(testing::_, testing::_))
        .WillOnce(testing::Return(5))   // num1 for Q1
        .WillOnce(testing::Return(3))   // num2 for Q1
        .WillOnce(testing::Return(4))   // num1 for Q2
        .WillOnce(testing::Return(2));  // num2 for Q2
    
    EXPECT_CALL(*mockRandomGeneratorPtr, generateOperation())
        .WillOnce(testing::Return(Operation::Add))
        .WillOnce(testing::Return(Operation::Multiply));
    
    EXPECT_CALL(*mockUserInteractionPtr, displayWelcome())
        .Times(1);
    
    EXPECT_CALL(*mockUserInteractionPtr, askQuestion(testing::_, testing::_, testing::_, testing::_))
        .WillOnce(testing::Return(8.0))   // Correct answer for Q1: 5 + 3 = 8
        .WillOnce(testing::Return(8.0));  // Correct answer for Q2: 4 * 2 = 8
    
    EXPECT_CALL(*mockUserInteractionPtr, displayResult(true, 8.0))
        .Times(2);
    
    EXPECT_CALL(*mockUserInteractionPtr, askToContinue())
        .WillOnce(testing::Return(true))   // Continue after Q1
        .WillOnce(testing::Return(false)); // Stop after Q2
    
    EXPECT_CALL(*mockUserInteractionPtr, displayStats(2, 2))
        .Times(1);
    
    double score = q.run();
    
    ASSERT_EQ(score, 100.0); // Both answers correct
}