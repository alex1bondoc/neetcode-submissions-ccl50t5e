class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto num : nums) {
            sum += num;
        }
        if (sum % 2) return false;
        return dp(nums, 0, 0, sum / 2);
    }
    bool dp(vector<int>& nums, int i, int sum, int aspect){
        if (i == nums.size()){
            return aspect == sum;
        }
        return dp(nums, i + 1, sum + nums[i], aspect) || dp(nums, i + 1, sum, aspect);
    }
};
