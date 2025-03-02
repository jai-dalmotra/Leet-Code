class Solution {
public:
    int fib(int n) {
        int f=0;
        int s=1;
        int th;
        if(n==0)
        {
            return f;
        }
        if(n==1)
        {
            return s;
        }

        for(int i=0;i<=n-2;i++)
        {
            if(s>INT_MAX/2)
                return 0;
            
            th=f+s;
            f=s;
            s=th;
        }
        return th;
    }
};
