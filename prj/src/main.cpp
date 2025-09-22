#include <iostream>
#include <cassert>
#include <main.h>
#include <test_main.h>

// Forward decl for new tests in test_main.cpp
void runAdditionalTests();

int main() {
    testNumberToPair(4, TelCoColorCoder::WHITE, TelCoColorCoder::BROWN);
    testNumberToPair(5, TelCoColorCoder::WHITE, TelCoColorCoder::SLATE);

    testPairToNumber(TelCoColorCoder::BLACK, TelCoColorCoder::ORANGE, 12);
    testPairToNumber(TelCoColorCoder::VIOLET, TelCoColorCoder::SLATE, 25);

    // Run enhanced tests
    runAdditionalTests();

    std::cout << "\nColor Code Reference Manual:\n";
    std::cout << TelCoColorCoder::GetReferenceManual() << std::endl;
    std::cout << "All tests passed." << std::endl;
    return 0;
}
