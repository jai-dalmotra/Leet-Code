class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int Current_sum=nums[0],best_sum=nums[0];

        for(int i=1;i<nums.size();i++)
        {
            if(Current_sum>0)
            {
                Current_sum+=nums[i];
            }
            else
            {
                Current_sum=nums[i];
            }

            if(Current_sum>best_sum)
            {
                best_sum=Current_sum;
            }
        }
        return best_sum;
    }
};
