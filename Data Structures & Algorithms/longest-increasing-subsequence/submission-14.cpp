class Solution {
    vector<vector<int>> ar;
public:
    int lengthOfLIS(vector<int>& nums) {
        ar.resize(nums.size(), vector<int> (nums.size(), -1));
        return dp(nums, 0, -1);
    }
    int dp(vector<int>& nums, int i, int j) {
        if (i == nums.size()){
            return 0;
        }
        if (ar[i][j + 1] != -1) return ar[i][j + 1];
        int res{};
        if (j == -1 || nums[j] <  nums[i]){
            res = 1 + dp(nums, i + 1, i);
        }
        res = std::max(res, dp(nums, i + 1, j));
        ar[i][j + 1] = res;
        return res;
    }
};
