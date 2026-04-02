class Solution {
    HashMap<Integer, Integer> map = new HashMap<>();
    public int rob(int[] nums) {
        int[] dp = new int[nums.length + 2];
        int unu = 0, doi = 0;
        for (int i = nums.length - 1; i>= 0; --i) {
            int temp = Math.max(nums[i] + doi, unu);
            doi = unu;
            unu = temp;
        }
        return unu;
    }
}
