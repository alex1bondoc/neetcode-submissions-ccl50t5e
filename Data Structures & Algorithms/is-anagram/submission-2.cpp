class Solution {
public:
    bool isAnagram(string s, string t) {
        std::vector<int> counter(26, 0);
        for (auto& c: s) {
            counter[c - 'a'] ++;
        }
        for (auto& c: t) {
            counter[c - 'a'] --;
            if (counter[c-'a'] < 0) {
                return false;
            }
        }
        for (int i{}; i < 26;++i) {
            if(counter[i]) return false;
        }
        return true;
    }
};
