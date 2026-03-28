#ifndef USER_INTERACTION_H
#define USER_INTERACTION_H

#include "IUserInteraction.h"

class UserInteraction : public IUserInteraction {
public:
    UserInteraction() = default;
    
    // Display a question and get user's numeric answer
    double askQuestion(int num1, int num2, char operation, int questionNumber) override;
    
    // Display whether answer is correct
    void displayResult(bool isCorrect, double correctAnswer) override;
    
    // Ask if user wants to continue
    bool askToContinue() override;
    
    // Display welcome message
    void displayWelcome() override;
    
    // Display final statistics
    void displayStats(int totalQuestions, int correctCount) override;
};

#endif // USER_INTERACTION_H
