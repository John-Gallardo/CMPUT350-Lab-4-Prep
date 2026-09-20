#include <cassert>  // assert
#include <cstddef>  // size_t
#include <cstdint>  // uint64_t, uint32_t
#include <bitset>
#include <iostream>

// Expands the binary representation of input by a factor of scale.
// e.g., expand(0b1111ull, 3) == 0b001001001001
uint64_t expand(uint64_t input, uint32_t scale) {
    // NOTE: this should technically be O(wordsize) since the upper bound of numBits is 64
    // i.e we cost for 1. and 2. is O(wordsize) + O(wordsize) = O(2wordsize) = O(wordsize)

    // 1. we count number of bits in input. eg. 0b1111 -> 4 bits
    int numBits{};
    uint64_t inputCopy{input};
    while (inputCopy) {
        numBits++;
        inputCopy >>= 1;
    }

    // 2. set bits
    uint64_t expandedBits{0};
    int currBitToSet{};  // 0-63
    for (int i{0}; i < numBits && currBitToSet < 64; i++) {
        uint64_t currVal{input & 0x1};
        expandedBits |= currVal << currBitToSet;
        // scale - 1 by definition, + 1 since we are moving onto the next bit
        currBitToSet += (scale - 1) + 1;
    }
    return expandedBits;
}

int main() {
    // test here...
    uint64_t res1{expand(0b1111, 3)};
    // reference for bit printing https://stackoverflow.com/questions/7349689/how-to-print-using-cout-a-number-in-binary-form
    std::cout << std::bitset<64>(res1) << '\n';
    assert(res1 == 0b001001001001);

    uint64_t res2{expand(0b0101, 2)};
    std::cout << std::bitset<64>(res2) << '\n';
    assert(res2 == 0b00010001);

    return 0;
}
