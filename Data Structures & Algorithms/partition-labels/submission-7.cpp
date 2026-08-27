class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> first(26, -1), last(26, -1);
        for (int i{}; i < s.size(); ++i) {
            char c{s[i]};
            if (first[c - 'a'] == -1) {
                first[c - 'a'] = i; 
            }
            last[c - 'a'] = i;
        }
        vector<int> res{};
        int left{}; 
        int right{};
        for (int i{}; i < s.size(); ++i) {
            right = max(last[s[i] - 'a'], right);

            if (right == i) {
                res.push_back(right - left + 1);
                left = i + 1;
                right = i + 1;
            }
        }
        return res;
    }
};
