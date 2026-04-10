class Solution {
    std::vector<std::vector<int>> memo;
public:
    int longestCommonSubsequence(string text1, string text2) {
        memo.resize(text1.size() + 1, vector<int> (text2.size() + 1, -1));
        return dp(text1, text2, 0, 0);        
    }
    int dp(string t1, string t2, int i, int j) {
        if (i == t1.size() || j == t2.size())
            return 0;
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        if (t1[i] == t2[j]) memo[i][j] =  1 + dp(t1, t2, i + 1, j + 1);
        else {
            memo[i][j] =  std::max(dp(t1, t2, i + 1, j), dp(t1, t2, i, j + 1));
        }    
        return memo[i][j];

    }
};
