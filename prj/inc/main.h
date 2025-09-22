
#include <string>

namespace TelCoColorCoder {

    enum MajorColor { WHITE, RED, BLACK, YELLOW, VIOLET };
    enum MinorColor { BLUE, ORANGE, GREEN, BROWN, SLATE };

    // Extern declarations for color name arrays (defined in .cpp)
    extern const char* const MajorColorNames[];
    extern const char* const MinorColorNames[];

    // Counts (constexpr so usable in compile-time contexts)
    constexpr int kNumberOfMajorColors = 5;
    constexpr int kNumberOfMinorColors = 5;
    constexpr int kMaxPairNumber = kNumberOfMajorColors * kNumberOfMinorColors; // 25

    class ColorPair {
    private:
        MajorColor majorColor;
        MinorColor minorColor;
    public:
        ColorPair(MajorColor major, MinorColor minor);
        MajorColor getMajor() const;
        MinorColor getMinor() const;
        std::string ToString() const;
    };

    ColorPair GetColorFromPairNumber(int pairNumber); // throws std::out_of_range on invalid
    int GetPairNumberFromColor(MajorColor major, MinorColor minor);
    bool TryGetColorFromPairNumber(int pairNumber, ColorPair& outPair); // no-throw
    std::string GetReferenceManual();
}
