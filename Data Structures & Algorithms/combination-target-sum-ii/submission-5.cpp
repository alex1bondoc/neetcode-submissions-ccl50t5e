class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        res.clear();
        sort(candidates.begin(), candidates.end());
        dfs(0, {}, 0, candidates, target);
        return res;
    }

private:
    void dfs(int idx, vector<int> path, int cur, vector<int>& nums, int target) {
        if (cur == target) {
            res.push_back(path);
            return;
        }
        if (cur > target || idx >= nums.size()) return;
        
        path.push_back(nums[idx]);
        dfs(idx + 1, path, cur + nums[idx], nums, target);
        path.pop_back();
        idx++;
        while (idx < nums.size() && nums[idx] == nums[idx - 1]) idx++;
        dfs(idx, path, cur, nums, target);

    }
};