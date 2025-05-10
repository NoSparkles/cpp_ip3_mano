#include "RandomObject.h"
#include <cstdlib>
#include <algorithm>
#include <stdexcept>
#include <iostream>

int RandomObject::getType() const {
    return this->type;
}

RandomNumber::RandomNumber(RandomNumberStrategy *strategy) {
    if (strategy == nullptr) {
        throw std::invalid_argument("Strategy cannot be nullptr.");
    }
    this->strategy = strategy;
    this->type = RandomNumber::TYPE;
}

void RandomNumber::generate() {
    if (this->strategy) {
        this->number = this->strategy->generateNumber();
    }
    else {
        this->number = 0;
    }
}

void *RandomNumber::get() {
    return &this->number;
}

std::string RandomNumber::toString() const {
    return "RandomNumber: " + std::to_string(this->number);
}

int RandomNumber::getNumber() const {
    return this->number;
}

RandomArray::RandomArray(RandomNumberStrategy* strategy, unsigned size) {
    if (size == 0) {
        throw std::invalid_argument("Array size must be greater than 0.");
    }
    this->numbers.resize(size);
    this->strategy = strategy;
    this->type = RandomArray::TYPE;
}

void RandomArray::generate() {
    if (this->numbers.empty()) {
        throw std::invalid_argument("Array is empty. Cannot generate numbers.");
    }
    if (this->strategy) {
        for (unsigned i = 0; i < this->numbers.size(); ++i) {
            this->numbers[i] = this->strategy->generateNumber();
        }
    }
}

void *RandomArray::get() {
    return &numbers;
}

std::string RandomArray::toString() const {
    std::string result = "RandomArray: ";
    for (const auto& num : numbers) {
        result += std::to_string(num) + " ";
    }
    return result;
}

std::vector<int> RandomArray::getArray() const {
    return this->numbers;
}

RandomNumberStrategy::RandomNumberStrategy(int min, int max, unsigned seed) {
    srand(seed);
    if (min >= max) {
        throw std::invalid_argument("min should be less than max.");
    }
    this->min = min;
    this->max = max;
}

IntervalNumberStrategy::IntervalNumberStrategy(int min, int max, unsigned seed) : RandomNumberStrategy(min, max, seed) {}

int IntervalNumberStrategy::generateNumber() {
    return rand() % (max - min + 1) + min;
}

MonteCarloStrategy::MonteCarloStrategy(int min, int max, unsigned seed) : RandomNumberStrategy(min, max, seed) {}

int MonteCarloStrategy::generateNumber() {
    int iterations = 100;
    int acceptedNumbers = 0;
    int generatedNumber = 0;

    for (int i = 0; i < iterations; ++i) {
        int candidate = rand() % (this->max - this->min + 1) + this->min;
        double probability = static_cast<double>(rand()) / RAND_MAX;

        if (probability < 0.5) { 
            generatedNumber = candidate;
            ++acceptedNumbers;
        }
    }

    if (acceptedNumbers == 0) return this->min;
    return generatedNumber;
}