class Solution {
private:
    int cache[1001][1001]{};
public:
    int lengthOfLIS(vector<int>& nums) {
        return dp (nums, 0, 0);
    }
    int dp(vector<int>& nums, int i, int start) {
        if (i == nums.size()){
            return 0;
        }
        if (cache[i][start] != 0) {
            return cache[i][start];
        }
        int res = 0;
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[i] < nums[j])
                res = std::max(res, 1 + dp(nums, j, start));
        } 
        res = std::max(res, 1 + dp(nums, nums.size(), start));
        res = std::max(res, dp(nums, i + 1, i + 1));
        cache[i][start] = res;
        return res;
    }
};
