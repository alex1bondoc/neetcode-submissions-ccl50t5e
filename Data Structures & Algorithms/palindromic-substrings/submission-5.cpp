class Solution {
public:
    int countSubstrings(string s) {
        int n{s.length()};
        bool dp[n][n]{};
        int res{};
        for (int len{1}; len <= n; ++len) {
            for (int i = 0; i < n - len + 1; ++i) {
                int j{i + len - 1};
                if ((len <= 2 || dp[i + 1][j - 1]) && s[i] == s[j]){
                    res ++;
                    dp[i][j] = true;
                }
            }
        }
        return res;
    }
};
