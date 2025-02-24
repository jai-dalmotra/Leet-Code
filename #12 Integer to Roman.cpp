class Solution {
public:
    string intToRoman(int num) {
        // Create mappings of Roman numerals with their respective values
        vector<pair<int, string>> romanMap = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"},
            {1, "I"}
        };

        string result = "";

        for (auto &pair : romanMap) {
            while (num >= pair.first) {
                result += pair.second; // Append the corresponding Roman numeral
                num -= pair.first; // Subtract the value from the number
            }
        }
        return result;
    }
};
