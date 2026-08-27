class Solution {
public:
    bool canJump(vector<int>& nums) {
        int left{};
        int right{};
        int n{static_cast<int>(nums.size())};
        while (left <= right && right < n - 1) {
            right = max(right, left + nums[left]);
            left++;
        }
        return right == n - 1;
    }
};
