#ifndef USER_INTERACTION_MOCK_H
#define USER_INTERACTION_MOCK_H

#include <gmock/gmock.h>
#include "../../src/dummy_app/IUserInteraction.h"

class UserInteractionMock : public IUserInteraction {
public:
    MOCK_METHOD(double, askQuestion, (int num1, int num2, char operation, int questionNumber), (override));
    MOCK_METHOD(void, displayResult, (bool isCorrect, double correctAnswer), (override));
    MOCK_METHOD(bool, askToContinue, (), (override));
    MOCK_METHOD(void, displayWelcome, (), (override));
    MOCK_METHOD(void, displayStats, (int totalQuestions, int correctCount), (override));
};

#endif // USER_INTERACTION_MOCK_H
