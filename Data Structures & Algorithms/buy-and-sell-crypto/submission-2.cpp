class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min{1 << 30};
        int maxProfit{0};
        for (const auto& price : prices) {
            if (price < min) {
                min = price;
            }
            maxProfit = std::max(maxProfit, price - min);
        }
        return maxProfit;
    }
};
