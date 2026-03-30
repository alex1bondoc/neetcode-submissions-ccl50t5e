class Solution {
public:
    int characterReplacement(string s, int k) {
        // optimal solution
        int res = 0;
        int maximum = 0;
        std::unordered_map<char, int> count;
        int l = 0;
        for (int r = 0; r < s.size(); ++r) {
            count[s[r]] = count[s[r]] + 1;
            if (count[s[r]] > maximum) maximum = count[s[r]];
            while (r - l + 1 -  maximum > k) {
                count[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
