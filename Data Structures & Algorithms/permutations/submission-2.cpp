class Solution {
    vector<vector<int>> res{};
    unordered_set<int> set;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        backtrack(cur, nums, 0);
        return res;
    }
    void backtrack(vector<int>& cur, vector<int>& nums, int k) {
        if (k == nums.size()) {
            res.push_back(cur);
        }
        for (int i{}; i < nums.size(); ++i) {
            if (set.contains(i)) continue;
            set.insert(i);
            cur.push_back(nums[i]);
            backtrack(cur, nums, k + 1);
            cur.pop_back();
            set.erase(i);
        }
    }
};
