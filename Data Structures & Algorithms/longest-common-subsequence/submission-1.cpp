class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.size() >  text2.size())
            std::swap(text1, text2);
        int n = text1.size();
        int m = text2.size();
        int dp[n + 1][m + 1]{};
        for (int i = n -1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (text1[i] == text2[j]){
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                else {
                    dp[i][j] = std::max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        return dp[0][0];
    }
};
