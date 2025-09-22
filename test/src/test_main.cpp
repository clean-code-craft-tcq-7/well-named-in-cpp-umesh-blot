#include <iostream>
#include <cassert>
#include <main.h>

void testNumberToPair(int pairNumber,
    TelCoColorCoder::MajorColor expectedMajor,
    TelCoColorCoder::MinorColor expectedMinor)
{
    TelCoColorCoder::ColorPair colorPair =
        TelCoColorCoder::GetColorFromPairNumber(pairNumber);
    std::cout << "Got pair " << colorPair.ToString() << std::endl;
    assert(colorPair.getMajor() == expectedMajor);
    assert(colorPair.getMinor() == expectedMinor);
}

void testPairToNumber(
    TelCoColorCoder::MajorColor major,
    TelCoColorCoder::MinorColor minor,
    int expectedPairNumber)
{
    int pairNumber = TelCoColorCoder::GetPairNumberFromColor(major, minor);
    std::cout << "Got pair number " << pairNumber << std::endl;
    assert(pairNumber == expectedPairNumber);
}

// Additional test helpers
static void testOutOfRange() {
    bool threw = false;
    try {
        (void)TelCoColorCoder::GetColorFromPairNumber(0); // invalid
    } catch(const std::out_of_range&) { threw = true; }
    assert(threw && "Expected out_of_range for pair 0");

    threw = false;
    try {
        (void)TelCoColorCoder::GetColorFromPairNumber(TelCoColorCoder::kMaxPairNumber + 1); // invalid
    } catch(const std::out_of_range&) { threw = true; }
    assert(threw && "Expected out_of_range for pair > max");
}

static void testReferenceManual() {
    std::string manual = TelCoColorCoder::GetReferenceManual();
    // Spot check a few known entries
    assert(manual.find("1\t| White\t| Blue") != std::string::npos);
    assert(manual.find("25\t| Violet\t| Slate") != std::string::npos);
    std::cout << "Reference manual generated:\n" << manual << std::endl;
}

// Expose new tests to main (optional) via weak linkage pattern if needed
void runAdditionalTests() {
    testOutOfRange();
    testReferenceManual();
}