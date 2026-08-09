class Solution {
public:
    string longestPalindrome(string s) {
        int n{static_cast<int>(s.size())};
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        int start{0}, length{1};
        for (int i{}; i < n; ++i) {
            dp[i][i] = true;
            if (i < n - 1) {
                if (s[i] == s[i + 1]) {
                    dp[i][i + 1] = true;
                    start = i;
                    length = 2;
                }
            }
        }

        for (int l{3}; l < n; ++l) {
            for (int i{0}; i < n - l + 1; ++i) {
                dp[i][i + l - 1] = (s[i] == s[i + l - 1] && dp[i + 1][i + l - 2]);
                if (dp[i][i + l - 1]) {
                    start = i;
                    length = l;
                }
            }
        }
        
        return s.substr(start, length);
    }

};
