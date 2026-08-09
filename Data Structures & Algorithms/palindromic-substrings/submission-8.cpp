class Solution {
public:
    int countSubstrings(string s) {
        string t{"#"};
        for (char c : s) {
            t += c;
            t += "#";
        }
        int n{static_cast<int>(t.size())};
        vector<int> p(n + 1);
        int l{}, r{};
        for (int i{}; i < n; ++i) {
            p[i] = (i < r) ? min(r - i, p[l + r - i]) : 0;
            while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 && t[i - p[i] - 1] == t[i + p[i] + 1]) p[i] ++;
            if (i + p[i] + 1 > r) {
                r = i + p[i];
                l = i - p[i];
            }
        }
        int res{};
        for (int i : p) {
            res += (i + 1) / 2;
        }
        return res;
    }
};
