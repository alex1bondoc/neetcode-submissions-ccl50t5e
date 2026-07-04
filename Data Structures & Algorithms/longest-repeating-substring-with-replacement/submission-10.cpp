class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxFreq{};
        int left{};
        unordered_map<char, int> freq;
        int sol{};
        for (int right{}; right < s.size(); ++right) {
            char c = s[right];
            freq[c] ++;
            maxFreq = std::max(maxFreq, freq[c]);
            while ((right - left + 1) - maxFreq > k){
                freq[s[left]]--;
                left ++;
            }
            sol = std::max(sol, right - left + 1);
        }
        return sol;
    }
};
