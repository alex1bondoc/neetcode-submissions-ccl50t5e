class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n{static_cast<int>(text1.size())}, m{static_cast<int>(text2.size())};
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));

        auto back = [&](auto self,int i, int j){
            if (i >= n || j >= m) return 0;
            int res{};
            if (dp[i][j] != -1) return dp[i][j];
            if (text1[i] == text2[j]) {
                res = max(res, self(self, i + 1, j + 1) + 1);
            }
            res = max(res, self(self, i, j + 1));
            res = max(res, self(self, i + 1, j));
            dp[i][j] = res;
            return res;
        };
        return back(back, 0, 0);
    }
};
