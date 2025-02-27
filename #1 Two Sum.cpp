// o(n^2) time complexity
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int sum=nums[i]+nums[j];
                if(sum==target)
                {
                    return {i,j};
                }
            }
        }
        return {};
    }
};

//O(n) Time Complexity using Hash Maps

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i}; 
            }
            mp[nums[i]] = i;  
        }
        return {};  
    }
};
