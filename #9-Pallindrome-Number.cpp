class Solution {
public:
    bool isPalindrome(int x) {
        long reverse=0;
       for(int i=x;i>0;i=i/10)
       {
           int d=i%10;
           reverse=reverse*10+d;
       }

        if(reverse==x)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
