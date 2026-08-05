class Solution {
    vector<vector<int>> res;
    unordered_set<int> set;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        backtrack(cur, nums, 0);
        return res;
    }

private: 
    void backtrack(vector<int>& cur, vector<int>& nums, int k) {
        if (k > nums.size()) return;
        res.push_back(cur);
        for (int i{k}; i < nums.size(); ++i) {
            cur.push_back(nums[i]);
            backtrack(cur, nums, i + 1);
            cur.pop_back();
        }
    }
};
