class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n{static_cast<int>(prices.size())};
        vector<vector<int>> dp(2, vector<int> (n + 1));
        auto back = [&](auto self, int day, int buy, int money) {
            if (day >= n) return 0;
            if (buy == 1) {
                return max(self(self, day + 1, 1, money), self(self, day + 2, 0, 0) + prices[day] - money);
            }
            else {
                return max(self(self, day + 1, 1, prices[day]), self(self, day + 1, 0, 0));
            }
        };
        return back(back, 0, 0, 0);
    }
};
