class Solution {
public:
    int characterReplacement(string s, int k) {
        // brute Force solution
        int n = s.size();
        int res = 0;
        for (int i = 0;i < n; ++i) {
            std::unordered_map<char, int> chars;
            int maximum = 0;
            for (int j = i; j < n; ++j) {
                chars[s[j]] = chars[s[j]] + 1;
                if (chars[s[j]] > maximum){
                    maximum = chars[s[j]];
                }
                if (j - i + 1 - maximum <= k)
                    res = max(j - i + 1, res);
            }
        }
        return res;
    }
};
