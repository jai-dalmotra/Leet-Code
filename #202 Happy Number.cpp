class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> usedIntegers;
        int t=n;
        int sum;
        int d;
        while(true)
        {
            sum=0;
            while(n>0)
            {
                d=n%10;
                sum=sum+d*d;
                n=n/10;
            }
            if(sum==1)
            {
                return true;
            }

            if(usedIntegers.count(sum))
                return false;

            usedIntegers.insert(sum); 

            n=sum;   
        }
        

    }
};
