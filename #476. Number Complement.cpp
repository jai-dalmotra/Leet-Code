class Solution {
public:
    int findComplement(int num) {
        int mask = 0, temp = num;
        
        // Create a mask with all 1s of the same length as num
        while (temp) {
            mask = (mask << 1) | 1;
            temp >>= 1;
        }
        
        // XOR num with mask to flip bits
        return num ^ mask;
    }
};
