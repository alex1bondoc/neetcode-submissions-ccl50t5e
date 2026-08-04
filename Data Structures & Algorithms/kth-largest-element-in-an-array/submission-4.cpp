class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left{}, right{static_cast<int>(nums.size() - 1)};
        int pivot{static_cast<int>(nums.size())};
        while (k - 1 != pivot) {
            int l{left};
            for (int r{left}; r < right; ++r) {
                if (nums[r] > nums[right]) {
                    swap(nums[r], nums[l]);
                    l++;
                }
            }
            swap(nums[l], nums[right]);
            pivot = l;
            if (pivot < k - 1) left = pivot + 1;
            else if (pivot > k - 1) right = pivot - 1;
        }
        return nums[k - 1];
    }
};
