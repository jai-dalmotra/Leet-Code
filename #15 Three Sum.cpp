class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> results;

        int i,j,k;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(i>0&&nums[i]==nums[i-1])
            {
                continue;
            }

            j=i+1;
            k=n-1;

            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0)
                {
                    results.push_back({nums[i],nums[j],nums[k]});
                    while(j<k && nums[j]==nums[j+1])
                    {
                        j++;
                    }
                    while(j<k && nums[k]==nums[k-1])
                    {
                        k--;
                    }
                    j++;
                    k--;
                }

                else if(sum<0)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }
        return results;
    }
};
