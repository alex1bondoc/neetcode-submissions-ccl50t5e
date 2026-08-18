class Solution {
public:
    bool isMatch(string s, string p) {
        int n{static_cast<int>(s.size())}, m{static_cast<int>(p.size())};
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        auto back = [&](auto self, int i, int j) {
            if (i == n && j == m) return true;
            if (i > n || j > m) return false;
            bool res{false};
            if (dp[i][j] != -1) return dp[i][j] == 1 ? true : false;
            if (j < m && p[j + 1] == '*' ) {
                if (i == n || s[i] == p[j] || p[j] == '.')
                    res = res || self(self, i + 1, j);
                res = res || self(self, i, j + 2);
            }
            else if (p[j] == '.' || s[i] == p[j]) {
                res = res || self(self, i + 1, j + 1);
            }
            dp[i][j] = res ? 1 : 0;
            return res;
        };
        return back(back, 0, 0);
    }
};
