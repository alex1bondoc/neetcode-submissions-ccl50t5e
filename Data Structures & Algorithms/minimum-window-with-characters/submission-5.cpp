class Solution {
public:
    string minWindow(string s, string t) {
        int need{};
        std::vector<int> freq(128, 0);
        std::vector<int> freq2(128, 0);
        for (char c : t) {
            if (freq[c] == 0) need ++;
            freq[c] ++;
        }
        int left{};
        int start{-1};
        int minLength{1 << 30};
        for(int right{}; right < s.size(); ++right) {
            if (freq[s[right]] != 0){
                freq2[s[right]] ++;
                if (freq2[s[right]] == freq[s[right]]) need --;
            }
            while (need == 0) {
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    start = left;
                }
                if (freq[s[left]] != 0) {
                    freq2[s[left]]--;
                    if (freq2[s[left]] < freq[s[left]])
                        need ++;
                }
                left++;
            }
        }
        return (start == -1) ? "" : s.substr(start, minLength);
    }
};
