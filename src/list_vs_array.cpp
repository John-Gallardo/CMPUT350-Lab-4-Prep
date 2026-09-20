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
    Timer listTimer{};
    for (size_t i{0}; i < SIZE; i++) {
        linkedList.push_back(rng());
    }
    std::cout << "Linked List: " << listTimer.click<Timer::Millis>() << "ms\n";

    return 0;
}
