#include <cstddef>  // size_t

#include "timer.h"
#include <list>
#include <vector>
#include <random> 
#include <iostream>

constexpr size_t SIZE = 16000000;

int main() {
    // test here...
    std::mt19937_64 rng(0);

    // 1. Linked list test
    std::list<uint64_t> linkedList{};
    Timer timer{};
    for (size_t i{0}; i < SIZE; i++) {
        linkedList.push_back(rng());
    }
    std::cout << "Linked List: " << timer.click<Timer::Millis>() << "ms\n";

    // 2. Vector test without reserve
    std::vector<uint64_t> vectorTestNoReserve{};
    for (size_t i{0}; i < SIZE; i++) {
        vectorTestNoReserve.push_back(rng());
    }
    std::cout << "Vector Test No Reserve: " << timer.click<Timer::Millis>() << "ms\n";

    // 3. Vector test with reserve
    std::vector<uint64_t> vectorTestWithReserve{};
    vectorTestWithReserve.reserve(SIZE);
    for (size_t i{0}; i < SIZE; i++) {
        vectorTestWithReserve.push_back(rng());
    }
    std::cout << "Vector Test With Reserve: " << timer.click<Timer::Millis>() << "ms\n";

    return 0;
}
