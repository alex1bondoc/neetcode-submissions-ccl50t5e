class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int res{0};
        int left{0};
        for (int right{}; right < s.size(); ++right) {
            if (map.contains(s[right])) {
                left = std::max(map[s[right]] + 1, left);
            }
            res = std::max(right - left + 1, res);
            map[s[right]] = right;
        }
        return res;
    }
};
