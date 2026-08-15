class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n{static_cast<int>(text1.size())}, m{static_cast<int>(text2.size())};
        vector<vector<int>> dp(n + 1, vector<int> (m + 1));
        for (int i{n - 1}; i >= 0; --i) {
            for (int j{m - 1}; j >= 0; --j) {
                int res{max(dp[i + 1][j], dp[i][j + 1])};
                if (text1[i] == text2[j]) {
                    res = max(res, dp[i + 1][j + 1] + 1) ;
                }
                dp[i][j] = res;
            }
        }
        return dp[0][0];
    }
};
