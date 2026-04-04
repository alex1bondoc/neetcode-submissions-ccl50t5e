class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (sum(nums) % 2 != 0) {
            return false;
        }

        int target = sum(nums) / 2;
        vector<vector<bool>> dp(target + 1, vector<bool> (nums.size() + 1, false));
        for (int i = 0; i <= target; i++) {
            for (int j = 0; j <= nums.size(); ++j) {
                if (i == 0) {
                    dp[i][j] = true;
                }
                else {
                    if (j == 0) {
                        dp[i][j] = false;
                        continue;
                    }
                    dp[i][j] = dp[i][j - 1];
                    if (i - nums[j - 1] >= 0) {
                        dp[i][j] = dp[i][j] || dp[i - nums[j - 1]][j - 1];
                    }
                }
            }
        }

        return dp[target][nums.size()];
    }

private:
    int sum(vector<int>& nums) {
        int total = 0;
        for (int num : nums) {
            total += num;
        }
        return total;
    }
};