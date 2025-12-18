class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Map<Integer, Integer> freq = new HashMap<>();

        // Count occurrences
        for (int num : arr) {
            freq.put(num, freq.getOrDefault(num, 0) + 1);
        }

        // Check if frequencies are unique
        Set<Integer> set = new HashSet<>(freq.values());
        return set.size() == freq.size();
    }
}
