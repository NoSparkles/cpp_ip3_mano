#pragma once

#include <vector>
#include <string>

class RandomNumberStrategy;

class RandomObject {
protected:
    RandomNumberStrategy* strategy;
    int type;
public:
    virtual void generate() = 0;
    virtual void *get() = 0;
    int getType() const;
    virtual std::string toString() const = 0;
};

class RandomNumber : public RandomObject {
private:
    int number;
public:
    const static int TYPE = 0;

    RandomNumber(RandomNumberStrategy* strategy);
    void generate() override;
    void* get() override;
    std::string toString() const override;
    int getNumber() const;
};

class RandomArray : public RandomObject {
private:
    std::vector<int> numbers;
public:
    const static int TYPE = 1;

    RandomArray(RandomNumberStrategy* strategy, unsigned size);
    void generate() override;
    void* get() override;
    std::string toString() const override;
    std::vector<int> getArray() const;
};

class RandomNumberStrategy {
protected:
    int min, max;
public:
    RandomNumberStrategy(int min, int max, unsigned seed);
    virtual int generateNumber() = 0;
};

class IntervalNumberStrategy : public RandomNumberStrategy {
public:
    IntervalNumberStrategy(int min, int max, unsigned seed);
    int generateNumber() override;
};

class MonteCarloStrategy : public RandomNumberStrategy {
public:
    MonteCarloStrategy(int min, int max, unsigned seed);
    int generateNumber() override;
};