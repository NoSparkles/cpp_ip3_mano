#include "RandomObject.h"
#include <cstdlib>
#include <algorithm>
#include <stdexcept>
#include <iostream>

RandomNumber::RandomNumber(RandomNumberStrategy *strategy) {
    if (strategy == nullptr) {
        throw std::invalid_argument("Klaida: strategija negali būti nullptr.");
    }
    this->strategy = strategy;
}

RandomArray::RandomArray(RandomNumberStrategy* strategy, unsigned size) {
    if (size == 0) {
        throw std::invalid_argument("Klaida: masyvo dydis turi būti didesnis už 0.");
    }
    numbers.resize(size);
    this->strategy = strategy;
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
    if (numbers.empty()) {
        throw std::invalid_argument("Klaida: masyvas yra tuščias.");
    }
    if (strategy) {
        for (unsigned i = 0; i < numbers.size(); ++i) {
            numbers[i] = strategy->generateNumber();
        }
    }
}

int RandomNumber::getNumber() const {
    return number;
}

std::vector<int> RandomArray::getArray() const {
    return numbers;
}

std::string RandomNumber::toString() const {
    return "RandomNumber: " + std::to_string(number);
}

std::string RandomArray::toString() const {
    std::string result = "RandomArray: ";
    for (const auto& num : numbers) {
        result += std::to_string(num) + " ";
    }
    return result;
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
