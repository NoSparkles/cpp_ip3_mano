/*
    Faile RandomObject.h atitinkamoje vietoje sukurkite klasę IntervalPrimeStrategy, 
    kuri paveldės RandomNumberStrategy klasę.
    Ši klasė turės du narius: min ir max, kurie bus intervalas,
    ir metodą generateNumber(), kuris sugeneruos pirminį skaičių iš nurodyto intervalo.
    Implementuokite šią klasę faile RandomObject.cpp.
*/
#include "RandomObject.h"

#include <iostream>
#include <cassert>
#include <vector>

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

// Testas: ar generuojami skaičiai yra pirminiai?
void testPrimeNumberGeneration() {
    IntervalPrimeStrategy strategy(10, 50); // Sukuriame strategiją su intervalu [10, 50]
    for (int i = 0; i < 10; ++i) {
        int num = strategy.generateNumber();
        assert(isPrime(num) && "Klaida: sugeneruotas skaičius nėra pirminis!");
    }
    std::cout << "Testas pavyko: visi sugeneruoti skaičiai yra pirminiai.\n";
}

// Testas: kai intervale nėra pirminių skaičių (pvz., [90, 100])
void testNoPrimesInInterval() {
    IntervalPrimeStrategy strategy(90, 100);
    int num = strategy.generateNumber();
    assert(num == -1 && "Klaida: turėjo būti grąžinta -1, nes intervale nėra pirminių skaičių!");
    std::cout << "Testas pavyko: intervale nėra pirminių skaičių.\n";
}

// Testas: kraštutiniai atvejai
void testEdgeCases() {
    IntervalPrimeStrategy strategy1(2, 2); // Tik vienas skaičius (2)
    assert(strategy1.generateNumber() == 2 && "Klaida: turėjo būti grąžintas 2!");

    IntervalPrimeStrategy strategy2(1000, 1100); // Didelis intervalas, reikia surasti pirminį
    int num = strategy2.generateNumber();
    assert(isPrime(num) && "Klaida: sugeneruotas skaičius nėra pirminis!");
    
    std::cout << "Testas pavyko: kraštutiniai atvejai veikė teisingai.\n";
}

int main() {
    testPrimeNumberGeneration();
    testNoPrimesInInterval();
    testEdgeCases();
    return 0;
}