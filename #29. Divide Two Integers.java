class Solution {
    public int divide(int dividend, int divisor) {
        // Case 1: Handle the one scenario where overflow happens.
        // -2147483648 / -1 = 2147483648 which is bigger than Integer.MAX_VALUE
        if (dividend == Integer.MIN_VALUE && divisor == -1) {
            return Integer.MAX_VALUE;
        }

        // (Optional) If divisor is 0, division is undefined.
        if (divisor == 0) {
            throw new ArithmeticException("Division by zero");
        }

        // Step 2: Figure out the sign of the result.
        // XOR (^) ensures result is negative only if exactly one input is negative.
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

        // Step 3: Work with positive numbers.
        // Convert to long before abs() to correctly handle Integer.MIN_VALUE.
        long a = Math.abs((long) dividend);
        long b = Math.abs((long) divisor);

        long res = 0; // Final quotient to build up.

        // Step 4: Subtract chunks of divisor from dividend.
        // Instead of subtracting divisor one-by-one (too slow),
        // we subtract the *largest doubled chunk* that still fits.
        while (a >= b) {
            long temp = b;       // start with divisor
            long multiple = 1;   // how many times divisor fits

            // Double temp (and multiple) until it would exceed 'a'
            // Example: if a=43, b=5, temp becomes 40, multiple = 8
            while ((temp << 1) <= a) {
                temp <<= 1;       // temp = temp * 2
                multiple <<= 1;   // multiple = multiple * 2
            }

            // Subtract that large chunk from dividend
            a -= temp;
            // Add the multiple to the quotient
            res += multiple;
        }

        // Step 5: Apply the sign
        res = (sign == 1) ? res : -res;

        // Step 6: Clamp result just in case it exceeds int bounds
        if (res > Integer.MAX_VALUE) return Integer.MAX_VALUE;
        if (res < Integer.MIN_VALUE) return Integer.MIN_VALUE;

        // Step 7: Return as int
        return (int) res;
    }
}
