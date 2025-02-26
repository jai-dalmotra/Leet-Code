// fixed sliding window:update sum by removing left element and adding right element --To optimize the o(n^2) solution to o(n)
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = 0;
        int n = nums.size();
        long long sum = 0;

        // Compute the sum of the first k elements
        for(int i = 0; i < k; i++) {
            sum += nums[i];
        }
        ans = (double)sum / k;

        // Sliding window approach
        for(int i = 0; i + k < n; i++) { 
            sum += nums[i + k] - nums[i]; // Shift the window
            ans = max(ans, (double)sum / k);
        }

        return ans;
    }
};


