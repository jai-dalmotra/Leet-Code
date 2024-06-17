class Solution {
public:
    int reverse(int x) {
        int flag=0;
        long rev=0;
        if(x>0)
        {
            flag=1;
        }
        x=abs(x);
        for(int i=x;i>0;i=i/10)
       {
           int d=i%10;
            // Check for overflow before updating rev
            if (rev > (INT_MAX - d) / 10) {
                return 0;
            }
           rev=rev*10+d;
       }
       if(flag==1)
       {
           return rev;
       }
       else
       {
           return(-rev);
       }
    }
};
