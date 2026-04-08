class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res{};
        auto backtracking = [&](auto&& backtracking, int i, vector<int> cur){
            if (i == nums.size()) {res.push_back(cur); return;}
            cur.push_back(nums[i]);
            backtracking(backtracking, i + 1, cur);
            cur.pop_back();
            backtracking(backtracking, i + 1, cur);
        };
        vector<int> seq{};
        backtracking(backtracking, 0, seq);
        return res;
    }
};
