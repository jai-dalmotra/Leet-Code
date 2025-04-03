class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        
        int n=nums.size();

        vector<int> right_max(n);

        int max_val=nums[n-1];

        for(int i=n-2;i>0;i--)
        {
            right_max[i]=max_val;
            if(nums[i]>max_val)
            {
                max_val=nums[i];
            }
        }

        long long max_triplet=0;
        max_val=nums[0];
        for(int i=1;i<n-1;i++)
        {
            long long triple=(long long)(max_val-nums[i])*(long long)(right_max[i]);
            if(triple>max_triplet)
            {
                max_triplet=triple;
            }

            if(nums[i]>max_val)
            {
                max_val=nums[i];
            }
        }

        return max_triplet;
    }
};
