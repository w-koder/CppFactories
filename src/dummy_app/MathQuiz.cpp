#include "MathQuiz.h"
#include "RandomGenerator.h"
#include "UserInteraction.h"
#include "factories/Factory.h"

MathQuiz::MathQuiz()
    : randomGenerator(Factory<IRandomGenerator, RandomGenerator>::getInstance().createObject()),
      userInteraction(Factory<IUserInteraction, UserInteraction>::getInstance().createObject()),
      correctCount(0),
      totalQuestions(0)
{
}

double MathQuiz::run()
{
    userInteraction->displayWelcome();

    bool running = true;
    while (running)
    {
        // Generate random numbers and operation
        int num1 = randomGenerator->generateNumber(1, 10);
        int num2 = randomGenerator->generateNumber(1, 10);
        Operation operation = randomGenerator->generateOperation();

        // Get question details
        char opChar = getOperationChar(operation);
        double correctAnswer = calculateAnswer(num1, num2, operation);

        // Ask question and get user answer
        double userAnswer = userInteraction->askQuestion(num1, num2, opChar, totalQuestions + 1);

        totalQuestions++;

        // Check answer
        bool isCorrect = checkAnswer(userAnswer, correctAnswer, operation);
        if (isCorrect)
        {
            correctCount++;
        }

        // Display result
        userInteraction->displayResult(isCorrect, correctAnswer);

        // Ask to continue
        running = userInteraction->askToContinue();
    }

    // Display final statistics
    userInteraction->displayStats(totalQuestions, correctCount);

    if (totalQuestions == 0)
    {
        return 0.0;
    }
    return (static_cast<double>(correctCount) / totalQuestions) * 100.0;
}

char MathQuiz::getOperationChar(Operation op)
{
    switch (op)
    {
    case Operation::Add:
        return '+';
    case Operation::Subtract:
        return '-';
    case Operation::Multiply:
        return '*';
    case Operation::Divide:
        return '/';
    }
    return '?'; // Should never reach here
}

double MathQuiz::calculateAnswer(int num1, int num2, Operation op)
{
    switch (op)
    {
    case Operation::Add:
        return num1 + num2;
    case Operation::Subtract:
        return num1 - num2;
    case Operation::Multiply:
        return num1 * num2;
    case Operation::Divide:
        return static_cast<double>(num1) / num2;
    }
    return 0.0; // Should never reach here
}

bool MathQuiz::checkAnswer(double userAnswer, double correctAnswer, Operation op)
{
    // For division, use tolerance due to floating point precision
    if (op == Operation::Divide)
    {
        return (userAnswer > correctAnswer - 0.01 && userAnswer < correctAnswer + 0.01);
    }
    return (userAnswer == correctAnswer);
}

