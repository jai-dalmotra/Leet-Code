class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long left = 1, right = *max_element(candies.begin(), candies.end());
        int result = 0;

        // Helper function to check if we can distribute "mid" candies to "k" children
        auto canDistribute = [&](long long mid) {
            long long count = 0;
            for (int candy : candies) {
                count += candy / mid; // Number of children that can get "mid" candies from this pile
                if (count >= k) return true; // Early exit if we already have enough
            }
            return count >= k;
        };

        while (left <= right) {
            long long mid = left + (right - left) / 2;

            if (canDistribute(mid)) {
                result = mid;        // Update result since "mid" is a valid answer
                left = mid + 1;      // Try for a larger answer
            } else {
                right = mid - 1;     // Try for a smaller answer
            }
        }

        return result;
    }
};
