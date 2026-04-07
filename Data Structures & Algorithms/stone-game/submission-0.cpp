class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        auto dp = [&](auto&& dp,int i, int j, int s1, int s2, int who){
            if (i > j) {
                if (s1 > s2) {
                    return true;
                }
                return false;
            }
            if (who == 0) {
                return dp(dp, i + 1, j, s1 + piles[i], s2, 1 - who) || dp(dp, i, j - 1, s1 + piles[j], s2, 1- who);
            }
            else {
                return dp(dp, i + 1, j, s1, s2 + piles[i], 1 - who) || dp(dp, i, j - 1, s1 , s2+ piles[j], 1- who);
            }
        };
        return dp(dp, 0, piles.size() - 1, 0, 0, 0);
    }
};