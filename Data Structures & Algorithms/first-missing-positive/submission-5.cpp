class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i{}; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                nums[i] = 0;
            }
        }
        for (int i{}; i < nums.size(); ++i) {
            int num{nums[i]};
            if (num < 0)
                num *= -1;
            if (0 < num && num <= nums.size()) {
                if (nums[num -1] > 0) {
                    nums[num - 1] *= -1;
                }
                else if(nums[num - 1] == 0) {
                    nums[num - 1] = -1;
                }
            }
        }
        for (int i{}; i < nums.size(); ++i) {
            if (nums[i] >= 0){
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};