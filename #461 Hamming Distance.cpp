class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        int xor_val = x ^ y;  
        
        while (xor_val) {
            count += (xor_val & 1); 
            xor_val >>= 1;          
        }
        
        return count;
    }
};

/*
Using Builtin Function

class Solution {
public:
    int hammingDistance(int x, int y) {
        return __builtin_popcount(x ^ y);  // Fastest way
    }
};



*/
