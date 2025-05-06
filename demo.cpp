#include "RandomObject.h"
#include <iostream>

int main() {
    IntervalNumberStrategy intervalStrategy(1, 100);
    MonteCarloStrategy monteCarloStrategy(1, 100);

    RandomObject* obj1 = new RandomNumber(&intervalStrategy); // polimorfizmas
    RandomObject* obj2 = new RandomArray(&monteCarloStrategy, 5); // polimorfizmas

    obj1->generate();
    obj2->generate();

    std::cout << obj1->toString() << std::endl;
    std::cout << obj2->toString() << std::endl;

    delete obj1;
    delete obj2;

    return 0;
}