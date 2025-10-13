class Solution {
    public int maxFreqSum(String s) {
        int[] freq = new int[26];  // frequencies of 'a' to 'z'

        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
        }

        int maxVowel = 0;
        int maxConsonant = 0;

        for (int i = 0; i < 26; i++) {
            int f = freq[i];
            if (f > 0) {
                char ch = (char) (i + 'a');
                if (isVowel(ch)) {
                    maxVowel = Math.max(maxVowel, f);
                } else {
                    maxConsonant = Math.max(maxConsonant, f);
                }
            }
        }

        return maxVowel + maxConsonant;
    }

    private boolean isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
}
