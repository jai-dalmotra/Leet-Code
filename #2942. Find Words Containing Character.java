class Solution {
    public List<Integer> findWordsContaining(String[] words, char x) {
        List<Integer> result = new ArrayList<>();
        
        for (int i = 0; i < words.length; i++) {
            if (words[i].indexOf(x) != -1) { // check if char exists in word
                result.add(i);
            }
        }
        
        return result;
    }
}
