class Solution {
    public List<String> removeAnagrams(String[] words) {
        List<String> res = new ArrayList<>();
        String prev = "";
        
        for (String word : words) {
            char[] chars = word.toCharArray();
            Arrays.sort(chars);
            String sorted = new String(chars);
            
            if (!sorted.equals(prev)) {   // only add if not an anagram of last kept
                res.add(word);
                prev = sorted;
            }
        }
        
        return res;
    }
}
