class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n{static_cast<int>(text1.size())}, m{static_cast<int>(text2.size())};
        auto back = [&](auto self,int i, int j){
            if (i >= n || j >= m) return 0;
            int res{};
            if (text1[i] == text2[j]) {
                res = max(res, self(self, i + 1, j + 1) + 1);
            }
            res = max(res, self(self, i, j + 1));
            res = max(res, self(self, i + 1, j));
            return res;
        };
        return back(back, 0, 0);
    }
};
