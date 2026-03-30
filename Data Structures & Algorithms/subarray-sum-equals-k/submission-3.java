class Solution {
    public int subarraySum(int[] nums, int k) {
        int s = 0;
        int res = 0;
        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(0, 1);
        for (int num : nums) {
            s += num;
            int dif = s - k;
            res += map.getOrDefault(dif, 0);
            map.put(s, map.getOrDefault(s, 0) + 1);
        }
        return res;
    }
}