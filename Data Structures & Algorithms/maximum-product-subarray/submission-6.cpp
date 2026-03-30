class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int mini = 1;
        int maxi = 1;
        for (int num : nums) {
            int miniClone = min(min(num, num * mini), num * maxi);
            int maxiClone = max(max(num, num * mini), num * maxi);
            res = max(res, maxiClone);
            maxi = maxiClone;
            mini = miniClone;
        }
        return res;
    }
};
