class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        auto back = [&](auto self, int i, int j){
            if (i == n && j == m) {
                return true;
            }
            else if (i > n || j > m) return false;
            if (s[i] == p[j] || p[j] == '.') {
                return self(self, i + 1, j + 1);
            }
            if (p[j] == '*') {
                bool res{false};
                for (int l{}; l <= n - m + j; ++l) {
                    res = res || self(self, i + l, j + 1);
                }
                return res;
            }
            return false;
        };

        return back(back, 0, 0);
    }
};
