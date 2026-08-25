class Solution {
public:
    bool canJump(vector<int>& nums) {
        int left{0};
        int right{};
        int n{static_cast<int>(nums.size())};
        while (right < n - 1 && left <= right) {
            right = max(right, left + nums[left]);
            left++;
        }
        return right >= n - 1;
    }
};
