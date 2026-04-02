class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> dp1(n + 2, 0);
        int one1 = 0, two1 = 0;
        std::vector<int> dp2(n + 1, 0);
        int one2{0}, two2{0};
        for (int i{n - 1}; i >= 1; --i) {
            int tmp{std::max(nums[i] + two1, one1)};
            two1 = one1;
            one1 = tmp;
        }
        for (int i{n - 2}; i >= 0; --i) {
            int tmp{std::max(nums[i] + two2, one2)};
            two2 = one2;
            one2 = tmp;
        }
        return std::max(nums[0], std::max(one1, one2));
    }
};
