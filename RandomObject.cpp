#include "RandomObject.h"
#include <cstdlib>
#include <algorithm>
#include <stdexcept>

RandomNumber::RandomNumber(RandomNumberStrategy *strategy) {
    if (strategy == nullptr) {
        throw std::invalid_argument("Klaida: strategija negali būti nullptr.");
    }
    this->strategy = strategy;
}

RandomNumber::~RandomNumber() {
    //strategy = nullptr;
}

RandomArray::RandomArray(RandomNumberStrategy* strategy, unsigned size) {
    if (size == 0) {
        throw std::invalid_argument("Klaida: masyvo dydis turi būti didesnis už 0.");
    }
    numbers.reserve(size);
}

RandomArray::~RandomArray() {
    //strategy = nullptr;
}

void RandomNumber::generate() {
    if (strategy) {
        number = strategy->generateNumber();
    }
    else {
        number = 0;
    }
}

void RandomArray::generate() {
    if (strategy) {
        numbers.clear();
        for (unsigned i = 0; i < numbers.size(); ++i) {
            numbers.push_back(strategy->generateNumber());
        }
    }
}

IntervalNumberStrategy::IntervalNumberStrategy(int min, int max) : min(min), max(max) {
    if (min >= max) {
        throw std::invalid_argument("Klaida: min turi būti mažesnis už max.");
    }
}

int IntervalNumberStrategy::generateNumber() {
    return rand() % (max - min + 1) + min;
}

MonteCarloStrategy::MonteCarloStrategy(int min, int max) : min(min), max(max) {
    if (min >= max) {
        throw std::invalid_argument("Klaida: min turi būti mažesnis už max.");
    }
}

int MonteCarloStrategy::generateNumber() {
    int iterations = 100;
    int acceptedNumbers = 0;
    int generatedNumber = 0;

    for (int i = 0; i < iterations; ++i) {
        int candidate = rand() % (max - min + 1) + min;
        double probability = static_cast<double>(rand()) / RAND_MAX;

        if (probability < 0.5) { 
            generatedNumber = candidate;
            ++acceptedNumbers;
        }
    }

    if (acceptedNumbers == 0) return min;
    return generatedNumber;
}
