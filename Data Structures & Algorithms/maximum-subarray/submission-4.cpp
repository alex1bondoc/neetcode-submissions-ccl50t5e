class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res{1 << 31};
        int sum{};
        for (const auto& num : nums) {
            if (sum < 0) sum = 0;
            sum += num;
            res = max(res, sum);
        }
        return res;
    }
};
