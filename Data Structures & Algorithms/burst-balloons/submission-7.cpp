class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> newNums(n + 2, 1);
        for (int i = 0; i < n; i++) {
            newNums[i + 1] = nums[i];
        }

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
        auto back = [&](auto self, int l, int r){
            if (l == r) {
                return newNums[l] * newNums[l - 1] * newNums[l + 1];
            }
            int res{};
            // if (dp[l][r] != -1) return dp[l][r];
            for (int i{l}; i <=r ; ++i) {
                res = max(res, newNums[i] * newNums[l - 1] * newNums[r + 1] + self(self, l, i - 1) + self(self, i + 1, r));
            }
            // dp[l][r] = res;
            return res;
        };
        for (int l = n; l >= 1; l--) {
            for (int r = l; r <= n; r++) {
                for (int i = l; i <= r; i++) {
                    int coins = newNums[l - 1] * newNums[i] * newNums[r + 1];
                    coins += dp[l][i - 1] + dp[i + 1][r];
                    dp[l][r] = max(dp[l][r], coins);
                }
            }
        }

        return back(back, 1, n);
    }
};