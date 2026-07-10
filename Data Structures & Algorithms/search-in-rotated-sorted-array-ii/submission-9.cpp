class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left{};
        int right{static_cast<int>(nums.size() - 1)};
        while (left <= right) {
            int mid{left + (right - left) / 2};
            if (nums[mid] == target) {
                return true;
            }
            if (nums[mid] <= nums[nums.size() - 1]) {
                if (nums[mid] < target && target <= nums[nums.size() - 1]) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            else {
                if (target > nums[nums.size() - 1] && target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            }
        }
        return false;
    }
};
