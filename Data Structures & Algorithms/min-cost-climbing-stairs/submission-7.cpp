class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n{static_cast<int>(cost.size())};
        int plusOne{}, plusTwo{};
        for (int i{n - 1}; i >= 0; --i) {
            int cur{plusOne + cost[i]};
            cur = min(cur, plusTwo + cost[i]);
            plusTwo = plusOne;
            plusOne = cur;
        }
        return min(plusOne, plusTwo);
    }
};
