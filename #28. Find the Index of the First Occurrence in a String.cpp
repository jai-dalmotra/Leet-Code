class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=haystack.size();
        int n=needle.size();
        int p1=0,p2=0;

        while(p2<n)
        {
            if(p1==m)
            {
                return -1;
            }

            if(haystack[p1]==needle[p2])
            {
                p1++;
                p2++;
            }
            else{
                p1=p1+1-p2;
                p2=0;
            }

        }
        return p1-n;
    }
};
