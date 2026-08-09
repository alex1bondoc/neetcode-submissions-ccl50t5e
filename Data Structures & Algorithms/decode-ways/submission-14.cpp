class Solution {
    unordered_map<int, int> cache;
public:
    int numDecodings(string s) {
        return back(s, 0);
    }
    int back(string& s, int i) {
        if (i == s.size()) return 1;
        if (s[i] == '0') return 0;
        if (!cache.contains(i)) {
            int cnt{};
            cnt += back(s, i + 1);
            if (i + 1 < s.size() && s[i] <= '2') {
                if (s[i] == '2' && s[i + 1] <= '6' || s[i] == '1') {
                    cnt += back(s, i + 2);
                }
            }
            cache[i] = cnt;
        }
        return cache[i];
    }
};
