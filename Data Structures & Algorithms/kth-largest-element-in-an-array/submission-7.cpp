class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left{}, right = nums.size() - 1;
        int pivot = nums.size();
        while (pivot != k - 1) {
            int l{left};
            for (int r{left}; r < right; ++r) {
                if (nums[r] > nums[right]) {
                    swap(nums[r], nums[l]);
                    l++;
                }
            } 
            pivot = l;
            swap(nums[l], nums[right]);
            if (pivot > k - 1) {
                right = pivot - 1;
            }
            else if (pivot < k - 1) {
                left = pivot + 1;
            }
        }
        return nums[k - 1];
    }
};
