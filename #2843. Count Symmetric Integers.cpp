class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;

        for (int num = low; num <= high; ++num) {
            string s = to_string(num);
            int len = s.length();

            // Skip numbers with odd number of digits
            if (len % 2 != 0) continue;

            int half = len / 2;
            int leftSum = 0, rightSum = 0;

            for (int i = 0; i < half; ++i) {
                leftSum += s[i] - '0';
                rightSum += s[i + half] - '0';
            }

            if (leftSum == rightSum) {
                count++;
            }
        }

        return count;
    }
};
