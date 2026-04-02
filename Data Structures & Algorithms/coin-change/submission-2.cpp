class Solution {
private: 
    std::unordered_map<int, int> cache;
public:
    int dfs(vector<int>& coins, int amount) {
        if (amount == 0) return 0;

        int res = 1e9;
        if (cache.contains(amount)){
            return cache[amount];
        }
        for (int coin : coins) {
            if (amount - coin >= 0) {
                res = min(res,
                      1 + dfs(coins, amount - coin));
            }
        }
        cache[amount] = res; 
        return res;
    }

    int coinChange(vector<int>& coins, int amount) {
        int minCoins = dfs(coins, amount);
        return (minCoins >= 1e9) ? -1 : minCoins;
    }
};