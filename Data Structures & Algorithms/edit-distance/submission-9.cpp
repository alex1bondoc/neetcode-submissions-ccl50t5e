class Solution {
public:
    int minDistance(string word1, string word2) {
        int n{static_cast<int>(word1.size())}, m{static_cast<int>(word2.size())};
        vector<vector<int>> dp(n + 1, vector<int> (m + 1));
        auto sol = [&](auto self, int i, int j){
            if (i == n && j == m) return 0;
            if (i > n || j > m) return 1 << 30;
            int res{};
            if (dp[i][j] != 0) return dp[i][j];
            if (word1[i] == word2[j]) {
                res = self(self, i + 1, j + 1);
            }
            else {
                res = self(self, i + 1, j) + 1;                 // remove letter
                res = min(res, self(self, i + 1, j + 1) + 1);   // change letter;
                res = min(res ,self(self, i, j + 1) + 1);       // insert letter
            }
            dp[i][j] = res;
            return res;
        };
        
        return sol(sol, 0, 0);
    }
};
