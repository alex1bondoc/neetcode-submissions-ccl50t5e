class Solution {
public:
    int findMin(vector<int> &nums) {
        int sol{1 << 30};
        int left{0};
        int right{static_cast<int>(nums.size() - 1)};
        while (left <= right) {
            int mid{left + (right - left) / 2};
            if (nums[mid] > nums[nums.size() - 1]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
            sol = std::min(sol, nums[mid]);
        }
        return sol;
    }
};
