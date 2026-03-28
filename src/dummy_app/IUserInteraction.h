#ifndef IUSER_INTERACTION_H
#define IUSER_INTERACTION_H

class IUserInteraction {
public:
    virtual ~IUserInteraction() = default;
    
    // Display a question and get user's numeric answer
    virtual double askQuestion(int num1, int num2, char operation, int questionNumber) = 0;
    
    // Display whether answer is correct
    virtual void displayResult(bool isCorrect, double correctAnswer) = 0;
    
    // Ask if user wants to continue
    virtual bool askToContinue() = 0;
    
    // Display welcome message
    virtual void displayWelcome() = 0;
    
    // Display final statistics
    virtual void displayStats(int totalQuestions, int correctCount) = 0;
};

#endif // IUSER_INTERACTION_H
