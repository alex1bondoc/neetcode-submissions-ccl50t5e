class Solution {
    int x[101][101]{};
public:
    bool isInterleave(string s1, string s2, string s3) {
        auto dp = [&](auto&& dp, int i, int j, int t) {
            if (t == s3.size() && i == s1.size() && s2.size() == j) return true;
            bool res = false;
            if (x[i][j] == 1) return false;
            if (x[i][j] == 2) return true; 
            if (s1[i] == s3[t]){
                res = res || dp(dp, i + 1, j, t + 1);
            }
            if (s2[j] == s3[t]) {
                res = res || dp(dp, i, j + 1, t + 1);
            }
            if (res) x[i][j] = 2;
            else x[i][j] = 1;
            return res;
        };
        return dp(dp, 0, 0, 0);
    }
};
