class Solution {
public:
    long long coloredCells(int n) {
        long long c=1;
        int jump=4;
        int i=1;
        while(i!=n)
        {
            c=c+jump;
            jump=jump+4;
            i++;
        }
        return c;
    }
};
