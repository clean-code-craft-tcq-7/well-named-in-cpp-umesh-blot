#include <stdexcept>
#include <sstream>
#include <string>
#include <main.h>

namespace TelCoColorCoder {

// Define color name arrays
const char* const MajorColorNames[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* const MinorColorNames[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

ColorPair::ColorPair(MajorColor major, MinorColor minor)
    : majorColor(major), minorColor(minor) {}

MajorColor ColorPair::getMajor() const { return majorColor; }
MinorColor ColorPair::getMinor() const { return minorColor; }

std::string ColorPair::ToString() const {
    std::string colorPairStr = MajorColorNames[majorColor];
    colorPairStr += ' ';
    colorPairStr += MinorColorNames[minorColor];
    return colorPairStr;
}

ColorPair GetColorFromPairNumber(int pairNumber) {
    if (pairNumber < 1 || pairNumber > kMaxPairNumber) {
        throw std::out_of_range("Pair number out of valid range 1-" + std::to_string(kMaxPairNumber));
    }
    int zeroBasedPairNumber = pairNumber - 1;
    MajorColor majorColor = static_cast<MajorColor>(zeroBasedPairNumber / kNumberOfMinorColors);
    MinorColor minorColor = static_cast<MinorColor>(zeroBasedPairNumber % kNumberOfMinorColors);
    return ColorPair(majorColor, minorColor);
}

int GetPairNumberFromColor(MajorColor major, MinorColor minor) {
    return major * kNumberOfMinorColors + minor + 1;
}

bool TryGetColorFromPairNumber(int pairNumber, ColorPair& outPair) {
    if (pairNumber < 1 || pairNumber > kMaxPairNumber) {
        return false;
    }
    outPair = GetColorFromPairNumber(pairNumber); // validated
    return true;
}

std::string GetReferenceManual() {
    std::ostringstream oss;
    oss << "PairNumber | Major  | Minor" << '\n';
    oss << "-----------+--------+-------" << '\n';
    for (int pairNumber = 1; pairNumber <= kMaxPairNumber; ++pairNumber) {
        ColorPair p = GetColorFromPairNumber(pairNumber);
        oss << pairNumber << "\t| " << MajorColorNames[p.getMajor()] << "\t| " << MinorColorNames[p.getMinor()] << '\n';
    }
    return oss.str();
}

} // namespace TelCoColorCoder
