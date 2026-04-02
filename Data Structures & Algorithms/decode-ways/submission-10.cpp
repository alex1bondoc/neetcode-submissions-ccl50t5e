class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0){
            return 0;
        }
        std::vector<int> dp(s.size() + 2, 0);
        int n{s.length()};
        dp[n] = dp[n + 1] = 1;
        for (int i{s.size() - 1}; i>= 0; --i) {
            int res{};
            char c{s[i]};
            if (c == '0')
                continue;
            res += dp[i + 1];
            if (c == '1' && i + 1 < n || (c == '2' && i + 1 < s.size() && s[i + 1] < '7'))
                res += dp[i + 2];
            dp[i] = res;
        }
        return dp[0];
    }
};
