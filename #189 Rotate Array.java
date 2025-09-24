class Solution {
    private void reverse(int[] nums, int low, int high) {
        while (low < high) {
            int temp = nums[low];
            nums[low] = nums[high];
            nums[high] = temp;
            low++;
            high--;
        }
    }

    public void rotate(int[] nums, int k) {
        int n = nums.length;
        k = k % n; // handle cases where k > n

        // reverse first part
        reverse(nums, 0, n - k - 1);
        // reverse second part
        reverse(nums, n - k, n - 1);
        // reverse whole array
        reverse(nums, 0, n - 1);
    }
}
