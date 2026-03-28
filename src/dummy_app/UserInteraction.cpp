#include "UserInteraction.h"
#include <iostream>

double UserInteraction::askQuestion(int num1, int num2, char operation, int questionNumber) {
    std::cout << "Question " << questionNumber << ": ";
    std::cout << num1 << " " << operation << " " << num2 << " = ? ";
    
    double answer;
    std::cin >> answer;
    return answer;
}

void UserInteraction::displayResult(bool isCorrect, double correctAnswer) {
    if (isCorrect) {
        std::cout << "Correct!" << std::endl;
    } else {
        std::cout << "Wrong! The correct answer is " << correctAnswer << std::endl;
    }
}

bool UserInteraction::askToContinue() {
    std::cout << std::endl;
    std::cout << "Do you want another question? (y/n): ";
    char choice;
    std::cin >> choice;
    return (choice == 'y' || choice == 'Y');
}

void UserInteraction::displayWelcome() {
    std::cout << "=== Welcome to Math Quiz ===" << std::endl;
    std::cout << std::endl;
}

void UserInteraction::displayStats(int totalQuestions, int correctCount) {
    std::cout << std::endl;
    std::cout << "=== Quiz Complete ===" << std::endl;
    std::cout << "Total Questions: " << totalQuestions << std::endl;
    std::cout << "Correct Answers: " << correctCount << std::endl;
    if (totalQuestions > 0) {
        double percentage = (static_cast<double>(correctCount) / totalQuestions) * 100;
        std::cout << "Score: " << percentage << "%" << std::endl;
    }
}
