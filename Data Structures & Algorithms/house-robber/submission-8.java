class Solution {
    public int rob(int[] nums) {
        return rec(0, nums);
    }
    public int rec(int n, int[] nums) {
        if (n >= nums.length){
            return 0;
        }
        return Math.max(nums[n] + rec(n + 2, nums), rec(n + 1, nums));
    }
}
