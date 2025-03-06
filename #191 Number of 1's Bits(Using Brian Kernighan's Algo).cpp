//Using Bit Manipulation (Brian Kernighan’s Algorithm)  Time Complexity: 𝑂(𝑘)O(k), where k is the number of 1's in n
class Solution {
public:
    int hammingWeight(int n) {
        
         int count = 0;
    while (n) {
        n &= (n - 1);  // Turn off the rightmost 1-bit
        count++;
    }
    return count;
    }
};
