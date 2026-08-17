class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n{static_cast<int>(coins.size())};
        sort(coins.begin(), coins.end());
        vector<vector<int>> dp(n + 1, vector<int> (amount + 1, 0));
        auto back = [&](auto self, int i, int a) {
            if (i == n) {
                if (amount == a) return 1;
                return 0;
            }
            if (a > amount) return 0;
            return self(self, i, a + coins[i]) + self(self, i + 1, a);
        
        };
        return back(back, 0, 0);
    }
};
