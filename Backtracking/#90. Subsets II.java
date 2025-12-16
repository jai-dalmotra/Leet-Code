// 1] Brute force

// class Solution {

//     private void calSubsets(int[] arr, int idx, HashSet<List<Integer>> set, List<Integer> list) {
//         if(idx == arr.length) {
//             set.add(new ArrayList<>(list));
//             return;
//         }

//         // Include element
//         list.add(arr[idx]);
//         calSubsets(arr, idx+1, set, list);

//         // Exclude element
//         list.remove(list.size()-1);
//         calSubsets(arr, idx+1, set, list);
//     }

//     public List<List<Integer>> subsetsWithDup(int[] nums) {
//         Arrays.sort(nums);

//         HashSet<List<Integer>> set = new HashSet<>();
//         calSubsets(nums, 0, set, new ArrayList<>());

//         List<List<Integer>> ans = new ArrayList<>(set);
//         return ans;
//     }
// } 






// 2] Optimal Solution

class Solution {

    private void findSubsets(int[] arr, int idx, List<List<Integer>> ans, List<Integer> list) {
        ans.add(new ArrayList<>(list));
        for(int i=idx; i<arr.length; i++) {
            if(i != idx && arr[i] == arr[i-1]) continue;
            list.add(arr[i]);
            findSubsets(arr, i+1, ans, list);
            list.remove(list.size()-1);
        }
    }

    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();
        findSubsets(nums, 0, ans, new ArrayList<>());

        return ans;
    }
} 
