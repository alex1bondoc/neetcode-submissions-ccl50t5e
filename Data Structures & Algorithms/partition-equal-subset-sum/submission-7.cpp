class Solution {
    std::vector<vector<int>> aux;
public:
    bool canPartition(vector<int>& nums) {
        int s = std::accumulate(nums.begin(), nums.end(), 0);
        aux.resize(nums.size(), vector<int> (s / 2 + 1, -1));
        if (s%2) return false;
        return dp(nums, 0, 0, s / 2);
    }
    bool dp(vector<int>& nums, int i, int sum, int target) {
        if (i == nums.size() && sum == target) return true;
        if (i == nums.size() || sum > target) return false;
        if (aux[i][sum] != -1) return aux[i][sum];
        aux[i][sum] =  dp(nums, i + 1, sum + nums[i], target) || dp(nums, i + 1, sum, target);
        return aux[i][sum];
    }
};
