class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        return min(rec(cost, 0), rec(cost, 1));
    }
    int rec(vector<int>& cost, int i) {
        if (i >= cost.size()) {
            return 0;
        }
        return cost[i] + min(rec(cost, i + 1), rec(cost, i + 2));
    }
};
