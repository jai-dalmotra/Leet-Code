class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> result = new ArrayList<>();
        backtrack(result, "", 0, 0, n);
        return result;
    }

    private void backtrack(List<String> result, String current, int open, int close, int n) {
        // Base case: if the current string has reached max length
        if (current.length() == 2 * n) {
            result.add(current);
            return;
        }

        // Add '(' if we still have some left to use
        if (open < n) {
            backtrack(result, current + "(", open + 1, close, n);
        }

        // Add ')' if it won't break validity
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, n);
        }
    }
}    
