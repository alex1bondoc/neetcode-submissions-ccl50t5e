class Solution {
public:
    string longestPalindrome(string s) {
        std::string t{"#"};
        for (char c : s) {
            t += c;
            t += "#";
        }
        int l{}, r{};
        std::vector<int> p(t.size(), 0);
        for (int i{}; i < t.size(); ++i) {
            if (i <  r) {
                p[i] = std::min(r - i, p[l + r - i]);
            }
            else p[i] = 0;
            while (i + p[i] + 1 < t.size() && i - p[i] - 1 >=0 && t[i + p[i] + 1] == t[i - p[i] - 1]) {
                p[i] ++;
            } 
            if (i + p[i] > r) {
                l = i - p[i];
                r = i + p[i];
            }
        }
        int resLen{}, idx{};
        for (int i{}; i < t.size(); ++i) {
            if (p[i] > resLen) {
                resLen = p[i];
                idx = i;
            }
        }
        idx = (idx - resLen) / 2;
        return s.substr(idx, resLen);
    }
};
