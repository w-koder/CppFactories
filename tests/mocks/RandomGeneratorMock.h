#ifndef RANDOM_GENERATOR_MOCK_H
#define RANDOM_GENERATOR_MOCK_H

#include <gmock/gmock.h>
#include "dummy_app/IRandomGenerator.h"

class RandomGeneratorMock : public IRandomGenerator {
public:
    MOCK_METHOD(int, generateNumber, (int min, int max), (override));
    MOCK_METHOD(Operation, generateOperation, (), (override));
};

#endif // RANDOM_GENERATOR_MOCK_H
