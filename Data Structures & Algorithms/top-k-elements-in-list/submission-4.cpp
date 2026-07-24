class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (const int& n : nums) {
            count[n] ++;
        }
        vector<vector<int>> freq(nums.size() + 1);
        for (const auto& p : count) {
            auto [key, value] = p;
            freq[value].push_back(key);
        }
        vector<int> res;
        for (int i{static_cast<int>(freq.size() - 1)}; i > 0; --i) {
            for (int n : freq[i]) {
                res.push_back(n);
                k--;
                if (k == 0) return res;
            }
        }
        return res;
    }
};
