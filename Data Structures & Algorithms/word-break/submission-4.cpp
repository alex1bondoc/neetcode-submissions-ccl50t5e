#include <string>
#include <vector>
#include <unordered_set>
#include <string_view>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = static_cast<int>(s.size());
        
        unordered_set<string_view> set;
        int max_len = 0;
        for (const auto& word : wordDict) {
            set.insert(word);
            max_len = max(max_len, static_cast<int>(word.size()));
        }

        // Use vector<bool> instead of unordered_map<int, bool>
        vector<bool> dp(n + 1, false);
        dp[n] = true;

        string_view sv(s);

        for (int i = n - 1; i >= 0; --i) {
            // Bound length by remaining string length AND maximum word length
            int limit = min(n - i, max_len);
            for (int l = 1; l <= limit; ++l) {
                // Check dp[i + l] FIRST to short-circuit set lookup
                if (dp[i + l] && set.contains(sv.substr(i, l))) {
                    dp[i] = true;
                    break; // Once dp[i] is true, no need to check other lengths
                }
            }
        }

        return dp[0];
    }
};