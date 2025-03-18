class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int maxLength = 0;
    int left = 0;
    int bitmask = 0;

    for (int right = 0; right < nums.size(); ++right) {
        // If adding nums[right] causes a conflict, move the left pointer
        while ((bitmask & nums[right]) != 0) {
            bitmask ^= nums[left]; // Remove nums[left] from the window
            ++left;
        }

        // Add nums[right] to the current window
        bitmask |= nums[right];

        // Update the maximum length
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
    }
};
