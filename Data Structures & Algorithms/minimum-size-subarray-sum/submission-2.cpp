class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left{};
        int minLength{static_cast<int>(nums.size())};
        int sum{};
        int check{};
        for (int right{}; right < nums.size(); ++right) {
            sum += nums[right];
            while (left < right && sum >= target) {
                check = 1;
                minLength = std::min(minLength, right - left + 1);
                sum -= nums[left++];
            }
        }
        return check ? minLength : 0;
    }
};