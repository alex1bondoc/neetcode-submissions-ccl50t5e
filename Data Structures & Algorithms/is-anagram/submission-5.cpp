class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> fq(26, 0);
        for (int i{}; i < s.size(); ++i) {
            fq[s[i] - 'a']++;
            fq[t[i] - 'a']--;
        }
        for (int i{}; i < 26; ++i) {
            if (fq[i]) return false;
        }
        return true;
    }
};
