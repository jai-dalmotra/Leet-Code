// Space Complexity - O(N)

class Solution {
    #define ll long long 
public:
    long long maximumTripletValue(vector<int>& nums) {
        ll max_triplet=0;
        ll max_diff=0;
        ll max_left=0;

        for(int i=0;i<nums.size();i++)
        {
            max_triplet=max<ll>(max_triplet,(long long)(max_diff*nums[i]));
            max_diff=max<ll>(max_diff,max_left-nums[i]);
            max_left=max<ll>(max_left,nums[i]);
        }

        return max_triplet;
    }
};
