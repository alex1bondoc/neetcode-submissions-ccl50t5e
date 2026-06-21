class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> count;
        vector<vector<int>> freq(nums.size() + 1);
        for (int num : nums) {
            count[num]++;
        }
        for (const auto& [x, y]: count) {
            freq[y].push_back(x);
        }
        vector<int> res;
        for (int i = freq.size() - 1; i > 0; --i) {
            for (int n : freq[i]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                }
            }
        }
        return res;
    }
};
