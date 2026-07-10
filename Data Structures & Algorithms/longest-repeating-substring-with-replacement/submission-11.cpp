class Solution {
public:
    int characterReplacement(string s, int k) {
        int res{};
        for (int i{}; i < s.size(); ++i) {
            int count{};
            for (int j{i}; j < s.size() ; ++j) {
                if (s[j] != s[i]) count ++;
                if (count > k) break;
                res = std::max(res, j - i + 1);
            }
        }
        return res;
    }
};
