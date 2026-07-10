class Solution {
    public int rob(int[] nums) {
        return Math.max(rec(nums, 0, nums.length - 1), rec(nums, 1, nums.length));
    }
    public int rec(int[] nums, int i, int end) {
        if (i >= end) {
            return 0;
        }
        return Math.max(nums[i] + rec(nums, i + 2, end), rec(nums, i + 1, end));
    }
}
