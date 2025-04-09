class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
    int min_ops = INT_MAX;

    for (int i = 0; i <= n; ++i) {
        unordered_set<int> seen;
        bool is_unique = true;

        // Check if suffix starting from index i is unique
        for (int j = i; j < n; ++j) {
            if (seen.count(nums[j])) {
                is_unique = false;
                break;
            }
            seen.insert(nums[j]);
        }

        if (is_unique) {
            int ops = (i + 2) / 3; // Equivalent to ceil(i / 3.0)
            min_ops = min(min_ops, ops);
        }
    }

    return min_ops;
    }
};
