class Solution {
    public int[] shuffle(int[] nums, int n) {
        int[] result = new int[2 * n];  // output array
        int j = 0;                      // pointer for result

        for (int i = 0; i < n; i++) {
            result[j++] = nums[i];      // take element from first half
            result[j++] = nums[i + n];  // take element from second half
        }

        return result;
    }
}
