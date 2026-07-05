class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int left{};
        int solution{};
        int freqMax{};
        for (int right{}; right < s.size(); right++) {
            count[s[right]]++;
            if (count[s[right]] > freqMax) freqMax = count[s[right]];
            while (right - left + 1 - freqMax > k) {
                count[s[left]]--;
                left ++;
            }
            solution = std::max(solution, right - left + 1);
        }
        return solution;
    }
};
