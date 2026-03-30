class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        std::unordered_map<char, int> map;
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (map.contains(s[i])) {
                l = max(map[s[i]] + 1, l);
            }
            map[s[i]] = i;
            res = max(res, i - l + 1);
        }            
        return res;
    }
};
