class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        int result = right;

        // Helper function to check if we can rob at least k houses with capability <= mid
        auto canRob = [&](int mid) {
            int count = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] <= mid) {
                    count++;
                    i++; // Skip the next house to avoid adjacent robbery
                }
            }
            return count >= k;
        };

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canRob(mid)) {
                result = mid;       // Update result since "mid" is a valid capability
                right = mid - 1;    // Try for a smaller capability
            } else {
                left = mid + 1;     // Try for a larger capability
            }
        }

        return result;
    }
};
