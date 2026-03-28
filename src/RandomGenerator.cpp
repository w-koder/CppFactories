#include "RandomGenerator.h"
#include <cstdlib>
#include <ctime>

RandomGenerator::RandomGenerator() {
    srand(time(0));  // Seed random number generator
}

int RandomGenerator::generateNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

Operation RandomGenerator::generateOperation() {
    int opIndex = rand() % 4;
    return static_cast<Operation>(opIndex);
}
