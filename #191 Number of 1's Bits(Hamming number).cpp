//using buily_in FUnction Time Complexity- O(1)
class Solution {
public:
    int hammingWeight(int n) {
        
        return __builtin_popcount(n);
    }
};
