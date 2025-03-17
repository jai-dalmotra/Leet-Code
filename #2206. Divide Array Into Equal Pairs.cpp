class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> counts;
    for (int num : nums) {
        counts[num]++;
    }

    // Check if all counts are even
    for (const auto& pair : counts) {
        if (pair.second % 2 != 0) {
            return false;
        }
    }

    return true;
    }
};
