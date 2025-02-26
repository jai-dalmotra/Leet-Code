class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x;  
        while (left <= right) {
            long long m = left + (right - left) / 2; // Use long long to avoid overflow

            if (m * m > x) {
                right = m - 1;
            } else {
                left = m + 1;
            }
        }
        return left - 1;
    }
};
