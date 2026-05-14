#ifndef RANDOM_GENERATOR_H
#define RANDOM_GENERATOR_H

#include "IRandomGenerator.h"

class RandomGenerator : public IRandomGenerator {
public:
    RandomGenerator();
    
    // Generate a random number between min and max (inclusive)
    int generateNumber(int min, int max) override;
    
    // Generate a random operation
    Operation generateOperation() override;
    
private:
    // Seed is done in constructor
};

#endif // RANDOM_GENERATOR_H
