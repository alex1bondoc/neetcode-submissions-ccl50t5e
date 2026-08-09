class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int, bool> cache;
        int n{static_cast<int>(s.size())};
        unordered_set<string> set;
        for (const auto& copy : wordDict) {
            set.insert(copy);
        }
        cache[n] = true;

        for (int i{n - 1}; i >= 0; --i) {
            int l{1};
            while (i + l <= n) {
                if (set.contains(s.substr(i, l))) {
                    cache[i] = cache[i] || cache[i + l];
                }
                l++;
            }
        }

        return cache[0];
    }
};
