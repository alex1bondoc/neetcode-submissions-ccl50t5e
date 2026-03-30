class Solution {
    public int maxProduct(int[] nums) {
        int res = nums[0];
        int mini = 1;
        int maxi = 1;

        for (int elem : nums) {
            int miniClone = Math.min(Math.min(elem, mini * elem), maxi * elem);
            int maxiClone = Math.max(Math.max(elem, mini * elem), maxi * elem);
            res = Math.max(res, maxiClone);
            maxi = maxiClone;
            mini = miniClone;
        }
        return res;

    }
}
