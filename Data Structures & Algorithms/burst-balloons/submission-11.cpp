class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n{static_cast<int>(nums.size())};
        vector<int> newNums(n + 2, 1);
        for (int i{}; i < n; ++i) {
            newNums[i + 1] = nums[i];
        }
        nums = newNums;
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
        auto back = [&](auto self, int l, int r) {
            if (l == r) {
                return nums[l] * nums[l - 1] * nums[r + 1];
            }
            if (dp[l][r] != -1) return dp[l][r];
            int res{};
            for (int i{l}; i <= r; ++i) {
                res = max(res, nums[i] * nums[l - 1] * nums[r + 1] + self(self, l, i - 1) + self(self, i + 1, r));
            }
            dp[l][r] = res;
            return res;
        };
        return back(back, 1, n);
    }
};
