class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int sol{};
        int left{0}, right{static_cast<int>(nums.size()) - 1};
        while (left <= right) {
            int mid{left + (right - left) / 2};
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) {
                sol = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return sol + 1;
    }
};