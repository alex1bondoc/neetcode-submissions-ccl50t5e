class Solution {
private:
    std::unordered_map<int, int> cache;
public:
    int lengthOfLIS(vector<int>& nums) {
        return dp (nums, 0);
    }
    int dp(vector<int>& nums, int i) {
        if (i == nums.size()) return 0;
        int res = 0;
        if (cache.find(i) != cache.end())
            return cache[i];
        for (int j{i + 1}; j < nums.size(); ++j) {
            if (nums[i] < nums[j]) {
                res = std::max(res, 1 + dp(nums, j));
            }
        }
        res = std::max(res, 1 + dp(nums, nums.size()));
        res = std::max(res, dp(nums, i + 1));
        cache[i] = res;
        return res;
    }
};
