class Solution {
    public String reverseVowels(String s) {
        char[] arr = s.toCharArray();
        int i = 0, j = arr.length - 1;

        while (i < j) {
            if (!isVowel(arr[i])) {
                i++;
                continue;
            }
            if (!isVowel(arr[j])) {
                j--;
                continue;
            }
            // Swap vowels
            char temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
        
        return new String(arr);
    }
    
    private boolean isVowel(char c) {
        return "aeiouAEIOU".indexOf(c) != -1;
    }
}
