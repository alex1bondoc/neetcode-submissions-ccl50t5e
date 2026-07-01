class Solution {
public:
    int findMin(vector<int> &nums) {
        int sol{1001};
        int left{};
        int right{static_cast<int> (nums.size() - 1)};

        while (left <= right) {
            int mid{left + (right - left) / 2};
            if (nums[mid] < sol) {
                sol = nums[mid];
            }
            if (nums[mid] < nums[right]) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return sol;
    }
};
