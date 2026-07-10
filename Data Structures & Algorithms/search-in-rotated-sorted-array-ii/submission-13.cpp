class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left{};
        int right{static_cast<int>(nums.size()) - 1};
        while (left <= right) {
            int mid{left + (right - left) / 2};
            if (nums[mid] == target) return true;
            if (nums[mid] <= nums[right]) {
                if (target <= nums[right] && target > nums[mid]) {
                    left = mid + 1;
                    std::cout << "1 " << std::endl;
                }
                else {
                    right = mid - 1;
                    std::cout << "2 " << std::endl;

                }
            }
            else if (nums[right] < nums[mid]) {
                if (target < nums[mid] && target >= nums[left]) {
                    right = mid - 1;
                    std::cout << "3 " << std::endl;

                }
                else {

                    std::cout << "4 " << std::endl;
                    left = mid + 1;
                }
            }
            else {
                right --;
            }
        }
        return false;
    }
};
