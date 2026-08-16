class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        auto back = [&](auto self, int i, int j){
            if (i == s1.size() && j == s2.size()) {
                return true;
            }
            else if (i > s1.size() || j > s2.size()) return false;
            bool res{false};
            if (s1[i] == s3[i + j]) res = res || self(self, i + 1, j);
            if (s2[j] == s3[i + j]) res = res || self(self, i, j + 1);
            return res;
        };
        return back(back, 0, 0);
    }
};
