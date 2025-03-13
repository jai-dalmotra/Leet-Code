class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        // Difference array for range updates, size = n+1
        vector<int> diff(n + 1, 0);
        int sum = 0;  // Accumulated decrement value at current index
        int pos = 0;  // Number of queries processed
        
        // Process each index in the array
        for (int i = 0; i < n; ++i) {
            // While the current decrement is less than required for nums[i]
            while (sum + diff[i] < nums[i]) {
                if (pos == queries.size())  // No more queries to process
                    return -1;
                int l = queries[pos][0], r = queries[pos][1], val = queries[pos][2];
                ++pos;
                // If the current query doesn't cover index i, skip it
                if (r < i)
                    continue;
                // Apply range update: add 'val' starting from max(l, i)
                diff[max(l, i)] += val;
                // Subtract 'val' right after the range
                diff[r + 1] -= val;
            }
            // Update the accumulated sum with the current difference value
            sum += diff[i];
        }
        return pos;
    }
};
