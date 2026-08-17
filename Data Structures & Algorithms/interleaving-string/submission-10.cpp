class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size() != s1.size() + s2.size()) return false;
        vector<vector<int>> dp(s1.size() + 1, vector<int> (s2.size() + 1));
        // auto back = [&](auto self, int i, int j){
        //     if (i == s1.size() && j == s2.size()) {
        //         return true;
        //     }
        //     else if (i > s1.size() || j > s2.size()) return false;
        //     bool res = false;
        //     if (dp[i][j] == -1) {
        //         if (s1[i] == s3[i + j]) res = res || self(self, i + 1, j);
        //         if (s2[j] == s3[i + j]) res = res || self(self, i, j + 1);
        //         if (res) dp[i][j] = 1;
        //         else dp[i][j] = 0;
        //     }
        //     return dp[i][j] == 1;
            
        // };
        int n{static_cast<int>(s1.size())}, m{static_cast<int>(s2.size())};
        dp[n][m] = 1;
        for (int i{n}; i >= 0; i-- ) {
            for (int j{m}; j >= 0; j--) {
                if (i < n && s1[i] == s3[i + j]) dp[i][j] = dp[i][j] || dp[i + 1][j];
                if (j < m && s2[j] == s3[i + j]) dp[i][j] = dp[i][j] || dp[i][j + 1];
            }
        }
        return dp[0][0];
    }
};
