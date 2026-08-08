class Solution {
    unordered_map<int, int> cache;
public:
    int minCostClimbingStairs(vector<int>& cost) {
        return min(rec(cost, 0), rec(cost, 1));
    }
    int rec(vector<int>& cost, int i) {
        if (i >= cost.size()) {
            return 0;
        }
        if (!cache.contains(i)) {
            cache[i] = cost[i] + min(rec(cost, i + 1), rec(cost, i + 2));
        }
        return cache[i];
        
    }
};
