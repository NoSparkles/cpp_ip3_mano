#include "RandomObject.h"
#include <iostream>

int main() {
    IntervalNumberStrategy intervalStrategy(1, 100);
    MonteCarloStrategy monteCarloStrategy(1, 100);

    RandomObject* obj1 = new RandomNumber(&intervalStrategy);
    RandomObject* obj2 = new RandomArray(&monteCarloStrategy, 5);

    obj1->generate(); // polymorphic call
    obj2->generate(); // polymorphic call

    if (obj1->getType() == RandomNumber::TYPE) {
        std::cout << "Random Number: " << dynamic_cast<RandomNumber*>(obj1)->getNumber() << std::endl;
    } else if (obj1->getType() == RandomArray::TYPE) {
        std::cout << "Random Array: ";
        for (int num : dynamic_cast<RandomArray*>(obj1)->getArray()) {
            std::cout << num << " ";
        }
    }

    if (obj2->getType() == RandomNumber::TYPE) {
        std::cout << "Random Number: " << dynamic_cast<RandomNumber*>(obj2)->getNumber() << std::endl;
    } else if (obj2->getType() == RandomArray::TYPE) {
        std::cout << "Random Array: ";
        for (int num : dynamic_cast<RandomArray*>(obj2)->getArray()) {
            std::cout << num << " ";
        }
    }

    delete obj1;
    delete obj2;

    return 0;
}