class Solution {
public:
    char findTheDifference(string s, string t) {
        int n1=s.length();
        int n2=t.length();
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        for(int i=0;i<n1;i++)
        {
            if(s[i]!=t[i])
                return t[i];
        }

        return t[n1];
    }
};
