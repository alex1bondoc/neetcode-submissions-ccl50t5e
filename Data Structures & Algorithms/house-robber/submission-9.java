class Solution {
    HashMap<Integer, Integer> map = new HashMap<>();
    public int rob(int[] nums) {
        return rec(0, nums);
    }
    public int rec(int n, int[] nums) {
        if (n >= nums.length){
            return 0;
        }
        if (map.containsKey(n)){
            return map.get(n);
        }
        map.put(n, Math.max(nums[n] + rec(n + 2, nums), rec(n + 1, nums)));
        return map.get(n);
    }
}
