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
        for (int i{0}; i < nums.size(); ++i) {
            if (set.contains(i)) continue;
            if (cur.size() && cur.back() > nums[i]) continue;
            cur.push_back(nums[i]);
            set.insert(i);
            backtrack(cur, nums, k + 1);
            set.erase(i);
            cur.pop_back();
        }
    }
};
