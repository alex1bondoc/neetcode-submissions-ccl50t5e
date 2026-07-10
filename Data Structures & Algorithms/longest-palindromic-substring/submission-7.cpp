class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 1) {
            return s;
        }
        bool dp[n][n]{};
        int sol = 0;
        int solLength = 0;
        for (int len{1}; len <= n; ++len) {
            for(int i = 0; i < n - len; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j] && (len <= 2 || dp[i + 1][j - 1])){
                    dp[i][j] = true;
                    sol = i;
                    solLength = len;
                }
            }
        }
        std::cout << sol << " " << solLength;
        return s.substr(sol, solLength);
    }
};
