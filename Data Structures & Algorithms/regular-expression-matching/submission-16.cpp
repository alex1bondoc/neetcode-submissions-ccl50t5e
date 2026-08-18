class Solution {
public:
    bool isMatch(string s, string p) {
        int n{static_cast<int>(s.size())}, m{static_cast<int>(p.size())};
        auto back = [&](auto self, int i, int j) {
            if (i == n && j == m) return true;
            if (i > n || j > m) return false;
            bool res{false};
            if (j < m && p[j + 1] == '*' && (i == n || s[i] == p[j] || p[j] == '.')) {
                res = res || self(self, i + 1, j);
                res = res || self(self, i, j + 2);
            }
            else if (p[j] == '.' || s[i] == p[j]) {
                res = res || self(self, i + 1, j + 1);
            }
            
            return res;
        };
        return back(back, 0, 0);
    }
};
