class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> freq;
        unordered_map<char, int> freq2;
        int need{26};
        int n{static_cast<int>(s1.size())};
        int m{static_cast<int>(s2.size())};
        for (int i{}; i < n; ++i) {
            if (freq[s1[i]] == 0) need --;
            freq[s1[i]] ++;
        }
        int left{};
        for (int right{}; right < m; ++right) {
            freq2[s2[right]]++;
            if (right >= n) freq2[s2[left]]--;
            if (freq2[s2[right]] == freq[s2[right]]) need ++;
            else if (freq2[s2[right]] == freq[s2[right]] + 1) need --;
            if (freq2[s2[left]] == freq[s2[left]]) need ++;
            else if (freq2[s2[left]] == freq[s2[left]] - 1) need --;
            if (need == 26) return true;
            if (right >= n)
                left ++;

        }

        return false;
    }
};
