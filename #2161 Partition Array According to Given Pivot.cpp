class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int lcount=0,gcount=0,pcount=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<pivot)
            {
                lcount++;
            }
            else if(nums[i]>pivot)
            {
                gcount++;
            }
            else
            {
                pcount++;
            }
        }

        int i=0,j=lcount,k=lcount+pcount;
        vector<int> result(nums.size());

        for(int n=0;n<nums.size();n++)
        {
            if(nums[n]<pivot)
            {
                result[i]=nums[n];
                i++;
            }
            else if(nums[n]>pivot)
            {
                result[k]=nums[n];
                k++;
            }
            else
            {
                result[j]=nums[n];
                j++;
            }
        }

        return result;

    }
};
