class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> freq(3, 0); // Frequency array for 'a', 'b', 'c'
        int count = 0, curCount = 0;
        int left = 0, n = s.length();

        for (int right = 0; right < n; right++) {
            char ch = s[right];
            freq[ch - 'a']++;
            if (freq[ch - 'a'] == 1) {
                curCount++;
            }
            
            while (curCount == 3) {
                count += (n - right);
                char c = s[left];
                freq[c - 'a']--;
                if (freq[c - 'a'] == 0) {
                    curCount--;
                }
                left++;
            }
        }
        return count;
    }
};
