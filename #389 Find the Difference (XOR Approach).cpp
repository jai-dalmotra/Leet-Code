class Solution {
public:
    char findTheDifference(string s, string t) {
        char result = 0;

        // XOR all characters in s
        for (char c : s) result ^= c;

        // XOR all characters in t
        for (char c : t) result ^= c;

        return result; // The remaining char is the extra one
    }
};
