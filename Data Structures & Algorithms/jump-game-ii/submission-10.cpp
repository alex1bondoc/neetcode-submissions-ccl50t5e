class Solution {
public:
    int jump(vector<int>& nums) {
        int n{static_cast<int>(nums.size())};
        int left{};
        int right{};
        int res{};
        while (left <= right && right < n - 1) {
            int far{};
            for (int i{left}; i <= right; ++i) {
                far = max(far, i + nums[i]);
            }
            left = right + 1;
            right = far;
            res++;
        }
        return res;
    }
};
