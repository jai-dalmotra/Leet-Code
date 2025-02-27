// Time Complexity- O(M+N)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l=m+n;
        vector<int> arr(l);
        int size1=0,size2=0;
        int size=0;
        while(size1<m&&size2<n)
        {
            if(nums1[size1]<nums2[size2])
            {
                arr[size]=nums1[size1];
                size++;
                size1++;
            }
            else
            {
                arr[size]=nums2[size2];
                size++;
                size2++;
            }
        }

        if(size1<m)
        {
            while(size1<m)
            {
                arr[size]=nums1[size1];
                size++;
                size1++;
            }
        }
        else
        {
            while(size2<n)
            {
                arr[size]=nums2[size2];
                size++;
                size2++;
            } 
        }

        nums1=arr;

    }
};
