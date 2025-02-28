class Solution {
public:
    int addDigits(int num) {
        int n=num;
        if(n<=0)
        {
            return 0;
        }
        int sum=0;
        while(true)
        {
            sum=0;
            while(n>0)
            {
                int d=n%10;
                sum=sum+d;
                n=n/10;
            }
            if(sum<10)
            {
                return sum;
            }
            n=sum;
        }
    }
};
