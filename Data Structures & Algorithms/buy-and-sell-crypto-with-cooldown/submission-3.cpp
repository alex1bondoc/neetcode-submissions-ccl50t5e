class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return dp(prices, 0, 0);
    }
    int dp(vector<int>& prices, int i, int buy) {
        if (i >= prices.size())
            return 0;
        if (buy == 0) {
            return std::max(-prices[i] + dp(prices, i + 1, 1), dp(prices, i + 1, 0));
        }
        else {
            return std::max(+prices[i] + dp(prices, i + 2, 0), dp(prices, i + 1, 1));
        }
    }
};
