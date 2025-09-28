class Solution {
    public int maxFrequencyElements(int[] nums) {
        Map<Integer, Integer> freq = new HashMap<>();
        
        // Count frequencies
        for (int num : nums) {
            freq.put(num, freq.getOrDefault(num, 0) + 1);
        }

        int maxFreq = 0;
        // Find maximum frequency
        for (int count : freq.values()) {
            maxFreq = Math.max(maxFreq, count);
        }

        int total = 0;
        // Count how many elements have that frequency
        for (int count : freq.values()) {
            if (count == maxFreq) {
                total += count;
            }
        }

        return total;
    }
}
