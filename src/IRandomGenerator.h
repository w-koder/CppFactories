#ifndef IRANDOM_GENERATOR_H
#define IRANDOM_GENERATOR_H

#include "Operation.h"

class IRandomGenerator {
public:
    virtual ~IRandomGenerator() = default;
    
    // Generate a random number between min and max (inclusive)
    virtual int generateNumber(int min = 1, int max = 10) = 0;
    
    // Generate a random operation
    virtual Operation generateOperation() = 0;
};

#endif // IRANDOM_GENERATOR_H
