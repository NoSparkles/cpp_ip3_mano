#include "RandomObject.h"

int main() {
    IntervalNumberStrategy intervalStrategy(1, 100);
    MonteCarloStrategy monteCarloStrategy(1, 100);

    RandomObject* obj1 = new RandomNumber(&intervalStrategy);
    RandomObject* obj2 = new RandomArray(&monteCarloStrategy, 5);

    obj1->generate();
    obj2->generate();

    delete obj1;
    delete obj2;

    return 0;
}