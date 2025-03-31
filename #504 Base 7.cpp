class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";  // Handle zero case
        
        bool isNegative = num < 0; // Store sign
        num = abs(num); // Work with positive number

        string base7 = "";
        while (num > 0) {
            int digit = num % 7; // Get remainder
            base7 = to_string(digit) + base7; // Append at the beginning
            num /= 7; // Divide by 7
        }

        return isNegative ? "-" + base7 : base7; // Add negative sign if needed
    }
};
