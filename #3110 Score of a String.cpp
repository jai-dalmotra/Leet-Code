class Solution {
public:
    int scoreOfString(string s) {
        int i;
        int sum=0;
        for(i=0;i<s.size()-1;i++)
        {
            sum=sum+abs(int(s[i])-int(s[i+1]));
        }
        return sum;
    }
};
