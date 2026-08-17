class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        unordered_map<string, bool> map;
        auto back = [&](auto self, int i, int j){
            if (i == n && j == m) {
                return true;
            }
            else if (i > n || j > m) return false;
            string c{to_string(i) + "," + to_string(j)};
            if(map.contains(c)) return map[c];
            if (s[i] == p[j] || p[j] == '.') {
                map[c] = self(self, i + 1, j + 1);
            }
            else if (p[j] == '*') {
                bool res{false};
                for (int l{}; l <= n - m + j; ++l) {
                    res = res || self(self, i + l + 1, j + 1);
                }
                map[c] = res;
            }
            else map[c] = false;
            return map[c];
        };

        return back(back, 0, 0);
    }
};
