class Solution {
public:
    int minDistance(string word1, string word2) {
        int n{static_cast<int>(word1.size())}, m{static_cast<int>(word2.size())};
        if (n < m) {
            swap(word1, word2);
            swap(n, m);
        }
        if (m == 0) return n; 
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 1 << 30));
        dp[n][m] = 0;
        dp[n - 1][m] = 1;
        dp[n][m - 1] = 1;
        for (int i{n - 1}; i >= 0; i--) {
            for (int j{m - 1}; j >= 0; j--) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                }
                else {
                    dp[i][j] = min(min(dp[i + 1][j], dp[i][j + 1]), dp[i + 1][j + 1]) + 1;
                }
            }
        }


        return dp[0][0];
    }
};
