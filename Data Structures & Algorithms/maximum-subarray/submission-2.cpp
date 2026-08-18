class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum{1 << 31};
        int sum{};
        for (const auto& num : nums) {
            if (sum < 0) {
                sum = 0;
            }
            sum += num;
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};
