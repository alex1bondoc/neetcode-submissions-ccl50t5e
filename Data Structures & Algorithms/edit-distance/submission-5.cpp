class Solution {
public:
    int minDistance(string word1, string word2) {
        auto dp = [&](auto&& dp, int i, int j) {
            if (i == word1.size() && j == word2.size()) {
                return 0;
            }
            else if(j == word2.size()) {
                return (int)word1.size() - i;
            }
            else if(i == word1.size()) {
                return (int) word2.size() - j;
            }
            int res = 1e9;
            if (word1[i] == word2[j]) res = dp(dp, i + 1, j + 1);
            else {
                res = dp(dp, i + 1, j);
                res = std::min(res, dp(dp, i, j + 1));
                res = std::min(res, dp(dp, i + 1, j + 1));
                return res + 1;
            }

            return res;
        };
        return dp(dp, 0, 0);
    }
};
