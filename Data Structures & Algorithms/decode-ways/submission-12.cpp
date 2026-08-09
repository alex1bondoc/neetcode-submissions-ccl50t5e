class Solution {
public:
    int numDecodings(string s) {
        return back(s, 0);
    }
    int back(string& s, int i) {
        if (i == s.size()) return 1;
        int cnt{};
        if (s[i] == '0') return 0;
        cnt += back(s, i + 1);
        if (i + 1 < s.size() && s[i] <= '2') {
            if (s[i] == '2' && s[i + 1] <= '6' || s[i] == '1') {
                cnt += back(s, i + 2);
            }
        }
        return cnt;
    }
};
