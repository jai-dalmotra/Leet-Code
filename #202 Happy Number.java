class Solution {
    public boolean isHappy(int n) {
        Set<Integer> usedIntegers = new HashSet<>();
        int t=n;
        int sum=10;
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

            n=sum;

            if(usedIntegers.contains(n))
                return false;

            usedIntegers.add(n);    
        }
    }
}
