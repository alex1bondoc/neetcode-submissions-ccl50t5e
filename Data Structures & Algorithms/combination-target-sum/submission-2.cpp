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
        if (sum > target) return;
        if (sum == target) {
            res.push_back(cur);
            return;
        }
        for (int i{idx}; i < nums.size(); ++i) {
            int num{nums[i]};
            cur.push_back(num);
            sum += num;
            backtrack(cur, nums, sum, target, i);
            sum -= num;
            cur.pop_back();
        }
    }
};
