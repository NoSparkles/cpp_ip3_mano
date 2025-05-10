#include "RandomObject.h"
#include <iostream>

int main() {
    IntervalNumberStrategy intervalStrategy(5, 50, 55);
    MonteCarloStrategy monteCarloStrategy(1, 100, 3);

    RandomObject* obj1 = new RandomNumber(&intervalStrategy);
    RandomObject* obj2 = new RandomArray(&monteCarloStrategy, 5);

    obj1->generate(); // polymorphic call
    obj2->generate(); // polymorphic call

    if (obj1->getType() == RandomNumber::TYPE) {
        int* numPtr = static_cast<int*>(obj1->get());
        std::cout << "Random Number: " << *numPtr << std::endl;
    } else if (obj1->getType() == RandomArray::TYPE) {
        std::vector<int>* arrPtr = static_cast<std::vector<int>*>(obj1->get());
        std::cout << "Random Array: ";
        for (int num : *arrPtr) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    if (obj2->getType() == RandomNumber::TYPE) {
        int* numPtr = static_cast<int*>(obj2->get());
        std::cout << "Random Number: " << *numPtr << std::endl;
    } else if (obj2->getType() == RandomArray::TYPE) {
        std::vector<int>* arrPtr = static_cast<std::vector<int>*>(obj2->get());
        std::cout << "Random Array: ";
        for (int num : *arrPtr) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    delete obj1;
    delete obj2;

    return 0;
}