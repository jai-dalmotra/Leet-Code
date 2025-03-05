class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        if (n == 0) return 0;

        int i = 0, sign = 1;
        long ans = 0;

        // Trim leading spaces
        while (i < n && s[i] == ' ') i++;

        // Check for sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Convert digits
        while (i < n && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');

            // Check for overflow
            if (sign == 1 && ans > INT_MAX) return INT_MAX;
            if (sign == -1 && -ans < INT_MIN) return INT_MIN;

            i++;
        }

        return sign * ans;
    }
};
