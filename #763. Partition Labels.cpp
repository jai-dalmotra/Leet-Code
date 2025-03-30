class Solution {
public:
    vector<int> partitionLabels(string s) {
        // Step 1: Store the last occurrence of each character
    unordered_map<char, int> last_index;
    for (int i = 0; i < s.length(); i++) {
        last_index[s[i]] = i;
    }

    vector<int> partitions;
    int start = 0, max_end = 0;

    // Step 2: Iterate and create partitions
    for (int i = 0; i < s.length(); i++) {
        max_end = max(max_end, last_index[s[i]]);
        
        // If current index reaches max_end, a partition is identified
        if (i == max_end) {
            partitions.push_back(i - start + 1);
            start = i + 1; // Move start to the next partition
        }
    }
    
    return partitions;
    }
};
