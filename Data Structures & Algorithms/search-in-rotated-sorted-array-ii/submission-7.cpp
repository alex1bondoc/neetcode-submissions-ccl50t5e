class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            std::cout << mid << " " << nums[mid] <<endl;
            if (nums[mid] == target) {
                return true;
            }
            if (nums[mid] > nums[right] ) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            else if (nums[left] > nums[mid]) { // Right portion
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                left++;
            }
        }
        return false;
    }
};
// class Solution:
//     def search(self, nums: List[int], target: int) -> int:
//         l = 0
//         r = len(nums) - 1
//         while l <= r:
//             mid = (l + r) // 2
//             print(mid)

//             if nums[mid] == target:
//                 return mid
//             if nums[mid] > nums[r]:
//                 if nums[l] <= target < nums[mid]:
//                     r = mid - 1
//                 else :
//                     l = mid + 1
//             else:
//                 if target < nums[mid]  or target > nums[r]:
//                     r = mid - 1
//                 else :
//                     l = mid + 1

//         return -1