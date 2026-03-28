#ifndef MATH_QUIZ_H
#define MATH_QUIZ_H

#include "Operation.h"
#include "IRandomGenerator.h"
#include "IUserInteraction.h"

#include <memory>

class MathQuiz {
public:
    MathQuiz();
    
    // Run the quiz - returns the score as percentage
    double run();
    
private:
    std::unique_ptr<IRandomGenerator> randomGenerator;
    std::unique_ptr<IUserInteraction> userInteraction;
    int correctCount;
    int totalQuestions;
    
    // Helper function to get the character representation of an operation
    char getOperationChar(Operation op);
    
    // Helper function to calculate the correct answer
    double calculateAnswer(int num1, int num2, Operation op);
    
    // Helper function to check if answer is correct
    bool checkAnswer(double userAnswer, double correctAnswer, Operation op);
};

#endif // MATH_QUIZ_H
