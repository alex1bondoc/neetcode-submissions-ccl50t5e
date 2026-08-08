class Solution {
    unordered_map<int, int> cache;
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n{static_cast<int>(cost.size())};
        cache[n] = 0;
        cache[n + 1] = 0;
        for (int i{n - 1}; i >= 0; --i) {
            cache[i] = cache[i + 1] + cost[i];
            cache[i] = min(cache[i], cache[i + 2] + cost[i]);
        }
        return min(cache[0], cache[1]);
    }
};
