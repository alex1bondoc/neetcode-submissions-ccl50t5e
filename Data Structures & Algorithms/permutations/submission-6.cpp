class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res{};
        auto back = [&](auto& self, int k) {
            if (k == nums.size()) {
                res.push_back(nums);
                return;
            }
            for (int i{k}; i < nums.size(); ++i) {
                swap(nums[i], nums[k]);
                self(self, k + 1);
                swap(nums[i], nums[k]);
            }
        };
        back(back, 0);
        return res;
    }
};
