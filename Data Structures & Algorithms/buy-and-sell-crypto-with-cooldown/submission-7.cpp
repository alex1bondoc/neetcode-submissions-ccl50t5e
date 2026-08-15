class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n{static_cast<int>(prices.size())};
        vector<vector<int>> dp(2, vector<int> (n + 1, -1));
        auto back = [&](auto self, int day, int buy) {
            if (day >= n) return 0;
            if (dp[buy][day] != -1) return dp[buy][day];
            if (buy == 1) {
                dp[buy][day] = max(self(self, day + 1, 1), prices[day] +self(self, day + 2, 0));
            }
            else {
                dp[buy][day] = max(-prices[day] + self(self, day + 1, 1), self(self, day + 1, 0));
            }
            return dp[buy][day];
        };
        return back(back, 0, 0);
    }
};
