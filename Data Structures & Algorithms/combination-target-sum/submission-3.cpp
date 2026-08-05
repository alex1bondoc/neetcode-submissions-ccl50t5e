class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        backtrack(cur, nums, 0, target, 0);
        
        return vector<vector<int>> (res.begin(), res.end());
    }
private: 
    void backtrack(vector<int>& cur, vector<int>& nums, int sum, int target, int idx) {
        if (sum > target || idx >= nums.size()) return;
        if (sum == target) {
            res.push_back(cur);
            return;
        }
        cur.push_back(nums[idx]);
        backtrack(cur, nums, sum + nums[idx], target, idx);
        cur.pop_back();
        backtrack(cur, nums, sum, target, idx + 1);
    }
};
