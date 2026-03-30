class Solution {
public:
    int characterReplacement(string s, int k) {
        // sliding window unoptimal
        int res = 0;
        std::unordered_set<char> charSet(s.begin(), s.end());

        for (char c : charSet) {
            int cnt = 0;
            int l = 0;
            for (int r = 0; r < s.size(); ++r) {
                if (s[r] == c) {
                    cnt ++;
                }
                while (r - l + 1 - cnt > k) {
                    if (s[l] == c) {
                        cnt --;
                    }
                    l ++;

                }
                res = max(res, r - l  +1);
            }
        }
        return res;
    }
};
