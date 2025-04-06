class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return dfs(nums, 0, 0);
    }
    
    int dfs(vector<int>& nums, int index, int currentXOR) {
        if (index == nums.size()) {
            return currentXOR;
        }
        
        // Include current element
        int with = dfs(nums, index + 1, currentXOR ^ nums[index]);
        
        // Exclude current element
        int without = dfs(nums, index + 1, currentXOR);
        
        return with + without;
    }
};
