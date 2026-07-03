class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left{};
        int right{};
        unordered_set<char> set;
        int max{};
        for (; right < s.size(); ++right) {
            while (set.contains(s[right])) {
                set.erase(s[left]);
                left++;
                
            }
            set.insert(s[right]);
            if (right - left + 1 > max) {
                max = right - left + 1;
            }
        }
        return max;
    }
};
