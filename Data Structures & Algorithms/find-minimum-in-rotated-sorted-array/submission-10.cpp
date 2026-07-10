class Solution {
public:
    int findMin(vector<int> &nums) {
        int sol{-1};
        for (int i{}; i < nums.size() - 1; ++i) {
            if (nums[i] > nums[i + 1]) sol = i + 1;
        }
        return (sol == -1) ? nums[nums.size() - 1] : nums[sol];
    }
};
