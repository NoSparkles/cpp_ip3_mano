#pragma once

#include <vector>
#include <string>

class RandomNumberStrategy {
public:
    virtual int generateNumber() = 0;
};

class IntervalNumberStrategy : public RandomNumberStrategy {
private:
    int min, max;
public:
    IntervalNumberStrategy(int min, int max);
    int generateNumber() override;
};

class MonteCarloStrategy : public RandomNumberStrategy {
private:
    int min, max;
public:
    MonteCarloStrategy(int min, int max);
    int generateNumber() override;
};

class RandomObject {
protected:
    RandomNumberStrategy* strategy;
public:
    virtual void generate() = 0;
    virtual std::string toString() const = 0;
};

class RandomNumber : public RandomObject {
private:
    int number;
public:
    RandomNumber(RandomNumberStrategy* strategy);
    void generate() override;
    std::string toString() const override;
    int getNumber() const;
};

class RandomArray : public RandomObject {
private:
    std::vector<int> numbers;
public:
    RandomArray(RandomNumberStrategy* strategy, unsigned size);
    void generate() override;
    std::string toString() const override;
    std::vector<int> getArray() const;
};